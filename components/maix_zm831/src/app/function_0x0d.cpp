
#include "zm831_uvai.hpp"

extern "C"
{
  extern zm831_uv *zm831;

  // ==============================================================================================

  void setup_scr_traffic_app(lv_ui *ui)
  {

    // Write codes traffic_app
    ui->traffic_app = lv_obj_create(NULL, NULL);

    // Write style LV_OBJ_PART_MAIN for traffic_app
    static lv_style_t style_traffic_app_main;
    lv_style_reset(&style_traffic_app_main);

    // Write style state: LV_STATE_DEFAULT for style_traffic_app_main
    lv_style_set_bg_color(&style_traffic_app_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
    lv_style_set_bg_opa(&style_traffic_app_main, LV_STATE_DEFAULT, 139);
    lv_obj_add_style(ui->traffic_app, LV_OBJ_PART_MAIN, &style_traffic_app_main);

    // Write codes traffic_app_label_top_title
    ui->traffic_app_label_top_title = lv_label_create(ui->traffic_app, NULL);
    lv_label_set_text(ui->traffic_app_label_top_title, "交通标志识别");
    lv_label_set_long_mode(ui->traffic_app_label_top_title, LV_LABEL_LONG_BREAK);
    lv_label_set_align(ui->traffic_app_label_top_title, LV_LABEL_ALIGN_CENTER);

    // Write style LV_LABEL_PART_MAIN for traffic_app_label_top_title
    static lv_style_t style_traffic_app_label_top_title_main;
    lv_style_reset(&style_traffic_app_label_top_title_main);

    // Write style state: LV_STATE_DEFAULT for style_traffic_app_label_top_title_main
    lv_style_set_radius(&style_traffic_app_label_top_title_main, LV_STATE_DEFAULT, 0);
    lv_style_set_bg_color(&style_traffic_app_label_top_title_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
    lv_style_set_bg_grad_color(&style_traffic_app_label_top_title_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
    lv_style_set_bg_grad_dir(&style_traffic_app_label_top_title_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
    lv_style_set_bg_opa(&style_traffic_app_label_top_title_main, LV_STATE_DEFAULT, 100);
    lv_style_set_text_color(&style_traffic_app_label_top_title_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
    lv_style_set_text_font(&style_traffic_app_label_top_title_main, LV_STATE_DEFAULT, &lv_font_simsun_18);
    lv_style_set_text_letter_space(&style_traffic_app_label_top_title_main, LV_STATE_DEFAULT, 2);
    lv_style_set_pad_left(&style_traffic_app_label_top_title_main, LV_STATE_DEFAULT, 0);
    lv_style_set_pad_right(&style_traffic_app_label_top_title_main, LV_STATE_DEFAULT, 0);
    lv_style_set_pad_top(&style_traffic_app_label_top_title_main, LV_STATE_DEFAULT, 8);
    lv_style_set_pad_bottom(&style_traffic_app_label_top_title_main, LV_STATE_DEFAULT, 8);
    lv_obj_add_style(ui->traffic_app_label_top_title, LV_LABEL_PART_MAIN, &style_traffic_app_label_top_title_main);
    lv_obj_set_pos(ui->traffic_app_label_top_title, 0, 0);
    lv_obj_set_size(ui->traffic_app_label_top_title, 240, 0);

    // Write codes traffic_app_imgbtn_back
    ui->traffic_app_imgbtn_back = lv_imgbtn_create(ui->traffic_app, NULL);

    // Write style LV_IMGBTN_PART_MAIN for traffic_app_imgbtn_back
    static lv_style_t style_traffic_app_imgbtn_back_main;
    lv_style_reset(&style_traffic_app_imgbtn_back_main);

    // Write style state: LV_STATE_DEFAULT for style_traffic_app_imgbtn_back_main
    lv_style_set_text_color(&style_traffic_app_imgbtn_back_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
    lv_style_set_image_recolor(&style_traffic_app_imgbtn_back_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
    lv_style_set_image_recolor_opa(&style_traffic_app_imgbtn_back_main, LV_STATE_DEFAULT, 0);
    lv_style_set_image_opa(&style_traffic_app_imgbtn_back_main, LV_STATE_DEFAULT, 255);

    // Write style state: LV_STATE_PRESSED for style_traffic_app_imgbtn_back_main
    lv_style_set_text_color(&style_traffic_app_imgbtn_back_main, LV_STATE_PRESSED, lv_color_make(0xFF, 0x33, 0xFF));
    lv_style_set_image_recolor(&style_traffic_app_imgbtn_back_main, LV_STATE_PRESSED, lv_color_make(0x00, 0x00, 0x00));
    lv_style_set_image_recolor_opa(&style_traffic_app_imgbtn_back_main, LV_STATE_PRESSED, 0);

    // Write style state: LV_STATE_CHECKED for style_traffic_app_imgbtn_back_main
    lv_style_set_text_color(&style_traffic_app_imgbtn_back_main, LV_STATE_CHECKED, lv_color_make(0xFF, 0x33, 0xFF));
    lv_style_set_image_recolor(&style_traffic_app_imgbtn_back_main, LV_STATE_CHECKED, lv_color_make(0x00, 0x00, 0x00));
    lv_style_set_image_recolor_opa(&style_traffic_app_imgbtn_back_main, LV_STATE_CHECKED, 0);
    lv_obj_add_style(ui->traffic_app_imgbtn_back, LV_IMGBTN_PART_MAIN, &style_traffic_app_imgbtn_back_main);
    lv_obj_set_pos(ui->traffic_app_imgbtn_back, 20, 180);
    lv_obj_set_size(ui->traffic_app_imgbtn_back, 50, 50);
    lv_imgbtn_set_src(ui->traffic_app_imgbtn_back, LV_BTN_STATE_RELEASED, &_back_alpha_50x50);
    lv_imgbtn_set_checkable(ui->traffic_app_imgbtn_back, true);
  }

  static struct _function_0x0d_
  {
    lv_ui *ui = &zm831->ui;

    lv_draw_rect_dsc_t rect_dsc;
    lv_draw_label_dsc_t label_dsc;
    time_t now;

    const char *model_path_param = "/home/res/yolo2_face_int8.param";
    const char *model_path_bin = "/home/res/yolo2_face_int8.bin";
    const char *inputs_names[1] = {"input0"};
    const char *outputs_names[1] = {"output0"};
    const float opt_param_mean = 127.5;
    const float opt_param_norm = 0.0078125;
    libmaix_nn_layer_t input = {
        .w = 224,
        .h = 224,
        .c = 3,
        .dtype = LIBMAIX_NN_DTYPE_UINT8,
    };
    libmaix_nn_layer_t out_fmap = {
        .w = 7,
        .h = 7,
        .c = 30,
        .dtype = LIBMAIX_NN_DTYPE_FLOAT,
    };
    libmaix_nn_t *nn;
    libmaix_nn_model_path_t model_path;
    libmaix_nn_opt_param_t opt_param;
    // -------------- yolo2 decode -----------------------
    const char *labels[1] = {"face"};
    const float anchors[10] = {1.19, 1.98, 2.79, 4.59, 4.53, 8.92, 8.06, 5.29, 10.32, 10.65};
    libmaix_nn_decoder_t *yolo2_decoder;
    libmaix_nn_decoder_yolo2_result_t yolo2_result;
    libmaix_nn_decoder_yolo2_config_t yolo2_config = {
        .classes_num = sizeof(labels) / sizeof(anchors[0]),
        .threshold = 0.5,
        .nms_value = 0.3,
        .anchors_num = (sizeof(anchors) / sizeof(anchors[0])) / 2,
        .anchors = (float *)anchors,
        .net_in_width = 224,
        .net_in_height = 224,
        .net_out_width = 7,
        .net_out_height = 7,
        .input_width = 224,
        .input_height = 224
    };

    bool init = false;
  } function_0x0d_app;

  int function_0x0d_app_load(zm831_home_app *app);
  int function_0x0d_app_loop(zm831_home_app *app);
  int function_0x0d_app_exit(zm831_home_app *app);

  zm831_home_app get_function_0x0d_app()
  {
    return {function_0x0d_app_load, function_0x0d_app_loop, function_0x0d_app_exit, &function_0x0d_app};
  }

  // ==============================================================================================

  static int max_index(float *a, int n)
  {
    int i, max_i = 0;
    float max = a[0];

    for (i = 1; i < n; ++i)
    {
      if (a[i] > max)
      {
        max = a[i];
        max_i = i;
      }
    }
    return max_i;
  }

  static void libmaix_nn_decoder_yolo2_draw(zm831_home_app *app, struct libmaix_nn_decoder *obj, libmaix_nn_decoder_yolo2_result_t *result)
  {
    auto self = (_function_0x0d_ *)app->userdata;

    region_layer_t *rl = (region_layer_t *)obj->data;
    char *label = NULL;
    uint32_t image_width = rl->config->input_width;
    uint32_t image_height = rl->config->input_height;
    float threshold = rl->config->threshold;
    libmaix_nn_decoder_yolo2_box_t *boxes = result->boxes;

    pthread_mutex_lock(&zm831->ui_mutex);
    lv_canvas_fill_bg(zm831_ui_get_canvas(), LV_COLOR_BLACK, LV_OPA_TRANSP);
    for (int i = 0; i < result->boxes_num; ++i)
    {
      int class_id = max_index(rl->probs[i], rl->config->classes_num);
      float prob = result->probs[i][class_id];
      if (prob > threshold)
      {
        libmaix_nn_decoder_yolo2_box_t *b = boxes + i;
        uint32_t x = b->x * image_width - (b->w * image_width / 2);
        uint32_t y = b->y * image_height - (b->h * image_height / 2);
        uint32_t w = b->w * image_width;
        uint32_t h = b->h * image_height;
        printf("%d %d %d %d %f %s\n", x, y, w, h, prob, self->labels[class_id]);
        std::ostringstream prob2str;
        prob2str << prob;
        lv_canvas_draw_rect(zm831_ui_get_canvas(), x, y, ai2vi(w), ai2vi(h), &self->rect_dsc);
        lv_canvas_draw_text(zm831_ui_get_canvas(), x, y, 120, &self->label_dsc, prob2str.str().c_str(), LV_LABEL_ALIGN_AUTO);
      }
    }
    pthread_mutex_unlock(&zm831->ui_mutex);
  }

  static void function_0x0d_btn_event_app_cb(lv_obj_t *btn, lv_event_t event)
  {
    // printf("btn %p event %d\n", btn, event);
    if (function_0x0d_app.ui->traffic_app_imgbtn_back == btn && event == LV_EVENT_SHORT_CLICKED)
    {
      zm831_home_app_select(0);
      return;
    }
  }

  int function_0x0d_app_load(zm831_home_app *app)
  {
    auto self = (_function_0x0d_ *)app->userdata;

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

    LIBMAIX_INFO_PRINTF("-- yolo2 decoder create\n");
    self->yolo2_decoder = libmaix_nn_decoder_yolo2_create(libmaix_nn_decoder_yolo2_init,
                                                          libmaix_nn_decoder_yolo2_deinit,
                                                          libmaix_nn_decoder_yolo2_decode);
    if (!self->yolo2_decoder)
    {
      LIBMAIX_INFO_PRINTF("no mem\n");
      return -1;
    }
    LIBMAIX_INFO_PRINTF("-- yolo2 decoder init\n");
    err = self->yolo2_decoder->init(self->yolo2_decoder, (void *)&self->yolo2_config);
    if (err != LIBMAIX_ERR_NONE)
    {
      LIBMAIX_INFO_PRINTF("decoder init error:%d\n", err);
      return -1;
    }

    if (!self->init)
    {
      zm831_home_setup_ui(&self->ui->traffic_app, setup_scr_traffic_app, 500);

      pthread_mutex_lock(&zm831->ui_mutex);
      lv_obj_set_event_cb(self->ui->traffic_app_imgbtn_back, function_0x0d_btn_event_app_cb);
      pthread_mutex_unlock(&zm831->ui_mutex);

      self->init = true;
    }
    LIBMAIX_INFO_PRINTF("function_0x0d_app_load");
    return 0;
  }

  int function_0x0d_app_exit(zm831_home_app *app)
  {
    auto self = (_function_0x0d_ *)app->userdata;

    if (self->yolo2_decoder)
    {
      self->yolo2_decoder->deinit(self->yolo2_decoder);
      libmaix_nn_decoder_yolo2_destroy(&self->yolo2_decoder);
      self->yolo2_decoder = NULL;
    }
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
      zm831_home_clear_ui(&self->ui->traffic_app);
      self->init = false;
    }
    LIBMAIX_INFO_PRINTF("function_0x0d_app_exit");
    return 0;
  }

  int function_0x0d_app_loop(zm831_home_app *app)
  {
    auto self = (_function_0x0d_ *)app->userdata;
    libmaix_err_t err = LIBMAIX_ERR_NONE;
    libmaix_image_t *ai_rgb = NULL;
    if (zm831->ai && LIBMAIX_ERR_NONE == zm831->ai->capture_image(zm831->ai, &ai_rgb))
    {
      
      self->input.data = ai_rgb->data;
      err = self->nn->forward(self->nn, &self->input, &self->out_fmap);
      if (err != LIBMAIX_ERR_NONE)
      {
        printf("libmaix_nn forward fail: %s\n", libmaix_get_err_msg(err));
      }

      err = self->yolo2_decoder->decode(self->yolo2_decoder, &self->out_fmap, (void *)&self->yolo2_result);
      if (err != LIBMAIX_ERR_NONE)
      {
        printf("yolo2 decode fail: %s\n", libmaix_get_err_msg(err));
      }

      if (self->yolo2_result.boxes_num > 0)
      {
        libmaix_nn_decoder_yolo2_draw(app, self->yolo2_decoder, &self->yolo2_result);
        // LIBMAIX_INFO_PRINTF("yolo2_result.boxes_num %d", self->yolo2_result.boxes_num);
      }

    }
    return 0;
  }
}
