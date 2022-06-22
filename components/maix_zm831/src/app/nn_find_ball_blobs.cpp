#include "zm831_uvai.hpp"

extern "C"
{
  extern zm831_uv *zm831;

  // ==============================================================================================

#include "imlib.h"

  static struct _imlib_find_blobs_
  {
    lv_draw_rect_dsc_t rect_dsc;
    lv_draw_label_dsc_t label_dsc;
    time_t now;
  } find_ball_blobs_app;

  // int find_ball_blobs_app_load(zm831_home_app *app);
  // int find_ball_blobs_app_loop(zm831_home_app *app);
  // int find_ball_blobs_app_exit(zm831_home_app *app);

  // zm831_home_app get_find_ball_blobs_app()
  // {
  //   return {find_ball_blobs_app_load, find_ball_blobs_app_loop, find_ball_blobs_app_exit, &find_ball_blobs_app};
  // }

  libmaix_err_t custom_find_ball_blobs(libmaix_image_t *s_img, list_t *src_thresholds, list_t *out, int x_stride, int y_stride, int area_threshold, int pixels_threshold, int w_min, int h_min, bool invert, bool margin)
  {
    cv::Mat src(s_img->height, s_img->width, CV_8UC3, s_img->data);
    cv::Mat in_img;
    src.copyTo(in_img);
    cv::Mat lab, mask1;
    bool grasy = 0;
    // imlib_list_init(out, sizeof(custom_find_blobs_list_lnk_data_t));
    std::vector<std::vector<int>> thresholds;
    cvtColor(in_img, lab, cv::COLOR_RGB2Lab);

    for (list_lnk_t *it = iterator_start_from_head(src_thresholds); it; it = iterator_next(it))
    {
      color_thresholds_list_lnk_data_t lnk_data;
      iterator_get(src_thresholds, it, &lnk_data);
      std::vector<int> threshold;
      threshold.push_back((int)lnk_data.LMin);
      threshold.push_back((int)lnk_data.AMin);
      threshold.push_back((int)lnk_data.BMin);
      threshold.push_back((int)lnk_data.LMax);
      threshold.push_back((int)lnk_data.AMax);
      threshold.push_back((int)lnk_data.BMax);
      thresholds.push_back(threshold);
    }
    for (size_t i = 0; i < thresholds.size(); i++)
    {
      thresholds[i][0] = int((thresholds[i][0] * 255) / 100);
      thresholds[i][1] = thresholds[i][1] + 128;
      thresholds[i][2] = thresholds[i][2] + 128;
      thresholds[i][3] = int((thresholds[i][3] * 255) / 100);
      thresholds[i][4] = thresholds[i][4] + 128;
      thresholds[i][5] = thresholds[i][5] + 128;
    }

    cv::Mat mask = cv::Mat::zeros(lab.size(), CV_8UC1);
    if (grasy)
    {
      for (size_t i = 0; i < thresholds.size(); i++)
      {
        cv::inRange(lab, cv::Scalar(thresholds[i][0]), cv::Scalar(thresholds[i][1]), mask1);
        mask = mask + mask1;
      }
    }
    else
    {
      for (size_t i = 0; i < thresholds.size(); i++)
      {
        cv::inRange(lab, cv::Scalar(thresholds[i][0], thresholds[i][1], thresholds[i][2]), cv::Scalar(thresholds[i][3], thresholds[i][4], thresholds[i][5]), mask1);
        mask = mask + mask1;
      }
    }
    if (invert)
    {
      cv::bitwise_not(mask, mask);
    }
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
      return LIBMAIX_ERR_NOT_EXEC;
    }
    // list_init(out, sizeof(find_blobs_list_lnk_data_t));

    for (size_t i = 0; i < contours.size(); i++)
    {
      // custom_find_blobs_list_lnk_data_t val;
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
      // val.rect.x = int(rects.x);
      // val.rect.y = int(rects.y);
      // val.rect.w = int(rects.width);
      // val.rect.h = int(rects.height);
      // val.pixels = int(cv::contourArea(contours[i]));
      // val.centroid.x = int(rects.x + rects.width / 2);
      // val.centroid.y = int(rects.y + rects.height / 2);

      if (contours[i].size() < 6)
      {
        // val.ball = 0;
        // list_push_back(out, &val);
        continue;
      }
      cv::RotatedRect rrt = fitEllipse(contours[i]);
      int cr_x, cr_y, cr_w, cr_h;
      cr_x = rrt.center.x;
      cr_y = rrt.center.y;
      cr_w = rrt.size.width;
      cr_h = rrt.size.height;
      if ((abs(cr_w - cr_h) > 10) ||
          (cr_w * cr_h) < 400)
      {
        // val.ball = 0;
        // list_push_back(out, &val);
      }
      else
      {
        int cr_x1, cr_y1, cr_x2, cr_y2;
        cr_x1 = cr_x - cr_w / 2;
        cr_x2 = cr_x + cr_w / 2;
        cr_y1 = cr_y - cr_h / 2;
        cr_y2 = cr_y + cr_h / 2;
        // val.rect_ball.x = cr_x;
        // val.rect_ball.y = cr_y;
        // val.rect_ball.w = cr_w;
        // val.rect_ball.h = cr_h;
        // val.line_ball.x1 = cr_x1;
        // val.line_ball.y1 = cr_y1;
        // val.line_ball.x2 = cr_x2;
        // val.line_ball.y2 = cr_y2;
        // val.ball = 1;
        // list_push_back(out, &val);
      }
    }
    return LIBMAIX_ERR_NONE;
  }
}