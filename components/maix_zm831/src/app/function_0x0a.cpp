
#include "zm831_uvai.hpp"

extern "C"
{
  extern zm831_uv *zm831;

  // ==============================================================================================

  void setup_scr_face_study_app(lv_ui *ui)
  {

    // Write codes face_study_app
    ui->face_study_app = lv_scr_act();

    // Write style LV_OBJ_PART_MAIN for face_study_app
    static lv_style_t style_face_study_app_main;
    lv_style_reset(&style_face_study_app_main);

    // Write style state: LV_STATE_DEFAULT for style_face_study_app_main
    lv_style_set_bg_color(&style_face_study_app_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
    lv_style_set_bg_opa(&style_face_study_app_main, LV_STATE_DEFAULT, 0);
    lv_obj_add_style(ui->face_study_app, LV_OBJ_PART_MAIN, &style_face_study_app_main);

    // Write codes face_study_app_label_top_title
    ui->face_study_app_label_top_title = lv_label_create(ui->face_study_app, NULL);
    lv_label_set_text(ui->face_study_app_label_top_title, "人脸学习");
    lv_label_set_long_mode(ui->face_study_app_label_top_title, LV_LABEL_LONG_BREAK);
    lv_label_set_align(ui->face_study_app_label_top_title, LV_LABEL_ALIGN_CENTER);

    // Write style LV_LABEL_PART_MAIN for face_study_app_label_top_title
    static lv_style_t style_face_study_app_label_top_title_main;
    lv_style_reset(&style_face_study_app_label_top_title_main);

    // Write style state: LV_STATE_DEFAULT for style_face_study_app_label_top_title_main
    lv_style_set_radius(&style_face_study_app_label_top_title_main, LV_STATE_DEFAULT, 0);
    lv_style_set_bg_color(&style_face_study_app_label_top_title_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
    lv_style_set_bg_grad_color(&style_face_study_app_label_top_title_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
    lv_style_set_bg_grad_dir(&style_face_study_app_label_top_title_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
    lv_style_set_bg_opa(&style_face_study_app_label_top_title_main, LV_STATE_DEFAULT, 100);
    lv_style_set_text_color(&style_face_study_app_label_top_title_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
    lv_style_set_text_font(&style_face_study_app_label_top_title_main, LV_STATE_DEFAULT, &lv_font_simsun_18);
    lv_style_set_text_letter_space(&style_face_study_app_label_top_title_main, LV_STATE_DEFAULT, 2);
    lv_style_set_pad_left(&style_face_study_app_label_top_title_main, LV_STATE_DEFAULT, 0);
    lv_style_set_pad_right(&style_face_study_app_label_top_title_main, LV_STATE_DEFAULT, 0);
    lv_style_set_pad_top(&style_face_study_app_label_top_title_main, LV_STATE_DEFAULT, 8);
    lv_style_set_pad_bottom(&style_face_study_app_label_top_title_main, LV_STATE_DEFAULT, 8);
    lv_obj_add_style(ui->face_study_app_label_top_title, LV_LABEL_PART_MAIN, &style_face_study_app_label_top_title_main);
    lv_obj_set_pos(ui->face_study_app_label_top_title, 0, 0);
    lv_obj_set_size(ui->face_study_app_label_top_title, 240, 0);

    // Write codes face_study_app_imgbtn_back
    ui->face_study_app_imgbtn_back = lv_imgbtn_create(ui->face_study_app, NULL);

    // Write style LV_IMGBTN_PART_MAIN for face_study_app_imgbtn_back
    static lv_style_t style_face_study_app_imgbtn_back_main;
    lv_style_reset(&style_face_study_app_imgbtn_back_main);

    // Write style state: LV_STATE_DEFAULT for style_face_study_app_imgbtn_back_main
    lv_style_set_text_color(&style_face_study_app_imgbtn_back_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
    lv_style_set_image_recolor(&style_face_study_app_imgbtn_back_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
    lv_style_set_image_recolor_opa(&style_face_study_app_imgbtn_back_main, LV_STATE_DEFAULT, 0);
    lv_style_set_image_opa(&style_face_study_app_imgbtn_back_main, LV_STATE_DEFAULT, 255);

    // Write style state: LV_STATE_PRESSED for style_face_study_app_imgbtn_back_main
    lv_style_set_text_color(&style_face_study_app_imgbtn_back_main, LV_STATE_PRESSED, lv_color_make(0xFF, 0x33, 0xFF));
    lv_style_set_image_recolor(&style_face_study_app_imgbtn_back_main, LV_STATE_PRESSED, lv_color_make(0x00, 0x00, 0x00));
    lv_style_set_image_recolor_opa(&style_face_study_app_imgbtn_back_main, LV_STATE_PRESSED, 0);

    // Write style state: LV_STATE_CHECKED for style_face_study_app_imgbtn_back_main
    lv_style_set_text_color(&style_face_study_app_imgbtn_back_main, LV_STATE_CHECKED, lv_color_make(0xFF, 0x33, 0xFF));
    lv_style_set_image_recolor(&style_face_study_app_imgbtn_back_main, LV_STATE_CHECKED, lv_color_make(0x00, 0x00, 0x00));
    lv_style_set_image_recolor_opa(&style_face_study_app_imgbtn_back_main, LV_STATE_CHECKED, 0);
    lv_obj_add_style(ui->face_study_app_imgbtn_back, LV_IMGBTN_PART_MAIN, &style_face_study_app_imgbtn_back_main);
    lv_obj_set_pos(ui->face_study_app_imgbtn_back, 20, 180);
    lv_obj_set_size(ui->face_study_app_imgbtn_back, 50, 50);
    lv_imgbtn_set_src(ui->face_study_app_imgbtn_back, LV_BTN_STATE_RELEASED, &_back_alpha_50x50);
    lv_imgbtn_set_checkable(ui->face_study_app_imgbtn_back, true);

    // Write codes face_study_app_imgbtn_clear
    ui->face_study_app_imgbtn_clear = lv_imgbtn_create(ui->face_study_app, NULL);

    // Write style LV_IMGBTN_PART_MAIN for face_study_app_imgbtn_clear
    static lv_style_t style_face_study_app_imgbtn_clear_main;
    lv_style_reset(&style_face_study_app_imgbtn_clear_main);

    // Write style state: LV_STATE_DEFAULT for style_face_study_app_imgbtn_clear_main
    lv_style_set_text_color(&style_face_study_app_imgbtn_clear_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
    lv_style_set_image_recolor(&style_face_study_app_imgbtn_clear_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
    lv_style_set_image_recolor_opa(&style_face_study_app_imgbtn_clear_main, LV_STATE_DEFAULT, 0);
    lv_style_set_image_opa(&style_face_study_app_imgbtn_clear_main, LV_STATE_DEFAULT, 255);

    // Write style state: LV_STATE_PRESSED for style_face_study_app_imgbtn_clear_main
    lv_style_set_text_color(&style_face_study_app_imgbtn_clear_main, LV_STATE_PRESSED, lv_color_make(0xFF, 0x33, 0xFF));
    lv_style_set_image_recolor(&style_face_study_app_imgbtn_clear_main, LV_STATE_PRESSED, lv_color_make(0x00, 0x00, 0x00));
    lv_style_set_image_recolor_opa(&style_face_study_app_imgbtn_clear_main, LV_STATE_PRESSED, 0);

    // Write style state: LV_STATE_CHECKED for style_face_study_app_imgbtn_clear_main
    lv_style_set_text_color(&style_face_study_app_imgbtn_clear_main, LV_STATE_CHECKED, lv_color_make(0xFF, 0x33, 0xFF));
    lv_style_set_image_recolor(&style_face_study_app_imgbtn_clear_main, LV_STATE_CHECKED, lv_color_make(0x00, 0x00, 0x00));
    lv_style_set_image_recolor_opa(&style_face_study_app_imgbtn_clear_main, LV_STATE_CHECKED, 0);
    lv_obj_add_style(ui->face_study_app_imgbtn_clear, LV_IMGBTN_PART_MAIN, &style_face_study_app_imgbtn_clear_main);
    lv_obj_set_pos(ui->face_study_app_imgbtn_clear, 170, 180);
    lv_obj_set_size(ui->face_study_app_imgbtn_clear, 50, 50);
    lv_imgbtn_set_src(ui->face_study_app_imgbtn_clear, LV_BTN_STATE_RELEASED, &_clear_alpha_50x50);
    lv_imgbtn_set_checkable(ui->face_study_app_imgbtn_clear, true);

    // Write codes face_study_app_imgbtn_press
    ui->face_study_app_imgbtn_press = lv_imgbtn_create(ui->face_study_app, NULL);

    // Write style LV_IMGBTN_PART_MAIN for face_study_app_imgbtn_press
    static lv_style_t style_face_study_app_imgbtn_press_main;
    lv_style_reset(&style_face_study_app_imgbtn_press_main);

    // Write style state: LV_STATE_DEFAULT for style_face_study_app_imgbtn_press_main
    lv_style_set_text_color(&style_face_study_app_imgbtn_press_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
    lv_style_set_image_recolor(&style_face_study_app_imgbtn_press_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
    lv_style_set_image_recolor_opa(&style_face_study_app_imgbtn_press_main, LV_STATE_DEFAULT, 0);
    lv_style_set_image_opa(&style_face_study_app_imgbtn_press_main, LV_STATE_DEFAULT, 255);

    // Write style state: LV_STATE_PRESSED for style_face_study_app_imgbtn_press_main
    lv_style_set_text_color(&style_face_study_app_imgbtn_press_main, LV_STATE_PRESSED, lv_color_make(0xFF, 0x33, 0xFF));
    lv_style_set_image_recolor(&style_face_study_app_imgbtn_press_main, LV_STATE_PRESSED, lv_color_make(0x00, 0x00, 0x00));
    lv_style_set_image_recolor_opa(&style_face_study_app_imgbtn_press_main, LV_STATE_PRESSED, 0);

    // Write style state: LV_STATE_CHECKED for style_face_study_app_imgbtn_press_main
    lv_style_set_text_color(&style_face_study_app_imgbtn_press_main, LV_STATE_CHECKED, lv_color_make(0xFF, 0x33, 0xFF));
    lv_style_set_image_recolor(&style_face_study_app_imgbtn_press_main, LV_STATE_CHECKED, lv_color_make(0x00, 0x00, 0x00));
    lv_style_set_image_recolor_opa(&style_face_study_app_imgbtn_press_main, LV_STATE_CHECKED, 0);
    lv_obj_add_style(ui->face_study_app_imgbtn_press, LV_IMGBTN_PART_MAIN, &style_face_study_app_imgbtn_press_main);
    lv_obj_set_pos(ui->face_study_app_imgbtn_press, 88, 170);
    lv_obj_set_size(ui->face_study_app_imgbtn_press, 63, 63);
    lv_imgbtn_set_src(ui->face_study_app_imgbtn_press, LV_BTN_STATE_RELEASED, &_study_alpha_63x63);
    lv_imgbtn_set_checkable(ui->face_study_app_imgbtn_press, true);
  }

#include "libmaix_nn_face.h"

  static struct _function_0x0a_
  {
    lv_ui *ui = &zm831->ui;
    lv_draw_rect_dsc_t rect_dsc;
    lv_draw_label_dsc_t label_dsc;
    lv_draw_line_dsc_t line_dsc;
    time_t now;

    const char *fa_model_path_param = "/home/res/model_int8.param";
    const char *fa_model_path_bin = "/home/res/model_int8.bin";
    const char *fa_inputs_names[1] = {"input0"};
    const char *fa_outputs_names[3] = {"output0", "431", "output2"};
    const float fa_opt_param_mean = 127.5;
    const float fa_opt_param_norm = 0.0078125;
    libmaix_nn_t *fa_nn;
    libmaix_nn_model_path_t fa_model_path;
    libmaix_nn_opt_param_t fa_opt_param;

    const char *fe_model_path_param = "/home/res/fe_res18_117.param";
    const char *fe_model_path_bin = "/home/res/fe_res18_117.bin";
    const char *fe_inputs_names[1] = {"inputs_blob"};
    const char *fe_outputs_names[1] = {"FC_blob"};
    const float fe_opt_param_mean = 127.5;
    const float fe_opt_param_norm = 0.0078125;
    libmaix_nn_t *fe_nn;
    libmaix_nn_model_path_t fe_model_path;
    libmaix_nn_opt_param_t fe_opt_param;

    libmaix_nn_face_config_t face_config = {
        .detect_nms = 0.3,
        .detect_thresh = 0.5,
        .detect_input_w = 224,
        .detect_input_h = 224,
    };

    float face_threshold = 70.f;   // 人脸阈值
    int face_feature_id = 0;       // 人脸学习id
    int face_feature_max = 0;      // 人脸总数id
    const int face_sum = 20;       // 最大人脸数量
    const int face_len = 256;      // 人脸数据宽度
    float **face_features;         // 人脸学习数据
    int max_face_num = 1;          // 输出的最大人脸数量
    void *recognize_module = NULL; // 人脸识别模块

    bool init = false;
  } function_0x0a_app;

  int function_0x0a_app_load(zm831_home_app *app);
  int function_0x0a_app_loop(zm831_home_app *app);
  int function_0x0a_app_exit(zm831_home_app *app);

  zm831_home_app get_function_0x0a_app()
  {
    return {function_0x0a_app_load, function_0x0a_app_loop, function_0x0a_app_exit, &function_0x0a_app};
  }

  // ==============================================================================================

  static void function_0x0a_btn_event_app_cb(lv_obj_t *btn, lv_event_t event)
  {
    // printf("btn %p event %d\n", btn, event);
    if (function_0x0a_app.ui->face_study_app_imgbtn_back == btn && event == LV_EVENT_SHORT_CLICKED)
    {
      zm831_home_app_select(0);
      return;
    }
  }

  int function_0x0a_app_load(zm831_home_app *app)
  {
    auto self = (_function_0x0a_ *)app->userdata;

    lv_draw_rect_dsc_init(&self->rect_dsc);
    self->rect_dsc.radius = 5;
    self->rect_dsc.bg_opa = LV_OPA_TRANSP;
    self->rect_dsc.border_width = 5;
    self->rect_dsc.border_opa = LV_OPA_80;
    self->rect_dsc.border_color = {0x00, 0x00, 0xFF, 0x9f};

    lv_draw_label_dsc_init(&self->label_dsc);
    self->label_dsc.color = LV_COLOR_GREEN;
    self->label_dsc.font = zm831->ft_font.font;

    lv_draw_line_dsc_init(&self->line_dsc);
    self->line_dsc.color = {0xFF, 0x00, 0x00, 0x9f};
    self->line_dsc.width = 2;
    self->line_dsc.opa = LV_OPA_70;

    libmaix_err_t err = LIBMAIX_ERR_NONE;

    {
      self->fa_opt_param.awnn.input_names = (char **)self->fa_inputs_names;
      self->fa_opt_param.awnn.output_names = (char **)self->fa_outputs_names;
      self->fa_opt_param.awnn.input_num = sizeof(self->fa_inputs_names) / sizeof(self->fa_inputs_names[0]);
      self->fa_opt_param.awnn.output_num = sizeof(self->fa_outputs_names) / sizeof(self->fa_outputs_names[0]);

      self->fa_opt_param.awnn.mean[0] = self->fa_opt_param_mean;
      self->fa_opt_param.awnn.mean[1] = self->fa_opt_param.awnn.mean[0];
      self->fa_opt_param.awnn.mean[2] = self->fa_opt_param.awnn.mean[0];

      self->fa_opt_param.awnn.norm[0] = self->fa_opt_param_norm;
      self->fa_opt_param.awnn.norm[1] = self->fa_opt_param.awnn.norm[0];
      self->fa_opt_param.awnn.norm[2] = self->fa_opt_param.awnn.norm[0];

      self->fa_model_path.awnn.param_path = (char *)self->fa_model_path_param;
      self->fa_model_path.awnn.bin_path = (char *)self->fa_model_path_bin;

      LIBMAIX_INFO_PRINTF("-- fa nn create\n");
      self->fa_nn = libmaix_nn_create();
      if (!self->fa_nn)
      {
        LIBMAIX_INFO_PRINTF("libmaix_nn object create fail\n");
        return -1;
      }
      LIBMAIX_INFO_PRINTF("-- nn object init\n");
      err = self->fa_nn->init(self->fa_nn);
      if (err != LIBMAIX_ERR_NONE)
      {
        LIBMAIX_INFO_PRINTF("libmaix_nn init fail: %s\n", libmaix_get_err_msg(err));
        return -1;
      }
      LIBMAIX_INFO_PRINTF("-- nn object load model\n");
      err = self->fa_nn->load(self->fa_nn, &self->fa_model_path, &self->fa_opt_param);
      if (err != LIBMAIX_ERR_NONE)
      {
        LIBMAIX_INFO_PRINTF("libmaix_nn load fail: %s\n", libmaix_get_err_msg(err));
        return -1;
      }
    }

    {
      self->fe_opt_param.awnn.input_names = (char **)self->fe_inputs_names;
      self->fe_opt_param.awnn.output_names = (char **)self->fe_outputs_names;
      self->fe_opt_param.awnn.input_num = sizeof(self->fe_inputs_names) / sizeof(self->fe_inputs_names[0]);
      self->fe_opt_param.awnn.output_num = sizeof(self->fe_outputs_names) / sizeof(self->fe_outputs_names[0]);

      self->fe_opt_param.awnn.mean[0] = self->fe_opt_param_mean;
      self->fe_opt_param.awnn.mean[1] = self->fe_opt_param.awnn.mean[0];
      self->fe_opt_param.awnn.mean[2] = self->fe_opt_param.awnn.mean[0];

      self->fe_opt_param.awnn.norm[0] = self->fe_opt_param_norm;
      self->fe_opt_param.awnn.norm[1] = self->fe_opt_param.awnn.norm[0];
      self->fe_opt_param.awnn.norm[2] = self->fe_opt_param.awnn.norm[0];

      self->fe_model_path.awnn.param_path = (char *)self->fe_model_path_param;
      self->fe_model_path.awnn.bin_path = (char *)self->fe_model_path_bin;

      LIBMAIX_INFO_PRINTF("-- fe nn create\n");
      self->fe_nn = libmaix_nn_create();
      if (!self->fe_nn)
      {
        LIBMAIX_INFO_PRINTF("libmaix_nn object create feil\n");
        return -1;
      }
      LIBMAIX_INFO_PRINTF("-- nn object init\n");
      err = self->fe_nn->init(self->fe_nn);
      if (err != LIBMAIX_ERR_NONE)
      {
        LIBMAIX_INFO_PRINTF("libmaix_nn init feil: %s\n", libmaix_get_err_msg(err));
        return -1;
      }
      LIBMAIX_INFO_PRINTF("-- nn object load model\n");
      err = self->fe_nn->load(self->fe_nn, &self->fe_model_path, &self->fe_opt_param);
      if (err != LIBMAIX_ERR_NONE)
      {
        LIBMAIX_INFO_PRINTF("libmaix_nn load fail: %s\n", libmaix_get_err_msg(err));
        return -1;
      }
    }

    err = libmaix_nn_face_recognize_init(&self->recognize_module, &self->face_config, self->fa_nn, NULL, self->fe_nn, self->face_len, self->max_face_num, NULL, NULL);
    if (err != LIBMAIX_ERR_NONE)
    {
      LIBMAIX_INFO_PRINTF("libmaix_nn face_recognize_init fail: %s\n", libmaix_get_err_msg(err));
      return -1;
    }

    self->face_features = (float **)malloc(self->face_sum * sizeof(float *));
    if (!self->face_features)
    {
      LIBMAIX_INFO_PRINTF("malloc fail\n");
      return -1;
    }

    for (int i = 0; i < self->face_sum; i++)
    {
      self->face_features[i] = (float *)malloc(self->face_len * sizeof(float));
      if (!self->face_features[i])
      {
        LIBMAIX_INFO_PRINTF("malloc fail\n");
        return -1;
      }
    }

    if (!self->init)
    {
      zm831_home_setup_ui(&self->ui->face_study_app, setup_scr_face_study_app, 500);

      pthread_mutex_lock(&zm831->ui_mutex);
      lv_obj_set_event_cb(self->ui->face_study_app_imgbtn_back, function_0x0a_btn_event_app_cb);
      pthread_mutex_unlock(&zm831->ui_mutex);

      self->init = true;
    }
    LIBMAIX_INFO_PRINTF("function_0x0a_app_load");
    return 0;
  }

  int function_0x0a_app_exit(zm831_home_app *app)
  {
    auto self = (_function_0x0a_ *)app->userdata;

    if (self->recognize_module)
    {
      libmaix_nn_face_recognize_deinit(&self->recognize_module);
    }

    if (self->fa_nn)
    {
      libmaix_nn_destroy(&self->fa_nn);
    }

    if (self->fe_nn)
    {
      libmaix_nn_destroy(&self->fe_nn);
    }

    if (self->face_features)
    {
      for (int i = 0; i < self->face_sum; i++)
      {
        free(self->face_features[i]);
        self->face_features[i] = NULL;
      }
      free(self->face_features);
      self->face_features = NULL;
    }

    if (self->init)
    {
      zm831_home_clear_ui(&self->ui->face_study_app);
      self->init = false;
    }
    LIBMAIX_INFO_PRINTF("function_0x0a_app_exit");
    return 0;
  }

  /**
   * @brief 对比人脸数据,找出最大的数据 id 和分数
   *
   * @param face_feature 输出人脸特征向量
   * @param score 输出人脸对比最高的分数
   * @return int 返回人脸对比的 id 索引号,无人脸时返回 -1.
   */
  static int nn_get_face_recognize_scores_max(zm831_home_app *app, float *face_feature, float *score)
  {
    auto self = (_function_0x0a_ *)app->userdata;
    float face_scores[self->face_sum] = {0};
    int face_score_max_id = 0;
    if (!self->face_feature_id)
    {
      *score = 0;
      return -1;
    }
    if (self->face_sum < self->face_feature_id)
    {
      self->face_feature_id = 0;
      return -1;
    }
    if (self->face_feature_max == 0)
    {
      return -1;
    }
    int limit = std::min(self->face_feature_max, self->face_sum);
    for (int i = 0; i < limit; ++i)
    {
      face_scores[i] = libmaix_nn_feature_compare_float(face_feature, self->face_features[i], self->face_len);
      if (face_scores[i] > face_scores[face_score_max_id])
      {
        face_score_max_id = i;
      }
    }
    *score = face_scores[face_score_max_id];
    return face_score_max_id;
  }

  int function_0x0a_app_loop(zm831_home_app *app)
  {
    auto self = (_function_0x0a_ *)app->userdata;
    libmaix_err_t err = LIBMAIX_ERR_NONE;
    libmaix_image_t *ai_rgb = NULL;
    if (zm831->ai && LIBMAIX_ERR_NONE == zm831->ai->capture_image(zm831->ai, &ai_rgb))
    {
      int face_num = 0;
      face_obj_t *face_objs = NULL;
      err = libmaix_nn_face_get_feature(self->recognize_module, ai_rgb, &face_num, NULL, &face_objs, false);
      if (err == LIBMAIX_ERR_NONE)
      {
        if (face_num > 0)
        {
          // printf("face_num: %d\n", face_num);
          // printf("face_objs: %p\n", face_objs);
          // printf("face_objs->prob: %f\n", face_objs->prob);
          // printf("face_objs->x1: %d\n", face_objs->x1);
          // printf("face_objs->y1: %d\n", face_objs->y1);
          // printf("face_objs->x2: %d\n", face_objs->x2);
          // printf("face_objs->y2: %d\n", face_objs->y2);

          // for (int i = 0; i < 5; i++)
          // {
          //   printf("face_objs->key_point(%d, %d)\n", i, face_objs->key_point.point[i].x, face_objs->key_point.point[i].y);
          // }

          std::ostringstream prob2str;
          prob2str << face_objs->prob;

          pthread_mutex_lock(&zm831->ui_mutex);
          lv_canvas_fill_bg(zm831_ui_get_canvas(), LV_COLOR_BLACK, LV_OPA_TRANSP);
          lv_canvas_draw_rect(zm831_ui_get_canvas(), face_objs->x1, face_objs->y1, ai2vi(face_objs->x2 - face_objs->x1), ai2vi(face_objs->y2 - face_objs->y1), &self->rect_dsc);
          lv_canvas_draw_text(zm831_ui_get_canvas(), face_objs->x1, face_objs->y1, 100, &self->label_dsc, prob2str.str().c_str(), LV_LABEL_ALIGN_LEFT);
          for (int i = 0; i < 5; i++) lv_canvas_draw_arc(zm831_ui_get_canvas(), ai2vi(face_objs->key_point.point[i].x), ai2vi(face_objs->key_point.point[i].y), 5, 0, 360, &self->line_dsc);
          pthread_mutex_unlock(&zm831->ui_mutex);

          float _tmp_score = 0;
          int tmp_id = nn_get_face_recognize_scores_max(app, face_objs->feature, &_tmp_score);
          if (tmp_id >= 0) // 有记录的人脸时
          {
            if (_tmp_score > self->face_threshold)
            {
              //人脸对比分数大于人脸阈值时,认为是记录的人脸
            }
            else
            {
              //人脸对比分数小于人脸阈值时,认为不是记录的人脸
            }
          }
          else
          {
            //没有记录的人脸时,但有脸
          }
        } else {
          pthread_mutex_lock(&zm831->ui_mutex);
          lv_canvas_fill_bg(zm831_ui_get_canvas(), LV_COLOR_BLACK, LV_OPA_TRANSP);
          pthread_mutex_unlock(&zm831->ui_mutex);
        }
      }
    }
    return 0;
  }
}
