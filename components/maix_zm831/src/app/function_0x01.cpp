
#include "zm831_uvai.hpp"

extern "C"
{
  extern zm831_uv *zm831;

  // ==============================================================================================

  void setup_scr_camera(lv_ui *ui)
  {
    // Write codes camera
    ui->photo_app = lv_scr_act();

    // Write codes photo_app_label_top
    ui->photo_app_label_top = lv_label_create(ui->photo_app, NULL);
    lv_label_set_text(ui->photo_app_label_top, "实时拍照");
    lv_label_set_long_mode(ui->photo_app_label_top, LV_LABEL_LONG_BREAK);
    lv_label_set_align(ui->photo_app_label_top, LV_LABEL_ALIGN_CENTER);

    // Write style LV_LABEL_PART_MAIN for photo_app_label_top
    static lv_style_t style_photo_app_label_top_main;
    lv_style_reset(&style_photo_app_label_top_main);

    // Write style state: LV_STATE_DEFAULT for style_photo_app_label_top_main
    lv_style_set_radius(&style_photo_app_label_top_main, LV_STATE_DEFAULT, 0);
    lv_style_set_bg_color(&style_photo_app_label_top_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
    lv_style_set_bg_grad_color(&style_photo_app_label_top_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
    lv_style_set_bg_grad_dir(&style_photo_app_label_top_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
    lv_style_set_bg_opa(&style_photo_app_label_top_main, LV_STATE_DEFAULT, 100);
    lv_style_set_text_color(&style_photo_app_label_top_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
    lv_style_set_text_font(&style_photo_app_label_top_main, LV_STATE_DEFAULT, &lv_font_simsun_15);
    lv_style_set_text_letter_space(&style_photo_app_label_top_main, LV_STATE_DEFAULT, 2);
    lv_style_set_pad_left(&style_photo_app_label_top_main, LV_STATE_DEFAULT, 0);
    lv_style_set_pad_right(&style_photo_app_label_top_main, LV_STATE_DEFAULT, 0);
    lv_style_set_pad_top(&style_photo_app_label_top_main, LV_STATE_DEFAULT, 8);
    lv_style_set_pad_bottom(&style_photo_app_label_top_main, LV_STATE_DEFAULT, 8);
    lv_obj_add_style(ui->photo_app_label_top, LV_LABEL_PART_MAIN, &style_photo_app_label_top_main);
    lv_obj_set_pos(ui->photo_app_label_top, 0, 0);
    lv_obj_set_size(ui->photo_app_label_top, 240, 0);

    // Write codes photo_app_imgbtn_back
    ui->photo_app_imgbtn_back = lv_imgbtn_create(ui->photo_app, NULL);

    // Write style LV_IMGBTN_PART_MAIN for photo_app_imgbtn_back
    static lv_style_t style_photo_app_imgbtn_back_main;
    lv_style_reset(&style_photo_app_imgbtn_back_main);

    // Write style state: LV_STATE_DEFAULT for style_photo_app_imgbtn_back_main
    lv_style_set_text_color(&style_photo_app_imgbtn_back_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
    lv_style_set_image_recolor(&style_photo_app_imgbtn_back_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
    lv_style_set_image_recolor_opa(&style_photo_app_imgbtn_back_main, LV_STATE_DEFAULT, 0);
    lv_style_set_image_opa(&style_photo_app_imgbtn_back_main, LV_STATE_DEFAULT, 255);

    // Write style state: LV_STATE_PRESSED for style_photo_app_imgbtn_back_main
    lv_style_set_text_color(&style_photo_app_imgbtn_back_main, LV_STATE_PRESSED, lv_color_make(0xFF, 0x33, 0xFF));
    lv_style_set_image_recolor(&style_photo_app_imgbtn_back_main, LV_STATE_PRESSED, lv_color_make(0x00, 0x00, 0x00));
    lv_style_set_image_recolor_opa(&style_photo_app_imgbtn_back_main, LV_STATE_PRESSED, 0);

    // Write style state: LV_STATE_CHECKED for style_photo_app_imgbtn_back_main
    lv_style_set_text_color(&style_photo_app_imgbtn_back_main, LV_STATE_CHECKED, lv_color_make(0xFF, 0x33, 0xFF));
    lv_style_set_image_recolor(&style_photo_app_imgbtn_back_main, LV_STATE_CHECKED, lv_color_make(0x00, 0x00, 0x00));
    lv_style_set_image_recolor_opa(&style_photo_app_imgbtn_back_main, LV_STATE_CHECKED, 0);
    lv_obj_add_style(ui->photo_app_imgbtn_back, LV_IMGBTN_PART_MAIN, &style_photo_app_imgbtn_back_main);
    lv_obj_set_pos(ui->photo_app_imgbtn_back, 25, 180);
    lv_obj_set_size(ui->photo_app_imgbtn_back, 50, 50);
    lv_imgbtn_set_src(ui->photo_app_imgbtn_back, LV_BTN_STATE_RELEASED, &_back_alpha_50x50);
    lv_imgbtn_set_checkable(ui->photo_app_imgbtn_back, true);

    // Write codes photo_app_imgbtn_press
    ui->photo_app_imgbtn_press = lv_imgbtn_create(ui->photo_app, NULL);

    // Write style LV_IMGBTN_PART_MAIN for photo_app_imgbtn_press
    static lv_style_t style_photo_app_imgbtn_press_main;
    lv_style_reset(&style_photo_app_imgbtn_press_main);

    // Write style state: LV_STATE_DEFAULT for style_photo_app_imgbtn_press_main
    lv_style_set_text_color(&style_photo_app_imgbtn_press_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
    lv_style_set_image_recolor(&style_photo_app_imgbtn_press_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
    lv_style_set_image_recolor_opa(&style_photo_app_imgbtn_press_main, LV_STATE_DEFAULT, 0);
    lv_style_set_image_opa(&style_photo_app_imgbtn_press_main, LV_STATE_DEFAULT, 255);

    // Write style state: LV_STATE_PRESSED for style_photo_app_imgbtn_press_main
    lv_style_set_text_color(&style_photo_app_imgbtn_press_main, LV_STATE_PRESSED, lv_color_make(0xFF, 0x33, 0xFF));
    lv_style_set_image_recolor(&style_photo_app_imgbtn_press_main, LV_STATE_PRESSED, lv_color_make(0x00, 0x00, 0x00));
    lv_style_set_image_recolor_opa(&style_photo_app_imgbtn_press_main, LV_STATE_PRESSED, 0);

    // Write style state: LV_STATE_CHECKED for style_photo_app_imgbtn_press_main
    lv_style_set_text_color(&style_photo_app_imgbtn_press_main, LV_STATE_CHECKED, lv_color_make(0xFF, 0x33, 0xFF));
    lv_style_set_image_recolor(&style_photo_app_imgbtn_press_main, LV_STATE_CHECKED, lv_color_make(0x00, 0x00, 0x00));
    lv_style_set_image_recolor_opa(&style_photo_app_imgbtn_press_main, LV_STATE_CHECKED, 0);
    lv_obj_add_style(ui->photo_app_imgbtn_press, LV_IMGBTN_PART_MAIN, &style_photo_app_imgbtn_press_main);
    lv_obj_set_pos(ui->photo_app_imgbtn_press, 88.5, 138);
    lv_obj_set_size(ui->photo_app_imgbtn_press, 63, 63);
    lv_imgbtn_set_src(ui->photo_app_imgbtn_press, LV_BTN_STATE_RELEASED, &_press_alpha_63x63);
    lv_imgbtn_set_checkable(ui->photo_app_imgbtn_press, true);

    // Write codes photo_app_imgbtn_clear
    ui->photo_app_imgbtn_clear = lv_imgbtn_create(ui->photo_app, NULL);

    // Write style LV_IMGBTN_PART_MAIN for photo_app_imgbtn_clear
    static lv_style_t style_photo_app_imgbtn_clear_main;
    lv_style_reset(&style_photo_app_imgbtn_clear_main);

    // Write style state: LV_STATE_DEFAULT for style_photo_app_imgbtn_clear_main
    lv_style_set_text_color(&style_photo_app_imgbtn_clear_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
    lv_style_set_image_recolor(&style_photo_app_imgbtn_clear_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
    lv_style_set_image_recolor_opa(&style_photo_app_imgbtn_clear_main, LV_STATE_DEFAULT, 0);
    lv_style_set_image_opa(&style_photo_app_imgbtn_clear_main, LV_STATE_DEFAULT, 255);

    // Write style state: LV_STATE_PRESSED for style_photo_app_imgbtn_clear_main
    lv_style_set_text_color(&style_photo_app_imgbtn_clear_main, LV_STATE_PRESSED, lv_color_make(0xFF, 0x33, 0xFF));
    lv_style_set_image_recolor(&style_photo_app_imgbtn_clear_main, LV_STATE_PRESSED, lv_color_make(0x00, 0x00, 0x00));
    lv_style_set_image_recolor_opa(&style_photo_app_imgbtn_clear_main, LV_STATE_PRESSED, 0);

    // Write style state: LV_STATE_CHECKED for style_photo_app_imgbtn_clear_main
    lv_style_set_text_color(&style_photo_app_imgbtn_clear_main, LV_STATE_CHECKED, lv_color_make(0xFF, 0x33, 0xFF));
    lv_style_set_image_recolor(&style_photo_app_imgbtn_clear_main, LV_STATE_CHECKED, lv_color_make(0x00, 0x00, 0x00));
    lv_style_set_image_recolor_opa(&style_photo_app_imgbtn_clear_main, LV_STATE_CHECKED, 0);
    lv_obj_add_style(ui->photo_app_imgbtn_clear, LV_IMGBTN_PART_MAIN, &style_photo_app_imgbtn_clear_main);
    lv_obj_set_pos(ui->photo_app_imgbtn_clear, 170, 180);
    lv_obj_set_size(ui->photo_app_imgbtn_clear, 50, 50);
    lv_imgbtn_set_src(ui->photo_app_imgbtn_clear, LV_BTN_STATE_RELEASED, &_clear_alpha_50x50);
    lv_imgbtn_set_checkable(ui->photo_app_imgbtn_clear, true);
  }

  static struct _function_0x01_
  {
    lv_ui *ui = &zm831->ui;
    bool is_capture = false;
    bool is_clear = false;

    bool init = false;
  } function_0x01_app;

  int function_0x01_app_load(zm831_home_app *app);
  int function_0x01_app_loop(zm831_home_app *app);
  int function_0x01_app_exit(zm831_home_app *app);

  zm831_home_app get_function_0x01_app()
  {
    return {function_0x01_app_load, function_0x01_app_loop, function_0x01_app_exit, &function_0x01_app};
  }

  // ==============================================================================================

  static int get_fps()
  {
    static int fcnt = 0, fps = 0;
    static struct timespec old, now;
    clock_gettime(CLOCK_MONOTONIC, &now);
    fcnt++;
    if ((now.tv_sec * 1000 + now.tv_nsec / 1000000) - (old.tv_sec * 1000 + old.tv_nsec / 1000000) >= 1000)
    {
      fps = fcnt;
      old = now;
      fcnt = 0;
    }
    return fps;
  }

  static int get_dir_file_nums()
  {
    FILE *fp;
    int file_num = 0;
    fp = popen("ls /root/camera | wc -w", "r");
    fscanf(fp, "%i", &file_num);
    pclose(fp);
    return file_num;
  }

  static void function_0x01_btn_event_app_cb(lv_obj_t *btn, lv_event_t event)
  {
    // printf("btn %p event %d\n", btn, event);
    if (function_0x01_app.ui->photo_app_imgbtn_press == btn && event == LV_EVENT_RELEASED)
    {
      function_0x01_app.is_capture = true;
      return;
    }
    if (function_0x01_app.ui->photo_app_imgbtn_back == btn && event == LV_EVENT_RELEASED)
    {
      zm831_home_app_select(0);
      return;
    }
    if (function_0x01_app.ui->photo_app_imgbtn_clear == btn && event == LV_EVENT_RELEASED)
    {
      function_0x01_app.is_clear = true;
      return;
    }
  }

  int function_0x01_app_load(zm831_home_app *app)
  {
    auto self = (_function_0x01_ *)app->userdata;

    if (!self->init)
    {
      if (access("/root/camera", 0))
        system("mkdir /root/camera");

      zm831_home_setup_ui(&self->ui->photo_app, setup_scr_camera, 1000);

      pthread_mutex_lock(&zm831->ui_mutex);
      lv_obj_set_event_cb(self->ui->photo_app_imgbtn_back, function_0x01_btn_event_app_cb);
      lv_obj_set_event_cb(self->ui->photo_app_imgbtn_press, function_0x01_btn_event_app_cb);
      lv_obj_set_event_cb(self->ui->photo_app_imgbtn_clear, function_0x01_btn_event_app_cb);
      pthread_mutex_unlock(&zm831->ui_mutex);

      self->init = true;
    }
    LIBMAIX_INFO_PRINTF("function_0x01_app_load");
    return 0;
  }

  int function_0x01_app_exit(zm831_home_app *app)
  {
    auto self = (_function_0x01_ *)app->userdata;
    if (self->init)
    {
      // lv_obj_del(self->btn);
      // lv_obj_del(self->label);
      zm831_home_clear_ui(&self->ui->photo_app);
      self->init = false;
    }
    LIBMAIX_INFO_PRINTF("function_0x01_app_exit");
    return 0;
  }

  int function_0x01_app_loop(zm831_home_app *app)
  {
    auto self = (_function_0x01_ *)app->userdata;
    libmaix_err_t err = LIBMAIX_ERR_NONE;
    libmaix_image_t *ai_rgb = NULL;
    if (zm831->ai && LIBMAIX_ERR_NONE == zm831->ai->capture_image(zm831->ai, &ai_rgb))
    {
      // CALC_FPS("function_0x01_app_loop"); // 224x224

      if (function_0x01_app.is_capture)
      {
        function_0x01_app.is_capture = false;

        int file_nums = get_dir_file_nums();

        std::ostringstream filename;
        filename << string_format("/root/camera/maix_image_%03d.jpg", file_nums + 1);

        cv::Mat rgb(ai_rgb->height, ai_rgb->width, CV_8UC3, ai_rgb->data);
        cv::Mat bgr;
        cvtColor(rgb, bgr, cv::COLOR_RGB2BGR);
        cv::imwrite(filename.str(), bgr);
        system("sync");

        printf("capture %s\n", filename.str().c_str());

        void zm831_ui_show_image(cv::Mat & img, int x, int y, lv_opa_t opa);
        zm831_ui_show_image(rgb, 8, 8, LV_OPA_90);

        sleep(2);

        void zm831_ui_show_clear();
        zm831_ui_show_clear();
      }

      {
        pthread_mutex_lock(&zm831->ui_mutex);
        lv_label_set_text(self->ui->photo_app_label_top, string_format("fps: %02d", get_fps()).c_str());
        pthread_mutex_unlock(&zm831->ui_mutex);
      }

      if (function_0x01_app.is_clear)
      {
        function_0x01_app.is_clear = false;
        system("rm /root/camera/* && sync");
      }
    }
    return 0;
  }
}
