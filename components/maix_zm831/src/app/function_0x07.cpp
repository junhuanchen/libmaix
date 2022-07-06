
#include "zm831_uvai.hpp"

extern "C"
{
  extern zm831_uv *zm831;

  // ==============================================================================================

  void setup_scr_classific_app(lv_ui *ui)
  {

    // Write codes classific_app
    ui->classific_app = lv_scr_act();

    // Write style LV_OBJ_PART_MAIN for classific_app
    static lv_style_t style_classific_app_main;
    lv_style_reset(&style_classific_app_main);

    // Write style state: LV_STATE_DEFAULT for style_classific_app_main
    lv_style_set_bg_color(&style_classific_app_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
    lv_style_set_bg_opa(&style_classific_app_main, LV_STATE_DEFAULT, 139);
    lv_obj_add_style(ui->classific_app, LV_OBJ_PART_MAIN, &style_classific_app_main);

    // Write codes classific_app_label_top_title
    ui->classific_app_label_top_title = lv_label_create(ui->classific_app, NULL);
    lv_label_set_text(ui->classific_app_label_top_title, "图像分类");
    lv_label_set_long_mode(ui->classific_app_label_top_title, LV_LABEL_LONG_BREAK);
    lv_label_set_align(ui->classific_app_label_top_title, LV_LABEL_ALIGN_CENTER);

    // Write style LV_LABEL_PART_MAIN for classific_app_label_top_title
    static lv_style_t style_classific_app_label_top_title_main;
    lv_style_reset(&style_classific_app_label_top_title_main);

    // Write style state: LV_STATE_DEFAULT for style_classific_app_label_top_title_main
    lv_style_set_radius(&style_classific_app_label_top_title_main, LV_STATE_DEFAULT, 0);
    lv_style_set_bg_color(&style_classific_app_label_top_title_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
    lv_style_set_bg_grad_color(&style_classific_app_label_top_title_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
    lv_style_set_bg_grad_dir(&style_classific_app_label_top_title_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
    lv_style_set_bg_opa(&style_classific_app_label_top_title_main, LV_STATE_DEFAULT, 100);
    lv_style_set_text_color(&style_classific_app_label_top_title_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
    lv_style_set_text_font(&style_classific_app_label_top_title_main, LV_STATE_DEFAULT, &lv_font_simsun_18);
    lv_style_set_text_letter_space(&style_classific_app_label_top_title_main, LV_STATE_DEFAULT, 2);
    lv_style_set_pad_left(&style_classific_app_label_top_title_main, LV_STATE_DEFAULT, 0);
    lv_style_set_pad_right(&style_classific_app_label_top_title_main, LV_STATE_DEFAULT, 0);
    lv_style_set_pad_top(&style_classific_app_label_top_title_main, LV_STATE_DEFAULT, 8);
    lv_style_set_pad_bottom(&style_classific_app_label_top_title_main, LV_STATE_DEFAULT, 8);
    lv_obj_add_style(ui->classific_app_label_top_title, LV_LABEL_PART_MAIN, &style_classific_app_label_top_title_main);
    lv_obj_set_pos(ui->classific_app_label_top_title, 0, 0);
    lv_obj_set_size(ui->classific_app_label_top_title, 240, 0);

    // Write codes classific_app_imgbtn_back
    ui->classific_app_imgbtn_back = lv_imgbtn_create(ui->classific_app, NULL);

    // Write style LV_IMGBTN_PART_MAIN for classific_app_imgbtn_back
    static lv_style_t style_classific_app_imgbtn_back_main;
    lv_style_reset(&style_classific_app_imgbtn_back_main);

    // Write style state: LV_STATE_DEFAULT for style_classific_app_imgbtn_back_main
    lv_style_set_text_color(&style_classific_app_imgbtn_back_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
    lv_style_set_image_recolor(&style_classific_app_imgbtn_back_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
    lv_style_set_image_recolor_opa(&style_classific_app_imgbtn_back_main, LV_STATE_DEFAULT, 0);
    lv_style_set_image_opa(&style_classific_app_imgbtn_back_main, LV_STATE_DEFAULT, 255);

    // Write style state: LV_STATE_PRESSED for style_classific_app_imgbtn_back_main
    lv_style_set_text_color(&style_classific_app_imgbtn_back_main, LV_STATE_PRESSED, lv_color_make(0xFF, 0x33, 0xFF));
    lv_style_set_image_recolor(&style_classific_app_imgbtn_back_main, LV_STATE_PRESSED, lv_color_make(0x00, 0x00, 0x00));
    lv_style_set_image_recolor_opa(&style_classific_app_imgbtn_back_main, LV_STATE_PRESSED, 0);

    // Write style state: LV_STATE_CHECKED for style_classific_app_imgbtn_back_main
    lv_style_set_text_color(&style_classific_app_imgbtn_back_main, LV_STATE_CHECKED, lv_color_make(0xFF, 0x33, 0xFF));
    lv_style_set_image_recolor(&style_classific_app_imgbtn_back_main, LV_STATE_CHECKED, lv_color_make(0x00, 0x00, 0x00));
    lv_style_set_image_recolor_opa(&style_classific_app_imgbtn_back_main, LV_STATE_CHECKED, 0);
    lv_obj_add_style(ui->classific_app_imgbtn_back, LV_IMGBTN_PART_MAIN, &style_classific_app_imgbtn_back_main);
    lv_obj_set_pos(ui->classific_app_imgbtn_back, 20, 180);
    lv_obj_set_size(ui->classific_app_imgbtn_back, 50, 50);
    lv_imgbtn_set_src(ui->classific_app_imgbtn_back, LV_BTN_STATE_RELEASED, &_back_alpha_50x50);
    lv_imgbtn_set_checkable(ui->classific_app_imgbtn_back, true);

    // Init events for screen
  }

  static struct _function_0x07_
  {
    lv_ui *ui = &zm831->ui;

    lv_draw_rect_dsc_t rect_dsc;
    lv_draw_label_dsc_t label_dsc;
    time_t now;

    const char *model_path_param = "/home/res/resnet.param";
    const char *model_path_bin = "/home/res/resnet.bin";
    const char *inputs_names[1] = {"input0"};
    const char *outputs_names[1] = {"output0"};
    const float opt_param_mean = 127.5;
    const float opt_param_norm = 0.00784313725490196;
    libmaix_nn_layer_t input = {
        .w = 224,
        .h = 224,
        .c = 3,
        .dtype = LIBMAIX_NN_DTYPE_UINT8,
    };
    libmaix_nn_layer_t out_fmap = {
        .w = 1,
        .h = 1,
        .c = 1000,
        .dtype = LIBMAIX_NN_DTYPE_FLOAT,
        .layout = LIBMAIX_NN_LAYOUT_CHW,
    };
    libmaix_nn_t *nn;
    libmaix_nn_model_path_t model_path;
    libmaix_nn_opt_param_t opt_param;

    bool init = false;
  } function_0x07_app;

  int function_0x07_app_load(zm831_home_app *app);
  int function_0x07_app_loop(zm831_home_app *app);
  int function_0x07_app_exit(zm831_home_app *app);

  zm831_home_app get_function_0x07_app()
  {
    return {function_0x07_app_load, function_0x07_app_loop, function_0x07_app_exit, &function_0x07_app};
  }

  // ==============================================================================================

  static void nn_resent_get_result(libmaix_nn_layer_t *nn_out, float *max_p, int *max_idx)
  {
      int stride = 1;
      int i;
      float sum = 0;
      float *data = (float*)nn_out->data;
      float largest_i = data[0];
      int n = nn_out->c;
  /*********************************************************/
  // softmax,
      for (i = 0; i < n; ++i)
      {
          if (data[i * stride] > largest_i)
              largest_i = data[i * stride];
      }
      for (i = 0; i < n; ++i)
      {
          float value = expf(data[i * stride] - largest_i);
          sum += value;
          data[i * stride] = value;
      }
      for (i = 0; i < n; ++i)
    {
          data[i * stride] /= sum;
    }
  /*********************************************************/
  // 找出最大值
      for (int i = 0; i < n; ++i)
      {
          if (data[i] > *max_p)
          {
              *max_p = data[i];
              *max_idx = i;
          }
      }
  }

  static void function_0x07_btn_event_app_cb(lv_obj_t *btn, lv_event_t event)
  {
    // printf("btn %p event %d\n", btn, event);
    if (function_0x07_app.ui->classific_app_imgbtn_back == btn && event == LV_EVENT_SHORT_CLICKED)
    {
      zm831_home_app_select(0);
      return;
    }
  }

  int function_0x07_app_load(zm831_home_app *app)
  {
    auto self = (_function_0x07_ *)app->userdata;
lv_draw_rect_dsc_init(&self->rect_dsc);
    self->rect_dsc.radius = 5;
    self->rect_dsc.bg_opa = LV_OPA_TRANSP;
    self->rect_dsc.border_width = 5;
    self->rect_dsc.border_opa = LV_OPA_80;
    self->rect_dsc.border_color = {0x00, 0x00, 0xFF, 0x9f};

    lv_draw_label_dsc_init(&self->label_dsc);
    self->label_dsc.color = LV_COLOR_YELLOW;

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

    self->input.need_quantization = true;

    self->out_fmap.data = (float *)malloc(self->out_fmap.w * self->out_fmap.h * self->out_fmap.c * sizeof(float));
    if (!self->out_fmap.data)
    {
      LIBMAIX_INFO_PRINTF("no memory!!!\n");
      return -1;
    }

    self->input.buff_quantization = (uint8_t *)malloc(self->input.w * self->input.h * self->input.c);
    if (!self->input.buff_quantization)
    {
      LIBMAIX_INFO_PRINTF("no memory!!!\n");
      return -1;
    }

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

    if (!self->init)
    {
      zm831_home_setup_ui(&self->ui->classific_app, setup_scr_classific_app, 500);

      pthread_mutex_lock(&zm831->ui_mutex);
      lv_obj_set_event_cb(self->ui->classific_app_imgbtn_back, function_0x07_btn_event_app_cb);
      pthread_mutex_unlock(&zm831->ui_mutex);

      self->init = true;
    }
    LIBMAIX_INFO_PRINTF("function_0x07_app_load");
    return 0;
  }

  int function_0x07_app_exit(zm831_home_app *app)
  {
    auto self = (_function_0x07_ *)app->userdata;

    if (self->input.buff_quantization)
    {
      free(self->input.buff_quantization);
      self->input.buff_quantization = NULL;
    }
    if (self->out_fmap.data)
    {
      free(self->out_fmap.data);
      self->out_fmap.data = NULL;
    }
    if (self->nn)
    {
      libmaix_nn_destroy(&self->nn);
    }

    if (self->init)
    {
      zm831_home_clear_ui(&self->ui->classific_app);
      self->init = false;
    }
    LIBMAIX_INFO_PRINTF("function_0x07_app_exit");
    return 0;
  }

  int function_0x07_app_loop(zm831_home_app *app)
  {
    auto self = (_function_0x07_ *)app->userdata;
    libmaix_err_t err = LIBMAIX_ERR_NONE;
    libmaix_image_t *ai_rgb = NULL;
    if (zm831->ai && LIBMAIX_ERR_NONE == zm831->ai->capture_image(zm831->ai, &ai_rgb))
    {
      self->input.data = ai_rgb->data;
      err = self->nn->forward(self->nn, &self->input, &self->out_fmap);
      if (err == LIBMAIX_ERR_NONE)
      {
        float max_p = 0;
        int max_idx = 0;
        nn_resent_get_result(&self->out_fmap, &max_p, &max_idx);
        printf("nn_resent_get_result: %f, %d\r\n", max_p, max_idx);
        // printf("nn_resent_get_result: %f, %d, %s\r\n", max_p, max_idx, classes_label[max_idx]);
      }
    }
    return 0;
  }
}
