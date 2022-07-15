
#include "zm831_uvai.hpp"

extern "C"
{
  extern zm831_uv *zm831;
  // ==============================================================================================

  // extern zm831_home_app get_qrcode_zbar_app();
  // extern zm831_home_app get_nn_yolo_face_app();
  // extern zm831_home_app get_qrcode_quirc_app();
  // extern zm831_home_app get_find_apriltag_app();
  // extern zm831_home_app get_imlib_find_blobs_app();
  // extern zm831_home_app get_imlib_cube_color_app();
  // extern zm831_home_app get_cv_nn_find_ball_app();
  // extern zm831_home_app get_nn_classifier_resnet_app();
  // extern zm831_home_app get_nn_retinaface_app();
  // extern zm831_home_app get_nn_classifier_custom_app();
  // extern zm831_home_app get_speech_asr_app();

  const _get_zm831_home_app_func_ get_function_0x0f_app = NULL;
  const _get_zm831_home_app_func_ get_function_0x10_app = NULL;
  const _get_zm831_home_app_func_ get_function_0x11_app = NULL;
  const _get_zm831_home_app_func_ get_function_0x12_app = NULL;
  const _get_zm831_home_app_func_ get_function_0x13_app = NULL;

  extern zm831_home_app get_function_home_app();
  extern zm831_home_app get_function_0x01_app();
  extern zm831_home_app get_function_0x02_app();
  extern zm831_home_app get_function_0x03_app();
  extern zm831_home_app get_function_0x04_app();
  extern zm831_home_app get_function_0x05_app();
  extern zm831_home_app get_function_0x06_app();
  extern zm831_home_app get_function_0x07_app();
  extern zm831_home_app get_function_0x08_app();
  extern zm831_home_app get_function_0x09_app();
  extern zm831_home_app get_function_0x0a_app();
  extern zm831_home_app get_function_0x0b_app();
  extern zm831_home_app get_function_0x0c_app();
  extern zm831_home_app get_function_0x0d_app();
  extern zm831_home_app get_function_0x0e_app();
  // extern zm831_home_app get_function_0x0f_app();
  // extern zm831_home_app get_function_0x10_app();
  // extern zm831_home_app get_function_0x11_app();
  // extern zm831_home_app get_function_0x12_app();
  // extern zm831_home_app get_function_0x13_app();
  extern zm831_home_app get_function_0x14_app();
  extern zm831_home_app get_function_0x15_app();

  uint8_t zm831_home_app_index = 0; // current app index
  static _get_zm831_home_app_func_ zm831_home_app_lists[] = {
      get_function_home_app,
      get_function_0x01_app,
      get_function_0x02_app,
      get_function_0x03_app,
      get_function_0x04_app,
      get_function_0x05_app,
      get_function_0x06_app,
      get_function_0x07_app,
      get_function_0x08_app,
      get_function_0x09_app,
      get_function_0x0a_app,
      get_function_0x0b_app,
      get_function_0x0c_app,
      get_function_0x0d_app,
      get_function_0x0e_app,
      get_function_0x0f_app,
      get_function_0x10_app,
      get_function_0x11_app,
      get_function_0x12_app,
      get_function_0x13_app,
      get_function_0x14_app,
      get_function_0x15_app,
      // get_nn_classifier_resnet_app,
      // get_nn_classifier_custom_app,
      // get_nn_retinaface_app,
      // get_cv_nn_find_ball_app,
      // get_imlib_cube_color_app,
      // get_qrcode_zbar_app,
      // get_qrcode_quirc_app,
      // get_nn_yolo_face_app,
      // get_find_apriltag_app,
      // get_imlib_find_blobs_app,
      // get_speech_asr_app,
  };

  // ==============================================================================================

  int zm831_home_app_load(zm831_home_app *app);
  int zm831_home_app_loop(zm831_home_app *app);
  int zm831_home_app_exit(zm831_home_app *app);

  zm831_home_app get_zm831_home_app()
  {
    return {zm831_home_app_load, zm831_home_app_loop, zm831_home_app_exit, NULL};
  }

  int zm831_home_app_load(zm831_home_app *app)
  {
    zm831_ui_show_clear();
    LIBMAIX_INFO_PRINTF("zm831_home_app_load");
    return 0;
  }

  int zm831_home_app_loop(zm831_home_app *app)
  {
    libmaix_image_t *ai_rgb = NULL;
    if (zm831->ai && LIBMAIX_ERR_NONE == zm831->ai->capture_image(zm831->ai, &ai_rgb))
    {
      CALC_FPS("zm831_home_loop");

      // LIBMAIX_INFO_PRINTF("ai_rgb: %p, %d, %d\r\n", ai_rgb, ai_rgb->width, ai_rgb->height);
      cv::Mat rgb(ai_rgb->height, ai_rgb->width, CV_8UC3, ai_rgb->data);
      // LIBMAIX_INFO_PRINTF("_zm831_home_app_loop");

      zm831_ui_show_image(rgb, 8, 8, LV_OPA_80);
    }

    msleep(zm831->ai_th_ms);

    if (!zm831->recvPacks.empty())
    {
      zm831_pack_t pack = zm831->recvPacks.front();
      zm831->recvPacks.pop_front();
      LIBMAIX_INFO_PRINTF("recv pack type: %d\n", pack.type);
      auto tmp = pack.data;
      for (int i = 0; i < tmp.size(); i++)
        printf(" 0x%02X", tmp[i]);
      printf("\n");
    }

    // LIBMAIX_INFO_PRINTF("_zm831_home_app_loop");
    return 0;
  }

  int zm831_home_app_exit(zm831_home_app *app)
  {
    zm831_ui_show_clear();
    LIBMAIX_INFO_PRINTF("zm831_home_app_exit");
    return 0;
  }

  void zm831_home_setup_ui(lv_obj_t **lvgl_screen, _ui_setup_scr_ setup_scr, int load_time_ms)
  {
    pthread_mutex_lock(&zm831->ui_mutex);
    lv_ui *ui = &zm831->ui;
    setup_scr(ui);
    lv_scr_load_anim(*lvgl_screen, LV_SCR_LOAD_ANIM_FADE_ON, load_time_ms, 0, false); // set false lv_scr_act() cant delete
    pthread_mutex_unlock(&zm831->ui_mutex);
  }

  void zm831_home_clear_ui(lv_obj_t **lvgl_screen)
  {
    pthread_mutex_lock(&zm831->ui_mutex);
    lv_canvas_fill_bg(zm831_ui_get_canvas(), LV_COLOR_BLACK, LV_OPA_TRANSP);
    lv_ui *ui = &zm831->ui;
    lv_obj_clean(*lvgl_screen);
    pthread_mutex_unlock(&zm831->ui_mutex);
  }

  // ==============================================================================================

  zm831_home_app *app_bak, *app_run, app_old, app_new;

  void zm831_home_app_stop()
  {
    if (app_run)
      app_run->loop = NULL; // when app lopp stop & exit old app
  }

  void zm831_home_app_reload(zm831_home_app app)
  {
    app_new = app;
    app_bak = &app_new;
    zm831_home_app_stop();
    LIBMAIX_INFO_PRINTF("zm831_home_app_reload");
  }

  int zm831_home_app_select(int id)
  {
    if (id == zm831_home_app_index)
      return 0;
    // LIBMAIX_INFO_PRINTF("id: %d\n", id);
    if (id < 0 || id >= (sizeof(zm831_home_app_lists) / sizeof(zm831_home_app_lists[0])))
    {
      LIBMAIX_INFO_PRINTF("zm831_home_app_select: id out of range");
      return -1;
    }
    if (zm831_home_app_lists[id] == NULL)
    {
      LIBMAIX_INFO_PRINTF("zm831_home_app_select: id not found");
      return -1;
    }
    zm831_home_app_reload(zm831_home_app_lists[id]());
    zm831_home_app_index = id;

    zm831->config_json["last_select"] = (int)id;
    zm831_save_json_conf(zm831->config_file, zm831->config_json);

    return 0;
  }

  // bool debug = false;

  void *_zm831_home_loop(void *)
  {
    int ret = 0;
    while (zm831->ai_th_ms)
    {
      if (app_bak)
      {
        app_old = app_new;
        app_run = &app_old;
        app_bak = NULL;
      }
      else
      {
        if (app_run->load)
        {
          int ret = app_run->load(app_run);
          if (ret)
          {
            zm831_home_app_reload(get_function_home_app()); // return app index
            if (app_run->exit)                              // init fail to exit
            {
              app_run->exit(app_run), app_run->exit = NULL;
            }
            continue;
          }
          app_run->load = NULL;
        }
        while (app_run->loop)
        {
          // extern int function_0x07_app_loop(zm831_home_app *app);
          // if (app_run->loop == function_0x07_app_loop)
          // {
          //   debug = true;
          //   msleep(1000);
          // } else {
            app_run->loop(app_run);
          // }
          // pthread_mutex_lock(&zm831->ai_mutex);
          // zm831->ai_th_keep = 0; // keep ai thread running.
          // pthread_mutex_unlock(&zm831->ai_mutex);
        }
        if (app_run->exit)
        {
          app_run->exit(app_run), app_run->exit = NULL;
        }
      }
    }
    return NULL;
  }

  // static void btn_event_app_cb(lv_obj_t *btn, lv_event_t event)
  // {
  //   if (event == LV_EVENT_CLICKED)
  //   {
  //     static uint8_t cnt = 0;
  //     cnt++;
  //     /*Get the first child of the button which is the label and change its text*/
  //     lv_obj_t *label = lv_obj_get_child(btn, NULL);
  //     lv_label_set_text_fmt(label, "app: %d", cnt);
  //     if (cnt > 20)
  //     {
  //       zm831->exit = 1;
  //     }
  //     zm831->config_json["last_select"] = (int)cnt;
  //     zm831_save_json_conf(zm831->config_file, zm831->config_json);
  //     zm831_home_app_select(cnt);
  //   }
  // }

  void zm831_home_load()
  {

    // {
    //   lv_obj_t *btn = lv_btn_create(lv_scr_act(), NULL); /*Add a button the current screen*/
    //   lv_obj_set_pos(btn, 80, 20);                       /*Set its position*/
    //   // lv_obj_align(btn, NULL, LV_ALIGN_IN_BOTTOM_RIGHT, 0, 0);
    //   lv_obj_set_size(btn, 80, 80);               /*Set its size*/
    //   lv_obj_set_event_cb(btn, btn_event_app_cb); /*Assign a callback to the button*/
    //   static lv_style_t style_btn_red;
    //   lv_style_init(&style_btn_red);
    //   lv_style_set_bg_color(&style_btn_red, LV_STATE_DEFAULT, {0xff, 0x00, 0x00, 0x7f}); // bgra
    //   lv_style_set_bg_grad_color(&style_btn_red, LV_STATE_DEFAULT, LV_COLOR_MAROON);
    //   lv_style_set_bg_color(&style_btn_red, LV_STATE_PRESSED, LV_COLOR_MAROON);
    //   lv_style_set_bg_grad_color(&style_btn_red, LV_STATE_PRESSED, LV_COLOR_RED);
    //   lv_style_set_text_color(&style_btn_red, LV_STATE_DEFAULT, LV_COLOR_WHITE);
    //   lv_obj_add_style(btn, LV_BTN_PART_MAIN, &style_btn_red); /*Add the red style on top of the current */
    //   lv_obj_t *label = lv_label_create(btn, NULL);            /*Add a label to the button*/
    //   lv_label_set_text(label, "app");                         /*Set the labels text*/
    // }

    zm831_home_app_reload(get_function_home_app());

    auto result = zm831->config_json["last_select"];
    if (result.is_number())
    {
      // printf("last_select: %d\n", result.as_integer());
      zm831_home_app_select(result.as_integer());
    }

    // zm831->config_json["last_select"] = (int)cnt;
    // zm831_save_json_conf(zm831->config_file, zm831->config_json);

    zm831->ai_th_ms = 20; // 40ms 25fps 50% 30ms 65% 10ms 100fps 80%

    zm831->ai_th_id = pthread_create(&zm831->ai_thread, NULL, _zm831_home_loop, NULL);

    // int ret, stacksize = 204800; /*thread 堆栈设置为 20K */
    // pthread_attr_t attr;
    // ret = pthread_attr_init(&attr);
    // pthread_attr_setschedpolicy(&attr, SCHED_RR);
    // sched_param param;
    // param.sched_priority = -20;
    // pthread_attr_setschedparam(&attr, &param);
    // ret = pthread_attr_setstacksize(&attr, stacksize);
    // zm831->ai_th_id = pthread_create(&zm831->ai_thread, &attr, _zm831_home_loop, NULL);
    // ret = pthread_attr_destroy(&attr);

    if (zm831->ai_th_id != 0)
    {
      printf("new thread create is failed.\n");
    }
    LIBMAIX_INFO_PRINTF("zm831_home_load");
  }

  void zm831_home_exit()
  {
    int *thread_ret = NULL;
    if (zm831->ai_th_ms)
    {
      zm831->ai_th_ms = 0;
      zm831_home_app_stop();
      pthread_join(zm831->ai_thread, (void **)&thread_ret);
    }
    LIBMAIX_INFO_PRINTF("zm831_home_exit");
  }

  void zm831_home_loop()
  {
    // if (debug) {
    //   extern int function_0x07_app_loop(zm831_home_app *app);
    //   if (app_run->loop == function_0x07_app_loop)
    //   {
    //     app_run->loop(app_run);
    //   }
    // }
    // if (zm831->ai_th_keep > 60) { // 30ms * 60 = 1800ms
    //   zm831->ai_th_keep = 0;
    //   zm831->ai_th_ms = 30000; // 40ms 25fps 50% 30ms 65% 10ms 100fps 80%
    //   // int res_kill = pthread_kill(zm831->ai_th_id, 0); // 0 signal is retain sign,then no signal is send
    //   // if(res_kill == ESRCH)
    //   // {
    //   //     printf("new thread tid is not found.\n");
    //   //     printf("ret_kill = %d\n",res_kill);
    //   // }
    //   int res_kill = pthread_kill(zm831->ai_th_id, SIGKILL);// SIGQUIT signal is quit signal ,it will quit main process
    //   zm831->ai_th_id = pthread_create(&zm831->ai_thread, NULL, _zm831_home_loop, NULL);
    //   if(zm831->ai_th_id != 0)
    //   {
    //       printf("new thread create is failed.\n");
    //   }
    // }
    // pthread_mutex_lock(&zm831->ai_mutex);
    // zm831->ai_th_keep++; // thread need reply zm831->ai_th_keep = 0;
    // pthread_mutex_unlock(&zm831->ai_mutex);
  }
}
