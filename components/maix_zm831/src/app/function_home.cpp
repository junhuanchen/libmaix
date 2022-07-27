
#include "zm831_uvai.hpp"

extern "C"
{
  extern zm831_uv *zm831;

  // ==============================================================================================

  void setup_scr_screen(lv_ui *ui)
  {

    // Write codes screen
    ui->home = lv_scr_act();

    //Write style LV_OBJ_PART_MAIN for home
    static lv_style_t style_home_main;
    lv_style_reset(&style_home_main);

    //Write style state: LV_STATE_DEFAULT for style_home_main
    lv_style_set_bg_color(&style_home_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
    lv_style_set_bg_opa(&style_home_main, LV_STATE_DEFAULT, 0);
    lv_obj_add_style(ui->home, LV_OBJ_PART_MAIN, &style_home_main);

    //Write codes home_home
    ui->home_home = lv_tileview_create(ui->home, NULL);
    static lv_point_t home_home_valid_pos[] = {{0, 0},{0, 1},{0, 2},{0, 3},{0, 4},{0, 5},};
    lv_tileview_set_valid_positions(ui->home_home, home_home_valid_pos, 6);
    lv_tileview_set_edge_flash(ui->home_home, true);
    lv_tileview_set_anim_time(ui->home_home, 2);

    //Write style LV_TILEVIEW_PART_BG for home_home
    static lv_style_t style_home_home_bg;
    lv_style_reset(&style_home_home_bg);

    //Write style state: LV_STATE_DEFAULT for style_home_home_bg
    lv_style_set_radius(&style_home_home_bg, LV_STATE_DEFAULT, 0);
    lv_style_set_bg_color(&style_home_home_bg, LV_STATE_DEFAULT, lv_color_make(0x3c, 0x3c, 0x3c));
    lv_style_set_bg_grad_color(&style_home_home_bg, LV_STATE_DEFAULT, lv_color_make(0x3c, 0x3c, 0x3c));
    lv_style_set_bg_grad_dir(&style_home_home_bg, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
    lv_style_set_bg_opa(&style_home_home_bg, LV_STATE_DEFAULT, 255);
    lv_obj_add_style(ui->home_home, LV_TILEVIEW_PART_BG, &style_home_home_bg);

    //Write style LV_TILEVIEW_PART_EDGE_FLASH for home_home
    static lv_style_t style_home_home_edge_flash;
    lv_style_reset(&style_home_home_edge_flash);

    //Write style state: LV_STATE_DEFAULT for style_home_home_edge_flash
    lv_style_set_radius(&style_home_home_edge_flash, LV_STATE_DEFAULT, 0);
    lv_style_set_bg_color(&style_home_home_edge_flash, LV_STATE_DEFAULT, lv_color_make(0xfa, 0xfa, 0xfa));
    lv_style_set_bg_grad_color(&style_home_home_edge_flash, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
    lv_style_set_bg_grad_dir(&style_home_home_edge_flash, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
    lv_style_set_bg_opa(&style_home_home_edge_flash, LV_STATE_DEFAULT, 255);
    lv_obj_add_style(ui->home_home, LV_TILEVIEW_PART_EDGE_FLASH, &style_home_home_edge_flash);
    lv_obj_set_pos(ui->home_home, 0, 0);
    lv_obj_set_size(ui->home_home, 240, 240);

    //Write codes home_home_home_1
    ui->home_home_home_1 = lv_obj_create(ui->home_home, NULL);
    lv_obj_set_style_local_bg_opa(ui->home_home_home_1, LV_OBJ_PART_MAIN, LV_STATE_DEFAULT, 0);
    lv_obj_set_style_local_border_width(ui->home_home_home_1, LV_OBJ_PART_MAIN, LV_STATE_FOCUSED, 0);
    lv_obj_set_pos(ui->home_home_home_1, 0, 0*240);
    lv_obj_set_size(ui->home_home_home_1, 240, 240);
    lv_tileview_add_element(ui->home_home, ui->home_home_home_1);

    //Write codes home_line_mid_h_home1
    ui->home_line_mid_h_home1 = lv_line_create(ui->home_home_home_1, NULL);

    //Write style LV_LINE_PART_MAIN for home_line_mid_h_home1
    static lv_style_t style_home_line_mid_h_home1_main;
    lv_style_reset(&style_home_line_mid_h_home1_main);

    //Write style state: LV_STATE_DEFAULT for style_home_line_mid_h_home1_main
    lv_style_set_line_color(&style_home_line_mid_h_home1_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
    lv_style_set_line_width(&style_home_line_mid_h_home1_main, LV_STATE_DEFAULT, 3);
    lv_obj_add_style(ui->home_line_mid_h_home1, LV_LINE_PART_MAIN, &style_home_line_mid_h_home1_main);
    lv_obj_set_pos(ui->home_line_mid_h_home1, 102, 0);
    lv_obj_set_size(ui->home_line_mid_h_home1, 10, 240);
    lv_tileview_add_element(ui->home_home, ui->home_line_mid_h_home1);
    static lv_point_t home_line_mid_h_home1[] ={{9,0},{9,240}};
    lv_line_set_points(ui->home_line_mid_h_home1,home_line_mid_h_home1,2);

    //Write codes home_lline_mid_v1_home1
    ui->home_lline_mid_v1_home1 = lv_line_create(ui->home_home_home_1, NULL);

    //Write style LV_LINE_PART_MAIN for home_lline_mid_v1_home1
    static lv_style_t style_home_lline_mid_v1_home1_main;
    lv_style_reset(&style_home_lline_mid_v1_home1_main);

    //Write style state: LV_STATE_DEFAULT for style_home_lline_mid_v1_home1_main
    lv_style_set_line_color(&style_home_lline_mid_v1_home1_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
    lv_style_set_line_width(&style_home_lline_mid_v1_home1_main, LV_STATE_DEFAULT, 3);
    lv_obj_add_style(ui->home_lline_mid_v1_home1, LV_LINE_PART_MAIN, &style_home_lline_mid_v1_home1_main);
    lv_obj_set_pos(ui->home_lline_mid_v1_home1, 0, 0);
    lv_obj_set_size(ui->home_lline_mid_v1_home1, 225, 10);
    lv_tileview_add_element(ui->home_home, ui->home_lline_mid_v1_home1);
    static lv_point_t home_lline_mid_v1_home1[] ={{0,0},{223,0}};
    lv_line_set_points(ui->home_lline_mid_v1_home1,home_lline_mid_v1_home1,2);

    //Write codes home_lline_bottom_h_home1
    ui->home_lline_bottom_h_home1 = lv_line_create(ui->home_home_home_1, NULL);

    //Write style LV_LINE_PART_MAIN for home_lline_bottom_h_home1
    static lv_style_t style_home_lline_bottom_h_home1_main;
    lv_style_reset(&style_home_lline_bottom_h_home1_main);

    //Write style state: LV_STATE_DEFAULT for style_home_lline_bottom_h_home1_main
    lv_style_set_line_color(&style_home_lline_bottom_h_home1_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
    lv_style_set_line_width(&style_home_lline_bottom_h_home1_main, LV_STATE_DEFAULT, 3);
    lv_obj_add_style(ui->home_lline_bottom_h_home1, LV_LINE_PART_MAIN, &style_home_lline_bottom_h_home1_main);
    lv_obj_set_pos(ui->home_lline_bottom_h_home1, 0, 230);
    lv_obj_set_size(ui->home_lline_bottom_h_home1, 225, 10);
    lv_tileview_add_element(ui->home_home, ui->home_lline_bottom_h_home1);
    static lv_point_t home_lline_bottom_h_home1[] ={{0,6},{223,6}};
    lv_line_set_points(ui->home_lline_bottom_h_home1,home_lline_bottom_h_home1,2);

    //Write codes home_lline_mid_v2_home1
    ui->home_lline_mid_v2_home1 = lv_line_create(ui->home_home_home_1, NULL);

    //Write style LV_LINE_PART_MAIN for home_lline_mid_v2_home1
    static lv_style_t style_home_lline_mid_v2_home1_main;
    lv_style_reset(&style_home_lline_mid_v2_home1_main);

    //Write style state: LV_STATE_DEFAULT for style_home_lline_mid_v2_home1_main
    lv_style_set_line_color(&style_home_lline_mid_v2_home1_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
    lv_style_set_line_width(&style_home_lline_mid_v2_home1_main, LV_STATE_DEFAULT, 3);
    lv_obj_add_style(ui->home_lline_mid_v2_home1, LV_LINE_PART_MAIN, &style_home_lline_mid_v2_home1_main);
    lv_obj_set_pos(ui->home_lline_mid_v2_home1, 0, 118);
    lv_obj_set_size(ui->home_lline_mid_v2_home1, 225, 10);
    lv_tileview_add_element(ui->home_home, ui->home_lline_mid_v2_home1);
    static lv_point_t home_lline_mid_v2_home1[] ={{0,0},{223,0}};
    lv_line_set_points(ui->home_lline_mid_v2_home1,home_lline_mid_v2_home1,2);

    //Write codes home_lline_right_v_home1
    ui->home_lline_right_v_home1 = lv_line_create(ui->home_home_home_1, NULL);

    //Write style LV_LINE_PART_MAIN for home_lline_right_v_home1
    static lv_style_t style_home_lline_right_v_home1_main;
    lv_style_reset(&style_home_lline_right_v_home1_main);

    //Write style state: LV_STATE_DEFAULT for style_home_lline_right_v_home1_main
    lv_style_set_line_color(&style_home_lline_right_v_home1_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
    lv_style_set_line_width(&style_home_lline_right_v_home1_main, LV_STATE_DEFAULT, 3);
    lv_obj_add_style(ui->home_lline_right_v_home1, LV_LINE_PART_MAIN, &style_home_lline_right_v_home1_main);
    lv_obj_set_pos(ui->home_lline_right_v_home1, 220, 0);
    lv_obj_set_size(ui->home_lline_right_v_home1, 10, 240);
    lv_tileview_add_element(ui->home_home, ui->home_lline_right_v_home1);
    static lv_point_t home_lline_right_v_home1[] ={{3,0},{3,240}};
    lv_line_set_points(ui->home_lline_right_v_home1,home_lline_right_v_home1,2);

    //Write codes home_imgbtn_photo
    ui->home_imgbtn_photo = lv_imgbtn_create(ui->home_home_home_1, NULL);

    //Write style LV_IMGBTN_PART_MAIN for home_imgbtn_photo
    static lv_style_t style_home_imgbtn_photo_main;
    lv_style_reset(&style_home_imgbtn_photo_main);

    //Write style state: LV_STATE_DEFAULT for style_home_imgbtn_photo_main
    lv_style_set_text_color(&style_home_imgbtn_photo_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
    lv_style_set_image_recolor(&style_home_imgbtn_photo_main, LV_STATE_DEFAULT, lv_color_make(0x2d, 0x3d, 0xb9));
    lv_style_set_image_recolor_opa(&style_home_imgbtn_photo_main, LV_STATE_DEFAULT, 0);
    lv_style_set_image_opa(&style_home_imgbtn_photo_main, LV_STATE_DEFAULT, 255);

    //Write style state: LV_STATE_PRESSED for style_home_imgbtn_photo_main
    lv_style_set_text_color(&style_home_imgbtn_photo_main, LV_STATE_PRESSED, lv_color_make(0xFF, 0x33, 0xFF));
    lv_style_set_image_recolor(&style_home_imgbtn_photo_main, LV_STATE_PRESSED, lv_color_make(0x00, 0x00, 0x00));
    lv_style_set_image_recolor_opa(&style_home_imgbtn_photo_main, LV_STATE_PRESSED, 0);

    //Write style state: LV_STATE_CHECKED for style_home_imgbtn_photo_main
    lv_style_set_text_color(&style_home_imgbtn_photo_main, LV_STATE_CHECKED, lv_color_make(0xFF, 0x33, 0xFF));
    lv_style_set_image_recolor(&style_home_imgbtn_photo_main, LV_STATE_CHECKED, lv_color_make(0x00, 0x00, 0x00));
    lv_style_set_image_recolor_opa(&style_home_imgbtn_photo_main, LV_STATE_CHECKED, 0);
    lv_obj_add_style(ui->home_imgbtn_photo, LV_IMGBTN_PART_MAIN, &style_home_imgbtn_photo_main);
    lv_obj_set_pos(ui->home_imgbtn_photo, 25, 40);
    lv_obj_set_size(ui->home_imgbtn_photo, 60, 42);
    lv_tileview_add_element(ui->home_home, ui->home_imgbtn_photo);
    lv_imgbtn_set_src(ui->home_imgbtn_photo,LV_BTN_STATE_RELEASED,&_main_photo_alpha_60x42);
    lv_imgbtn_set_checkable(ui->home_imgbtn_photo, true);

    //Write codes home_imgbtn_gesture
    ui->home_imgbtn_gesture = lv_imgbtn_create(ui->home_home_home_1, NULL);

    //Write style LV_IMGBTN_PART_MAIN for home_imgbtn_gesture
    static lv_style_t style_home_imgbtn_gesture_main;
    lv_style_reset(&style_home_imgbtn_gesture_main);

    //Write style state: LV_STATE_DEFAULT for style_home_imgbtn_gesture_main
    lv_style_set_text_color(&style_home_imgbtn_gesture_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
    lv_style_set_image_recolor(&style_home_imgbtn_gesture_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
    lv_style_set_image_recolor_opa(&style_home_imgbtn_gesture_main, LV_STATE_DEFAULT, 0);
    lv_style_set_image_opa(&style_home_imgbtn_gesture_main, LV_STATE_DEFAULT, 255);

    //Write style state: LV_STATE_PRESSED for style_home_imgbtn_gesture_main
    lv_style_set_text_color(&style_home_imgbtn_gesture_main, LV_STATE_PRESSED, lv_color_make(0xFF, 0x33, 0xFF));
    lv_style_set_image_recolor(&style_home_imgbtn_gesture_main, LV_STATE_PRESSED, lv_color_make(0x00, 0x00, 0x00));
    lv_style_set_image_recolor_opa(&style_home_imgbtn_gesture_main, LV_STATE_PRESSED, 0);

    //Write style state: LV_STATE_CHECKED for style_home_imgbtn_gesture_main
    lv_style_set_text_color(&style_home_imgbtn_gesture_main, LV_STATE_CHECKED, lv_color_make(0xFF, 0x33, 0xFF));
    lv_style_set_image_recolor(&style_home_imgbtn_gesture_main, LV_STATE_CHECKED, lv_color_make(0x00, 0x00, 0x00));
    lv_style_set_image_recolor_opa(&style_home_imgbtn_gesture_main, LV_STATE_CHECKED, 0);
    lv_obj_add_style(ui->home_imgbtn_gesture, LV_IMGBTN_PART_MAIN, &style_home_imgbtn_gesture_main);
    lv_obj_set_pos(ui->home_imgbtn_gesture, 143, 152);
    lv_obj_set_size(ui->home_imgbtn_gesture, 47, 47);
    lv_tileview_add_element(ui->home_home, ui->home_imgbtn_gesture);
    lv_imgbtn_set_src(ui->home_imgbtn_gesture,LV_BTN_STATE_RELEASED,&_main_shoushi_alpha_47x47);
    lv_imgbtn_set_checkable(ui->home_imgbtn_gesture, true);

    //Write codes home_imgbtn_face_study
    ui->home_imgbtn_face_study = lv_imgbtn_create(ui->home_home_home_1, NULL);

    //Write style LV_IMGBTN_PART_MAIN for home_imgbtn_face_study
    static lv_style_t style_home_imgbtn_face_study_main;
    lv_style_reset(&style_home_imgbtn_face_study_main);

    //Write style state: LV_STATE_DEFAULT for style_home_imgbtn_face_study_main
    lv_style_set_text_color(&style_home_imgbtn_face_study_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
    lv_style_set_image_recolor(&style_home_imgbtn_face_study_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
    lv_style_set_image_recolor_opa(&style_home_imgbtn_face_study_main, LV_STATE_DEFAULT, 0);
    lv_style_set_image_opa(&style_home_imgbtn_face_study_main, LV_STATE_DEFAULT, 255);

    //Write style state: LV_STATE_PRESSED for style_home_imgbtn_face_study_main
    lv_style_set_text_color(&style_home_imgbtn_face_study_main, LV_STATE_PRESSED, lv_color_make(0xFF, 0x33, 0xFF));
    lv_style_set_image_recolor(&style_home_imgbtn_face_study_main, LV_STATE_PRESSED, lv_color_make(0x00, 0x00, 0x00));
    lv_style_set_image_recolor_opa(&style_home_imgbtn_face_study_main, LV_STATE_PRESSED, 0);

    //Write style state: LV_STATE_CHECKED for style_home_imgbtn_face_study_main
    lv_style_set_text_color(&style_home_imgbtn_face_study_main, LV_STATE_CHECKED, lv_color_make(0xFF, 0x33, 0xFF));
    lv_style_set_image_recolor(&style_home_imgbtn_face_study_main, LV_STATE_CHECKED, lv_color_make(0x00, 0x00, 0x00));
    lv_style_set_image_recolor_opa(&style_home_imgbtn_face_study_main, LV_STATE_CHECKED, 0);
    lv_obj_add_style(ui->home_imgbtn_face_study, LV_IMGBTN_PART_MAIN, &style_home_imgbtn_face_study_main);
    lv_obj_set_pos(ui->home_imgbtn_face_study, 30, 152);
    lv_obj_set_size(ui->home_imgbtn_face_study, 49, 49);
    lv_tileview_add_element(ui->home_home, ui->home_imgbtn_face_study);
    lv_imgbtn_set_src(ui->home_imgbtn_face_study,LV_BTN_STATE_RELEASED,&_main_face_s_alpha_49x49);
    lv_imgbtn_set_checkable(ui->home_imgbtn_face_study, true);

    //Write codes home_imgbtn_face
    ui->home_imgbtn_face = lv_imgbtn_create(ui->home_home_home_1, NULL);

    //Write style LV_IMGBTN_PART_MAIN for home_imgbtn_face
    static lv_style_t style_home_imgbtn_face_main;
    lv_style_reset(&style_home_imgbtn_face_main);

    //Write style state: LV_STATE_DEFAULT for style_home_imgbtn_face_main
    lv_style_set_text_color(&style_home_imgbtn_face_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
    lv_style_set_image_recolor(&style_home_imgbtn_face_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
    lv_style_set_image_recolor_opa(&style_home_imgbtn_face_main, LV_STATE_DEFAULT, 0);
    lv_style_set_image_opa(&style_home_imgbtn_face_main, LV_STATE_DEFAULT, 255);

    //Write style state: LV_STATE_PRESSED for style_home_imgbtn_face_main
    lv_style_set_text_color(&style_home_imgbtn_face_main, LV_STATE_PRESSED, lv_color_make(0xFF, 0x33, 0xFF));
    lv_style_set_image_recolor(&style_home_imgbtn_face_main, LV_STATE_PRESSED, lv_color_make(0x00, 0x00, 0x00));
    lv_style_set_image_recolor_opa(&style_home_imgbtn_face_main, LV_STATE_PRESSED, 0);

    //Write style state: LV_STATE_CHECKED for style_home_imgbtn_face_main
    lv_style_set_text_color(&style_home_imgbtn_face_main, LV_STATE_CHECKED, lv_color_make(0xFF, 0x33, 0xFF));
    lv_style_set_image_recolor(&style_home_imgbtn_face_main, LV_STATE_CHECKED, lv_color_make(0x00, 0x00, 0x00));
    lv_style_set_image_recolor_opa(&style_home_imgbtn_face_main, LV_STATE_CHECKED, 0);
    lv_obj_add_style(ui->home_imgbtn_face, LV_IMGBTN_PART_MAIN, &style_home_imgbtn_face_main);
    lv_obj_set_pos(ui->home_imgbtn_face, 143, 38);
    lv_obj_set_size(ui->home_imgbtn_face, 49, 49);
    lv_tileview_add_element(ui->home_home, ui->home_imgbtn_face);
    lv_imgbtn_set_src(ui->home_imgbtn_face,LV_BTN_STATE_RELEASED,&_main_face_alpha_49x49);
    lv_imgbtn_set_checkable(ui->home_imgbtn_face, true);

    //Write codes home_label_photo
    ui->home_label_photo = lv_label_create(ui->home_home_home_1, NULL);
    lv_label_set_text(ui->home_label_photo, "实时拍照");
    lv_label_set_long_mode(ui->home_label_photo, LV_LABEL_LONG_BREAK);
    lv_label_set_align(ui->home_label_photo, LV_LABEL_ALIGN_CENTER);

    //Write style LV_LABEL_PART_MAIN for home_label_photo
    static lv_style_t style_home_label_photo_main;
    lv_style_reset(&style_home_label_photo_main);

    //Write style state: LV_STATE_DEFAULT for style_home_label_photo_main
    lv_style_set_radius(&style_home_label_photo_main, LV_STATE_DEFAULT, 0);
    lv_style_set_bg_color(&style_home_label_photo_main, LV_STATE_DEFAULT, lv_color_make(0x3c, 0x3c, 0x3c));
    lv_style_set_bg_grad_color(&style_home_label_photo_main, LV_STATE_DEFAULT, lv_color_make(0x3c, 0x3c, 0x3c));
    lv_style_set_bg_grad_dir(&style_home_label_photo_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
    lv_style_set_bg_opa(&style_home_label_photo_main, LV_STATE_DEFAULT, 255);
    lv_style_set_text_color(&style_home_label_photo_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
    lv_style_set_text_font(&style_home_label_photo_main, LV_STATE_DEFAULT, &lv_font_simsun_15);
    lv_style_set_text_letter_space(&style_home_label_photo_main, LV_STATE_DEFAULT, 2);
    lv_style_set_pad_left(&style_home_label_photo_main, LV_STATE_DEFAULT, 0);
    lv_style_set_pad_right(&style_home_label_photo_main, LV_STATE_DEFAULT, 0);
    lv_style_set_pad_top(&style_home_label_photo_main, LV_STATE_DEFAULT, 0);
    lv_style_set_pad_bottom(&style_home_label_photo_main, LV_STATE_DEFAULT, 0);
    lv_obj_add_style(ui->home_label_photo, LV_LABEL_PART_MAIN, &style_home_label_photo_main);
    lv_obj_set_pos(ui->home_label_photo, 20, 98);
    lv_obj_set_size(ui->home_label_photo, 69, 0);
    lv_tileview_add_element(ui->home_home, ui->home_label_photo);

    //Write codes home_label_face
    ui->home_label_face = lv_label_create(ui->home_home_home_1, NULL);
    lv_label_set_text(ui->home_label_face, "人脸检测");
    lv_label_set_long_mode(ui->home_label_face, LV_LABEL_LONG_BREAK);
    lv_label_set_align(ui->home_label_face, LV_LABEL_ALIGN_CENTER);

    //Write style LV_LABEL_PART_MAIN for home_label_face
    static lv_style_t style_home_label_face_main;
    lv_style_reset(&style_home_label_face_main);

    //Write style state: LV_STATE_DEFAULT for style_home_label_face_main
    lv_style_set_radius(&style_home_label_face_main, LV_STATE_DEFAULT, 0);
    lv_style_set_bg_color(&style_home_label_face_main, LV_STATE_DEFAULT, lv_color_make(0x3c, 0x3c, 0x3c));
    lv_style_set_bg_grad_color(&style_home_label_face_main, LV_STATE_DEFAULT, lv_color_make(0x3c, 0x3c, 0x3c));
    lv_style_set_bg_grad_dir(&style_home_label_face_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
    lv_style_set_bg_opa(&style_home_label_face_main, LV_STATE_DEFAULT, 255);
    lv_style_set_text_color(&style_home_label_face_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
    lv_style_set_text_font(&style_home_label_face_main, LV_STATE_DEFAULT, &lv_font_simsun_15);
    lv_style_set_text_letter_space(&style_home_label_face_main, LV_STATE_DEFAULT, 2);
    lv_style_set_pad_left(&style_home_label_face_main, LV_STATE_DEFAULT, 0);
    lv_style_set_pad_right(&style_home_label_face_main, LV_STATE_DEFAULT, 0);
    lv_style_set_pad_top(&style_home_label_face_main, LV_STATE_DEFAULT, 0);
    lv_style_set_pad_bottom(&style_home_label_face_main, LV_STATE_DEFAULT, 0);
    lv_obj_add_style(ui->home_label_face, LV_LABEL_PART_MAIN, &style_home_label_face_main);
    lv_obj_set_pos(ui->home_label_face, 135, 98);
    lv_obj_set_size(ui->home_label_face, 68, 0);
    lv_tileview_add_element(ui->home_home, ui->home_label_face);

    //Write codes home_label_face_s
    ui->home_label_face_s = lv_label_create(ui->home_home_home_1, NULL);
    lv_label_set_text(ui->home_label_face_s, "人脸学习");
    lv_label_set_long_mode(ui->home_label_face_s, LV_LABEL_LONG_BREAK);
    lv_label_set_align(ui->home_label_face_s, LV_LABEL_ALIGN_CENTER);

    //Write style LV_LABEL_PART_MAIN for home_label_face_s
    static lv_style_t style_home_label_face_s_main;
    lv_style_reset(&style_home_label_face_s_main);

    //Write style state: LV_STATE_DEFAULT for style_home_label_face_s_main
    lv_style_set_radius(&style_home_label_face_s_main, LV_STATE_DEFAULT, 0);
    lv_style_set_bg_color(&style_home_label_face_s_main, LV_STATE_DEFAULT, lv_color_make(0x3c, 0x3c, 0x3c));
    lv_style_set_bg_grad_color(&style_home_label_face_s_main, LV_STATE_DEFAULT, lv_color_make(0x3c, 0x3c, 0x3c));
    lv_style_set_bg_grad_dir(&style_home_label_face_s_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
    lv_style_set_bg_opa(&style_home_label_face_s_main, LV_STATE_DEFAULT, 255);
    lv_style_set_text_color(&style_home_label_face_s_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
    lv_style_set_text_font(&style_home_label_face_s_main, LV_STATE_DEFAULT, &lv_font_simsun_15);
    lv_style_set_text_letter_space(&style_home_label_face_s_main, LV_STATE_DEFAULT, 2);
    lv_style_set_pad_left(&style_home_label_face_s_main, LV_STATE_DEFAULT, 0);
    lv_style_set_pad_right(&style_home_label_face_s_main, LV_STATE_DEFAULT, 0);
    lv_style_set_pad_top(&style_home_label_face_s_main, LV_STATE_DEFAULT, 0);
    lv_style_set_pad_bottom(&style_home_label_face_s_main, LV_STATE_DEFAULT, 0);
    lv_obj_add_style(ui->home_label_face_s, LV_LABEL_PART_MAIN, &style_home_label_face_s_main);
    lv_obj_set_pos(ui->home_label_face_s, 20, 215);
    lv_obj_set_size(ui->home_label_face_s, 68, 0);
    lv_tileview_add_element(ui->home_home, ui->home_label_face_s);

    //Write codes home_label_gesture
    ui->home_label_gesture = lv_label_create(ui->home_home_home_1, NULL);
    lv_label_set_text(ui->home_label_gesture, "手势识别");
    lv_label_set_long_mode(ui->home_label_gesture, LV_LABEL_LONG_BREAK);
    lv_label_set_align(ui->home_label_gesture, LV_LABEL_ALIGN_CENTER);

    //Write style LV_LABEL_PART_MAIN for home_label_gesture
    static lv_style_t style_home_label_gesture_main;
    lv_style_reset(&style_home_label_gesture_main);

    //Write style state: LV_STATE_DEFAULT for style_home_label_gesture_main
    lv_style_set_radius(&style_home_label_gesture_main, LV_STATE_DEFAULT, 0);
    lv_style_set_bg_color(&style_home_label_gesture_main, LV_STATE_DEFAULT, lv_color_make(0x3c, 0x3c, 0x3c));
    lv_style_set_bg_grad_color(&style_home_label_gesture_main, LV_STATE_DEFAULT, lv_color_make(0x3c, 0x3c, 0x3c));
    lv_style_set_bg_grad_dir(&style_home_label_gesture_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
    lv_style_set_bg_opa(&style_home_label_gesture_main, LV_STATE_DEFAULT, 255);
    lv_style_set_text_color(&style_home_label_gesture_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
    lv_style_set_text_font(&style_home_label_gesture_main, LV_STATE_DEFAULT, &lv_font_simsun_15);
    lv_style_set_text_letter_space(&style_home_label_gesture_main, LV_STATE_DEFAULT, 2);
    lv_style_set_pad_left(&style_home_label_gesture_main, LV_STATE_DEFAULT, 0);
    lv_style_set_pad_right(&style_home_label_gesture_main, LV_STATE_DEFAULT, 0);
    lv_style_set_pad_top(&style_home_label_gesture_main, LV_STATE_DEFAULT, 0);
    lv_style_set_pad_bottom(&style_home_label_gesture_main, LV_STATE_DEFAULT, 0);
    lv_obj_add_style(ui->home_label_gesture, LV_LABEL_PART_MAIN, &style_home_label_gesture_main);
    lv_obj_set_pos(ui->home_label_gesture, 135, 215);
    lv_obj_set_size(ui->home_label_gesture, 69, 0);
    lv_tileview_add_element(ui->home_home, ui->home_label_gesture);

    //Write codes home_home_home_2
    ui->home_home_home_2 = lv_obj_create(ui->home_home, NULL);
    lv_obj_set_style_local_bg_opa(ui->home_home_home_2, LV_OBJ_PART_MAIN, LV_STATE_DEFAULT, 0);
    lv_obj_set_style_local_border_width(ui->home_home_home_2, LV_OBJ_PART_MAIN, LV_STATE_FOCUSED, 0);
    lv_obj_set_pos(ui->home_home_home_2, 0, 1*240);
    lv_obj_set_size(ui->home_home_home_2, 240, 240);
    lv_tileview_add_element(ui->home_home, ui->home_home_home_2);

    //Write codes home_label_tagcode
    ui->home_label_tagcode = lv_label_create(ui->home_home_home_2, NULL);
    lv_label_set_text(ui->home_label_tagcode, "标签码识别");
    lv_label_set_long_mode(ui->home_label_tagcode, LV_LABEL_LONG_BREAK);
    lv_label_set_align(ui->home_label_tagcode, LV_LABEL_ALIGN_CENTER);

    //Write style LV_LABEL_PART_MAIN for home_label_tagcode
    static lv_style_t style_home_label_tagcode_main;
    lv_style_reset(&style_home_label_tagcode_main);

    //Write style state: LV_STATE_DEFAULT for style_home_label_tagcode_main
    lv_style_set_radius(&style_home_label_tagcode_main, LV_STATE_DEFAULT, 0);
    lv_style_set_bg_color(&style_home_label_tagcode_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
    lv_style_set_bg_grad_color(&style_home_label_tagcode_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
    lv_style_set_bg_grad_dir(&style_home_label_tagcode_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
    lv_style_set_bg_opa(&style_home_label_tagcode_main, LV_STATE_DEFAULT, 0);
    lv_style_set_text_color(&style_home_label_tagcode_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
    lv_style_set_text_font(&style_home_label_tagcode_main, LV_STATE_DEFAULT, &lv_font_simsun_15);
    lv_style_set_text_letter_space(&style_home_label_tagcode_main, LV_STATE_DEFAULT, 2);
    lv_style_set_pad_left(&style_home_label_tagcode_main, LV_STATE_DEFAULT, 0);
    lv_style_set_pad_right(&style_home_label_tagcode_main, LV_STATE_DEFAULT, 0);
    lv_style_set_pad_top(&style_home_label_tagcode_main, LV_STATE_DEFAULT, 0);
    lv_style_set_pad_bottom(&style_home_label_tagcode_main, LV_STATE_DEFAULT, 0);
    lv_obj_add_style(ui->home_label_tagcode, LV_LABEL_PART_MAIN, &style_home_label_tagcode_main);
    lv_obj_set_pos(ui->home_label_tagcode, 125, 215);
    lv_obj_set_size(ui->home_label_tagcode, 87, 0);
    lv_tileview_add_element(ui->home_home, ui->home_label_tagcode);

    //Write codes home_lline_bottom_h_home2
    ui->home_lline_bottom_h_home2 = lv_line_create(ui->home_home_home_2, NULL);

    //Write style LV_LINE_PART_MAIN for home_lline_bottom_h_home2
    static lv_style_t style_home_lline_bottom_h_home2_main;
    lv_style_reset(&style_home_lline_bottom_h_home2_main);

    //Write style state: LV_STATE_DEFAULT for style_home_lline_bottom_h_home2_main
    lv_style_set_line_color(&style_home_lline_bottom_h_home2_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
    lv_style_set_line_width(&style_home_lline_bottom_h_home2_main, LV_STATE_DEFAULT, 3);
    lv_obj_add_style(ui->home_lline_bottom_h_home2, LV_LINE_PART_MAIN, &style_home_lline_bottom_h_home2_main);
    lv_obj_set_pos(ui->home_lline_bottom_h_home2, 0, 230);
    lv_obj_set_size(ui->home_lline_bottom_h_home2, 240, 10);
    lv_tileview_add_element(ui->home_home, ui->home_lline_bottom_h_home2);
    static lv_point_t home_lline_bottom_h_home2[] ={{0,6},{223,6}};
    lv_line_set_points(ui->home_lline_bottom_h_home2,home_lline_bottom_h_home2,2);

    //Write codes home_hline_mid_v_home2
    ui->home_hline_mid_v_home2 = lv_line_create(ui->home_home_home_2, NULL);

    //Write style LV_LINE_PART_MAIN for home_hline_mid_v_home2
    static lv_style_t style_home_hline_mid_v_home2_main;
    lv_style_reset(&style_home_hline_mid_v_home2_main);

    //Write style state: LV_STATE_DEFAULT for style_home_hline_mid_v_home2_main
    lv_style_set_line_color(&style_home_hline_mid_v_home2_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
    lv_style_set_line_width(&style_home_hline_mid_v_home2_main, LV_STATE_DEFAULT, 3);
    lv_obj_add_style(ui->home_hline_mid_v_home2, LV_LINE_PART_MAIN, &style_home_hline_mid_v_home2_main);
    lv_obj_set_pos(ui->home_hline_mid_v_home2, 102, 0);
    lv_obj_set_size(ui->home_hline_mid_v_home2, 10, 240);
    lv_tileview_add_element(ui->home_home, ui->home_hline_mid_v_home2);
    static lv_point_t home_hline_mid_v_home2[] ={{9,0},{9,240}};
    lv_line_set_points(ui->home_hline_mid_v_home2,home_hline_mid_v_home2,2);

    //Write codes home_lline_right_v_home2
    ui->home_lline_right_v_home2 = lv_line_create(ui->home_home_home_2, NULL);

    //Write style LV_LINE_PART_MAIN for home_lline_right_v_home2
    static lv_style_t style_home_lline_right_v_home2_main;
    lv_style_reset(&style_home_lline_right_v_home2_main);

    //Write style state: LV_STATE_DEFAULT for style_home_lline_right_v_home2_main
    lv_style_set_line_color(&style_home_lline_right_v_home2_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
    lv_style_set_line_width(&style_home_lline_right_v_home2_main, LV_STATE_DEFAULT, 3);
    lv_obj_add_style(ui->home_lline_right_v_home2, LV_LINE_PART_MAIN, &style_home_lline_right_v_home2_main);
    lv_obj_set_pos(ui->home_lline_right_v_home2, 220, 0);
    lv_obj_set_size(ui->home_lline_right_v_home2, 10, 240);
    lv_tileview_add_element(ui->home_home, ui->home_lline_right_v_home2);
    static lv_point_t home_lline_right_v_home2[] ={{3,0},{3,240}};
    lv_line_set_points(ui->home_lline_right_v_home2,home_lline_right_v_home2,2);

    //Write codes home_line_mid_h_home2
    ui->home_line_mid_h_home2 = lv_line_create(ui->home_home_home_2, NULL);

    //Write style LV_LINE_PART_MAIN for home_line_mid_h_home2
    static lv_style_t style_home_line_mid_h_home2_main;
    lv_style_reset(&style_home_line_mid_h_home2_main);

    //Write style state: LV_STATE_DEFAULT for style_home_line_mid_h_home2_main
    lv_style_set_line_color(&style_home_line_mid_h_home2_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
    lv_style_set_line_width(&style_home_line_mid_h_home2_main, LV_STATE_DEFAULT, 3);
    lv_obj_add_style(ui->home_line_mid_h_home2, LV_LINE_PART_MAIN, &style_home_line_mid_h_home2_main);
    lv_obj_set_pos(ui->home_line_mid_h_home2, 0, 118);
    lv_obj_set_size(ui->home_line_mid_h_home2, 225, 10);
    lv_tileview_add_element(ui->home_home, ui->home_line_mid_h_home2);
    static lv_point_t home_line_mid_h_home2[] ={{0,0},{223,0}};
    lv_line_set_points(ui->home_line_mid_h_home2,home_line_mid_h_home2,2);

    //Write codes home_label_qrcode
    ui->home_label_qrcode = lv_label_create(ui->home_home_home_2, NULL);
    lv_label_set_text(ui->home_label_qrcode, "二维码识别");
    lv_label_set_long_mode(ui->home_label_qrcode, LV_LABEL_LONG_BREAK);
    lv_label_set_align(ui->home_label_qrcode, LV_LABEL_ALIGN_CENTER);

    //Write style LV_LABEL_PART_MAIN for home_label_qrcode
    static lv_style_t style_home_label_qrcode_main;
    lv_style_reset(&style_home_label_qrcode_main);

    //Write style state: LV_STATE_DEFAULT for style_home_label_qrcode_main
    lv_style_set_radius(&style_home_label_qrcode_main, LV_STATE_DEFAULT, 0);
    lv_style_set_bg_color(&style_home_label_qrcode_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
    lv_style_set_bg_grad_color(&style_home_label_qrcode_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
    lv_style_set_bg_grad_dir(&style_home_label_qrcode_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
    lv_style_set_bg_opa(&style_home_label_qrcode_main, LV_STATE_DEFAULT, 0);
    lv_style_set_text_color(&style_home_label_qrcode_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
    lv_style_set_text_font(&style_home_label_qrcode_main, LV_STATE_DEFAULT, &lv_font_simsun_15);
    lv_style_set_text_letter_space(&style_home_label_qrcode_main, LV_STATE_DEFAULT, 2);
    lv_style_set_pad_left(&style_home_label_qrcode_main, LV_STATE_DEFAULT, 0);
    lv_style_set_pad_right(&style_home_label_qrcode_main, LV_STATE_DEFAULT, 0);
    lv_style_set_pad_top(&style_home_label_qrcode_main, LV_STATE_DEFAULT, 0);
    lv_style_set_pad_bottom(&style_home_label_qrcode_main, LV_STATE_DEFAULT, 0);
    lv_obj_add_style(ui->home_label_qrcode, LV_LABEL_PART_MAIN, &style_home_label_qrcode_main);
    lv_obj_set_pos(ui->home_label_qrcode, 15, 215);
    lv_obj_set_size(ui->home_label_qrcode, 85, 0);
    lv_tileview_add_element(ui->home_home, ui->home_label_qrcode);

    //Write codes home_label_color_s
    ui->home_label_color_s = lv_label_create(ui->home_home_home_2, NULL);
    lv_label_set_text(ui->home_label_color_s, "颜色学习");
    lv_label_set_long_mode(ui->home_label_color_s, LV_LABEL_LONG_BREAK);
    lv_label_set_align(ui->home_label_color_s, LV_LABEL_ALIGN_CENTER);

    //Write style LV_LABEL_PART_MAIN for home_label_color_s
    static lv_style_t style_home_label_color_s_main;
    lv_style_reset(&style_home_label_color_s_main);

    //Write style state: LV_STATE_DEFAULT for style_home_label_color_s_main
    lv_style_set_radius(&style_home_label_color_s_main, LV_STATE_DEFAULT, 0);
    lv_style_set_bg_color(&style_home_label_color_s_main, LV_STATE_DEFAULT, lv_color_make(0x3c, 0x3c, 0x3c));
    lv_style_set_bg_grad_color(&style_home_label_color_s_main, LV_STATE_DEFAULT, lv_color_make(0x3c, 0x3c, 0x3c));
    lv_style_set_bg_grad_dir(&style_home_label_color_s_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
    lv_style_set_bg_opa(&style_home_label_color_s_main, LV_STATE_DEFAULT, 0);
    lv_style_set_text_color(&style_home_label_color_s_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
    lv_style_set_text_font(&style_home_label_color_s_main, LV_STATE_DEFAULT, &lv_font_simsun_15);
    lv_style_set_text_letter_space(&style_home_label_color_s_main, LV_STATE_DEFAULT, 2);
    lv_style_set_pad_left(&style_home_label_color_s_main, LV_STATE_DEFAULT, 0);
    lv_style_set_pad_right(&style_home_label_color_s_main, LV_STATE_DEFAULT, 0);
    lv_style_set_pad_top(&style_home_label_color_s_main, LV_STATE_DEFAULT, 0);
    lv_style_set_pad_bottom(&style_home_label_color_s_main, LV_STATE_DEFAULT, 0);
    lv_obj_add_style(ui->home_label_color_s, LV_LABEL_PART_MAIN, &style_home_label_color_s_main);
    lv_obj_set_pos(ui->home_label_color_s, 135, 98);
    lv_obj_set_size(ui->home_label_color_s, 68, 0);
    lv_tileview_add_element(ui->home_home, ui->home_label_color_s);

    //Write codes home_label_color
    ui->home_label_color = lv_label_create(ui->home_home_home_2, NULL);
    lv_label_set_text(ui->home_label_color, "颜色检测");
    lv_label_set_long_mode(ui->home_label_color, LV_LABEL_LONG_BREAK);
    lv_label_set_align(ui->home_label_color, LV_LABEL_ALIGN_CENTER);

    //Write style LV_LABEL_PART_MAIN for home_label_color
    static lv_style_t style_home_label_color_main;
    lv_style_reset(&style_home_label_color_main);

    //Write style state: LV_STATE_DEFAULT for style_home_label_color_main
    lv_style_set_radius(&style_home_label_color_main, LV_STATE_DEFAULT, 0);
    lv_style_set_bg_color(&style_home_label_color_main, LV_STATE_DEFAULT, lv_color_make(0x3c, 0x3c, 0x3c));
    lv_style_set_bg_grad_color(&style_home_label_color_main, LV_STATE_DEFAULT, lv_color_make(0x3c, 0x3c, 0x3c));
    lv_style_set_bg_grad_dir(&style_home_label_color_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
    lv_style_set_bg_opa(&style_home_label_color_main, LV_STATE_DEFAULT, 0);
    lv_style_set_text_color(&style_home_label_color_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
    lv_style_set_text_font(&style_home_label_color_main, LV_STATE_DEFAULT, &lv_font_simsun_15);
    lv_style_set_text_letter_space(&style_home_label_color_main, LV_STATE_DEFAULT, 2);
    lv_style_set_pad_left(&style_home_label_color_main, LV_STATE_DEFAULT, 0);
    lv_style_set_pad_right(&style_home_label_color_main, LV_STATE_DEFAULT, 0);
    lv_style_set_pad_top(&style_home_label_color_main, LV_STATE_DEFAULT, 0);
    lv_style_set_pad_bottom(&style_home_label_color_main, LV_STATE_DEFAULT, 0);
    lv_obj_add_style(ui->home_label_color, LV_LABEL_PART_MAIN, &style_home_label_color_main);
    lv_obj_set_pos(ui->home_label_color, 20, 98);
    lv_obj_set_size(ui->home_label_color, 69, 0);
    lv_tileview_add_element(ui->home_home, ui->home_label_color);

    //Write codes home_imgbtn_color
    ui->home_imgbtn_color = lv_imgbtn_create(ui->home_home_home_2, NULL);

    //Write style LV_IMGBTN_PART_MAIN for home_imgbtn_color
    static lv_style_t style_home_imgbtn_color_main;
    lv_style_reset(&style_home_imgbtn_color_main);

    //Write style state: LV_STATE_DEFAULT for style_home_imgbtn_color_main
    lv_style_set_text_color(&style_home_imgbtn_color_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
    lv_style_set_image_recolor(&style_home_imgbtn_color_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
    lv_style_set_image_recolor_opa(&style_home_imgbtn_color_main, LV_STATE_DEFAULT, 0);
    lv_style_set_image_opa(&style_home_imgbtn_color_main, LV_STATE_DEFAULT, 255);

    //Write style state: LV_STATE_PRESSED for style_home_imgbtn_color_main
    lv_style_set_text_color(&style_home_imgbtn_color_main, LV_STATE_PRESSED, lv_color_make(0xFF, 0x33, 0xFF));
    lv_style_set_image_recolor(&style_home_imgbtn_color_main, LV_STATE_PRESSED, lv_color_make(0x00, 0x00, 0x00));
    lv_style_set_image_recolor_opa(&style_home_imgbtn_color_main, LV_STATE_PRESSED, 0);

    //Write style state: LV_STATE_CHECKED for style_home_imgbtn_color_main
    lv_style_set_text_color(&style_home_imgbtn_color_main, LV_STATE_CHECKED, lv_color_make(0xFF, 0x33, 0xFF));
    lv_style_set_image_recolor(&style_home_imgbtn_color_main, LV_STATE_CHECKED, lv_color_make(0x00, 0x00, 0x00));
    lv_style_set_image_recolor_opa(&style_home_imgbtn_color_main, LV_STATE_CHECKED, 0);
    lv_obj_add_style(ui->home_imgbtn_color, LV_IMGBTN_PART_MAIN, &style_home_imgbtn_color_main);
    lv_obj_set_pos(ui->home_imgbtn_color, 30, 38);
    lv_obj_set_size(ui->home_imgbtn_color, 52, 49);
    lv_tileview_add_element(ui->home_home, ui->home_imgbtn_color);
    lv_imgbtn_set_src(ui->home_imgbtn_color,LV_BTN_STATE_RELEASED,&_home_color_alpha_52x49);
    lv_imgbtn_set_checkable(ui->home_imgbtn_color, true);

    //Write codes home_Imgbtn_tagcode
    ui->home_Imgbtn_tagcode = lv_imgbtn_create(ui->home_home_home_2, NULL);

    //Write style LV_IMGBTN_PART_MAIN for home_Imgbtn_tagcode
    static lv_style_t style_home_Imgbtn_tagcode_main;
    lv_style_reset(&style_home_Imgbtn_tagcode_main);

    //Write style state: LV_STATE_DEFAULT for style_home_Imgbtn_tagcode_main
    lv_style_set_text_color(&style_home_Imgbtn_tagcode_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
    lv_style_set_image_recolor(&style_home_Imgbtn_tagcode_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
    lv_style_set_image_recolor_opa(&style_home_Imgbtn_tagcode_main, LV_STATE_DEFAULT, 0);
    lv_style_set_image_opa(&style_home_Imgbtn_tagcode_main, LV_STATE_DEFAULT, 255);

    //Write style state: LV_STATE_PRESSED for style_home_Imgbtn_tagcode_main
    lv_style_set_text_color(&style_home_Imgbtn_tagcode_main, LV_STATE_PRESSED, lv_color_make(0xFF, 0x33, 0xFF));
    lv_style_set_image_recolor(&style_home_Imgbtn_tagcode_main, LV_STATE_PRESSED, lv_color_make(0x00, 0x00, 0x00));
    lv_style_set_image_recolor_opa(&style_home_Imgbtn_tagcode_main, LV_STATE_PRESSED, 0);

    //Write style state: LV_STATE_CHECKED for style_home_Imgbtn_tagcode_main
    lv_style_set_text_color(&style_home_Imgbtn_tagcode_main, LV_STATE_CHECKED, lv_color_make(0xFF, 0x33, 0xFF));
    lv_style_set_image_recolor(&style_home_Imgbtn_tagcode_main, LV_STATE_CHECKED, lv_color_make(0x00, 0x00, 0x00));
    lv_style_set_image_recolor_opa(&style_home_Imgbtn_tagcode_main, LV_STATE_CHECKED, 0);
    lv_obj_add_style(ui->home_Imgbtn_tagcode, LV_IMGBTN_PART_MAIN, &style_home_Imgbtn_tagcode_main);
    lv_obj_set_pos(ui->home_Imgbtn_tagcode, 143, 152);
    lv_obj_set_size(ui->home_Imgbtn_tagcode, 47, 47);
    lv_tileview_add_element(ui->home_home, ui->home_Imgbtn_tagcode);
    lv_imgbtn_set_src(ui->home_Imgbtn_tagcode,LV_BTN_STATE_RELEASED,&_home_tagcode_alpha_47x47);
    lv_imgbtn_set_checkable(ui->home_Imgbtn_tagcode, true);

    //Write codes home_imgbtn_qrcode
    ui->home_imgbtn_qrcode = lv_imgbtn_create(ui->home_home_home_2, NULL);

    //Write style LV_IMGBTN_PART_MAIN for home_imgbtn_qrcode
    static lv_style_t style_home_imgbtn_qrcode_main;
    lv_style_reset(&style_home_imgbtn_qrcode_main);

    //Write style state: LV_STATE_DEFAULT for style_home_imgbtn_qrcode_main
    lv_style_set_text_color(&style_home_imgbtn_qrcode_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
    lv_style_set_image_recolor(&style_home_imgbtn_qrcode_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
    lv_style_set_image_recolor_opa(&style_home_imgbtn_qrcode_main, LV_STATE_DEFAULT, 0);
    lv_style_set_image_opa(&style_home_imgbtn_qrcode_main, LV_STATE_DEFAULT, 255);

    //Write style state: LV_STATE_PRESSED for style_home_imgbtn_qrcode_main
    lv_style_set_text_color(&style_home_imgbtn_qrcode_main, LV_STATE_PRESSED, lv_color_make(0xFF, 0x33, 0xFF));
    lv_style_set_image_recolor(&style_home_imgbtn_qrcode_main, LV_STATE_PRESSED, lv_color_make(0x00, 0x00, 0x00));
    lv_style_set_image_recolor_opa(&style_home_imgbtn_qrcode_main, LV_STATE_PRESSED, 0);

    //Write style state: LV_STATE_CHECKED for style_home_imgbtn_qrcode_main
    lv_style_set_text_color(&style_home_imgbtn_qrcode_main, LV_STATE_CHECKED, lv_color_make(0xFF, 0x33, 0xFF));
    lv_style_set_image_recolor(&style_home_imgbtn_qrcode_main, LV_STATE_CHECKED, lv_color_make(0x00, 0x00, 0x00));
    lv_style_set_image_recolor_opa(&style_home_imgbtn_qrcode_main, LV_STATE_CHECKED, 0);
    lv_obj_add_style(ui->home_imgbtn_qrcode, LV_IMGBTN_PART_MAIN, &style_home_imgbtn_qrcode_main);
    lv_obj_set_pos(ui->home_imgbtn_qrcode, 30, 152);
    lv_obj_set_size(ui->home_imgbtn_qrcode, 47, 47);
    lv_tileview_add_element(ui->home_home, ui->home_imgbtn_qrcode);
    lv_imgbtn_set_src(ui->home_imgbtn_qrcode,LV_BTN_STATE_RELEASED,&_home_qrcode_alpha_47x47);
    lv_imgbtn_set_checkable(ui->home_imgbtn_qrcode, true);

    //Write codes home_imgbtn_colo_s
    ui->home_imgbtn_colo_s = lv_imgbtn_create(ui->home_home_home_2, NULL);

    //Write style LV_IMGBTN_PART_MAIN for home_imgbtn_colo_s
    static lv_style_t style_home_imgbtn_colo_s_main;
    lv_style_reset(&style_home_imgbtn_colo_s_main);

    //Write style state: LV_STATE_DEFAULT for style_home_imgbtn_colo_s_main
    lv_style_set_text_color(&style_home_imgbtn_colo_s_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
    lv_style_set_image_recolor(&style_home_imgbtn_colo_s_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
    lv_style_set_image_recolor_opa(&style_home_imgbtn_colo_s_main, LV_STATE_DEFAULT, 0);
    lv_style_set_image_opa(&style_home_imgbtn_colo_s_main, LV_STATE_DEFAULT, 255);

    //Write style state: LV_STATE_PRESSED for style_home_imgbtn_colo_s_main
    lv_style_set_text_color(&style_home_imgbtn_colo_s_main, LV_STATE_PRESSED, lv_color_make(0xFF, 0x33, 0xFF));
    lv_style_set_image_recolor(&style_home_imgbtn_colo_s_main, LV_STATE_PRESSED, lv_color_make(0x00, 0x00, 0x00));
    lv_style_set_image_recolor_opa(&style_home_imgbtn_colo_s_main, LV_STATE_PRESSED, 0);

    //Write style state: LV_STATE_CHECKED for style_home_imgbtn_colo_s_main
    lv_style_set_text_color(&style_home_imgbtn_colo_s_main, LV_STATE_CHECKED, lv_color_make(0xFF, 0x33, 0xFF));
    lv_style_set_image_recolor(&style_home_imgbtn_colo_s_main, LV_STATE_CHECKED, lv_color_make(0x00, 0x00, 0x00));
    lv_style_set_image_recolor_opa(&style_home_imgbtn_colo_s_main, LV_STATE_CHECKED, 0);
    lv_obj_add_style(ui->home_imgbtn_colo_s, LV_IMGBTN_PART_MAIN, &style_home_imgbtn_colo_s_main);
    lv_obj_set_pos(ui->home_imgbtn_colo_s, 143, 38);
    lv_obj_set_size(ui->home_imgbtn_colo_s, 52, 50);
    lv_tileview_add_element(ui->home_home, ui->home_imgbtn_colo_s);
    lv_imgbtn_set_src(ui->home_imgbtn_colo_s,LV_BTN_STATE_RELEASED,&_home_s_alpha_52x50);
    lv_imgbtn_set_checkable(ui->home_imgbtn_colo_s, true);

    //Write codes home_home_home_3
    ui->home_home_home_3 = lv_obj_create(ui->home_home, NULL);
    lv_obj_set_style_local_bg_opa(ui->home_home_home_3, LV_OBJ_PART_MAIN, LV_STATE_DEFAULT, 0);
    lv_obj_set_style_local_border_width(ui->home_home_home_3, LV_OBJ_PART_MAIN, LV_STATE_FOCUSED, 0);
    lv_obj_set_pos(ui->home_home_home_3, 0, 2*240);
    lv_obj_set_size(ui->home_home_home_3, 240, 240);
    lv_tileview_add_element(ui->home_home, ui->home_home_home_3);

    //Write codes home_line_right_v_home3
    ui->home_line_right_v_home3 = lv_line_create(ui->home_home_home_3, NULL);

    //Write style LV_LINE_PART_MAIN for home_line_right_v_home3
    static lv_style_t style_home_line_right_v_home3_main;
    lv_style_reset(&style_home_line_right_v_home3_main);

    //Write style state: LV_STATE_DEFAULT for style_home_line_right_v_home3_main
    lv_style_set_line_color(&style_home_line_right_v_home3_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
    lv_style_set_line_width(&style_home_line_right_v_home3_main, LV_STATE_DEFAULT, 3);
    lv_obj_add_style(ui->home_line_right_v_home3, LV_LINE_PART_MAIN, &style_home_line_right_v_home3_main);
    lv_obj_set_pos(ui->home_line_right_v_home3, 220, 0);
    lv_obj_set_size(ui->home_line_right_v_home3, 10, 240);
    lv_tileview_add_element(ui->home_home, ui->home_line_right_v_home3);
    static lv_point_t home_line_right_v_home3[] ={{3,0},{3,240}};
    lv_line_set_points(ui->home_line_right_v_home3,home_line_right_v_home3,2);

    //Write codes home_line_bottom_h_home3
    ui->home_line_bottom_h_home3 = lv_line_create(ui->home_home_home_3, NULL);

    //Write style LV_LINE_PART_MAIN for home_line_bottom_h_home3
    static lv_style_t style_home_line_bottom_h_home3_main;
    lv_style_reset(&style_home_line_bottom_h_home3_main);

    //Write style state: LV_STATE_DEFAULT for style_home_line_bottom_h_home3_main
    lv_style_set_line_color(&style_home_line_bottom_h_home3_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
    lv_style_set_line_width(&style_home_line_bottom_h_home3_main, LV_STATE_DEFAULT, 3);
    lv_obj_add_style(ui->home_line_bottom_h_home3, LV_LINE_PART_MAIN, &style_home_line_bottom_h_home3_main);
    lv_obj_set_pos(ui->home_line_bottom_h_home3, 0, 230);
    lv_obj_set_size(ui->home_line_bottom_h_home3, 225, 10);
    lv_tileview_add_element(ui->home_home, ui->home_line_bottom_h_home3);
    static lv_point_t home_line_bottom_h_home3[] ={{0,6},{223,6}};
    lv_line_set_points(ui->home_line_bottom_h_home3,home_line_bottom_h_home3,2);

    //Write codes home_line_mid_h_home3
    ui->home_line_mid_h_home3 = lv_line_create(ui->home_home_home_3, NULL);

    //Write style LV_LINE_PART_MAIN for home_line_mid_h_home3
    static lv_style_t style_home_line_mid_h_home3_main;
    lv_style_reset(&style_home_line_mid_h_home3_main);

    //Write style state: LV_STATE_DEFAULT for style_home_line_mid_h_home3_main
    lv_style_set_line_color(&style_home_line_mid_h_home3_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
    lv_style_set_line_width(&style_home_line_mid_h_home3_main, LV_STATE_DEFAULT, 3);
    lv_obj_add_style(ui->home_line_mid_h_home3, LV_LINE_PART_MAIN, &style_home_line_mid_h_home3_main);
    lv_obj_set_pos(ui->home_line_mid_h_home3, 102, 0);
    lv_obj_set_size(ui->home_line_mid_h_home3, 10, 240);
    lv_tileview_add_element(ui->home_home, ui->home_line_mid_h_home3);
    static lv_point_t home_line_mid_h_home3[] ={{9,0},{9,240}};
    lv_line_set_points(ui->home_line_mid_h_home3,home_line_mid_h_home3,2);

    //Write codes home_line_mid_v_home3
    ui->home_line_mid_v_home3 = lv_line_create(ui->home_home_home_3, NULL);

    //Write style LV_LINE_PART_MAIN for home_line_mid_v_home3
    static lv_style_t style_home_line_mid_v_home3_main;
    lv_style_reset(&style_home_line_mid_v_home3_main);

    //Write style state: LV_STATE_DEFAULT for style_home_line_mid_v_home3_main
    lv_style_set_line_color(&style_home_line_mid_v_home3_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
    lv_style_set_line_width(&style_home_line_mid_v_home3_main, LV_STATE_DEFAULT, 3);
    lv_obj_add_style(ui->home_line_mid_v_home3, LV_LINE_PART_MAIN, &style_home_line_mid_v_home3_main);
    lv_obj_set_pos(ui->home_line_mid_v_home3, 0, 118);
    lv_obj_set_size(ui->home_line_mid_v_home3, 225, 10);
    lv_tileview_add_element(ui->home_home, ui->home_line_mid_v_home3);
    static lv_point_t home_line_mid_v_home3[] ={{0,0},{223,0}};
    lv_line_set_points(ui->home_line_mid_v_home3,home_line_mid_v_home3,2);

    //Write codes home_label_number
    ui->home_label_number = lv_label_create(ui->home_home_home_3, NULL);
    lv_label_set_text(ui->home_label_number, "数字识别");
    lv_label_set_long_mode(ui->home_label_number, LV_LABEL_LONG_BREAK);
    lv_label_set_align(ui->home_label_number, LV_LABEL_ALIGN_CENTER);

    //Write style LV_LABEL_PART_MAIN for home_label_number
    static lv_style_t style_home_label_number_main;
    lv_style_reset(&style_home_label_number_main);

    //Write style state: LV_STATE_DEFAULT for style_home_label_number_main
    lv_style_set_radius(&style_home_label_number_main, LV_STATE_DEFAULT, 0);
    lv_style_set_bg_color(&style_home_label_number_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
    lv_style_set_bg_grad_color(&style_home_label_number_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
    lv_style_set_bg_grad_dir(&style_home_label_number_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
    lv_style_set_bg_opa(&style_home_label_number_main, LV_STATE_DEFAULT, 0);
    lv_style_set_text_color(&style_home_label_number_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
    lv_style_set_text_font(&style_home_label_number_main, LV_STATE_DEFAULT, &lv_font_simsun_15);
    lv_style_set_text_letter_space(&style_home_label_number_main, LV_STATE_DEFAULT, 2);
    lv_style_set_pad_left(&style_home_label_number_main, LV_STATE_DEFAULT, 0);
    lv_style_set_pad_right(&style_home_label_number_main, LV_STATE_DEFAULT, 0);
    lv_style_set_pad_top(&style_home_label_number_main, LV_STATE_DEFAULT, 0);
    lv_style_set_pad_bottom(&style_home_label_number_main, LV_STATE_DEFAULT, 0);
    lv_obj_add_style(ui->home_label_number, LV_LABEL_PART_MAIN, &style_home_label_number_main);
    lv_obj_set_pos(ui->home_label_number, 135, 215);
    lv_obj_set_size(ui->home_label_number, 68, 0);
    lv_tileview_add_element(ui->home_home, ui->home_label_number);

    //Write codes home_label_ball
    ui->home_label_ball = lv_label_create(ui->home_home_home_3, NULL);
    lv_label_set_text(ui->home_label_ball, "小球识别");
    lv_label_set_long_mode(ui->home_label_ball, LV_LABEL_LONG_BREAK);
    lv_label_set_align(ui->home_label_ball, LV_LABEL_ALIGN_CENTER);

    //Write style LV_LABEL_PART_MAIN for home_label_ball
    static lv_style_t style_home_label_ball_main;
    lv_style_reset(&style_home_label_ball_main);

    //Write style state: LV_STATE_DEFAULT for style_home_label_ball_main
    lv_style_set_radius(&style_home_label_ball_main, LV_STATE_DEFAULT, 0);
    lv_style_set_bg_color(&style_home_label_ball_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
    lv_style_set_bg_grad_color(&style_home_label_ball_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
    lv_style_set_bg_grad_dir(&style_home_label_ball_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
    lv_style_set_bg_opa(&style_home_label_ball_main, LV_STATE_DEFAULT, 0);
    lv_style_set_text_color(&style_home_label_ball_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
    lv_style_set_text_font(&style_home_label_ball_main, LV_STATE_DEFAULT, &lv_font_simsun_15);
    lv_style_set_text_letter_space(&style_home_label_ball_main, LV_STATE_DEFAULT, 2);
    lv_style_set_pad_left(&style_home_label_ball_main, LV_STATE_DEFAULT, 0);
    lv_style_set_pad_right(&style_home_label_ball_main, LV_STATE_DEFAULT, 0);
    lv_style_set_pad_top(&style_home_label_ball_main, LV_STATE_DEFAULT, 0);
    lv_style_set_pad_bottom(&style_home_label_ball_main, LV_STATE_DEFAULT, 0);
    lv_obj_add_style(ui->home_label_ball, LV_LABEL_PART_MAIN, &style_home_label_ball_main);
    lv_obj_set_pos(ui->home_label_ball, 20, 215);
    lv_obj_set_size(ui->home_label_ball, 68, 0);
    lv_tileview_add_element(ui->home_home, ui->home_label_ball);

    //Write codes home_label_traffic
    ui->home_label_traffic = lv_label_create(ui->home_home_home_3, NULL);
    lv_label_set_text(ui->home_label_traffic, "交通标志");
    lv_label_set_long_mode(ui->home_label_traffic, LV_LABEL_LONG_BREAK);
    lv_label_set_align(ui->home_label_traffic, LV_LABEL_ALIGN_CENTER);

    //Write style LV_LABEL_PART_MAIN for home_label_traffic
    static lv_style_t style_home_label_traffic_main;
    lv_style_reset(&style_home_label_traffic_main);

    //Write style state: LV_STATE_DEFAULT for style_home_label_traffic_main
    lv_style_set_radius(&style_home_label_traffic_main, LV_STATE_DEFAULT, 0);
    lv_style_set_bg_color(&style_home_label_traffic_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
    lv_style_set_bg_grad_color(&style_home_label_traffic_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
    lv_style_set_bg_grad_dir(&style_home_label_traffic_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
    lv_style_set_bg_opa(&style_home_label_traffic_main, LV_STATE_DEFAULT, 0);
    lv_style_set_text_color(&style_home_label_traffic_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
    lv_style_set_text_font(&style_home_label_traffic_main, LV_STATE_DEFAULT, &lv_font_simsun_15);
    lv_style_set_text_letter_space(&style_home_label_traffic_main, LV_STATE_DEFAULT, 2);
    lv_style_set_pad_left(&style_home_label_traffic_main, LV_STATE_DEFAULT, 0);
    lv_style_set_pad_right(&style_home_label_traffic_main, LV_STATE_DEFAULT, 0);
    lv_style_set_pad_top(&style_home_label_traffic_main, LV_STATE_DEFAULT, 0);
    lv_style_set_pad_bottom(&style_home_label_traffic_main, LV_STATE_DEFAULT, 0);
    lv_obj_add_style(ui->home_label_traffic, LV_LABEL_PART_MAIN, &style_home_label_traffic_main);
    lv_obj_set_pos(ui->home_label_traffic, 135, 98);
    lv_obj_set_size(ui->home_label_traffic, 68, 0);
    lv_tileview_add_element(ui->home_home, ui->home_label_traffic);

    //Write codes home_label_road
    ui->home_label_road = lv_label_create(ui->home_home_home_3, NULL);
    lv_label_set_text(ui->home_label_road, "道路识别");
    lv_label_set_long_mode(ui->home_label_road, LV_LABEL_LONG_BREAK);
    lv_label_set_align(ui->home_label_road, LV_LABEL_ALIGN_CENTER);

    //Write style LV_LABEL_PART_MAIN for home_label_road
    static lv_style_t style_home_label_road_main;
    lv_style_reset(&style_home_label_road_main);

    //Write style state: LV_STATE_DEFAULT for style_home_label_road_main
    lv_style_set_radius(&style_home_label_road_main, LV_STATE_DEFAULT, 0);
    lv_style_set_bg_color(&style_home_label_road_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
    lv_style_set_bg_grad_color(&style_home_label_road_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
    lv_style_set_bg_grad_dir(&style_home_label_road_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
    lv_style_set_bg_opa(&style_home_label_road_main, LV_STATE_DEFAULT, 0);
    lv_style_set_text_color(&style_home_label_road_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
    lv_style_set_text_font(&style_home_label_road_main, LV_STATE_DEFAULT, &lv_font_simsun_15);
    lv_style_set_text_letter_space(&style_home_label_road_main, LV_STATE_DEFAULT, 2);
    lv_style_set_pad_left(&style_home_label_road_main, LV_STATE_DEFAULT, 0);
    lv_style_set_pad_right(&style_home_label_road_main, LV_STATE_DEFAULT, 0);
    lv_style_set_pad_top(&style_home_label_road_main, LV_STATE_DEFAULT, 0);
    lv_style_set_pad_bottom(&style_home_label_road_main, LV_STATE_DEFAULT, 0);
    lv_obj_add_style(ui->home_label_road, LV_LABEL_PART_MAIN, &style_home_label_road_main);
    lv_obj_set_pos(ui->home_label_road, 20, 98);
    lv_obj_set_size(ui->home_label_road, 68, 0);
    lv_tileview_add_element(ui->home_home, ui->home_label_road);

    //Write codes home_imgbtn_number
    ui->home_imgbtn_number = lv_imgbtn_create(ui->home_home_home_3, NULL);

    //Write style LV_IMGBTN_PART_MAIN for home_imgbtn_number
    static lv_style_t style_home_imgbtn_number_main;
    lv_style_reset(&style_home_imgbtn_number_main);

    //Write style state: LV_STATE_DEFAULT for style_home_imgbtn_number_main
    lv_style_set_text_color(&style_home_imgbtn_number_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
    lv_style_set_image_recolor(&style_home_imgbtn_number_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
    lv_style_set_image_recolor_opa(&style_home_imgbtn_number_main, LV_STATE_DEFAULT, 0);
    lv_style_set_image_opa(&style_home_imgbtn_number_main, LV_STATE_DEFAULT, 255);

    //Write style state: LV_STATE_PRESSED for style_home_imgbtn_number_main
    lv_style_set_text_color(&style_home_imgbtn_number_main, LV_STATE_PRESSED, lv_color_make(0xFF, 0x33, 0xFF));
    lv_style_set_image_recolor(&style_home_imgbtn_number_main, LV_STATE_PRESSED, lv_color_make(0x00, 0x00, 0x00));
    lv_style_set_image_recolor_opa(&style_home_imgbtn_number_main, LV_STATE_PRESSED, 0);

    //Write style state: LV_STATE_CHECKED for style_home_imgbtn_number_main
    lv_style_set_text_color(&style_home_imgbtn_number_main, LV_STATE_CHECKED, lv_color_make(0xFF, 0x33, 0xFF));
    lv_style_set_image_recolor(&style_home_imgbtn_number_main, LV_STATE_CHECKED, lv_color_make(0x00, 0x00, 0x00));
    lv_style_set_image_recolor_opa(&style_home_imgbtn_number_main, LV_STATE_CHECKED, 0);
    lv_obj_add_style(ui->home_imgbtn_number, LV_IMGBTN_PART_MAIN, &style_home_imgbtn_number_main);
    lv_obj_set_pos(ui->home_imgbtn_number, 143, 152);
    lv_obj_set_size(ui->home_imgbtn_number, 47, 47);
    lv_tileview_add_element(ui->home_home, ui->home_imgbtn_number);
    lv_imgbtn_set_src(ui->home_imgbtn_number,LV_BTN_STATE_RELEASED,&_home_number_alpha_47x47);
    lv_imgbtn_set_checkable(ui->home_imgbtn_number, true);

    //Write codes home_imgbtn_ball
    ui->home_imgbtn_ball = lv_imgbtn_create(ui->home_home_home_3, NULL);

    //Write style LV_IMGBTN_PART_MAIN for home_imgbtn_ball
    static lv_style_t style_home_imgbtn_ball_main;
    lv_style_reset(&style_home_imgbtn_ball_main);

    //Write style state: LV_STATE_DEFAULT for style_home_imgbtn_ball_main
    lv_style_set_text_color(&style_home_imgbtn_ball_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
    lv_style_set_image_recolor(&style_home_imgbtn_ball_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
    lv_style_set_image_recolor_opa(&style_home_imgbtn_ball_main, LV_STATE_DEFAULT, 0);
    lv_style_set_image_opa(&style_home_imgbtn_ball_main, LV_STATE_DEFAULT, 255);

    //Write style state: LV_STATE_PRESSED for style_home_imgbtn_ball_main
    lv_style_set_text_color(&style_home_imgbtn_ball_main, LV_STATE_PRESSED, lv_color_make(0xFF, 0x33, 0xFF));
    lv_style_set_image_recolor(&style_home_imgbtn_ball_main, LV_STATE_PRESSED, lv_color_make(0x00, 0x00, 0x00));
    lv_style_set_image_recolor_opa(&style_home_imgbtn_ball_main, LV_STATE_PRESSED, 0);

    //Write style state: LV_STATE_CHECKED for style_home_imgbtn_ball_main
    lv_style_set_text_color(&style_home_imgbtn_ball_main, LV_STATE_CHECKED, lv_color_make(0xFF, 0x33, 0xFF));
    lv_style_set_image_recolor(&style_home_imgbtn_ball_main, LV_STATE_CHECKED, lv_color_make(0x00, 0x00, 0x00));
    lv_style_set_image_recolor_opa(&style_home_imgbtn_ball_main, LV_STATE_CHECKED, 0);
    lv_obj_add_style(ui->home_imgbtn_ball, LV_IMGBTN_PART_MAIN, &style_home_imgbtn_ball_main);
    lv_obj_set_pos(ui->home_imgbtn_ball, 30, 152);
    lv_obj_set_size(ui->home_imgbtn_ball, 47, 47);
    lv_tileview_add_element(ui->home_home, ui->home_imgbtn_ball);
    lv_imgbtn_set_src(ui->home_imgbtn_ball,LV_BTN_STATE_RELEASED,&_home_find_ball_alpha_47x47);
    lv_imgbtn_set_checkable(ui->home_imgbtn_ball, true);

    //Write codes home_imgbtn_traffic
    ui->home_imgbtn_traffic = lv_imgbtn_create(ui->home_home_home_3, NULL);

    //Write style LV_IMGBTN_PART_MAIN for home_imgbtn_traffic
    static lv_style_t style_home_imgbtn_traffic_main;
    lv_style_reset(&style_home_imgbtn_traffic_main);

    //Write style state: LV_STATE_DEFAULT for style_home_imgbtn_traffic_main
    lv_style_set_text_color(&style_home_imgbtn_traffic_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
    lv_style_set_image_recolor(&style_home_imgbtn_traffic_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
    lv_style_set_image_recolor_opa(&style_home_imgbtn_traffic_main, LV_STATE_DEFAULT, 0);
    lv_style_set_image_opa(&style_home_imgbtn_traffic_main, LV_STATE_DEFAULT, 255);

    //Write style state: LV_STATE_PRESSED for style_home_imgbtn_traffic_main
    lv_style_set_text_color(&style_home_imgbtn_traffic_main, LV_STATE_PRESSED, lv_color_make(0xFF, 0x33, 0xFF));
    lv_style_set_image_recolor(&style_home_imgbtn_traffic_main, LV_STATE_PRESSED, lv_color_make(0x00, 0x00, 0x00));
    lv_style_set_image_recolor_opa(&style_home_imgbtn_traffic_main, LV_STATE_PRESSED, 0);

    //Write style state: LV_STATE_CHECKED for style_home_imgbtn_traffic_main
    lv_style_set_text_color(&style_home_imgbtn_traffic_main, LV_STATE_CHECKED, lv_color_make(0xFF, 0x33, 0xFF));
    lv_style_set_image_recolor(&style_home_imgbtn_traffic_main, LV_STATE_CHECKED, lv_color_make(0x00, 0x00, 0x00));
    lv_style_set_image_recolor_opa(&style_home_imgbtn_traffic_main, LV_STATE_CHECKED, 0);
    lv_obj_add_style(ui->home_imgbtn_traffic, LV_IMGBTN_PART_MAIN, &style_home_imgbtn_traffic_main);
    lv_obj_set_pos(ui->home_imgbtn_traffic, 143, 38);
    lv_obj_set_size(ui->home_imgbtn_traffic, 47, 47);
    lv_tileview_add_element(ui->home_home, ui->home_imgbtn_traffic);
    lv_imgbtn_set_src(ui->home_imgbtn_traffic,LV_BTN_STATE_RELEASED,&_home_traffic_alpha_47x47);
    lv_imgbtn_set_checkable(ui->home_imgbtn_traffic, true);

    //Write codes home_imgbtn_road
    ui->home_imgbtn_road = lv_imgbtn_create(ui->home_home_home_3, NULL);

    //Write style LV_IMGBTN_PART_MAIN for home_imgbtn_road
    static lv_style_t style_home_imgbtn_road_main;
    lv_style_reset(&style_home_imgbtn_road_main);

    //Write style state: LV_STATE_DEFAULT for style_home_imgbtn_road_main
    lv_style_set_text_color(&style_home_imgbtn_road_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
    lv_style_set_image_recolor(&style_home_imgbtn_road_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
    lv_style_set_image_recolor_opa(&style_home_imgbtn_road_main, LV_STATE_DEFAULT, 0);
    lv_style_set_image_opa(&style_home_imgbtn_road_main, LV_STATE_DEFAULT, 255);

    //Write style state: LV_STATE_PRESSED for style_home_imgbtn_road_main
    lv_style_set_text_color(&style_home_imgbtn_road_main, LV_STATE_PRESSED, lv_color_make(0xFF, 0x33, 0xFF));
    lv_style_set_image_recolor(&style_home_imgbtn_road_main, LV_STATE_PRESSED, lv_color_make(0x00, 0x00, 0x00));
    lv_style_set_image_recolor_opa(&style_home_imgbtn_road_main, LV_STATE_PRESSED, 0);

    //Write style state: LV_STATE_CHECKED for style_home_imgbtn_road_main
    lv_style_set_text_color(&style_home_imgbtn_road_main, LV_STATE_CHECKED, lv_color_make(0xFF, 0x33, 0xFF));
    lv_style_set_image_recolor(&style_home_imgbtn_road_main, LV_STATE_CHECKED, lv_color_make(0x00, 0x00, 0x00));
    lv_style_set_image_recolor_opa(&style_home_imgbtn_road_main, LV_STATE_CHECKED, 0);
    lv_obj_add_style(ui->home_imgbtn_road, LV_IMGBTN_PART_MAIN, &style_home_imgbtn_road_main);
    lv_obj_set_pos(ui->home_imgbtn_road, 30, 38);
    lv_obj_set_size(ui->home_imgbtn_road, 47, 47);
    lv_tileview_add_element(ui->home_home, ui->home_imgbtn_road);
    lv_imgbtn_set_src(ui->home_imgbtn_road,LV_BTN_STATE_RELEASED,&_home_road_alpha_47x47);
    lv_imgbtn_set_checkable(ui->home_imgbtn_road, true);

    //Write codes home_home_home_4
    ui->home_home_home_4 = lv_obj_create(ui->home_home, NULL);
    lv_obj_set_style_local_bg_opa(ui->home_home_home_4, LV_OBJ_PART_MAIN, LV_STATE_DEFAULT, 0);
    lv_obj_set_style_local_border_width(ui->home_home_home_4, LV_OBJ_PART_MAIN, LV_STATE_FOCUSED, 0);
    lv_obj_set_pos(ui->home_home_home_4, 0, 3*240);
    lv_obj_set_size(ui->home_home_home_4, 240, 240);
    lv_tileview_add_element(ui->home_home, ui->home_home_home_4);

    //Write codes home_line_mid_h_home4
    ui->home_line_mid_h_home4 = lv_line_create(ui->home_home_home_4, NULL);

    //Write style LV_LINE_PART_MAIN for home_line_mid_h_home4
    static lv_style_t style_home_line_mid_h_home4_main;
    lv_style_reset(&style_home_line_mid_h_home4_main);

    //Write style state: LV_STATE_DEFAULT for style_home_line_mid_h_home4_main
    lv_style_set_line_color(&style_home_line_mid_h_home4_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
    lv_style_set_line_width(&style_home_line_mid_h_home4_main, LV_STATE_DEFAULT, 3);
    lv_obj_add_style(ui->home_line_mid_h_home4, LV_LINE_PART_MAIN, &style_home_line_mid_h_home4_main);
    lv_obj_set_pos(ui->home_line_mid_h_home4, 102, 0);
    lv_obj_set_size(ui->home_line_mid_h_home4, 10, 240);
    lv_tileview_add_element(ui->home_home, ui->home_line_mid_h_home4);
    static lv_point_t home_line_mid_h_home4[] ={{9,0},{9,240}};
    lv_line_set_points(ui->home_line_mid_h_home4,home_line_mid_h_home4,2);

    //Write codes home_label_classific_study
    ui->home_label_classific_study = lv_label_create(ui->home_home_home_4, NULL);
    lv_label_set_text(ui->home_label_classific_study, "图像学习");
    lv_label_set_long_mode(ui->home_label_classific_study, LV_LABEL_LONG_BREAK);
    lv_label_set_align(ui->home_label_classific_study, LV_LABEL_ALIGN_CENTER);

    //Write style LV_LABEL_PART_MAIN for home_label_classific_study
    static lv_style_t style_home_label_classific_study_main;
    lv_style_reset(&style_home_label_classific_study_main);

    //Write style state: LV_STATE_DEFAULT for style_home_label_classific_study_main
    lv_style_set_radius(&style_home_label_classific_study_main, LV_STATE_DEFAULT, 0);
    lv_style_set_bg_color(&style_home_label_classific_study_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
    lv_style_set_bg_grad_color(&style_home_label_classific_study_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
    lv_style_set_bg_grad_dir(&style_home_label_classific_study_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
    lv_style_set_bg_opa(&style_home_label_classific_study_main, LV_STATE_DEFAULT, 0);
    lv_style_set_text_color(&style_home_label_classific_study_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
    lv_style_set_text_font(&style_home_label_classific_study_main, LV_STATE_DEFAULT, &lv_font_simsun_15);
    lv_style_set_text_letter_space(&style_home_label_classific_study_main, LV_STATE_DEFAULT, 2);
    lv_style_set_pad_left(&style_home_label_classific_study_main, LV_STATE_DEFAULT, 0);
    lv_style_set_pad_right(&style_home_label_classific_study_main, LV_STATE_DEFAULT, 0);
    lv_style_set_pad_top(&style_home_label_classific_study_main, LV_STATE_DEFAULT, 0);
    lv_style_set_pad_bottom(&style_home_label_classific_study_main, LV_STATE_DEFAULT, 0);
    lv_obj_add_style(ui->home_label_classific_study, LV_LABEL_PART_MAIN, &style_home_label_classific_study_main);
    lv_obj_set_pos(ui->home_label_classific_study, 135, 215);
    lv_obj_set_size(ui->home_label_classific_study, 68, 0);
    lv_tileview_add_element(ui->home_home, ui->home_label_classific_study);

    //Write codes home_label_classific
    ui->home_label_classific = lv_label_create(ui->home_home_home_4, NULL);
    lv_label_set_text(ui->home_label_classific, "图像分类");
    lv_label_set_long_mode(ui->home_label_classific, LV_LABEL_LONG_BREAK);
    lv_label_set_align(ui->home_label_classific, LV_LABEL_ALIGN_CENTER);

    //Write style LV_LABEL_PART_MAIN for home_label_classific
    static lv_style_t style_home_label_classific_main;
    lv_style_reset(&style_home_label_classific_main);

    //Write style state: LV_STATE_DEFAULT for style_home_label_classific_main
    lv_style_set_radius(&style_home_label_classific_main, LV_STATE_DEFAULT, 0);
    lv_style_set_bg_color(&style_home_label_classific_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
    lv_style_set_bg_grad_color(&style_home_label_classific_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
    lv_style_set_bg_grad_dir(&style_home_label_classific_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
    lv_style_set_bg_opa(&style_home_label_classific_main, LV_STATE_DEFAULT, 0);
    lv_style_set_text_color(&style_home_label_classific_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
    lv_style_set_text_font(&style_home_label_classific_main, LV_STATE_DEFAULT, &lv_font_simsun_15);
    lv_style_set_text_letter_space(&style_home_label_classific_main, LV_STATE_DEFAULT, 2);
    lv_style_set_pad_left(&style_home_label_classific_main, LV_STATE_DEFAULT, 0);
    lv_style_set_pad_right(&style_home_label_classific_main, LV_STATE_DEFAULT, 0);
    lv_style_set_pad_top(&style_home_label_classific_main, LV_STATE_DEFAULT, 0);
    lv_style_set_pad_bottom(&style_home_label_classific_main, LV_STATE_DEFAULT, 0);
    lv_obj_add_style(ui->home_label_classific, LV_LABEL_PART_MAIN, &style_home_label_classific_main);
    lv_obj_set_pos(ui->home_label_classific, 20, 215);
    lv_obj_set_size(ui->home_label_classific, 68, 0);
    lv_tileview_add_element(ui->home_home, ui->home_label_classific);

    //Write codes home_label_five_road
    ui->home_label_five_road = lv_label_create(ui->home_home_home_4, NULL);
    lv_label_set_text(ui->home_label_five_road, "五通道巡线");
    lv_label_set_long_mode(ui->home_label_five_road, LV_LABEL_LONG_BREAK);
    lv_label_set_align(ui->home_label_five_road, LV_LABEL_ALIGN_CENTER);

    //Write style LV_LABEL_PART_MAIN for home_label_five_road
    static lv_style_t style_home_label_five_road_main;
    lv_style_reset(&style_home_label_five_road_main);

    //Write style state: LV_STATE_DEFAULT for style_home_label_five_road_main
    lv_style_set_radius(&style_home_label_five_road_main, LV_STATE_DEFAULT, 0);
    lv_style_set_bg_color(&style_home_label_five_road_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
    lv_style_set_bg_grad_color(&style_home_label_five_road_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
    lv_style_set_bg_grad_dir(&style_home_label_five_road_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
    lv_style_set_bg_opa(&style_home_label_five_road_main, LV_STATE_DEFAULT, 0);
    lv_style_set_text_color(&style_home_label_five_road_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
    lv_style_set_text_font(&style_home_label_five_road_main, LV_STATE_DEFAULT, &lv_font_simsun_15);
    lv_style_set_text_letter_space(&style_home_label_five_road_main, LV_STATE_DEFAULT, 2);
    lv_style_set_pad_left(&style_home_label_five_road_main, LV_STATE_DEFAULT, 0);
    lv_style_set_pad_right(&style_home_label_five_road_main, LV_STATE_DEFAULT, 0);
    lv_style_set_pad_top(&style_home_label_five_road_main, LV_STATE_DEFAULT, 0);
    lv_style_set_pad_bottom(&style_home_label_five_road_main, LV_STATE_DEFAULT, 0);
    lv_obj_add_style(ui->home_label_five_road, LV_LABEL_PART_MAIN, &style_home_label_five_road_main);
    lv_obj_set_pos(ui->home_label_five_road, 125, 99);
    lv_obj_set_size(ui->home_label_five_road, 86, 0);
    lv_tileview_add_element(ui->home_home, ui->home_label_five_road);

    //Write codes home_label_cube
    ui->home_label_cube = lv_label_create(ui->home_home_home_4, NULL);
    lv_label_set_text(ui->home_label_cube, "魔方识别");
    lv_label_set_long_mode(ui->home_label_cube, LV_LABEL_LONG_BREAK);
    lv_label_set_align(ui->home_label_cube, LV_LABEL_ALIGN_CENTER);

    //Write style LV_LABEL_PART_MAIN for home_label_cube
    static lv_style_t style_home_label_cube_main;
    lv_style_reset(&style_home_label_cube_main);

    //Write style state: LV_STATE_DEFAULT for style_home_label_cube_main
    lv_style_set_radius(&style_home_label_cube_main, LV_STATE_DEFAULT, 0);
    lv_style_set_bg_color(&style_home_label_cube_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
    lv_style_set_bg_grad_color(&style_home_label_cube_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
    lv_style_set_bg_grad_dir(&style_home_label_cube_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
    lv_style_set_bg_opa(&style_home_label_cube_main, LV_STATE_DEFAULT, 0);
    lv_style_set_text_color(&style_home_label_cube_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
    lv_style_set_text_font(&style_home_label_cube_main, LV_STATE_DEFAULT, &lv_font_simsun_15);
    lv_style_set_text_letter_space(&style_home_label_cube_main, LV_STATE_DEFAULT, 2);
    lv_style_set_pad_left(&style_home_label_cube_main, LV_STATE_DEFAULT, 0);
    lv_style_set_pad_right(&style_home_label_cube_main, LV_STATE_DEFAULT, 0);
    lv_style_set_pad_top(&style_home_label_cube_main, LV_STATE_DEFAULT, 0);
    lv_style_set_pad_bottom(&style_home_label_cube_main, LV_STATE_DEFAULT, 0);
    lv_obj_add_style(ui->home_label_cube, LV_LABEL_PART_MAIN, &style_home_label_cube_main);
    lv_obj_set_pos(ui->home_label_cube, 20, 98);
    lv_obj_set_size(ui->home_label_cube, 68, 0);
    lv_tileview_add_element(ui->home_home, ui->home_label_cube);

    //Write codes home_imgbtn_five_road
    ui->home_imgbtn_five_road = lv_imgbtn_create(ui->home_home_home_4, NULL);

    //Write style LV_IMGBTN_PART_MAIN for home_imgbtn_five_road
    static lv_style_t style_home_imgbtn_five_road_main;
    lv_style_reset(&style_home_imgbtn_five_road_main);

    //Write style state: LV_STATE_DEFAULT for style_home_imgbtn_five_road_main
    lv_style_set_text_color(&style_home_imgbtn_five_road_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
    lv_style_set_image_recolor(&style_home_imgbtn_five_road_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
    lv_style_set_image_recolor_opa(&style_home_imgbtn_five_road_main, LV_STATE_DEFAULT, 0);
    lv_style_set_image_opa(&style_home_imgbtn_five_road_main, LV_STATE_DEFAULT, 255);

    //Write style state: LV_STATE_PRESSED for style_home_imgbtn_five_road_main
    lv_style_set_text_color(&style_home_imgbtn_five_road_main, LV_STATE_PRESSED, lv_color_make(0xFF, 0x33, 0xFF));
    lv_style_set_image_recolor(&style_home_imgbtn_five_road_main, LV_STATE_PRESSED, lv_color_make(0x00, 0x00, 0x00));
    lv_style_set_image_recolor_opa(&style_home_imgbtn_five_road_main, LV_STATE_PRESSED, 0);

    //Write style state: LV_STATE_CHECKED for style_home_imgbtn_five_road_main
    lv_style_set_text_color(&style_home_imgbtn_five_road_main, LV_STATE_CHECKED, lv_color_make(0xFF, 0x33, 0xFF));
    lv_style_set_image_recolor(&style_home_imgbtn_five_road_main, LV_STATE_CHECKED, lv_color_make(0x00, 0x00, 0x00));
    lv_style_set_image_recolor_opa(&style_home_imgbtn_five_road_main, LV_STATE_CHECKED, 0);
    lv_obj_add_style(ui->home_imgbtn_five_road, LV_IMGBTN_PART_MAIN, &style_home_imgbtn_five_road_main);
    lv_obj_set_pos(ui->home_imgbtn_five_road, 130, 50);
    lv_obj_set_size(ui->home_imgbtn_five_road, 72, 30);
    lv_tileview_add_element(ui->home_home, ui->home_imgbtn_five_road);
    lv_imgbtn_set_src(ui->home_imgbtn_five_road,LV_BTN_STATE_RELEASED,&_home_five_road_alpha_72x30);
    lv_imgbtn_set_checkable(ui->home_imgbtn_five_road, true);

    //Write codes home_imgbtn_classific
    ui->home_imgbtn_classific = lv_imgbtn_create(ui->home_home_home_4, NULL);

    //Write style LV_IMGBTN_PART_MAIN for home_imgbtn_classific
    static lv_style_t style_home_imgbtn_classific_main;
    lv_style_reset(&style_home_imgbtn_classific_main);

    //Write style state: LV_STATE_DEFAULT for style_home_imgbtn_classific_main
    lv_style_set_text_color(&style_home_imgbtn_classific_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
    lv_style_set_image_recolor(&style_home_imgbtn_classific_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
    lv_style_set_image_recolor_opa(&style_home_imgbtn_classific_main, LV_STATE_DEFAULT, 0);
    lv_style_set_image_opa(&style_home_imgbtn_classific_main, LV_STATE_DEFAULT, 255);

    //Write style state: LV_STATE_PRESSED for style_home_imgbtn_classific_main
    lv_style_set_text_color(&style_home_imgbtn_classific_main, LV_STATE_PRESSED, lv_color_make(0xFF, 0x33, 0xFF));
    lv_style_set_image_recolor(&style_home_imgbtn_classific_main, LV_STATE_PRESSED, lv_color_make(0x00, 0x00, 0x00));
    lv_style_set_image_recolor_opa(&style_home_imgbtn_classific_main, LV_STATE_PRESSED, 0);

    //Write style state: LV_STATE_CHECKED for style_home_imgbtn_classific_main
    lv_style_set_text_color(&style_home_imgbtn_classific_main, LV_STATE_CHECKED, lv_color_make(0xFF, 0x33, 0xFF));
    lv_style_set_image_recolor(&style_home_imgbtn_classific_main, LV_STATE_CHECKED, lv_color_make(0x00, 0x00, 0x00));
    lv_style_set_image_recolor_opa(&style_home_imgbtn_classific_main, LV_STATE_CHECKED, 0);
    lv_obj_add_style(ui->home_imgbtn_classific, LV_IMGBTN_PART_MAIN, &style_home_imgbtn_classific_main);
    lv_obj_set_pos(ui->home_imgbtn_classific, 30, 152);
    lv_obj_set_size(ui->home_imgbtn_classific, 47, 47);
    lv_tileview_add_element(ui->home_home, ui->home_imgbtn_classific);
    lv_imgbtn_set_src(ui->home_imgbtn_classific,LV_BTN_STATE_RELEASED,&_home_classific_alpha_47x47);
    lv_imgbtn_set_checkable(ui->home_imgbtn_classific, true);

    //Write codes home_imgbtn_classific_study
    ui->home_imgbtn_classific_study = lv_imgbtn_create(ui->home_home_home_4, NULL);

    //Write style LV_IMGBTN_PART_MAIN for home_imgbtn_classific_study
    static lv_style_t style_home_imgbtn_classific_study_main;
    lv_style_reset(&style_home_imgbtn_classific_study_main);

    //Write style state: LV_STATE_DEFAULT for style_home_imgbtn_classific_study_main
    lv_style_set_text_color(&style_home_imgbtn_classific_study_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
    lv_style_set_image_recolor(&style_home_imgbtn_classific_study_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
    lv_style_set_image_recolor_opa(&style_home_imgbtn_classific_study_main, LV_STATE_DEFAULT, 0);
    lv_style_set_image_opa(&style_home_imgbtn_classific_study_main, LV_STATE_DEFAULT, 255);

    //Write style state: LV_STATE_PRESSED for style_home_imgbtn_classific_study_main
    lv_style_set_text_color(&style_home_imgbtn_classific_study_main, LV_STATE_PRESSED, lv_color_make(0xFF, 0x33, 0xFF));
    lv_style_set_image_recolor(&style_home_imgbtn_classific_study_main, LV_STATE_PRESSED, lv_color_make(0x00, 0x00, 0x00));
    lv_style_set_image_recolor_opa(&style_home_imgbtn_classific_study_main, LV_STATE_PRESSED, 0);

    //Write style state: LV_STATE_CHECKED for style_home_imgbtn_classific_study_main
    lv_style_set_text_color(&style_home_imgbtn_classific_study_main, LV_STATE_CHECKED, lv_color_make(0xFF, 0x33, 0xFF));
    lv_style_set_image_recolor(&style_home_imgbtn_classific_study_main, LV_STATE_CHECKED, lv_color_make(0x00, 0x00, 0x00));
    lv_style_set_image_recolor_opa(&style_home_imgbtn_classific_study_main, LV_STATE_CHECKED, 0);
    lv_obj_add_style(ui->home_imgbtn_classific_study, LV_IMGBTN_PART_MAIN, &style_home_imgbtn_classific_study_main);
    lv_obj_set_pos(ui->home_imgbtn_classific_study, 142, 152);
    lv_obj_set_size(ui->home_imgbtn_classific_study, 49, 49);
    lv_tileview_add_element(ui->home_home, ui->home_imgbtn_classific_study);
    lv_imgbtn_set_src(ui->home_imgbtn_classific_study,LV_BTN_STATE_RELEASED,&_home_image_s_alpha_49x49);
    lv_imgbtn_set_checkable(ui->home_imgbtn_classific_study, true);

    //Write codes home_imgbtn_cube
    ui->home_imgbtn_cube = lv_imgbtn_create(ui->home_home_home_4, NULL);

    //Write style LV_IMGBTN_PART_MAIN for home_imgbtn_cube
    static lv_style_t style_home_imgbtn_cube_main;
    lv_style_reset(&style_home_imgbtn_cube_main);

    //Write style state: LV_STATE_DEFAULT for style_home_imgbtn_cube_main
    lv_style_set_text_color(&style_home_imgbtn_cube_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
    lv_style_set_image_recolor(&style_home_imgbtn_cube_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
    lv_style_set_image_recolor_opa(&style_home_imgbtn_cube_main, LV_STATE_DEFAULT, 0);
    lv_style_set_image_opa(&style_home_imgbtn_cube_main, LV_STATE_DEFAULT, 255);

    //Write style state: LV_STATE_PRESSED for style_home_imgbtn_cube_main
    lv_style_set_text_color(&style_home_imgbtn_cube_main, LV_STATE_PRESSED, lv_color_make(0xFF, 0x33, 0xFF));
    lv_style_set_image_recolor(&style_home_imgbtn_cube_main, LV_STATE_PRESSED, lv_color_make(0x00, 0x00, 0x00));
    lv_style_set_image_recolor_opa(&style_home_imgbtn_cube_main, LV_STATE_PRESSED, 0);

    //Write style state: LV_STATE_CHECKED for style_home_imgbtn_cube_main
    lv_style_set_text_color(&style_home_imgbtn_cube_main, LV_STATE_CHECKED, lv_color_make(0xFF, 0x33, 0xFF));
    lv_style_set_image_recolor(&style_home_imgbtn_cube_main, LV_STATE_CHECKED, lv_color_make(0x00, 0x00, 0x00));
    lv_style_set_image_recolor_opa(&style_home_imgbtn_cube_main, LV_STATE_CHECKED, 0);
    lv_obj_add_style(ui->home_imgbtn_cube, LV_IMGBTN_PART_MAIN, &style_home_imgbtn_cube_main);
    lv_obj_set_pos(ui->home_imgbtn_cube, 25, 35);
    lv_obj_set_size(ui->home_imgbtn_cube, 52, 53);
    lv_tileview_add_element(ui->home_home, ui->home_imgbtn_cube);
    lv_imgbtn_set_src(ui->home_imgbtn_cube,LV_BTN_STATE_RELEASED,&_home_cube_alpha_52x53);
    lv_imgbtn_set_checkable(ui->home_imgbtn_cube, true);

    //Write codes home_line_bottom_h_home4
    ui->home_line_bottom_h_home4 = lv_line_create(ui->home_home_home_4, NULL);

    //Write style LV_LINE_PART_MAIN for home_line_bottom_h_home4
    static lv_style_t style_home_line_bottom_h_home4_main;
    lv_style_reset(&style_home_line_bottom_h_home4_main);

    //Write style state: LV_STATE_DEFAULT for style_home_line_bottom_h_home4_main
    lv_style_set_line_color(&style_home_line_bottom_h_home4_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
    lv_style_set_line_width(&style_home_line_bottom_h_home4_main, LV_STATE_DEFAULT, 3);
    lv_obj_add_style(ui->home_line_bottom_h_home4, LV_LINE_PART_MAIN, &style_home_line_bottom_h_home4_main);
    lv_obj_set_pos(ui->home_line_bottom_h_home4, 0, 230);
    lv_obj_set_size(ui->home_line_bottom_h_home4, 225, 10);
    lv_tileview_add_element(ui->home_home, ui->home_line_bottom_h_home4);
    static lv_point_t home_line_bottom_h_home4[] ={{0,6},{223,6}};
    lv_line_set_points(ui->home_line_bottom_h_home4,home_line_bottom_h_home4,2);

    //Write codes home_line_right_h_home4
    ui->home_line_right_h_home4 = lv_line_create(ui->home_home_home_4, NULL);

    //Write style LV_LINE_PART_MAIN for home_line_right_h_home4
    static lv_style_t style_home_line_right_h_home4_main;
    lv_style_reset(&style_home_line_right_h_home4_main);

    //Write style state: LV_STATE_DEFAULT for style_home_line_right_h_home4_main
    lv_style_set_line_color(&style_home_line_right_h_home4_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
    lv_style_set_line_width(&style_home_line_right_h_home4_main, LV_STATE_DEFAULT, 3);
    lv_obj_add_style(ui->home_line_right_h_home4, LV_LINE_PART_MAIN, &style_home_line_right_h_home4_main);
    lv_obj_set_pos(ui->home_line_right_h_home4, 220, 0);
    lv_obj_set_size(ui->home_line_right_h_home4, 10, 240);
    lv_tileview_add_element(ui->home_home, ui->home_line_right_h_home4);
    static lv_point_t home_line_right_h_home4[] ={{3,0},{3,240}};
    lv_line_set_points(ui->home_line_right_h_home4,home_line_right_h_home4,2);

    //Write codes home_line_mid_v_home4
    ui->home_line_mid_v_home4 = lv_line_create(ui->home_home_home_4, NULL);

    //Write style LV_LINE_PART_MAIN for home_line_mid_v_home4
    static lv_style_t style_home_line_mid_v_home4_main;
    lv_style_reset(&style_home_line_mid_v_home4_main);

    //Write style state: LV_STATE_DEFAULT for style_home_line_mid_v_home4_main
    lv_style_set_line_color(&style_home_line_mid_v_home4_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
    lv_style_set_line_width(&style_home_line_mid_v_home4_main, LV_STATE_DEFAULT, 3);
    lv_obj_add_style(ui->home_line_mid_v_home4, LV_LINE_PART_MAIN, &style_home_line_mid_v_home4_main);
    lv_obj_set_pos(ui->home_line_mid_v_home4, 0, 118);
    lv_obj_set_size(ui->home_line_mid_v_home4, 225, 10);
    lv_tileview_add_element(ui->home_home, ui->home_line_mid_v_home4);
    static lv_point_t home_line_mid_v_home4[] ={{0,0},{223,0}};
    lv_line_set_points(ui->home_line_mid_v_home4,home_line_mid_v_home4,2);

    //Write codes home_home_home_5
    ui->home_home_home_5 = lv_obj_create(ui->home_home, NULL);
    lv_obj_set_style_local_bg_opa(ui->home_home_home_5, LV_OBJ_PART_MAIN, LV_STATE_DEFAULT, 0);
    lv_obj_set_style_local_border_width(ui->home_home_home_5, LV_OBJ_PART_MAIN, LV_STATE_FOCUSED, 0);
    lv_obj_set_pos(ui->home_home_home_5, 0, 4*240);
    lv_obj_set_size(ui->home_home_home_5, 240, 240);
    lv_tileview_add_element(ui->home_home, ui->home_home_home_5);

    //Write codes home_line_right_h_home5
    ui->home_line_right_h_home5 = lv_line_create(ui->home_home_home_5, NULL);

    //Write style LV_LINE_PART_MAIN for home_line_right_h_home5
    static lv_style_t style_home_line_right_h_home5_main;
    lv_style_reset(&style_home_line_right_h_home5_main);

    //Write style state: LV_STATE_DEFAULT for style_home_line_right_h_home5_main
    lv_style_set_line_color(&style_home_line_right_h_home5_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
    lv_style_set_line_width(&style_home_line_right_h_home5_main, LV_STATE_DEFAULT, 3);
    lv_obj_add_style(ui->home_line_right_h_home5, LV_LINE_PART_MAIN, &style_home_line_right_h_home5_main);
    lv_obj_set_pos(ui->home_line_right_h_home5, 220, 0);
    lv_obj_set_size(ui->home_line_right_h_home5, 10, 240);
    lv_tileview_add_element(ui->home_home, ui->home_line_right_h_home5);
    static lv_point_t home_line_right_h_home5[] ={{3,0},{3,240}};
    lv_line_set_points(ui->home_line_right_h_home5,home_line_right_h_home5,2);

    //Write codes home_label_speech_interaction
    ui->home_label_speech_interaction = lv_label_create(ui->home_home_home_5, NULL);
    lv_label_set_text(ui->home_label_speech_interaction, "语音交互");
    lv_label_set_long_mode(ui->home_label_speech_interaction, LV_LABEL_LONG_BREAK);
    lv_label_set_align(ui->home_label_speech_interaction, LV_LABEL_ALIGN_CENTER);

    //Write style LV_LABEL_PART_MAIN for home_label_speech_interaction
    static lv_style_t style_home_label_speech_interaction_main;
    lv_style_reset(&style_home_label_speech_interaction_main);

    //Write style state: LV_STATE_DEFAULT for style_home_label_speech_interaction_main
    lv_style_set_radius(&style_home_label_speech_interaction_main, LV_STATE_DEFAULT, 0);
    lv_style_set_bg_color(&style_home_label_speech_interaction_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
    lv_style_set_bg_grad_color(&style_home_label_speech_interaction_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
    lv_style_set_bg_grad_dir(&style_home_label_speech_interaction_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
    lv_style_set_bg_opa(&style_home_label_speech_interaction_main, LV_STATE_DEFAULT, 0);
    lv_style_set_text_color(&style_home_label_speech_interaction_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
    lv_style_set_text_font(&style_home_label_speech_interaction_main, LV_STATE_DEFAULT, &lv_font_simsun_15);
    lv_style_set_text_letter_space(&style_home_label_speech_interaction_main, LV_STATE_DEFAULT, 2);
    lv_style_set_pad_left(&style_home_label_speech_interaction_main, LV_STATE_DEFAULT, 0);
    lv_style_set_pad_right(&style_home_label_speech_interaction_main, LV_STATE_DEFAULT, 0);
    lv_style_set_pad_top(&style_home_label_speech_interaction_main, LV_STATE_DEFAULT, 0);
    lv_style_set_pad_bottom(&style_home_label_speech_interaction_main, LV_STATE_DEFAULT, 0);
    lv_obj_add_style(ui->home_label_speech_interaction, LV_LABEL_PART_MAIN, &style_home_label_speech_interaction_main);
    lv_obj_set_pos(ui->home_label_speech_interaction, 135, 215);
    lv_obj_set_size(ui->home_label_speech_interaction, 68, 0);
    lv_tileview_add_element(ui->home_home, ui->home_label_speech_interaction);

    //Write codes home_label_word_study
    ui->home_label_word_study = lv_label_create(ui->home_home_home_5, NULL);
    lv_label_set_text(ui->home_label_word_study, "语音学习");
    lv_label_set_long_mode(ui->home_label_word_study, LV_LABEL_LONG_BREAK);
    lv_label_set_align(ui->home_label_word_study, LV_LABEL_ALIGN_CENTER);

    //Write style LV_LABEL_PART_MAIN for home_label_word_study
    static lv_style_t style_home_label_word_study_main;
    lv_style_reset(&style_home_label_word_study_main);

    //Write style state: LV_STATE_DEFAULT for style_home_label_word_study_main
    lv_style_set_radius(&style_home_label_word_study_main, LV_STATE_DEFAULT, 0);
    lv_style_set_bg_color(&style_home_label_word_study_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
    lv_style_set_bg_grad_color(&style_home_label_word_study_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
    lv_style_set_bg_grad_dir(&style_home_label_word_study_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
    lv_style_set_bg_opa(&style_home_label_word_study_main, LV_STATE_DEFAULT, 0);
    lv_style_set_text_color(&style_home_label_word_study_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
    lv_style_set_text_font(&style_home_label_word_study_main, LV_STATE_DEFAULT, &lv_font_simsun_15);
    lv_style_set_text_letter_space(&style_home_label_word_study_main, LV_STATE_DEFAULT, 2);
    lv_style_set_pad_left(&style_home_label_word_study_main, LV_STATE_DEFAULT, 0);
    lv_style_set_pad_right(&style_home_label_word_study_main, LV_STATE_DEFAULT, 0);
    lv_style_set_pad_top(&style_home_label_word_study_main, LV_STATE_DEFAULT, 0);
    lv_style_set_pad_bottom(&style_home_label_word_study_main, LV_STATE_DEFAULT, 0);
    lv_obj_add_style(ui->home_label_word_study, LV_LABEL_PART_MAIN, &style_home_label_word_study_main);
    lv_obj_set_pos(ui->home_label_word_study, 20, 215);
    lv_obj_set_size(ui->home_label_word_study, 68, 0);
    lv_tileview_add_element(ui->home_home, ui->home_label_word_study);

    //Write codes home_label_key_word
    ui->home_label_key_word = lv_label_create(ui->home_home_home_5, NULL);
    lv_label_set_text(ui->home_label_key_word, "关键词识别");
    lv_label_set_long_mode(ui->home_label_key_word, LV_LABEL_LONG_BREAK);
    lv_label_set_align(ui->home_label_key_word, LV_LABEL_ALIGN_CENTER);

    //Write style LV_LABEL_PART_MAIN for home_label_key_word
    static lv_style_t style_home_label_key_word_main;
    lv_style_reset(&style_home_label_key_word_main);

    //Write style state: LV_STATE_DEFAULT for style_home_label_key_word_main
    lv_style_set_radius(&style_home_label_key_word_main, LV_STATE_DEFAULT, 0);
    lv_style_set_bg_color(&style_home_label_key_word_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
    lv_style_set_bg_grad_color(&style_home_label_key_word_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
    lv_style_set_bg_grad_dir(&style_home_label_key_word_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
    lv_style_set_bg_opa(&style_home_label_key_word_main, LV_STATE_DEFAULT, 0);
    lv_style_set_text_color(&style_home_label_key_word_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
    lv_style_set_text_font(&style_home_label_key_word_main, LV_STATE_DEFAULT, &lv_font_simsun_15);
    lv_style_set_text_letter_space(&style_home_label_key_word_main, LV_STATE_DEFAULT, 2);
    lv_style_set_pad_left(&style_home_label_key_word_main, LV_STATE_DEFAULT, 0);
    lv_style_set_pad_right(&style_home_label_key_word_main, LV_STATE_DEFAULT, 0);
    lv_style_set_pad_top(&style_home_label_key_word_main, LV_STATE_DEFAULT, 0);
    lv_style_set_pad_bottom(&style_home_label_key_word_main, LV_STATE_DEFAULT, 0);
    lv_obj_add_style(ui->home_label_key_word, LV_LABEL_PART_MAIN, &style_home_label_key_word_main);
    lv_obj_set_pos(ui->home_label_key_word, 125, 98);
    lv_obj_set_size(ui->home_label_key_word, 88, 0);
    lv_tileview_add_element(ui->home_home, ui->home_label_key_word);

    //Write codes home_label_speech
    ui->home_label_speech = lv_label_create(ui->home_home_home_5, NULL);
    lv_label_set_text(ui->home_label_speech, "语音识别");
    lv_label_set_long_mode(ui->home_label_speech, LV_LABEL_LONG_BREAK);
    lv_label_set_align(ui->home_label_speech, LV_LABEL_ALIGN_CENTER);

    //Write style LV_LABEL_PART_MAIN for home_label_speech
    static lv_style_t style_home_label_speech_main;
    lv_style_reset(&style_home_label_speech_main);

    //Write style state: LV_STATE_DEFAULT for style_home_label_speech_main
    lv_style_set_radius(&style_home_label_speech_main, LV_STATE_DEFAULT, 0);
    lv_style_set_bg_color(&style_home_label_speech_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
    lv_style_set_bg_grad_color(&style_home_label_speech_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
    lv_style_set_bg_grad_dir(&style_home_label_speech_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
    lv_style_set_bg_opa(&style_home_label_speech_main, LV_STATE_DEFAULT, 0);
    lv_style_set_text_color(&style_home_label_speech_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
    lv_style_set_text_font(&style_home_label_speech_main, LV_STATE_DEFAULT, &lv_font_simsun_15);
    lv_style_set_text_letter_space(&style_home_label_speech_main, LV_STATE_DEFAULT, 2);
    lv_style_set_pad_left(&style_home_label_speech_main, LV_STATE_DEFAULT, 0);
    lv_style_set_pad_right(&style_home_label_speech_main, LV_STATE_DEFAULT, 0);
    lv_style_set_pad_top(&style_home_label_speech_main, LV_STATE_DEFAULT, 0);
    lv_style_set_pad_bottom(&style_home_label_speech_main, LV_STATE_DEFAULT, 0);
    lv_obj_add_style(ui->home_label_speech, LV_LABEL_PART_MAIN, &style_home_label_speech_main);
    lv_obj_set_pos(ui->home_label_speech, 20, 98);
    lv_obj_set_size(ui->home_label_speech, 68, 0);
    lv_tileview_add_element(ui->home_home, ui->home_label_speech);

    //Write codes home_imgbtn_speech_interaction
    ui->home_imgbtn_speech_interaction = lv_imgbtn_create(ui->home_home_home_5, NULL);

    //Write style LV_IMGBTN_PART_MAIN for home_imgbtn_speech_interaction
    static lv_style_t style_home_imgbtn_speech_interaction_main;
    lv_style_reset(&style_home_imgbtn_speech_interaction_main);

    //Write style state: LV_STATE_DEFAULT for style_home_imgbtn_speech_interaction_main
    lv_style_set_text_color(&style_home_imgbtn_speech_interaction_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
    lv_style_set_image_recolor(&style_home_imgbtn_speech_interaction_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
    lv_style_set_image_recolor_opa(&style_home_imgbtn_speech_interaction_main, LV_STATE_DEFAULT, 0);
    lv_style_set_image_opa(&style_home_imgbtn_speech_interaction_main, LV_STATE_DEFAULT, 255);

    //Write style state: LV_STATE_PRESSED for style_home_imgbtn_speech_interaction_main
    lv_style_set_text_color(&style_home_imgbtn_speech_interaction_main, LV_STATE_PRESSED, lv_color_make(0xFF, 0x33, 0xFF));
    lv_style_set_image_recolor(&style_home_imgbtn_speech_interaction_main, LV_STATE_PRESSED, lv_color_make(0x00, 0x00, 0x00));
    lv_style_set_image_recolor_opa(&style_home_imgbtn_speech_interaction_main, LV_STATE_PRESSED, 0);

    //Write style state: LV_STATE_CHECKED for style_home_imgbtn_speech_interaction_main
    lv_style_set_text_color(&style_home_imgbtn_speech_interaction_main, LV_STATE_CHECKED, lv_color_make(0xFF, 0x33, 0xFF));
    lv_style_set_image_recolor(&style_home_imgbtn_speech_interaction_main, LV_STATE_CHECKED, lv_color_make(0x00, 0x00, 0x00));
    lv_style_set_image_recolor_opa(&style_home_imgbtn_speech_interaction_main, LV_STATE_CHECKED, 0);
    lv_obj_add_style(ui->home_imgbtn_speech_interaction, LV_IMGBTN_PART_MAIN, &style_home_imgbtn_speech_interaction_main);
    lv_obj_set_pos(ui->home_imgbtn_speech_interaction, 143, 152);
    lv_obj_set_size(ui->home_imgbtn_speech_interaction, 47, 47);
    lv_tileview_add_element(ui->home_home, ui->home_imgbtn_speech_interaction);
    lv_imgbtn_set_src(ui->home_imgbtn_speech_interaction,LV_BTN_STATE_RELEASED,&_home_speech_alpha_47x47);
    lv_imgbtn_set_checkable(ui->home_imgbtn_speech_interaction, true);

    //Write codes home_imgbtn_word_study
    ui->home_imgbtn_word_study = lv_imgbtn_create(ui->home_home_home_5, NULL);

    //Write style LV_IMGBTN_PART_MAIN for home_imgbtn_word_study
    static lv_style_t style_home_imgbtn_word_study_main;
    lv_style_reset(&style_home_imgbtn_word_study_main);

    //Write style state: LV_STATE_DEFAULT for style_home_imgbtn_word_study_main
    lv_style_set_text_color(&style_home_imgbtn_word_study_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
    lv_style_set_image_recolor(&style_home_imgbtn_word_study_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
    lv_style_set_image_recolor_opa(&style_home_imgbtn_word_study_main, LV_STATE_DEFAULT, 0);
    lv_style_set_image_opa(&style_home_imgbtn_word_study_main, LV_STATE_DEFAULT, 255);

    //Write style state: LV_STATE_PRESSED for style_home_imgbtn_word_study_main
    lv_style_set_text_color(&style_home_imgbtn_word_study_main, LV_STATE_PRESSED, lv_color_make(0xFF, 0x33, 0xFF));
    lv_style_set_image_recolor(&style_home_imgbtn_word_study_main, LV_STATE_PRESSED, lv_color_make(0x00, 0x00, 0x00));
    lv_style_set_image_recolor_opa(&style_home_imgbtn_word_study_main, LV_STATE_PRESSED, 0);

    //Write style state: LV_STATE_CHECKED for style_home_imgbtn_word_study_main
    lv_style_set_text_color(&style_home_imgbtn_word_study_main, LV_STATE_CHECKED, lv_color_make(0xFF, 0x33, 0xFF));
    lv_style_set_image_recolor(&style_home_imgbtn_word_study_main, LV_STATE_CHECKED, lv_color_make(0x00, 0x00, 0x00));
    lv_style_set_image_recolor_opa(&style_home_imgbtn_word_study_main, LV_STATE_CHECKED, 0);
    lv_obj_add_style(ui->home_imgbtn_word_study, LV_IMGBTN_PART_MAIN, &style_home_imgbtn_word_study_main);
    lv_obj_set_pos(ui->home_imgbtn_word_study, 30, 152);
    lv_obj_set_size(ui->home_imgbtn_word_study, 49, 49);
    lv_tileview_add_element(ui->home_home, ui->home_imgbtn_word_study);
    lv_imgbtn_set_src(ui->home_imgbtn_word_study,LV_BTN_STATE_RELEASED,&_home_speech_study_alpha_49x49);
    lv_imgbtn_set_checkable(ui->home_imgbtn_word_study, true);

    //Write codes home_imgbtn_key_word
    ui->home_imgbtn_key_word = lv_imgbtn_create(ui->home_home_home_5, NULL);

    //Write style LV_IMGBTN_PART_MAIN for home_imgbtn_key_word
    static lv_style_t style_home_imgbtn_key_word_main;
    lv_style_reset(&style_home_imgbtn_key_word_main);

    //Write style state: LV_STATE_DEFAULT for style_home_imgbtn_key_word_main
    lv_style_set_text_color(&style_home_imgbtn_key_word_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
    lv_style_set_image_recolor(&style_home_imgbtn_key_word_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
    lv_style_set_image_recolor_opa(&style_home_imgbtn_key_word_main, LV_STATE_DEFAULT, 0);
    lv_style_set_image_opa(&style_home_imgbtn_key_word_main, LV_STATE_DEFAULT, 255);

    //Write style state: LV_STATE_PRESSED for style_home_imgbtn_key_word_main
    lv_style_set_text_color(&style_home_imgbtn_key_word_main, LV_STATE_PRESSED, lv_color_make(0xFF, 0x33, 0xFF));
    lv_style_set_image_recolor(&style_home_imgbtn_key_word_main, LV_STATE_PRESSED, lv_color_make(0x00, 0x00, 0x00));
    lv_style_set_image_recolor_opa(&style_home_imgbtn_key_word_main, LV_STATE_PRESSED, 0);

    //Write style state: LV_STATE_CHECKED for style_home_imgbtn_key_word_main
    lv_style_set_text_color(&style_home_imgbtn_key_word_main, LV_STATE_CHECKED, lv_color_make(0xFF, 0x33, 0xFF));
    lv_style_set_image_recolor(&style_home_imgbtn_key_word_main, LV_STATE_CHECKED, lv_color_make(0x00, 0x00, 0x00));
    lv_style_set_image_recolor_opa(&style_home_imgbtn_key_word_main, LV_STATE_CHECKED, 0);
    lv_obj_add_style(ui->home_imgbtn_key_word, LV_IMGBTN_PART_MAIN, &style_home_imgbtn_key_word_main);
    lv_obj_set_pos(ui->home_imgbtn_key_word, 143, 38);
    lv_obj_set_size(ui->home_imgbtn_key_word, 47, 47);
    lv_tileview_add_element(ui->home_home, ui->home_imgbtn_key_word);
    lv_imgbtn_set_src(ui->home_imgbtn_key_word,LV_BTN_STATE_RELEASED,&_home_keyword_alpha_47x47);
    lv_imgbtn_set_checkable(ui->home_imgbtn_key_word, true);

    //Write codes home_imgbtn_5
    ui->home_imgbtn_5 = lv_imgbtn_create(ui->home_home_home_5, NULL);

    //Write style LV_IMGBTN_PART_MAIN for home_imgbtn_5
    static lv_style_t style_home_imgbtn_5_main;
    lv_style_reset(&style_home_imgbtn_5_main);

    //Write style state: LV_STATE_DEFAULT for style_home_imgbtn_5_main
    lv_style_set_text_color(&style_home_imgbtn_5_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
    lv_style_set_image_recolor(&style_home_imgbtn_5_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
    lv_style_set_image_recolor_opa(&style_home_imgbtn_5_main, LV_STATE_DEFAULT, 0);
    lv_style_set_image_opa(&style_home_imgbtn_5_main, LV_STATE_DEFAULT, 255);

    //Write style state: LV_STATE_PRESSED for style_home_imgbtn_5_main
    lv_style_set_text_color(&style_home_imgbtn_5_main, LV_STATE_PRESSED, lv_color_make(0xFF, 0x33, 0xFF));
    lv_style_set_image_recolor(&style_home_imgbtn_5_main, LV_STATE_PRESSED, lv_color_make(0x00, 0x00, 0x00));
    lv_style_set_image_recolor_opa(&style_home_imgbtn_5_main, LV_STATE_PRESSED, 0);

    //Write style state: LV_STATE_CHECKED for style_home_imgbtn_5_main
    lv_style_set_text_color(&style_home_imgbtn_5_main, LV_STATE_CHECKED, lv_color_make(0xFF, 0x33, 0xFF));
    lv_style_set_image_recolor(&style_home_imgbtn_5_main, LV_STATE_CHECKED, lv_color_make(0x00, 0x00, 0x00));
    lv_style_set_image_recolor_opa(&style_home_imgbtn_5_main, LV_STATE_CHECKED, 0);
    lv_obj_add_style(ui->home_imgbtn_5, LV_IMGBTN_PART_MAIN, &style_home_imgbtn_5_main);
    lv_obj_set_pos(ui->home_imgbtn_5, 30, 38);
    lv_obj_set_size(ui->home_imgbtn_5, 47, 47);
    lv_tileview_add_element(ui->home_home, ui->home_imgbtn_5);
    lv_imgbtn_set_src(ui->home_imgbtn_5,LV_BTN_STATE_RELEASED,&_home__alpha_47x47);
    lv_imgbtn_set_checkable(ui->home_imgbtn_5, true);

    //Write codes home_line_mid_v_home5
    ui->home_line_mid_v_home5 = lv_line_create(ui->home_home_home_5, NULL);

    //Write style LV_LINE_PART_MAIN for home_line_mid_v_home5
    static lv_style_t style_home_line_mid_v_home5_main;
    lv_style_reset(&style_home_line_mid_v_home5_main);

    //Write style state: LV_STATE_DEFAULT for style_home_line_mid_v_home5_main
    lv_style_set_line_color(&style_home_line_mid_v_home5_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
    lv_style_set_line_width(&style_home_line_mid_v_home5_main, LV_STATE_DEFAULT, 3);
    lv_obj_add_style(ui->home_line_mid_v_home5, LV_LINE_PART_MAIN, &style_home_line_mid_v_home5_main);
    lv_obj_set_pos(ui->home_line_mid_v_home5, 0, 118);
    lv_obj_set_size(ui->home_line_mid_v_home5, 225, 10);
    lv_tileview_add_element(ui->home_home, ui->home_line_mid_v_home5);
    static lv_point_t home_line_mid_v_home5[] ={{0,0},{223,0}};
    lv_line_set_points(ui->home_line_mid_v_home5,home_line_mid_v_home5,2);

    //Write codes home_line_mid_h_home5
    ui->home_line_mid_h_home5 = lv_line_create(ui->home_home_home_5, NULL);

    //Write style LV_LINE_PART_MAIN for home_line_mid_h_home5
    static lv_style_t style_home_line_mid_h_home5_main;
    lv_style_reset(&style_home_line_mid_h_home5_main);

    //Write style state: LV_STATE_DEFAULT for style_home_line_mid_h_home5_main
    lv_style_set_line_color(&style_home_line_mid_h_home5_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
    lv_style_set_line_width(&style_home_line_mid_h_home5_main, LV_STATE_DEFAULT, 3);
    lv_obj_add_style(ui->home_line_mid_h_home5, LV_LINE_PART_MAIN, &style_home_line_mid_h_home5_main);
    lv_obj_set_pos(ui->home_line_mid_h_home5, 102, 0);
    lv_obj_set_size(ui->home_line_mid_h_home5, 10, 240);
    lv_tileview_add_element(ui->home_home, ui->home_line_mid_h_home5);
    static lv_point_t home_line_mid_h_home5[] ={{9,0},{9,240}};
    lv_line_set_points(ui->home_line_mid_h_home5,home_line_mid_h_home5,2);

    //Write codes home_line_bottom_h_home5
    ui->home_line_bottom_h_home5 = lv_line_create(ui->home_home_home_5, NULL);

    //Write style LV_LINE_PART_MAIN for home_line_bottom_h_home5
    static lv_style_t style_home_line_bottom_h_home5_main;
    lv_style_reset(&style_home_line_bottom_h_home5_main);

    //Write style state: LV_STATE_DEFAULT for style_home_line_bottom_h_home5_main
    lv_style_set_line_color(&style_home_line_bottom_h_home5_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
    lv_style_set_line_width(&style_home_line_bottom_h_home5_main, LV_STATE_DEFAULT, 3);
    lv_obj_add_style(ui->home_line_bottom_h_home5, LV_LINE_PART_MAIN, &style_home_line_bottom_h_home5_main);
    lv_obj_set_pos(ui->home_line_bottom_h_home5, 0, 230);
    lv_obj_set_size(ui->home_line_bottom_h_home5, 225, 10);
    lv_tileview_add_element(ui->home_home, ui->home_line_bottom_h_home5);
    static lv_point_t home_line_bottom_h_home5[] ={{0,6},{223,6}};
    lv_line_set_points(ui->home_line_bottom_h_home5,home_line_bottom_h_home5,2);

    //Write codes home_home_home_6
    ui->home_home_home_6 = lv_obj_create(ui->home_home, NULL);
    lv_obj_set_style_local_bg_opa(ui->home_home_home_6, LV_OBJ_PART_MAIN, LV_STATE_DEFAULT, 0);
    lv_obj_set_style_local_border_width(ui->home_home_home_6, LV_OBJ_PART_MAIN, LV_STATE_FOCUSED, 0);
    lv_obj_set_pos(ui->home_home_home_6, 0, 5*240);
    lv_obj_set_size(ui->home_home_home_6, 240, 240);
    lv_tileview_add_element(ui->home_home, ui->home_home_home_6);

    //Write codes home_line_right_h_home6
    ui->home_line_right_h_home6 = lv_line_create(ui->home_home_home_6, NULL);

    //Write style LV_LINE_PART_MAIN for home_line_right_h_home6
    static lv_style_t style_home_line_right_h_home6_main;
    lv_style_reset(&style_home_line_right_h_home6_main);

    //Write style state: LV_STATE_DEFAULT for style_home_line_right_h_home6_main
    lv_style_set_line_color(&style_home_line_right_h_home6_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
    lv_style_set_line_width(&style_home_line_right_h_home6_main, LV_STATE_DEFAULT, 3);
    lv_obj_add_style(ui->home_line_right_h_home6, LV_LINE_PART_MAIN, &style_home_line_right_h_home6_main);
    lv_obj_set_pos(ui->home_line_right_h_home6, 220, 0);
    lv_obj_set_size(ui->home_line_right_h_home6, 10, 240);
    lv_tileview_add_element(ui->home_home, ui->home_line_right_h_home6);
    static lv_point_t home_line_right_h_home6[] ={{3,0},{3,240}};
    lv_line_set_points(ui->home_line_right_h_home6,home_line_right_h_home6,2);

    //Write codes home_label_led
    ui->home_label_led = lv_label_create(ui->home_home_home_6, NULL);
    lv_label_set_text(ui->home_label_led, "补光灯设置");
    lv_label_set_long_mode(ui->home_label_led, LV_LABEL_LONG_BREAK);
    lv_label_set_align(ui->home_label_led, LV_LABEL_ALIGN_CENTER);

    //Write style LV_LABEL_PART_MAIN for home_label_led
    static lv_style_t style_home_label_led_main;
    lv_style_reset(&style_home_label_led_main);

    //Write style state: LV_STATE_DEFAULT for style_home_label_led_main
    lv_style_set_radius(&style_home_label_led_main, LV_STATE_DEFAULT, 0);
    lv_style_set_bg_color(&style_home_label_led_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
    lv_style_set_bg_grad_color(&style_home_label_led_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
    lv_style_set_bg_grad_dir(&style_home_label_led_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
    lv_style_set_bg_opa(&style_home_label_led_main, LV_STATE_DEFAULT, 0);
    lv_style_set_text_color(&style_home_label_led_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
    lv_style_set_text_font(&style_home_label_led_main, LV_STATE_DEFAULT, &lv_font_simsun_15);
    lv_style_set_text_letter_space(&style_home_label_led_main, LV_STATE_DEFAULT, 2);
    lv_style_set_pad_left(&style_home_label_led_main, LV_STATE_DEFAULT, 0);
    lv_style_set_pad_right(&style_home_label_led_main, LV_STATE_DEFAULT, 0);
    lv_style_set_pad_top(&style_home_label_led_main, LV_STATE_DEFAULT, 0);
    lv_style_set_pad_bottom(&style_home_label_led_main, LV_STATE_DEFAULT, 0);
    lv_obj_add_style(ui->home_label_led, LV_LABEL_PART_MAIN, &style_home_label_led_main);
    lv_obj_set_pos(ui->home_label_led, 125, 98);
    lv_obj_set_size(ui->home_label_led, 88, 0);
    lv_tileview_add_element(ui->home_home, ui->home_label_led);

    //Write codes home_label_language
    ui->home_label_language = lv_label_create(ui->home_home_home_6, NULL);
    lv_label_set_text(ui->home_label_language, "语言设置");
    lv_label_set_long_mode(ui->home_label_language, LV_LABEL_LONG_BREAK);
    lv_label_set_align(ui->home_label_language, LV_LABEL_ALIGN_CENTER);

    //Write style LV_LABEL_PART_MAIN for home_label_language
    static lv_style_t style_home_label_language_main;
    lv_style_reset(&style_home_label_language_main);

    //Write style state: LV_STATE_DEFAULT for style_home_label_language_main
    lv_style_set_radius(&style_home_label_language_main, LV_STATE_DEFAULT, 0);
    lv_style_set_bg_color(&style_home_label_language_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
    lv_style_set_bg_grad_color(&style_home_label_language_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
    lv_style_set_bg_grad_dir(&style_home_label_language_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
    lv_style_set_bg_opa(&style_home_label_language_main, LV_STATE_DEFAULT, 0);
    lv_style_set_text_color(&style_home_label_language_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
    lv_style_set_text_font(&style_home_label_language_main, LV_STATE_DEFAULT, &lv_font_simsun_15);
    lv_style_set_text_letter_space(&style_home_label_language_main, LV_STATE_DEFAULT, 2);
    lv_style_set_pad_left(&style_home_label_language_main, LV_STATE_DEFAULT, 0);
    lv_style_set_pad_right(&style_home_label_language_main, LV_STATE_DEFAULT, 0);
    lv_style_set_pad_top(&style_home_label_language_main, LV_STATE_DEFAULT, 0);
    lv_style_set_pad_bottom(&style_home_label_language_main, LV_STATE_DEFAULT, 0);
    lv_obj_add_style(ui->home_label_language, LV_LABEL_PART_MAIN, &style_home_label_language_main);
    lv_obj_set_pos(ui->home_label_language, 20, 98);
    lv_obj_set_size(ui->home_label_language, 68, 0);
    lv_tileview_add_element(ui->home_home, ui->home_label_language);

    //Write codes home_imgbtn_led
    ui->home_imgbtn_led = lv_imgbtn_create(ui->home_home_home_6, NULL);

    //Write style LV_IMGBTN_PART_MAIN for home_imgbtn_led
    static lv_style_t style_home_imgbtn_led_main;
    lv_style_reset(&style_home_imgbtn_led_main);

    //Write style state: LV_STATE_DEFAULT for style_home_imgbtn_led_main
    lv_style_set_text_color(&style_home_imgbtn_led_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
    lv_style_set_image_recolor(&style_home_imgbtn_led_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
    lv_style_set_image_recolor_opa(&style_home_imgbtn_led_main, LV_STATE_DEFAULT, 0);
    lv_style_set_image_opa(&style_home_imgbtn_led_main, LV_STATE_DEFAULT, 255);

    //Write style state: LV_STATE_PRESSED for style_home_imgbtn_led_main
    lv_style_set_text_color(&style_home_imgbtn_led_main, LV_STATE_PRESSED, lv_color_make(0xFF, 0x33, 0xFF));
    lv_style_set_image_recolor(&style_home_imgbtn_led_main, LV_STATE_PRESSED, lv_color_make(0x00, 0x00, 0x00));
    lv_style_set_image_recolor_opa(&style_home_imgbtn_led_main, LV_STATE_PRESSED, 0);

    //Write style state: LV_STATE_CHECKED for style_home_imgbtn_led_main
    lv_style_set_text_color(&style_home_imgbtn_led_main, LV_STATE_CHECKED, lv_color_make(0xFF, 0x33, 0xFF));
    lv_style_set_image_recolor(&style_home_imgbtn_led_main, LV_STATE_CHECKED, lv_color_make(0x00, 0x00, 0x00));
    lv_style_set_image_recolor_opa(&style_home_imgbtn_led_main, LV_STATE_CHECKED, 0);
    lv_obj_add_style(ui->home_imgbtn_led, LV_IMGBTN_PART_MAIN, &style_home_imgbtn_led_main);
    lv_obj_set_pos(ui->home_imgbtn_led, 150, 40);
    lv_obj_set_size(ui->home_imgbtn_led, 39, 39);
    lv_tileview_add_element(ui->home_home, ui->home_imgbtn_led);
    lv_imgbtn_set_src(ui->home_imgbtn_led,LV_BTN_STATE_RELEASED,&_home_led_alpha_39x39);
    lv_imgbtn_set_checkable(ui->home_imgbtn_led, true);

    //Write codes home_imgbtn_language
    ui->home_imgbtn_language = lv_imgbtn_create(ui->home_home_home_6, NULL);

    //Write style LV_IMGBTN_PART_MAIN for home_imgbtn_language
    static lv_style_t style_home_imgbtn_language_main;
    lv_style_reset(&style_home_imgbtn_language_main);

    //Write style state: LV_STATE_DEFAULT for style_home_imgbtn_language_main
    lv_style_set_text_color(&style_home_imgbtn_language_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
    lv_style_set_image_recolor(&style_home_imgbtn_language_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
    lv_style_set_image_recolor_opa(&style_home_imgbtn_language_main, LV_STATE_DEFAULT, 0);
    lv_style_set_image_opa(&style_home_imgbtn_language_main, LV_STATE_DEFAULT, 255);

    //Write style state: LV_STATE_PRESSED for style_home_imgbtn_language_main
    lv_style_set_text_color(&style_home_imgbtn_language_main, LV_STATE_PRESSED, lv_color_make(0xFF, 0x33, 0xFF));
    lv_style_set_image_recolor(&style_home_imgbtn_language_main, LV_STATE_PRESSED, lv_color_make(0x00, 0x00, 0x00));
    lv_style_set_image_recolor_opa(&style_home_imgbtn_language_main, LV_STATE_PRESSED, 0);

    //Write style state: LV_STATE_CHECKED for style_home_imgbtn_language_main
    lv_style_set_text_color(&style_home_imgbtn_language_main, LV_STATE_CHECKED, lv_color_make(0xFF, 0x33, 0xFF));
    lv_style_set_image_recolor(&style_home_imgbtn_language_main, LV_STATE_CHECKED, lv_color_make(0x00, 0x00, 0x00));
    lv_style_set_image_recolor_opa(&style_home_imgbtn_language_main, LV_STATE_CHECKED, 0);
    lv_obj_add_style(ui->home_imgbtn_language, LV_IMGBTN_PART_MAIN, &style_home_imgbtn_language_main);
    lv_obj_set_pos(ui->home_imgbtn_language, 30, 45);
    lv_obj_set_size(ui->home_imgbtn_language, 47, 32);
    lv_tileview_add_element(ui->home_home, ui->home_imgbtn_language);
    lv_imgbtn_set_src(ui->home_imgbtn_language,LV_BTN_STATE_RELEASED,&_home_language_alpha_47x32);
    lv_imgbtn_set_checkable(ui->home_imgbtn_language, true);

    //Write codes home_line_mid_v_home6
    ui->home_line_mid_v_home6 = lv_line_create(ui->home_home_home_6, NULL);

    //Write style LV_LINE_PART_MAIN for home_line_mid_v_home6
    static lv_style_t style_home_line_mid_v_home6_main;
    lv_style_reset(&style_home_line_mid_v_home6_main);

    //Write style state: LV_STATE_DEFAULT for style_home_line_mid_v_home6_main
    lv_style_set_line_color(&style_home_line_mid_v_home6_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
    lv_style_set_line_width(&style_home_line_mid_v_home6_main, LV_STATE_DEFAULT, 3);
    lv_obj_add_style(ui->home_line_mid_v_home6, LV_LINE_PART_MAIN, &style_home_line_mid_v_home6_main);
    lv_obj_set_pos(ui->home_line_mid_v_home6, 0, 118);
    lv_obj_set_size(ui->home_line_mid_v_home6, 225, 10);
    lv_tileview_add_element(ui->home_home, ui->home_line_mid_v_home6);
    static lv_point_t home_line_mid_v_home6[] ={{0,0},{223,0}};
    lv_line_set_points(ui->home_line_mid_v_home6,home_line_mid_v_home6,2);

    //Write codes home_line_mid_h_home6
    ui->home_line_mid_h_home6 = lv_line_create(ui->home_home_home_6, NULL);

    //Write style LV_LINE_PART_MAIN for home_line_mid_h_home6
    static lv_style_t style_home_line_mid_h_home6_main;
    lv_style_reset(&style_home_line_mid_h_home6_main);

    //Write style state: LV_STATE_DEFAULT for style_home_line_mid_h_home6_main
    lv_style_set_line_color(&style_home_line_mid_h_home6_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
    lv_style_set_line_width(&style_home_line_mid_h_home6_main, LV_STATE_DEFAULT, 3);
    lv_obj_add_style(ui->home_line_mid_h_home6, LV_LINE_PART_MAIN, &style_home_line_mid_h_home6_main);
    lv_obj_set_pos(ui->home_line_mid_h_home6, 102, 0);
    lv_obj_set_size(ui->home_line_mid_h_home6, 10, 240);
    lv_tileview_add_element(ui->home_home, ui->home_line_mid_h_home6);
    static lv_point_t home_line_mid_h_home6[] ={{9,0},{9,240}};
    lv_line_set_points(ui->home_line_mid_h_home6,home_line_mid_h_home6,2);

    //Write codes home_line_bottom_h_home6
    ui->home_line_bottom_h_home6 = lv_line_create(ui->home_home_home_6, NULL);

    //Write style LV_LINE_PART_MAIN for home_line_bottom_h_home6
    static lv_style_t style_home_line_bottom_h_home6_main;
    lv_style_reset(&style_home_line_bottom_h_home6_main);

    //Write style state: LV_STATE_DEFAULT for style_home_line_bottom_h_home6_main
    lv_style_set_line_color(&style_home_line_bottom_h_home6_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
    lv_style_set_line_width(&style_home_line_bottom_h_home6_main, LV_STATE_DEFAULT, 3);
    lv_obj_add_style(ui->home_line_bottom_h_home6, LV_LINE_PART_MAIN, &style_home_line_bottom_h_home6_main);
    lv_obj_set_pos(ui->home_line_bottom_h_home6, 0, 230);
    lv_obj_set_size(ui->home_line_bottom_h_home6, 225, 10);
    lv_tileview_add_element(ui->home_home, ui->home_line_bottom_h_home6);
    static lv_point_t home_line_bottom_h_home6[] ={{0,6},{223,6}};
    lv_line_set_points(ui->home_line_bottom_h_home6,home_line_bottom_h_home6,2);

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
    if (event == LV_EVENT_SHORT_CLICKED)
    {
      if (function_home_app.ui->home_imgbtn_photo == btn)
      {
        zm831_home_app_select(0x01);
        return;
      }
      if (function_home_app.ui->home_imgbtn_color == btn)
      {
        zm831_home_app_select(0x02);
        return;
      }
      if (function_home_app.ui->home_imgbtn_qrcode == btn)
      {
        zm831_home_app_select(0x03);
        return;
      }
      if (function_home_app.ui->home_imgbtn_ball == btn)
      {
        zm831_home_app_select(0x04);
        return;
      }
      if (function_home_app.ui->home_imgbtn_road == btn)
      {
        zm831_home_app_select(0x05);
        return;
      }
      if (function_home_app.ui->home_imgbtn_face == btn)
      {
        zm831_home_app_select(0x06);
        return;
      }
      if (function_home_app.ui->home_imgbtn_classific == btn)
      {
        zm831_home_app_select(0x07);
        return;
      }
      if (function_home_app.ui->home_Imgbtn_tagcode == btn)
      {
        zm831_home_app_select(0x08);
        return;
      }
      if (function_home_app.ui->home_imgbtn_colo_s == btn)
      {
        zm831_home_app_select(0x09);
        return;
      }
      if (function_home_app.ui->home_imgbtn_face_study == btn)
      {
        zm831_home_app_select(0x0a);
        return;
      }
      if (function_home_app.ui->home_imgbtn_gesture == btn)
      {
        zm831_home_app_select(0x0b);
        return;
      }
      if (function_home_app.ui->home_imgbtn_classific_study == btn)
      {
        zm831_home_app_select(0x0c);
        return;
      }
      if (function_home_app.ui->home_imgbtn_traffic == btn)
      {
        zm831_home_app_select(0x0d);
        return;
      }
      if (function_home_app.ui->home_imgbtn_five_road == btn)
      {
        zm831_home_app_select(0x0e);
        return;
      }
      // if (function_home_app.ui->home_imgbtn_speech_interaction == btn)
      // {
      //   zm831_home_app_select(0x0f);
      //   return;
      // }
      // if (function_home_app.ui->home_imgbtn_speech_interaction == btn)
      // {
      //   zm831_home_app_select(0x10);
      //   return;
      // }
      // if (function_home_app.ui->home_imgbtn_speech_interaction == btn)
      // {
      //   zm831_home_app_select(0x11);
      //   return;
      // }
      // if (function_home_app.ui->home_imgbtn_speech_interaction == btn)
      // {
      //   zm831_home_app_select(0x12);
      //   return;
      // }
      // if (function_home_app.ui->home_imgbtn_speech_interaction == btn)
      // {
      //   zm831_home_app_select(0x13);
      //   return;
      // }
      if (function_home_app.ui->home_imgbtn_led == btn)
      {
        static int home_imgbtn_led_flag = 0;
        home_imgbtn_led_flag = (home_imgbtn_led_flag + 1) % 5;
        switch (home_imgbtn_led_flag)
        {
        case 0:
          _pwm_init("PH8", 50000, 0.1);
          break;
        case 1:
          _pwm_set_duty("PH8", 0.4);
          break;
        case 2:
          _pwm_set_duty("PH8", 0.7);
          break;
        case 3:
          _pwm_set_duty("PH8", 1.0);
          break;
        case 4:
          _pwm_deinit("PH8");
          break;
        }
        return;
      }
      if (function_home_app.ui->home_imgbtn_cube == btn)
      {
        zm831_home_app_select(0x14);
        return;
      }
      if (function_home_app.ui->home_imgbtn_number == btn)
      {
        zm831_home_app_select(0x15);
        return;
      }
    }
  }

  int function_home_app_load(zm831_home_app *app)
  {
    auto self = (_function_home_ *)app->userdata;
    if (!self->init)
    {
      zm831_home_setup_ui(&self->ui->home, setup_scr_screen, 250);

      pthread_mutex_lock(&zm831->ui_mutex);
      lv_obj_set_event_cb(self->ui->home_imgbtn_photo, function_home_btn_event_app_cb);
      lv_obj_set_event_cb(self->ui->home_imgbtn_color, function_home_btn_event_app_cb);
      lv_obj_set_event_cb(self->ui->home_imgbtn_qrcode, function_home_btn_event_app_cb);
      lv_obj_set_event_cb(self->ui->home_imgbtn_ball, function_home_btn_event_app_cb);
      lv_obj_set_event_cb(self->ui->home_imgbtn_road, function_home_btn_event_app_cb);
      lv_obj_set_event_cb(self->ui->home_imgbtn_face, function_home_btn_event_app_cb);
      lv_obj_set_event_cb(self->ui->home_imgbtn_classific, function_home_btn_event_app_cb);
      lv_obj_set_event_cb(self->ui->home_Imgbtn_tagcode, function_home_btn_event_app_cb);
      lv_obj_set_event_cb(self->ui->home_imgbtn_colo_s, function_home_btn_event_app_cb);
      lv_obj_set_event_cb(self->ui->home_imgbtn_face_study, function_home_btn_event_app_cb);
      lv_obj_set_event_cb(self->ui->home_imgbtn_gesture, function_home_btn_event_app_cb);
      lv_obj_set_event_cb(self->ui->home_imgbtn_classific_study, function_home_btn_event_app_cb);
      lv_obj_set_event_cb(self->ui->home_imgbtn_traffic, function_home_btn_event_app_cb);
      lv_obj_set_event_cb(self->ui->home_imgbtn_five_road, function_home_btn_event_app_cb);
      lv_obj_set_event_cb(self->ui->home_imgbtn_cube, function_home_btn_event_app_cb);
      lv_obj_set_event_cb(self->ui->home_imgbtn_number, function_home_btn_event_app_cb);
      lv_obj_set_event_cb(self->ui->home_imgbtn_led, function_home_btn_event_app_cb);
      pthread_mutex_unlock(&zm831->ui_mutex);

      extern int zm831_home_app_last;
      // printf("zm831_home_app_last:%d\n", zm831_home_app_last);
      pthread_mutex_lock(&zm831->ui_mutex);
      if (zm831_home_app_last != 0) {
        const int last_pos[] = { 0, 0, 1, 1, 2, 2, 0, 3, 1, 1, 0, 0, 3, 2, 3, 4, 4, 4, 4, 4, 3, 2,  };
        lv_page_scroll_ver(self->ui->home_home, -lv_obj_get_height(self->ui->home_home) * last_pos[zm831_home_app_last]);
      }
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
      zm831_home_clear_ui(&self->ui->home);
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
      zm831->sensor_time = zm831_get_ms();
      // zm831_home_app_select(1);
    }
    return 0;
  }
}
