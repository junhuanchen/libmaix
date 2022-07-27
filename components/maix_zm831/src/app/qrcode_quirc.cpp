
#include "zm831_uvai.hpp"

extern "C"
{
  extern zm831_uv *zm831;

// ==============================================================================================

#include <quirc.h>

  static struct _qrcode_quirc_
  {
    lv_draw_rect_dsc_t rect_dsc;
    lv_draw_label_dsc_t label_dsc;
    struct quirc *scanner;
    time_t now;
  } qrcode_quirc_app;

  int qrcode_quirc_app_load(zm831_home_app *app);
  int qrcode_quirc_app_loop(zm831_home_app *app);
  int qrcode_quirc_app_exit(zm831_home_app *app);

  zm831_home_app get_qrcode_quirc_app()
  {
    return {qrcode_quirc_app_load, qrcode_quirc_app_loop, qrcode_quirc_app_exit, &qrcode_quirc_app};
  }

// ==============================================================================================

  int qrcode_quirc_app_load(zm831_home_app *app)
  {
    auto self = (_qrcode_quirc_ *)app->userdata;
    lv_draw_rect_dsc_init(&self->rect_dsc);
    self->rect_dsc.radius = 5;
    self->rect_dsc.bg_opa = LV_OPA_TRANSP;
    self->rect_dsc.border_width = 5;
    self->rect_dsc.border_opa = LV_OPA_90;
    self->rect_dsc.border_color = {0x00, 0xFF, 0x00, 0x9f};

    lv_draw_label_dsc_init(&self->label_dsc);
    self->label_dsc.color = LV_COLOR_BLACK;

    self->scanner = quirc_new();
    quirc_resize(self->scanner, zm831->ai_w, zm831->ai_h);

    LIBMAIX_INFO_PRINTF("qrcode_quirc_app_load");
    return 0;
  }

  int qrcode_quirc_app_exit(zm831_home_app *app)
  {
    auto self = (_qrcode_quirc_ *)app->userdata;
    if (self->scanner != NULL)
      quirc_destroy(self->scanner), self->scanner = NULL;

    pthread_mutex_lock(&zm831->ui_mutex);
    lv_canvas_fill_bg(zm831_ui_get_canvas(), LV_COLOR_BLACK, LV_OPA_TRANSP);
    pthread_mutex_unlock(&zm831->ui_mutex);

    LIBMAIX_INFO_PRINTF("qrcode_quirc_app_exit");
    return 0;
  }

  int qrcode_quirc_app_loop(zm831_home_app *app)
  {
    auto self = (_qrcode_quirc_ *)app->userdata;
    if (self->scanner == NULL)
      return -1;

    libmaix_image_t *ai_rgb = NULL;
    if (zm831->ai && LIBMAIX_ERR_NONE == zm831->ai->capture_image(zm831->ai, &ai_rgb))
    {
      zm831->sensor_time = zm831_get_ms();
      // printf("ai_rgb: %p, %d, %d\r\n", ai_rgb, ai_rgb->width, ai_rgb->height);

      cv::Mat rgb(ai_rgb->height, ai_rgb->width, CV_8UC3, ai_rgb->data);

      uint8_t *grayscale_image = quirc_begin(self->scanner, NULL, NULL);

      cv::Mat gray(ai_rgb->height, ai_rgb->width, CV_8UC1, grayscale_image);

      cv::cvtColor(rgb, gray, cv::COLOR_RGB2GRAY);

      quirc_end(self->scanner);

      if (self->now < time(NULL))
      {
        pthread_mutex_lock(&zm831->ui_mutex);
        lv_canvas_fill_bg(zm831_ui_get_canvas(), LV_COLOR_BLACK, LV_OPA_TRANSP);
        pthread_mutex_unlock(&zm831->ui_mutex);
      }
      for (int i = 0, j = quirc_count(self->scanner); i < j; i++)
      {
        struct quirc_code code;
        struct quirc_data data;
        quirc_decode_error_t err;

        quirc_extract(self->scanner, i, &code);
        err = quirc_decode(&code, &data);
        if (err == QUIRC_ERROR_DATA_ECC)
        {
          quirc_flip(&code);
          err = quirc_decode(&code, &data);
        }

        // dump_cells(&code);
        // printf("\n");

        if (err)
        {
          printf("  Decoding FAILED: %s\n", quirc_strerror(err));
        }
        else
        {
          auto info = std::string();
          info.assign((const char *)data.payload, data.payload_len);
          // dump_data(&data);
          pthread_mutex_lock(&zm831->ui_mutex);
          lv_canvas_fill_bg(zm831_ui_get_canvas(), LV_COLOR_BLACK, LV_OPA_TRANSP);
          lv_canvas_draw_rect(zm831_ui_get_canvas(), code.corners[0].x, code.corners[0].y, ai2vi(code.corners[2].x - code.corners[0].x), ai2vi(code.corners[2].y - code.corners[0].y), &self->rect_dsc);
          lv_canvas_draw_text(zm831_ui_get_canvas(), code.corners[0].x, code.corners[1].y, 100, &self->label_dsc, info.c_str(), LV_LABEL_ALIGN_LEFT);
          pthread_mutex_unlock(&zm831->ui_mutex);
          self->now = time(NULL);
          break;// only one QR code
        }
      }
    }

    usleep(10000); // 10ms

    // LIBMAIX_INFO_PRINTF("qrcode_quirc_app_loop");
    return 0;
  }
}
