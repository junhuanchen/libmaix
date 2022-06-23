#include "zm831_uvai.hpp"

extern "C"
{
  extern zm831_uv *zm831;

  // ==============================================================================================

  #include "imlib.h"

  static struct _imlib_cube_color_
  {
    lv_color_t bgra_lab_color[4] = {
      {0, 0, 255, 255}, // red
      {0, 255, 0, 255}, // green
      {255, 0, 0, 255}, // blue
      {0, 255, 255, 255} // yellow
    };
    rectangle_t cube_roi[10] = {
        {.x = 46 , .y = 46 , .w = 148, .h = 148},
        {.x = 64 , .y = 64 , .w = 13 , .h = 13 },
        {.x = 113, .y = 64 , .w = 13 , .h = 13 },
        {.x = 163, .y = 64 , .w = 13 , .h = 13 },
        {.x = 64 , .y = 113, .w = 13 , .h = 13 },
        {.x = 113, .y = 113, .w = 13 , .h = 13 },
        {.x = 163, .y = 113, .w = 13 , .h = 13 },
        {.x = 64 , .y = 163, .w = 13 , .h = 13 },
        {.x = 113, .y = 163, .w = 13 , .h = 13 },
        {.x = 163, .y = 163, .w = 13 , .h = 13 },
    };
    rectangle_t cube_roi_ui[9] = {
        {.x = 0  , .y = 0  , .w = 15 , .h = 15 },
        {.x = 15 , .y = 0  , .w = 15 , .h = 15 },
        {.x = 30 , .y = 0  , .w = 15 , .h = 15 },
        {.x = 0  , .y = 15 , .w = 15 , .h = 15 },
        {.x = 15 , .y = 15 , .w = 15 , .h = 15 },
        {.x = 30 , .y = 15 , .w = 15 , .h = 15 },
        {.x = 0  , .y = 30 , .w = 15 , .h = 15 },
        {.x = 15 , .y = 30 , .w = 15 , .h = 15 },
        {.x = 30 , .y = 30 , .w = 15 , .h = 15 },
    };
    lv_draw_rect_dsc_t rect_dsc;
    lv_draw_label_dsc_t label_dsc;
    time_t now;
  } imlib_cube_color_app;

  int imlib_cube_color_app_load(zm831_home_app *app);
  int imlib_cube_color_app_loop(zm831_home_app *app);
  int imlib_cube_color_app_exit(zm831_home_app *app);

  zm831_home_app get_imlib_cube_color_app()
  {
    return {imlib_cube_color_app_load, imlib_cube_color_app_loop, imlib_cube_color_app_exit, &imlib_cube_color_app};
  }

  int imlib_cube_color_app_load(zm831_home_app *app)
  {
    auto self = (_imlib_cube_color_ *)app->userdata;
    lv_draw_rect_dsc_init(&self->rect_dsc);
    self->rect_dsc.radius = 5;
    self->rect_dsc.bg_opa = LV_OPA_50;
    self->rect_dsc.border_width = 2;
    self->rect_dsc.border_opa = LV_OPA_50;
    self->rect_dsc.border_color = {0x00, 0x00, 0xFF, 0x9f};

    lv_draw_label_dsc_init(&self->label_dsc);
    self->label_dsc.color = LV_COLOR_YELLOW;

    fb_realloc_init1(1 * 1024 * 1024);

    return 0;
  }

  int imlib_cube_color_app_loop(zm831_home_app *app)
  {
    auto self = (_imlib_cube_color_ *)app->userdata;
    libmaix_image_t *ai_rgb = NULL;
    if (LIBMAIX_ERR_NONE == zm831->ai->capture_image(zm831->ai, &ai_rgb))
    {
      CALC_FPS("imlib_cube_color_app_loop");

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

      //定义直方图通道
      histogram_t hist;
      hist.LBinCount = COLOR_L_MAX-COLOR_L_MIN + 1;
      hist.ABinCount = COLOR_A_MAX-COLOR_A_MIN + 1;
      hist.BBinCount = COLOR_B_MAX-COLOR_B_MIN + 1;
      //分配直方图通道内存
      hist.LBins = (float *)fb_alloc(hist.LBinCount * sizeof(float), FB_ALLOC_NO_HINT);
      hist.ABins = (float *)fb_alloc(hist.ABinCount * sizeof(float), FB_ALLOC_NO_HINT);
      hist.BBins = (float *)fb_alloc(hist.BBinCount * sizeof(float), FB_ALLOC_NO_HINT);
      simple_color_t tmp_lab[9];
      for( int i = 0; i < 10; ++ i){
          //获取直方图
          imlib_get_histogram(&hist, img, &self->cube_roi_ui[i], NULL, false, NULL);
          //进行直方图统计
          statistics_t stats;
          imlib_get_statistics(&stats, (pixformat_t)img->pixfmt, &hist);
          //get color
          int piexs = COLOR_LAB_TO_RGB888(stats.LMode, stats.AMode, stats.BMode);
          int r = COLOR_RGB888_TO_R8(piexs);
          int g = COLOR_RGB888_TO_G8(piexs);
          int b = COLOR_RGB888_TO_B8(piexs);
          printf("i:%d, L:%d, A:%d, B:%d, R:%d, G:%d, B:%d\n", i, stats.LMode, stats.AMode, stats.BMode, r, g, b);
      }
      //释放直方图通道内存
      fb_free(hist.BBins);
      fb_free(hist.ABins);
      fb_free(hist.LBins);
      fb_alloc_free_till_mark();
    }
    return 0;
  }

  int imlib_cube_color_app_exit(zm831_home_app *app)
  {
    fb_alloc_close0();
    return 0;
  }

}