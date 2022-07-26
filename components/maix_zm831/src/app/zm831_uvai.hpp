
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
#include "linux_gpio.h"

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

static void msleep(unsigned int ms)
{
    usleep(ms * 1000);
    // struct timespec ts = {ms / 1000, (ms % 1000) * 1000 * 1000};
    // nanosleep(&ts, nullptr);
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
        lv_obj_t *home;
        lv_obj_t *home_home;
        lv_obj_t *home_home_home_1;
        lv_obj_t *home_line_mid_h_home1;
        lv_obj_t *home_lline_mid_v1_home1;
        lv_obj_t *home_lline_bottom_h_home1;
        lv_obj_t *home_lline_mid_v2_home1;
        lv_obj_t *home_lline_right_v_home1;
        lv_obj_t *home_imgbtn_photo;
        lv_obj_t *home_imgbtn_photo_label;
        lv_obj_t *home_imgbtn_gesture;
        lv_obj_t *home_imgbtn_gesture_label;
        lv_obj_t *home_imgbtn_face_study;
        lv_obj_t *home_imgbtn_face_study_label;
        lv_obj_t *home_imgbtn_face;
        lv_obj_t *home_imgbtn_face_label;
        lv_obj_t *home_label_photo;
        lv_obj_t *home_label_face;
        lv_obj_t *home_label_face_s;
        lv_obj_t *home_label_gesture;
        lv_obj_t *home_home_home_2;
        lv_obj_t *home_label_tagcode;
        lv_obj_t *home_lline_bottom_h_home2;
        lv_obj_t *home_hline_mid_v_home2;
        lv_obj_t *home_lline_right_v_home2;
        lv_obj_t *home_line_mid_h_home2;
        lv_obj_t *home_label_qrcode;
        lv_obj_t *home_label_color_s;
        lv_obj_t *home_label_color;
        lv_obj_t *home_imgbtn_color;
        lv_obj_t *home_imgbtn_color_label;
        lv_obj_t *home_Imgbtn_tagcode;
        lv_obj_t *home_Imgbtn_tagcode_label;
        lv_obj_t *home_imgbtn_qrcode;
        lv_obj_t *home_imgbtn_qrcode_label;
        lv_obj_t *home_imgbtn_colo_s;
        lv_obj_t *home_imgbtn_colo_s_label;
        lv_obj_t *home_home_home_3;
        lv_obj_t *home_line_right_v_home3;
        lv_obj_t *home_line_bottom_h_home3;
        lv_obj_t *home_line_mid_h_home3;
        lv_obj_t *home_line_mid_v_home3;
        lv_obj_t *home_label_number;
        lv_obj_t *home_label_ball;
        lv_obj_t *home_label_traffic;
        lv_obj_t *home_label_road;
        lv_obj_t *home_imgbtn_number;
        lv_obj_t *home_imgbtn_number_label;
        lv_obj_t *home_imgbtn_ball;
        lv_obj_t *home_imgbtn_ball_label;
        lv_obj_t *home_imgbtn_traffic;
        lv_obj_t *home_imgbtn_traffic_label;
        lv_obj_t *home_imgbtn_road;
        lv_obj_t *home_imgbtn_road_label;
        lv_obj_t *home_home_home_4;
        lv_obj_t *home_line_mid_h_home4;
        lv_obj_t *home_label_classific_study;
        lv_obj_t *home_label_classific;
        lv_obj_t *home_label_five_road;
        lv_obj_t *home_label_cube;
        lv_obj_t *home_imgbtn_five_road;
        lv_obj_t *home_imgbtn_five_road_label;
        lv_obj_t *home_imgbtn_classific;
        lv_obj_t *home_imgbtn_classific_label;
        lv_obj_t *home_imgbtn_classific_study;
        lv_obj_t *home_imgbtn_classific_study_label;
        lv_obj_t *home_imgbtn_cube;
        lv_obj_t *home_imgbtn_cube_label;
        lv_obj_t *home_line_bottom_h_home4;
        lv_obj_t *home_line_right_h_home4;
        lv_obj_t *home_line_mid_v_home4;
        lv_obj_t *home_home_home_5;
        lv_obj_t *home_line_right_h_home5;
        lv_obj_t *home_label_speech_interaction;
        lv_obj_t *home_label_word_study;
        lv_obj_t *home_label_key_word;
        lv_obj_t *home_label_speech;
        lv_obj_t *home_imgbtn_speech_interaction;
        lv_obj_t *home_imgbtn_speech_interaction_label;
        lv_obj_t *home_imgbtn_word_study;
        lv_obj_t *home_imgbtn_word_study_label;
        lv_obj_t *home_imgbtn_key_word;
        lv_obj_t *home_imgbtn_key_word_label;
        lv_obj_t *home_imgbtn_5;
        lv_obj_t *home_imgbtn_5_label;
        lv_obj_t *home_line_mid_v_home5;
        lv_obj_t *home_line_mid_h_home5;
        lv_obj_t *home_line_bottom_h_home5;
        lv_obj_t *home_home_home_6;
        lv_obj_t *home_line_right_h_home6;
        lv_obj_t *home_label_led;
        lv_obj_t *home_label_language;
        lv_obj_t *home_imgbtn_led;
        lv_obj_t *home_imgbtn_led_label;
        lv_obj_t *home_imgbtn_language;
        lv_obj_t *home_imgbtn_language_label;
        lv_obj_t *home_line_mid_v_home6;
        lv_obj_t *home_line_mid_h_home6;
        lv_obj_t *home_line_bottom_h_home6;
        lv_obj_t *photo_app;
        lv_obj_t *photo_app_label_top_title;
        lv_obj_t *photo_app_imgbtn_back;
        lv_obj_t *photo_app_imgbtn_back_label;
        lv_obj_t *photo_app_imgbtn_clear;
        lv_obj_t *photo_app_imgbtn_clear_label;
        lv_obj_t *photo_app_imgbtn_press;
        lv_obj_t *photo_app_imgbtn_press_label;
        lv_obj_t *face_app;
        lv_obj_t *face_app_label_top_title;
        lv_obj_t *face_app_imgbtn_back;
        lv_obj_t *face_app_imgbtn_back_label;
        lv_obj_t *face_study_app;
        lv_obj_t *face_study_app_label_top_title;
        lv_obj_t *face_study_app_imgbtn_back;
        lv_obj_t *face_study_app_imgbtn_back_label;
        lv_obj_t *face_study_app_imgbtn_clear;
        lv_obj_t *face_study_app_imgbtn_clear_label;
        lv_obj_t *face_study_app_imgbtn_press;
        lv_obj_t *face_study_app_imgbtn_press_label;
        lv_obj_t *gesture_app;
        lv_obj_t *gesture_app_label_top_title;
        lv_obj_t *gesture_app_imgbtn_back;
        lv_obj_t *gesture_app_imgbtn_back_label;
        lv_obj_t *color_app;
        lv_obj_t *color_app_label_top_title;
        lv_obj_t *color_app_imgbtn_back;
        lv_obj_t *color_app_imgbtn_back_label;
        lv_obj_t *color_study_app;
        lv_obj_t *color_study_app_label_top_title;
        lv_obj_t *color_study_app_imgbtn_back;
        lv_obj_t *color_study_app_imgbtn_back_label;
        lv_obj_t *color_study_app_imgbtn_clear;
        lv_obj_t *color_study_app_imgbtn_clear_label;
        lv_obj_t *color_study_app_imgbtn_press;
        lv_obj_t *color_study_app_imgbtn_press_label;
        lv_obj_t *qrcode_app;
        lv_obj_t *qrcode_app_label_top_title;
        lv_obj_t *qrcode_app_imgbtn_back;
        lv_obj_t *qrcode_app_imgbtn_back_label;
        lv_obj_t *tagcode_app;
        lv_obj_t *tagcode_app_label_top_title;
        lv_obj_t *tagcode_app_imgbtn_back;
        lv_obj_t *tagcode_app_imgbtn_back_label;
        lv_obj_t *road_app;
        lv_obj_t *road_app_label_top_title;
        lv_obj_t *road_app_imgbtn_back;
        lv_obj_t *road_app_imgbtn_back_label;
        lv_obj_t *traffic_app;
        lv_obj_t *traffic_app_label_top_title;
        lv_obj_t *traffic_app_imgbtn_back;
        lv_obj_t *traffic_app_imgbtn_back_label;
        lv_obj_t *ball_app;
        lv_obj_t *ball_app_label_top_title;
        lv_obj_t *ball_app_imgbtn_back;
        lv_obj_t *ball_app_imgbtn_back_label;
        lv_obj_t *ball_app_imgbtn_change_color;
        lv_obj_t *ball_app_imgbtn_change_color_label;
        lv_obj_t *number_app;
        lv_obj_t *number_app_label_top_title;
        lv_obj_t *number_app_imgbtn_back;
        lv_obj_t *number_app_imgbtn_back_label;
        lv_obj_t *cube_app;
        lv_obj_t *cube_app_label_top_title;
        lv_obj_t *cube_app_imgbtn_back;
        lv_obj_t *cube_app_imgbtn_back_label;
        lv_obj_t *cube_app_imgbtn_clear;
        lv_obj_t *cube_app_imgbtn_clear_label;
        lv_obj_t *cube_app_imgbtn_press;
        lv_obj_t *cube_app_imgbtn_press_label;
        lv_obj_t *five_road_app;
        lv_obj_t *five_road_app_label_top_title;
        lv_obj_t *five_road_app_imgbtn_back;
        lv_obj_t *five_road_app_imgbtn_back_label;
        lv_obj_t *five_road_app_imgbtn_change_color;
        lv_obj_t *five_road_app_imgbtn_change_color_label;
        lv_obj_t *classific_app;
        lv_obj_t *classific_app_label_top_title;
        lv_obj_t *classific_app_imgbtn_back;
        lv_obj_t *classific_app_imgbtn_back_label;
        lv_obj_t *classific_study_app;
        lv_obj_t *classific_study_app_label_top_title;
        lv_obj_t *classific_study_app_imgbtn_back;
        lv_obj_t *classific_study_app_imgbtn_back_label;
        lv_obj_t *classific_study_app_imgbtn_clear;
        lv_obj_t *classific_study_app_imgbtn_clear_label;
        lv_obj_t *classific_study_app_imgbtn_press;
        lv_obj_t *classific_study_app_imgbtn_press_label;
        lv_obj_t *speech_app;
        lv_obj_t *speech_app_canvas_background;
        lv_obj_t *speech_app_label_top_title;
        lv_obj_t *speech_app_imgbtn_back;
        lv_obj_t *speech_app_imgbtn_back_label;
        lv_obj_t *speech_app_imgbtn_clear;
        lv_obj_t *speech_app_imgbtn_clear_label;
        lv_obj_t *speech_study_app;
        lv_obj_t *speech_study_app_canvas_background;
        lv_obj_t *speech_study_app_label_top_title;
        lv_obj_t *speech_study_app_imgbtn_back;
        lv_obj_t *speech_study_app_imgbtn_back_label;
        lv_obj_t *speech_study_app_imgbtn_clear;
        lv_obj_t *speech_study_app_imgbtn_clear_label;
        lv_obj_t *speech_study_app_imgbtn_press;
        lv_obj_t *speech_study_app_imgbtn_press_label;
        lv_obj_t *speech_keyword_app;
        lv_obj_t *speech_keyword_app_canvas_background;
        lv_obj_t *speech_keyword_app_label_top_title;
        lv_obj_t *speech_keyword_app_imgbtn_back;
        lv_obj_t *speech_keyword_app_imgbtn_back_label;
        lv_obj_t *speech_keyword_app_imgbtn_press;
        lv_obj_t *speech_keyword_app_imgbtn_press_label;
        lv_obj_t *speech_keyword_app_imgbtn_clear;
        lv_obj_t *speech_keyword_app_imgbtn_clear_label;
        lv_obj_t *speech_interaction_app;
        lv_obj_t *speech_interaction_app_canvas_background;
        lv_obj_t *speech_interaction_app_label_top_title;
        lv_obj_t *speech_interaction_app_imgbtn_back;
        lv_obj_t *speech_interaction_app_imgbtn_back_label;
        lv_obj_t *speech_interaction_app_imgbtn_clear;
        lv_obj_t *speech_interaction_app_imgbtn_clear_label;
        lv_obj_t *language_app;
        lv_obj_t *language_app_canvas_background;
        lv_obj_t *language_app_label_top_title;
        lv_obj_t *language_app_imgbtn_chinese;
        lv_obj_t *language_app_imgbtn_chinese_label;
        lv_obj_t *language_app_imgbtn_english;
        lv_obj_t *language_app_imgbtn_english_label;
        lv_obj_t *led_app;
        lv_obj_t *led_app_canvas_background;
        lv_obj_t *led_app_label_top_title;
        lv_obj_t *led_app_imgbtn_led_on;
        lv_obj_t *led_app_imgbtn_led_on_label;
        lv_obj_t *led_app_imgbtn_led_off;
        lv_obj_t *led_app_imgbtn_led_off_label;
    }lv_ui;

    LV_IMG_DECLARE(_home_led_alpha_39x39);
    LV_IMG_DECLARE(_home_keyword_alpha_47x47);
    LV_IMG_DECLARE(_study_alpha_63x63);
    LV_IMG_DECLARE(_keyword_change_alpha_63x63);
    LV_IMG_DECLARE(_home_classific_alpha_47x47);
    LV_IMG_DECLARE(_home_road5_alpha_63x63);
    LV_IMG_DECLARE(_home_speech_study_alpha_49x49);
    LV_IMG_DECLARE(_home_ball_alpha_63x63);
    LV_IMG_DECLARE(_home_road_alpha_47x47);
    LV_IMG_DECLARE(_main_photo_alpha_60x42);
    LV_IMG_DECLARE(_home_speech_alpha_47x47);
    LV_IMG_DECLARE(_home_tagcode_alpha_47x47);
    LV_IMG_DECLARE(_home_number_alpha_47x47);
    LV_IMG_DECLARE(_main_face_s_alpha_49x49);
    LV_IMG_DECLARE(_back_alpha_50x50);
    LV_IMG_DECLARE(_home_traffic_alpha_47x47);
    LV_IMG_DECLARE(_clear_alpha_50x50);
    LV_IMG_DECLARE(_press_alpha_63x63);
    LV_IMG_DECLARE(_led_off_alpha_63x63);
    LV_IMG_DECLARE(_home__alpha_47x47);
    LV_IMG_DECLARE(_home_five_road_alpha_72x30);
    LV_IMG_DECLARE(_led_on_alpha_63x63);
    LV_IMG_DECLARE(_home_find_ball_alpha_47x47);
    LV_IMG_DECLARE(_main_face_alpha_49x49);
    LV_IMG_DECLARE(_home_color_alpha_52x49);
    LV_IMG_DECLARE(_english_alpha_63x63);
    LV_IMG_DECLARE(_home_language_alpha_47x32);
    LV_IMG_DECLARE(_home_qrcode_alpha_47x47);
    LV_IMG_DECLARE(_home_s_alpha_52x50);
    LV_IMG_DECLARE(_home_cube_alpha_52x53);
    LV_IMG_DECLARE(_home_image_s_alpha_49x49);
    LV_IMG_DECLARE(_main_shoushi_alpha_47x47);
    LV_IMG_DECLARE(_chinese_alpha_63x63);

    LV_FONT_DECLARE(lv_font_simsun_15);
    LV_FONT_DECLARE(lv_font_simsun_6);
    LV_FONT_DECLARE(lv_font_simsun_12);
    LV_FONT_DECLARE(lv_font_simsun_18);

    typedef void (*_ui_setup_scr_)(lv_ui *ui);
    void zm831_home_setup_ui(lv_obj_t **lvgl_screen, _ui_setup_scr_ setup_scr, int load_time_ms);
    void zm831_home_clear_ui(lv_obj_t **lvgl_screen);
}

