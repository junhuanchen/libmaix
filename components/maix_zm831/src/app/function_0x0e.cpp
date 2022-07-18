
#include "zm831_uvai.hpp"

extern "C"
{
  extern zm831_uv *zm831;

  // ==============================================================================================

  void setup_scr_five_road_app(lv_ui *ui)
  {

    // Write codes five_road_app
    ui->five_road_app = lv_scr_act();

    // Write style LV_OBJ_PART_MAIN for five_road_app
    static lv_style_t style_five_road_app_main;
    lv_style_reset(&style_five_road_app_main);

    // Write style state: LV_STATE_DEFAULT for style_five_road_app_main
    lv_style_set_bg_color(&style_five_road_app_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
    lv_style_set_bg_opa(&style_five_road_app_main, LV_STATE_DEFAULT, 0);
    lv_obj_add_style(ui->five_road_app, LV_OBJ_PART_MAIN, &style_five_road_app_main);

    // Write codes five_road_app_label_top_title
    ui->five_road_app_label_top_title = lv_label_create(ui->five_road_app, NULL);
    lv_label_set_text(ui->five_road_app_label_top_title, "五通道巡线");
    lv_label_set_long_mode(ui->five_road_app_label_top_title, LV_LABEL_LONG_BREAK);
    lv_label_set_align(ui->five_road_app_label_top_title, LV_LABEL_ALIGN_CENTER);

    // Write style LV_LABEL_PART_MAIN for five_road_app_label_top_title
    static lv_style_t style_five_road_app_label_top_title_main;
    lv_style_reset(&style_five_road_app_label_top_title_main);

    // Write style state: LV_STATE_DEFAULT for style_five_road_app_label_top_title_main
    lv_style_set_radius(&style_five_road_app_label_top_title_main, LV_STATE_DEFAULT, 0);
    lv_style_set_bg_color(&style_five_road_app_label_top_title_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
    lv_style_set_bg_grad_color(&style_five_road_app_label_top_title_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
    lv_style_set_bg_grad_dir(&style_five_road_app_label_top_title_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
    lv_style_set_bg_opa(&style_five_road_app_label_top_title_main, LV_STATE_DEFAULT, 100);
    lv_style_set_text_color(&style_five_road_app_label_top_title_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
    lv_style_set_text_font(&style_five_road_app_label_top_title_main, LV_STATE_DEFAULT, &lv_font_simsun_18);
    lv_style_set_text_letter_space(&style_five_road_app_label_top_title_main, LV_STATE_DEFAULT, 2);
    lv_style_set_pad_left(&style_five_road_app_label_top_title_main, LV_STATE_DEFAULT, 0);
    lv_style_set_pad_right(&style_five_road_app_label_top_title_main, LV_STATE_DEFAULT, 0);
    lv_style_set_pad_top(&style_five_road_app_label_top_title_main, LV_STATE_DEFAULT, 8);
    lv_style_set_pad_bottom(&style_five_road_app_label_top_title_main, LV_STATE_DEFAULT, 8);
    lv_obj_add_style(ui->five_road_app_label_top_title, LV_LABEL_PART_MAIN, &style_five_road_app_label_top_title_main);
    lv_obj_set_pos(ui->five_road_app_label_top_title, 0, 0);
    lv_obj_set_size(ui->five_road_app_label_top_title, 240, 0);

    // Write codes five_road_app_imgbtn_back
    ui->five_road_app_imgbtn_back = lv_imgbtn_create(ui->five_road_app, NULL);

    // Write style LV_IMGBTN_PART_MAIN for five_road_app_imgbtn_back
    static lv_style_t style_five_road_app_imgbtn_back_main;
    lv_style_reset(&style_five_road_app_imgbtn_back_main);

    // Write style state: LV_STATE_DEFAULT for style_five_road_app_imgbtn_back_main
    lv_style_set_text_color(&style_five_road_app_imgbtn_back_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
    lv_style_set_image_recolor(&style_five_road_app_imgbtn_back_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
    lv_style_set_image_recolor_opa(&style_five_road_app_imgbtn_back_main, LV_STATE_DEFAULT, 0);
    lv_style_set_image_opa(&style_five_road_app_imgbtn_back_main, LV_STATE_DEFAULT, 255);

    // Write style state: LV_STATE_PRESSED for style_five_road_app_imgbtn_back_main
    lv_style_set_text_color(&style_five_road_app_imgbtn_back_main, LV_STATE_PRESSED, lv_color_make(0xFF, 0x33, 0xFF));
    lv_style_set_image_recolor(&style_five_road_app_imgbtn_back_main, LV_STATE_PRESSED, lv_color_make(0x00, 0x00, 0x00));
    lv_style_set_image_recolor_opa(&style_five_road_app_imgbtn_back_main, LV_STATE_PRESSED, 0);

    // Write style state: LV_STATE_CHECKED for style_five_road_app_imgbtn_back_main
    lv_style_set_text_color(&style_five_road_app_imgbtn_back_main, LV_STATE_CHECKED, lv_color_make(0xFF, 0x33, 0xFF));
    lv_style_set_image_recolor(&style_five_road_app_imgbtn_back_main, LV_STATE_CHECKED, lv_color_make(0x00, 0x00, 0x00));
    lv_style_set_image_recolor_opa(&style_five_road_app_imgbtn_back_main, LV_STATE_CHECKED, 0);
    lv_obj_add_style(ui->five_road_app_imgbtn_back, LV_IMGBTN_PART_MAIN, &style_five_road_app_imgbtn_back_main);
    lv_obj_set_pos(ui->five_road_app_imgbtn_back, 20, 180);
    lv_obj_set_size(ui->five_road_app_imgbtn_back, 50, 50);
    lv_imgbtn_set_src(ui->five_road_app_imgbtn_back, LV_BTN_STATE_RELEASED, &_back_alpha_50x50);
    lv_imgbtn_set_checkable(ui->five_road_app_imgbtn_back, true);

    // Write codes five_road_app_imgbtn_change_color
    ui->five_road_app_imgbtn_change_color = lv_imgbtn_create(ui->five_road_app, NULL);

    // Write style LV_IMGBTN_PART_MAIN for five_road_app_imgbtn_change_color
    static lv_style_t style_five_road_app_imgbtn_change_color_main;
    lv_style_reset(&style_five_road_app_imgbtn_change_color_main);

    // Write style state: LV_STATE_DEFAULT for style_five_road_app_imgbtn_change_color_main
    lv_style_set_text_color(&style_five_road_app_imgbtn_change_color_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
    lv_style_set_image_recolor(&style_five_road_app_imgbtn_change_color_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
    lv_style_set_image_recolor_opa(&style_five_road_app_imgbtn_change_color_main, LV_STATE_DEFAULT, 0);
    lv_style_set_image_opa(&style_five_road_app_imgbtn_change_color_main, LV_STATE_DEFAULT, 255);

    // Write style state: LV_STATE_PRESSED for style_five_road_app_imgbtn_change_color_main
    lv_style_set_text_color(&style_five_road_app_imgbtn_change_color_main, LV_STATE_PRESSED, lv_color_make(0xFF, 0x33, 0xFF));
    lv_style_set_image_recolor(&style_five_road_app_imgbtn_change_color_main, LV_STATE_PRESSED, lv_color_make(0x00, 0x00, 0x00));
    lv_style_set_image_recolor_opa(&style_five_road_app_imgbtn_change_color_main, LV_STATE_PRESSED, 0);

    // Write style state: LV_STATE_CHECKED for style_five_road_app_imgbtn_change_color_main
    lv_style_set_text_color(&style_five_road_app_imgbtn_change_color_main, LV_STATE_CHECKED, lv_color_make(0xFF, 0x33, 0xFF));
    lv_style_set_image_recolor(&style_five_road_app_imgbtn_change_color_main, LV_STATE_CHECKED, lv_color_make(0x00, 0x00, 0x00));
    lv_style_set_image_recolor_opa(&style_five_road_app_imgbtn_change_color_main, LV_STATE_CHECKED, 0);
    lv_obj_add_style(ui->five_road_app_imgbtn_change_color, LV_IMGBTN_PART_MAIN, &style_five_road_app_imgbtn_change_color_main);
    lv_obj_set_pos(ui->five_road_app_imgbtn_change_color, 88, 170);
    lv_obj_set_size(ui->five_road_app_imgbtn_change_color, 63, 63);
    lv_imgbtn_set_src(ui->five_road_app_imgbtn_change_color, LV_BTN_STATE_RELEASED, &_home_road5_alpha_63x63);
    lv_imgbtn_set_checkable(ui->five_road_app_imgbtn_change_color, true);
  }

  #include "imlib.h"

  static struct _function_0x0e_
  {
    lv_ui *ui = &zm831->ui;

    color_thresholds_list_lnk_data_t gray_line_threshold = {
        .LMin = 0,
        .LMax = 10,
        .AMin = -9,
        .AMax = 20,
        .BMin = -4,
        .BMax = 22,
    };

    rectangle_t roi[5] = {
        {.x =  0, .y = 200, .w = 64, .h = 24},
        {.x = 64, .y = 200, .w = 64, .h = 24},
        {.x =128, .y = 200, .w = 64, .h = 24},
        {.x =192, .y = 200, .w = 64, .h = 24},
        {.x =256, .y = 200, .w = 64, .h = 24},
    };

    lv_draw_rect_dsc_t rect_dsc;
    lv_draw_line_dsc_t line_dsc;

    bool init = false;
  } function_0x0e_app;

  int function_0x0e_app_load(zm831_home_app *app);
  int function_0x0e_app_loop(zm831_home_app *app);
  int function_0x0e_app_exit(zm831_home_app *app);

  zm831_home_app get_function_0x0e_app()
  {
    return {function_0x0e_app_load, function_0x0e_app_loop, function_0x0e_app_exit, &function_0x0e_app};
  }

  // ==============================================================================================

  static void function_0x0e_btn_event_app_cb(lv_obj_t *btn, lv_event_t event)
  {
    // printf("btn %p event %d\n", btn, event);
    if (function_0x0e_app.ui->five_road_app_imgbtn_back == btn && event == LV_EVENT_SHORT_CLICKED)
    {
      zm831_home_app_select(0);
      return;
    }
  }

  int function_0x0e_app_load(zm831_home_app *app)
  {
    auto self = (_function_0x0e_ *)app->userdata;

    fb_realloc_init1(1 * 1024 * 1024);

    if (!self->init)
    {
      if (NULL != zm831->ai)
      {
        libmaix_cam_destroy(&zm831->ai);
        if (NULL == zm831->ai)
        {
          zm831->ai = libmaix_cam_create(1, 320, 240, 0, 0);
          if (NULL == zm831->ai)
            return -1;
          zm831->ai->start_capture(zm831->ai);
        }
      }

      lv_draw_line_dsc_init(&self->line_dsc);
      self->line_dsc.color = {0x00, 0xFF, 0x00, 0x9f};
      self->line_dsc.width = 3;
      self->line_dsc.opa = LV_OPA_20;

      lv_draw_rect_dsc_init(&self->rect_dsc);
      self->rect_dsc.radius = 5;
      self->rect_dsc.bg_opa = LV_OPA_0;
      self->rect_dsc.border_width = 2;
      self->rect_dsc.border_opa = LV_OPA_80;
      self->rect_dsc.border_color = {0x00, 0x00, 0x00, 0x7f};

      zm831_home_setup_ui(&self->ui->five_road_app, setup_scr_five_road_app, 500);

      pthread_mutex_lock(&zm831->ui_mutex);
      lv_obj_set_event_cb(self->ui->five_road_app_imgbtn_back, function_0x0e_btn_event_app_cb);
      pthread_mutex_unlock(&zm831->ui_mutex);

      self->init = true;
    }
    LIBMAIX_INFO_PRINTF("function_0x0e_app_load");
    return 0;
  }

  int function_0x0e_app_exit(zm831_home_app *app)
  {
    auto self = (_function_0x0e_ *)app->userdata;

    fb_alloc_close0();

    if (self->init)
    {
      zm831_home_clear_ui(&self->ui->five_road_app);

      if (NULL != zm831->ai)
      {
        libmaix_cam_destroy(&zm831->ai);
        if (NULL == zm831->ai)
        {
          zm831->ai = libmaix_cam_create(1, zm831->ai_w, zm831->ai_h, 0, 0);
          if (NULL == zm831->ai)
            return -1;
          zm831->ai->start_capture(zm831->ai);
        }
      }

      self->init = false;
    }
    LIBMAIX_INFO_PRINTF("function_0x0e_app_exit");
    return 0;
  }

  int function_0x0e_app_loop(zm831_home_app *app)
  {
    auto self = (_function_0x0e_ *)app->userdata;
    libmaix_err_t err = LIBMAIX_ERR_NONE;
    libmaix_image_t *ai_rgb = NULL;
    if (zm831->ai && LIBMAIX_ERR_NONE == zm831->ai->capture_image(zm831->ai, &ai_rgb))
    {
      // CALC_FPS("function_0x0e_app_loop"); // 224x224

      fb_alloc_mark();

      list_t thresholds;
      imlib_list_init(&thresholds, sizeof(color_thresholds_list_lnk_data_t));

      image_t imlib_img, *img = &imlib_img;
      {
        img->w = ai_rgb->width;
        img->h = ai_rgb->height;
        img->data = (uint8_t *)ai_rgb->data;
        img->size = ai_rgb->width * ai_rgb->height * 3;
        img->is_data_alloc = NULL;
        img->pixfmt = PIXFORMAT_RGB888;
      }

      list_push_back(&thresholds, &self->gray_line_threshold);

      uint8_t area_part[5] = { 0 };
      bool invert = false;
      uint32_t x_stride = 5;
      uint32_t y_stride = 5;
      uint32_t area_threshold = 10;
      uint32_t pixels_threshold = 10;
      bool merge = true;
      int margin = 0;
      uint32_t x_hist_bins_max = 0;
      uint32_t y_hist_bins_max = 0;
      list_t out;
      for(int i = 0; i < 5 ; ++ i){
          imlib_find_blobs(&out, img, &self->roi[i], x_stride, y_stride, &thresholds, invert,
                  area_threshold, pixels_threshold, merge, margin,
                  NULL, NULL, NULL, NULL, x_hist_bins_max, y_hist_bins_max);
          find_blobs_list_lnk_data_t max_blobs_data;
          if(list_size(&out) > 0)
          {
              int most_pixels = 10;
              for (size_t m = 0; list_size(&out); m++) {
                  find_blobs_list_lnk_data_t lnk_data;
                  list_pop_front(&out, &lnk_data);
                  if(lnk_data.pixels > most_pixels)
                  {
                      most_pixels = lnk_data.pixels;
                      max_blobs_data = lnk_data;
                  }
              }
              area_part[i] = 1;
          }
          else
          {
              area_part[i] = 0;
          }
      }

      uint8_t data[] = { area_part[0], area_part[1], area_part[2], area_part[3], area_part[4] };
      zm831_protocol_send(0x0e, (uint8_t *)data, sizeof(data));

      pthread_mutex_lock(&zm831->ui_mutex);
      lv_canvas_fill_bg(zm831_ui_get_canvas(), LV_COLOR_BLACK, LV_OPA_TRANSP);
      for (size_t i = 0; i < sizeof(area_part); i++)
      {
        if (area_part[i]) lv_canvas_draw_rect(zm831_ui_get_canvas(), self->roi[i].x - 40, self->roi[i].y - 100, self->roi[i].w, self->roi[i].h, &self->rect_dsc);
      }
      pthread_mutex_unlock(&zm831->ui_mutex);

      list_clear(&thresholds);
      fb_alloc_free_till_mark();
    }
    return 0;
  }
}
