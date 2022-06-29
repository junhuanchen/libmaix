
#include "zm831_uvai.hpp"

extern "C"
{
  extern zm831_uv *zm831;

  // ==============================================================================================

  void setup_scr_screen(lv_ui *ui){

    //Write codes screen
    ui->screen = lv_scr_act();

    // //Write style LV_OBJ_PART_MAIN for screen
    // static lv_style_t style_screen_main;
    // lv_style_reset(&style_screen_main);

    // //Write style state: LV_STATE_DEFAULT for style_screen_main
    // lv_style_set_bg_color(&style_screen_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
    // lv_style_set_bg_opa(&style_screen_main, LV_STATE_DEFAULT, 255);
    // lv_obj_add_style(ui->screen, LV_OBJ_PART_MAIN, &style_screen_main);

    //Write codes screen_imgbtn_1
    ui->screen_imgbtn_1 = lv_imgbtn_create(ui->screen, NULL);

    //Write style LV_IMGBTN_PART_MAIN for screen_imgbtn_1
    static lv_style_t style_screen_imgbtn_1_main;
    lv_style_reset(&style_screen_imgbtn_1_main);

    //Write style state: LV_STATE_DEFAULT for style_screen_imgbtn_1_main
    lv_style_set_text_color(&style_screen_imgbtn_1_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
    lv_style_set_image_recolor(&style_screen_imgbtn_1_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
    lv_style_set_image_recolor_opa(&style_screen_imgbtn_1_main, LV_STATE_DEFAULT, 0);
    lv_style_set_image_opa(&style_screen_imgbtn_1_main, LV_STATE_DEFAULT, 255);

    //Write style state: LV_STATE_PRESSED for style_screen_imgbtn_1_main
    lv_style_set_text_color(&style_screen_imgbtn_1_main, LV_STATE_PRESSED, lv_color_make(0xFF, 0x33, 0xFF));
    lv_style_set_image_recolor(&style_screen_imgbtn_1_main, LV_STATE_PRESSED, lv_color_make(0x00, 0x00, 0x00));
    lv_style_set_image_recolor_opa(&style_screen_imgbtn_1_main, LV_STATE_PRESSED, 0);

    //Write style state: LV_STATE_CHECKED for style_screen_imgbtn_1_main
    lv_style_set_text_color(&style_screen_imgbtn_1_main, LV_STATE_CHECKED, lv_color_make(0xFF, 0x33, 0xFF));
    lv_style_set_image_recolor(&style_screen_imgbtn_1_main, LV_STATE_CHECKED, lv_color_make(0x00, 0x00, 0x00));
    lv_style_set_image_recolor_opa(&style_screen_imgbtn_1_main, LV_STATE_CHECKED, 0);
    lv_obj_add_style(ui->screen_imgbtn_1, LV_IMGBTN_PART_MAIN, &style_screen_imgbtn_1_main);
    lv_obj_set_pos(ui->screen_imgbtn_1, 28, 28);
    lv_obj_set_size(ui->screen_imgbtn_1, 172, 181);
    lv_imgbtn_set_src(ui->screen_imgbtn_1,LV_BTN_STATE_RELEASED,&_possum2_alpha_172x181);
    lv_imgbtn_set_checkable(ui->screen_imgbtn_1, true);
  }

  static struct _function_home_
  {
    lv_ui page;
    bool init = false;
  } function_home_app;

  int function_home_app_load(zm831_home_app *app);
  int function_home_app_loop(zm831_home_app *app);
  int function_home_app_exit(zm831_home_app *app);

  zm831_home_app get_function_home_app()
  {
    return {function_home_app_load, function_home_app_loop, function_home_app_exit, &function_home_app};
  }

  // ==============================================================================================

  int function_home_app_load(zm831_home_app *app)
  {
    auto self = (_function_home_ *)app->userdata;
    if (!self->init)
    {
      zm831_home_setup_ui(setup_scr_screen);
      self->init = true;
    }
    LIBMAIX_INFO_PRINTF("function_home_app_load");
    return 0;
  }

  int function_home_app_exit(zm831_home_app *app)
  {
    auto self = (_function_home_ *)app->userdata;
    if (self->init)
    {
      zm831_home_clear_ui();
      self->init = false;
    }
    LIBMAIX_INFO_PRINTF("function_home_app_exit");
    return 0;
  }

  int function_home_app_loop(zm831_home_app *app)
  {
    auto self = (_function_home_ *)app->userdata;
    libmaix_err_t err = LIBMAIX_ERR_NONE;
    libmaix_image_t *ai_rgb = NULL;
    if (zm831->ai && LIBMAIX_ERR_NONE == zm831->ai->capture_image(zm831->ai, &ai_rgb))
    {
      sleep(5);
      zm831_home_app_select(1);
    }
    return 0;
  }
}
