
#include "zm831_uvai.hpp"

extern "C"
{
  extern zm831_uv *zm831;

// ==============================================================================================

  #include "apriltag.h"
  #include "tag36h11.h"
  #include "tag25h9.h"
  #include "tag16h5.h"
  #include "tagCircle21h7.h"
  #include "tagCircle49h12.h"
  #include "tagCustom48h12.h"
  #include "tagStandard41h12.h"
  #include "tagStandard52h13.h"

  static struct _find_apriltag_
  {
    lv_draw_line_dsc_t line_dsc;
    lv_draw_label_dsc_t label_dsc;
    const char *famname = "tag36h11";
    apriltag_detector_t *td = NULL;
    apriltag_family_t *tf = NULL;
    time_t now;
  } find_apriltag_app;

  int find_apriltag_app_load(zm831_home_app *app);
  int find_apriltag_app_loop(zm831_home_app *app);
  int find_apriltag_app_exit(zm831_home_app *app);

  zm831_home_app get_find_apriltag_app()
  {
    return {find_apriltag_app_load, find_apriltag_app_loop, find_apriltag_app_exit, &find_apriltag_app};
  }

// ==============================================================================================

  int find_apriltag_app_load(zm831_home_app *app)
  {
    auto self = (_find_apriltag_ *)app->userdata;
    lv_draw_line_dsc_init(&self->line_dsc);
    self->line_dsc.color = {0xFF, 0x00, 0x00, 0x9f};
    self->line_dsc.width = 3;
    self->line_dsc.opa = LV_OPA_90;

    lv_draw_label_dsc_init(&self->label_dsc);
    self->label_dsc.color = LV_COLOR_BLACK;

    {
      // Initialize tag detector with options
      if (!strcmp(self->famname, "tag36h11")) {
          self->tf = tag36h11_create();
      } else if (!strcmp(self->famname, "tag25h9")) {
          self->tf = tag25h9_create();
      } else if (!strcmp(self->famname, "tag16h5")) {
          self->tf = tag16h5_create();
      } else if (!strcmp(self->famname, "tagCircle21h7")) {
          self->tf = tagCircle21h7_create();
      } else if (!strcmp(self->famname, "tagCircle49h12")) {
          self->tf = tagCircle49h12_create();
      } else if (!strcmp(self->famname, "tagStandard41h12")) {
          self->tf = tagStandard41h12_create();
      } else if (!strcmp(self->famname, "tagStandard52h13")) {
          self->tf = tagStandard52h13_create();
      } else if (!strcmp(self->famname, "tagCustom48h12")) {
          self->tf = tagCustom48h12_create();
      } else {
          printf("Unrecognized tag family name. Use e.g. \"tag36h11\".\n");
          exit(-1);
      }
      self->td = apriltag_detector_create();
      apriltag_detector_add_family_bits(self->td, self->tf, 1);
      // apriltag_detector_add_family(td, tf);
      self->td->quad_decimate = 2.0; // "Decimate input image by this factor"
      self->td->quad_sigma = 0.0; // Apply low-pass blur to input
      self->td->nthreads = 1;
      self->td->debug = 0;
      self->td->refine_edges = 1;// Spend more time trying to align edges of tags
    }

    LIBMAIX_INFO_PRINTF("find_apriltag_app_load");
    if (self->td && self->tf)
    {
      return 0;
    }
    return -1;
  }

  int find_apriltag_app_exit(zm831_home_app *app)
  {
    auto self = (_find_apriltag_ *)app->userdata;
    if (self->td && self->tf)
    {
        apriltag_detector_destroy(self->td), self->td = NULL;
        if (!strcmp(self->famname, "tag36h11")) {
            tag36h11_destroy(self->tf);
        } else if (!strcmp(self->famname, "tag25h9")) {
            tag25h9_destroy(self->tf);
        } else if (!strcmp(self->famname, "tag16h5")) {
            tag16h5_destroy(self->tf);
        } else if (!strcmp(self->famname, "tagCircle21h7")) {
            tagCircle21h7_destroy(self->tf);
        } else if (!strcmp(self->famname, "tagCircle49h12")) {
            tagCircle49h12_destroy(self->tf);
        } else if (!strcmp(self->famname, "tagStandard41h12")) {
            tagStandard41h12_destroy(self->tf);
        } else if (!strcmp(self->famname, "tagStandard52h13")) {
            tagStandard52h13_destroy(self->tf);
        } else if (!strcmp(self->famname, "tagCustom48h12")) {
            tagCustom48h12_destroy(self->tf);
        }
        self->tf = NULL;
    }

    pthread_mutex_lock(&zm831->ui_mutex);
    lv_canvas_fill_bg(zm831_ui_get_canvas(), LV_COLOR_BLACK, LV_OPA_TRANSP);
    pthread_mutex_unlock(&zm831->ui_mutex);

    LIBMAIX_INFO_PRINTF("find_apriltag_app_exit");
    return 0;
  }

  int find_apriltag_app_loop(zm831_home_app *app)
  {
    auto self = (_find_apriltag_ *)app->userdata;
    if (self->td && self->tf)
    {
      libmaix_image_t *ai_rgb = NULL;
      if (zm831->ai && LIBMAIX_ERR_NONE == zm831->ai->capture_image(zm831->ai, &ai_rgb))
      {
        zm831->sensor_time = zm831_get_ms();
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
            .buf = (uint8_t *)(gray.data)
        };

        zarray_t *detections = apriltag_detector_detect(self->td, &im);

        pthread_mutex_lock(&zm831->ui_mutex);
        lv_canvas_fill_bg(zm831_ui_get_canvas(), LV_COLOR_BLACK, LV_OPA_TRANSP);
        // Draw detection outlines
        for (int i = 0; i < zarray_size(detections); i++) {

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

    usleep(10000);// 10ms

    // LIBMAIX_INFO_PRINTF("find_apriltag_app_loop");
    return 0;
  }
}
