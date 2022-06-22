
#include "zm831_uvai.hpp"

extern "C"
{
  extern zm831_uv *zm831;

  int zm831_home_app_load(zm831_home_app *app)
  {
    LIBMAIX_INFO_PRINTF("zm831_home_app_load");
    return 0;
  }

  int zm831_home_app_loop(zm831_home_app *app)
  {
    libmaix_image_t *ai_rgb = NULL;
    if (LIBMAIX_ERR_NONE == zm831->ai->capture_image(zm831->ai, &ai_rgb))
    {
      CALC_FPS("zm831_home_loop");
      // ai_rgb = NULL;
      // libmaix_image_t tmp = *ai_rgb;
      // LIBMAIX_INFO_PRINTF("_zm831_home_app_loop");
    }
    usleep(zm831->ai_th_usec);
    // LIBMAIX_INFO_PRINTF("_zm831_home_app_loop");
    return 0;
  }

  int zm831_home_app_exit(zm831_home_app *app)
  {
    LIBMAIX_INFO_PRINTF("zm831_home_app_exit");
    return 0;
  }

  zm831_home_app get_zm831_home_app()
  {
    return {zm831_home_app_load, zm831_home_app_loop, zm831_home_app_exit, NULL};
  }

  zm831_home_app *app_bak, *app_run, app_old, app_new;

  void zm831_home_app_reload(zm831_home_app app)
  {
    app_new = app;
    app_bak = &app_new;
    if (app_run) app_run->loop = NULL; // when app lopp stop & exit old app
    LIBMAIX_INFO_PRINTF("zm831_home_app_reload");
  }

  void *_zm831_home_loop(void *)
  {
    int ret = 0;
    while (zm831->ai_th_usec)
    {
      if (app_bak)
      {
        app_old = app_new;
        app_run = &app_old;
        app_bak = NULL;
      }
      else
      {
        if (app_run->load) {
          int ret = app_run->load(app_run);
          if (ret) {
            zm831_home_app_reload(get_zm831_home_app()); // return app index
            continue;
          }
          app_run->load = NULL;
        }
        while (app_run->loop) {
          app_run->loop(app_run);
          // pthread_mutex_lock(&zm831->ai_mutex);
          // zm831->ai_th_keep = 0; // keep ai thread running.
          // pthread_mutex_unlock(&zm831->ai_mutex);
        }
        if (app_run->exit) {
          app_run->exit(app_run), app_run->exit = NULL;
        }
      }
    }
    return 0;
  }

  static void btn_event_app_cb(lv_obj_t *btn, lv_event_t event)
  {
    if (event == LV_EVENT_CLICKED)
    {
      static uint8_t cnt = 0;
      cnt++;

      /*Get the first child of the button which is the label and change its text*/
      lv_obj_t *label = lv_obj_get_child(btn, NULL);
      lv_label_set_text_fmt(label, "zbar: %d", cnt);

      // if (cnt > 9) {
      //     zm831->exit = 1;
      // }

      extern zm831_home_app get_qrcode_zbar_app();
      zm831_home_app_reload(get_qrcode_zbar_app());
    }
  }

  static void btn_event_def_cb(lv_obj_t *btn, lv_event_t event)
  {
    if (event == LV_EVENT_CLICKED)
    {
      static uint8_t cnt = 0;
      cnt++;

      /*Get the first child of the button which is the label and change its text*/
      lv_obj_t *label = lv_obj_get_child(btn, NULL);
      lv_label_set_text_fmt(label, "nn: %d", cnt);

      // if (cnt > 9) {
      //     zm831->exit = 1;
      // }


      // extern zm831_home_app get_qrcode_quirc_app();
      // zm831_home_app_reload(get_qrcode_quirc_app());

      extern zm831_home_app get_nn_yolo_face_app();
      zm831_home_app_reload(get_nn_yolo_face_app());
    }
  }

  void zm831_home_load()
  {
    {
      lv_obj_t *btn = lv_btn_create(lv_scr_act(), NULL); /*Add a button the current screen*/
      lv_obj_set_pos(btn, 80, 160);                      /*Set its position*/
      // lv_obj_align(btn, NULL, LV_ALIGN_IN_BOTTOM_RIGHT, 0, 0);
      lv_obj_set_size(btn, 80, 80);               /*Set its size*/
      lv_obj_set_event_cb(btn, btn_event_app_cb); /*Assign a callback to the button*/
      static lv_style_t style_btn_red;
      lv_style_init(&style_btn_red);
      lv_style_set_bg_color(&style_btn_red, LV_STATE_DEFAULT, {0x00, 0x00, 0xff, 0x7f});
      lv_style_set_bg_grad_color(&style_btn_red, LV_STATE_DEFAULT, LV_COLOR_MAROON);
      lv_style_set_bg_color(&style_btn_red, LV_STATE_PRESSED, LV_COLOR_MAROON);
      lv_style_set_bg_grad_color(&style_btn_red, LV_STATE_PRESSED, LV_COLOR_RED);
      lv_style_set_text_color(&style_btn_red, LV_STATE_DEFAULT, LV_COLOR_WHITE);
      lv_obj_add_style(btn, LV_BTN_PART_MAIN, &style_btn_red); /*Add the red style on top of the current */
      lv_obj_t *label = lv_label_create(btn, NULL);            /*Add a label to the button*/
      lv_label_set_text(label, "app");                         /*Set the labels text*/
    }

    {
      lv_obj_t *btn = lv_btn_create(lv_scr_act(), NULL); /*Add a button the current screen*/
      lv_obj_set_pos(btn, 160, 160);                     /*Set its position*/
      // lv_obj_align(btn, NULL, LV_ALIGN_IN_BOTTOM_RIGHT, 0, 0);
      lv_obj_set_size(btn, 80, 80);               /*Set its size*/
      lv_obj_set_event_cb(btn, btn_event_def_cb); /*Assign a callback to the button*/
      static lv_style_t style_btn_red;
      lv_style_init(&style_btn_red);
      lv_style_set_bg_color(&style_btn_red, LV_STATE_DEFAULT, {0xff, 0x00, 0x00, 0x7f});
      lv_style_set_bg_grad_color(&style_btn_red, LV_STATE_DEFAULT, LV_COLOR_MAROON);
      lv_style_set_bg_color(&style_btn_red, LV_STATE_PRESSED, LV_COLOR_MAROON);
      lv_style_set_bg_grad_color(&style_btn_red, LV_STATE_PRESSED, LV_COLOR_RED);
      lv_style_set_text_color(&style_btn_red, LV_STATE_DEFAULT, LV_COLOR_WHITE);
      lv_obj_add_style(btn, LV_BTN_PART_MAIN, &style_btn_red); /*Add the red style on top of the current */
      lv_obj_t *label = lv_label_create(btn, NULL);            /*Add a label to the button*/
      lv_label_set_text(label, "def");                         /*Set the labels text*/
    }

    // zm831_home_app_reload(get_zm831_home_app());

    // extern zm831_home_app get_find_apriltag_app();
    // zm831_home_app_reload(get_find_apriltag_app());

    extern zm831_home_app get_imlib_find_blobs_app();
    zm831_home_app_reload(get_imlib_find_blobs_app());

    // int ret, stacksize = 204800; /*thread 堆栈设置为 20K */
    // pthread_attr_t attr;
    // ret = pthread_attr_init(&attr);
    // ret = pthread_attr_setstacksize(&attr, stacksize);
    // ret = pthread_create(&zm831->ai_thread, &attr, zm831_home_thread, NULL);
    // ret = pthread_attr_destroy(&attr);

    zm831->ai_th_usec = 40000; // 40ms 25fps 50% 30ms 65% 10ms 100fps 80%
    zm831->ai_th_id = pthread_create(&zm831->ai_thread, NULL, _zm831_home_loop, NULL);
    if(zm831->ai_th_id != 0)
    {
        printf("new thread create is failed.\n");
    }
    LIBMAIX_INFO_PRINTF("zm831_home_load");
  }

  void zm831_home_exit()
  {
    int *thread_ret = NULL;
    if (zm831->ai_th_usec)
    {
      zm831->ai_th_usec = 0;
      pthread_join(zm831->ai_thread, (void **)&thread_ret);
    }
    LIBMAIX_INFO_PRINTF("zm831_home_exit");
  }

  void zm831_home_loop()
  {
    // if (zm831->ai_th_keep > 60) { // 30ms * 60 = 1800ms
    //   zm831->ai_th_keep = 0;
    //   zm831->ai_th_usec = 30000; // 40ms 25fps 50% 30ms 65% 10ms 100fps 80%
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
