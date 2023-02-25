
#include "fb_display.h"

#include <fcntl.h>
#include <pthread.h>
#include <sys/time.h>
#include <sys/select.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <linux/input.h>
#include <time.h>
#include <unistd.h>
#include <string>

#include "imlib.h"

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

static void msleep(unsigned int ms)
{
	usleep(ms * 1000);
	// struct timespec ts = {ms / 1000, (ms % 1000) * 1000 * 1000};
	// nanosleep(&ts, nullptr);
}

struct main_t
{
	const uint32_t imlib_img_w = 240, imlib_img_h = 240, imlib_img_s = imlib_img_w * imlib_img_h * PIXFORMAT_BPP_RGB888;

	image_t *imlib_img;
	uint32_t input_event0, is_working;
	struct timeval timeout;
	fd_set readfd;

	image_t img_ts, *ptr = &img_ts;

	int load()
	{
		fb_realloc_init1(1 * 1024 * 1024);

		imlib_img = imlib_image_create(imlib_img_w, imlib_img_h, PIXFORMAT_RGB888, imlib_img_s, NULL, true);

		imlib_image_init(ptr, 240, 240, PIXFORMAT_RGB888, 0, NULL);
		bmp_read(ptr, "/root/888.bmp");

		input_event0 = open("/dev/input/event0", O_RDONLY | O_NONBLOCK);
		if (input_event0 <= 0)
		{
			perror("open /dev/input/event0 device error!\n");
			abort();
		}

		timeout.tv_sec = 0;
		timeout.tv_usec = 0;
		FD_ZERO(&readfd);

		return 0;
	}

	int exit()
	{
		imlib_image_destroy(&ptr);

		imlib_image_destroy(&imlib_img);
		fb_alloc_close0();
		close(input_event0);
		return 0;
	}

	int loop()
	{
		fb_alloc_mark();

		// 清理一下图片
		memset(imlib_img->data, 0, imlib_img_s);

		// 贴一张背景图
		rectangle_t roi = {0, 0, 240, 240};
		imlib_pixfmt_to(imlib_img, ptr, &roi);

		// 读取按键事件
		FD_SET(input_event0, &readfd);
		int ret = select(input_event0 + 1, &readfd, NULL, NULL, &timeout);
		if (ret != -1 && FD_ISSET(input_event0, &readfd))
		{
			struct input_event event;
			if (read(input_event0, &event, sizeof(event)) == sizeof(event))
			{
				if ((event.type == EV_KEY) && (event.value == 0 || event.value == 1))
				{
					printf("keyEvent %d %s\n", event.code, (event.value) ? "Pressed" : "Released");
					if (event.code == 2) {
						if (!is_working) {
							is_working = 1;
							system("python3 main.py &");
						}
					}
					if (event.code == 3) {
						if (is_working) {
							is_working = 0;
							system("killall python3; python3 -c 'from maix import camera'");
						}
					}
				}
			}
		}

		// check python process
		if (is_working) {
			if (system("ps -w | grep python3 | grep -v grep > /dev/null")) {
				is_working = 0;
				system("killall python3; python3 -c 'from maix import camera'");
			}
		}

		// 显示当前时间在右上角
		time_t now = time(NULL);
		struct tm *tm_now = localtime(&now);
		char time_str[64];
		strftime(time_str, sizeof(time_str), "%Y-%m-%d %H:%M:%S", tm_now);
		imlib_draw_string(imlib_img, 10, 10, time_str, COLOR_R8_G8_B8_TO_RGB888(0x7f, 0x7f, 0x7f), 3.0, 0, 0, 0, 0, 0, 0, 0, 0, 0);

		// 显示一张图
		fb_display(imlib_img->data, NULL, 240, 240, 0, 0, 0, 0);

		fb_alloc_free_till_mark();

		msleep(100); // cpu 100ms 7% or 200ms %3

		return 0;
	}

} g_main_t;

int main()
{
	g_main_t.load();
	while (1)
	{
		g_main_t.loop();
	}
	g_main_t.exit();
}
