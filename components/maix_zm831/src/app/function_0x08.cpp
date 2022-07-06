
#include "zm831_uvai.hpp"

extern "C"
{
  extern zm831_uv *zm831;

  // ==============================================================================================

  void setup_scr_tagcode_app(lv_ui *ui)
  {

    // Write codes tagcode_app
    ui->tagcode_app = lv_scr_act();

    // Write style LV_OBJ_PART_MAIN for tagcode_app
    static lv_style_t style_tagcode_app_main;
    lv_style_reset(&style_tagcode_app_main);

    // Write style state: LV_STATE_DEFAULT for style_tagcode_app_main
    lv_style_set_bg_color(&style_tagcode_app_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
    lv_style_set_bg_opa(&style_tagcode_app_main, LV_STATE_DEFAULT, 139);
    lv_obj_add_style(ui->tagcode_app, LV_OBJ_PART_MAIN, &style_tagcode_app_main);

    // Write codes tagcode_app_label_top_title
    ui->tagcode_app_label_top_title = lv_label_create(ui->tagcode_app, NULL);
    lv_label_set_text(ui->tagcode_app_label_top_title, "标签码识别");
    lv_label_set_long_mode(ui->tagcode_app_label_top_title, LV_LABEL_LONG_BREAK);
    lv_label_set_align(ui->tagcode_app_label_top_title, LV_LABEL_ALIGN_CENTER);

    // Write style LV_LABEL_PART_MAIN for tagcode_app_label_top_title
    static lv_style_t style_tagcode_app_label_top_title_main;
    lv_style_reset(&style_tagcode_app_label_top_title_main);

    // Write style state: LV_STATE_DEFAULT for style_tagcode_app_label_top_title_main
    lv_style_set_radius(&style_tagcode_app_label_top_title_main, LV_STATE_DEFAULT, 0);
    lv_style_set_bg_color(&style_tagcode_app_label_top_title_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
    lv_style_set_bg_grad_color(&style_tagcode_app_label_top_title_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
    lv_style_set_bg_grad_dir(&style_tagcode_app_label_top_title_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
    lv_style_set_bg_opa(&style_tagcode_app_label_top_title_main, LV_STATE_DEFAULT, 100);
    lv_style_set_text_color(&style_tagcode_app_label_top_title_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
    lv_style_set_text_font(&style_tagcode_app_label_top_title_main, LV_STATE_DEFAULT, &lv_font_simsun_18);
    lv_style_set_text_letter_space(&style_tagcode_app_label_top_title_main, LV_STATE_DEFAULT, 2);
    lv_style_set_pad_left(&style_tagcode_app_label_top_title_main, LV_STATE_DEFAULT, 0);
    lv_style_set_pad_right(&style_tagcode_app_label_top_title_main, LV_STATE_DEFAULT, 0);
    lv_style_set_pad_top(&style_tagcode_app_label_top_title_main, LV_STATE_DEFAULT, 8);
    lv_style_set_pad_bottom(&style_tagcode_app_label_top_title_main, LV_STATE_DEFAULT, 8);
    lv_obj_add_style(ui->tagcode_app_label_top_title, LV_LABEL_PART_MAIN, &style_tagcode_app_label_top_title_main);
    lv_obj_set_pos(ui->tagcode_app_label_top_title, 0, 0);
    lv_obj_set_size(ui->tagcode_app_label_top_title, 240, 0);

    // Write codes tagcode_app_imgbtn_back
    ui->tagcode_app_imgbtn_back = lv_imgbtn_create(ui->tagcode_app, NULL);

    // Write style LV_IMGBTN_PART_MAIN for tagcode_app_imgbtn_back
    static lv_style_t style_tagcode_app_imgbtn_back_main;
    lv_style_reset(&style_tagcode_app_imgbtn_back_main);

    // Write style state: LV_STATE_DEFAULT for style_tagcode_app_imgbtn_back_main
    lv_style_set_text_color(&style_tagcode_app_imgbtn_back_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
    lv_style_set_image_recolor(&style_tagcode_app_imgbtn_back_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
    lv_style_set_image_recolor_opa(&style_tagcode_app_imgbtn_back_main, LV_STATE_DEFAULT, 0);
    lv_style_set_image_opa(&style_tagcode_app_imgbtn_back_main, LV_STATE_DEFAULT, 255);

    // Write style state: LV_STATE_PRESSED for style_tagcode_app_imgbtn_back_main
    lv_style_set_text_color(&style_tagcode_app_imgbtn_back_main, LV_STATE_PRESSED, lv_color_make(0xFF, 0x33, 0xFF));
    lv_style_set_image_recolor(&style_tagcode_app_imgbtn_back_main, LV_STATE_PRESSED, lv_color_make(0x00, 0x00, 0x00));
    lv_style_set_image_recolor_opa(&style_tagcode_app_imgbtn_back_main, LV_STATE_PRESSED, 0);

    // Write style state: LV_STATE_CHECKED for style_tagcode_app_imgbtn_back_main
    lv_style_set_text_color(&style_tagcode_app_imgbtn_back_main, LV_STATE_CHECKED, lv_color_make(0xFF, 0x33, 0xFF));
    lv_style_set_image_recolor(&style_tagcode_app_imgbtn_back_main, LV_STATE_CHECKED, lv_color_make(0x00, 0x00, 0x00));
    lv_style_set_image_recolor_opa(&style_tagcode_app_imgbtn_back_main, LV_STATE_CHECKED, 0);
    lv_obj_add_style(ui->tagcode_app_imgbtn_back, LV_IMGBTN_PART_MAIN, &style_tagcode_app_imgbtn_back_main);
    lv_obj_set_pos(ui->tagcode_app_imgbtn_back, 20, 180);
    lv_obj_set_size(ui->tagcode_app_imgbtn_back, 50, 50);
    lv_imgbtn_set_src(ui->tagcode_app_imgbtn_back, LV_BTN_STATE_RELEASED, &_back_alpha_50x50);
    lv_imgbtn_set_checkable(ui->tagcode_app_imgbtn_back, true);
  }

  static struct _function_0x08_
  {
    lv_ui *ui = &zm831->ui;

    bool init = false;
  } function_0x08_app;

  int function_0x08_app_load(zm831_home_app *app);
  int function_0x08_app_loop(zm831_home_app *app);
  int function_0x08_app_exit(zm831_home_app *app);

  zm831_home_app get_function_0x08_app()
  {
    return {function_0x08_app_load, function_0x08_app_loop, function_0x08_app_exit, &function_0x08_app};
  }

  // ==============================================================================================

  static void function_0x08_btn_event_app_cb(lv_obj_t *btn, lv_event_t event)
  {
    // printf("btn %p event %d\n", btn, event);
    if (function_0x08_app.ui->tagcode_app_imgbtn_back == btn && event == LV_EVENT_SHORT_CLICKED)
    {
      zm831_home_app_select(0);
      return;
    }
  }

  int function_0x08_app_load(zm831_home_app *app)
  {
    auto self = (_function_0x08_ *)app->userdata;

    if (!self->init)
    {
      zm831_home_setup_ui(&self->ui->tagcode_app, setup_scr_tagcode_app, 500);

      pthread_mutex_lock(&zm831->ui_mutex);
      lv_obj_set_event_cb(self->ui->tagcode_app_imgbtn_back, function_0x08_btn_event_app_cb);
      pthread_mutex_unlock(&zm831->ui_mutex);

      self->init = true;
    }
    LIBMAIX_INFO_PRINTF("function_0x08_app_load");
    return 0;
  }

  int function_0x08_app_exit(zm831_home_app *app)
  {
    auto self = (_function_0x08_ *)app->userdata;
    if (self->init)
    {
      zm831_home_clear_ui(&self->ui->tagcode_app);
      self->init = false;
    }
    LIBMAIX_INFO_PRINTF("function_0x08_app_exit");
    return 0;
  }

  int function_0x08_app_loop(zm831_home_app *app)
  {
    auto self = (_function_0x08_ *)app->userdata;
    libmaix_err_t err = LIBMAIX_ERR_NONE;
    libmaix_image_t *ai_rgb = NULL;
    if (zm831->ai && LIBMAIX_ERR_NONE == zm831->ai->capture_image(zm831->ai, &ai_rgb))
    {
      // CALC_FPS("function_0x08_app_loop"); // 224x224
    }
    return 0;
  }
}
