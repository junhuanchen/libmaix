
#include "zm831_uvai.hpp"

extern "C"
{
  extern zm831_uv *zm831;

  // ==============================================================================================

#include "libmaix_nn_face.h"

  static struct _nn_retinaface_
  {
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

  } nn_retinaface_app;

  int nn_retinaface_app_load(zm831_home_app *app);
  int nn_retinaface_app_loop(zm831_home_app *app);
  int nn_retinaface_app_exit(zm831_home_app *app);

  zm831_home_app get_nn_retinaface_app()
  {
    return {nn_retinaface_app_load, nn_retinaface_app_loop, nn_retinaface_app_exit, &nn_retinaface_app};
  }

  // ==============================================================================================

  int nn_retinaface_app_load(zm831_home_app *app)
  {
    auto self = (_nn_retinaface_ *)app->userdata;
    lv_draw_rect_dsc_init(&self->rect_dsc);
    self->rect_dsc.radius = 5;
    self->rect_dsc.bg_opa = LV_OPA_TRANSP;
    self->rect_dsc.border_width = 5;
    self->rect_dsc.border_opa = LV_OPA_80;
    self->rect_dsc.border_color = {0x00, 0x00, 0xFF, 0x9f};

    lv_draw_label_dsc_init(&self->label_dsc);
    self->label_dsc.color = LV_COLOR_GREEN;

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

    LIBMAIX_INFO_PRINTF("nn_retinaface_app_load");
    return 0;
  }

  int nn_retinaface_app_exit(zm831_home_app *app)
  {
    auto self = (_nn_retinaface_ *)app->userdata;

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

    pthread_mutex_lock(&zm831->ui_mutex);
    lv_canvas_fill_bg(zm831->canvas, LV_COLOR_BLACK, LV_OPA_TRANSP);
    pthread_mutex_unlock(&zm831->ui_mutex);

    LIBMAIX_INFO_PRINTF("nn_retinaface_app_exit");
    return 0;
  }

  /**
   * @brief 对比人脸数据,找出最大的数据 id 和分数
   *
   * @param face_feature 输出人脸特征向量
   * @param score 输出人脸对比最高的分数
   * @return int 返回人脸对比的 id 索引号,无人脸时返回 -1.
   */
  int nn_get_face_recognize_scores_max(zm831_home_app *app, float *face_feature, float *score)
  {
    auto self = (_nn_retinaface_ *)app->userdata;
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

  int nn_retinaface_app_loop(zm831_home_app *app)
  {
    auto self = (_nn_retinaface_ *)app->userdata;
    libmaix_err_t err = LIBMAIX_ERR_NONE;
    libmaix_image_t *ai_rgb = NULL;
    if (LIBMAIX_ERR_NONE == zm831->ai->capture_image(zm831->ai, &ai_rgb))
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
          lv_canvas_fill_bg(zm831->canvas, LV_COLOR_BLACK, LV_OPA_TRANSP);
          lv_canvas_draw_rect(zm831->canvas, face_objs->x1, face_objs->y1, ai2vi(face_objs->x2 - face_objs->x1), ai2vi(face_objs->y2 - face_objs->y1), &self->rect_dsc);
          lv_canvas_draw_text(zm831->canvas, face_objs->x1, face_objs->y1, 100, &self->label_dsc, prob2str.str().c_str(), LV_LABEL_ALIGN_LEFT);
          for (int i = 0; i < 5; i++) lv_canvas_draw_arc(zm831->canvas, ai2vi(face_objs->key_point.point[i].x), ai2vi(face_objs->key_point.point[i].y), 5, 0, 360, &self->line_dsc);
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
        }
      }
    }
    // LIBMAIX_INFO_PRINTF("nn_retinaface_app_loop");
    return 0;
  }
}
