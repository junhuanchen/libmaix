
#include "zm831_uvai.hpp"

extern "C"
{
  extern zm831_uv *zm831;

  // ==============================================================================================

  void setup_scr_screen(lv_ui *ui)
  {

    // Write codes screen
    ui->Home = lv_scr_act();

    // Write style LV_OBJ_PART_MAIN for Home
    static lv_style_t style_Home_main;
    lv_style_reset(&style_Home_main);

    // Write style state: LV_STATE_DEFAULT for style_Home_main
    lv_style_set_bg_color(&style_Home_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
    lv_style_set_bg_opa(&style_Home_main, LV_STATE_DEFAULT, 0);
    lv_obj_add_style(ui->Home, LV_OBJ_PART_MAIN, &style_Home_main);

    // Write codes Home_home
    ui->Home_home = lv_tileview_create(ui->Home, NULL);
    static lv_point_t Home_home_valid_pos[] = {
        {0, 0},
        {0, 1},
        {0, 2},
    };
    lv_tileview_set_valid_positions(ui->Home_home, Home_home_valid_pos, 3);
    lv_tileview_set_edge_flash(ui->Home_home, false);
    lv_tileview_set_anim_time(ui->Home_home, 100);

    // Write style LV_TILEVIEW_PART_BG for Home_home
    static lv_style_t style_Home_home_bg;
    lv_style_reset(&style_Home_home_bg);

    // Write style state: LV_STATE_DEFAULT for style_Home_home_bg
    lv_style_set_radius(&style_Home_home_bg, LV_STATE_DEFAULT, 0);
    lv_style_set_bg_color(&style_Home_home_bg, LV_STATE_DEFAULT, lv_color_make(0x3c, 0x3c, 0x3c));
    lv_style_set_bg_grad_color(&style_Home_home_bg, LV_STATE_DEFAULT, lv_color_make(0x3c, 0x3c, 0x3c));
    lv_style_set_bg_grad_dir(&style_Home_home_bg, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
    lv_style_set_bg_opa(&style_Home_home_bg, LV_STATE_DEFAULT, 255);
    lv_obj_add_style(ui->Home_home, LV_TILEVIEW_PART_BG, &style_Home_home_bg);

    // Write style LV_TILEVIEW_PART_EDGE_FLASH for Home_home
    static lv_style_t style_Home_home_edge_flash;
    lv_style_reset(&style_Home_home_edge_flash);

    // Write style state: LV_STATE_DEFAULT for style_Home_home_edge_flash
    lv_style_set_radius(&style_Home_home_edge_flash, LV_STATE_DEFAULT, 0);
    lv_style_set_bg_color(&style_Home_home_edge_flash, LV_STATE_DEFAULT, lv_color_make(0xea, 0xef, 0xf3));
    lv_style_set_bg_grad_color(&style_Home_home_edge_flash, LV_STATE_DEFAULT, lv_color_make(0xea, 0xef, 0xf3));
    lv_style_set_bg_grad_dir(&style_Home_home_edge_flash, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
    lv_style_set_bg_opa(&style_Home_home_edge_flash, LV_STATE_DEFAULT, 255);
    lv_obj_add_style(ui->Home_home, LV_TILEVIEW_PART_EDGE_FLASH, &style_Home_home_edge_flash);

    // Write style LV_TILEVIEW_PART_SCROLLBAR for Home_home
    static lv_style_t style_Home_home_scrollbar;
    lv_style_reset(&style_Home_home_scrollbar);

    // Write style state: LV_STATE_DEFAULT for style_Home_home_scrollbar
    lv_style_set_radius(&style_Home_home_scrollbar, LV_STATE_DEFAULT, 0);
    lv_style_set_bg_color(&style_Home_home_scrollbar, LV_STATE_DEFAULT, lv_color_make(0xea, 0xef, 0xf3));
    lv_style_set_bg_grad_color(&style_Home_home_scrollbar, LV_STATE_DEFAULT, lv_color_make(0xea, 0xef, 0xf3));
    lv_style_set_bg_grad_dir(&style_Home_home_scrollbar, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
    lv_style_set_bg_opa(&style_Home_home_scrollbar, LV_STATE_DEFAULT, 255);
    lv_obj_add_style(ui->Home_home, LV_TILEVIEW_PART_SCROLLBAR, &style_Home_home_scrollbar);
    lv_obj_set_pos(ui->Home_home, 0, 0);
    lv_obj_set_size(ui->Home_home, 240, 240);

    // Write codes Home_home_home_1
    ui->Home_home_home_1 = lv_obj_create(ui->Home_home, NULL);
    lv_obj_set_style_local_bg_opa(ui->Home_home_home_1, LV_OBJ_PART_MAIN, LV_STATE_DEFAULT, 0);
    lv_obj_set_style_local_border_width(ui->Home_home_home_1, LV_OBJ_PART_MAIN, LV_STATE_FOCUSED, 0);
    lv_obj_set_pos(ui->Home_home_home_1, 0, 0 * 240);
    lv_obj_set_size(ui->Home_home_home_1, 240, 240);
    lv_tileview_add_element(ui->Home_home, ui->Home_home_home_1);

    // Write codes Home_home1_lline_h
    ui->Home_home1_lline_h = lv_line_create(ui->Home_home_home_1, NULL);

    // Write style LV_LINE_PART_MAIN for Home_home1_lline_h
    static lv_style_t style_Home_home1_lline_h_main;
    lv_style_reset(&style_Home_home1_lline_h_main);

    // Write style state: LV_STATE_DEFAULT for style_Home_home1_lline_h_main
    lv_style_set_line_color(&style_Home_home1_lline_h_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
    lv_style_set_line_width(&style_Home_home1_lline_h_main, LV_STATE_DEFAULT, 3);
    lv_obj_add_style(ui->Home_home1_lline_h, LV_LINE_PART_MAIN, &style_Home_home1_lline_h_main);
    lv_obj_set_pos(ui->Home_home1_lline_h, 0, 110);
    lv_obj_set_size(ui->Home_home1_lline_h, 240, 10);
    lv_tileview_add_element(ui->Home_home, ui->Home_home1_lline_h);
    static lv_point_t Home_home1_lline_h[] = {{0, 0}, {240, 0}};
    lv_line_set_points(ui->Home_home1_lline_h, Home_home1_lline_h, 2);

    // Write codes Home_home1_line_w
    ui->Home_home1_line_w = lv_line_create(ui->Home_home_home_1, NULL);

    // Write style LV_LINE_PART_MAIN for Home_home1_line_w
    static lv_style_t style_Home_home1_line_w_main;
    lv_style_reset(&style_Home_home1_line_w_main);

    // Write style state: LV_STATE_DEFAULT for style_Home_home1_line_w_main
    lv_style_set_line_color(&style_Home_home1_line_w_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
    lv_style_set_line_width(&style_Home_home1_line_w_main, LV_STATE_DEFAULT, 3);
    lv_obj_add_style(ui->Home_home1_line_w, LV_LINE_PART_MAIN, &style_Home_home1_line_w_main);
    lv_obj_set_pos(ui->Home_home1_line_w, 110, 0);
    lv_obj_set_size(ui->Home_home1_line_w, 10, 240);
    lv_tileview_add_element(ui->Home_home, ui->Home_home1_line_w);
    static lv_point_t Home_home1_line_w[] = {{9, 0}, {9, 225}};
    lv_line_set_points(ui->Home_home1_line_w, Home_home1_line_w, 2);

    // Write codes Home_home1_lline_h2
    ui->Home_home1_lline_h2 = lv_line_create(ui->Home_home_home_1, NULL);

    // Write style LV_LINE_PART_MAIN for Home_home1_lline_h2
    static lv_style_t style_Home_home1_lline_h2_main;
    lv_style_reset(&style_Home_home1_lline_h2_main);

    // Write style state: LV_STATE_DEFAULT for style_Home_home1_lline_h2_main
    lv_style_set_line_color(&style_Home_home1_lline_h2_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
    lv_style_set_line_width(&style_Home_home1_lline_h2_main, LV_STATE_DEFAULT, 3);
    lv_obj_add_style(ui->Home_home1_lline_h2, LV_LINE_PART_MAIN, &style_Home_home1_lline_h2_main);
    lv_obj_set_pos(ui->Home_home1_lline_h2, 0, 220);
    lv_obj_set_size(ui->Home_home1_lline_h2, 240, 10);
    lv_tileview_add_element(ui->Home_home, ui->Home_home1_lline_h2);
    static lv_point_t Home_home1_lline_h2[] = {{0, 3}, {240, 3}};
    lv_line_set_points(ui->Home_home1_lline_h2, Home_home1_lline_h2, 2);

    // Write codes Home_home_photo
    ui->Home_home_photo = lv_imgbtn_create(ui->Home_home_home_1, NULL);

    // Write style LV_IMGBTN_PART_MAIN for Home_home_photo
    static lv_style_t style_Home_home_photo_main;
    lv_style_reset(&style_Home_home_photo_main);

    // Write style state: LV_STATE_DEFAULT for style_Home_home_photo_main
    lv_style_set_text_color(&style_Home_home_photo_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
    lv_style_set_image_recolor(&style_Home_home_photo_main, LV_STATE_DEFAULT, lv_color_make(0x2d, 0x3d, 0xb9));
    lv_style_set_image_recolor_opa(&style_Home_home_photo_main, LV_STATE_DEFAULT, 0);
    lv_style_set_image_opa(&style_Home_home_photo_main, LV_STATE_DEFAULT, 255);

    // Write style state: LV_STATE_PRESSED for style_Home_home_photo_main
    lv_style_set_text_color(&style_Home_home_photo_main, LV_STATE_PRESSED, lv_color_make(0xFF, 0x33, 0xFF));
    lv_style_set_image_recolor(&style_Home_home_photo_main, LV_STATE_PRESSED, lv_color_make(0x00, 0x00, 0x00));
    lv_style_set_image_recolor_opa(&style_Home_home_photo_main, LV_STATE_PRESSED, 0);

    // Write style state: LV_STATE_CHECKED for style_Home_home_photo_main
    lv_style_set_text_color(&style_Home_home_photo_main, LV_STATE_CHECKED, lv_color_make(0xFF, 0x33, 0xFF));
    lv_style_set_image_recolor(&style_Home_home_photo_main, LV_STATE_CHECKED, lv_color_make(0x00, 0x00, 0x00));
    lv_style_set_image_recolor_opa(&style_Home_home_photo_main, LV_STATE_CHECKED, 0);
    lv_obj_add_style(ui->Home_home_photo, LV_IMGBTN_PART_MAIN, &style_Home_home_photo_main);
    lv_obj_set_pos(ui->Home_home_photo, 30, 32);
    lv_obj_set_size(ui->Home_home_photo, 60, 42);
    lv_tileview_add_element(ui->Home_home, ui->Home_home_photo);
    lv_imgbtn_set_src(ui->Home_home_photo, LV_BTN_STATE_RELEASED, &_main_photo_alpha_60x42);
    lv_imgbtn_set_checkable(ui->Home_home_photo, true);

    // Write codes Home_home_gesture
    ui->Home_home_gesture = lv_imgbtn_create(ui->Home_home_home_1, NULL);

    // Write style LV_IMGBTN_PART_MAIN for Home_home_gesture
    static lv_style_t style_Home_home_gesture_main;
    lv_style_reset(&style_Home_home_gesture_main);

    // Write style state: LV_STATE_DEFAULT for style_Home_home_gesture_main
    lv_style_set_text_color(&style_Home_home_gesture_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
    lv_style_set_image_recolor(&style_Home_home_gesture_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
    lv_style_set_image_recolor_opa(&style_Home_home_gesture_main, LV_STATE_DEFAULT, 0);
    lv_style_set_image_opa(&style_Home_home_gesture_main, LV_STATE_DEFAULT, 255);

    // Write style state: LV_STATE_PRESSED for style_Home_home_gesture_main
    lv_style_set_text_color(&style_Home_home_gesture_main, LV_STATE_PRESSED, lv_color_make(0xFF, 0x33, 0xFF));
    lv_style_set_image_recolor(&style_Home_home_gesture_main, LV_STATE_PRESSED, lv_color_make(0x00, 0x00, 0x00));
    lv_style_set_image_recolor_opa(&style_Home_home_gesture_main, LV_STATE_PRESSED, 0);

    // Write style state: LV_STATE_CHECKED for style_Home_home_gesture_main
    lv_style_set_text_color(&style_Home_home_gesture_main, LV_STATE_CHECKED, lv_color_make(0xFF, 0x33, 0xFF));
    lv_style_set_image_recolor(&style_Home_home_gesture_main, LV_STATE_CHECKED, lv_color_make(0x00, 0x00, 0x00));
    lv_style_set_image_recolor_opa(&style_Home_home_gesture_main, LV_STATE_CHECKED, 0);
    lv_obj_add_style(ui->Home_home_gesture, LV_IMGBTN_PART_MAIN, &style_Home_home_gesture_main);
    lv_obj_set_pos(ui->Home_home_gesture, 152, 143);
    lv_obj_set_size(ui->Home_home_gesture, 47, 47);
    lv_tileview_add_element(ui->Home_home, ui->Home_home_gesture);
    lv_imgbtn_set_src(ui->Home_home_gesture, LV_BTN_STATE_RELEASED, &_main_shoushi_alpha_47x47);
    lv_imgbtn_set_checkable(ui->Home_home_gesture, true);

    // Write codes Home_home_face_s
    ui->Home_home_face_s = lv_imgbtn_create(ui->Home_home_home_1, NULL);

    // Write style LV_IMGBTN_PART_MAIN for Home_home_face_s
    static lv_style_t style_Home_home_face_s_main;
    lv_style_reset(&style_Home_home_face_s_main);

    // Write style state: LV_STATE_DEFAULT for style_Home_home_face_s_main
    lv_style_set_text_color(&style_Home_home_face_s_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
    lv_style_set_image_recolor(&style_Home_home_face_s_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
    lv_style_set_image_recolor_opa(&style_Home_home_face_s_main, LV_STATE_DEFAULT, 0);
    lv_style_set_image_opa(&style_Home_home_face_s_main, LV_STATE_DEFAULT, 255);

    // Write style state: LV_STATE_PRESSED for style_Home_home_face_s_main
    lv_style_set_text_color(&style_Home_home_face_s_main, LV_STATE_PRESSED, lv_color_make(0xFF, 0x33, 0xFF));
    lv_style_set_image_recolor(&style_Home_home_face_s_main, LV_STATE_PRESSED, lv_color_make(0x00, 0x00, 0x00));
    lv_style_set_image_recolor_opa(&style_Home_home_face_s_main, LV_STATE_PRESSED, 0);

    // Write style state: LV_STATE_CHECKED for style_Home_home_face_s_main
    lv_style_set_text_color(&style_Home_home_face_s_main, LV_STATE_CHECKED, lv_color_make(0xFF, 0x33, 0xFF));
    lv_style_set_image_recolor(&style_Home_home_face_s_main, LV_STATE_CHECKED, lv_color_make(0x00, 0x00, 0x00));
    lv_style_set_image_recolor_opa(&style_Home_home_face_s_main, LV_STATE_CHECKED, 0);
    lv_obj_add_style(ui->Home_home_face_s, LV_IMGBTN_PART_MAIN, &style_Home_home_face_s_main);
    lv_obj_set_pos(ui->Home_home_face_s, 33, 143);
    lv_obj_set_size(ui->Home_home_face_s, 49, 49);
    lv_tileview_add_element(ui->Home_home, ui->Home_home_face_s);
    lv_imgbtn_set_src(ui->Home_home_face_s, LV_BTN_STATE_RELEASED, &_main_face_s_alpha_49x49);
    lv_imgbtn_set_checkable(ui->Home_home_face_s, true);

    // Write codes Home_home_face
    ui->Home_home_face = lv_imgbtn_create(ui->Home_home_home_1, NULL);

    // Write style LV_IMGBTN_PART_MAIN for Home_home_face
    static lv_style_t style_Home_home_face_main;
    lv_style_reset(&style_Home_home_face_main);

    // Write style state: LV_STATE_DEFAULT for style_Home_home_face_main
    lv_style_set_text_color(&style_Home_home_face_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
    lv_style_set_image_recolor(&style_Home_home_face_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
    lv_style_set_image_recolor_opa(&style_Home_home_face_main, LV_STATE_DEFAULT, 0);
    lv_style_set_image_opa(&style_Home_home_face_main, LV_STATE_DEFAULT, 255);

    // Write style state: LV_STATE_PRESSED for style_Home_home_face_main
    lv_style_set_text_color(&style_Home_home_face_main, LV_STATE_PRESSED, lv_color_make(0xFF, 0x33, 0xFF));
    lv_style_set_image_recolor(&style_Home_home_face_main, LV_STATE_PRESSED, lv_color_make(0x00, 0x00, 0x00));
    lv_style_set_image_recolor_opa(&style_Home_home_face_main, LV_STATE_PRESSED, 0);

    // Write style state: LV_STATE_CHECKED for style_Home_home_face_main
    lv_style_set_text_color(&style_Home_home_face_main, LV_STATE_CHECKED, lv_color_make(0xFF, 0x33, 0xFF));
    lv_style_set_image_recolor(&style_Home_home_face_main, LV_STATE_CHECKED, lv_color_make(0x00, 0x00, 0x00));
    lv_style_set_image_recolor_opa(&style_Home_home_face_main, LV_STATE_CHECKED, 0);
    lv_obj_add_style(ui->Home_home_face, LV_IMGBTN_PART_MAIN, &style_Home_home_face_main);
    lv_obj_set_pos(ui->Home_home_face, 152, 30);
    lv_obj_set_size(ui->Home_home_face, 49, 49);
    lv_tileview_add_element(ui->Home_home, ui->Home_home_face);
    lv_imgbtn_set_src(ui->Home_home_face, LV_BTN_STATE_RELEASED, &_main_face_alpha_49x49);
    lv_imgbtn_set_checkable(ui->Home_home_face, true);

    // Write codes Home_label_photo
    ui->Home_label_photo = lv_label_create(ui->Home_home_home_1, NULL);
    lv_label_set_text(ui->Home_label_photo, "实时拍照");
    lv_label_set_long_mode(ui->Home_label_photo, LV_LABEL_LONG_BREAK);
    lv_label_set_align(ui->Home_label_photo, LV_LABEL_ALIGN_CENTER);

    // Write style LV_LABEL_PART_MAIN for Home_label_photo
    static lv_style_t style_Home_label_photo_main;
    lv_style_reset(&style_Home_label_photo_main);

    // Write style state: LV_STATE_DEFAULT for style_Home_label_photo_main
    lv_style_set_radius(&style_Home_label_photo_main, LV_STATE_DEFAULT, 0);
    lv_style_set_bg_color(&style_Home_label_photo_main, LV_STATE_DEFAULT, lv_color_make(0x3c, 0x3c, 0x3c));
    lv_style_set_bg_grad_color(&style_Home_label_photo_main, LV_STATE_DEFAULT, lv_color_make(0x3c, 0x3c, 0x3c));
    lv_style_set_bg_grad_dir(&style_Home_label_photo_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
    lv_style_set_bg_opa(&style_Home_label_photo_main, LV_STATE_DEFAULT, 255);
    lv_style_set_text_color(&style_Home_label_photo_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
    lv_style_set_text_font(&style_Home_label_photo_main, LV_STATE_DEFAULT, &lv_font_simsun_15);
    lv_style_set_text_letter_space(&style_Home_label_photo_main, LV_STATE_DEFAULT, 2);
    lv_style_set_pad_left(&style_Home_label_photo_main, LV_STATE_DEFAULT, 0);
    lv_style_set_pad_right(&style_Home_label_photo_main, LV_STATE_DEFAULT, 0);
    lv_style_set_pad_top(&style_Home_label_photo_main, LV_STATE_DEFAULT, 0);
    lv_style_set_pad_bottom(&style_Home_label_photo_main, LV_STATE_DEFAULT, 0);
    lv_obj_add_style(ui->Home_label_photo, LV_LABEL_PART_MAIN, &style_Home_label_photo_main);
    lv_obj_set_pos(ui->Home_label_photo, 25, 90);
    lv_obj_set_size(ui->Home_label_photo, 69, 0);
    lv_tileview_add_element(ui->Home_home, ui->Home_label_photo);

    // Write codes Home_label_face
    ui->Home_label_face = lv_label_create(ui->Home_home_home_1, NULL);
    lv_label_set_text(ui->Home_label_face, "人脸检测");
    lv_label_set_long_mode(ui->Home_label_face, LV_LABEL_LONG_BREAK);
    lv_label_set_align(ui->Home_label_face, LV_LABEL_ALIGN_CENTER);

    // Write style LV_LABEL_PART_MAIN for Home_label_face
    static lv_style_t style_Home_label_face_main;
    lv_style_reset(&style_Home_label_face_main);

    // Write style state: LV_STATE_DEFAULT for style_Home_label_face_main
    lv_style_set_radius(&style_Home_label_face_main, LV_STATE_DEFAULT, 0);
    lv_style_set_bg_color(&style_Home_label_face_main, LV_STATE_DEFAULT, lv_color_make(0x3c, 0x3c, 0x3c));
    lv_style_set_bg_grad_color(&style_Home_label_face_main, LV_STATE_DEFAULT, lv_color_make(0x3c, 0x3c, 0x3c));
    lv_style_set_bg_grad_dir(&style_Home_label_face_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
    lv_style_set_bg_opa(&style_Home_label_face_main, LV_STATE_DEFAULT, 255);
    lv_style_set_text_color(&style_Home_label_face_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
    lv_style_set_text_font(&style_Home_label_face_main, LV_STATE_DEFAULT, &lv_font_simsun_15);
    lv_style_set_text_letter_space(&style_Home_label_face_main, LV_STATE_DEFAULT, 2);
    lv_style_set_pad_left(&style_Home_label_face_main, LV_STATE_DEFAULT, 0);
    lv_style_set_pad_right(&style_Home_label_face_main, LV_STATE_DEFAULT, 0);
    lv_style_set_pad_top(&style_Home_label_face_main, LV_STATE_DEFAULT, 0);
    lv_style_set_pad_bottom(&style_Home_label_face_main, LV_STATE_DEFAULT, 0);
    lv_obj_add_style(ui->Home_label_face, LV_LABEL_PART_MAIN, &style_Home_label_face_main);
    lv_obj_set_pos(ui->Home_label_face, 143, 90);
    lv_obj_set_size(ui->Home_label_face, 68, 0);
    lv_tileview_add_element(ui->Home_home, ui->Home_label_face);

    // Write codes Home_label_face_s
    ui->Home_label_face_s = lv_label_create(ui->Home_home_home_1, NULL);
    lv_label_set_text(ui->Home_label_face_s, "人脸学习");
    lv_label_set_long_mode(ui->Home_label_face_s, LV_LABEL_LONG_BREAK);
    lv_label_set_align(ui->Home_label_face_s, LV_LABEL_ALIGN_CENTER);

    // Write style LV_LABEL_PART_MAIN for Home_label_face_s
    static lv_style_t style_Home_label_face_s_main;
    lv_style_reset(&style_Home_label_face_s_main);

    // Write style state: LV_STATE_DEFAULT for style_Home_label_face_s_main
    lv_style_set_radius(&style_Home_label_face_s_main, LV_STATE_DEFAULT, 0);
    lv_style_set_bg_color(&style_Home_label_face_s_main, LV_STATE_DEFAULT, lv_color_make(0x3c, 0x3c, 0x3c));
    lv_style_set_bg_grad_color(&style_Home_label_face_s_main, LV_STATE_DEFAULT, lv_color_make(0x3c, 0x3c, 0x3c));
    lv_style_set_bg_grad_dir(&style_Home_label_face_s_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
    lv_style_set_bg_opa(&style_Home_label_face_s_main, LV_STATE_DEFAULT, 255);
    lv_style_set_text_color(&style_Home_label_face_s_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
    lv_style_set_text_font(&style_Home_label_face_s_main, LV_STATE_DEFAULT, &lv_font_simsun_15);
    lv_style_set_text_letter_space(&style_Home_label_face_s_main, LV_STATE_DEFAULT, 2);
    lv_style_set_pad_left(&style_Home_label_face_s_main, LV_STATE_DEFAULT, 0);
    lv_style_set_pad_right(&style_Home_label_face_s_main, LV_STATE_DEFAULT, 0);
    lv_style_set_pad_top(&style_Home_label_face_s_main, LV_STATE_DEFAULT, 0);
    lv_style_set_pad_bottom(&style_Home_label_face_s_main, LV_STATE_DEFAULT, 0);
    lv_obj_add_style(ui->Home_label_face_s, LV_LABEL_PART_MAIN, &style_Home_label_face_s_main);
    lv_obj_set_pos(ui->Home_label_face_s, 25, 203);
    lv_obj_set_size(ui->Home_label_face_s, 68, 0);
    lv_tileview_add_element(ui->Home_home, ui->Home_label_face_s);

    // Write codes Home_label_gesture
    ui->Home_label_gesture = lv_label_create(ui->Home_home_home_1, NULL);
    lv_label_set_text(ui->Home_label_gesture, "手势识别");
    lv_label_set_long_mode(ui->Home_label_gesture, LV_LABEL_LONG_BREAK);
    lv_label_set_align(ui->Home_label_gesture, LV_LABEL_ALIGN_CENTER);

    // Write style LV_LABEL_PART_MAIN for Home_label_gesture
    static lv_style_t style_Home_label_gesture_main;
    lv_style_reset(&style_Home_label_gesture_main);

    // Write style state: LV_STATE_DEFAULT for style_Home_label_gesture_main
    lv_style_set_radius(&style_Home_label_gesture_main, LV_STATE_DEFAULT, 0);
    lv_style_set_bg_color(&style_Home_label_gesture_main, LV_STATE_DEFAULT, lv_color_make(0x3c, 0x3c, 0x3c));
    lv_style_set_bg_grad_color(&style_Home_label_gesture_main, LV_STATE_DEFAULT, lv_color_make(0x3c, 0x3c, 0x3c));
    lv_style_set_bg_grad_dir(&style_Home_label_gesture_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
    lv_style_set_bg_opa(&style_Home_label_gesture_main, LV_STATE_DEFAULT, 255);
    lv_style_set_text_color(&style_Home_label_gesture_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
    lv_style_set_text_font(&style_Home_label_gesture_main, LV_STATE_DEFAULT, &lv_font_simsun_15);
    lv_style_set_text_letter_space(&style_Home_label_gesture_main, LV_STATE_DEFAULT, 2);
    lv_style_set_pad_left(&style_Home_label_gesture_main, LV_STATE_DEFAULT, 0);
    lv_style_set_pad_right(&style_Home_label_gesture_main, LV_STATE_DEFAULT, 0);
    lv_style_set_pad_top(&style_Home_label_gesture_main, LV_STATE_DEFAULT, 0);
    lv_style_set_pad_bottom(&style_Home_label_gesture_main, LV_STATE_DEFAULT, 0);
    lv_obj_add_style(ui->Home_label_gesture, LV_LABEL_PART_MAIN, &style_Home_label_gesture_main);
    lv_obj_set_pos(ui->Home_label_gesture, 143, 203);
    lv_obj_set_size(ui->Home_label_gesture, 69, 0);
    lv_tileview_add_element(ui->Home_home, ui->Home_label_gesture);

    // Write codes Home_home_home_2
    ui->Home_home_home_2 = lv_obj_create(ui->Home_home, NULL);
    lv_obj_set_style_local_bg_opa(ui->Home_home_home_2, LV_OBJ_PART_MAIN, LV_STATE_DEFAULT, 0);
    lv_obj_set_style_local_border_width(ui->Home_home_home_2, LV_OBJ_PART_MAIN, LV_STATE_FOCUSED, 0);
    lv_obj_set_pos(ui->Home_home_home_2, 0, 1 * 240);
    lv_obj_set_size(ui->Home_home_home_2, 240, 240);
    lv_tileview_add_element(ui->Home_home, ui->Home_home_home_2);

    // Write codes Home_home2_line_w
    ui->Home_home2_line_w = lv_line_create(ui->Home_home_home_2, NULL);

    // Write style LV_LINE_PART_MAIN for Home_home2_line_w
    static lv_style_t style_Home_home2_line_w_main;
    lv_style_reset(&style_Home_home2_line_w_main);

    // Write style state: LV_STATE_DEFAULT for style_Home_home2_line_w_main
    lv_style_set_line_color(&style_Home_home2_line_w_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
    lv_style_set_line_width(&style_Home_home2_line_w_main, LV_STATE_DEFAULT, 3);
    lv_obj_add_style(ui->Home_home2_line_w, LV_LINE_PART_MAIN, &style_Home_home2_line_w_main);
    lv_obj_set_pos(ui->Home_home2_line_w, 110, 0);
    lv_obj_set_size(ui->Home_home2_line_w, 10, 240);
    lv_tileview_add_element(ui->Home_home, ui->Home_home2_line_w);
    static lv_point_t Home_home2_line_w[] = {{9, 0}, {9, 225}};
    lv_line_set_points(ui->Home_home2_line_w, Home_home2_line_w, 2);

    // Write codes Home_label_tagcode
    ui->Home_label_tagcode = lv_label_create(ui->Home_home_home_2, NULL);
    lv_label_set_text(ui->Home_label_tagcode, "标签码识别");
    lv_label_set_long_mode(ui->Home_label_tagcode, LV_LABEL_LONG_BREAK);
    lv_label_set_align(ui->Home_label_tagcode, LV_LABEL_ALIGN_CENTER);

    // Write style LV_LABEL_PART_MAIN for Home_label_tagcode
    static lv_style_t style_Home_label_tagcode_main;
    lv_style_reset(&style_Home_label_tagcode_main);

    // Write style state: LV_STATE_DEFAULT for style_Home_label_tagcode_main
    lv_style_set_radius(&style_Home_label_tagcode_main, LV_STATE_DEFAULT, 0);
    lv_style_set_bg_color(&style_Home_label_tagcode_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
    lv_style_set_bg_grad_color(&style_Home_label_tagcode_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
    lv_style_set_bg_grad_dir(&style_Home_label_tagcode_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
    lv_style_set_bg_opa(&style_Home_label_tagcode_main, LV_STATE_DEFAULT, 0);
    lv_style_set_text_color(&style_Home_label_tagcode_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
    lv_style_set_text_font(&style_Home_label_tagcode_main, LV_STATE_DEFAULT, &lv_font_simsun_15);
    lv_style_set_text_letter_space(&style_Home_label_tagcode_main, LV_STATE_DEFAULT, 2);
    lv_style_set_pad_left(&style_Home_label_tagcode_main, LV_STATE_DEFAULT, 0);
    lv_style_set_pad_right(&style_Home_label_tagcode_main, LV_STATE_DEFAULT, 0);
    lv_style_set_pad_top(&style_Home_label_tagcode_main, LV_STATE_DEFAULT, 0);
    lv_style_set_pad_bottom(&style_Home_label_tagcode_main, LV_STATE_DEFAULT, 0);
    lv_obj_add_style(ui->Home_label_tagcode, LV_LABEL_PART_MAIN, &style_Home_label_tagcode_main);
    lv_obj_set_pos(ui->Home_label_tagcode, 135, 203);
    lv_obj_set_size(ui->Home_label_tagcode, 87, 0);
    lv_tileview_add_element(ui->Home_home, ui->Home_label_tagcode);

    // Write codes Home_label_qrcode
    ui->Home_label_qrcode = lv_label_create(ui->Home_home_home_2, NULL);
    lv_label_set_text(ui->Home_label_qrcode, "二维码识别");
    lv_label_set_long_mode(ui->Home_label_qrcode, LV_LABEL_LONG_BREAK);
    lv_label_set_align(ui->Home_label_qrcode, LV_LABEL_ALIGN_CENTER);

    // Write style LV_LABEL_PART_MAIN for Home_label_qrcode
    static lv_style_t style_Home_label_qrcode_main;
    lv_style_reset(&style_Home_label_qrcode_main);

    // Write style state: LV_STATE_DEFAULT for style_Home_label_qrcode_main
    lv_style_set_radius(&style_Home_label_qrcode_main, LV_STATE_DEFAULT, 0);
    lv_style_set_bg_color(&style_Home_label_qrcode_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
    lv_style_set_bg_grad_color(&style_Home_label_qrcode_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
    lv_style_set_bg_grad_dir(&style_Home_label_qrcode_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
    lv_style_set_bg_opa(&style_Home_label_qrcode_main, LV_STATE_DEFAULT, 0);
    lv_style_set_text_color(&style_Home_label_qrcode_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
    lv_style_set_text_font(&style_Home_label_qrcode_main, LV_STATE_DEFAULT, &lv_font_simsun_15);
    lv_style_set_text_letter_space(&style_Home_label_qrcode_main, LV_STATE_DEFAULT, 2);
    lv_style_set_pad_left(&style_Home_label_qrcode_main, LV_STATE_DEFAULT, 0);
    lv_style_set_pad_right(&style_Home_label_qrcode_main, LV_STATE_DEFAULT, 0);
    lv_style_set_pad_top(&style_Home_label_qrcode_main, LV_STATE_DEFAULT, 0);
    lv_style_set_pad_bottom(&style_Home_label_qrcode_main, LV_STATE_DEFAULT, 0);
    lv_obj_add_style(ui->Home_label_qrcode, LV_LABEL_PART_MAIN, &style_Home_label_qrcode_main);
    lv_obj_set_pos(ui->Home_label_qrcode, 18, 203);
    lv_obj_set_size(ui->Home_label_qrcode, 85, 0);
    lv_tileview_add_element(ui->Home_home, ui->Home_label_qrcode);

    // Write codes Home_label_color_s
    ui->Home_label_color_s = lv_label_create(ui->Home_home_home_2, NULL);
    lv_label_set_text(ui->Home_label_color_s, "颜色学习");
    lv_label_set_long_mode(ui->Home_label_color_s, LV_LABEL_LONG_BREAK);
    lv_label_set_align(ui->Home_label_color_s, LV_LABEL_ALIGN_CENTER);

    // Write style LV_LABEL_PART_MAIN for Home_label_color_s
    static lv_style_t style_Home_label_color_s_main;
    lv_style_reset(&style_Home_label_color_s_main);

    // Write style state: LV_STATE_DEFAULT for style_Home_label_color_s_main
    lv_style_set_radius(&style_Home_label_color_s_main, LV_STATE_DEFAULT, 0);
    lv_style_set_bg_color(&style_Home_label_color_s_main, LV_STATE_DEFAULT, lv_color_make(0x3c, 0x3c, 0x3c));
    lv_style_set_bg_grad_color(&style_Home_label_color_s_main, LV_STATE_DEFAULT, lv_color_make(0x3c, 0x3c, 0x3c));
    lv_style_set_bg_grad_dir(&style_Home_label_color_s_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
    lv_style_set_bg_opa(&style_Home_label_color_s_main, LV_STATE_DEFAULT, 0);
    lv_style_set_text_color(&style_Home_label_color_s_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
    lv_style_set_text_font(&style_Home_label_color_s_main, LV_STATE_DEFAULT, &lv_font_simsun_15);
    lv_style_set_text_letter_space(&style_Home_label_color_s_main, LV_STATE_DEFAULT, 2);
    lv_style_set_pad_left(&style_Home_label_color_s_main, LV_STATE_DEFAULT, 0);
    lv_style_set_pad_right(&style_Home_label_color_s_main, LV_STATE_DEFAULT, 0);
    lv_style_set_pad_top(&style_Home_label_color_s_main, LV_STATE_DEFAULT, 0);
    lv_style_set_pad_bottom(&style_Home_label_color_s_main, LV_STATE_DEFAULT, 0);
    lv_obj_add_style(ui->Home_label_color_s, LV_LABEL_PART_MAIN, &style_Home_label_color_s_main);
    lv_obj_set_pos(ui->Home_label_color_s, 143, 90);
    lv_obj_set_size(ui->Home_label_color_s, 68, 0);
    lv_tileview_add_element(ui->Home_home, ui->Home_label_color_s);

    // Write codes Home_label_color
    ui->Home_label_color = lv_label_create(ui->Home_home_home_2, NULL);
    lv_label_set_text(ui->Home_label_color, "颜色检测");
    lv_label_set_long_mode(ui->Home_label_color, LV_LABEL_LONG_BREAK);
    lv_label_set_align(ui->Home_label_color, LV_LABEL_ALIGN_CENTER);

    // Write style LV_LABEL_PART_MAIN for Home_label_color
    static lv_style_t style_Home_label_color_main;
    lv_style_reset(&style_Home_label_color_main);

    // Write style state: LV_STATE_DEFAULT for style_Home_label_color_main
    lv_style_set_radius(&style_Home_label_color_main, LV_STATE_DEFAULT, 0);
    lv_style_set_bg_color(&style_Home_label_color_main, LV_STATE_DEFAULT, lv_color_make(0x3c, 0x3c, 0x3c));
    lv_style_set_bg_grad_color(&style_Home_label_color_main, LV_STATE_DEFAULT, lv_color_make(0x3c, 0x3c, 0x3c));
    lv_style_set_bg_grad_dir(&style_Home_label_color_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
    lv_style_set_bg_opa(&style_Home_label_color_main, LV_STATE_DEFAULT, 0);
    lv_style_set_text_color(&style_Home_label_color_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
    lv_style_set_text_font(&style_Home_label_color_main, LV_STATE_DEFAULT, &lv_font_simsun_15);
    lv_style_set_text_letter_space(&style_Home_label_color_main, LV_STATE_DEFAULT, 2);
    lv_style_set_pad_left(&style_Home_label_color_main, LV_STATE_DEFAULT, 0);
    lv_style_set_pad_right(&style_Home_label_color_main, LV_STATE_DEFAULT, 0);
    lv_style_set_pad_top(&style_Home_label_color_main, LV_STATE_DEFAULT, 0);
    lv_style_set_pad_bottom(&style_Home_label_color_main, LV_STATE_DEFAULT, 0);
    lv_obj_add_style(ui->Home_label_color, LV_LABEL_PART_MAIN, &style_Home_label_color_main);
    lv_obj_set_pos(ui->Home_label_color, 25, 90);
    lv_obj_set_size(ui->Home_label_color, 69, 0);
    lv_tileview_add_element(ui->Home_home, ui->Home_label_color);

    // Write codes Home_home2_lline_h2
    ui->Home_home2_lline_h2 = lv_line_create(ui->Home_home_home_2, NULL);

    // Write style LV_LINE_PART_MAIN for Home_home2_lline_h2
    static lv_style_t style_Home_home2_lline_h2_main;
    lv_style_reset(&style_Home_home2_lline_h2_main);

    // Write style state: LV_STATE_DEFAULT for style_Home_home2_lline_h2_main
    lv_style_set_line_color(&style_Home_home2_lline_h2_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
    lv_style_set_line_width(&style_Home_home2_lline_h2_main, LV_STATE_DEFAULT, 3);
    lv_obj_add_style(ui->Home_home2_lline_h2, LV_LINE_PART_MAIN, &style_Home_home2_lline_h2_main);
    lv_obj_set_pos(ui->Home_home2_lline_h2, 0, 220);
    lv_obj_set_size(ui->Home_home2_lline_h2, 240, 10);
    lv_tileview_add_element(ui->Home_home, ui->Home_home2_lline_h2);
    static lv_point_t Home_home2_lline_h2[] = {{0, 3}, {240, 3}};
    lv_line_set_points(ui->Home_home2_lline_h2, Home_home2_lline_h2, 2);

    // Write codes Home_home2_line_h
    ui->Home_home2_line_h = lv_line_create(ui->Home_home_home_2, NULL);

    // Write style LV_LINE_PART_MAIN for Home_home2_line_h
    static lv_style_t style_Home_home2_line_h_main;
    lv_style_reset(&style_Home_home2_line_h_main);

    // Write style state: LV_STATE_DEFAULT for style_Home_home2_line_h_main
    lv_style_set_line_color(&style_Home_home2_line_h_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
    lv_style_set_line_width(&style_Home_home2_line_h_main, LV_STATE_DEFAULT, 3);
    lv_obj_add_style(ui->Home_home2_line_h, LV_LINE_PART_MAIN, &style_Home_home2_line_h_main);
    lv_obj_set_pos(ui->Home_home2_line_h, 0, 110);
    lv_obj_set_size(ui->Home_home2_line_h, 240, 10);
    lv_tileview_add_element(ui->Home_home, ui->Home_home2_line_h);
    static lv_point_t Home_home2_line_h[] = {{0, 0}, {240, 0}};
    lv_line_set_points(ui->Home_home2_line_h, Home_home2_line_h, 2);

    // Write codes Home_hom_color
    ui->Home_hom_color = lv_imgbtn_create(ui->Home_home_home_2, NULL);

    // Write style LV_IMGBTN_PART_MAIN for Home_hom_color
    static lv_style_t style_Home_hom_color_main;
    lv_style_reset(&style_Home_hom_color_main);

    // Write style state: LV_STATE_DEFAULT for style_Home_hom_color_main
    lv_style_set_text_color(&style_Home_hom_color_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
    lv_style_set_image_recolor(&style_Home_hom_color_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
    lv_style_set_image_recolor_opa(&style_Home_hom_color_main, LV_STATE_DEFAULT, 0);
    lv_style_set_image_opa(&style_Home_hom_color_main, LV_STATE_DEFAULT, 255);

    // Write style state: LV_STATE_PRESSED for style_Home_hom_color_main
    lv_style_set_text_color(&style_Home_hom_color_main, LV_STATE_PRESSED, lv_color_make(0xFF, 0x33, 0xFF));
    lv_style_set_image_recolor(&style_Home_hom_color_main, LV_STATE_PRESSED, lv_color_make(0x00, 0x00, 0x00));
    lv_style_set_image_recolor_opa(&style_Home_hom_color_main, LV_STATE_PRESSED, 0);

    // Write style state: LV_STATE_CHECKED for style_Home_hom_color_main
    lv_style_set_text_color(&style_Home_hom_color_main, LV_STATE_CHECKED, lv_color_make(0xFF, 0x33, 0xFF));
    lv_style_set_image_recolor(&style_Home_hom_color_main, LV_STATE_CHECKED, lv_color_make(0x00, 0x00, 0x00));
    lv_style_set_image_recolor_opa(&style_Home_hom_color_main, LV_STATE_CHECKED, 0);
    lv_obj_add_style(ui->Home_hom_color, LV_IMGBTN_PART_MAIN, &style_Home_hom_color_main);
    lv_obj_set_pos(ui->Home_hom_color, 32, 30);
    lv_obj_set_size(ui->Home_hom_color, 52, 49);
    lv_tileview_add_element(ui->Home_home, ui->Home_hom_color);
    lv_imgbtn_set_src(ui->Home_hom_color, LV_BTN_STATE_RELEASED, &_home_color_alpha_52x49);
    lv_imgbtn_set_checkable(ui->Home_hom_color, true);

    // Write codes Home_hom_tagcode
    ui->Home_hom_tagcode = lv_imgbtn_create(ui->Home_home_home_2, NULL);

    // Write style LV_IMGBTN_PART_MAIN for Home_hom_tagcode
    static lv_style_t style_Home_hom_tagcode_main;
    lv_style_reset(&style_Home_hom_tagcode_main);

    // Write style state: LV_STATE_DEFAULT for style_Home_hom_tagcode_main
    lv_style_set_text_color(&style_Home_hom_tagcode_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
    lv_style_set_image_recolor(&style_Home_hom_tagcode_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
    lv_style_set_image_recolor_opa(&style_Home_hom_tagcode_main, LV_STATE_DEFAULT, 0);
    lv_style_set_image_opa(&style_Home_hom_tagcode_main, LV_STATE_DEFAULT, 255);

    // Write style state: LV_STATE_PRESSED for style_Home_hom_tagcode_main
    lv_style_set_text_color(&style_Home_hom_tagcode_main, LV_STATE_PRESSED, lv_color_make(0xFF, 0x33, 0xFF));
    lv_style_set_image_recolor(&style_Home_hom_tagcode_main, LV_STATE_PRESSED, lv_color_make(0x00, 0x00, 0x00));
    lv_style_set_image_recolor_opa(&style_Home_hom_tagcode_main, LV_STATE_PRESSED, 0);

    // Write style state: LV_STATE_CHECKED for style_Home_hom_tagcode_main
    lv_style_set_text_color(&style_Home_hom_tagcode_main, LV_STATE_CHECKED, lv_color_make(0xFF, 0x33, 0xFF));
    lv_style_set_image_recolor(&style_Home_hom_tagcode_main, LV_STATE_CHECKED, lv_color_make(0x00, 0x00, 0x00));
    lv_style_set_image_recolor_opa(&style_Home_hom_tagcode_main, LV_STATE_CHECKED, 0);
    lv_obj_add_style(ui->Home_hom_tagcode, LV_IMGBTN_PART_MAIN, &style_Home_hom_tagcode_main);
    lv_obj_set_pos(ui->Home_hom_tagcode, 155, 143);
    lv_obj_set_size(ui->Home_hom_tagcode, 47, 47);
    lv_tileview_add_element(ui->Home_home, ui->Home_hom_tagcode);
    lv_imgbtn_set_src(ui->Home_hom_tagcode, LV_BTN_STATE_RELEASED, &_home_tagcode_alpha_47x47);
    lv_imgbtn_set_checkable(ui->Home_hom_tagcode, true);

    // Write codes Home_home_qrcode
    ui->Home_home_qrcode = lv_imgbtn_create(ui->Home_home_home_2, NULL);

    // Write style LV_IMGBTN_PART_MAIN for Home_home_qrcode
    static lv_style_t style_Home_home_qrcode_main;
    lv_style_reset(&style_Home_home_qrcode_main);

    // Write style state: LV_STATE_DEFAULT for style_Home_home_qrcode_main
    lv_style_set_text_color(&style_Home_home_qrcode_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
    lv_style_set_image_recolor(&style_Home_home_qrcode_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
    lv_style_set_image_recolor_opa(&style_Home_home_qrcode_main, LV_STATE_DEFAULT, 0);
    lv_style_set_image_opa(&style_Home_home_qrcode_main, LV_STATE_DEFAULT, 255);

    // Write style state: LV_STATE_PRESSED for style_Home_home_qrcode_main
    lv_style_set_text_color(&style_Home_home_qrcode_main, LV_STATE_PRESSED, lv_color_make(0xFF, 0x33, 0xFF));
    lv_style_set_image_recolor(&style_Home_home_qrcode_main, LV_STATE_PRESSED, lv_color_make(0x00, 0x00, 0x00));
    lv_style_set_image_recolor_opa(&style_Home_home_qrcode_main, LV_STATE_PRESSED, 0);

    // Write style state: LV_STATE_CHECKED for style_Home_home_qrcode_main
    lv_style_set_text_color(&style_Home_home_qrcode_main, LV_STATE_CHECKED, lv_color_make(0xFF, 0x33, 0xFF));
    lv_style_set_image_recolor(&style_Home_home_qrcode_main, LV_STATE_CHECKED, lv_color_make(0x00, 0x00, 0x00));
    lv_style_set_image_recolor_opa(&style_Home_home_qrcode_main, LV_STATE_CHECKED, 0);
    lv_obj_add_style(ui->Home_home_qrcode, LV_IMGBTN_PART_MAIN, &style_Home_home_qrcode_main);
    lv_obj_set_pos(ui->Home_home_qrcode, 35, 143);
    lv_obj_set_size(ui->Home_home_qrcode, 47, 47);
    lv_tileview_add_element(ui->Home_home, ui->Home_home_qrcode);
    lv_imgbtn_set_src(ui->Home_home_qrcode, LV_BTN_STATE_RELEASED, &_home_qrcode_alpha_47x47);
    lv_imgbtn_set_checkable(ui->Home_home_qrcode, true);

    // Write codes Home_hom_colo_s
    ui->Home_hom_colo_s = lv_imgbtn_create(ui->Home_home_home_2, NULL);

    // Write style LV_IMGBTN_PART_MAIN for Home_hom_colo_s
    static lv_style_t style_Home_hom_colo_s_main;
    lv_style_reset(&style_Home_hom_colo_s_main);

    // Write style state: LV_STATE_DEFAULT for style_Home_hom_colo_s_main
    lv_style_set_text_color(&style_Home_hom_colo_s_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
    lv_style_set_image_recolor(&style_Home_hom_colo_s_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
    lv_style_set_image_recolor_opa(&style_Home_hom_colo_s_main, LV_STATE_DEFAULT, 0);
    lv_style_set_image_opa(&style_Home_hom_colo_s_main, LV_STATE_DEFAULT, 255);

    // Write style state: LV_STATE_PRESSED for style_Home_hom_colo_s_main
    lv_style_set_text_color(&style_Home_hom_colo_s_main, LV_STATE_PRESSED, lv_color_make(0xFF, 0x33, 0xFF));
    lv_style_set_image_recolor(&style_Home_hom_colo_s_main, LV_STATE_PRESSED, lv_color_make(0x00, 0x00, 0x00));
    lv_style_set_image_recolor_opa(&style_Home_hom_colo_s_main, LV_STATE_PRESSED, 0);

    // Write style state: LV_STATE_CHECKED for style_Home_hom_colo_s_main
    lv_style_set_text_color(&style_Home_hom_colo_s_main, LV_STATE_CHECKED, lv_color_make(0xFF, 0x33, 0xFF));
    lv_style_set_image_recolor(&style_Home_hom_colo_s_main, LV_STATE_CHECKED, lv_color_make(0x00, 0x00, 0x00));
    lv_style_set_image_recolor_opa(&style_Home_hom_colo_s_main, LV_STATE_CHECKED, 0);
    lv_obj_add_style(ui->Home_hom_colo_s, LV_IMGBTN_PART_MAIN, &style_Home_hom_colo_s_main);
    lv_obj_set_pos(ui->Home_hom_colo_s, 155, 30);
    lv_obj_set_size(ui->Home_hom_colo_s, 52, 50);
    lv_tileview_add_element(ui->Home_home, ui->Home_hom_colo_s);
    lv_imgbtn_set_src(ui->Home_hom_colo_s, LV_BTN_STATE_RELEASED, &_home_s_alpha_52x50);
    lv_imgbtn_set_checkable(ui->Home_hom_colo_s, true);

    // Write codes Home_home_home_3
    ui->Home_home_home_3 = lv_obj_create(ui->Home_home, NULL);
    lv_obj_set_style_local_bg_opa(ui->Home_home_home_3, LV_OBJ_PART_MAIN, LV_STATE_DEFAULT, 0);
    lv_obj_set_style_local_border_width(ui->Home_home_home_3, LV_OBJ_PART_MAIN, LV_STATE_FOCUSED, 0);
    lv_obj_set_pos(ui->Home_home_home_3, 0, 2 * 240);
    lv_obj_set_size(ui->Home_home_home_3, 240, 240);
    lv_tileview_add_element(ui->Home_home, ui->Home_home_home_3);

    // Write codes Home_imgbtn_5
    ui->Home_imgbtn_5 = lv_imgbtn_create(ui->Home_home_home_3, NULL);

    // Write style LV_IMGBTN_PART_MAIN for Home_imgbtn_5
    static lv_style_t style_Home_imgbtn_5_main;
    lv_style_reset(&style_Home_imgbtn_5_main);

    // Write style state: LV_STATE_DEFAULT for style_Home_imgbtn_5_main
    lv_style_set_text_color(&style_Home_imgbtn_5_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
    lv_style_set_image_recolor(&style_Home_imgbtn_5_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
    lv_style_set_image_recolor_opa(&style_Home_imgbtn_5_main, LV_STATE_DEFAULT, 0);
    lv_style_set_image_opa(&style_Home_imgbtn_5_main, LV_STATE_DEFAULT, 255);

    // Write style state: LV_STATE_PRESSED for style_Home_imgbtn_5_main
    lv_style_set_text_color(&style_Home_imgbtn_5_main, LV_STATE_PRESSED, lv_color_make(0xFF, 0x33, 0xFF));
    lv_style_set_image_recolor(&style_Home_imgbtn_5_main, LV_STATE_PRESSED, lv_color_make(0x00, 0x00, 0x00));
    lv_style_set_image_recolor_opa(&style_Home_imgbtn_5_main, LV_STATE_PRESSED, 0);

    // Write style state: LV_STATE_CHECKED for style_Home_imgbtn_5_main
    lv_style_set_text_color(&style_Home_imgbtn_5_main, LV_STATE_CHECKED, lv_color_make(0xFF, 0x33, 0xFF));
    lv_style_set_image_recolor(&style_Home_imgbtn_5_main, LV_STATE_CHECKED, lv_color_make(0x00, 0x00, 0x00));
    lv_style_set_image_recolor_opa(&style_Home_imgbtn_5_main, LV_STATE_CHECKED, 0);
    lv_obj_add_style(ui->Home_imgbtn_5, LV_IMGBTN_PART_MAIN, &style_Home_imgbtn_5_main);
    lv_obj_set_pos(ui->Home_imgbtn_5, 30, 79);
    lv_obj_set_size(ui->Home_imgbtn_5, 50, 44);
    lv_tileview_add_element(ui->Home_home, ui->Home_imgbtn_5);
    lv_imgbtn_set_src(ui->Home_imgbtn_5, LV_BTN_STATE_RELEASED, &_main_shoushi_alpha_50x44);
    lv_imgbtn_set_checkable(ui->Home_imgbtn_5, true);
  }

  static struct _function_home_
  {
    lv_ui *ui = &zm831->ui;
    bool init = false;
  } function_home_app;

  int function_home_app_load(zm831_home_app *app);
  int function_home_app_loop(zm831_home_app *app);
  int function_home_app_exit(zm831_home_app *app);

  zm831_home_app get_function_home_app()
  {
    return {function_home_app_load, function_home_app_loop, function_home_app_exit, &function_home_app};
  }

  // ==============================================================================================

  static void function_home_btn_event_app_cb(lv_obj_t *btn, lv_event_t event)
  {
    if (function_home_app.ui->Home_home_photo == btn && event == LV_EVENT_PRESSED)
    {
      zm831_home_app_select(1);
      return;
    }
    if (function_home_app.ui->Home_home_face == btn && event == LV_EVENT_PRESSED)
    {
      zm831_home_app_select(2);
      return;
    }
  }

  int function_home_app_load(zm831_home_app *app)
  {
    auto self = (_function_home_ *)app->userdata;
    if (!self->init)
    {
      zm831_home_setup_ui(&self->ui->Home, setup_scr_screen, 500);

      pthread_mutex_lock(&zm831->ui_mutex);
      lv_obj_set_event_cb(self->ui->Home_home_photo, function_home_btn_event_app_cb);
      lv_obj_set_event_cb(self->ui->Home_home_face, function_home_btn_event_app_cb);
      pthread_mutex_unlock(&zm831->ui_mutex);

      self->init = true;
    }
    LIBMAIX_INFO_PRINTF("function_home_app_load");
    return 0;
  }

  int function_home_app_exit(zm831_home_app *app)
  {
    auto self = (_function_home_ *)app->userdata;
    if (self->init)
    {
      zm831_home_clear_ui(&self->ui->Home);
      self->init = false;
    }
    LIBMAIX_INFO_PRINTF("function_home_app_exit");
    return 0;
  }

  int function_home_app_loop(zm831_home_app *app)
  {
    auto self = (_function_home_ *)app->userdata;
    libmaix_err_t err = LIBMAIX_ERR_NONE;
    libmaix_image_t *ai_rgb = NULL;
    if (zm831->ai && LIBMAIX_ERR_NONE == zm831->ai->capture_image(zm831->ai, &ai_rgb))
    {
      // sleep(5);
      // zm831_home_app_select(1);
    }
    return 0;
  }
}
