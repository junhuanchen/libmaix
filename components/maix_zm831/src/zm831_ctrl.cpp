
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

  void zm831_protocol_recv(char *buf, int len)
  {
    char data = buf[0];
    static char data_buf[64] = { 0 };
    static uint16_t data_sta, data_len;
    switch (data_sta)
    {
    case 0:
    {
      if (data == 0x86)
      {
        data_sta = 1;
      }
      break;
    }
    case 1:
    {
      if (data == 0xAB)
      {
        data_sta = 2;
        data_len = 0;
      }
      else
      {
        data_sta = 0;
      }
      break;
    }
    case 2:
    {
      data_len = data << 8;
      data_sta = 3;
      break;
    }
    case 3:
    {
      data_len = data_len | data;
      data_len = data_len - 4;
      data_sta = 4;
      break;
    }
    case 4:
    { // cmd one
      data_len--;
      data_sta = 5;
      break;
    }
    case 5:
    { // cmd two
      data_len--;
      data_sta = 6;
      break;
    }
    case 6:
    { // fun
      data_len--;
      extern int zm831_home_app_select(int id);
      zm831_home_app_select(data); // home app select
      if (data_len == 3)
      {
        data_sta = 8;
      }
      else
      {
        data_sta = 7;
      }
      break;
    }
    case 7:
    { // data
      data_len--;
      // extern int zm831_home_app_index;
      // zm831->protocol_list.push_back({zm831_home_app_index, std::string(1, data)});
      if (data_len == 3)
        data_sta = 8;
      break;
    }
    case 8:
    { // number
      data_len--;
      data_sta = 9;
      break;
    }
    case 9:
    { // sum
      data_len--;
      data_sta = 10;
      break;
    }
    case 10:
    { // end
      data_len--;
      data_sta = 0;
      break;
    }
    }

    LIBMAIX_DEBUG_PRINTF("\n data_sta %d data_len %d 0x%02X", data_sta, data_len, buf[0]);
  }

  void zm831_protocol_send(char *buf, int len)
  {
    LIBMAIX_DEBUG_PRINTF("zm831_protocol_send");
    write(zm831->dev_ttyS1, buf, len);
  }

  void zm831_ctrl_loop()
  {
    // CALC_FPS("zm831_ctrl_loop");

    int ret = 0;

    // serial
    FD_SET(zm831->dev_ttyS1, &zm831->readfd);
    ret = select(zm831->dev_ttyS1 + 1, &zm831->readfd, NULL, NULL, &zm831->timeout);
    if (ret != -1 && FD_ISSET(zm831->dev_ttyS1, &zm831->readfd))
    {
      char tmp[2] = {0};
      int readByte = read(zm831->dev_ttyS1, &tmp, 1);
      if (readByte != -1)
      {
        // printf("readByte %d %X\n", readByte, tmp);
        zm831_protocol_recv(tmp, readByte);
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