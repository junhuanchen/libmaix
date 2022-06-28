
#include "zm831_uvai.hpp"

extern "C"
{
  extern zm831_uv *zm831;

  // ==============================================================================================

#include "ms_asr.h"

  static struct _speech_asr_
  {
    lv_draw_label_dsc_t label_dsc, label_dsc_en;
    lv_draw_rect_dsc_t rect_dsc;

    const int device_type = DEVICE_MIC;
    const char *device_name = "hw:0,0";
    const am_args_t am_args = {
        "/home/res/test_files/cnnctc/cnnctc_3332_192",
        192,
        6,
        6,
        CN_PNYTONE,
        1};

    bool init = false;

  } speech_asr_app;

  int speech_asr_app_load(zm831_home_app *app);
  int speech_asr_app_loop(zm831_home_app *app);
  int speech_asr_app_exit(zm831_home_app *app);

  zm831_home_app get_speech_asr_app()
  {
    return {speech_asr_app_load, speech_asr_app_loop, speech_asr_app_exit, &speech_asr_app};
  }

  // ==============================================================================================

  void speech_asr_app_digitcb(void *data, int len)
  {
    char *digit_res = (char *)data;
    char digit_res1[32];
    memset(digit_res1, ' ', 32);
    digit_res1[32 - 1] = 0;
    memcpy(digit_res1, digit_res, strlen(digit_res));
    printf("digit_res1: %s\n", digit_res);
    return;
  }

  void speech_asr_app_lvcsrcb(void *data, int len)
  {
    char *words = ((char **)data)[0];
    char *pnys = ((char **)data)[1];
    int strlennum = strlen(words);
    printf("PNYS: %s\nHANS: %s, num:%zu\n", pnys, words, strlen(words));
    std::string tmp_words(words), tmp_pnys(pnys);
    if (tmp_pnys.length() > 64)
    {
      ms_asr_clear();
    }
    pthread_mutex_lock(&zm831->ui_mutex);
    lv_canvas_fill_bg(zm831->canvas, LV_COLOR_BLACK, LV_OPA_TRANSP);
    lv_canvas_draw_rect(zm831->canvas, 8, 8, 224, 224, &speech_asr_app.rect_dsc);
    lv_canvas_draw_text(zm831->canvas, 12, 12, 220, &speech_asr_app.label_dsc_en, tmp_pnys.c_str(), LV_LABEL_ALIGN_LEFT);
    // lv_canvas_draw_text(zm831->canvas, 0, 120, 240, &speech_asr_app.label_dsc, tmp_words.c_str(), LV_LABEL_ALIGN_LEFT);
    pthread_mutex_unlock(&zm831->ui_mutex);
    return;
  }

  // int font_draw(uint8_t* fb, int lcd_w, int lcd_h, int char_size, int x_oft, int y_oft, int c_color, int bg_color, char* str);
  /*int fb_display(unsigned char *rgbbuff, unsigned char * alpha,
                unsigned int x_size, unsigned int y_size,
                unsigned int x_pan, unsigned int y_pan,
                unsigned int x_offs, unsigned int y_offs) */
  char *speech_asr_app_kw_tbl[3] = {
      (char *)"xiao3 ai4 tong2 xue2",
      (char *)"tian1 mao1 jing1 ling2",
      (char *)"tian1 qi4 zen3 me yang4"};
  char *speech_asr_app_kw_str[3] = {
      (char *)"XIAO AI TONG XU",
      (char *)"TIAN MAO JING L",
      (char *)"TIAN QI ZEN ME"};
  float speech_asr_app_kw_gate[3] = {0.1, 0.1, 0.1};
  void speech_asr_app_kwscb(void *data, int len)
  {
    float *p = (float *)data;
    float maxp = -1;
    for (int i = 0; i < len; i++)
    {
      printf("\tkw%d: %.3f;", i, p[i]);
      if (p[i] > maxp)
      {
        maxp = p[i];
      }
    }
    printf("\n");
    return;
  }

  void speech_asr_app_set_dig(int flag)
  {
    size_t decoder_args[10];
    int res = 0;
    if (flag)
    {                        // init
      decoder_args[0] = 640; // blank_t ms
      res = ms_asr_decoder_cfg(DECODER_DIG, speech_asr_app_digitcb, &decoder_args, 1);
      if (res != 0)
      {
        printf("DECODER_DIG init error!\n");
      };
    }
    else
    {
      ms_asr_decoder_cfg(DECODER_DIG, NULL, NULL, 0);
    }
    return;
  }

  void speech_asr_app_set_kws(int flag)
  {
    size_t decoder_args[10];
    int res = 0;
    if (flag)
    { // init
      decoder_args[0] = (size_t)speech_asr_app_kw_tbl;
      decoder_args[1] = (size_t)speech_asr_app_kw_gate;
      decoder_args[2] = 3;
      decoder_args[3] = 1; // auto similar //自动去除音调 近音处理
      res = ms_asr_decoder_cfg(DECODER_KWS, speech_asr_app_kwscb, &decoder_args, 3);
      if (res != 0)
      {
        printf("DECODER_KWS init error!\n");
        return;
      };
      char *similar_pnys0[1] = {(char *)"xiang3"}; //每个最多注册10个近音词
      ms_asr_kws_reg_similar((char *)"xiao3", similar_pnys0, 1);
      char *similar_pnys1[3] = {(char *)"xin1", (char *)"ting1", (char *)"jin1"};
      ms_asr_kws_reg_similar((char *)"jing1", similar_pnys1, 3);
    }
    else
    {
      ms_asr_decoder_cfg(DECODER_KWS, NULL, NULL, 0);
    }
  }

  void speech_asr_app_set_lvcsr(int flag)
  {
    size_t decoder_args[10];
    int res = 0;
    if (flag)
    { // init
      decoder_args[0] = (size_t) "/home/res/test_files/lmS/lg_6m.sfst";
      decoder_args[1] = (size_t) "/home/res/test_files/lmS/lg_6m.sym";
      decoder_args[2] = (size_t) "/home/res/test_files/lmS/phones.bin";
      decoder_args[3] = (size_t) "/home/res/test_files/lmS/words_utf.bin";
      float beam = 0.8;
      memcpy(&decoder_args[4], &(beam), sizeof(float));
      float bg_prob = 10.0;
      memcpy(&decoder_args[5], &(bg_prob), sizeof(float));
      float scale = 0.5;
      memcpy(&decoder_args[6], &(scale), sizeof(float));
      float is_mmap = 0;
      decoder_args[7] = (size_t)is_mmap; // printf("#\n");
      res = ms_asr_decoder_cfg(DECODER_LVCSR, speech_asr_app_lvcsrcb, &decoder_args, 8);
      if (res != 0)
      {
        printf("DECODER_LVCSR init error!\n");
      };
    }
    else
    {
      ms_asr_decoder_cfg(DECODER_LVCSR, NULL, NULL, 0);
    }
    return;
  }

  int speech_asr_app_load(zm831_home_app *app)
  {
    auto self = (_speech_asr_ *)app->userdata;

    lv_draw_label_dsc_init(&self->label_dsc);
    self->label_dsc.color = LV_COLOR_GREEN;
    self->label_dsc.font = zm831->ft_font.font;

    lv_draw_label_dsc_init(&self->label_dsc_en);
    self->label_dsc_en.color = LV_COLOR_WHITE;

    lv_draw_rect_dsc_init(&self->rect_dsc);
    self->rect_dsc.radius = 5;
    self->rect_dsc.bg_color = {0x00, 0x00, 0x00, 0xDF};;
    self->rect_dsc.bg_opa = LV_OPA_80;
    self->rect_dsc.border_width = 5;
    self->rect_dsc.border_opa = LV_OPA_80;
    self->rect_dsc.border_color = {0x00, 0x00, 0x00, 0x7f};

    if (!self->init)
    {
      int res = ms_asr_init(self->device_type, (char *)self->device_name, (am_args_t *)&self->am_args, 0x00);
      // printf("ms_asr_init res: %d\n", res);
      if (res == 0)
      {
        // speech_asr_app_set_dig(1);
        speech_asr_app_set_kws(1);
        speech_asr_app_set_lvcsr(1);
        // extern void zm831_vi_stop();
        // zm831_vi_stop();
        self->init = true;
      }
    }
    LIBMAIX_INFO_PRINTF("speech_asr_app_load");
    return 0;
  }

  int speech_asr_app_loop(zm831_home_app *app)
  {
    auto self = (_speech_asr_ *)app->userdata;
    libmaix_err_t err = LIBMAIX_ERR_NONE;
    libmaix_image_t *ai_rgb = NULL;
    if (zm831->ai && LIBMAIX_ERR_NONE == zm831->ai->capture_image(zm831->ai, &ai_rgb))
    {
      CALC_FPS("speech_asr_app_loop");
    }
    // set 1 frame default 768ms(am_xxyy_192)
    if (self->init && ms_asr_run(1) < 1)
    {
      printf("ms_asr_run error\n");
      return -1;
    }
    return 0;
  }

  int speech_asr_app_exit(zm831_home_app *app)
  {
    auto self = (_speech_asr_ *)app->userdata;
    if (self->init)
    {
      extern void zm831_vi_stop();
      zm831_vi_stop();
      zm831->exit = 1; // need restart app
      void zm831_home_app_stop();
      zm831_home_app_stop();
      ms_asr_deinit();
      self->init = false;
      // extern void zm831_vi_open();
      // zm831_vi_open();
    }
    LIBMAIX_INFO_PRINTF("speech_asr_app_exit");
    return 0;
  }
}
