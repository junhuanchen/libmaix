
#include "zm831_uvai.hpp"

extern "C"
{
  extern zm831_uv *zm831;

  // ==============================================================================================

  #include "libmaix_nn_classifier.h"

  static struct _nn_classifier_custom_
  {
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

    const char* classifier_pth = "classifier.bin";
    int class_num = 3;
    int sample_num = 8;
    int feature_length = 512;
    int input_w = 224, input_h = 224;
    float class_prob = 0;
    int class_id = -1;
    int i_class_num = 0, i_sample_num = 0, flag_trained = 0;
    void* classifier_obj;

  } nn_classifier_custom_app;

  int nn_classifier_custom_app_load(zm831_home_app *app);
  int nn_classifier_custom_app_loop(zm831_home_app *app);
  int nn_classifier_custom_app_exit(zm831_home_app *app);

  zm831_home_app get_nn_classifier_custom_app()
  {
    return {nn_classifier_custom_app_load, nn_classifier_custom_app_loop, nn_classifier_custom_app_exit, &nn_classifier_custom_app};
  }

  // ==============================================================================================

  int nn_classifier_custom_app_load(zm831_home_app *app)
  {
    auto self = (_nn_classifier_custom_ *)app->userdata;
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
    if(err != LIBMAIX_ERR_NONE)
    {
      self->i_class_num = self->i_sample_num = self->flag_trained = 0;
      LIBMAIX_INFO_PRINTF("libmaix_classifier_load fail\n");
      libmaix_classifier_init(&self->classifier_obj, self->nn, self->feature_length, self->input_w, self->input_h, self->class_num, self->sample_num);
    } else {
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

    LIBMAIX_INFO_PRINTF("nn_classifier_custom_app_load");
    return 0;
  }

  int nn_classifier_custom_app_exit(zm831_home_app *app)
  {
    auto self = (_nn_classifier_custom_ *)app->userdata;

    if(self->classifier_obj)
    {
        libmaix_classifier_del(&self->classifier_obj);
    }

    if (self->nn)
    {
      libmaix_nn_destroy(&self->nn);
    }

    pthread_mutex_lock(&zm831->ui_mutex);
    lv_canvas_fill_bg(zm831->canvas, LV_COLOR_BLACK, LV_OPA_TRANSP);
    pthread_mutex_unlock(&zm831->ui_mutex);

    LIBMAIX_INFO_PRINTF("nn_classifier_custom_app_exit");
    return 0;
  }

  int nn_classifier_custom_app_loop(zm831_home_app *app)
  {
    auto self = (_nn_classifier_custom_ *)app->userdata;
    libmaix_err_t err = LIBMAIX_ERR_NONE;
    libmaix_image_t *ai_rgb = NULL;
    if (LIBMAIX_ERR_NONE == zm831->ai->capture_image(zm831->ai, &ai_rgb))
    {
      if (self->flag_trained)
      {
        err = libmaix_classifier_predict(self->classifier_obj, ai_rgb, &self->class_id, &self->class_prob);
        if (err != LIBMAIX_ERR_NONE)
        {
          printf("libmaix_classifier_predict fail: %s\n", libmaix_get_err_msg(err));
        } else {
          if (self->class_id >= 0)
          {
            printf("class id: %d, class prob: %f\n", self->class_id, 100 - self->class_prob);
            std::ostringstream prob2str;
            prob2str << "class id: " << self->class_id << ", prob: " << (int)((100 - self->class_prob) * 10) << std::endl;
            pthread_mutex_lock(&zm831->ui_mutex);
            lv_canvas_fill_bg(zm831->canvas, LV_COLOR_BLACK, LV_OPA_TRANSP);
            lv_canvas_draw_text(zm831->canvas, 0, 0, 240, &self->label_dsc, prob2str.str().c_str(), LV_LABEL_ALIGN_CENTER);
            pthread_mutex_unlock(&zm831->ui_mutex);
          }
        }
      } else {
        printf("wait for training\n");
        if(self->i_class_num < self->class_num)
        {
          printf("add class img, class num: %d\n", self->i_class_num);
          sleep(2);
          libmaix_classifier_add_class_img(&self->classifier_obj, ai_rgb, &self->i_class_num);
          self->i_class_num++; // 先添加类别
        }
        else if(self->i_sample_num < self->sample_num)
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
          if(err != LIBMAIX_ERR_NONE)
          {
            printf("libmaix_classifier_init fail\n");
            libmaix_classifier_init(&self->classifier_obj, self->nn, self->feature_length, self->input_w, self->input_h, self->class_num, self->sample_num);
          }
          printf("train classifier\n");
        }
      }
    }
    // LIBMAIX_INFO_PRINTF("nn_classifier_custom_app_loop");
    return 0;
  }
}
