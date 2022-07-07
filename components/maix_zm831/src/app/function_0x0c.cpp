
#include "zm831_uvai.hpp"

extern "C"
{
  extern zm831_uv *zm831;

  // ==============================================================================================

  void setup_scr_classific_study_app(lv_ui *ui)
  {

    // Write codes classific_study_app
    ui->classific_study_app = lv_obj_create(NULL, NULL);

    // Write style LV_OBJ_PART_MAIN for classific_study_app
    static lv_style_t style_classific_study_app_main;
    lv_style_reset(&style_classific_study_app_main);

    // Write style state: LV_STATE_DEFAULT for style_classific_study_app_main
    lv_style_set_bg_color(&style_classific_study_app_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
    lv_style_set_bg_opa(&style_classific_study_app_main, LV_STATE_DEFAULT, 139);
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
    time_t now;

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
    int class_num = 3;
    int sample_num = 8;
    int feature_length = 512;
    int input_w = 224, input_h = 224;
    float class_prob = 0;
    int class_id = -1;
    int i_class_num = 0, i_sample_num = 0, flag_trained = 0;
    void *classifier_obj;

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
  }

  int function_0x0c_app_load(zm831_home_app *app)
  {
    auto self = (_function_0x0c_ *)app->userdata;

    lv_draw_rect_dsc_init(&self->rect_dsc);
    self->rect_dsc.radius = 5;
    self->rect_dsc.bg_opa = LV_OPA_TRANSP;
    self->rect_dsc.border_width = 5;
    self->rect_dsc.border_opa = LV_OPA_80;
    self->rect_dsc.border_color = {0x00, 0x00, 0xFF, 0x9f};

    lv_draw_label_dsc_init(&self->label_dsc);
    self->label_dsc.color = LV_COLOR_GREEN;
    self->label_dsc.font = zm831->ft_font.font;

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

    if (!self->init)
    {
      zm831_home_setup_ui(&self->ui->classific_study_app, setup_scr_classific_study_app, 500);

      pthread_mutex_lock(&zm831->ui_mutex);
      lv_obj_set_event_cb(self->ui->classific_study_app_imgbtn_back, function_0x0c_btn_event_app_cb);
      pthread_mutex_unlock(&zm831->ui_mutex);

      self->init = true;
    }
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
        if (err != LIBMAIX_ERR_NONE)
        {
          printf("libmaix_classifier_predict fail: %s\n", libmaix_get_err_msg(err));
        }
        else
        {
          if (self->class_id >= 0)
          {
            printf("class id: %d, class prob: %f\n", self->class_id, 100 - self->class_prob);
            std::ostringstream prob2str;
            prob2str << "class id: " << self->class_id << ", prob: " << (int)((100 - self->class_prob) * 10) << std::endl;
            pthread_mutex_lock(&zm831->ui_mutex);
            lv_canvas_fill_bg(zm831_ui_get_canvas(), LV_COLOR_BLACK, LV_OPA_TRANSP);
            lv_canvas_draw_text(zm831_ui_get_canvas(), 0, 0, 240, &self->label_dsc, prob2str.str().c_str(), LV_LABEL_ALIGN_LEFT);
            pthread_mutex_unlock(&zm831->ui_mutex);
          }
        }
      }
      else
      {
        printf("wait for training\n");
        if (self->i_class_num < self->class_num)
        {
          printf("add class img, class num: %d\n", self->i_class_num);
          sleep(2);
          libmaix_classifier_add_class_img(&self->classifier_obj, ai_rgb, &self->i_class_num);
          self->i_class_num++; // 先添加类别
        }
        else if (self->i_sample_num < self->sample_num)
        {
          printf("add sample img, sample num: %d\n", self->i_sample_num);
          sleep(1);
          libmaix_classifier_add_sample_img(self->classifier_obj, ai_rgb, &self->i_sample_num);
          self->i_sample_num++; // 再添加样本
        }
        else if (self->i_sample_num == self->sample_num)
        {
          // 训练完成
          libmaix_classifier_train(self->classifier_obj);
          self->flag_trained = 1;
          self->i_sample_num = 0;
          self->i_class_num = 0;
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
        }
      }
    }
    return 0;
  }
}
