
#include "zm831_uvai.hpp"

extern "C"
{
  extern zm831_uv *zm831;

  // ==============================================================================================
  /*
  显示当前摄像头拍摄的图像，并显示帧率，按下确定键可以拍照，屏幕同时闪烁一次（矽速可自行调整闪烁方式），并保存到虚拟磁盘的camera文件夹下。
  */
  static struct _function_0x01_
  {
    lv_draw_label_dsc_t label_dsc_zh, label_dsc_en;
    lv_draw_rect_dsc_t rect_dsc;
    int fps = 0, tmp = 0;
    struct timespec old;

    lv_obj_t *btn, *label;
    bool is_capture = false;

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

  int get_dir_file_nums()
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
    if (event == LV_EVENT_CLICKED)
    {
      function_0x01_app.is_capture = true;
    }
  }

  int function_0x01_app_load(zm831_home_app *app)
  {
    auto self = (_function_0x01_ *)app->userdata;

    lv_draw_label_dsc_init(&self->label_dsc_zh);
    self->label_dsc_zh.color = LV_COLOR_GREEN;
    self->label_dsc_zh.font = zm831->ft_font.font;

    lv_draw_label_dsc_init(&self->label_dsc_en);
    self->label_dsc_en.color = LV_COLOR_WHITE;

    lv_draw_rect_dsc_init(&self->rect_dsc);
    self->rect_dsc.radius = 5;
    self->rect_dsc.bg_color = {0x00, 0x00, 0x00, 0xDF};;
    self->rect_dsc.bg_opa = LV_OPA_80;
    self->rect_dsc.border_width = 5;
    self->rect_dsc.border_opa = LV_OPA_80;
    self->rect_dsc.border_color = {0x00, 0x00, 0x00, 0x7f};

    if (!self->init)
    {
      if (access("/root/camera",0))
          system("mkdir /root/camera");
      {
        lv_obj_t *btn = self->btn;
        btn = lv_btn_create(lv_scr_act(), NULL); /*Add a button the current screen*/
        lv_obj_set_pos(btn, 80, 160);                      /*Set its position*/
        // lv_obj_align(btn, NULL, LV_ALIGN_IN_BOTTOM_RIGHT, 0, 0);
        lv_obj_set_size(btn, 80, 80);               /*Set its size*/
        lv_obj_set_event_cb(btn, function_0x01_btn_event_app_cb); /*Assign a callback to the button*/
        static lv_style_t style_btn_red;
        lv_style_init(&style_btn_red);
        lv_style_set_bg_color(&style_btn_red, LV_STATE_DEFAULT, {0x00, 0x00, 0xff, 0x7f}); // bgra
        lv_style_set_bg_grad_color(&style_btn_red, LV_STATE_DEFAULT, LV_COLOR_MAROON);
        lv_style_set_bg_color(&style_btn_red, LV_STATE_PRESSED, LV_COLOR_MAROON);
        lv_style_set_bg_grad_color(&style_btn_red, LV_STATE_PRESSED, LV_COLOR_RED);
        lv_style_set_text_color(&style_btn_red, LV_STATE_DEFAULT, LV_COLOR_WHITE);
        lv_obj_add_style(btn, LV_BTN_PART_MAIN, &style_btn_red); /*Add the red style on top of the current */
        lv_obj_t *label = lv_label_create(btn, NULL);            /*Add a label to the button*/
        lv_label_set_text(label, "capture");                         /*Set the labels text*/
      }
      {
        lv_obj_t *label = self->label;
        label = lv_label_create(lv_scr_act(), NULL);            /*Add a label to the button*/
        lv_obj_set_pos(label, 10, 10);                      /*Set its position*/
        lv_label_set_text(label, "fps: 00");                         /*Set the labels text*/
      }

      function_0x01_app.is_capture = false;

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
      CALC_FPS("function_0x01_app_loop");

      if (function_0x01_app.is_capture)
      {
        function_0x01_app.is_capture = false;

        int file_nums = get_dir_file_nums();

        std::ostringstream filename;
        filename << string_format("/root/camera/maix_image_%d.jpg", file_nums + 1);

        cv::Mat rgb(ai_rgb->height, ai_rgb->width, CV_8UC3, ai_rgb->data);
        cv::imwrite(filename.str(), rgb);
      }

      // self->fps = fps;

      // printf("fps: %d\n", self->fps);

      lv_label_set_text_fmt(self->label, "fps: %02d", self->fps);
    }
    return 0;
  }

  int function_0x01_app_exit(zm831_home_app *app)
  {
    auto self = (_function_0x01_ *)app->userdata;
    if (self->init)
    {
      lv_obj_del(self->btn);
      lv_obj_del(self->label);
      self->init = false;
    }
    LIBMAIX_INFO_PRINTF("function_0x01_app_exit");
    return 0;
  }
}
