
#include "zm831_uvai.hpp"

extern "C"
{
  extern zm831_uv *zm831;

  // ==============================================================================================

  void setup_scr_color_app(lv_ui *ui)
  {
    // Write codes camera
    ui->color_app = lv_scr_act();

    // Write style LV_OBJ_PART_MAIN for color_app
    static lv_style_t style_color_app_main;
    lv_style_reset(&style_color_app_main);

    // Write style state: LV_STATE_DEFAULT for style_color_app_main
    lv_style_set_bg_color(&style_color_app_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
    lv_style_set_bg_opa(&style_color_app_main, LV_STATE_DEFAULT, 139);
    lv_obj_add_style(ui->color_app, LV_OBJ_PART_MAIN, &style_color_app_main);

    // Write codes color_app_label_top_title
    ui->color_app_label_top_title = lv_label_create(ui->color_app, NULL);
    lv_label_set_text(ui->color_app_label_top_title, "颜色检测");
    lv_label_set_long_mode(ui->color_app_label_top_title, LV_LABEL_LONG_BREAK);
    lv_label_set_align(ui->color_app_label_top_title, LV_LABEL_ALIGN_CENTER);

    // Write style LV_LABEL_PART_MAIN for color_app_label_top_title
    static lv_style_t style_color_app_label_top_title_main;
    lv_style_reset(&style_color_app_label_top_title_main);

    // Write style state: LV_STATE_DEFAULT for style_color_app_label_top_title_main
    lv_style_set_radius(&style_color_app_label_top_title_main, LV_STATE_DEFAULT, 0);
    lv_style_set_bg_color(&style_color_app_label_top_title_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
    lv_style_set_bg_grad_color(&style_color_app_label_top_title_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
    lv_style_set_bg_grad_dir(&style_color_app_label_top_title_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
    lv_style_set_bg_opa(&style_color_app_label_top_title_main, LV_STATE_DEFAULT, 100);
    lv_style_set_text_color(&style_color_app_label_top_title_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
    lv_style_set_text_font(&style_color_app_label_top_title_main, LV_STATE_DEFAULT, &lv_font_simsun_18);
    lv_style_set_text_letter_space(&style_color_app_label_top_title_main, LV_STATE_DEFAULT, 2);
    lv_style_set_pad_left(&style_color_app_label_top_title_main, LV_STATE_DEFAULT, 0);
    lv_style_set_pad_right(&style_color_app_label_top_title_main, LV_STATE_DEFAULT, 0);
    lv_style_set_pad_top(&style_color_app_label_top_title_main, LV_STATE_DEFAULT, 8);
    lv_style_set_pad_bottom(&style_color_app_label_top_title_main, LV_STATE_DEFAULT, 8);
    lv_obj_add_style(ui->color_app_label_top_title, LV_LABEL_PART_MAIN, &style_color_app_label_top_title_main);
    lv_obj_set_pos(ui->color_app_label_top_title, 0, 0);
    lv_obj_set_size(ui->color_app_label_top_title, 240, 0);

    // Write codes color_app_imgbtn_back
    ui->color_app_imgbtn_back = lv_imgbtn_create(ui->color_app, NULL);

    // Write style LV_IMGBTN_PART_MAIN for color_app_imgbtn_back
    static lv_style_t style_color_app_imgbtn_back_main;
    lv_style_reset(&style_color_app_imgbtn_back_main);

    // Write style state: LV_STATE_DEFAULT for style_color_app_imgbtn_back_main
    lv_style_set_text_color(&style_color_app_imgbtn_back_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
    lv_style_set_image_recolor(&style_color_app_imgbtn_back_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
    lv_style_set_image_recolor_opa(&style_color_app_imgbtn_back_main, LV_STATE_DEFAULT, 0);
    lv_style_set_image_opa(&style_color_app_imgbtn_back_main, LV_STATE_DEFAULT, 255);

    // Write style state: LV_STATE_PRESSED for style_color_app_imgbtn_back_main
    lv_style_set_text_color(&style_color_app_imgbtn_back_main, LV_STATE_PRESSED, lv_color_make(0xFF, 0x33, 0xFF));
    lv_style_set_image_recolor(&style_color_app_imgbtn_back_main, LV_STATE_PRESSED, lv_color_make(0x00, 0x00, 0x00));
    lv_style_set_image_recolor_opa(&style_color_app_imgbtn_back_main, LV_STATE_PRESSED, 0);

    // Write style state: LV_STATE_CHECKED for style_color_app_imgbtn_back_main
    lv_style_set_text_color(&style_color_app_imgbtn_back_main, LV_STATE_CHECKED, lv_color_make(0xFF, 0x33, 0xFF));
    lv_style_set_image_recolor(&style_color_app_imgbtn_back_main, LV_STATE_CHECKED, lv_color_make(0x00, 0x00, 0x00));
    lv_style_set_image_recolor_opa(&style_color_app_imgbtn_back_main, LV_STATE_CHECKED, 0);
    lv_obj_add_style(ui->color_app_imgbtn_back, LV_IMGBTN_PART_MAIN, &style_color_app_imgbtn_back_main);
    lv_obj_set_pos(ui->color_app_imgbtn_back, 20, 180);
    lv_obj_set_size(ui->color_app_imgbtn_back, 50, 50);
    lv_imgbtn_set_src(ui->color_app_imgbtn_back, LV_BTN_STATE_RELEASED, &_back_alpha_50x50);
    lv_imgbtn_set_checkable(ui->color_app_imgbtn_back, true);
  }

  #include "imlib.h"

  static struct _function_0x02_
  {
    lv_ui *ui = &zm831->ui;

    lv_color_t bgra_lab_color[4] = {
        {0, 0, 255, 255},  // red
        {0, 255, 0, 255},  // green
        {255, 0, 0, 255},  // blue
        {0, 255, 255, 255} // yellow
    };

    color_thresholds_list_lnk_data_t lab_thresholds[4] = {
        {.LMin = 5, .LMax = 50, .AMin = 30, .AMax = 85, .BMin = -29, .BMax = 72},   //红
        {.LMin = 20, .LMax = 74, .AMin = -60, .AMax = -8, .BMin = -18, .BMax = 62}, //绿
        {.LMin = 5, .LMax = 82, .AMin = 3, .AMax = 57, .BMin = -81, .BMax = -30},   //蓝
        {.LMin = 50, .LMax = 100, .AMin = -2, .AMax = 40, .BMin = 40, .BMax = 90},  //黄
    };

    lv_draw_rect_dsc_t rect_dsc;
    lv_draw_label_dsc_t label_dsc;
    time_t now;

    bool init = false;
  } function_0x02_app;

  int function_0x02_app_load(zm831_home_app *app);
  int function_0x02_app_loop(zm831_home_app *app);
  int function_0x02_app_exit(zm831_home_app *app);

  zm831_home_app get_function_0x02_app()
  {
    return {function_0x02_app_load, function_0x02_app_loop, function_0x02_app_exit, &function_0x02_app};
  }

  // =============================================================================================

  static void function_0x02_btn_event_app_cb(lv_obj_t *btn, lv_event_t event)
  {
    if (function_0x02_app.ui->color_app_imgbtn_back == btn && event == LV_EVENT_SHORT_CLICKED)
    {
      zm831_home_app_select(0);
      return;
    }
  }

  int function_0x02_app_load(zm831_home_app *app)
  {
    auto self = (_function_0x02_ *)app->userdata;

    fb_realloc_init1(1 * 1024 * 1024);

    if (!self->init)
    {
      lv_draw_rect_dsc_init(&self->rect_dsc);
      self->rect_dsc.radius = 5;
      self->rect_dsc.bg_opa = LV_OPA_50;
      self->rect_dsc.border_width = 2;
      self->rect_dsc.border_opa = LV_OPA_50;
      self->rect_dsc.border_color = {0x00, 0x00, 0xFF, 0x9f};

      lv_draw_label_dsc_init(&self->label_dsc);
      self->label_dsc.color = LV_COLOR_YELLOW;

      zm831_home_setup_ui(&self->ui->color_app, setup_scr_color_app, 500);

      pthread_mutex_lock(&zm831->ui_mutex);
      lv_obj_set_event_cb(self->ui->color_app_imgbtn_back, function_0x02_btn_event_app_cb);
      pthread_mutex_unlock(&zm831->ui_mutex);

      self->init = true;
    }

    LIBMAIX_INFO_PRINTF("function_0x02_app_load");
    return 0;
  }

  int function_0x02_app_exit(zm831_home_app *app)
  {
    auto self = (_function_0x02_ *)app->userdata;

    fb_alloc_close0();

    if (self->init)
    {
      zm831_home_clear_ui(&self->ui->color_app);
      self->init = false;
    }
    LIBMAIX_INFO_PRINTF("function_0x02_app_exit");
    return 0;
  }

  int function_0x02_app_loop(zm831_home_app *app)
  {
    auto self = (_function_0x02_ *)app->userdata;
    libmaix_err_t err = LIBMAIX_ERR_NONE;
    libmaix_image_t *ai_rgb = NULL;
    if (zm831->ai && LIBMAIX_ERR_NONE == zm831->ai->capture_image(zm831->ai, &ai_rgb))
    {
      // CALC_FPS("function_0x02_app_loop"); // 224x224x3

      image_t imlib_img, *img = &imlib_img;
      {
        img->w = ai_rgb->width;
        img->h = ai_rgb->height;
        img->data = (uint8_t *)ai_rgb->data;
        img->size = ai_rgb->width * ai_rgb->height * 3;
        img->is_data_alloc = NULL;
        img->pixfmt = PIXFORMAT_RGB888;
      }

      fb_alloc_mark();

      rectangle_t roi = {.x = 0, .y = 0, .w = (int16_t)img->w, .h = (int16_t)img->h};

      {
        list_t thresholds;
        imlib_list_init(&thresholds, sizeof(color_thresholds_list_lnk_data_t));
        bool invert = false;
        rectangle_t roi = {
            .x = 0,
            .y = 0,
            .w = (int16_t)img->w,
            .h = (int16_t)img->h,
        };
        unsigned int x_stride = 10;
        unsigned int y_stride = 10;
        unsigned int area_threshold = 100;
        unsigned int pixels_threshold = 100;
        bool merge = true;
        int margin = 0;
        unsigned int x_hist_bins_max = 0;
        unsigned int y_hist_bins_max = 0;

        if (self->now < time(NULL))
        {
          zm831_ui_show_clear();
        }

        list_t out;
        for (int i = 0; i < 4; i++)
        {
          list_push_back(&thresholds, &self->lab_thresholds[i]);
          imlib_find_blobs(&out, img, &roi, x_stride, y_stride, &thresholds, invert, area_threshold,
                           pixels_threshold, merge, margin, NULL, NULL, NULL, NULL, x_hist_bins_max, y_hist_bins_max);
          list_clear(&thresholds);
          self->rect_dsc.border_color = self->bgra_lab_color[i];
          self->rect_dsc.bg_color = self->bgra_lab_color[i];
          for (size_t m = 0; list_size(&out); m++)
          {
            find_blobs_list_lnk_data_t lnk_data;
            list_pop_front(&out, &lnk_data);

            pthread_mutex_lock(&zm831->ui_mutex);
            lv_canvas_draw_rect(zm831_ui_get_canvas(), lnk_data.rect.x, lnk_data.rect.y, ai2vi(lnk_data.rect.w), ai2vi(lnk_data.rect.h), &self->rect_dsc);
            pthread_mutex_unlock(&zm831->ui_mutex);

            uint8_t cmd[5];
            cmd[0] = 0x02;
            cmd[1] = lnk_data.rect.x;
            cmd[2] = lnk_data.rect.y;
            cmd[3] = lnk_data.rect.w;
            cmd[4] = lnk_data.rect.h;
            extern int zm831_protocol_send(uint8_t * data, int len);
            zm831_protocol_send(cmd, sizeof(cmd));

            self->now = time(NULL);

            // printf("[imlib_find_blobs] %d %d %d %d %d\n", i, lnk_data.rect.x, lnk_data.rect.y, lnk_data.rect.x + lnk_data.rect.w, lnk_data.rect.y + lnk_data.rect.h);
          }
        }
      }

      fb_alloc_free_till_mark();
    }
    return 0;
  }
}
