
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
#include "lv_lib_freetype/lv_freetype.h"
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

#include "json5pp.hpp"

// << string_format("%d", 202412);
template <typename... Args>
std::string string_format(const std::string &format, Args... args)
{
    size_t size = 1 + snprintf(nullptr, 0, format.c_str(), args...); // Extra space for \0
    // unique_ptr<char[]> buf(new char[size]);
    char bytes[size];
    snprintf(bytes, size, format.c_str(), args...);
    return std::string(bytes);
}

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

extern "C"
{
    typedef struct
    {
        lv_obj_t *Home;
        lv_obj_t *Home_home;
        lv_obj_t *Home_home_home_1;
        lv_obj_t *Home_home1_lline_h;
        lv_obj_t *Home_home1_line_w;
        lv_obj_t *Home_home1_lline_h2;
        lv_obj_t *Home_home_photo;
        lv_obj_t *Home_home_photo_label;
        lv_obj_t *Home_home_gesture;
        lv_obj_t *Home_home_gesture_label;
        lv_obj_t *Home_home_face_s;
        lv_obj_t *Home_home_face_s_label;
        lv_obj_t *Home_home_face;
        lv_obj_t *Home_home_face_label;
        lv_obj_t *Home_label_photo;
        lv_obj_t *Home_label_face;
        lv_obj_t *Home_label_face_s;
        lv_obj_t *Home_label_gesture;
        lv_obj_t *Home_home_home_2;
        lv_obj_t *Home_home2_line_w;
        lv_obj_t *Home_label_tagcode;
        lv_obj_t *Home_label_qrcode;
        lv_obj_t *Home_label_color_s;
        lv_obj_t *Home_label_color;
        lv_obj_t *Home_home2_lline_h2;
        lv_obj_t *Home_home2_line_h;
        lv_obj_t *Home_hom_color;
        lv_obj_t *Home_hom_color_label;
        lv_obj_t *Home_hom_tagcode;
        lv_obj_t *Home_hom_tagcode_label;
        lv_obj_t *Home_home_qrcode;
        lv_obj_t *Home_home_qrcode_label;
        lv_obj_t *Home_hom_colo_s;
        lv_obj_t *Home_hom_colo_s_label;
        lv_obj_t *Home_home_home_3;
        lv_obj_t *Home_imgbtn_5;
        lv_obj_t *Home_imgbtn_5_label;
        lv_obj_t *photo_app;
        lv_obj_t *photo_app_photo_app;
        lv_obj_t *photo_app_photo_app_tileview;
        lv_obj_t *photo_app_label_top;
        lv_obj_t *photo_app_imgbtn_press;
        lv_obj_t *photo_app_imgbtn_press_label;
        lv_obj_t *photo_app_imgbtn_clear;
        lv_obj_t *photo_app_imgbtn_clear_label;
        lv_obj_t *photo_app_imgbtn_back;
        lv_obj_t *photo_app_imgbtn_back_label;
    }lv_ui;

    void setup_ui(lv_ui *ui);
    extern lv_ui guider_ui;
    void setup_scr_Home(lv_ui *ui);
    void setup_scr_photo_app(lv_ui *ui);
    LV_IMG_DECLARE(_press_alpha_63x63);
    LV_IMG_DECLARE(_clear_alpha_50x50);
    LV_IMG_DECLARE(_main_photo_alpha_60x42);
    LV_IMG_DECLARE(_home_tagcode_alpha_47x47);
    LV_IMG_DECLARE(_home_qrcode_alpha_47x47);
    LV_IMG_DECLARE(_home_s_alpha_52x50);
    LV_IMG_DECLARE(_main_face_s_alpha_49x49);
    LV_IMG_DECLARE(_back_alpha_50x50);
    LV_IMG_DECLARE(_main_face_alpha_49x49);
    LV_IMG_DECLARE(_home_color_alpha_52x49);
    LV_IMG_DECLARE(_main_shoushi_alpha_47x47);
    LV_IMG_DECLARE(_main_shoushi_alpha_50x44);
    LV_FONT_DECLARE(lv_font_simsun_15);
    LV_FONT_DECLARE(lv_font_simsun_6);

    typedef void (*_ui_setup_scr_)(lv_ui *ui);
    void zm831_home_setup_ui(lv_obj_t **lvgl_screen, _ui_setup_scr_ setup_scr, int load_time_ms);
    void zm831_home_clear_ui(lv_obj_t **lvgl_screen);
}

typedef struct
{
    // ui designed
    lv_ui ui;
    // sys
    const char *config_file = "/root/zm831.conf";
    json5pp::value config_json;

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
    libmaix_vo *vo;
    // cv::Mat ui_bgra;
    // libmaix_image_t *ui_rgba;
    lv_color_t *ui_buf1, *ui_buf2;
    lv_color_t canvas_buffer[LV_CANVAS_BUF_SIZE_TRUE_COLOR_ALPHA(zm831_ui_w, zm831_ui_h)];
    lv_obj_t *canvas;
    lv_style_t screen_style;
    lv_ft_info_t ft_font;
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

#define mv2cvL(l) (int(((l)*255) / 100))
#define mv2cvA(a) ((a) + 128)
#define mv2cvB(b) ((b) + 128)

extern "C"
{
    void zm831_load_json_conf();
    void zm831_save_json_conf();
    void zm831_ui_show_clear();
    void zm831_ui_show_image(cv::Mat &img, int x, int y, lv_opa_t opa);
    int zm831_home_app_select(int id);
    void zm831_home_app_stop();
}

#endif /*_zm831_uv_*/
