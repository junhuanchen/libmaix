
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
        .detect_thresh = 0.6,
        .detect_input_w = 224,
        .detect_input_h = 224,
    };

    const int max_face_num = 1;       // 输出的最大人脸数量
    float face_threshold = 70.f;      // 人脸阈值
    int face_feature_id = 0;          // 人脸学习id
    int face_feature_max = 0;         // 人脸总数id
    const int face_features_len = 256;// 人脸数据宽度
    const int face_features_max = 10; // 最大人脸数量
    int face_features_sum = 0;        // 人脸特征总数
    float **face_features;            // 人脸特征数据
    void *recognize_module = NULL;    // 人脸识别模块

    const char *config_file = "/root/function_0x0a.json";
    json5pp::value config_json;

    uint32_t old = 0;
    uint8_t state = 0;
    uint8_t is_clear = false;
    uint8_t is_learn = false;

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
    if (function_0x0a_app.ui->face_study_app_imgbtn_clear == btn && event == LV_EVENT_SHORT_CLICKED)
    {
      function_0x0a_app.is_clear = true;
      return;
    }
    if (function_0x0a_app.ui->face_study_app_imgbtn_press == btn && event == LV_EVENT_SHORT_CLICKED)
    {
      function_0x0a_app.is_learn = true;
      return;
    }
  }

  int function_0x0a_app_load(zm831_home_app *app)
  {
    auto self = (_function_0x0a_ *)app->userdata;

    zm831_load_json_conf(self->config_file, self->config_json, json5pp::object({
        { "face_features_sum", 0},
        {
          "face_features", json5pp::array({}),
        }
    }));

    pthread_mutex_lock(&zm831->ui_mutex);
    lv_draw_rect_dsc_init(&self->rect_dsc);
    self->rect_dsc.radius = 5;
    self->rect_dsc.bg_opa = LV_OPA_TRANSP;
    self->rect_dsc.border_width = 5;
    self->rect_dsc.border_opa = LV_OPA_80;
    self->rect_dsc.border_color = LV_COLOR_GREEN;

    lv_draw_label_dsc_init(&self->label_dsc);
    self->label_dsc.color = LV_COLOR_GREEN;
    self->label_dsc.font = zm831->ft_font.font;

    lv_draw_line_dsc_init(&self->line_dsc);
    self->line_dsc.color = LV_COLOR_WHITE;
    self->line_dsc.width = 2;
    self->line_dsc.opa = LV_OPA_70;
    pthread_mutex_unlock(&zm831->ui_mutex);

    zm831_home_setup_ui(&self->ui->face_study_app, setup_scr_face_study_app, 500);

    pthread_mutex_lock(&zm831->ui_mutex);
    lv_obj_set_event_cb(self->ui->face_study_app_imgbtn_back, function_0x0a_btn_event_app_cb);
    lv_obj_set_event_cb(self->ui->face_study_app_imgbtn_clear, function_0x0a_btn_event_app_cb);
    lv_obj_set_event_cb(self->ui->face_study_app_imgbtn_press, function_0x0a_btn_event_app_cb);
    pthread_mutex_unlock(&zm831->ui_mutex);

    pthread_mutex_lock(&zm831->ui_mutex);
    lv_obj_t* loading = lv_spinner_create(lv_scr_act(), NULL);
    lv_obj_set_size(loading, 120, 120);
    lv_obj_align(loading, NULL, LV_ALIGN_CENTER, 0, 0);
    lv_spinner_set_type(loading, LV_SPINNER_TYPE_FILLSPIN_ARC);
    pthread_mutex_unlock(&zm831->ui_mutex);

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

    err = libmaix_nn_face_recognize_init(&self->recognize_module, &self->face_config, self->fa_nn, NULL, self->fe_nn, self->face_features_len, self->max_face_num, NULL, NULL);
    if (err != LIBMAIX_ERR_NONE)
    {
      LIBMAIX_INFO_PRINTF("libmaix_nn face_recognize_init fail: %s\n", libmaix_get_err_msg(err));
      return -1;
    }

    self->face_features = (float **)malloc(self->face_features_max * sizeof(float *));
    if (!self->face_features)
    {
      LIBMAIX_INFO_PRINTF("malloc fail\n");
      return -1;
    }

    for (int i = 0; i < self->face_features_max; i++)
    {
      self->face_features[i] = (float *)malloc(self->face_features_len * sizeof(float));
      if (!self->face_features[i])
      {
        LIBMAIX_INFO_PRINTF("malloc fail\n");
        return -1;
      }
      memset(self->face_features[i], 0, self->face_features_len * sizeof(float));
    }

    try
    {
      {
        auto &result = self->config_json["face_features_sum"];
        if (result.is_integer())
        {
          self->face_features_sum = result.as_integer();
          if (self->face_features_sum > 10 || self->face_features_sum < 0) {
            self->face_features_sum = 0;
            result = self->face_features_sum;
          }
        }
      }
      printf("self->face_features_sum: %d\n", self->face_features_sum);
      if (self->face_features_sum)
      {
        auto &result = self->config_json["face_features"];
        if (result.is_array()) {
          auto face_features = result.as_array();
          for (int i = 0; i < self->face_features_sum; i++) {
            auto item = face_features[i];
            if (item.is_array()) {
              auto face_feature = item.as_array();
              auto face_features_len = face_feature.size();
              for (int j = 0; j < face_features_len; j++) {
                self->face_features[i][j] = face_feature[j].as_number();
              }
            }
          }
        }
      }
      else
      {
        auto face_features = json5pp::array({});
        for (int i = 0; i < self->face_features_max; i++) {
          auto face_feature = json5pp::array({});
          for (int j = 0; j < self->face_features_len; j++) {
            face_feature.as_array().push_back(self->face_features[i][j]);
          }
          face_features.as_array().push_back(face_feature);
        }
        self->config_json["face_features"] = face_features;
        zm831_save_json_conf(self->config_file, self->config_json);
      }
    }
    catch(const std::exception& e)
    {
      self->face_features_sum = 0;
      std::cerr << e.what() << '\n';
    }

    if (!self->init)
    {
      self->init = true;
    }

    pthread_mutex_lock(&zm831->ui_mutex);
    lv_obj_del(loading);
    pthread_mutex_unlock(&zm831->ui_mutex);

    LIBMAIX_INFO_PRINTF("function_0x0a_app_load");
    return 0;
  }

  int function_0x0a_app_exit(zm831_home_app *app)
  {
    auto self = (_function_0x0a_ *)app->userdata;

    zm831_save_json_conf(self->config_file, self->config_json);

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
      for (int i = 0; i < self->face_features_max; i++)
      {
        free(self->face_features[i]);
        self->face_features[i] = NULL;
      }
      free(self->face_features);
      self->face_features = NULL;
    }

    if (self->init)
    {
      self->init = false;
    }

    zm831_home_clear_ui(&self->ui->face_study_app);

    LIBMAIX_INFO_PRINTF("function_0x0a_app_exit");
    return 0;
  }

  int function_0x0a_app_loop(zm831_home_app *app)
  {
    auto self = (_function_0x0a_ *)app->userdata;
    libmaix_err_t err = LIBMAIX_ERR_NONE;
    libmaix_image_t *ai_rgb = NULL;
    if (zm831->ai && LIBMAIX_ERR_NONE == zm831->ai->capture_image(zm831->ai, &ai_rgb))
    {
      zm831->sensor_time = zm831_get_ms();

      int face_num = 0;
      face_obj_t *face_objs = NULL;
      err = libmaix_nn_face_get_feature(self->recognize_module, ai_rgb, &face_num, NULL, &face_objs, false);
      if (err == LIBMAIX_ERR_NONE)
      {
        if (face_num > 0)
        {
          pthread_mutex_lock(&zm831->ui_mutex);
          lv_canvas_fill_bg(zm831_ui_get_canvas(), LV_COLOR_BLACK, LV_OPA_TRANSP);

          self->label_dsc.color = LV_COLOR_RED;
          self->rect_dsc.border_color = LV_COLOR_RED;

          int x = ai2vi(face_objs->x1), y = ai2vi(face_objs->y1), w = ai2vi(face_objs->x2 - face_objs->x1), h = ai2vi(face_objs->y2 - face_objs->y1);

          for (int i = 0; i < 5; i++)
            lv_canvas_draw_arc(zm831_ui_get_canvas(), ai2vi(face_objs->key_point.point[i].x), ai2vi(face_objs->key_point.point[i].y), 5, 0, 360, &self->line_dsc);

          if (self->face_features_sum) // 有记录的人脸时
          {
            int face_id = 0;
            float face_scores[self->face_features_sum] = {0};
            for (int i = 0; i < self->face_features_sum; ++i)
            {
              face_scores[i] = libmaix_nn_feature_compare_float(face_objs->feature, self->face_features[i], self->face_features_len);
              if (face_scores[i] > face_scores[face_id]) face_id = i;
            }
            float face_score = face_scores[face_id];
            if (face_score > self->face_threshold)
            {
              //人脸对比分数大于人脸阈值时,认为是记录的人脸
              self->label_dsc.color = LV_COLOR_GREEN;
              self->rect_dsc.border_color = LV_COLOR_GREEN;
              lv_canvas_draw_rect(zm831_ui_get_canvas(), x, y, w, h, &self->rect_dsc);
              lv_canvas_draw_text(zm831_ui_get_canvas(), x, y - 20, w * 2, &self->label_dsc, string_format("ID%d:%d", face_id + 1, (int)(face_objs->prob * 100)).c_str(), LV_LABEL_ALIGN_LEFT);
              // lv_canvas_draw_text(zm831_ui_get_canvas(), x + 5, y + 5, ai2vi(w), &self->label_dsc, string_format("%d", (int)(prob * 100)).c_str(), LV_LABEL_ALIGN_AUTO);
              int area = ((float)(w * h) / (240 * 240)) * 100;

              uint8_t data[] = { face_id + 1, ai2vi(x + ((w - x) / 2)), ai2vi(y + ((h - y) / 2)), area, (int)(face_objs->prob * 100) };
              zm831_protocol_send(0x0a, (uint8_t *)data, sizeof(data));

              self->state = 2, self->old = zm831->sensor_time;
            }
            else
            {
              self->state = 4, self->old = zm831->sensor_time;
              //人脸对比分数小于人脸阈值时,认为不是记录的人脸
              lv_canvas_draw_rect(zm831_ui_get_canvas(), x, y, w, h, &self->rect_dsc);
              lv_canvas_draw_text(zm831_ui_get_canvas(), x, y - 20, w * 2, &self->label_dsc, string_format("IDx:%d", (int)(face_objs->prob * 100)).c_str(), LV_LABEL_ALIGN_LEFT);
            }
          }
          else
          {
            //没有记录过的人脸
            self->state = 3, self->old = zm831->sensor_time;
            lv_canvas_draw_rect(zm831_ui_get_canvas(), x, y, w, h, &self->rect_dsc);
            lv_canvas_draw_text(zm831_ui_get_canvas(), x, y - 20, w * 2, &self->label_dsc, string_format("IDx:00").c_str(), LV_LABEL_ALIGN_LEFT);
          }
          pthread_mutex_unlock(&zm831->ui_mutex);
        }

        if (self->is_clear)
        {
          self->is_clear = false;
          // printf("is_clear %d\r\n", self->face_features_sum);
          self->face_features_sum = 0;
          {
            auto &result = self->config_json["face_features_sum"];
            if (result.is_integer()) self->config_json["face_features_sum"] = (int)self->face_features_sum;
          }
          zm831_save_json_conf(self->config_file, self->config_json);
        }

        if (self->is_learn)
        {
          self->is_learn = false;
          // printf("is_learn %d\r\n", self->state);
          if (self->state == 3 || self->state == 4) {
            // printf("self->face_features_sum = %d\r\n", self->face_features_sum);
            float *tmp = self->face_features[self->face_features_sum];
            for(int i = 0; i < self->face_features_len; i++) tmp[i] = face_objs->feature[i];
            {
              auto &result = self->config_json["face_features"];
              auto _face_feature = json5pp::array({});
              for (int j = 0; j < self->face_features_len; j++) {
                _face_feature.as_array().push_back(self->face_features[self->face_features_sum][j]);
              }
              result[self->face_features_sum] = _face_feature;
            }
            self->face_features_sum += 1;
            {
              auto &result = self->config_json["face_features_sum"];
              if (result.is_integer()) self->config_json["face_features_sum"] = (int)self->face_features_sum;
            }
            zm831_save_json_conf(self->config_file, self->config_json);
          }
        }

        switch (self->state)
        {
        case 1:
        {
          std::array<uint8_t, 5> data_cmd;
          data_cmd.fill(0);
          zm831_protocol_send(0x0a, (uint8_t *)data_cmd.data(), data_cmd.size());
          pthread_mutex_lock(&zm831->ui_mutex);
          lv_canvas_fill_bg(zm831_ui_get_canvas(), LV_COLOR_BLACK, LV_OPA_TRANSP);
          pthread_mutex_unlock(&zm831->ui_mutex);
          self->state = 0;
          break;
        }
        case 2:
        {
          if (zm831->sensor_time - self->old > 100) {
            self->state = 1;
          }
          break;
        }
        case 3:
        case 4:
        {
          if (zm831->sensor_time - self->old > 100) {
            pthread_mutex_lock(&zm831->ui_mutex);
            lv_canvas_fill_bg(zm831_ui_get_canvas(), LV_COLOR_BLACK, LV_OPA_TRANSP);
            pthread_mutex_unlock(&zm831->ui_mutex);
            self->state = 0;
          }
          break;
        }
        }
      }
    }
    return 0;
  }
}
