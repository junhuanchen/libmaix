
#include "zm831_uvai.hpp"

extern "C"
{
  extern zm831_uv *zm831;

  // ==============================================================================================

  void setup_scr_camera(lv_ui *ui){

    //Write codes camera
    ui->camera = lv_scr_act();

    // //Write style LV_OBJ_PART_MAIN for camera
    // static lv_style_t style_camera_main;
    // lv_style_reset(&style_camera_main);

    // //Write style state: LV_STATE_DEFAULT for style_camera_main
    // lv_style_set_bg_color(&style_camera_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
    // lv_style_set_bg_opa(&style_camera_main, LV_STATE_DEFAULT, 0);
    // lv_obj_add_style(ui->camera, LV_OBJ_PART_MAIN, &style_camera_main);

    //Write codes camera_label_1
    ui->camera_label_1 = lv_label_create(ui->camera, NULL);
    lv_label_set_text(ui->camera_label_1, "fps: 00");
    lv_label_set_long_mode(ui->camera_label_1, LV_LABEL_LONG_BREAK);
    lv_label_set_align(ui->camera_label_1, LV_LABEL_ALIGN_CENTER);

    //Write style LV_LABEL_PART_MAIN for camera_label_1
    static lv_style_t style_camera_label_1_main;
    lv_style_reset(&style_camera_label_1_main);

    //Write style state: LV_STATE_DEFAULT for style_camera_label_1_main
    lv_style_set_radius(&style_camera_label_1_main, LV_STATE_DEFAULT, 0);
    lv_style_set_bg_color(&style_camera_label_1_main, LV_STATE_DEFAULT, lv_color_make(0x5a, 0x61, 0x73));
    lv_style_set_bg_grad_color(&style_camera_label_1_main, LV_STATE_DEFAULT, lv_color_make(0x5a, 0x61, 0x73));
    lv_style_set_bg_grad_dir(&style_camera_label_1_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
    lv_style_set_bg_opa(&style_camera_label_1_main, LV_STATE_DEFAULT, 255);
    lv_style_set_text_color(&style_camera_label_1_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
    lv_style_set_text_font(&style_camera_label_1_main, LV_STATE_DEFAULT, &lv_font_simsun_12);
    lv_style_set_text_letter_space(&style_camera_label_1_main, LV_STATE_DEFAULT, 2);
    lv_style_set_pad_left(&style_camera_label_1_main, LV_STATE_DEFAULT, 0);
    lv_style_set_pad_right(&style_camera_label_1_main, LV_STATE_DEFAULT, 0);
    lv_style_set_pad_top(&style_camera_label_1_main, LV_STATE_DEFAULT, 0);
    lv_style_set_pad_bottom(&style_camera_label_1_main, LV_STATE_DEFAULT, 0);
    lv_obj_add_style(ui->camera_label_1, LV_LABEL_PART_MAIN, &style_camera_label_1_main);
    lv_obj_set_pos(ui->camera_label_1, 17, 16);
    lv_obj_set_size(ui->camera_label_1, 106, 0);

    //Write codes camera_btn_1
    ui->camera_btn_1 = lv_btn_create(ui->camera, NULL);

    //Write style LV_BTN_PART_MAIN for camera_btn_1
    static lv_style_t style_camera_btn_1_main;
    lv_style_reset(&style_camera_btn_1_main);

    //Write style state: LV_STATE_DEFAULT for style_camera_btn_1_main
    lv_style_set_radius(&style_camera_btn_1_main, LV_STATE_DEFAULT, 50);
    lv_style_set_bg_color(&style_camera_btn_1_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
    lv_style_set_bg_grad_color(&style_camera_btn_1_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x48, 0xff));
    lv_style_set_bg_grad_dir(&style_camera_btn_1_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
    lv_style_set_bg_opa(&style_camera_btn_1_main, LV_STATE_DEFAULT, 255);
    lv_style_set_border_color(&style_camera_btn_1_main, LV_STATE_DEFAULT, lv_color_make(0x01, 0xa2, 0xb1));
    lv_style_set_border_width(&style_camera_btn_1_main, LV_STATE_DEFAULT, 2);
    lv_style_set_border_opa(&style_camera_btn_1_main, LV_STATE_DEFAULT, 255);
    lv_style_set_outline_color(&style_camera_btn_1_main, LV_STATE_DEFAULT, lv_color_make(0xd4, 0xd7, 0xd9));
    lv_style_set_outline_opa(&style_camera_btn_1_main, LV_STATE_DEFAULT, 255);
    lv_obj_add_style(ui->camera_btn_1, LV_BTN_PART_MAIN, &style_camera_btn_1_main);
    lv_obj_set_pos(ui->camera_btn_1, 67, 157);
    lv_obj_set_size(ui->camera_btn_1, 100, 50);
    ui->camera_btn_1_label = lv_label_create(ui->camera_btn_1, NULL);
    lv_label_set_text(ui->camera_btn_1_label, "capture");
    lv_obj_set_style_local_text_color(ui->camera_btn_1_label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
    lv_obj_set_style_local_text_font(ui->camera_btn_1_label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, &lv_font_simsun_12);
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
    if (event == LV_EVENT_RELEASED)
    {
      function_0x01_app.is_capture = true;
      // extern int zm831_home_app_select(int id);
      // zm831_home_app_select(2);
    }
  }

  int function_0x01_app_load(zm831_home_app *app)
  {
    auto self = (_function_0x01_ *)app->userdata;

    if (!self->init)
    {
      if (access("/root/camera",0))
          system("mkdir /root/camera");

      zm831_home_setup_ui(setup_scr_camera, 1000);

      pthread_mutex_lock(&zm831->ui_mutex);
      lv_obj_set_event_cb(self->ui->camera_btn_1, function_0x01_btn_event_app_cb);
      pthread_mutex_unlock(&zm831->ui_mutex);

      self->init = true;
    }
    LIBMAIX_INFO_PRINTF("function_0x01_app_load");
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

        void zm831_ui_show_image(cv::Mat &img, int x, int y, lv_opa_t opa);
        zm831_ui_show_image(rgb, 8, 8, LV_OPA_90);

        sleep(2);

        void zm831_ui_show_clear();
        zm831_ui_show_clear();

        zm831_home_app_select(0);

      }

      {
        pthread_mutex_lock(&zm831->ui_mutex);
        lv_label_set_text(self->ui->camera_label_1, string_format("fps: %02d", get_fps()).c_str());
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

  int function_0x01_app_exit(zm831_home_app *app)
  {
    auto self = (_function_0x01_ *)app->userdata;
    if (self->init)
    {
      // lv_obj_del(self->btn);
      // lv_obj_del(self->label);
      zm831_home_clear_ui();
      self->init = false;
    }
    LIBMAIX_INFO_PRINTF("function_0x01_app_exit");
    return 0;
  }
}
