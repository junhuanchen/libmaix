
#ifndef _zm831_uv_
#define _zm831_uv_

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <pthread.h>
#include <sys/time.h>
#include <sys/select.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <linux/input.h>

#include "global_config.h"
#include "libmaix_debug.h"
#include "libmaix_err.h"
#include "libmaix_cam.h"
#include "libmaix_image.h"
#include "libmaix_disp.h"
#include "libmaix_nn.h"
#include "libmaix_nn_decoder_yolo2.h"

#include "lvgl/lvgl.h"
#include "lv_examples/lv_examples.h"
#include "lv_lib_png/lv_png.h"
#include "evdev_mouse.h"
#include "linux_uart.h"

#include "opencv2/core.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/videoio.hpp"
#include "opencv2/imgcodecs.hpp"
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/imgcodecs/legacy/constants_c.h>
#include "opencv2/core/types_c.h"

#define CALC_FPS(tips)                                                                                         \
    {                                                                                                          \
        static int fcnt = 0;                                                                                   \
        fcnt++;                                                                                                \
        static struct timespec ts1, ts2;                                                                       \
        clock_gettime(CLOCK_MONOTONIC, &ts2);                                                                  \
        if ((ts2.tv_sec * 1000 + ts2.tv_nsec / 1000000) - (ts1.tv_sec * 1000 + ts1.tv_nsec / 1000000) >= 1000) \
        {                                                                                                      \
            printf("%s => H26X FPS:%d     \r\n", tips, fcnt);                                                  \
            ts1 = ts2;                                                                                         \
            fcnt = 0;                                                                                          \
        }                                                                                                      \
    }

const int zm831_ui_w = 240, zm831_ui_h = 240;
const int zm831_vi_w = 240, zm831_vi_h = 240;
const int zm831_ai_w = 224, zm831_ai_h = 224;

struct zm831_pack_t
{
    uint8_t type;
    std::vector<uint8_t> data;
};

typedef struct
{
    // sys
    int exit, signal;
    pthread_mutex_t vi_mutex, ai_mutex, ui_mutex;
    // hw
    struct timeval timeout;
    int input_event0, dev_ttyS1;
    fd_set readfd;
    std::list<zm831_pack_t> recvPacks;
    // vi
    uint16_t vi_w, vi_h, ai_w, ai_h, ui_w, ui_h;
    libmaix_cam *vi, *ai;
    // uint8_t *vi_yuv;
    // uint8_t *ai_rgb;
    // libmaix_image_t *ai_rgb;
    libmaix_vo *ui;
    // cv::Mat ui_bgra;
    // libmaix_image_t *ui_rgba;
    lv_color_t *ui_buf1, *ui_buf2;
    lv_color_t canvas_buffer[LV_CANVAS_BUF_SIZE_TRUE_COLOR_ALPHA(zm831_ui_w, zm831_ui_h)];
    lv_obj_t *canvas;
    lv_style_t screen_style;
    // ui
    pthread_t ui_thread;
    int ui_th_usec, vi_th_usec;
    // ai
    pthread_t ai_thread;
    int ai_th_usec, ai_th_id;
    volatile int ai_th_keep;
} zm831_uv;

typedef struct _zm831_home_app_
{
    int (*load)(struct _zm831_home_app_ *);
    int (*loop)(struct _zm831_home_app_ *);
    int (*exit)(struct _zm831_home_app_ *);
    void *userdata;
} zm831_home_app;

typedef void (*_zm831_home_app_func_)(zm831_home_app *);

typedef zm831_home_app (*_get_zm831_home_app_func_)();

#define ai2vi(val) (int)((val) * (240.0 / 224.0)) // ai / vi = 224 / 240
#define vi2ai(val) (int)((val) * (224.0 / 240.0)) // vi / ai = 240 / 224

// #define ai2vi(val) (int)((val) * 15 / 14) // ai / vi = 224 / 240
// #define vi2ai(val) (int)((val) * 14 / 15) // vi / ai = 240 / 224

#define mv2cvL(l) (int(((l) * 255) / 100))
#define mv2cvA(a) ((a) + 128)
#define mv2cvB(b) ((b) + 128)

#endif /*_zm831_uv_*/
