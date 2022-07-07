
#include "zm831_uvai.hpp"

extern "C"
{
  extern zm831_uv *zm831;

  // ==============================================================================================

  void setup_scr_color_study_app(lv_ui *ui){

    //Write codes color_study_app
    ui->color_study_app = lv_scr_act();

    //Write style LV_OBJ_PART_MAIN for color_study_app
    static lv_style_t style_color_study_app_main;
    lv_style_reset(&style_color_study_app_main);

    //Write style state: LV_STATE_DEFAULT for style_color_study_app_main
    lv_style_set_bg_color(&style_color_study_app_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
    lv_style_set_bg_opa(&style_color_study_app_main, LV_STATE_DEFAULT, 139);
    lv_obj_add_style(ui->color_study_app, LV_OBJ_PART_MAIN, &style_color_study_app_main);

    //Write codes color_study_app_label_top_title
    ui->color_study_app_label_top_title = lv_label_create(ui->color_study_app, NULL);
    lv_label_set_text(ui->color_study_app_label_top_title, "颜色学习");
    lv_label_set_long_mode(ui->color_study_app_label_top_title, LV_LABEL_LONG_BREAK);
    lv_label_set_align(ui->color_study_app_label_top_title, LV_LABEL_ALIGN_CENTER);

    //Write style LV_LABEL_PART_MAIN for color_study_app_label_top_title
    static lv_style_t style_color_study_app_label_top_title_main;
    lv_style_reset(&style_color_study_app_label_top_title_main);

    //Write style state: LV_STATE_DEFAULT for style_color_study_app_label_top_title_main
    lv_style_set_radius(&style_color_study_app_label_top_title_main, LV_STATE_DEFAULT, 0);
    lv_style_set_bg_color(&style_color_study_app_label_top_title_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
    lv_style_set_bg_grad_color(&style_color_study_app_label_top_title_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
    lv_style_set_bg_grad_dir(&style_color_study_app_label_top_title_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
    lv_style_set_bg_opa(&style_color_study_app_label_top_title_main, LV_STATE_DEFAULT, 100);
    lv_style_set_text_color(&style_color_study_app_label_top_title_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
    lv_style_set_text_font(&style_color_study_app_label_top_title_main, LV_STATE_DEFAULT, &lv_font_simsun_18);
    lv_style_set_text_letter_space(&style_color_study_app_label_top_title_main, LV_STATE_DEFAULT, 2);
    lv_style_set_pad_left(&style_color_study_app_label_top_title_main, LV_STATE_DEFAULT, 0);
    lv_style_set_pad_right(&style_color_study_app_label_top_title_main, LV_STATE_DEFAULT, 0);
    lv_style_set_pad_top(&style_color_study_app_label_top_title_main, LV_STATE_DEFAULT, 8);
    lv_style_set_pad_bottom(&style_color_study_app_label_top_title_main, LV_STATE_DEFAULT, 8);
    lv_obj_add_style(ui->color_study_app_label_top_title, LV_LABEL_PART_MAIN, &style_color_study_app_label_top_title_main);
    lv_obj_set_pos(ui->color_study_app_label_top_title, 0, 0);
    lv_obj_set_size(ui->color_study_app_label_top_title, 240, 0);

    //Write codes color_study_app_imgbtn_back
    ui->color_study_app_imgbtn_back = lv_imgbtn_create(ui->color_study_app, NULL);

    //Write style LV_IMGBTN_PART_MAIN for color_study_app_imgbtn_back
    static lv_style_t style_color_study_app_imgbtn_back_main;
    lv_style_reset(&style_color_study_app_imgbtn_back_main);

    //Write style state: LV_STATE_DEFAULT for style_color_study_app_imgbtn_back_main
    lv_style_set_text_color(&style_color_study_app_imgbtn_back_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
    lv_style_set_image_recolor(&style_color_study_app_imgbtn_back_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
    lv_style_set_image_recolor_opa(&style_color_study_app_imgbtn_back_main, LV_STATE_DEFAULT, 0);
    lv_style_set_image_opa(&style_color_study_app_imgbtn_back_main, LV_STATE_DEFAULT, 255);

    //Write style state: LV_STATE_PRESSED for style_color_study_app_imgbtn_back_main
    lv_style_set_text_color(&style_color_study_app_imgbtn_back_main, LV_STATE_PRESSED, lv_color_make(0xFF, 0x33, 0xFF));
    lv_style_set_image_recolor(&style_color_study_app_imgbtn_back_main, LV_STATE_PRESSED, lv_color_make(0x00, 0x00, 0x00));
    lv_style_set_image_recolor_opa(&style_color_study_app_imgbtn_back_main, LV_STATE_PRESSED, 0);

    //Write style state: LV_STATE_CHECKED for style_color_study_app_imgbtn_back_main
    lv_style_set_text_color(&style_color_study_app_imgbtn_back_main, LV_STATE_CHECKED, lv_color_make(0xFF, 0x33, 0xFF));
    lv_style_set_image_recolor(&style_color_study_app_imgbtn_back_main, LV_STATE_CHECKED, lv_color_make(0x00, 0x00, 0x00));
    lv_style_set_image_recolor_opa(&style_color_study_app_imgbtn_back_main, LV_STATE_CHECKED, 0);
    lv_obj_add_style(ui->color_study_app_imgbtn_back, LV_IMGBTN_PART_MAIN, &style_color_study_app_imgbtn_back_main);
    lv_obj_set_pos(ui->color_study_app_imgbtn_back, 20, 180);
    lv_obj_set_size(ui->color_study_app_imgbtn_back, 50, 50);
    lv_imgbtn_set_src(ui->color_study_app_imgbtn_back,LV_BTN_STATE_RELEASED,&_back_alpha_50x50);
    lv_imgbtn_set_checkable(ui->color_study_app_imgbtn_back, true);

    //Write codes color_study_app_imgbtn_clear
    ui->color_study_app_imgbtn_clear = lv_imgbtn_create(ui->color_study_app, NULL);

    //Write style LV_IMGBTN_PART_MAIN for color_study_app_imgbtn_clear
    static lv_style_t style_color_study_app_imgbtn_clear_main;
    lv_style_reset(&style_color_study_app_imgbtn_clear_main);

    //Write style state: LV_STATE_DEFAULT for style_color_study_app_imgbtn_clear_main
    lv_style_set_text_color(&style_color_study_app_imgbtn_clear_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
    lv_style_set_image_recolor(&style_color_study_app_imgbtn_clear_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
    lv_style_set_image_recolor_opa(&style_color_study_app_imgbtn_clear_main, LV_STATE_DEFAULT, 0);
    lv_style_set_image_opa(&style_color_study_app_imgbtn_clear_main, LV_STATE_DEFAULT, 255);

    //Write style state: LV_STATE_PRESSED for style_color_study_app_imgbtn_clear_main
    lv_style_set_text_color(&style_color_study_app_imgbtn_clear_main, LV_STATE_PRESSED, lv_color_make(0xFF, 0x33, 0xFF));
    lv_style_set_image_recolor(&style_color_study_app_imgbtn_clear_main, LV_STATE_PRESSED, lv_color_make(0x00, 0x00, 0x00));
    lv_style_set_image_recolor_opa(&style_color_study_app_imgbtn_clear_main, LV_STATE_PRESSED, 0);

    //Write style state: LV_STATE_CHECKED for style_color_study_app_imgbtn_clear_main
    lv_style_set_text_color(&style_color_study_app_imgbtn_clear_main, LV_STATE_CHECKED, lv_color_make(0xFF, 0x33, 0xFF));
    lv_style_set_image_recolor(&style_color_study_app_imgbtn_clear_main, LV_STATE_CHECKED, lv_color_make(0x00, 0x00, 0x00));
    lv_style_set_image_recolor_opa(&style_color_study_app_imgbtn_clear_main, LV_STATE_CHECKED, 0);
    lv_obj_add_style(ui->color_study_app_imgbtn_clear, LV_IMGBTN_PART_MAIN, &style_color_study_app_imgbtn_clear_main);
    lv_obj_set_pos(ui->color_study_app_imgbtn_clear, 170, 180);
    lv_obj_set_size(ui->color_study_app_imgbtn_clear, 50, 50);
    lv_imgbtn_set_src(ui->color_study_app_imgbtn_clear,LV_BTN_STATE_RELEASED,&_clear_alpha_50x50);
    lv_imgbtn_set_checkable(ui->color_study_app_imgbtn_clear, true);

    //Write codes color_study_app_imgbtn_press
    ui->color_study_app_imgbtn_press = lv_imgbtn_create(ui->color_study_app, NULL);

    //Write style LV_IMGBTN_PART_MAIN for color_study_app_imgbtn_press
    static lv_style_t style_color_study_app_imgbtn_press_main;
    lv_style_reset(&style_color_study_app_imgbtn_press_main);

    //Write style state: LV_STATE_DEFAULT for style_color_study_app_imgbtn_press_main
    lv_style_set_text_color(&style_color_study_app_imgbtn_press_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
    lv_style_set_image_recolor(&style_color_study_app_imgbtn_press_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
    lv_style_set_image_recolor_opa(&style_color_study_app_imgbtn_press_main, LV_STATE_DEFAULT, 0);
    lv_style_set_image_opa(&style_color_study_app_imgbtn_press_main, LV_STATE_DEFAULT, 255);

    //Write style state: LV_STATE_PRESSED for style_color_study_app_imgbtn_press_main
    lv_style_set_text_color(&style_color_study_app_imgbtn_press_main, LV_STATE_PRESSED, lv_color_make(0xFF, 0x33, 0xFF));
    lv_style_set_image_recolor(&style_color_study_app_imgbtn_press_main, LV_STATE_PRESSED, lv_color_make(0x00, 0x00, 0x00));
    lv_style_set_image_recolor_opa(&style_color_study_app_imgbtn_press_main, LV_STATE_PRESSED, 0);

    //Write style state: LV_STATE_CHECKED for style_color_study_app_imgbtn_press_main
    lv_style_set_text_color(&style_color_study_app_imgbtn_press_main, LV_STATE_CHECKED, lv_color_make(0xFF, 0x33, 0xFF));
    lv_style_set_image_recolor(&style_color_study_app_imgbtn_press_main, LV_STATE_CHECKED, lv_color_make(0x00, 0x00, 0x00));
    lv_style_set_image_recolor_opa(&style_color_study_app_imgbtn_press_main, LV_STATE_CHECKED, 0);
    lv_obj_add_style(ui->color_study_app_imgbtn_press, LV_IMGBTN_PART_MAIN, &style_color_study_app_imgbtn_press_main);
    lv_obj_set_pos(ui->color_study_app_imgbtn_press, 88, 170);
    lv_obj_set_size(ui->color_study_app_imgbtn_press, 63, 63);
    lv_imgbtn_set_src(ui->color_study_app_imgbtn_press,LV_BTN_STATE_RELEASED,&_study_alpha_63x63);
    lv_imgbtn_set_checkable(ui->color_study_app_imgbtn_press, true);


  }

#include "imlib.h"

  static struct _function_0x09_
  {
    lv_ui *ui = &zm831->ui;

    bool init = false;
  } function_0x09_app;

  int function_0x09_app_load(zm831_home_app *app);
  int function_0x09_app_loop(zm831_home_app *app);
  int function_0x09_app_exit(zm831_home_app *app);

  zm831_home_app get_function_0x09_app()
  {
    return {function_0x09_app_load, function_0x09_app_loop, function_0x09_app_exit, &function_0x09_app};
  }

  // ==============================================================================================

  static statistics_t get_roi_color_lab(image_t * arg_img, rectangle_t roi)
  {
      fb_alloc_mark();
      //定义直方图通道
      histogram_t hist;
      hist.LBinCount = COLOR_L_MAX - COLOR_L_MIN + 1;
      hist.ABinCount = COLOR_A_MAX - COLOR_A_MIN + 1;
      hist.BBinCount = COLOR_B_MAX - COLOR_B_MIN + 1;
      //分配直方图通道内存
      hist.LBins = (float *)fb_alloc(hist.LBinCount * sizeof(float), FB_ALLOC_NO_HINT);
      hist.ABins = (float *)fb_alloc(hist.ABinCount * sizeof(float), FB_ALLOC_NO_HINT);
      hist.BBins = (float *)fb_alloc(hist.BBinCount * sizeof(float), FB_ALLOC_NO_HINT);
      //获取直方图
      imlib_get_histogram(&hist, arg_img, &roi, NULL, false, NULL);
      //定义统计值
      statistics_t stats;
      //进行直方图统计
      imlib_get_statistics(&stats, (pixformat_t)arg_img->pixfmt, &hist);
      fb_free(hist.BBins);
      fb_free(hist.ABins);
      fb_free(hist.LBins);
      fb_alloc_free_till_mark();
      return stats;
  }

  static void function_0x09_btn_event_app_cb(lv_obj_t *btn, lv_event_t event)
  {
    // printf("btn %p event %d\n", btn, event);
    if (function_0x09_app.ui->color_study_app_imgbtn_back == btn && event == LV_EVENT_SHORT_CLICKED)
    {
      zm831_home_app_select(0);
      return;
    }
  }

  int function_0x09_app_load(zm831_home_app *app)
  {
    auto self = (_function_0x09_ *)app->userdata;

    if (!self->init)
    {
      zm831_home_setup_ui(&self->ui->color_study_app, setup_scr_color_study_app, 500);

      pthread_mutex_lock(&zm831->ui_mutex);
      lv_obj_set_event_cb(self->ui->color_study_app_imgbtn_back, function_0x09_btn_event_app_cb);
      pthread_mutex_unlock(&zm831->ui_mutex);

      self->init = true;
    }
    LIBMAIX_INFO_PRINTF("function_0x09_app_load");
    return 0;
  }

  int function_0x09_app_exit(zm831_home_app *app)
  {
    auto self = (_function_0x09_ *)app->userdata;
    if (self->init)
    {
      zm831_home_clear_ui(&self->ui->color_study_app);
      self->init = false;
    }
    LIBMAIX_INFO_PRINTF("function_0x09_app_exit");
    return 0;
  }

  int function_0x09_app_loop(zm831_home_app *app)
  {
    auto self = (_function_0x09_ *)app->userdata;
    libmaix_err_t err = LIBMAIX_ERR_NONE;
    libmaix_image_t *ai_rgb = NULL;
    if (zm831->ai && LIBMAIX_ERR_NONE == zm831->ai->capture_image(zm831->ai, &ai_rgb))
    {
      // CALC_FPS("function_0x09_app_loop"); // 224x224
    }
    return 0;
  }
}
