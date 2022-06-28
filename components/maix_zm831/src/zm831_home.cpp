
#include "zm831_uvai.hpp"

extern "C"
{
  extern zm831_uv *zm831;

// ==============================================================================================


  void zm831_ui_show_clear()
  {
    pthread_mutex_lock(&zm831->ui_mutex);
    lv_canvas_fill_bg(zm831->canvas, LV_COLOR_BLACK, LV_OPA_TRANSP);
    pthread_mutex_unlock(&zm831->ui_mutex);
  }

  void zm831_ui_show_image(cv::Mat &img, int x, int y, lv_opa_t opa)
  {
      pthread_mutex_lock(&zm831->ui_mutex);

      cv::Mat bgra;
      cv::cvtColor(img, bgra, cv::COLOR_RGB2BGRA);

      lv_img_dsc_t img_bgra;
      img_bgra.header.always_zero = 0;
      img_bgra.header.w = bgra.cols;
      img_bgra.header.h = bgra.rows;
      img_bgra.header.cf = LV_IMG_CF_TRUE_COLOR_ALPHA;
      img_bgra.data = (uint8_t*)bgra.data;
      img_bgra.data_size = bgra.cols * bgra.rows * LV_IMG_PX_SIZE_ALPHA_BYTE;

      lv_draw_img_dsc_t img_dsc;
      lv_draw_img_dsc_init(&img_dsc);
      img_dsc.opa = opa;
      lv_canvas_draw_img(zm831->canvas, x, y, &img_bgra, &img_dsc);

      pthread_mutex_unlock(&zm831->ui_mutex);
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

    usleep(zm831->ai_th_usec);

    if (!zm831->recvPacks.empty()){
      zm831_pack_t pack = zm831->recvPacks.front();
      zm831->recvPacks.pop_front();
      LIBMAIX_INFO_PRINTF("recv pack type: %d\n", pack.type);
      auto tmp = pack.data;
      for (int i = 0; i < tmp.size(); i++) printf(" 0x%02X", tmp[i]);
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

  int zm831_home_app_load(zm831_home_app *app);
  int zm831_home_app_loop(zm831_home_app *app);
  int zm831_home_app_exit(zm831_home_app *app);

  zm831_home_app get_zm831_home_app()
  {
    return {zm831_home_app_load, zm831_home_app_loop, zm831_home_app_exit, NULL};
  }

  // ==============================================================================================

  extern zm831_home_app get_qrcode_zbar_app();
  extern zm831_home_app get_nn_yolo_face_app();
  extern zm831_home_app get_qrcode_quirc_app();
  extern zm831_home_app get_find_apriltag_app();
  extern zm831_home_app get_imlib_find_blobs_app();
  extern zm831_home_app get_imlib_cube_color_app();
  extern zm831_home_app get_cv_nn_find_ball_app();
  extern zm831_home_app get_nn_classifier_resnet_app();
  extern zm831_home_app get_nn_retinaface_app();
  extern zm831_home_app get_nn_classifier_custom_app();
  extern zm831_home_app get_speech_asr_app();

  extern zm831_home_app get_function_0x01_app();

  int zm831_home_app_index = 0; // current app index
  static _get_zm831_home_app_func_ zm831_home_app_lists[] ={
    NULL, // 0 is disabled
    get_function_0x01_app,
    get_zm831_home_app,
    get_nn_classifier_custom_app,
    get_nn_retinaface_app,
    get_nn_classifier_resnet_app,
    get_cv_nn_find_ball_app,
    get_imlib_cube_color_app,
    get_qrcode_zbar_app,
    get_qrcode_quirc_app,
    get_nn_yolo_face_app,
    get_find_apriltag_app,
    get_imlib_find_blobs_app,
    // get_speech_asr_app,
  };

// ==============================================================================================

  zm831_home_app *app_bak, *app_run, app_old, app_new;

  void zm831_home_app_stop()
  {
    if (app_run) app_run->loop = NULL; // when app lopp stop & exit old app
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
    if (id == zm831_home_app_index) return 0;
    if (id < 0 || id >= sizeof(zm831_home_app_lists) / sizeof(zm831_home_app_lists[0]))
    {
      LIBMAIX_ERROR_PRINTF("zm831_home_app_select: id out of range");
      return -1;
    }
    if (zm831_home_app_lists[id] == NULL)
    {
      LIBMAIX_ERROR_PRINTF("zm831_home_app_select: id not found");
      return -1;
    }
    zm831_home_app_reload(zm831_home_app_lists[id]());
    zm831_home_app_index = id;
    return 0;
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

  //     if (cnt > 20) {
  //         zm831->exit = 1;
  //     }

  //     zm831_home_app_select(cnt);
  //   }
  // }

  void zm831_home_load()
  {
    // {
    //   lv_obj_t *btn = lv_btn_create(lv_scr_act(), NULL); /*Add a button the current screen*/
    //   lv_obj_set_pos(btn, 80, 160);                      /*Set its position*/
    //   // lv_obj_align(btn, NULL, LV_ALIGN_IN_BOTTOM_RIGHT, 0, 0);
    //   lv_obj_set_size(btn, 80, 80);               /*Set its size*/
    //   lv_obj_set_event_cb(btn, btn_event_app_cb); /*Assign a callback to the button*/
    //   static lv_style_t style_btn_red;
    //   lv_style_init(&style_btn_red);
    //   lv_style_set_bg_color(&style_btn_red, LV_STATE_DEFAULT, {0x00, 0x00, 0xff, 0x7f}); // bgra
    //   lv_style_set_bg_grad_color(&style_btn_red, LV_STATE_DEFAULT, LV_COLOR_MAROON);
    //   lv_style_set_bg_color(&style_btn_red, LV_STATE_PRESSED, LV_COLOR_MAROON);
    //   lv_style_set_bg_grad_color(&style_btn_red, LV_STATE_PRESSED, LV_COLOR_RED);
    //   lv_style_set_text_color(&style_btn_red, LV_STATE_DEFAULT, LV_COLOR_WHITE);
    //   lv_obj_add_style(btn, LV_BTN_PART_MAIN, &style_btn_red); /*Add the red style on top of the current */
    //   lv_obj_t *label = lv_label_create(btn, NULL);            /*Add a label to the button*/
    //   lv_label_set_text(label, "app");                         /*Set the labels text*/
    // }

    zm831_home_app_reload(get_zm831_home_app());

    zm831_home_app_select(1);

    zm831->ai_th_usec = 40000; // 40ms 25fps 50% 30ms 65% 10ms 100fps 80%

    zm831->ai_th_id = pthread_create(&zm831->ai_thread, NULL, _zm831_home_loop, NULL);

    // int ret, stacksize = 204800; /*thread 堆栈设置为 20K */
    // pthread_attr_t attr;
    // ret = pthread_attr_init(&attr);
    // ret = pthread_attr_setstacksize(&attr, stacksize);
    // zm831->ai_th_id = pthread_create(&zm831->ai_thread, &attr, _zm831_home_loop, NULL);
    // ret = pthread_attr_destroy(&attr);

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
      zm831_home_app_stop();
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
