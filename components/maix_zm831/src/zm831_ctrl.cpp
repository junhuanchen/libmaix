
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

  int zm831_protocol_send(uint8_t *data, int len)
  {
    int size = len + 9;
    if (size > (254)) return -1;
    uint8_t buffer[255] = { 0x00 };
    int pos = 0;
    buffer[pos++] = 0x86;
    buffer[pos++] = 0xAB;
    buffer[pos++] = (size >> 8) & 0xFF;
    buffer[pos++] = size & 0xFF;
    buffer[pos++] = 0xE8;
    buffer[pos++] = 0x15;
    memcpy(buffer + pos, data, len);
    pos += len;
    uint8_t sum = 0;
    for (int i = 0; i < pos; i++) sum += buffer[i];
    buffer[pos++] = 0x00;
    buffer[pos++] = sum;
    buffer[pos++] = 0xCF;
    write(zm831->dev_ttyS1, buffer, pos);
    return 0;
  }

  void zm831_protocol_recv(char *buf, int len)
  {
    char data = buf[0];
    static char data_buf[64] = { 0 }, *data_pos = NULL;
    static uint16_t data_sta, data_tmp, data_len;

    // printf("%02X %d\n", data, data_sta);
    if (data_pos - data_buf > 64) {
      data_pos = data_buf;
      data_sta = 0;
    }

    switch (data_sta)
    {
      case 0:
      {
        if (data == 0x86)
        {
          data_sta = 1;
          data_pos = data_buf;
          *data_pos++ = data;
        }
        break;
      }
      case 1:
      {
        if (data == 0xAB)
        {
          data_sta = 2;
          data_tmp = 0;
          *data_pos++ = data;
        }
        else
        {
          data_sta = 0;
        }
        break;
      }
      case 2:
      {
        *data_pos++ = data;
        data_tmp = data << 8;
        data_sta = 3;
        break;
      }
      case 3:
      {
        *data_pos++ = data;
        data_tmp = data_tmp | data;
        data_tmp = data_tmp - 4;
        data_sta = 4;
        break;
      }
      case 4:
      { // cmd one
        *data_pos++ = data;
        data_tmp--;
        data_sta = 5;
        break;
      }
      case 5:
      { // cmd two
        *data_pos++ = data;
        data_tmp--;
        data_sta = 6;
        break;
      }
      case 6:
      { // fun
        *data_pos++ = data;
        data_tmp--;
        extern int zm831_home_app_select(int id);
        zm831_home_app_select(data); // home app select
        if (data_tmp == 3)
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
        *data_pos++ = data;
        data_tmp--;
        if (data_tmp == 3) {
          data_sta = 8;
        }
        break;
      }
      case 8:
      { // number
        *data_pos++ = data;
        data_tmp--;
        data_sta = 9;
        break;
      }
      case 9:
      { // sum
        *data_pos++ = data;
        data_tmp--;
        data_sta = 10;
        break;
      }
      case 10:
      { // end
        *data_pos++ = data;
        data_sta = 0;
        data_tmp--;
        if (data_tmp == 0) {
          uint8_t data_sum = 0;
          int data_len = (data_pos - data_buf);
          for (int i = 0, len = data_len - 2; i < len; i++) data_sum += data_buf[i];
          // LIBMAIX_INFO_PRINTF("data_sum: %02X\n", data_sum);
          if (data_sum == data_buf[data_len - 2]) { // sum check pass
            // LIBMAIX_INFO_PRINTF("\n data_sum 0x%02X data_len %d", data_sum, data_len);
            // for(int i = 0; i < data_len; i++) LIBMAIX_INFO_PRINTF(" 0x%02X", data_buf[i]);
            extern int zm831_home_app_index;
            if (zm831->recvPacks.size() > 16) { // limit recv pack size
              zm831->recvPacks.pop_front();
            }
            auto tmp = std::vector<uint8_t>(data_len);
            memcpy(tmp.data(), data_buf, data_len);
            zm831->recvPacks.push_back((zm831_pack_t){ zm831_home_app_index, tmp});
          }
        }
        break;
      }
    }
    // LIBMAIX_INFO_PRINTF("\n data_sta %d data 0x%02X", data_sta, data);
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