typedef struct
{
    // ui designed
    lv_ui ui;
    // sys
    const char *config_file = "/root/zm831_home.json";
    json5pp::value config_json;

    int exit, signal;
    pthread_mutex_t vi_mutex, ai_mutex, ui_mutex;
    // hw
    struct timeval timeout;
    int input_event0, dev_ttyS1, sensor_flip;
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
    int ui_th_ms, vi_th_ms;
    // ai
    pthread_t ai_thread;
    int ai_th_ms, ai_th_id;
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

// #define ai2vi(val) (int)((val) * (240.0 / 224.0)) // ai / vi = 224 / 240
// #define vi2ai(val) (int)((val) * (224.0 / 240.0)) // vi / ai = 240 / 224

#define ai2vi(val) (int)((val) * 15 / 14) // ai / vi = 224 / 240
#define vi2ai(val) (int)((val) * 14 / 15) // vi / ai = 240 / 224

#define mv2cvL(l) (int(((l)*255) / 100))
#define mv2cvA(a) ((a) + 128)
#define mv2cvB(b) ((b) + 128)

extern "C"
{
    void zm831_save_json_conf(const std::string &path, json5pp::value &cfg);
    void zm831_load_json_conf(const std::string &path, json5pp::value &cfg, json5pp::value old);
    lv_obj_t *zm831_ui_get_canvas();
    void zm831_ui_show_clear();
    void zm831_ui_show_image(cv::Mat &img, int x, int y, lv_opa_t opa);
    int zm831_home_app_select(int id);
    void zm831_home_app_stop();
    uint32_t zm831_get_ms();
    int zm831_protocol_send(uint8_t func, uint8_t * data, int len);

    int AW_MPI_VI_SetVippMirror(int ViDev, int Value);
    int AW_MPI_VI_SetVippFlip(int ViDev, int Value);
}

#endif /*_zm831_uv_*/
