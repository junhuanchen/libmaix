#include "zm831_uvai.hpp"

extern "C"
{
  extern zm831_uv *zm831;

  // ==============================================================================================

  #include "imlib.h"

  static struct _imlib_find_blobs_
  {
    color_thresholds_list_lnk_data_t lab_thresholds[4] = {
        {.LMin = 5 , .LMax = 50, .AMin = 30, .AMax = 85, .BMin = -29, .BMax = 72},       //红
        {.LMin = 20 , .LMax = 74, .AMin =-60, .AMax = -8, .BMin = -18, .BMax = 62},       //绿
        {.LMin = 5 , .LMax = 82, .AMin = 3 , .AMax = 57, .BMin =-81, .BMax =-30},       //蓝
        {.LMin = 50, .LMax =100, .AMin = -2, .AMax = 40, .BMin = 40, .BMax = 90},       //黄
    };
    lv_draw_rect_dsc_t rect_dsc;
    lv_draw_label_dsc_t label_dsc;
    time_t now;
  } imlib_find_blobs_app;

  int imlib_find_blobs_app_load(zm831_home_app *app);
  int imlib_find_blobs_app_loop(zm831_home_app *app);
  int imlib_find_blobs_app_exit(zm831_home_app *app);

  zm831_home_app get_imlib_find_blobs_app()
  {
    return {imlib_find_blobs_app_load, imlib_find_blobs_app_loop, imlib_find_blobs_app_exit, &imlib_find_blobs_app};
  }

  int imlib_find_blobs_app_load(zm831_home_app *app)
  {
    auto self = (_imlib_find_blobs_ *)app->userdata;
    lv_draw_rect_dsc_init(&self->rect_dsc);
    self->rect_dsc.radius = 5;
    self->rect_dsc.bg_opa = LV_OPA_TRANSP;
    self->rect_dsc.border_width = 5;
    self->rect_dsc.border_opa = LV_OPA_80;
    self->rect_dsc.border_color = {0x00, 0x00, 0xFF, 0x9f};

    lv_draw_label_dsc_init(&self->label_dsc);
    self->label_dsc.color = LV_COLOR_YELLOW;

    fb_realloc_init1(1 * 1024 * 1024);

    return 0;
  }

  int imlib_find_blobs_app_loop(zm831_home_app *app)
  {
    auto self = (_imlib_find_blobs_ *)app->userdata;
    libmaix_image_t *ai_rgb = NULL;
    if (LIBMAIX_ERR_NONE == zm831->ai->capture_image(zm831->ai, &ai_rgb))
    {
      CALC_FPS("imlib_find_blobs_app_loop");

      image_t imlib_img, *img = &imlib_img;
      {
        img->w = ai_rgb->width;
        img->h = ai_rgb->height;
        img->data = (uint8_t *)ai_rgb->data;
        img->size = ai_rgb->width * ai_rgb->height * 3;
        img->is_data_alloc = NULL;
        img->pixfmt = PIXFORMAT_RGB888;
      }

      rectangle_t roi = {.x = 0, .y = 0, .w = img->w, .h = img->h};

      {
        fb_alloc_mark();
        histogram_t hist;
        hist.LBinCount = COLOR_L_MAX - COLOR_L_MIN + 1;
        hist.ABinCount = COLOR_A_MAX - COLOR_A_MIN + 1;
        hist.BBinCount = COLOR_B_MAX - COLOR_B_MIN + 1;
        hist.LBins = (float *)fb_alloc(hist.LBinCount * sizeof(float), FB_ALLOC_NO_HINT);
        hist.ABins = (float *)fb_alloc(hist.ABinCount * sizeof(float), FB_ALLOC_NO_HINT);
        hist.BBins = (float *)fb_alloc(hist.BBinCount * sizeof(float), FB_ALLOC_NO_HINT);
        imlib_get_histogram(&hist, img, &roi, NULL, false, NULL);
        statistics_t stats;
        imlib_get_statistics(&stats, (pixformat_t)img->pixfmt, &hist);
        fb_free(hist.BBins);
        fb_free(hist.ABins);
        fb_free(hist.LBins);
        fb_alloc_free_till_mark();
        printf("[imlib_get_statistics] LMin: %d, LMax: %d, AMin: %d, AMax: %d, BMin: %d, BMax: %d\n", stats.LMin, stats.LMax, stats.AMin, stats.AMax, stats.BMin, stats.BMax);
      }

      {
        unsigned int x_stride = 2;
        unsigned int y_stride = 2;
        uint32_t threshold = 50;
        unsigned int x_margin = 10;
        unsigned int y_margin = 10;
        unsigned int r_margin = 10;
        unsigned int r_min = 15;
        unsigned int r_max = 25;
        unsigned int r_step = 2;
        list_t out;
        fb_alloc_mark();
        imlib_find_circles(&out, img, &roi, x_stride, y_stride, threshold, x_margin, y_margin, r_margin, r_min, r_max, r_step);
        fb_alloc_free_till_mark();
        for (size_t i = 0; list_size(&out); i++)
        {
          find_circles_list_lnk_data_t lnk_data;
          list_pop_front(&out, &lnk_data);
          printf("[imlib_find_circles]  %d: %d, %d, %d\n", i, lnk_data.p.x, lnk_data.p.y, lnk_data.r);
        }
      }

      {
        list_t thresholds;
        imlib_list_init(&thresholds, sizeof(color_thresholds_list_lnk_data_t));
        bool invert = false;
        rectangle_t roi = {
            .x = 0,
            .y = 0,
            .w = img->w,
            .h = img->h,
        };
        unsigned int x_stride = 10;
        unsigned int y_stride = 10;
        unsigned int area_threshold = 100;
        unsigned int pixels_threshold = 100;
        bool merge = false;
        int margin = 0;
        unsigned int x_hist_bins_max = 0;
        unsigned int y_hist_bins_max = 0;
        list_t out;
        fb_alloc_mark();
        for(int i = 0; i < 4; i ++){
            list_push_back(&thresholds, &self->lab_thresholds[i]);
            imlib_find_blobs(&out, img, &roi, x_stride, y_stride, &thresholds, invert,area_threshold,
                        pixels_threshold, merge, margin, NULL, NULL, NULL, NULL, x_hist_bins_max, y_hist_bins_max);
            list_clear(&thresholds);
            for (size_t m = 0; list_size(&out); m++) {
                find_blobs_list_lnk_data_t lnk_data;
                list_pop_front(&out, &lnk_data);
                lnk_data.rect.x, lnk_data.rect.y, lnk_data.rect.x + lnk_data.rect.w, lnk_data.rect.y + lnk_data.rect.h;
                printf("[imlib_find_blobs] %d %d %d %d\n", lnk_data.rect.x, lnk_data.rect.y, lnk_data.rect.x + lnk_data.rect.w, lnk_data.rect.y + lnk_data.rect.h);
            }
        }
        fb_alloc_free_till_mark();
      }
    }
    return 0;
  }

  int imlib_find_blobs_app_exit(zm831_home_app *app)
  {
    fb_alloc_close0();
    return 0;
  }

}