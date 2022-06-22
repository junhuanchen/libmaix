
#include "zm831_uvai.hpp"

extern "C"
{
  extern zm831_uv *zm831;

  void zm831_ctrl_load()
  {
    zm831->input_event0 = open("/dev/input/event0", O_RDONLY | O_NONBLOCK);
    if (zm831->input_event0 <= 0)
    {
      perror("open /dev/input/event0 device error!\n");
      abort();
    }

    uart_t uart_dev_parm = {
        .baud = 115200,
        .data_bits = 8,
        .stop_bits = 1,
        .parity = 'n'};
    zm831->dev_ttyS1 = linux_uart_init((char *)"/dev/ttyS1", &uart_dev_parm);
    if (zm831->dev_ttyS1 < 0)
    {
      perror(" uart /dev/ttyS1 open err!");
      abort();
    }
    write(zm831->dev_ttyS1, "zm831!\r\n", sizeof("zm831!\r\n"));

    zm831->timeout.tv_sec = 0;
    zm831->timeout.tv_usec = 0;
    FD_ZERO(&zm831->readfd);
    LIBMAIX_DEBUG_PRINTF("zm831_ctrl_load");
  }

  void zm831_ctrl_exit()
  {
    close(zm831->dev_ttyS1);
    close(zm831->input_event0);
    LIBMAIX_DEBUG_PRINTF("zm831_ctrl_exit");
  }

  void zm831_ctrl_loop()
  {
    CALC_FPS("zm831_ctrl_loop");

    int ret = 0;

    // serial
    FD_SET(zm831->dev_ttyS1, &zm831->readfd);
    ret = select(zm831->dev_ttyS1 + 1, &zm831->readfd, NULL, NULL, &zm831->timeout);
    if (ret != -1 && FD_ISSET(zm831->dev_ttyS1, &zm831->readfd))
    {
      char tmp;
      int readByte = read(zm831->dev_ttyS1, &tmp, 1);
      if (readByte != -1)
      {
        printf("readByte %d %X\n", readByte, tmp);
      }
    }

    // key
    FD_SET(zm831->input_event0, &zm831->readfd);
    ret = select(zm831->input_event0 + 1, &zm831->readfd, NULL, NULL, &zm831->timeout);
    if (ret != -1 && FD_ISSET(zm831->input_event0, &zm831->readfd))
    {
      struct input_event event;
      if (read(zm831->input_event0, &event, sizeof(event)) == sizeof(event))
      {
        if ((event.type == EV_KEY) && (event.value == 0 || event.value == 1))
        {
          printf("keyEvent %d %s\n", event.code, (event.value) ? "Pressed" : "Released");
          if (event.value == 0)
          {
            zm831->exit = 1;
          }
        }
      }
    }

    LIBMAIX_DEBUG_PRINTF("zm831_ctrl_loop");
  }
}