
#include "gs831_uvai.hpp"

extern "C"
{
  extern gs831_uv *gs831;

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
    const char *famname = "tagStandard52h13";
    apriltag_detector_t *td = NULL;
    apriltag_family_t *tf = NULL;
  } find_apriltag_app;

// ==============================================================================================

  int find_apriltag_app_load(_find_apriltag_ *self)
  {

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
      apriltag_detector_add_family_bits(self->td, self->tf, 0);
      // apriltag_detector_add_family(td, tf);
      self->td->quad_decimate = 2.0; // "Decimate input image by this factor"
      self->td->quad_sigma = 0.0; // Apply low-pass blur to input
      self->td->nthreads = 2;
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

  int find_apriltag_app_exit(_find_apriltag_ *self)
  {
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

    LIBMAIX_INFO_PRINTF("find_apriltag_app_exit");
    return 0;
  }

  static inline uint32_t gs831_get_ms()
  {
      static struct timespec tmp;
      clock_gettime(CLOCK_MONOTONIC, &tmp);
      return (tmp.tv_sec * 1000) + (uint32_t)tmp.tv_nsec / 1000000;
  }

  int find_apriltag_app_loop(_find_apriltag_ *self, uint8_t *data, uint32_t width, uint32_t height)
  {
    if (self->td && self->tf)
    {
      struct apriltag_data {
        uint8_t head;
        uint8_t len;
        uint8_t retain_0;
        uint8_t retain_1;
        uint32_t tm;
        uint32_t id;
        float decision_margin;
        float center[2];
        float points[4][2];
        float rotation[3][3];
        uint8_t retain_2;
        uint8_t retain_3;
        uint8_t sum;
        uint8_t end;
      } upload_data = { 0x55, sizeof(struct apriltag_data), 0, 0, gs831_get_ms(), 0, 0, { 0, 0 }, { { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 } }, { { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 } }, 0, 0, 0, 0x0A };

      cv::Mat gray(height, width, CV_8UC1, data);

      // Make an image_u8_t header for the Mat data
      image_u8_t im = {
          .width = gray.cols,
          .height = gray.rows,
          .stride = gray.cols,
          .buf = (uint8_t *)(gray.data)
      };

      zarray_t *detections = apriltag_detector_detect(self->td, &im);

      // Draw detection outlines
      for (int i = 0; i < zarray_size(detections); i++) {

        apriltag_detection_t *det;
        zarray_get(detections, i, &det);

        cv::line(gray, cv::Point(det->p[0][0], det->p[0][1]),
                  cv::Point(det->p[1][0], det->p[1][1]),
                  cv::Scalar(0xff, 0, 0), 2);
        cv::line(gray, cv::Point(det->p[1][0], det->p[1][1]),
                  cv::Point(det->p[2][0], det->p[2][1]),
                  cv::Scalar(0xff, 0, 0), 2);
        cv::line(gray, cv::Point(det->p[2][0], det->p[2][1]),
                  cv::Point(det->p[3][0], det->p[3][1]),
                  cv::Scalar(0xff, 0, 0), 2);
        cv::line(gray, cv::Point(det->p[3][0], det->p[3][1]),
                  cv::Point(det->p[0][0], det->p[0][1]),
                  cv::Scalar(0xff, 0, 0), 2);

        upload_data.id = det->id;
        upload_data.decision_margin = det->decision_margin;
        upload_data.center[0] = det->c[0];
        upload_data.center[1] = det->c[1];
        upload_data.points[0][0] = det->p[0][0];
        upload_data.points[0][1] = det->p[0][1];
        upload_data.points[1][0] = det->p[1][0];
        upload_data.points[1][1] = det->p[1][1];
        upload_data.points[2][0] = det->p[2][0];
        upload_data.points[2][1] = det->p[2][1];
        upload_data.points[3][0] = det->p[3][0];
        upload_data.points[3][1] = det->p[3][1];

        uint8_t *ptr = (uint8_t *)&upload_data;
        // uint8_t sum = 0;
        for (int i = 0; i < upload_data.len - 2; i++) upload_data.sum += ptr[i];
        // upload_data.sum = sum;
        write(gs831->dev_ttyS, ptr, upload_data.len);

        break;

        // cv::Matx<double, 3, 3> R_inv = R.t();

        // auto text = string_format("[(%d,%.0f),(%d,%d)]\r\n", det->id, det->decision_margin, (int)det->c[0], (int)det->c[1]);

        // write(gs831->dev_ttyS, text.c_str(), text.length());

        // printf("detection %d: id=%d, hamming=%d, decision_margin=%f, "
        //        "p[0]=(%f,%f), p[1]=(%f,%f), p[2]=(%f,%f), p[3]=(%f,%f)\n",
        //        i, det->id, det->hamming, det->decision_margin,
        //        det->p[0][0], det->p[0][1], det->p[1][0], det->p[1][1],
        //        det->p[2][0], det->p[2][1], det->p[3][0], det->p[3][1]);

        // int fontface = cv::FONT_HERSHEY_SCRIPT_SIMPLEX;
        // double fontscale = 1.0;
        // int baseline;
        // cv::Size textsize = cv::getTextSize(text, fontface, fontscale, 2,
        //                                 &baseline);
        // cv::putText(gray, text, cv::Point(det->c[0]-textsize.width/2,
        //                             det->c[1]+textsize.height/2),
        //         fontface, fontscale, cv::Scalar(0xff, 0x99, 0), 2);
      }

      apriltag_detections_destroy(detections);
    }

    return 0;
  }

}
