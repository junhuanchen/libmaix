
#include "zm831_uvai.hpp"

extern "C"
{
  extern zm831_uv *zm831;

  // ==============================================================================================

  void setup_scr_ball_app(lv_ui *ui)
  {
    // Write codes ball_app
    ui->ball_app = lv_scr_act();

    // Write style LV_OBJ_PART_MAIN for ball_app
    static lv_style_t style_ball_app_main;
    lv_style_reset(&style_ball_app_main);

    // Write style state: LV_STATE_DEFAULT for style_ball_app_main
    lv_style_set_bg_color(&style_ball_app_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
    lv_style_set_bg_opa(&style_ball_app_main, LV_STATE_DEFAULT, 0);
    lv_obj_add_style(ui->ball_app, LV_OBJ_PART_MAIN, &style_ball_app_main);

    // Write codes ball_app_label_top_title
    ui->ball_app_label_top_title = lv_label_create(ui->ball_app, NULL);
    lv_label_set_text(ui->ball_app_label_top_title, "小球识别");
    lv_label_set_long_mode(ui->ball_app_label_top_title, LV_LABEL_LONG_BREAK);
    lv_label_set_align(ui->ball_app_label_top_title, LV_LABEL_ALIGN_CENTER);

    // Write style LV_LABEL_PART_MAIN for ball_app_label_top_title
    static lv_style_t style_ball_app_label_top_title_main;
    lv_style_reset(&style_ball_app_label_top_title_main);

    // Write style state: LV_STATE_DEFAULT for style_ball_app_label_top_title_main
    lv_style_set_radius(&style_ball_app_label_top_title_main, LV_STATE_DEFAULT, 0);
    lv_style_set_bg_color(&style_ball_app_label_top_title_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
    lv_style_set_bg_grad_color(&style_ball_app_label_top_title_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
    lv_style_set_bg_grad_dir(&style_ball_app_label_top_title_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
    lv_style_set_bg_opa(&style_ball_app_label_top_title_main, LV_STATE_DEFAULT, 100);
    lv_style_set_text_color(&style_ball_app_label_top_title_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
    lv_style_set_text_font(&style_ball_app_label_top_title_main, LV_STATE_DEFAULT, &lv_font_simsun_18);
    lv_style_set_text_letter_space(&style_ball_app_label_top_title_main, LV_STATE_DEFAULT, 2);
    lv_style_set_pad_left(&style_ball_app_label_top_title_main, LV_STATE_DEFAULT, 0);
    lv_style_set_pad_right(&style_ball_app_label_top_title_main, LV_STATE_DEFAULT, 0);
    lv_style_set_pad_top(&style_ball_app_label_top_title_main, LV_STATE_DEFAULT, 8);
    lv_style_set_pad_bottom(&style_ball_app_label_top_title_main, LV_STATE_DEFAULT, 8);
    lv_obj_add_style(ui->ball_app_label_top_title, LV_LABEL_PART_MAIN, &style_ball_app_label_top_title_main);
    lv_obj_set_pos(ui->ball_app_label_top_title, 0, 0);
    lv_obj_set_size(ui->ball_app_label_top_title, 240, 0);

    // Write codes ball_app_imgbtn_back
    ui->ball_app_imgbtn_back = lv_imgbtn_create(ui->ball_app, NULL);

    // Write style LV_IMGBTN_PART_MAIN for ball_app_imgbtn_back
    static lv_style_t style_ball_app_imgbtn_back_main;
    lv_style_reset(&style_ball_app_imgbtn_back_main);

    // Write style state: LV_STATE_DEFAULT for style_ball_app_imgbtn_back_main
    lv_style_set_text_color(&style_ball_app_imgbtn_back_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
    lv_style_set_image_recolor(&style_ball_app_imgbtn_back_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
    lv_style_set_image_recolor_opa(&style_ball_app_imgbtn_back_main, LV_STATE_DEFAULT, 0);
    lv_style_set_image_opa(&style_ball_app_imgbtn_back_main, LV_STATE_DEFAULT, 255);

    // Write style state: LV_STATE_PRESSED for style_ball_app_imgbtn_back_main
    lv_style_set_text_color(&style_ball_app_imgbtn_back_main, LV_STATE_PRESSED, lv_color_make(0xFF, 0x33, 0xFF));
    lv_style_set_image_recolor(&style_ball_app_imgbtn_back_main, LV_STATE_PRESSED, lv_color_make(0x00, 0x00, 0x00));
    lv_style_set_image_recolor_opa(&style_ball_app_imgbtn_back_main, LV_STATE_PRESSED, 0);

    // Write style state: LV_STATE_CHECKED for style_ball_app_imgbtn_back_main
    lv_style_set_text_color(&style_ball_app_imgbtn_back_main, LV_STATE_CHECKED, lv_color_make(0xFF, 0x33, 0xFF));
    lv_style_set_image_recolor(&style_ball_app_imgbtn_back_main, LV_STATE_CHECKED, lv_color_make(0x00, 0x00, 0x00));
    lv_style_set_image_recolor_opa(&style_ball_app_imgbtn_back_main, LV_STATE_CHECKED, 0);
    lv_obj_add_style(ui->ball_app_imgbtn_back, LV_IMGBTN_PART_MAIN, &style_ball_app_imgbtn_back_main);
    lv_obj_set_pos(ui->ball_app_imgbtn_back, 20, 180);
    lv_obj_set_size(ui->ball_app_imgbtn_back, 50, 50);
    lv_imgbtn_set_src(ui->ball_app_imgbtn_back, LV_BTN_STATE_RELEASED, &_back_alpha_50x50);
    lv_imgbtn_set_checkable(ui->ball_app_imgbtn_back, true);

    // Write codes ball_app_imgbtn_change_color
    ui->ball_app_imgbtn_change_color = lv_imgbtn_create(ui->ball_app, NULL);

    // Write style LV_IMGBTN_PART_MAIN for ball_app_imgbtn_change_color
    static lv_style_t style_ball_app_imgbtn_change_color_main;
    lv_style_reset(&style_ball_app_imgbtn_change_color_main);

    // Write style state: LV_STATE_DEFAULT for style_ball_app_imgbtn_change_color_main
    lv_style_set_text_color(&style_ball_app_imgbtn_change_color_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
    lv_style_set_image_recolor(&style_ball_app_imgbtn_change_color_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
    lv_style_set_image_recolor_opa(&style_ball_app_imgbtn_change_color_main, LV_STATE_DEFAULT, 0);
    lv_style_set_image_opa(&style_ball_app_imgbtn_change_color_main, LV_STATE_DEFAULT, 255);

    // Write style state: LV_STATE_PRESSED for style_ball_app_imgbtn_change_color_main
    lv_style_set_text_color(&style_ball_app_imgbtn_change_color_main, LV_STATE_PRESSED, lv_color_make(0xFF, 0x33, 0xFF));
    lv_style_set_image_recolor(&style_ball_app_imgbtn_change_color_main, LV_STATE_PRESSED, lv_color_make(0x00, 0x00, 0x00));
    lv_style_set_image_recolor_opa(&style_ball_app_imgbtn_change_color_main, LV_STATE_PRESSED, 0);

    // Write style state: LV_STATE_CHECKED for style_ball_app_imgbtn_change_color_main
    lv_style_set_text_color(&style_ball_app_imgbtn_change_color_main, LV_STATE_CHECKED, lv_color_make(0xFF, 0x33, 0xFF));
    lv_style_set_image_recolor(&style_ball_app_imgbtn_change_color_main, LV_STATE_CHECKED, lv_color_make(0x00, 0x00, 0x00));
    lv_style_set_image_recolor_opa(&style_ball_app_imgbtn_change_color_main, LV_STATE_CHECKED, 0);
    lv_obj_add_style(ui->ball_app_imgbtn_change_color, LV_IMGBTN_PART_MAIN, &style_ball_app_imgbtn_change_color_main);
    lv_obj_set_pos(ui->ball_app_imgbtn_change_color, 88, 170);
    lv_obj_set_size(ui->ball_app_imgbtn_change_color, 63, 63);
    lv_imgbtn_set_src(ui->ball_app_imgbtn_change_color, LV_BTN_STATE_RELEASED, &_home_ball_alpha_63x63);
    lv_imgbtn_set_checkable(ui->ball_app_imgbtn_change_color, true);
  }

  static struct _function_0x04_
  {
    lv_ui *ui = &zm831->ui;

    lv_draw_line_dsc_t line_dsc;
    lv_draw_rect_dsc_t rect_dsc;
    lv_draw_label_dsc_t label_dsc;

    const char *model_path_param = "/home/res/ball.param";
    const char *model_path_bin = "/home/res/ball.bin";
    const char *inputs_names[1] = {"ftr00_input_blob"};
    const char *outputs_names[1] = {"fc2_blob"};
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

    lv_color_t bgra_lab_color[4] = {
        {0, 0, 255, 255},  // red
        {0, 255, 0, 255},  // green
        {255, 0, 0, 255},  // blue
        {0, 255, 255, 255} // yellow
    };

    uint32_t old, target = 0; // < thresholds.size()
    std::vector<std::vector<int>> thresholds[4] = {
        {{mv2cvL(5), mv2cvA(30), mv2cvB(-29), mv2cvL(50), mv2cvA(85), mv2cvA(72)}}, // 红
        {{mv2cvL(20), mv2cvA(-60), mv2cvB(-18), mv2cvL(74), mv2cvA(-8), mv2cvA(62)}}, // 绿
        {{mv2cvL(5), mv2cvA(3), mv2cvB(-81), mv2cvL(82), mv2cvA(57), mv2cvA(-30)}}, // 蓝
        {{mv2cvL(50), mv2cvA(-1), mv2cvB(40), mv2cvL(100), mv2cvA(40), mv2cvA(90)}}, // 黄
    };

    bool init = false;
  } function_0x04_app;

  int function_0x04_app_load(zm831_home_app *app);
  int function_0x04_app_loop(zm831_home_app *app);
  int function_0x04_app_exit(zm831_home_app *app);

  zm831_home_app get_function_0x04_app()
  {
    return {function_0x04_app_load, function_0x04_app_loop, function_0x04_app_exit, &function_0x04_app};
  }

  // =============================================================================================

  static cv::Mat cv_resize_with_padding(cv::Mat cv_src, int dst_w, int dst_h)
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

  static std::vector<std::vector<int>> cv_nn_find_ball(zm831_home_app *app, cv::Mat &lab, std::vector<std::vector<int>> &thresholds, int x_stride, int y_stride, int area_threshold, int pixels_threshold, int w_min, int h_min, bool invert, bool margin)
  {
    auto self = (_function_0x04_ *)app->userdata;
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

    // zm831_ui_show_image(mask, 8, 8, LV_OPA_100);

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
          int(rects.x + rects.width / 2), int(rects.y + rects.height / 2)};

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
        // show ball image
        cv::Mat ball = cv_resize_with_padding(mask(cv::Rect(rects.x, rects.y, rects.width, rects.height)), 32, 32);

        // zm831_ui_show_image(ball, 0, 0, LV_OPA_100);

        self->input.data = ball.data;
        libmaix_err_t err = self->nn->forward(self->nn, &self->input, &self->out_fmap);
        if (err == LIBMAIX_ERR_NONE)
        {
          float *ball_val = (float *)self->out_fmap.data;
          // printf("%f\n", ball_val[0]);
          if (ball_val[0] > 0.5)
          {
            tmp.push_back(2);
          }
          else
          {
            tmp.push_back(0);
          }
          return_val.push_back(tmp);
        }
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

  static void function_0x04_btn_event_app_cb(lv_obj_t *btn, lv_event_t event)
  {
    if (function_0x04_app.ui->ball_app_imgbtn_back == btn && event == LV_EVENT_SHORT_CLICKED)
    {
      zm831_home_app_select(0);
      return;
    }
  }

  int function_0x04_app_load(zm831_home_app *app)
  {
    auto self = (_function_0x04_ *)app->userdata;

    if (!self->init)
    {

      lv_draw_line_dsc_init(&self->line_dsc);
      self->line_dsc.color = {0xFF, 0x00, 0x00, 0x9f};
      self->line_dsc.width = 2;
      self->line_dsc.opa = LV_OPA_70;

      lv_draw_rect_dsc_init(&self->rect_dsc);
      self->rect_dsc.radius = 5;
      self->rect_dsc.bg_opa = LV_OPA_10;
      self->rect_dsc.border_width = 2;
      self->rect_dsc.border_opa = LV_OPA_80;
      self->rect_dsc.border_color = {0x00, 0x00, 0xFF, 0x9f};

      lv_draw_label_dsc_init(&self->label_dsc);
      self->label_dsc.color = LV_COLOR_GREEN;

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

      zm831_home_setup_ui(&self->ui->ball_app, setup_scr_ball_app, 500);

      pthread_mutex_lock(&zm831->ui_mutex);
      lv_obj_set_event_cb(self->ui->ball_app_imgbtn_back, function_0x04_btn_event_app_cb);
      pthread_mutex_unlock(&zm831->ui_mutex);

      self->init = true;
    }

    LIBMAIX_INFO_PRINTF("function_0x04_app_load");
    return 0;
  }

  int function_0x04_app_exit(zm831_home_app *app)
  {
    auto self = (_function_0x04_ *)app->userdata;
    if (self->init)
    {

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

      zm831_home_clear_ui(&self->ui->ball_app);

      self->init = false;
    }
    LIBMAIX_INFO_PRINTF("function_0x04_app_exit");
    return 0;
  }

  int function_0x04_app_loop(zm831_home_app *app)
  {
    auto self = (_function_0x04_ *)app->userdata;
    libmaix_image_t *ai_rgb = NULL;
    if (zm831->ai && LIBMAIX_ERR_NONE == zm831->ai->capture_image(zm831->ai, &ai_rgb))
    {
      try
      {
        if (!zm831->recvPacks.empty())
        {
          auto pack = zm831->recvPacks.front();
          // for(auto i = 0; i < pack.data.size(); i++) printf("%02x ", pack.data[i]);
          // printf("\n");
          if (pack.type == 0x04)
          {
            if (pack.data.size() > 7 && 0 <= pack.data[7] && pack.data[7] < 4)
            {
              self->target = pack.data[7];
              // printf("target: %d\n", self->target);
            }
          }
          zm831->recvPacks.pop_front();
        }

        int now = zm831_get_ms();
        if (now - self->old > 200) // 200ms
        {
          self->old = now;
          // for (int i = 0; i < sizeof(self->data_cmd); i++) printf("%02x-", self->data_cmd[i]);
          // printf("\r\n");
          // memset(self->data_cmd + 1, 0, sizeof(self->data_cmd) - 1);
          // zm831_protocol_send(self->data_cmd, sizeof(self->data_cmd));
          zm831_ui_show_clear();
        }

        // LIBMAIX_INFO_PRINTF("ai_rgb: %p, %d, %d\r\n", ai_rgb, ai_rgb->width, ai_rgb->height);
        cv::Mat lab, rgb(ai_rgb->height, ai_rgb->width, CV_8UC3, ai_rgb->data);
        cvtColor(rgb, lab, cv::COLOR_RGB2Lab);
        auto result = cv_nn_find_ball(app, lab, self->thresholds[self->target], 2, 2, 500, 10, 22, 22, 0, 0);

        pthread_mutex_lock(&zm831->ui_mutex);
        // std::cout << result.size() << std::endl;
        for (const auto& tmp : result)
        {
          int x = ai2vi(tmp[0]), y = ai2vi(tmp[1]), w = ai2vi(tmp[2]), h = ai2vi(tmp[3]);
          switch (tmp[7])
          {
            case 1:
            {
              self->rect_dsc.border_color = self->rect_dsc.bg_color = self->bgra_lab_color[self->target];
              self->line_dsc.color = self->bgra_lab_color[self->target];
              lv_canvas_draw_rect(zm831_ui_get_canvas(), x, y, w, h, &self->rect_dsc);
              lv_canvas_draw_arc(zm831_ui_get_canvas(), ai2vi(tmp[8]), ai2vi(tmp[9]), tmp[10] / 2 , 0, 360, &self->line_dsc);
              int area = (tmp[10] / 2) * (tmp[10] / 2) * 3.14;
              char data[] = { 0x04, self->target, x, y, (area > 255) ? 255 : area };
              zm831_protocol_send((uint8_t *)data, sizeof(data));
              break;
            }
            case 2:
            {
              // self->old = now;
              self->rect_dsc.bg_color = self->bgra_lab_color[self->target];
              lv_canvas_draw_rect(zm831_ui_get_canvas(), x, y, w, h, &self->rect_dsc);
              int area = (w) * (h);
              char data[] = { 0x04, self->target, x, y, (area > 255) ? 255 : area };
              zm831_protocol_send((uint8_t *)data, sizeof(data));
              break;
            }
            case 0:
              break;
            default:
              break;
          }
        }
        pthread_mutex_unlock(&zm831->ui_mutex);
      }
      catch(const std::exception& e)
      {
        std::cerr << e.what() << '\n';
      }
    }

    return 0;
  }
}
