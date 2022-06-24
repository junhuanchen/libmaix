#include "zm831_uvai.hpp"

extern "C"
{
  extern zm831_uv *zm831;

  // ==============================================================================================

  static struct _cv_nn_find_ball_
  {
    lv_draw_rect_dsc_t rect_dsc;
    lv_draw_label_dsc_t label_dsc;
    time_t now;

    const char *model_path_param = "/home/res/ball.param";
    const char *model_path_bin = "/home/res/ball.bin";
    const char *inputs_names[1] = {"input0"};
    const char *outputs_names[1] = {"output0"};
    const float opt_param_mean = 127.5;
    const float opt_param_norm = 0.00784313725490196;
    libmaix_nn_layer_t input = {
        .w = 32,
        .h = 32,
        .c = 1,
        .dtype = LIBMAIX_NN_DTYPE_UINT8,
    };
    libmaix_nn_layer_t out_fmap = {
        .w = 1,
        .h = 1,
        .c = 2,
        .dtype = LIBMAIX_NN_DTYPE_FLOAT,
    };
    libmaix_nn_t *nn;
    libmaix_nn_model_path_t model_path;
    libmaix_nn_opt_param_t opt_param;

    int threshold_target = 0; // < thresholds.size()
    std::vector<std::vector<int>> thresholds[4] = {
        {{21, 78, 34, 77, -8, 55}, {18, 61, 25, 61, -2, 50}},
        {{6, 86, -47, -9, 12, 46}},
        {{10, 60, 5, 41, -70, -24}, {20, 55, 8, 42, -88, -24}},
        {{50, 100, -2, 40, 40, 90}},
    };

  } cv_nn_find_ball_app;

  int cv_nn_find_ball_app_load(zm831_home_app *app);
  int cv_nn_find_ball_app_loop(zm831_home_app *app);
  int cv_nn_find_ball_app_exit(zm831_home_app *app);

  zm831_home_app get_cv_nn_find_ball_app()
  {
    return {cv_nn_find_ball_app_load, cv_nn_find_ball_app_loop, cv_nn_find_ball_app_exit, &cv_nn_find_ball_app};
  }

  cv::Mat cv_resize_with_padding(cv::Mat cv_src, int dst_w, int dst_h)
  {
    cv::Mat cv_dst;
    int src_w = cv_src.cols, src_h = cv_src.rows;
    float scale_src = ((float)src_w) / ((float)src_h), scale_dst = ((float)dst_w) / ((float)dst_h);
    if (scale_dst == scale_src)
    {
      // func == InterpolationFlags default 1 == cv::INTER_LINEAR
      cv::resize(cv_src, cv_dst, cv::Size(dst_w, dst_h), cv::INTER_LINEAR);
    }
    else
    {
      // Scale to original image
      int new_w = 0, new_h = 0, top = 0, bottom = 0, left = 0, right = 0;
      if (scale_src > scale_dst)
      {
        new_w = dst_w, new_h = new_w * src_h / src_w; // new_h / src_h = new_w / src_w => new_h = new_w * src_h / src_w
        top = (dst_h - new_h) / 2, bottom = top;
      }
      else
      { // Division loses precision
        new_h = dst_h, new_w = new_h * src_w / src_h;
        left = (dst_w - new_w) / 2, right = left;
      }
      // printf("_resize %d %d > %d %d > %d %d : %d %d %d %d \r\n", src_w, src_h, new_w, new_h, dst_w, dst_h, top, bottom, left, right);
      // printf("[dls] 1 %p\n", cv_dst.data);
      cv::resize(cv_src, cv_dst, cv::Size(new_w, new_h), cv::INTER_LINEAR);
      // printf("[dls] 2 %p\n", cv_dst.data);
      cv::copyMakeBorder(cv_dst, cv_dst, top, bottom, left, right, IPL_BORDER_CONSTANT);
    }
    return std::move(cv_dst);
  }

  std::vector<std::vector<int>> cv_nn_find_ball(cv::Mat &lab, std::vector<std::vector<int>> &thresholds, int x_stride, int y_stride, int area_threshold, int pixels_threshold, int w_min, int h_min, bool invert, bool margin)
  {
    std::vector<std::vector<int>> return_val;
    cv::Mat tmp, mask = cv::Mat::zeros(lab.size(), CV_8UC1);
    for (size_t i = 0; i < thresholds.size(); i++)
    {
      // LMin AMin BMin LMax AMax BMax
      cv::inRange(lab, cv::Scalar(thresholds[i][0], thresholds[i][1], thresholds[i][2]), cv::Scalar(thresholds[i][3], thresholds[i][4], thresholds[i][5]), tmp);
      mask = mask + tmp;
    }

    if (invert)
    {
      cv::bitwise_not(mask, mask);
    }

    extern void zm831_ui_show_image(cv::Mat &img, int x, int y);
    zm831_ui_show_image(mask, 8, 8);

    cv::Mat se = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(x_stride, y_stride), cv::Point(-1, -1));
    cv::morphologyEx(mask, mask, cv::MORPH_OPEN, se);
    if (margin != 0)
    {
      cv::Mat se_t = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(margin, margin), cv::Point(-1, -1));
      cv::morphologyEx(mask, mask, cv::MORPH_CLOSE, se_t);
    }

    std::vector<std::vector<cv::Point>> contours;
    std::vector<cv::Vec4i> hiearchy;
    cv::findContours(mask, contours, hiearchy, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_NONE);

    if (contours.size() == 0)
    {
      return std::move(return_val);
    }

    for (size_t i = 0; i < contours.size(); i++)
    {
      cv::Rect rects = cv::boundingRect(contours[i]);
      if (int(rects.width) * int(rects.width) < area_threshold)
      {
        continue;
      }
      if (int(cv::contourArea(contours[i])) < pixels_threshold)
      {
        continue;
      }
      if (int(rects.width) < w_min)
      {
        continue;
      }
      if (int(rects.height) < h_min)
      {
        continue;
      }

      auto tmp = std::vector<int>{
          int(rects.x), int(rects.y), int(rects.width), int(rects.height),
          int(cv::contourArea(contours[i])),
          int(rects.x + rects.width / 2), int(rects.y + rects.height / 2)
      };

      if (contours[i].size() < 6)
      {
        tmp.push_back(0);
        return_val.push_back(tmp);
        continue;
      }

      cv::RotatedRect rrt = fitEllipse(contours[i]);
      int cr_x, cr_y, cr_w, cr_h;
      cr_x = rrt.center.x;
      cr_y = rrt.center.y;
      cr_w = rrt.size.width;
      cr_h = rrt.size.height;

      if ((abs(cr_w - cr_h) > 10) || (cr_w * cr_h) < 400)
      {
        tmp.push_back(0);
        return_val.push_back(tmp);
      }
      else
      {
        tmp.push_back(1);
        tmp.push_back(cr_x);
        tmp.push_back(cr_y);
        tmp.push_back(cr_w);
        tmp.push_back(cr_h);
        tmp.push_back(cr_x - cr_w / 2);
        tmp.push_back(cr_x + cr_w / 2);
        tmp.push_back(cr_y - cr_h / 2);
        tmp.push_back(cr_y + cr_h / 2);
        return_val.push_back(tmp);
      }

    }
    return std::move(return_val);
  }

  int cv_nn_find_ball_app_loop(zm831_home_app *app)
  {
    auto self = (_cv_nn_find_ball_ *)app->userdata;
    libmaix_image_t *ai_rgb = NULL;
    if (LIBMAIX_ERR_NONE == zm831->ai->capture_image(zm831->ai, &ai_rgb))
    {
      try
      {
        // LIBMAIX_INFO_PRINTF("ai_rgb: %p, %d, %d\r\n", ai_rgb, ai_rgb->width, ai_rgb->height);
        cv::Mat lab, rgb(ai_rgb->height, ai_rgb->width, CV_8UC3, ai_rgb->data);
        cvtColor(rgb, lab, cv::COLOR_RGB2Lab);
        auto result = cv_nn_find_ball(lab, self->thresholds[self->threshold_target], 2, 2, 500, 10, 22, 22, 0, 0);
        for (size_t i = 0; i < result.size(); i++)
        {
          std::cout << result[i].size() << " ";
          for (size_t j = 0; j < result[i].size(); j++)
          {
            std::cout << result[i][j] << " ";
          }
          std::cout << std::endl;
        }
      }
      catch(const std::exception& e)
      {
        std::cerr << e.what() << '\n';
      }
    }

    usleep(zm831->ai_th_usec);

    if (!zm831->recvPacks.empty()){
      zm831_pack_t pack = zm831->recvPacks.front();
      zm831->recvPacks.pop_front();
      LIBMAIX_INFO_PRINTF("recv pack type: %d\n", pack.type);
      auto tmp = pack.data;
      for (int i = 0; i < tmp.size(); i++) printf(" 0x%02X", tmp[i]);
      printf("\n");
    }

    // LIBMAIX_INFO_PRINTF("_zm831_home_app_loop");
  }

  int cv_nn_find_ball_app_load(zm831_home_app *app)
  {
    auto self = (_cv_nn_find_ball_ *)app->userdata;

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

    LIBMAIX_INFO_PRINTF("cv_nn_find_ball_app_load");
    return 0;
  }

  int cv_nn_find_ball_app_exit(zm831_home_app *app)
  {
    auto self = (_cv_nn_find_ball_ *)app->userdata;

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

    LIBMAIX_INFO_PRINTF("cv_nn_find_ball_app_exit");
    return 0;
  }
}