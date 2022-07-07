
#include "zm831_uvai.hpp"

extern "C"
{
  extern zm831_uv *zm831;

  // ==============================================================================================

  void setup_scr_cube_app(lv_ui *ui)
  {

    // Write codes cube_app
    ui->cube_app = lv_obj_create(NULL, NULL);

    // Write style LV_OBJ_PART_MAIN for cube_app
    static lv_style_t style_cube_app_main;
    lv_style_reset(&style_cube_app_main);

    // Write style state: LV_STATE_DEFAULT for style_cube_app_main
    lv_style_set_bg_color(&style_cube_app_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
    lv_style_set_bg_opa(&style_cube_app_main, LV_STATE_DEFAULT, 139);
    lv_obj_add_style(ui->cube_app, LV_OBJ_PART_MAIN, &style_cube_app_main);

    // Write codes cube_app_label_top_title
    ui->cube_app_label_top_title = lv_label_create(ui->cube_app, NULL);
    lv_label_set_text(ui->cube_app_label_top_title, "魔方识别");
    lv_label_set_long_mode(ui->cube_app_label_top_title, LV_LABEL_LONG_BREAK);
    lv_label_set_align(ui->cube_app_label_top_title, LV_LABEL_ALIGN_CENTER);

    // Write style LV_LABEL_PART_MAIN for cube_app_label_top_title
    static lv_style_t style_cube_app_label_top_title_main;
    lv_style_reset(&style_cube_app_label_top_title_main);

    // Write style state: LV_STATE_DEFAULT for style_cube_app_label_top_title_main
    lv_style_set_radius(&style_cube_app_label_top_title_main, LV_STATE_DEFAULT, 0);
    lv_style_set_bg_color(&style_cube_app_label_top_title_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
    lv_style_set_bg_grad_color(&style_cube_app_label_top_title_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
    lv_style_set_bg_grad_dir(&style_cube_app_label_top_title_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
    lv_style_set_bg_opa(&style_cube_app_label_top_title_main, LV_STATE_DEFAULT, 100);
    lv_style_set_text_color(&style_cube_app_label_top_title_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
    lv_style_set_text_font(&style_cube_app_label_top_title_main, LV_STATE_DEFAULT, &lv_font_simsun_18);
    lv_style_set_text_letter_space(&style_cube_app_label_top_title_main, LV_STATE_DEFAULT, 2);
    lv_style_set_pad_left(&style_cube_app_label_top_title_main, LV_STATE_DEFAULT, 0);
    lv_style_set_pad_right(&style_cube_app_label_top_title_main, LV_STATE_DEFAULT, 0);
    lv_style_set_pad_top(&style_cube_app_label_top_title_main, LV_STATE_DEFAULT, 8);
    lv_style_set_pad_bottom(&style_cube_app_label_top_title_main, LV_STATE_DEFAULT, 8);
    lv_obj_add_style(ui->cube_app_label_top_title, LV_LABEL_PART_MAIN, &style_cube_app_label_top_title_main);
    lv_obj_set_pos(ui->cube_app_label_top_title, 0, 0);
    lv_obj_set_size(ui->cube_app_label_top_title, 240, 0);

    // Write codes cube_app_imgbtn_back
    ui->cube_app_imgbtn_back = lv_imgbtn_create(ui->cube_app, NULL);

    // Write style LV_IMGBTN_PART_MAIN for cube_app_imgbtn_back
    static lv_style_t style_cube_app_imgbtn_back_main;
    lv_style_reset(&style_cube_app_imgbtn_back_main);

    // Write style state: LV_STATE_DEFAULT for style_cube_app_imgbtn_back_main
    lv_style_set_text_color(&style_cube_app_imgbtn_back_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
    lv_style_set_image_recolor(&style_cube_app_imgbtn_back_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
    lv_style_set_image_recolor_opa(&style_cube_app_imgbtn_back_main, LV_STATE_DEFAULT, 0);
    lv_style_set_image_opa(&style_cube_app_imgbtn_back_main, LV_STATE_DEFAULT, 255);

    // Write style state: LV_STATE_PRESSED for style_cube_app_imgbtn_back_main
    lv_style_set_text_color(&style_cube_app_imgbtn_back_main, LV_STATE_PRESSED, lv_color_make(0xFF, 0x33, 0xFF));
    lv_style_set_image_recolor(&style_cube_app_imgbtn_back_main, LV_STATE_PRESSED, lv_color_make(0x00, 0x00, 0x00));
    lv_style_set_image_recolor_opa(&style_cube_app_imgbtn_back_main, LV_STATE_PRESSED, 0);

    // Write style state: LV_STATE_CHECKED for style_cube_app_imgbtn_back_main
    lv_style_set_text_color(&style_cube_app_imgbtn_back_main, LV_STATE_CHECKED, lv_color_make(0xFF, 0x33, 0xFF));
    lv_style_set_image_recolor(&style_cube_app_imgbtn_back_main, LV_STATE_CHECKED, lv_color_make(0x00, 0x00, 0x00));
    lv_style_set_image_recolor_opa(&style_cube_app_imgbtn_back_main, LV_STATE_CHECKED, 0);
    lv_obj_add_style(ui->cube_app_imgbtn_back, LV_IMGBTN_PART_MAIN, &style_cube_app_imgbtn_back_main);
    lv_obj_set_pos(ui->cube_app_imgbtn_back, 20, 180);
    lv_obj_set_size(ui->cube_app_imgbtn_back, 50, 50);
    lv_imgbtn_set_src(ui->cube_app_imgbtn_back, LV_BTN_STATE_RELEASED, &_back_alpha_50x50);
    lv_imgbtn_set_checkable(ui->cube_app_imgbtn_back, true);

    // Write codes cube_app_imgbtn_clear
    ui->cube_app_imgbtn_clear = lv_imgbtn_create(ui->cube_app, NULL);

    // Write style LV_IMGBTN_PART_MAIN for cube_app_imgbtn_clear
    static lv_style_t style_cube_app_imgbtn_clear_main;
    lv_style_reset(&style_cube_app_imgbtn_clear_main);

    // Write style state: LV_STATE_DEFAULT for style_cube_app_imgbtn_clear_main
    lv_style_set_text_color(&style_cube_app_imgbtn_clear_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
    lv_style_set_image_recolor(&style_cube_app_imgbtn_clear_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
    lv_style_set_image_recolor_opa(&style_cube_app_imgbtn_clear_main, LV_STATE_DEFAULT, 0);
    lv_style_set_image_opa(&style_cube_app_imgbtn_clear_main, LV_STATE_DEFAULT, 255);

    // Write style state: LV_STATE_PRESSED for style_cube_app_imgbtn_clear_main
    lv_style_set_text_color(&style_cube_app_imgbtn_clear_main, LV_STATE_PRESSED, lv_color_make(0xFF, 0x33, 0xFF));
    lv_style_set_image_recolor(&style_cube_app_imgbtn_clear_main, LV_STATE_PRESSED, lv_color_make(0x00, 0x00, 0x00));
    lv_style_set_image_recolor_opa(&style_cube_app_imgbtn_clear_main, LV_STATE_PRESSED, 0);

    // Write style state: LV_STATE_CHECKED for style_cube_app_imgbtn_clear_main
    lv_style_set_text_color(&style_cube_app_imgbtn_clear_main, LV_STATE_CHECKED, lv_color_make(0xFF, 0x33, 0xFF));
    lv_style_set_image_recolor(&style_cube_app_imgbtn_clear_main, LV_STATE_CHECKED, lv_color_make(0x00, 0x00, 0x00));
    lv_style_set_image_recolor_opa(&style_cube_app_imgbtn_clear_main, LV_STATE_CHECKED, 0);
    lv_obj_add_style(ui->cube_app_imgbtn_clear, LV_IMGBTN_PART_MAIN, &style_cube_app_imgbtn_clear_main);
    lv_obj_set_pos(ui->cube_app_imgbtn_clear, 170, 180);
    lv_obj_set_size(ui->cube_app_imgbtn_clear, 50, 50);
    lv_imgbtn_set_src(ui->cube_app_imgbtn_clear, LV_BTN_STATE_RELEASED, &_clear_alpha_50x50);
    lv_imgbtn_set_checkable(ui->cube_app_imgbtn_clear, true);

    // Write codes cube_app_imgbtn_press
    ui->cube_app_imgbtn_press = lv_imgbtn_create(ui->cube_app, NULL);

    // Write style LV_IMGBTN_PART_MAIN for cube_app_imgbtn_press
    static lv_style_t style_cube_app_imgbtn_press_main;
    lv_style_reset(&style_cube_app_imgbtn_press_main);

    // Write style state: LV_STATE_DEFAULT for style_cube_app_imgbtn_press_main
    lv_style_set_text_color(&style_cube_app_imgbtn_press_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
    lv_style_set_image_recolor(&style_cube_app_imgbtn_press_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
    lv_style_set_image_recolor_opa(&style_cube_app_imgbtn_press_main, LV_STATE_DEFAULT, 0);
    lv_style_set_image_opa(&style_cube_app_imgbtn_press_main, LV_STATE_DEFAULT, 255);

    // Write style state: LV_STATE_PRESSED for style_cube_app_imgbtn_press_main
    lv_style_set_text_color(&style_cube_app_imgbtn_press_main, LV_STATE_PRESSED, lv_color_make(0xFF, 0x33, 0xFF));
    lv_style_set_image_recolor(&style_cube_app_imgbtn_press_main, LV_STATE_PRESSED, lv_color_make(0x00, 0x00, 0x00));
    lv_style_set_image_recolor_opa(&style_cube_app_imgbtn_press_main, LV_STATE_PRESSED, 0);

    // Write style state: LV_STATE_CHECKED for style_cube_app_imgbtn_press_main
    lv_style_set_text_color(&style_cube_app_imgbtn_press_main, LV_STATE_CHECKED, lv_color_make(0xFF, 0x33, 0xFF));
    lv_style_set_image_recolor(&style_cube_app_imgbtn_press_main, LV_STATE_CHECKED, lv_color_make(0x00, 0x00, 0x00));
    lv_style_set_image_recolor_opa(&style_cube_app_imgbtn_press_main, LV_STATE_CHECKED, 0);
    lv_obj_add_style(ui->cube_app_imgbtn_press, LV_IMGBTN_PART_MAIN, &style_cube_app_imgbtn_press_main);
    lv_obj_set_pos(ui->cube_app_imgbtn_press, 88, 170);
    lv_obj_set_size(ui->cube_app_imgbtn_press, 63, 63);
    lv_imgbtn_set_src(ui->cube_app_imgbtn_press, LV_BTN_STATE_RELEASED, &_study_alpha_63x63);
    lv_imgbtn_set_checkable(ui->cube_app_imgbtn_press, true);
  }
  
  #include "imlib.h"

  static struct _function_0x14_
  {
    lv_ui *ui = &zm831->ui;

    rectangle_t roi[10] = {
            {.x = 46 , .y = 46 , .w = 148, .h = 148},
            {.x = 64 , .y = 64 , .w = 13 , .h = 13 },
            {.x = 113, .y = 64 , .w = 13 , .h = 13 },
            {.x = 163, .y = 64 , .w = 13 , .h = 13 },
            {.x = 64 , .y = 113, .w = 13 , .h = 13 },
            {.x = 113, .y = 113, .w = 13 , .h = 13 },
            {.x = 163, .y = 113, .w = 13 , .h = 13 },
            {.x = 64 , .y = 163, .w = 13 , .h = 13 },
            {.x = 113, .y = 163, .w = 13 , .h = 13 },
            {.x = 163, .y = 163, .w = 13 , .h = 13 },
        };
    // [(0, 0, 15, 15),(15, 0, 30, 15),(30, 0, 45, 15), 
    // (0, 15, 15, 30), (15, 15, 30, 30),(30, 15, 45, 30),
    // (0, 30, 15, 45),  (15, 30, 30, 45),   (30, 30, 45, 45)]
    rectangle_t roi_ui[9] = {
            {.x = 0  , .y = 0  , .w = 15 , .h = 15 },
            {.x = 15 , .y = 0  , .w = 15 , .h = 15 },
            {.x = 30 , .y = 0  , .w = 15 , .h = 15 },
            {.x = 0  , .y = 15 , .w = 15 , .h = 15 },
            {.x = 15 , .y = 15 , .w = 15 , .h = 15 },
            {.x = 30 , .y = 15 , .w = 15 , .h = 15 },
            {.x = 0  , .y = 30 , .w = 15 , .h = 15 },
            {.x = 15 , .y = 30 , .w = 15 , .h = 15 },
            {.x = 30 , .y = 30 , .w = 15 , .h = 15 },
        };

    lv_draw_rect_dsc_t rect_dsc;
    lv_draw_label_dsc_t label_dsc;
    time_t now;

    bool init = false;
  } function_0x14_app;

  int function_0x14_app_load(zm831_home_app *app);
  int function_0x14_app_loop(zm831_home_app *app);
  int function_0x14_app_exit(zm831_home_app *app);

  zm831_home_app get_function_0x14_app()
  {
    return {function_0x14_app_load, function_0x14_app_loop, function_0x14_app_exit, &function_0x14_app};
  }

  // ==============================================================================================

  static void function_0x14_btn_event_app_cb(lv_obj_t *btn, lv_event_t event)
  {
    // printf("btn %p event %d\n", btn, event);
    if (function_0x14_app.ui->cube_app_imgbtn_back == btn && event == LV_EVENT_SHORT_CLICKED)
    {
      zm831_home_app_select(0);
      return;
    }
  }

  int function_0x14_app_load(zm831_home_app *app)
  {
    auto self = (_function_0x14_ *)app->userdata;

    fb_realloc_init1(1 * 1024 * 1024);

    if (!self->init)
    {
      zm831_home_setup_ui(&self->ui->cube_app, setup_scr_cube_app, 500);

      lv_draw_rect_dsc_init(&self->rect_dsc);
      self->rect_dsc.radius = 5;
      self->rect_dsc.bg_opa = LV_OPA_50;
      self->rect_dsc.border_width = 2;
      self->rect_dsc.border_opa = LV_OPA_50;
      self->rect_dsc.border_color = {0x00, 0x00, 0xFF, 0x9f};

      lv_draw_label_dsc_init(&self->label_dsc);
      self->label_dsc.color = LV_COLOR_YELLOW;

      pthread_mutex_lock(&zm831->ui_mutex);
      lv_obj_set_event_cb(self->ui->cube_app_imgbtn_back, function_0x14_btn_event_app_cb);
      pthread_mutex_unlock(&zm831->ui_mutex);

      self->init = true;
    }
    LIBMAIX_INFO_PRINTF("function_0x14_app_load");
    return 0;
  }

  int function_0x14_app_exit(zm831_home_app *app)
  {
    auto self = (_function_0x14_ *)app->userdata;

    fb_alloc_close0();

    if (self->init)
    {
      zm831_home_clear_ui(&self->ui->cube_app);
      self->init = false;
    }
    LIBMAIX_INFO_PRINTF("function_0x14_app_exit");
    return 0;
  }

  int function_0x14_app_loop(zm831_home_app *app)
  {
    auto self = (_function_0x14_ *)app->userdata;
    libmaix_err_t err = LIBMAIX_ERR_NONE;
    libmaix_image_t *ai_rgb = NULL;
    if (zm831->ai && LIBMAIX_ERR_NONE == zm831->ai->capture_image(zm831->ai, &ai_rgb))
    {
      // CALC_FPS("function_0x14_app_loop"); // 224x224

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

      //定义直方图通道
      histogram_t hist;
      hist.LBinCount = COLOR_L_MAX-COLOR_L_MIN + 1;
      hist.ABinCount = COLOR_A_MAX-COLOR_A_MIN + 1;
      hist.BBinCount = COLOR_B_MAX-COLOR_B_MIN + 1;
      //分配直方图通道内存
      hist.LBins = fb_alloc(hist.LBinCount * sizeof(float), FB_ALLOC_NO_HINT);
      hist.ABins = fb_alloc(hist.ABinCount * sizeof(float), FB_ALLOC_NO_HINT);
      hist.BBins = fb_alloc(hist.BBinCount * sizeof(float), FB_ALLOC_NO_HINT);
      simple_color_t tmp_lab[9];
      for( int i = 0; i < 10; ++ i){
          if(!i){
          //     libmaix_cv_image_draw_rectangle(self->io->zhongming_ui_data.ui_root_img, roi[i].x, roi[i].y, roi[i].x + roi[i].w, 
          //                                                     roi[i].y + roi[i].h, self->io->libmaix_cv_colou[4], 1);
              continue;
          } 
          //获取直方图
          imlib_get_histogram(&hist, img, &self->roi[i], NULL, false, NULL);
          //进行直方图统计
          statistics_t stats;
          imlib_get_statistics(&stats, (pixformat_t)img->pixfmt, &hist);
          //get color
          int piexs = COLOR_LAB_TO_RGB888(stats.LMode, stats.AMode, stats.BMode);
          // self->io->libmaix_cv_colou[6].rgb888.b = COLOR_RGB888_TO_R8(piexs);
          // self->io->libmaix_cv_colou[6].rgb888.g = COLOR_RGB888_TO_G8(piexs);
          // self->io->libmaix_cv_colou[6].rgb888.r = COLOR_RGB888_TO_B8(piexs);
          // self->io->libmaix_cv_colou[6].rgb888.a = 255;

          // agre_data[AGRE_NUM + ((i - 1) * 3) + 1 ] = COLOR_RGB888_TO_R8(piexs);
          // agre_data[AGRE_NUM + ((i - 1) * 3) + 2 ] = COLOR_RGB888_TO_G8(piexs);
          // agre_data[AGRE_NUM + ((i - 1) * 3) + 3 ] = COLOR_RGB888_TO_B8(piexs);

          int point[2];
          point[0] = self->roi[i].x + self->roi[i].w;
          point[1] = self->roi[i].y + self->roi[i].h;

          // //do ui
          // libmaix_cv_image_draw_rectangle(self->io->zhongming_ui_data.ui_root_img, roi[i].x, roi[i].y, roi[i].x + roi[i].w, 
          //                                                 roi[i].y + roi[i].h, self->io->libmaix_cv_colou[1], 1);
          // point[0] = roi_ui[i-1].x + roi_ui[i-1].w;
          // point[1] = roi_ui[i-1].y + roi_ui[i-1].h;
          // libmaix_cv_image_draw_rectangle(self->io->zhongming_ui_data.ui_root_img, roi_ui[i-1].x, roi_ui[i-1].y, point[0], point[1], 
          //                                                     self->io->libmaix_cv_colou[6], -1);

          // libmaix_cv_image_draw_rectangle(self->io->zhongming_ui_data.ui_root_img, roi_ui[i-1].x, roi_ui[i-1].y, point[0], point[1], 
          //                                                     self->io->libmaix_cv_colou[4], 1);
      }
      //释放直方图通道内存
      fb_free(hist.BBins);
      fb_free(hist.ABins);
      fb_free(hist.LBins);

      fb_alloc_free_till_mark();
    }
    return 0;
  }
}
