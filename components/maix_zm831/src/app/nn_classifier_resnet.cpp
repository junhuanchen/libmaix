
#include "zm831_uvai.hpp"

extern "C"
{
  extern zm831_uv *zm831;

  // ==============================================================================================

  static struct _nn_classifier_resnet_
  {
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
  } nn_classifier_resnet_app;

  int nn_classifier_resnet_app_load(zm831_home_app *app);
  int nn_classifier_resnet_app_loop(zm831_home_app *app);
  int nn_classifier_resnet_app_exit(zm831_home_app *app);

  zm831_home_app get_nn_classifier_resnet_app()
  {
    return {nn_classifier_resnet_app_load, nn_classifier_resnet_app_loop, nn_classifier_resnet_app_exit, &nn_classifier_resnet_app};
  }

  // ==============================================================================================

  void nn_resent_get_result(libmaix_nn_layer_t *nn_out, float *max_p, int *max_idx)
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

  int nn_classifier_resnet_app_load(zm831_home_app *app)
  {
    auto self = (_nn_classifier_resnet_ *)app->userdata;
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

    LIBMAIX_INFO_PRINTF("nn_classifier_resnet_app_load");
    return 0;
  }

  int nn_classifier_resnet_app_exit(zm831_home_app *app)
  {
    auto self = (_nn_classifier_resnet_ *)app->userdata;

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

    pthread_mutex_lock(&zm831->ui_mutex);
    lv_canvas_fill_bg(zm831->canvas, LV_COLOR_BLACK, LV_OPA_TRANSP);
    pthread_mutex_unlock(&zm831->ui_mutex);

    LIBMAIX_INFO_PRINTF("nn_classifier_resnet_app_exit");
    return 0;
  }

  int nn_classifier_resnet_app_loop(zm831_home_app *app)
  {
    auto self = (_nn_classifier_resnet_ *)app->userdata;
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
    // LIBMAIX_INFO_PRINTF("nn_classifier_resnet_app_loop");
    return 0;
  }
}
