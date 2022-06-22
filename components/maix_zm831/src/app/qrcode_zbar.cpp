
#include "zm831_uvai.hpp"

extern "C"
{
  extern zm831_uv *zm831;

// ==============================================================================================

#include "zbar.h"
#include "symbol.h"

#define zbar_fourcc(a, b, c, d) \
  ((unsigned long)(a) |         \
   ((unsigned long)(b) << 8) |  \
   ((unsigned long)(c) << 16) | \
   ((unsigned long)(d) << 24))

  static struct _qrcode_zbar_
  {
    zbar_image_scanner_t *scanner;
    lv_draw_rect_dsc_t rect_dsc;
    lv_draw_label_dsc_t label_dsc;
    time_t now;
  } qrcode_zbar_app;

  int qrcode_zbar_app_load(zm831_home_app *app);
  int qrcode_zbar_app_loop(zm831_home_app *app);
  int qrcode_zbar_app_exit(zm831_home_app *app);

  zm831_home_app get_qrcode_zbar_app()
  {
    return {qrcode_zbar_app_load, qrcode_zbar_app_loop, qrcode_zbar_app_exit, &qrcode_zbar_app};
  }

// ==============================================================================================

  int qrcode_zbar_app_load(zm831_home_app *app)
  {
    auto self = (_qrcode_zbar_ *)app->userdata;
    lv_draw_rect_dsc_init(&self->rect_dsc);
    self->rect_dsc.radius = 5;
    self->rect_dsc.bg_opa = LV_OPA_TRANSP;
    self->rect_dsc.border_width = 5;
    self->rect_dsc.border_opa = LV_OPA_80;
    self->rect_dsc.border_color = {0x00, 0x00, 0xFF, 0x9f}; // bgra vo 9 ARGB

    lv_draw_label_dsc_init(&self->label_dsc);
    self->label_dsc.color = LV_COLOR_BLACK;

    self->scanner = zbar_image_scanner_create();
    if (!self->scanner)
    {
      return -1;
    }

    LIBMAIX_INFO_PRINTF("qrcode_zbar_app_load");
    return 0;
  }

  int qrcode_zbar_app_exit(zm831_home_app *app)
  {
    auto self = (_qrcode_zbar_ *)app->userdata;
    if (self->scanner != NULL)
      zbar_image_scanner_destroy(self->scanner), self->scanner = NULL;

    pthread_mutex_lock(&zm831->ui_mutex);
    lv_canvas_fill_bg(zm831->canvas, LV_COLOR_BLACK, LV_OPA_TRANSP);
    pthread_mutex_unlock(&zm831->ui_mutex);

    LIBMAIX_INFO_PRINTF("qrcode_zbar_app_exit");
    return 0;
  }

  int qrcode_zbar_app_loop(zm831_home_app *app)
  {
    auto self = (_qrcode_zbar_ *)app->userdata;
    if (self->scanner == NULL)
      return -1;

    libmaix_image_t *ai_rgb = NULL;
    if (LIBMAIX_ERR_NONE == zm831->ai->capture_image(zm831->ai, &ai_rgb))
    {
      // printf("ai_rgb: %p, %d, %d\r\n", ai_rgb, ai_rgb->width, ai_rgb->height);
      cv::Mat rgb(ai_rgb->height, ai_rgb->width, CV_8UC3, ai_rgb->data);
      cv::Mat gray;
      cv::cvtColor(rgb, gray, cv::COLOR_RGB2GRAY);

      /* obtain image data */
      int width = gray.cols, height = gray.rows;
      uint8_t *raw = gray.data;

      /* wrap image data */
      zbar_image_t *image = zbar_image_create();
      zbar_image_set_format(image, zbar_fourcc('Y', '8', '0', '0'));
      zbar_image_set_size(image, width, height);
      zbar_image_set_data(image, raw, width * height, NULL);

      /* scan the image for barcodes */
      int n = zbar_scan_image(self->scanner, image);

      /* extract results */
      const zbar_symbol_t *symbol = zbar_image_first_symbol(image);

      if (self->now < time(NULL))
      {
        pthread_mutex_lock(&zm831->ui_mutex);
        lv_canvas_fill_bg(zm831->canvas, LV_COLOR_BLACK, LV_OPA_TRANSP);
        pthread_mutex_unlock(&zm831->ui_mutex);
      }

      for (; symbol; symbol = zbar_symbol_next(symbol))
      {
        point_t corners[4];
        corners[0].x = zbar_symbol_get_loc_x(symbol, 0);
        corners[0].y = zbar_symbol_get_loc_y(symbol, 0);
        corners[1].x = zbar_symbol_get_loc_x(symbol, 1);
        corners[1].y = zbar_symbol_get_loc_y(symbol, 1);
        corners[2].x = zbar_symbol_get_loc_x(symbol, 2);
        corners[2].y = zbar_symbol_get_loc_y(symbol, 2);
        corners[3].x = zbar_symbol_get_loc_x(symbol, 3);
        corners[3].y = zbar_symbol_get_loc_y(symbol, 3);

        zbar_symbol_type_t typ = zbar_symbol_get_type(symbol);
        const char *data = zbar_symbol_get_data(symbol);
        // if (typ == ZBAR_QRCODE)
        {
          printf("decoded %s symbol \"%s\"\n", zbar_get_symbol_name(typ), data);
          pthread_mutex_lock(&zm831->ui_mutex);
          lv_canvas_fill_bg(zm831->canvas, LV_COLOR_BLACK, LV_OPA_TRANSP);
          lv_canvas_draw_rect(zm831->canvas, corners[0].x, corners[0].y, corners[2].x - corners[0].x + 8, corners[2].y - corners[0].y + 8, &self->rect_dsc);
          lv_canvas_draw_text(zm831->canvas, corners[0].x, corners[0].y, 120, &self->label_dsc, data, LV_LABEL_ALIGN_AUTO);
          pthread_mutex_unlock(&zm831->ui_mutex);
          self->now = time(NULL);
          break;// only one QR code
        }
      }

      /* clean up */
      zbar_image_destroy(image); // use zbar_image_free_data
    }

    usleep(10000); // 10ms

    // LIBMAIX_INFO_PRINTF("qrcode_zbar_app_loop");
    return 0;
  }
}
