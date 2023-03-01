
#include <stdio.h>
#include <unistd.h>
#include <string>
#include <sstream>
#include <fstream>
#include <iostream>
#include "gpio_lib.h"

#define PH7 231
#define debug_printf(fmt, ...) (fmt, ##__VA_ARGS__)

// << string_format("%d", 202412);
template <typename... Args>
std::string string_format(const std::string &format, Args... args)
{
    size_t size = 1 + snprintf(nullptr, 0, format.c_str(), args...); // Extra space for \0
    // unique_ptr<char[]> buf(new char[size]);
    char bytes[size];
    snprintf(bytes, size, format.c_str(), args...);
    return std::string(bytes);
}

std::string read_file_to_string(const std::string &path)
{
    std::ifstream file(path);
    if (!file.is_open())
    {
        return "";
    }
    std::stringstream ss;
    ss << file.rdbuf();
    return ss.str();
}

static void msleep(unsigned int ms)
{
    usleep(ms * 1000);
}

#define menu_program "/root/main.py"
int is_menu_running = 0;

void ready_process()
{
    system("rm -rf /tmp/start /tmp/stop /tmp/event /tmp/event.pid && sync");
    debug_printf("ready process\r\n");
}

void return_menu()
{
    int is_exist = access("/tmp/event.pid", F_OK) == 0;
    if (is_exist)
    {
        debug_printf("exist\r\n");
        auto pid = read_file_to_string("/tmp/event.pid");
        pid.erase(pid.find_last_not_of("\r\n") + 1);
        auto proc = string_format("/proc/%s", pid.c_str());
        int is_running = access(proc.c_str(), F_OK) == 0;
        debug_printf("is_running %d\r\n", is_running);
        if (!is_running) {
            ready_process();
            system(string_format("python %s & echo $! > /tmp/event.pid && sync", menu_program).c_str());
            is_menu_running = 1;
            debug_printf("no exist return menu\r\n");
        }
    }
    else
    {
        ready_process();
        system(string_format("python %s & echo $! > /tmp/event.pid && sync", menu_program).c_str());
        is_menu_running = 1;
        debug_printf("exist & no running return menu\r\n");
    }
}

void start_program()
{
    if (access("/tmp/event", F_OK) == 0)
    {
        system("ps | grep -v grep | grep python | awk '{print $1}' | xargs kill -9");
        system("rm -rf /root/event.log && sync");
        system("python /tmp/event > /root/event.log & echo $! > /tmp/event.pid && sync");
        is_menu_running = 0;
        debug_printf("start it\r\n");
    }
}

void close_program()
{
    if (access("/tmp/event.pid", F_OK) == 0 && access(string_format("/proc/%s", read_file_to_string("/tmp/event.pid").c_str()).c_str(), F_OK) != 0)
    {
        system("kill -9 $(cat /tmp/event.pid)");
        system("rm -rf /tmp/event.pid && sync");
        debug_printf("close it\r\n");
    }
}

int check_program(int ret)
{
    static int state = 0, last = 0;

    time_t now = time(NULL);
    debug_printf("gpio ret = %d now %d\r\n", ret, now);
    switch (state)
    {
        case 0:
        {
            state = 1;
            last = now;
            break;
        }
        case 1:
            if (ret)
            {
                if (is_menu_running != 1 && now > last + 1)
                {
                    state = 2;
                    debug_printf("kill it\r\n");
                }
            }
            else // 松开归位
            {
                last = now;
                debug_printf("give up\r\n");
            }
            break;
        case 2: // 长按 2 秒杀程序
            if (ret)
            {
                close_program();
                state = 0;
            }
            break;
    }

    if (access("/tmp/start", F_OK) == 0)
    {
        system("rm -rf /tmp/start && sync");
        start_program();
    }

    if (access("/tmp/stop", F_OK) == 0)
    {
        system("rm -rf /tmp/stop && sync");
        close_program();
    }

    return_menu();

}

int main()
{
    ready_process();
    sunxi_gpio_init();
    while (true)
    {
        sunxi_gpio_set_cfgpin(PH7, INPUT); // PH7 INPUT
        check_program(!sunxi_gpio_input(PH7));
        // usleep(500 * 1000);
        sleep(1);
    }
    sunxi_gpio_cleanup();
    return 0;
}
