
#include "zm831_uvai.hpp"

extern "C"
{
  extern zm831_uv *zm831;

  // ==============================================================================================

  void setup_scr_classific_study_app(lv_ui *ui)
  {

    // Write codes classific_study_app
    ui->classific_study_app = lv_scr_act();

    // Write style LV_OBJ_PART_MAIN for classific_study_app
    static lv_style_t style_classific_study_app_main;
    lv_style_reset(&style_classific_study_app_main);

    // Write style state: LV_STATE_DEFAULT for style_classific_study_app_main
    lv_style_set_bg_color(&style_classific_study_app_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
    lv_style_set_bg_opa(&style_classific_study_app_main, LV_STATE_DEFAULT, 0);
    lv_obj_add_style(ui->classific_study_app, LV_OBJ_PART_MAIN, &style_classific_study_app_main);

    // Write codes classific_study_app_label_top_title
    ui->classific_study_app_label_top_title = lv_label_create(ui->classific_study_app, NULL);
    lv_label_set_text(ui->classific_study_app_label_top_title, "图像分类学习");
    lv_label_set_long_mode(ui->classific_study_app_label_top_title, LV_LABEL_LONG_BREAK);
    lv_label_set_align(ui->classific_study_app_label_top_title, LV_LABEL_ALIGN_CENTER);

    // Write style LV_LABEL_PART_MAIN for classific_study_app_label_top_title
    static lv_style_t style_classific_study_app_label_top_title_main;
    lv_style_reset(&style_classific_study_app_label_top_title_main);

    // Write style state: LV_STATE_DEFAULT for style_classific_study_app_label_top_title_main
    lv_style_set_radius(&style_classific_study_app_label_top_title_main, LV_STATE_DEFAULT, 0);
    lv_style_set_bg_color(&style_classific_study_app_label_top_title_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
    lv_style_set_bg_grad_color(&style_classific_study_app_label_top_title_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
    lv_style_set_bg_grad_dir(&style_classific_study_app_label_top_title_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
    lv_style_set_bg_opa(&style_classific_study_app_label_top_title_main, LV_STATE_DEFAULT, 100);
    lv_style_set_text_color(&style_classific_study_app_label_top_title_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
    lv_style_set_text_font(&style_classific_study_app_label_top_title_main, LV_STATE_DEFAULT, &lv_font_simsun_18);
    lv_style_set_text_letter_space(&style_classific_study_app_label_top_title_main, LV_STATE_DEFAULT, 2);
    lv_style_set_pad_left(&style_classific_study_app_label_top_title_main, LV_STATE_DEFAULT, 0);
    lv_style_set_pad_right(&style_classific_study_app_label_top_title_main, LV_STATE_DEFAULT, 0);
    lv_style_set_pad_top(&style_classific_study_app_label_top_title_main, LV_STATE_DEFAULT, 8);
    lv_style_set_pad_bottom(&style_classific_study_app_label_top_title_main, LV_STATE_DEFAULT, 8);
    lv_obj_add_style(ui->classific_study_app_label_top_title, LV_LABEL_PART_MAIN, &style_classific_study_app_label_top_title_main);
    lv_obj_set_pos(ui->classific_study_app_label_top_title, 0, 0);
    lv_obj_set_size(ui->classific_study_app_label_top_title, 240, 0);

    // Write codes classific_study_app_imgbtn_back
    ui->classific_study_app_imgbtn_back = lv_imgbtn_create(ui->classific_study_app, NULL);

    // Write style LV_IMGBTN_PART_MAIN for classific_study_app_imgbtn_back
    static lv_style_t style_classific_study_app_imgbtn_back_main;
    lv_style_reset(&style_classific_study_app_imgbtn_back_main);

    // Write style state: LV_STATE_DEFAULT for style_classific_study_app_imgbtn_back_main
    lv_style_set_text_color(&style_classific_study_app_imgbtn_back_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
    lv_style_set_image_recolor(&style_classific_study_app_imgbtn_back_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
    lv_style_set_image_recolor_opa(&style_classific_study_app_imgbtn_back_main, LV_STATE_DEFAULT, 0);
    lv_style_set_image_opa(&style_classific_study_app_imgbtn_back_main, LV_STATE_DEFAULT, 255);

    // Write style state: LV_STATE_PRESSED for style_classific_study_app_imgbtn_back_main
    lv_style_set_text_color(&style_classific_study_app_imgbtn_back_main, LV_STATE_PRESSED, lv_color_make(0xFF, 0x33, 0xFF));
    lv_style_set_image_recolor(&style_classific_study_app_imgbtn_back_main, LV_STATE_PRESSED, lv_color_make(0x00, 0x00, 0x00));
    lv_style_set_image_recolor_opa(&style_classific_study_app_imgbtn_back_main, LV_STATE_PRESSED, 0);

    // Write style state: LV_STATE_CHECKED for style_classific_study_app_imgbtn_back_main
    lv_style_set_text_color(&style_classific_study_app_imgbtn_back_main, LV_STATE_CHECKED, lv_color_make(0xFF, 0x33, 0xFF));
    lv_style_set_image_recolor(&style_classific_study_app_imgbtn_back_main, LV_STATE_CHECKED, lv_color_make(0x00, 0x00, 0x00));
    lv_style_set_image_recolor_opa(&style_classific_study_app_imgbtn_back_main, LV_STATE_CHECKED, 0);
    lv_obj_add_style(ui->classific_study_app_imgbtn_back, LV_IMGBTN_PART_MAIN, &style_classific_study_app_imgbtn_back_main);
    lv_obj_set_pos(ui->classific_study_app_imgbtn_back, 20, 180);
    lv_obj_set_size(ui->classific_study_app_imgbtn_back, 50, 50);
    lv_imgbtn_set_src(ui->classific_study_app_imgbtn_back, LV_BTN_STATE_RELEASED, &_back_alpha_50x50);
    lv_imgbtn_set_checkable(ui->classific_study_app_imgbtn_back, true);

    // Write codes classific_study_app_imgbtn_clear
    ui->classific_study_app_imgbtn_clear = lv_imgbtn_create(ui->classific_study_app, NULL);

    // Write style LV_IMGBTN_PART_MAIN for classific_study_app_imgbtn_clear
    static lv_style_t style_classific_study_app_imgbtn_clear_main;
    lv_style_reset(&style_classific_study_app_imgbtn_clear_main);

    // Write style state: LV_STATE_DEFAULT for style_classific_study_app_imgbtn_clear_main
    lv_style_set_text_color(&style_classific_study_app_imgbtn_clear_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
    lv_style_set_image_recolor(&style_classific_study_app_imgbtn_clear_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
    lv_style_set_image_recolor_opa(&style_classific_study_app_imgbtn_clear_main, LV_STATE_DEFAULT, 0);
    lv_style_set_image_opa(&style_classific_study_app_imgbtn_clear_main, LV_STATE_DEFAULT, 255);

    // Write style state: LV_STATE_PRESSED for style_classific_study_app_imgbtn_clear_main
    lv_style_set_text_color(&style_classific_study_app_imgbtn_clear_main, LV_STATE_PRESSED, lv_color_make(0xFF, 0x33, 0xFF));
    lv_style_set_image_recolor(&style_classific_study_app_imgbtn_clear_main, LV_STATE_PRESSED, lv_color_make(0x00, 0x00, 0x00));
    lv_style_set_image_recolor_opa(&style_classific_study_app_imgbtn_clear_main, LV_STATE_PRESSED, 0);

    // Write style state: LV_STATE_CHECKED for style_classific_study_app_imgbtn_clear_main
    lv_style_set_text_color(&style_classific_study_app_imgbtn_clear_main, LV_STATE_CHECKED, lv_color_make(0xFF, 0x33, 0xFF));
    lv_style_set_image_recolor(&style_classific_study_app_imgbtn_clear_main, LV_STATE_CHECKED, lv_color_make(0x00, 0x00, 0x00));
    lv_style_set_image_recolor_opa(&style_classific_study_app_imgbtn_clear_main, LV_STATE_CHECKED, 0);
    lv_obj_add_style(ui->classific_study_app_imgbtn_clear, LV_IMGBTN_PART_MAIN, &style_classific_study_app_imgbtn_clear_main);
    lv_obj_set_pos(ui->classific_study_app_imgbtn_clear, 170, 180);
    lv_obj_set_size(ui->classific_study_app_imgbtn_clear, 50, 50);
    lv_imgbtn_set_src(ui->classific_study_app_imgbtn_clear, LV_BTN_STATE_RELEASED, &_clear_alpha_50x50);
    lv_imgbtn_set_checkable(ui->classific_study_app_imgbtn_clear, true);

    // Write codes classific_study_app_imgbtn_press
    ui->classific_study_app_imgbtn_press = lv_imgbtn_create(ui->classific_study_app, NULL);

    // Write style LV_IMGBTN_PART_MAIN for classific_study_app_imgbtn_press
    static lv_style_t style_classific_study_app_imgbtn_press_main;
    lv_style_reset(&style_classific_study_app_imgbtn_press_main);

    // Write style state: LV_STATE_DEFAULT for style_classific_study_app_imgbtn_press_main
    lv_style_set_text_color(&style_classific_study_app_imgbtn_press_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
    lv_style_set_image_recolor(&style_classific_study_app_imgbtn_press_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
    lv_style_set_image_recolor_opa(&style_classific_study_app_imgbtn_press_main, LV_STATE_DEFAULT, 0);
    lv_style_set_image_opa(&style_classific_study_app_imgbtn_press_main, LV_STATE_DEFAULT, 255);

    // Write style state: LV_STATE_PRESSED for style_classific_study_app_imgbtn_press_main
    lv_style_set_text_color(&style_classific_study_app_imgbtn_press_main, LV_STATE_PRESSED, lv_color_make(0xFF, 0x33, 0xFF));
    lv_style_set_image_recolor(&style_classific_study_app_imgbtn_press_main, LV_STATE_PRESSED, lv_color_make(0x00, 0x00, 0x00));
    lv_style_set_image_recolor_opa(&style_classific_study_app_imgbtn_press_main, LV_STATE_PRESSED, 0);

    // Write style state: LV_STATE_CHECKED for style_classific_study_app_imgbtn_press_main
    lv_style_set_text_color(&style_classific_study_app_imgbtn_press_main, LV_STATE_CHECKED, lv_color_make(0xFF, 0x33, 0xFF));
    lv_style_set_image_recolor(&style_classific_study_app_imgbtn_press_main, LV_STATE_CHECKED, lv_color_make(0x00, 0x00, 0x00));
    lv_style_set_image_recolor_opa(&style_classific_study_app_imgbtn_press_main, LV_STATE_CHECKED, 0);
    lv_obj_add_style(ui->classific_study_app_imgbtn_press, LV_IMGBTN_PART_MAIN, &style_classific_study_app_imgbtn_press_main);
    lv_obj_set_pos(ui->classific_study_app_imgbtn_press, 88, 170);
    lv_obj_set_size(ui->classific_study_app_imgbtn_press, 63, 63);
    lv_imgbtn_set_src(ui->classific_study_app_imgbtn_press, LV_BTN_STATE_RELEASED, &_study_alpha_63x63);
    lv_imgbtn_set_checkable(ui->classific_study_app_imgbtn_press, true);
  }

#include "libmaix_nn_classifier.h"

  static struct _function_0x0c_
  {
    lv_ui *ui = &zm831->ui;

    lv_draw_rect_dsc_t rect_dsc;
    lv_draw_label_dsc_t label_dsc;

    const char *model_path_param = "/home/res/resnet.param";
    const char *model_path_bin = "/home/res/resnet.bin";
    const char *inputs_names[1] = {"input0"};
    const char *outputs_names[1] = {"190"};
    const float opt_param_mean = 127.5;
    const float opt_param_norm = 0.0176;
    libmaix_nn_t *nn;
    libmaix_nn_model_path_t model_path;
    libmaix_nn_opt_param_t opt_param;

    const char *classifier_pth = "/root/classifier.bin";
    void *classifier_obj;
    float class_prob = 0;
    int feature_length = 512;
    int input_w = 224, input_h = 224;
    int i_class_num = 0, i_sample_num = 0;
    int class_num = 4;
    int sample_num = 3;
    int class_id = -1;
    uint8_t flag_trained = 0;
    uint8_t flag_confirm = 0;
    // uint8_t flag_captrue = 0;
    uint8_t is_clear = false;
    uint8_t is_learn = false;
    uint8_t state = 0;

    bool init = false;
  } function_0x0c_app;

  int function_0x0c_app_load(zm831_home_app *app);
  int function_0x0c_app_loop(zm831_home_app *app);
  int function_0x0c_app_exit(zm831_home_app *app);

  zm831_home_app get_function_0x0c_app()
  {
    return {function_0x0c_app_load, function_0x0c_app_loop, function_0x0c_app_exit, &function_0x0c_app};
  }

  // ==============================================================================================

  static void function_0x0c_btn_event_app_cb(lv_obj_t *btn, lv_event_t event)
  {
    // printf("btn %p event %d\n", btn, event);
    if (function_0x0c_app.ui->classific_study_app_imgbtn_back == btn && event == LV_EVENT_SHORT_CLICKED)
    {
      zm831_home_app_select(0);
      return;
    }
    if (function_0x0c_app.ui->classific_study_app_imgbtn_clear == btn && event == LV_EVENT_SHORT_CLICKED)
    {
      function_0x0c_app.is_clear = true;
      return;
    }
    if (function_0x0c_app.ui->classific_study_app_imgbtn_press == btn && event == LV_EVENT_SHORT_CLICKED)
    {
      function_0x0c_app.is_learn = true;
      return;
    }
  }

  int function_0x0c_app_load(zm831_home_app *app)
  {
    auto self = (_function_0x0c_ *)app->userdata;

    lv_draw_rect_dsc_init(&self->rect_dsc);
    self->rect_dsc.radius = 5;
    self->rect_dsc.bg_opa = LV_OPA_TRANSP;
    self->rect_dsc.border_width = 5;
    self->rect_dsc.border_opa = LV_OPA_80;
    self->rect_dsc.border_color = {0x00, 0xFF, 0x00, 0x9f};

    lv_draw_label_dsc_init(&self->label_dsc);
    self->label_dsc.color = LV_COLOR_GREEN;
    self->label_dsc.font = zm831->ft_font.font;

    if (!self->init)
    {
      zm831_home_setup_ui(&self->ui->classific_study_app, setup_scr_classific_study_app, 2500);

      pthread_mutex_lock(&zm831->ui_mutex);
      lv_obj_set_event_cb(self->ui->classific_study_app_imgbtn_back, function_0x0c_btn_event_app_cb);
      lv_obj_set_event_cb(self->ui->classific_study_app_imgbtn_clear, function_0x0c_btn_event_app_cb);
      lv_obj_set_event_cb(self->ui->classific_study_app_imgbtn_press, function_0x0c_btn_event_app_cb);
      pthread_mutex_unlock(&zm831->ui_mutex);

      self->init = true;
    }

    libmaix_err_t err = LIBMAIX_ERR_NONE;

    self->opt_param.awnn.input_names = (char **)self->inputs_names;
    self->opt_param.awnn.output_names = (char **)self->outputs_names;
    self->opt_param.awnn.input_num = sizeof(self->inputs_names) / sizeof(self->inputs_names[0]);
    self->opt_param.awnn.output_num = sizeof(self->outputs_names) / sizeof(self->outputs_names[0]);

    self->opt_param.awnn.mean[0] = self->opt_param_mean;
    self->opt_param.awnn.mean[1] = self->opt_param.awnn.mean[0];
    self->opt_param.awnn.mean[2] = self->opt_param.awnn.mean[0];

    self->opt_param.awnn.norm[0] = self->opt_param_norm;
    self->opt_param.awnn.norm[1] = self->opt_param.awnn.norm[0];
    self->opt_param.awnn.norm[2] = self->opt_param.awnn.norm[0];

    self->model_path.awnn.param_path = (char *)self->model_path_param;
    self->model_path.awnn.bin_path = (char *)self->model_path_bin;

    LIBMAIX_INFO_PRINTF("-- nn create\n");
    self->nn = libmaix_nn_create();
    if (!self->nn)
    {
      LIBMAIX_INFO_PRINTF("libmaix_nn object create fail\n");
      return -1;
    }
    LIBMAIX_INFO_PRINTF("-- nn object init\n");
    err = self->nn->init(self->nn);
    if (err != LIBMAIX_ERR_NONE)
    {
      LIBMAIX_INFO_PRINTF("libmaix_nn init fail: %s\n", libmaix_get_err_msg(err));
      return -1;
    }
    LIBMAIX_INFO_PRINTF("-- nn object load model\n");
    err = self->nn->load(self->nn, &self->model_path, &self->opt_param);
    if (err != LIBMAIX_ERR_NONE)
    {
      LIBMAIX_INFO_PRINTF("libmaix_nn load fail: %s\n", libmaix_get_err_msg(err));
      return -1;
    }
    err = libmaix_classifier_load(&self->classifier_obj, self->classifier_pth, self->nn, &self->feature_length, &self->input_w, &self->input_h, &self->class_num, &self->sample_num);
    if (err != LIBMAIX_ERR_NONE)
    {
      self->i_class_num = self->i_sample_num = self->flag_trained = 0;
      LIBMAIX_INFO_PRINTF("libmaix_classifier_load fail\n");
      libmaix_classifier_init(&self->classifier_obj, self->nn, self->feature_length, self->input_w, self->input_h, self->class_num, self->sample_num);
    }
    else
    {
      // self->flag_trained = 0; // need rebuild model
      self->flag_trained = 1;
    }

    printf("self->classifier_obj = %p\n", self->classifier_obj);
    printf("self->nn = %p\n", self->nn);
    printf("self->feature_length = %d\n", self->feature_length);
    printf("self->input_w = %d\n", self->input_w);
    printf("self->input_h = %d\n", self->input_h);
    printf("self->class_num = %d\n", self->class_num);
    printf("self->sample_num = %d\n", self->sample_num);

    LIBMAIX_INFO_PRINTF("function_0x0c_app_load");
    return 0;
  }

  int function_0x0c_app_exit(zm831_home_app *app)
  {
    auto self = (_function_0x0c_ *)app->userdata;

    if (self->classifier_obj)
    {
      libmaix_classifier_del(&self->classifier_obj);
    }

    if (self->nn)
    {
      libmaix_nn_destroy(&self->nn);
    }

    if (self->init)
    {
      zm831_home_clear_ui(&self->ui->classific_study_app);
      self->init = false;
    }

    LIBMAIX_INFO_PRINTF("function_0x0c_app_exit");
    return 0;
  }

  int function_0x0c_app_loop(zm831_home_app *app)
  {
    auto self = (_function_0x0c_ *)app->userdata;
    libmaix_err_t err = LIBMAIX_ERR_NONE;
    libmaix_image_t *ai_rgb = NULL;
    if (zm831->ai && LIBMAIX_ERR_NONE == zm831->ai->capture_image(zm831->ai, &ai_rgb))
    {
      if (self->flag_trained)
      {
        err = libmaix_classifier_predict(self->classifier_obj, ai_rgb, &self->class_id, &self->class_prob);
        printf("err %d: class id: %d, class prob: %f\n", err, self->class_id, 100 - self->class_prob);
        if (err != LIBMAIX_ERR_NONE)
        {
          printf("libmaix_classifier_predict fail: %s\n", libmaix_get_err_msg(err));
        }
        else if (self->class_id >= 0)
        {
          pthread_mutex_lock(&zm831->ui_mutex);
          lv_canvas_fill_bg(zm831_ui_get_canvas(), LV_COLOR_BLACK, LV_OPA_TRANSP);
          lv_canvas_draw_text(zm831_ui_get_canvas(), 0, 40, 240, &self->label_dsc, string_format("class id: %d, prob: %d", self->class_id + 1, (int)((100 - self->class_prob))).c_str(), LV_LABEL_ALIGN_LEFT);
          pthread_mutex_unlock(&zm831->ui_mutex);
        }
      }
      else if (self->state == 0)
      {
        pthread_mutex_lock(&zm831->ui_mutex);
        lv_canvas_fill_bg(zm831_ui_get_canvas(), LV_COLOR_BLACK, LV_OPA_TRANSP);
        lv_canvas_draw_text(zm831_ui_get_canvas(), 0, 40, 240, &self->label_dsc, string_format("no train model...").c_str(), LV_LABEL_ALIGN_LEFT);
        pthread_mutex_unlock(&zm831->ui_mutex);
      }

      if (self->is_clear)
      {
        self->is_clear = false;
        system(string_format("rm %s && sync", self->classifier_pth).c_str());
        self->flag_trained = 0;
        self->state = 0;
      }

      if (self->is_learn)
      {
        self->is_learn = false;
        if (self->flag_trained == 0)
        {
          if (self->state == 0)
          {
            self->flag_confirm = false;
            self->state = 3;
          }
          else
          {
            self->flag_confirm = true;
          }
        }
      }

      switch (self->state)
      {
      case 1:
      {
        if (self->i_sample_num == 0 && self->i_class_num == 0)
        {
          pthread_mutex_lock(&zm831->ui_mutex);
          lv_canvas_fill_bg(zm831_ui_get_canvas(), LV_COLOR_BLACK, LV_OPA_TRANSP);
          lv_canvas_draw_text(zm831_ui_get_canvas(), 0, 40, 240, &self->label_dsc, string_format("start train model...").c_str(), LV_LABEL_ALIGN_LEFT);
          pthread_mutex_unlock(&zm831->ui_mutex);

          libmaix_classifier_train(self->classifier_obj);
          libmaix_classifier_save(self->classifier_obj, self->classifier_pth);
          system("sync");
          libmaix_classifier_del(&self->classifier_obj);
          err = libmaix_classifier_load(&self->classifier_obj, self->classifier_pth, self->nn, &self->feature_length, &self->input_w, &self->input_h, &self->class_num, &self->sample_num);
          if (err != LIBMAIX_ERR_NONE)
          {
            printf("libmaix_classifier_init fail\n");
            libmaix_classifier_init(&self->classifier_obj, self->nn, self->feature_length, self->input_w, self->input_h, self->class_num, self->sample_num);
          }
          printf("train classifier\n");
          self->flag_trained = 1;
          self->state = 0;
        }
        break;
      }
      case 2:
      {
        if (self->i_class_num < self->class_num)
        {
          pthread_mutex_lock(&zm831->ui_mutex);
          lv_canvas_fill_bg(zm831_ui_get_canvas(), LV_COLOR_BLACK, LV_OPA_TRANSP);
          lv_canvas_draw_text(zm831_ui_get_canvas(), 0, 40, 240, &self->label_dsc, string_format("Capture ID:%d(%d)", self->i_class_num - 1, self->class_num).c_str(), LV_LABEL_ALIGN_LEFT);
          pthread_mutex_unlock(&zm831->ui_mutex);
          if (self->flag_confirm)
          {
            self->flag_confirm = false;
            cv::Mat rgb(ai_rgb->height, ai_rgb->width, CV_8UC3, ai_rgb->data);
            zm831_ui_show_image(rgb, 8, 8, LV_OPA_90);
            msleep(200);
            libmaix_err_t err = libmaix_classifier_add_class_img(self->classifier_obj, ai_rgb, &self->i_class_num);
            if (err != LIBMAIX_ERR_NONE) printf("libmaix_classifier_add_class_img fail: %s\n", libmaix_get_err_msg(err));
            self->i_class_num++;
          }
        }
        else if (self->i_class_num == self->class_num)
        {
          pthread_mutex_lock(&zm831->ui_mutex);
          lv_canvas_fill_bg(zm831_ui_get_canvas(), LV_COLOR_BLACK, LV_OPA_TRANSP);
          lv_canvas_draw_text(zm831_ui_get_canvas(), 0, 40, 240, &self->label_dsc, string_format("Capture Datas:%d(%d)", self->i_sample_num, self->sample_num).c_str(), LV_LABEL_ALIGN_LEFT);
          pthread_mutex_unlock(&zm831->ui_mutex);
          if (self->i_sample_num < self->sample_num)
          {
            if (self->flag_confirm)
            {
              self->flag_confirm = false;
              cv::Mat rgb(ai_rgb->height, ai_rgb->width, CV_8UC3, ai_rgb->data);
              zm831_ui_show_image(rgb, 8, 8, LV_OPA_90);
              msleep(200);
              int idx = -1;
              libmaix_err_t err = libmaix_classifier_add_sample_img(self->classifier_obj, ai_rgb, &idx);
              if (err != LIBMAIX_ERR_NONE) printf("libmaix_classifier_add_sample_img fail: %s\n", libmaix_get_err_msg(err));
              printf("idx %d\r\n", idx);
              self->i_sample_num++;
            }
          }
          else if (self->i_sample_num == self->sample_num)
          {
            self->i_sample_num = 0;
            self->i_class_num = 0;
            self->state = 1;
          }
        }
        break;
        /*
        pthread_mutex_lock(&zm831->ui_mutex);
        lv_canvas_fill_bg(zm831_ui_get_canvas(), LV_COLOR_BLACK, LV_OPA_TRANSP);
        lv_canvas_draw_text(zm831_ui_get_canvas(), 0, 40, 240, &self->label_dsc, string_format("ID%d:datas(%d)", self->i_class_num, self->i_sample_num).c_str(), LV_LABEL_ALIGN_LEFT);
        pthread_mutex_unlock(&zm831->ui_mutex);
        if (self->flag_confirm)
        {
          self->flag_confirm = false;
          if (self->flag_captrue == 0)
          {
            self->flag_captrue = 1;
            cv::Mat rgb(ai_rgb->height, ai_rgb->width, CV_8UC3, ai_rgb->data);
            zm831_ui_show_image(rgb, 8, 8, LV_OPA_90);
            msleep(250);
            libmaix_err_t err = libmaix_classifier_add_class_img(self->classifier_obj, ai_rgb, &self->i_class_num);
            if (err != LIBMAIX_ERR_NONE) printf("libmaix_classifier_add_class_img fail: %s\n", libmaix_get_err_msg(err));
          }
          else if (self->i_sample_num < self->sample_num)
          {
            cv::Mat rgb(ai_rgb->height, ai_rgb->width, CV_8UC3, ai_rgb->data);
            zm831_ui_show_image(rgb, 8, 8, LV_OPA_90);
            msleep(250);
            libmaix_err_t err = libmaix_classifier_add_sample_img(self->classifier_obj, ai_rgb, &self->i_sample_num);
            if (err != LIBMAIX_ERR_NONE) printf("libmaix_classifier_add_sample_img fail: %s\n", libmaix_get_err_msg(err));
            self->i_sample_num++;
          }
          else if (self->i_sample_num == self->sample_num)
          {
            self->i_class_num++;
            self->flag_captrue = 0;
            if (self->i_class_num == self->class_num)
            {
              self->i_sample_num = 0;
              self->i_class_num = 0;
              self->state = 1;
            }
          }
        }
        */
      }
      case 3:
      {
        self->i_class_num = 0;
        self->i_sample_num = 0;
        self->state = 2;
        // ready null image
        libmaix_err_t err = libmaix_classifier_add_class_img(self->classifier_obj, ai_rgb, &self->i_class_num);
        if (err != LIBMAIX_ERR_NONE) printf("libmaix_classifier_add_class_img fail: %s\n", libmaix_get_err_msg(err));
        self->i_class_num++;
      }
      }

    }
    return 0;
  }
}
