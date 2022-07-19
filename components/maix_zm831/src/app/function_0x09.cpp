
#include "zm831_uvai.hpp"

extern "C"
{
  extern zm831_uv *zm831;

  // ==============================================================================================

  void setup_scr_color_study_app(lv_ui *ui)
  {

    // Write codes color_study_app
    ui->color_study_app = lv_scr_act();

    // Write style LV_OBJ_PART_MAIN for color_study_app
    static lv_style_t style_color_study_app_main;
    lv_style_reset(&style_color_study_app_main);

    // Write style state: LV_STATE_DEFAULT for style_color_study_app_main
    lv_style_set_bg_color(&style_color_study_app_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
    lv_style_set_bg_opa(&style_color_study_app_main, LV_STATE_DEFAULT, 0);
    lv_obj_add_style(ui->color_study_app, LV_OBJ_PART_MAIN, &style_color_study_app_main);

    // Write codes color_study_app_label_top_title
    ui->color_study_app_label_top_title = lv_label_create(ui->color_study_app, NULL);
    lv_label_set_text(ui->color_study_app_label_top_title, "颜色学习");
    lv_label_set_long_mode(ui->color_study_app_label_top_title, LV_LABEL_LONG_BREAK);
    lv_label_set_align(ui->color_study_app_label_top_title, LV_LABEL_ALIGN_CENTER);

    // Write style LV_LABEL_PART_MAIN for color_study_app_label_top_title
    static lv_style_t style_color_study_app_label_top_title_main;
    lv_style_reset(&style_color_study_app_label_top_title_main);

    // Write style state: LV_STATE_DEFAULT for style_color_study_app_label_top_title_main
    lv_style_set_radius(&style_color_study_app_label_top_title_main, LV_STATE_DEFAULT, 0);
    lv_style_set_bg_color(&style_color_study_app_label_top_title_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
    lv_style_set_bg_grad_color(&style_color_study_app_label_top_title_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
    lv_style_set_bg_grad_dir(&style_color_study_app_label_top_title_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
    lv_style_set_bg_opa(&style_color_study_app_label_top_title_main, LV_STATE_DEFAULT, 100);
    lv_style_set_text_color(&style_color_study_app_label_top_title_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
    lv_style_set_text_font(&style_color_study_app_label_top_title_main, LV_STATE_DEFAULT, &lv_font_simsun_18);
    lv_style_set_text_letter_space(&style_color_study_app_label_top_title_main, LV_STATE_DEFAULT, 2);
    lv_style_set_pad_left(&style_color_study_app_label_top_title_main, LV_STATE_DEFAULT, 0);
    lv_style_set_pad_right(&style_color_study_app_label_top_title_main, LV_STATE_DEFAULT, 0);
    lv_style_set_pad_top(&style_color_study_app_label_top_title_main, LV_STATE_DEFAULT, 8);
    lv_style_set_pad_bottom(&style_color_study_app_label_top_title_main, LV_STATE_DEFAULT, 8);
    lv_obj_add_style(ui->color_study_app_label_top_title, LV_LABEL_PART_MAIN, &style_color_study_app_label_top_title_main);
    lv_obj_set_pos(ui->color_study_app_label_top_title, 0, 0);
    lv_obj_set_size(ui->color_study_app_label_top_title, 240, 0);

    // Write codes color_study_app_imgbtn_back
    ui->color_study_app_imgbtn_back = lv_imgbtn_create(ui->color_study_app, NULL);

    // Write style LV_IMGBTN_PART_MAIN for color_study_app_imgbtn_back
    static lv_style_t style_color_study_app_imgbtn_back_main;
    lv_style_reset(&style_color_study_app_imgbtn_back_main);

    // Write style state: LV_STATE_DEFAULT for style_color_study_app_imgbtn_back_main
    lv_style_set_text_color(&style_color_study_app_imgbtn_back_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
    lv_style_set_image_recolor(&style_color_study_app_imgbtn_back_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
    lv_style_set_image_recolor_opa(&style_color_study_app_imgbtn_back_main, LV_STATE_DEFAULT, 0);
    lv_style_set_image_opa(&style_color_study_app_imgbtn_back_main, LV_STATE_DEFAULT, 255);

    // Write style state: LV_STATE_PRESSED for style_color_study_app_imgbtn_back_main
    lv_style_set_text_color(&style_color_study_app_imgbtn_back_main, LV_STATE_PRESSED, lv_color_make(0xFF, 0x33, 0xFF));
    lv_style_set_image_recolor(&style_color_study_app_imgbtn_back_main, LV_STATE_PRESSED, lv_color_make(0x00, 0x00, 0x00));
    lv_style_set_image_recolor_opa(&style_color_study_app_imgbtn_back_main, LV_STATE_PRESSED, 0);

    // Write style state: LV_STATE_CHECKED for style_color_study_app_imgbtn_back_main
    lv_style_set_text_color(&style_color_study_app_imgbtn_back_main, LV_STATE_CHECKED, lv_color_make(0xFF, 0x33, 0xFF));
    lv_style_set_image_recolor(&style_color_study_app_imgbtn_back_main, LV_STATE_CHECKED, lv_color_make(0x00, 0x00, 0x00));
    lv_style_set_image_recolor_opa(&style_color_study_app_imgbtn_back_main, LV_STATE_CHECKED, 0);
    lv_obj_add_style(ui->color_study_app_imgbtn_back, LV_IMGBTN_PART_MAIN, &style_color_study_app_imgbtn_back_main);
    lv_obj_set_pos(ui->color_study_app_imgbtn_back, 20, 180);
    lv_obj_set_size(ui->color_study_app_imgbtn_back, 50, 50);
    lv_imgbtn_set_src(ui->color_study_app_imgbtn_back, LV_BTN_STATE_RELEASED, &_back_alpha_50x50);
    lv_imgbtn_set_checkable(ui->color_study_app_imgbtn_back, true);

    // Write codes color_study_app_imgbtn_clear
    ui->color_study_app_imgbtn_clear = lv_imgbtn_create(ui->color_study_app, NULL);

    // Write style LV_IMGBTN_PART_MAIN for color_study_app_imgbtn_clear
    static lv_style_t style_color_study_app_imgbtn_clear_main;
    lv_style_reset(&style_color_study_app_imgbtn_clear_main);

    // Write style state: LV_STATE_DEFAULT for style_color_study_app_imgbtn_clear_main
    lv_style_set_text_color(&style_color_study_app_imgbtn_clear_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
    lv_style_set_image_recolor(&style_color_study_app_imgbtn_clear_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
    lv_style_set_image_recolor_opa(&style_color_study_app_imgbtn_clear_main, LV_STATE_DEFAULT, 0);
    lv_style_set_image_opa(&style_color_study_app_imgbtn_clear_main, LV_STATE_DEFAULT, 255);

    // Write style state: LV_STATE_PRESSED for style_color_study_app_imgbtn_clear_main
    lv_style_set_text_color(&style_color_study_app_imgbtn_clear_main, LV_STATE_PRESSED, lv_color_make(0xFF, 0x33, 0xFF));
    lv_style_set_image_recolor(&style_color_study_app_imgbtn_clear_main, LV_STATE_PRESSED, lv_color_make(0x00, 0x00, 0x00));
    lv_style_set_image_recolor_opa(&style_color_study_app_imgbtn_clear_main, LV_STATE_PRESSED, 0);

    // Write style state: LV_STATE_CHECKED for style_color_study_app_imgbtn_clear_main
    lv_style_set_text_color(&style_color_study_app_imgbtn_clear_main, LV_STATE_CHECKED, lv_color_make(0xFF, 0x33, 0xFF));
    lv_style_set_image_recolor(&style_color_study_app_imgbtn_clear_main, LV_STATE_CHECKED, lv_color_make(0x00, 0x00, 0x00));
    lv_style_set_image_recolor_opa(&style_color_study_app_imgbtn_clear_main, LV_STATE_CHECKED, 0);
    lv_obj_add_style(ui->color_study_app_imgbtn_clear, LV_IMGBTN_PART_MAIN, &style_color_study_app_imgbtn_clear_main);
    lv_obj_set_pos(ui->color_study_app_imgbtn_clear, 170, 180);
    lv_obj_set_size(ui->color_study_app_imgbtn_clear, 50, 50);
    lv_imgbtn_set_src(ui->color_study_app_imgbtn_clear, LV_BTN_STATE_RELEASED, &_clear_alpha_50x50);
    lv_imgbtn_set_checkable(ui->color_study_app_imgbtn_clear, true);

    // Write codes color_study_app_imgbtn_press
    ui->color_study_app_imgbtn_press = lv_imgbtn_create(ui->color_study_app, NULL);

    // Write style LV_IMGBTN_PART_MAIN for color_study_app_imgbtn_press
    static lv_style_t style_color_study_app_imgbtn_press_main;
    lv_style_reset(&style_color_study_app_imgbtn_press_main);

    // Write style state: LV_STATE_DEFAULT for style_color_study_app_imgbtn_press_main
    lv_style_set_text_color(&style_color_study_app_imgbtn_press_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
    lv_style_set_image_recolor(&style_color_study_app_imgbtn_press_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
    lv_style_set_image_recolor_opa(&style_color_study_app_imgbtn_press_main, LV_STATE_DEFAULT, 0);
    lv_style_set_image_opa(&style_color_study_app_imgbtn_press_main, LV_STATE_DEFAULT, 255);

    // Write style state: LV_STATE_PRESSED for style_color_study_app_imgbtn_press_main
    lv_style_set_text_color(&style_color_study_app_imgbtn_press_main, LV_STATE_PRESSED, lv_color_make(0xFF, 0x33, 0xFF));
    lv_style_set_image_recolor(&style_color_study_app_imgbtn_press_main, LV_STATE_PRESSED, lv_color_make(0x00, 0x00, 0x00));
    lv_style_set_image_recolor_opa(&style_color_study_app_imgbtn_press_main, LV_STATE_PRESSED, 0);

    // Write style state: LV_STATE_CHECKED for style_color_study_app_imgbtn_press_main
    lv_style_set_text_color(&style_color_study_app_imgbtn_press_main, LV_STATE_CHECKED, lv_color_make(0xFF, 0x33, 0xFF));
    lv_style_set_image_recolor(&style_color_study_app_imgbtn_press_main, LV_STATE_CHECKED, lv_color_make(0x00, 0x00, 0x00));
    lv_style_set_image_recolor_opa(&style_color_study_app_imgbtn_press_main, LV_STATE_CHECKED, 0);
    lv_obj_add_style(ui->color_study_app_imgbtn_press, LV_IMGBTN_PART_MAIN, &style_color_study_app_imgbtn_press_main);
    lv_obj_set_pos(ui->color_study_app_imgbtn_press, 88, 170);
    lv_obj_set_size(ui->color_study_app_imgbtn_press, 63, 63);
    lv_imgbtn_set_src(ui->color_study_app_imgbtn_press, LV_BTN_STATE_RELEASED, &_study_alpha_63x63);
    lv_imgbtn_set_checkable(ui->color_study_app_imgbtn_press, true);
  }

#include "imlib.h"

  static struct _function_0x09_
  {
    lv_ui *ui = &zm831->ui;

    lv_color_t lab_colors[4] = {
        {0, 0, 255, 255},  // red
        {0, 255, 0, 255},  // green
        {255, 0, 0, 255},  // blue
        {0, 255, 255, 255} // yellow
    };

    color_thresholds_list_lnk_data_t lab_thresholds[4] = {
        {0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0},
        // {.LMin = 5, .LMax = 50, .AMin = 30, .AMax = 85, .BMin = -29, .BMax = 72},   //红
        // {.LMin = 20, .LMax = 74, .AMin = -60, .AMax = -8, .BMin = -18, .BMax = 62}, //绿
        // {.LMin = 5, .LMax = 82, .AMin = 3, .AMax = 57, .BMin = -81, .BMax = -30},   //蓝
        // {.LMin = 50, .LMax = 100, .AMin = -2, .AMax = 40, .BMin = 40, .BMax = 90},  //黄
    };

    uint32_t old = 0;
    uint8_t state = 0;
    int8_t color_learn_id = -1;
    uint8_t is_clear_color = false;
    uint8_t is_learn_color = false;
    std::array<uint8_t, 4> data_cmd;

    lv_draw_rect_dsc_t rect_dsc;
    lv_draw_label_dsc_t label_dsc;

    const char *config_file = "/root/function_0x09.json";
    json5pp::value config_json;

    bool init = false;
  } function_0x09_app;

  int function_0x09_app_load(zm831_home_app *app);
  int function_0x09_app_loop(zm831_home_app *app);
  int function_0x09_app_exit(zm831_home_app *app);

  zm831_home_app get_function_0x09_app()
  {
    return {function_0x09_app_load, function_0x09_app_loop, function_0x09_app_exit, &function_0x09_app};
  }

  // ==============================================================================================

  static statistics_t get_roi_color_lab(image_t *arg_img, rectangle_t roi)
  {
    // fb_alloc_mark();
    //定义直方图通道
    histogram_t hist;
    hist.LBinCount = COLOR_L_MAX - COLOR_L_MIN + 1;
    hist.ABinCount = COLOR_A_MAX - COLOR_A_MIN + 1;
    hist.BBinCount = COLOR_B_MAX - COLOR_B_MIN + 1;
    //分配直方图通道内存
    hist.LBins = (float *)fb_alloc(hist.LBinCount * sizeof(float), FB_ALLOC_NO_HINT);
    hist.ABins = (float *)fb_alloc(hist.ABinCount * sizeof(float), FB_ALLOC_NO_HINT);
    hist.BBins = (float *)fb_alloc(hist.BBinCount * sizeof(float), FB_ALLOC_NO_HINT);
    //获取直方图
    imlib_get_histogram(&hist, arg_img, &roi, NULL, false, NULL);
    //定义统计值
    statistics_t stats;
    //进行直方图统计
    imlib_get_statistics(&stats, (pixformat_t)arg_img->pixfmt, &hist);
    fb_free(hist.BBins);
    fb_free(hist.ABins);
    fb_free(hist.LBins);
    // fb_alloc_free_till_mark();
    return stats;
  }

  static void function_0x09_btn_event_app_cb(lv_obj_t *btn, lv_event_t event)
  {
    // printf("btn %p event %d\n", btn, event);
    if (function_0x09_app.ui->color_study_app_imgbtn_back == btn && event == LV_EVENT_SHORT_CLICKED)
    {
      zm831_home_app_select(0);
      return;
    }
    if (function_0x09_app.ui->color_study_app_imgbtn_clear == btn && event == LV_EVENT_SHORT_CLICKED)
    {
      function_0x09_app.is_clear_color = true;
      return;
    }
    if (function_0x09_app.ui->color_study_app_imgbtn_press == btn && event == LV_EVENT_SHORT_CLICKED)
    {
      function_0x09_app.is_learn_color = true;
      return;
    }
  }

  void function_0x09_cfg_load(_function_0x09_ *self)
  {
    int cfgsum = 0;
    {
      auto result = self->config_json["color_learn_id"];
      if (result.is_integer())
      {
        self->color_learn_id = result.as_integer();
        if (self->color_learn_id > 4 || self->color_learn_id < -1) {
          self->color_learn_id = -1;
        }
        cfgsum += 1;
      }
    }
    {
      auto result = self->config_json["lab_thresholds"];
      if (result.is_array())
      {
        auto arr = result.as_array();
        if (arr.size() == 4)
        {
          for (int i = 0; i < 4; i++)
          {
            auto item = arr[i];
            if (item.is_array())
            {
              auto arr = item.as_array();
              self->lab_thresholds[i].LMin = arr[0].as_integer();
              self->lab_thresholds[i].LMax = arr[1].as_integer();
              self->lab_thresholds[i].AMin = arr[2].as_integer();
              self->lab_thresholds[i].AMax = arr[3].as_integer();
              self->lab_thresholds[i].BMin = arr[4].as_integer();
              self->lab_thresholds[i].BMax = arr[5].as_integer();
              cfgsum += 1;
            }
          }
        }
      }
    }
    {
      auto result = self->config_json["lab_colors"];
      if (result.is_array())
      {
        auto arr = result.as_array();
        if (arr.size() == 4)
        {
          for (int i = 0; i < 4; i++)
          {
            auto item = arr[i];
            if (item.is_array())
            {
              auto arr = item.as_array();
              self->lab_colors[i].ch.red = arr[0].as_integer();
              self->lab_colors[i].ch.green = arr[1].as_integer();
              self->lab_colors[i].ch.blue = arr[2].as_integer();
              self->lab_colors[i].ch.alpha = arr[3].as_integer();
              cfgsum += 1;
            }
          }
        }
      }
    }
    if (cfgsum == 9)
    {
      LIBMAIX_INFO_PRINTF("function_0x09_app_load conf success");
    }
    else
    {
      LIBMAIX_INFO_PRINTF("function_0x09_app_load conf error need reset");
      system(string_format("rm -f %s", self->config_file).c_str());
    }
    zm831_save_json_conf(self->config_file, self->config_json);
  }

  int function_0x09_app_load(zm831_home_app *app)
  {
    auto self = (_function_0x09_ *)app->userdata;

    fb_realloc_init1(1 * 1024 * 1024);

    zm831_load_json_conf(self->config_file, self->config_json,
      json5pp::object({{"color_learn_id", -1}, {
        "lab_thresholds",
        json5pp::array({json5pp::array({self->lab_thresholds[0].LMin, self->lab_thresholds[0].LMax, self->lab_thresholds[0].AMin, self->lab_thresholds[0].AMax, self->lab_thresholds[0].BMin, self->lab_thresholds[0].BMax}), json5pp::array({self->lab_thresholds[1].LMin, self->lab_thresholds[1].LMax, self->lab_thresholds[1].AMin, self->lab_thresholds[1].AMax, self->lab_thresholds[1].BMin, self->lab_thresholds[1].BMax}), json5pp::array({self->lab_thresholds[2].LMin, self->lab_thresholds[2].LMax, self->lab_thresholds[2].AMin, self->lab_thresholds[2].AMax, self->lab_thresholds[2].BMin, self->lab_thresholds[2].BMax}), json5pp::array({self->lab_thresholds[3].LMin, self->lab_thresholds[3].LMax, self->lab_thresholds[3].AMin, self->lab_thresholds[3].AMax, self->lab_thresholds[3].BMin, self->lab_thresholds[3].BMax})}),
      },
      {
        "lab_colors",
        json5pp::array({json5pp::array({self->lab_colors[0].ch.red, self->lab_colors[0].ch.green, self->lab_colors[0].ch.blue, self->lab_colors[0].ch.alpha}), json5pp::array({self->lab_colors[1].ch.red, self->lab_colors[1].ch.green, self->lab_colors[1].ch.blue, self->lab_colors[1].ch.alpha}), json5pp::array({self->lab_colors[2].ch.red, self->lab_colors[2].ch.green, self->lab_colors[2].ch.blue, self->lab_colors[2].ch.alpha}), json5pp::array({self->lab_colors[3].ch.red, self->lab_colors[3].ch.green, self->lab_colors[3].ch.blue, self->lab_colors[3].ch.alpha})}),
      }})
    );

    function_0x09_cfg_load(self);

    if (!self->init)
    {
      lv_draw_rect_dsc_init(&self->rect_dsc);
      self->rect_dsc.radius = 5;
      self->rect_dsc.bg_opa = LV_OPA_80;
      self->rect_dsc.border_width = 2;
      self->rect_dsc.border_opa = LV_OPA_90;
      self->rect_dsc.border_color = {0x00, 0x00, 0x00, 0x7f};

      lv_draw_label_dsc_init(&self->label_dsc);
      self->label_dsc.color = LV_COLOR_GREEN;
      // self->label_dsc.font = zm831->ft_font.font;

      zm831_home_setup_ui(&self->ui->color_study_app, setup_scr_color_study_app, 500);

      pthread_mutex_lock(&zm831->ui_mutex);
      lv_obj_set_event_cb(self->ui->color_study_app_imgbtn_back, function_0x09_btn_event_app_cb);
      lv_obj_set_event_cb(self->ui->color_study_app_imgbtn_clear, function_0x09_btn_event_app_cb);
      lv_obj_set_event_cb(self->ui->color_study_app_imgbtn_press, function_0x09_btn_event_app_cb);
      pthread_mutex_unlock(&zm831->ui_mutex);

      self->init = true;
    }
    LIBMAIX_INFO_PRINTF("function_0x09_app_load");
    return 0;
  }

  int function_0x09_app_exit(zm831_home_app *app)
  {
    auto self = (_function_0x09_ *)app->userdata;

    fb_alloc_close0();

    zm831_save_json_conf(self->config_file, self->config_json);

    if (self->init)
    {
      zm831_home_clear_ui(&self->ui->color_study_app);
      self->init = false;
    }
    LIBMAIX_INFO_PRINTF("function_0x09_app_exit");
    return 0;
  }

  int function_0x09_app_loop(zm831_home_app *app)
  {
    auto self = (_function_0x09_ *)app->userdata;
    libmaix_err_t err = LIBMAIX_ERR_NONE;
    libmaix_image_t *ai_rgb = NULL;
    if (zm831->ai && LIBMAIX_ERR_NONE == zm831->ai->capture_image(zm831->ai, &ai_rgb))
    {
      image_t imlib_img, *img = &imlib_img;
      {
        img->w = ai_rgb->width;
        img->h = ai_rgb->height;
        img->data = (uint8_t *)ai_rgb->data;
        img->size = ai_rgb->width * ai_rgb->height * 3;
        img->is_data_alloc = NULL;
        img->pixfmt = PIXFORMAT_RGB888;
      }

      fb_alloc_mark();

      if (!zm831->recvPacks.empty())
      {
        auto pack = zm831->recvPacks.front();
        // for(auto i = 0; i < pack.data.size(); i++) printf("%02x ", pack.data[i]);
        // printf("\n");
        if (pack.data[5] == 0x16 && pack.type == 0x01)
        {
          self->is_learn_color = true;
        }
        zm831->recvPacks.pop_front();
      }

      color_thresholds_list_lnk_data_t tmp_lab;
      lv_color_t tmp_rgb;

      pthread_mutex_lock(&zm831->ui_mutex);
      lv_canvas_fill_bg(zm831_ui_get_canvas(), LV_COLOR_BLACK, LV_OPA_TRANSP);

      if (self->color_learn_id < 3)
      {
        const rectangle_t goal_roi = { .x = vi2ai(110), .y = vi2ai(110), .w = vi2ai(20), .h = vi2ai(20), };

        statistics_t stats = get_roi_color_lab(img, goal_roi);
        tmp_lab = (color_thresholds_list_lnk_data_t){
            .LMin = stats.LMin, .LMax = stats.LMax, .AMin = stats.AMin,
            .AMax = stats.AMax, .BMin = stats.BMin, .BMax = stats.BMax,
        };
        int pixel = COLOR_LAB_TO_RGB888(stats.LMode, stats.AMode, stats.BMode);
        tmp_rgb = {COLOR_RGB888_TO_B8(pixel), COLOR_RGB888_TO_G8(pixel), COLOR_RGB888_TO_R8(pixel), 0xFF};
        self->rect_dsc.bg_color = tmp_rgb;
        lv_canvas_draw_rect(zm831_ui_get_canvas(), 110, 110, 20, 20, &self->rect_dsc);
      }

      if (self->color_learn_id >= 0)
      {
        list_t thresholds;
        imlib_list_init(&thresholds, sizeof(color_thresholds_list_lnk_data_t));
        bool invert = false;
        rectangle_t roi = { .x = 0, .y = 0, .w = (int16_t)img->w, .h = (int16_t)img->h, };
        unsigned int x_stride = 30;
        unsigned int y_stride = 30;
        unsigned int area_threshold = 150;
        unsigned int pixels_threshold = 150;
        bool merge = false;
        int margin = 0;
        unsigned int x_hist_bins_max = 0;
        unsigned int y_hist_bins_max = 0;
        int now = zm831_get_ms();
        list_t out;
        for (int i = 0, sum = self->color_learn_id + 1; i < sum; i++)
        {
          // printf("self->lab_thresholds[i].LMin: %d\n", self->lab_thresholds[i].LMin);
          // printf("self->lab_thresholds[i].LMax: %d\n", self->lab_thresholds[i].LMax);
          // printf("self->lab_thresholds[i].AMin: %d\n", self->lab_thresholds[i].AMin);
          // printf("self->lab_thresholds[i].AMax: %d\n", self->lab_thresholds[i].AMax);
          // printf("self->lab_thresholds[i].BMin: %d\n", self->lab_thresholds[i].BMin);
          // printf("self->lab_thresholds[i].BMax: %d\n", self->lab_thresholds[i].BMax);
          list_push_back(&thresholds, &self->lab_thresholds[i]);
          imlib_find_blobs(&out, img, &roi, x_stride, y_stride, &thresholds, invert, area_threshold,
                           pixels_threshold, merge, margin, NULL, NULL, NULL, NULL, x_hist_bins_max, y_hist_bins_max);
          list_clear(&thresholds);
          self->rect_dsc.bg_color = self->lab_colors[i];
          for (size_t m = 0; list_size(&out); m++)
          {
            find_blobs_list_lnk_data_t lnk_data;
            list_pop_front(&out, &lnk_data);
            if (lnk_data.rect.w > 112) continue;

            self->label_dsc.color = self->lab_colors[i];
            lv_canvas_draw_text(zm831_ui_get_canvas(), lnk_data.rect.x, lnk_data.rect.y - 14, 60, &self->label_dsc, string_format("ID:%d", i).c_str(), LV_LABEL_ALIGN_LEFT);
            lv_canvas_draw_rect(zm831_ui_get_canvas(), lnk_data.rect.x, lnk_data.rect.y, ai2vi(lnk_data.rect.w), ai2vi(lnk_data.rect.h), &self->rect_dsc);
            self->data_cmd[i] += 1;
            self->state = 2, self->old = now;
            // printf("[imlib_find_blobs] %d %d %d %d %d\n", i, lnk_data.rect.x, lnk_data.rect.y, lnk_data.rect.x + lnk_data.rect.w, lnk_data.rect.y + lnk_data.rect.h);
          }
        }
        switch (self->state)
        {
        case 1:
        {
          self->data_cmd.fill(0);
          zm831_protocol_send(0x09, (uint8_t *)self->data_cmd.data(), self->data_cmd.size());
          lv_canvas_fill_bg(zm831_ui_get_canvas(), LV_COLOR_BLACK, LV_OPA_TRANSP);
          self->state = 0;
          break;
        }
        case 2:
        {
          zm831_protocol_send(0x09, (uint8_t *)self->data_cmd.data(), self->data_cmd.size());
          self->data_cmd.fill(0);
          if (now - self->old > 100)
          {
            self->state = 1;
          }
          break;
        }
        }
      }

      pthread_mutex_unlock(&zm831->ui_mutex);

      if (self->is_clear_color)
      {
        self->is_clear_color = false;
        self->color_learn_id = -1;
        // {
        //   auto result = self->config_json["color_learn_id"];
        //   if (result.is_integer())
        //   {
        //     self->config_json["color_learn_id"] = (int)self->color_learn_id;
        //   }
        //   zm831_save_json_conf(self->config_file, self->config_json);
        // }
      }

      if (self->is_learn_color)
      {
        self->is_learn_color = false;
        printf("self->color_learn_id %d\r\n", self->color_learn_id);
        self->color_learn_id += 1;
        self->lab_thresholds[self->color_learn_id] = tmp_lab;
        self->lab_colors[self->color_learn_id] = tmp_rgb;

        // {
        //   auto result = self->config_json["color_learn_id"];
        //   if (result.is_integer())
        //   {
        //     self->config_json["color_learn_id"] = (int)self->color_learn_id;
        //   }
        // }
        // {
        //   auto result = self->config_json["lab_thresholds"];
        //   if (result.is_array())
        //   {
        //     auto item = result.as_array()[self->color_learn_id];
        //     if (item.is_array())
        //     {
        //       auto arr = item.as_array();
        //       arr[0] = tmp_lab.LMin;
        //       arr[1] = tmp_lab.LMax;
        //       arr[2] = tmp_lab.AMin;
        //       arr[3] = tmp_lab.AMax;
        //       arr[4] = tmp_lab.BMin;
        //       arr[5] = tmp_lab.BMax;
        //     }
        //   }
        // }
        // {
        //   auto result = self->config_json["lab_colors"];
        //   if (result.is_array())
        //   {
        //     auto item = result.as_array()[self->color_learn_id];
        //     if (item.is_array())
        //     {
        //       auto arr = item.as_array();
        //       arr[0] = tmp_rgb.ch.red;
        //       arr[1] = tmp_rgb.ch.green;
        //       arr[2] = tmp_rgb.ch.blue;
        //       arr[3] = tmp_rgb.ch.alpha;
        //     }
        //   }
        // }
        // zm831_save_json_conf(self->config_file, self->config_json);
      }

      fb_alloc_free_till_mark();
    }
    return 0;
  }
}
