
#include "zm831_uvai.hpp"

extern "C"
{
  extern zm831_uv *zm831;

  // ==============================================================================================

  void setup_scr_tagcode_app(lv_ui *ui)
  {

    // Write codes tagcode_app
    ui->tagcode_app = lv_scr_act();

    // Write style LV_OBJ_PART_MAIN for tagcode_app
    static lv_style_t style_tagcode_app_main;
    lv_style_reset(&style_tagcode_app_main);

    // Write style state: LV_STATE_DEFAULT for style_tagcode_app_main
    lv_style_set_bg_color(&style_tagcode_app_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
    lv_style_set_bg_opa(&style_tagcode_app_main, LV_STATE_DEFAULT, 139);
    lv_obj_add_style(ui->tagcode_app, LV_OBJ_PART_MAIN, &style_tagcode_app_main);

    // Write codes tagcode_app_label_top_title
    ui->tagcode_app_label_top_title = lv_label_create(ui->tagcode_app, NULL);
    lv_label_set_text(ui->tagcode_app_label_top_title, "标签码识别");
    lv_label_set_long_mode(ui->tagcode_app_label_top_title, LV_LABEL_LONG_BREAK);
    lv_label_set_align(ui->tagcode_app_label_top_title, LV_LABEL_ALIGN_CENTER);

    // Write style LV_LABEL_PART_MAIN for tagcode_app_label_top_title
    static lv_style_t style_tagcode_app_label_top_title_main;
    lv_style_reset(&style_tagcode_app_label_top_title_main);

    // Write style state: LV_STATE_DEFAULT for style_tagcode_app_label_top_title_main
    lv_style_set_radius(&style_tagcode_app_label_top_title_main, LV_STATE_DEFAULT, 0);
    lv_style_set_bg_color(&style_tagcode_app_label_top_title_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
    lv_style_set_bg_grad_color(&style_tagcode_app_label_top_title_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
    lv_style_set_bg_grad_dir(&style_tagcode_app_label_top_title_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
    lv_style_set_bg_opa(&style_tagcode_app_label_top_title_main, LV_STATE_DEFAULT, 100);
    lv_style_set_text_color(&style_tagcode_app_label_top_title_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
    lv_style_set_text_font(&style_tagcode_app_label_top_title_main, LV_STATE_DEFAULT, &lv_font_simsun_18);
    lv_style_set_text_letter_space(&style_tagcode_app_label_top_title_main, LV_STATE_DEFAULT, 2);
    lv_style_set_pad_left(&style_tagcode_app_label_top_title_main, LV_STATE_DEFAULT, 0);
    lv_style_set_pad_right(&style_tagcode_app_label_top_title_main, LV_STATE_DEFAULT, 0);
    lv_style_set_pad_top(&style_tagcode_app_label_top_title_main, LV_STATE_DEFAULT, 8);
    lv_style_set_pad_bottom(&style_tagcode_app_label_top_title_main, LV_STATE_DEFAULT, 8);
    lv_obj_add_style(ui->tagcode_app_label_top_title, LV_LABEL_PART_MAIN, &style_tagcode_app_label_top_title_main);
    lv_obj_set_pos(ui->tagcode_app_label_top_title, 0, 0);
    lv_obj_set_size(ui->tagcode_app_label_top_title, 240, 0);

    // Write codes tagcode_app_imgbtn_back
    ui->tagcode_app_imgbtn_back = lv_imgbtn_create(ui->tagcode_app, NULL);

    // Write style LV_IMGBTN_PART_MAIN for tagcode_app_imgbtn_back
    static lv_style_t style_tagcode_app_imgbtn_back_main;
    lv_style_reset(&style_tagcode_app_imgbtn_back_main);

    // Write style state: LV_STATE_DEFAULT for style_tagcode_app_imgbtn_back_main
    lv_style_set_text_color(&style_tagcode_app_imgbtn_back_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
    lv_style_set_image_recolor(&style_tagcode_app_imgbtn_back_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
    lv_style_set_image_recolor_opa(&style_tagcode_app_imgbtn_back_main, LV_STATE_DEFAULT, 0);
    lv_style_set_image_opa(&style_tagcode_app_imgbtn_back_main, LV_STATE_DEFAULT, 255);

    // Write style state: LV_STATE_PRESSED for style_tagcode_app_imgbtn_back_main
    lv_style_set_text_color(&style_tagcode_app_imgbtn_back_main, LV_STATE_PRESSED, lv_color_make(0xFF, 0x33, 0xFF));
    lv_style_set_image_recolor(&style_tagcode_app_imgbtn_back_main, LV_STATE_PRESSED, lv_color_make(0x00, 0x00, 0x00));
    lv_style_set_image_recolor_opa(&style_tagcode_app_imgbtn_back_main, LV_STATE_PRESSED, 0);

    // Write style state: LV_STATE_CHECKED for style_tagcode_app_imgbtn_back_main
    lv_style_set_text_color(&style_tagcode_app_imgbtn_back_main, LV_STATE_CHECKED, lv_color_make(0xFF, 0x33, 0xFF));
    lv_style_set_image_recolor(&style_tagcode_app_imgbtn_back_main, LV_STATE_CHECKED, lv_color_make(0x00, 0x00, 0x00));
    lv_style_set_image_recolor_opa(&style_tagcode_app_imgbtn_back_main, LV_STATE_CHECKED, 0);
    lv_obj_add_style(ui->tagcode_app_imgbtn_back, LV_IMGBTN_PART_MAIN, &style_tagcode_app_imgbtn_back_main);
    lv_obj_set_pos(ui->tagcode_app_imgbtn_back, 20, 180);
    lv_obj_set_size(ui->tagcode_app_imgbtn_back, 50, 50);
    lv_imgbtn_set_src(ui->tagcode_app_imgbtn_back, LV_BTN_STATE_RELEASED, &_back_alpha_50x50);
    lv_imgbtn_set_checkable(ui->tagcode_app_imgbtn_back, true);
  }

#include "apriltag.h"
#include "tag36h11.h"
#include "tag25h9.h"
#include "tag16h5.h"
#include "tagCircle21h7.h"
#include "tagCircle49h12.h"
#include "tagCustom48h12.h"
#include "tagStandard41h12.h"
#include "tagStandard52h13.h"

  static struct _function_0x08_
  {
    lv_ui *ui = &zm831->ui;

    lv_draw_line_dsc_t line_dsc;
    lv_draw_label_dsc_t label_dsc;
    const char *famname = "tag36h11";
    apriltag_detector_t *td = NULL;
    apriltag_family_t *tf = NULL;
    time_t now;

    bool init = false;
  } function_0x08_app;

  int function_0x08_app_load(zm831_home_app *app);
  int function_0x08_app_loop(zm831_home_app *app);
  int function_0x08_app_exit(zm831_home_app *app);

  zm831_home_app get_function_0x08_app()
  {
    return {function_0x08_app_load, function_0x08_app_loop, function_0x08_app_exit, &function_0x08_app};
  }

  // ==============================================================================================

  static void function_0x08_btn_event_app_cb(lv_obj_t *btn, lv_event_t event)
  {
    // printf("btn %p event %d\n", btn, event);
    if (function_0x08_app.ui->tagcode_app_imgbtn_back == btn && event == LV_EVENT_SHORT_CLICKED)
    {
      zm831_home_app_select(0);
      return;
    }
  }

  int function_0x08_app_load(zm831_home_app *app)
  {
    auto self = (_function_0x08_ *)app->userdata;

    lv_draw_line_dsc_init(&self->line_dsc);
    self->line_dsc.color = {0xFF, 0x00, 0x00, 0x9f};
    self->line_dsc.width = 3;
    self->line_dsc.opa = LV_OPA_90;

    lv_draw_label_dsc_init(&self->label_dsc);
    self->label_dsc.color = LV_COLOR_BLACK;

    // Initialize tag detector with options
    if (!strcmp(self->famname, "tag36h11"))
    {
      self->tf = tag36h11_create();
    }
    else if (!strcmp(self->famname, "tag25h9"))
    {
      self->tf = tag25h9_create();
    }
    else if (!strcmp(self->famname, "tag16h5"))
    {
      self->tf = tag16h5_create();
    }
    else if (!strcmp(self->famname, "tagCircle21h7"))
    {
      self->tf = tagCircle21h7_create();
    }
    else if (!strcmp(self->famname, "tagCircle49h12"))
    {
      self->tf = tagCircle49h12_create();
    }
    else if (!strcmp(self->famname, "tagStandard41h12"))
    {
      self->tf = tagStandard41h12_create();
    }
    else if (!strcmp(self->famname, "tagStandard52h13"))
    {
      self->tf = tagStandard52h13_create();
    }
    else if (!strcmp(self->famname, "tagCustom48h12"))
    {
      self->tf = tagCustom48h12_create();
    }
    else
    {
      printf("Unrecognized tag family name. Use e.g. \"tag36h11\".\n");
      exit(-1);
    }
    if (self->tf == NULL)
    {
      return -1;
    }

    self->td = apriltag_detector_create();
    apriltag_detector_add_family_bits(self->td, self->tf, 1);
    // apriltag_detector_add_family(td, tf);
    self->td->quad_decimate = 2.0; // "Decimate input image by this factor"
    self->td->quad_sigma = 0.0;    // Apply low-pass blur to input
    self->td->nthreads = 1;
    self->td->debug = 0;
    self->td->refine_edges = 1; // Spend more time trying to align edges of tags

    if (self->td == NULL)
    {
      return -1;
    }

    if (!self->init)
    {
      zm831_home_setup_ui(&self->ui->tagcode_app, setup_scr_tagcode_app, 500);

      pthread_mutex_lock(&zm831->ui_mutex);
      lv_obj_set_event_cb(self->ui->tagcode_app_imgbtn_back, function_0x08_btn_event_app_cb);
      pthread_mutex_unlock(&zm831->ui_mutex);

      self->init = true;
    }
    LIBMAIX_INFO_PRINTF("function_0x08_app_load");
    return 0;
  }

  int function_0x08_app_exit(zm831_home_app *app)
  {
    auto self = (_function_0x08_ *)app->userdata;

    if (self->td)
    {
      apriltag_detector_destroy(self->td), self->td = NULL;
    }

    if (self->tf)
    {
      if (!strcmp(self->famname, "tag36h11"))
      {
        tag36h11_destroy(self->tf);
      }
      else if (!strcmp(self->famname, "tag25h9"))
      {
        tag25h9_destroy(self->tf);
      }
      else if (!strcmp(self->famname, "tag16h5"))
      {
        tag16h5_destroy(self->tf);
      }
      else if (!strcmp(self->famname, "tagCircle21h7"))
      {
        tagCircle21h7_destroy(self->tf);
      }
      else if (!strcmp(self->famname, "tagCircle49h12"))
      {
        tagCircle49h12_destroy(self->tf);
      }
      else if (!strcmp(self->famname, "tagStandard41h12"))
      {
        tagStandard41h12_destroy(self->tf);
      }
      else if (!strcmp(self->famname, "tagStandard52h13"))
      {
        tagStandard52h13_destroy(self->tf);
      }
      else if (!strcmp(self->famname, "tagCustom48h12"))
      {
        tagCustom48h12_destroy(self->tf);
      }
      self->tf = NULL;
    }

    if (self->init)
    {
      zm831_home_clear_ui(&self->ui->tagcode_app);
      self->init = false;
    }
    LIBMAIX_INFO_PRINTF("function_0x08_app_exit");
    return 0;
  }

  int function_0x08_app_loop(zm831_home_app *app)
  {
    auto self = (_function_0x08_ *)app->userdata;
    if (self->td && self->tf)
    {
      libmaix_image_t *ai_rgb = NULL;
      if (zm831->ai && LIBMAIX_ERR_NONE == zm831->ai->capture_image(zm831->ai, &ai_rgb))
      {
        // printf("ai_rgb: %p, %d, %d\r\n", ai_rgb, ai_rgb->width, ai_rgb->height);
        cv::Mat gray, rgb(ai_rgb->height, ai_rgb->width, CV_8UC3, ai_rgb->data);
        cv::cvtColor(rgb, gray, cv::COLOR_RGB2GRAY);

        // if (self->now < time(NULL))
        // {
        //   pthread_mutex_lock(&zm831->ui_mutex);
        //   lv_canvas_fill_bg(zm831_ui_get_canvas(), LV_COLOR_BLACK, LV_OPA_TRANSP);
        //   pthread_mutex_unlock(&zm831->ui_mutex);
        // }

        libmaix_err_t err = LIBMAIX_ERR_NONE;

        // Make an image_u8_t header for the Mat data
        image_u8_t im = {
            .width = gray.cols,
            .height = gray.rows,
            .stride = gray.cols,
            .buf = (uint8_t *)(gray.data)};

        zarray_t *detections = apriltag_detector_detect(self->td, &im);

        pthread_mutex_lock(&zm831->ui_mutex);
        lv_canvas_fill_bg(zm831_ui_get_canvas(), LV_COLOR_BLACK, LV_OPA_TRANSP);
        // Draw detection outlines
        for (int i = 0; i < zarray_size(detections); i++)
        {

          apriltag_detection_t *det;
          zarray_get(detections, i, &det);

          std::ostringstream prob2str;
          prob2str << det->id;

          const lv_point_t points[] = {
              {ai2vi(det->p[0][0]), ai2vi(det->p[0][1])},
              {ai2vi(det->p[1][0]), ai2vi(det->p[1][1])},
              {ai2vi(det->p[2][0]), ai2vi(det->p[2][1])},
              {ai2vi(det->p[3][0]), ai2vi(det->p[3][1])},
              {ai2vi(det->p[0][0]), ai2vi(det->p[0][1])},
          };

          lv_canvas_draw_line(zm831_ui_get_canvas(), points, sizeof(points) / sizeof(points[0]), &self->line_dsc);

          lv_canvas_draw_text(zm831_ui_get_canvas(), det->c[0], det->c[1], 100, &self->label_dsc, prob2str.str().c_str(), LV_LABEL_ALIGN_LEFT);
          self->now = time(NULL);
        }
        pthread_mutex_unlock(&zm831->ui_mutex);

        apriltag_detections_destroy(detections);
      }
    }
    return 0;
  }
}
