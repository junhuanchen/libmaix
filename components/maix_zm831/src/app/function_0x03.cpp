
#include "zm831_uvai.hpp"

extern "C"
{
  extern zm831_uv *zm831;

  // ==============================================================================================

  void setup_scr_qrcode_app(lv_ui *ui)
  {
    // Write codes camera
    ui->qrcode_app = lv_scr_act();

    //Write style LV_OBJ_PART_MAIN for qrcode_app
    static lv_style_t style_qrcode_app_main;
    lv_style_reset(&style_qrcode_app_main);

    //Write style state: LV_STATE_DEFAULT for style_qrcode_app_main
    lv_style_set_bg_color(&style_qrcode_app_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
    lv_style_set_bg_opa(&style_qrcode_app_main, LV_STATE_DEFAULT, 139);
    lv_obj_add_style(ui->qrcode_app, LV_OBJ_PART_MAIN, &style_qrcode_app_main);

    //Write codes qrcode_app_label_top_title
    ui->qrcode_app_label_top_title = lv_label_create(ui->qrcode_app, NULL);
    lv_label_set_text(ui->qrcode_app_label_top_title, "二维码识别");
    lv_label_set_long_mode(ui->qrcode_app_label_top_title, LV_LABEL_LONG_BREAK);
    lv_label_set_align(ui->qrcode_app_label_top_title, LV_LABEL_ALIGN_CENTER);

    //Write style LV_LABEL_PART_MAIN for qrcode_app_label_top_title
    static lv_style_t style_qrcode_app_label_top_title_main;
    lv_style_reset(&style_qrcode_app_label_top_title_main);

    //Write style state: LV_STATE_DEFAULT for style_qrcode_app_label_top_title_main
    lv_style_set_radius(&style_qrcode_app_label_top_title_main, LV_STATE_DEFAULT, 0);
    lv_style_set_bg_color(&style_qrcode_app_label_top_title_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
    lv_style_set_bg_grad_color(&style_qrcode_app_label_top_title_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
    lv_style_set_bg_grad_dir(&style_qrcode_app_label_top_title_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
    lv_style_set_bg_opa(&style_qrcode_app_label_top_title_main, LV_STATE_DEFAULT, 100);
    lv_style_set_text_color(&style_qrcode_app_label_top_title_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
    lv_style_set_text_font(&style_qrcode_app_label_top_title_main, LV_STATE_DEFAULT, &lv_font_simsun_18);
    lv_style_set_text_letter_space(&style_qrcode_app_label_top_title_main, LV_STATE_DEFAULT, 2);
    lv_style_set_pad_left(&style_qrcode_app_label_top_title_main, LV_STATE_DEFAULT, 0);
    lv_style_set_pad_right(&style_qrcode_app_label_top_title_main, LV_STATE_DEFAULT, 0);
    lv_style_set_pad_top(&style_qrcode_app_label_top_title_main, LV_STATE_DEFAULT, 8);
    lv_style_set_pad_bottom(&style_qrcode_app_label_top_title_main, LV_STATE_DEFAULT, 8);
    lv_obj_add_style(ui->qrcode_app_label_top_title, LV_LABEL_PART_MAIN, &style_qrcode_app_label_top_title_main);
    lv_obj_set_pos(ui->qrcode_app_label_top_title, 0, 0);
    lv_obj_set_size(ui->qrcode_app_label_top_title, 240, 0);

    //Write codes qrcode_app_imgbtn_back
    ui->qrcode_app_imgbtn_back = lv_imgbtn_create(ui->qrcode_app, NULL);

    //Write style LV_IMGBTN_PART_MAIN for qrcode_app_imgbtn_back
    static lv_style_t style_qrcode_app_imgbtn_back_main;
    lv_style_reset(&style_qrcode_app_imgbtn_back_main);

    //Write style state: LV_STATE_DEFAULT for style_qrcode_app_imgbtn_back_main
    lv_style_set_text_color(&style_qrcode_app_imgbtn_back_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
    lv_style_set_image_recolor(&style_qrcode_app_imgbtn_back_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
    lv_style_set_image_recolor_opa(&style_qrcode_app_imgbtn_back_main, LV_STATE_DEFAULT, 0);
    lv_style_set_image_opa(&style_qrcode_app_imgbtn_back_main, LV_STATE_DEFAULT, 255);

    //Write style state: LV_STATE_PRESSED for style_qrcode_app_imgbtn_back_main
    lv_style_set_text_color(&style_qrcode_app_imgbtn_back_main, LV_STATE_PRESSED, lv_color_make(0xFF, 0x33, 0xFF));
    lv_style_set_image_recolor(&style_qrcode_app_imgbtn_back_main, LV_STATE_PRESSED, lv_color_make(0x00, 0x00, 0x00));
    lv_style_set_image_recolor_opa(&style_qrcode_app_imgbtn_back_main, LV_STATE_PRESSED, 0);

    //Write style state: LV_STATE_CHECKED for style_qrcode_app_imgbtn_back_main
    lv_style_set_text_color(&style_qrcode_app_imgbtn_back_main, LV_STATE_CHECKED, lv_color_make(0xFF, 0x33, 0xFF));
    lv_style_set_image_recolor(&style_qrcode_app_imgbtn_back_main, LV_STATE_CHECKED, lv_color_make(0x00, 0x00, 0x00));
    lv_style_set_image_recolor_opa(&style_qrcode_app_imgbtn_back_main, LV_STATE_CHECKED, 0);
    lv_obj_add_style(ui->qrcode_app_imgbtn_back, LV_IMGBTN_PART_MAIN, &style_qrcode_app_imgbtn_back_main);
    lv_obj_set_pos(ui->qrcode_app_imgbtn_back, 20, 180);
    lv_obj_set_size(ui->qrcode_app_imgbtn_back, 50, 50);
    lv_imgbtn_set_src(ui->qrcode_app_imgbtn_back,LV_BTN_STATE_RELEASED,&_back_alpha_50x50);
    lv_imgbtn_set_checkable(ui->qrcode_app_imgbtn_back, true);

  }

#include "zbar.h"
#include "symbol.h"

#define zbar_fourcc(a, b, c, d) \
  ((unsigned long)(a) |         \
   ((unsigned long)(b) << 8) |  \
   ((unsigned long)(c) << 16) | \
   ((unsigned long)(d) << 24))

  static struct _function_0x03_
  {
    lv_ui *ui = &zm831->ui;

    zbar_image_scanner_t *scanner;
    lv_draw_rect_dsc_t rect_dsc;
    lv_draw_label_dsc_t label_dsc;
    time_t now;

    bool init = false;
  } function_0x03_app;

  int function_0x03_app_load(zm831_home_app *app);
  int function_0x03_app_loop(zm831_home_app *app);
  int function_0x03_app_exit(zm831_home_app *app);

  zm831_home_app get_function_0x03_app()
  {
    return {function_0x03_app_load, function_0x03_app_loop, function_0x03_app_exit, &function_0x03_app};
  }

  // =============================================================================================

  static void function_0x03_btn_event_app_cb(lv_obj_t *btn, lv_event_t event)
  {
    if (function_0x03_app.ui->qrcode_app_imgbtn_back == btn && event == LV_EVENT_SHORT_CLICKED)
    {
      zm831_home_app_select(0);
      return;
    }
  }

  int function_0x03_app_load(zm831_home_app *app)
  {
    auto self = (_function_0x03_ *)app->userdata;

    if (!self->init)
    {
      self->scanner = zbar_image_scanner_create();
      if (!self->scanner)
      {
        return -1;
      }

      lv_draw_rect_dsc_init(&self->rect_dsc);
      self->rect_dsc.radius = 5;
      self->rect_dsc.bg_opa = LV_OPA_50;
      self->rect_dsc.border_width = 2;
      self->rect_dsc.border_opa = LV_OPA_50;
      self->rect_dsc.border_color = {0x00, 0x00, 0xFF, 0x9f};

      lv_draw_label_dsc_init(&self->label_dsc);
      self->label_dsc.color = LV_COLOR_YELLOW;

      zm831_home_setup_ui(&self->ui->qrcode_app, setup_scr_qrcode_app, 500);

      pthread_mutex_lock(&zm831->ui_mutex);
      lv_obj_set_event_cb(self->ui->qrcode_app_imgbtn_back, function_0x03_btn_event_app_cb);
      pthread_mutex_unlock(&zm831->ui_mutex);

      self->init = true;
    }

    LIBMAIX_INFO_PRINTF("function_0x03_app_load");
    return 0;
  }

  int function_0x03_app_exit(zm831_home_app *app)
  {
    auto self = (_function_0x03_ *)app->userdata;
    if (self->init)
    {
      if (self->scanner != NULL)
        zbar_image_scanner_destroy(self->scanner), self->scanner = NULL;

      zm831_home_clear_ui(&self->ui->qrcode_app);

      self->init = false;
    }
    LIBMAIX_INFO_PRINTF("function_0x03_app_exit");
    return 0;
  }

  int function_0x03_app_loop(zm831_home_app *app)
  {
    auto self = (_function_0x03_ *)app->userdata;
    libmaix_err_t err = LIBMAIX_ERR_NONE;
    libmaix_image_t *ai_rgb = NULL;
    if (zm831->ai && LIBMAIX_ERR_NONE == zm831->ai->capture_image(zm831->ai, &ai_rgb))
    {
      // CALC_FPS("function_0x03_app_loop"); // 224x224x3
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
        lv_canvas_fill_bg(zm831_ui_get_canvas(), LV_COLOR_BLACK, LV_OPA_TRANSP);
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
          printf("decoded %s symbol \"%s\" | ", zbar_get_symbol_name(typ), data);
          for(int i = 0, s = strlen(data); i < s; i++)
          {
            printf("%02X ", data[i]);
          }
          printf("\n");

          pthread_mutex_lock(&zm831->ui_mutex);
          lv_canvas_fill_bg(zm831_ui_get_canvas(), LV_COLOR_BLACK, LV_OPA_TRANSP);
          lv_canvas_draw_rect(zm831_ui_get_canvas(), corners[0].x, corners[0].y, ai2vi(corners[2].x - corners[0].x), ai2vi(corners[2].y - corners[0].y), &self->rect_dsc);
          lv_canvas_draw_text(zm831_ui_get_canvas(), corners[0].x, corners[0].y, 120, &self->label_dsc, data, LV_LABEL_ALIGN_AUTO);
          pthread_mutex_unlock(&zm831->ui_mutex);
          self->now = time(NULL);
          break;// only one QR code
        }
      }

      /* clean up */
      zbar_image_destroy(image); // use zbar_image_free_data
      // printf("[imlib_find_blobs] %d %d %d %d %d\n", i, lnk_data.rect.x, lnk_data.rect.y, lnk_data.rect.x + lnk_data.rect.w, lnk_data.rect.y + lnk_data.rect.h);
    }
    return 0;
  }
}
