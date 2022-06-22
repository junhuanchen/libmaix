
#include "zm831_uvai.hpp"

/*
designed UI > VI > HW > AI , UI ticks 5ms.
┌──────────────────────────────┐
│                              │
│  UI     touch & lvgl > 30fps │
│                              │
│  AI     ai & vision < 30fps  │
│                              │
│  HW     key & serial > 20fps │
│                              │
│  VI     rgb & yuv > 30fps    │
│                              │
└──────────────────────────────┘
*/

extern "C"
{
    zm831_uv _zm831_, *zm831 = &_zm831_;

    // static struct timeval old, now;

    static void cap_set()
    {
        return;
        // gettimeofday(&old, NULL);
    }

    static void cap_get(const char *tips)
    {
        return;
        // gettimeofday(&now, NULL);
        // if (now.tv_usec > old.tv_usec)
        //     printf("%20s - %5ld ms\r\n", tips, (now.tv_usec - old.tv_usec) / 1000);
    }

    unsigned char *g2d_allocMem(unsigned int size);
    int g2d_freeMem(void *vir_ptr);
    unsigned int g2d_getPhyAddrByVirAddr(void *vir_ptr);

    /**
     * Print the memory usage periodically
     * @param param
     */
    static void memory_monitor(lv_task_t *param)
    {
        (void)param; /*Unused*/

        lv_mem_monitor_t mon;
        lv_mem_monitor(&mon);
        printf("used: %6d (%3d %%), frag: %3d %%, biggest free: %6d\n",
               (int)mon.total_size - mon.free_size, mon.used_pct, mon.frag_pct,
               (int)mon.free_biggest_size);
    }

    void zm831_signal(int signal)
    {
        zm831->signal = signal;
        switch (signal)
        {
        case SIGINT:
        case SIGABRT:
        case SIGSEGV:
        {
            zm831->exit = 0;
            break;
        }
        case SIGALRM:
        {
            lv_tick_inc(5);
            break;
        }
        default:
            break;
        }
    }

    void _lvgl_ui_flush_(lv_disp_drv_t *drv, const lv_area_t *area, lv_color_t *color_p)
    {
        cap_set();
        if (zm831->ui)
        {
            void *tmp = zm831->ui->get_frame(zm831->ui, 9);
            if (tmp != NULL)
            {
                uint32_t *phy = NULL, *vir = NULL;
                zm831->ui->frame_addr(zm831->ui, tmp, &vir, &phy);
                cv::Mat ui_bgra(zm831->ui_h, zm831->ui_w, CV_8UC4, (unsigned char *)color_p);
                cv::Mat vo_bgra(zm831->ui_h, zm831->ui_w, CV_8UC4, (unsigned char *)vir[0]);
                ui_bgra.copyTo(vo_bgra);
                // pthread_mutex_lock(&zm831->ai_mutex);
                // zm831->ui_bgra = cv::Mat(zm831->ui_h, zm831->ui_w, CV_8UC4, (unsigned char *)color_p);
                // cv::rectangle(ui_bgra, cv::Point(20, 20), cv::Point(220, 220), cv::Scalar(255, 0, 0, 128), 20);
                // zm831->ui_bgra.copyTo(vo_bgra);
                // pthread_mutex_unlock(&zm831->ai_mutex);
                // cv::cvtColor(rgba, bgra, cv::COLOR_BGRA2RGBA);
                zm831->ui->set_frame(zm831->ui, tmp, 9);
                lv_disp_flush_ready(drv);
            }
        }
        cap_get("_lvgl_ui_flush_");
    }

    void zm831_ui_loop()
    {
        // CALC_FPS("zm831_ui_loop");
        pthread_mutex_lock(&zm831->ui_mutex);
        lv_task_handler();
        LIBMAIX_DEBUG_PRINTF("zm831_ui_loop");
        pthread_mutex_unlock(&zm831->ui_mutex);
    }

    void *zm831_ui_thread(void *)
    {
        while (zm831->ui_th_usec)
        {
            zm831_ui_loop();
            usleep(zm831->ui_th_usec);
        }
        return 0;
    }

    // static void btn_event_cb(lv_obj_t *btn, lv_event_t event)
    // {
    //     if (event == LV_EVENT_CLICKED)
    //     {
    //         static uint8_t cnt = 0;
    //         cnt++;
    //         /*Get the first child of the button which is the label and change its text*/
    //         lv_obj_t *label = lv_obj_get_child(btn, NULL);
    //         lv_label_set_text_fmt(label, "Button: %d", cnt);
    //         // if (cnt > 9) {
    //         //     zm831->exit = 1;
    //         // }
    //     }
    // }

    void zm831_ui_load()
    {
        lv_init();

        uint32_t size_in_px_cnt = zm831->ui_w * zm831->ui_h;
        zm831->ui_buf1 = (lv_color_t *)malloc(size_in_px_cnt * sizeof(lv_color_t));
        assert(zm831->ui_buf1);
        zm831->ui_buf2 = (lv_color_t *)malloc(size_in_px_cnt * sizeof(lv_color_t));
        assert(zm831->ui_buf2);

        /*Create a display buffer*/
        static lv_disp_buf_t disp_buf;
        lv_disp_buf_init(&disp_buf, zm831->ui_buf1, zm831->ui_buf2, size_in_px_cnt);

        /*Create a display*/
        lv_disp_drv_t disp_drv;
        lv_disp_drv_init(&disp_drv);
        disp_drv.buffer = &disp_buf;
        disp_drv.hor_res = zm831->ui_w;
        disp_drv.ver_res = zm831->ui_h;
        disp_drv.flush_cb = _lvgl_ui_flush_;
        lv_disp_drv_register(&disp_drv);

        evdev_mouse_set_file((char *)"/dev/input/event1");
        lv_indev_drv_t indev_drv;
        lv_indev_drv_init(&indev_drv);
        indev_drv.type = LV_INDEV_TYPE_POINTER;
        indev_drv.read_cb = evdev_mouse_read;
        lv_indev_t *mouse_indev = lv_indev_drv_register(&indev_drv);

        /*Set a cursor for the mouse*/
        LV_IMG_DECLARE(touch);                                    /*Declare the image file.*/
        lv_obj_t *cursor_obj = lv_img_create(lv_scr_act(), NULL); /*Create an image object for the cursor */
        lv_img_set_src(cursor_obj, &touch);                       /*Set the image source*/
        // lv_label_set_recolor(cursor_obj, true);
        // lv_label_set_text(cursor_obj, "#ff0000 .cursor");

        lv_indev_set_cursor(mouse_indev, cursor_obj);

        /* Optional:
         * Create a memory monitor task which prints the memory usage in
         * periodically.*/
        // lv_task_create(memory_monitor, 1000, LV_TASK_PRIO_MID, NULL);

        void lv_port_fs_init(void);

        lv_port_fs_init();

        lv_png_init();

        lv_style_init(&zm831->screen_style);
        // lv_style_set_bg_opa(&screen_style, LV_STATE_DEFAULT, LV_OPA_0);
        lv_style_set_bg_color(&zm831->screen_style, LV_STATE_DEFAULT, (lv_color_t){0x00, 0x00, 0x00, 0x00});
        lv_obj_add_style(lv_scr_act(), LV_OBJ_PART_MAIN, &zm831->screen_style); /*Default button style*/
        lv_obj_add_style(lv_scr_act(), LV_BTN_PART_MAIN, &zm831->screen_style); /*Default button style*/
        lv_obj_add_style(lv_scr_act(), LV_IMG_PART_MAIN, &zm831->screen_style); /*Default button style*/

        zm831->canvas = lv_canvas_create(lv_scr_act(), NULL);
        lv_canvas_set_buffer(zm831->canvas, zm831->canvas_buffer, zm831->ui_w, zm831->ui_h, LV_IMG_CF_TRUE_COLOR_ALPHA);
        lv_obj_align(zm831->canvas, NULL, LV_ALIGN_CENTER, 0, 0);

        // lv_obj_t *screen = lv_obj_create(lv_scr_act(), NULL);
        // lv_obj_set_size(screen, disp_width, disp_height);
        // lv_obj_add_style(screen, LV_OBJ_PART_MAIN, &screen_style);
        // lv_obj_align(screen, NULL, LV_ALIGN_CENTER, 0, 0);

        // lv_obj_t *obj = lv_img_create(lv_scr_act(), NULL);
        // lv_img_set_src(obj, "/home/res/logo.png");
        // lv_obj_add_style(obj, LV_STATE_DEFAULT, &screen_style);
        // lv_obj_align(obj, NULL, LV_ALIGN_CENTER, 0, 0);

        // lv_obj_t *btn = lv_btn_create(lv_scr_act(), NULL); /*Add a button the current screen*/
        // // lv_obj_set_pos(btn, 0, 0);                     /*Set its position*/
        // lv_obj_align(btn, NULL, LV_ALIGN_CENTER, 0, 0);
        // lv_obj_set_size(btn, 120, 120);         /*Set its size*/
        // lv_obj_set_event_cb(btn, btn_event_cb); /*Assign a callback to the button*/
        // static lv_style_t style_btn_red;
        // lv_style_init(&style_btn_red);
        // lv_style_set_bg_color(&style_btn_red, LV_STATE_DEFAULT,  {0xff, 0x00, 0x00, 0x7f});
        // lv_style_set_bg_grad_color(&style_btn_red, LV_STATE_DEFAULT, LV_COLOR_MAROON);
        // lv_style_set_bg_color(&style_btn_red, LV_STATE_PRESSED, LV_COLOR_MAROON);
        // lv_style_set_bg_grad_color(&style_btn_red, LV_STATE_PRESSED, LV_COLOR_RED);
        // lv_style_set_text_color(&style_btn_red, LV_STATE_DEFAULT, LV_COLOR_WHITE);
        // lv_obj_add_style(btn, LV_BTN_PART_MAIN, &style_btn_red); /*Add the red style on top of the current */
        // lv_obj_t *label = lv_label_create(btn, NULL);            /*Add a label to the button*/
        // lv_label_set_text(label, "Button");                      /*Set the labels text*/

        // lv_demo_widgets();

        signal(SIGALRM, zm831_signal);
        ualarm(5000, 5000); // 5ms

        zm831->ui_th_usec = 20000; // 20ms > 5ms
        int ret = pthread_create(&zm831->ui_thread, NULL, zm831_ui_thread, NULL);
        // (ret != 0) ? -1 : 0;

        LIBMAIX_DEBUG_PRINTF("zm831_ui_init");
    }

    void zm831_ui_exit()
    {
        int *thread_ret = NULL;
        if (zm831->ui_th_usec)
        {
            zm831->ui_th_usec = 0;
            pthread_join(zm831->ui_thread, (void **)&thread_ret);
        }

        ualarm(0, 0);

        if (zm831->ui_buf1)
            free(zm831->ui_buf1), zm831->ui_buf1 = NULL;
        if (zm831->ui_buf1)
            free(zm831->ui_buf2), zm831->ui_buf2 = NULL;

        LIBMAIX_DEBUG_PRINTF("zm831_ui_exit");
    }

    // // =========================================================================================

    // static struct _zm831_ai_
    // {
    //     const char *labels[1] = {"face"};
    //     const char *inputs_names[1] = {"input0"};
    //     const char *outputs_names[1] = {"output0"};
    //     float anchors[10] = {1.19, 1.98, 2.79, 4.59, 4.53, 8.92, 8.06, 5.29, 10.32, 10.65};
    //     float *output_buffer;
    //     uint8_t *quantize_buffer;
    //     libmaix_nn_t *nn;
    //     libmaix_nn_model_path_t model_path;
    //     libmaix_nn_opt_param_t opt_param;
    //     libmaix_nn_layer_t input;
    //     libmaix_nn_layer_t out_fmap;
    //     libmaix_nn_decoder_t *yolo2_decoder;
    //     libmaix_nn_decoder_yolo2_config_t yolo2_config;
    //     libmaix_nn_decoder_yolo2_result_t yolo2_result;
    // } _zm831_ai, *zm831_ai = &_zm831_ai;

    // int zm831_ai_load()
    // {
    //     libmaix_err_t err = LIBMAIX_ERR_NONE;

    //     zm831_ai->yolo2_config = {
    //         .classes_num = 1,
    //         .threshold = 0.5,
    //         .nms_value = 0.3,
    //         .anchors_num = 5,
    //         .anchors = zm831_ai->anchors,
    //         .net_in_width = 224,
    //         .net_in_height = 224,
    //         .net_out_width = 7,
    //         .net_out_height = 7,
    //         .input_width = 224,
    //         .input_height = 224
    //     };

    //     printf("zm831_ai->yolo2_config.classes_num: %d\n", zm831_ai->yolo2_config.classes_num);
    //     printf("zm831_ai->yolo2_config.threshold: %f\n", zm831_ai->yolo2_config.threshold);
    //     printf("zm831_ai->yolo2_config.nms_value: %f\n", zm831_ai->yolo2_config.nms_value);
    //     printf("zm831_ai->yolo2_config.anchors_num: %d\n", zm831_ai->yolo2_config.anchors_num);
    //     printf("zm831_ai->yolo2_config.net_in_width: %d\n", zm831_ai->yolo2_config.net_in_width);
    //     printf("zm831_ai->yolo2_config.net_in_height: %d\n", zm831_ai->yolo2_config.net_in_height);
    //     printf("zm831_ai->yolo2_config.net_out_width: %d\n", zm831_ai->yolo2_config.net_out_width);
    //     printf("zm831_ai->yolo2_config.net_out_height: %d\n", zm831_ai->yolo2_config.net_out_height);
    //     printf("zm831_ai->yolo2_config.input_width: %d\n", zm831_ai->yolo2_config.input_width);
    //     printf("zm831_ai->yolo2_config.input_height: %d\n", zm831_ai->yolo2_config.input_height);
    //     printf("zm831_ai->yolo2_config.anchors: %p\n", zm831_ai->yolo2_config.anchors);
    //     for(int i = 0; i < zm831_ai->yolo2_config.anchors_num * 2; i++)
    //         printf("zm831_ai->yolo2_config.anchors[%d]: %f\n", i, zm831_ai->yolo2_config.anchors[i]);

    //     zm831_ai->opt_param.awnn.input_names = (char **)zm831_ai->inputs_names;
    //     zm831_ai->opt_param.awnn.output_names = (char **)zm831_ai->outputs_names;
    //     zm831_ai->opt_param.awnn.input_num = 1;  // len(input_names)
    //     zm831_ai->opt_param.awnn.output_num = 1; // len(output_names)

    //     zm831_ai->opt_param.awnn.mean[0] = 127.5;
    //     zm831_ai->opt_param.awnn.mean[1] = zm831_ai->opt_param.awnn.mean[0];
    //     zm831_ai->opt_param.awnn.mean[2] = zm831_ai->opt_param.awnn.mean[0];

    //     zm831_ai->opt_param.awnn.norm[0] = 0.0078125;
    //     zm831_ai->opt_param.awnn.norm[1] = zm831_ai->opt_param.awnn.norm[0];
    //     zm831_ai->opt_param.awnn.norm[2] = zm831_ai->opt_param.awnn.norm[0];

    //     zm831_ai->model_path.awnn.param_path = (char *)"/home/res/yolo2_face_int8.param";
    //     zm831_ai->model_path.awnn.bin_path = (char *)"/home/res/yolo2_face_int8.bin";

    //     zm831_ai->input = {
    //         .w = 224,
    //         .h = 224,
    //         .c = 3,
    //         .dtype = LIBMAIX_NN_DTYPE_UINT8,
    //     };
    //     zm831_ai->input.need_quantization = true;

    //     zm831_ai->out_fmap = {
    //         .w = 7,
    //         .h = 7,
    //         .c = 30,
    //         .dtype = LIBMAIX_NN_DTYPE_FLOAT,
    //     };

    //     zm831_ai->output_buffer = (float *)malloc(zm831_ai->out_fmap.w * zm831_ai->out_fmap.h * zm831_ai->out_fmap.c * sizeof(float));
    //     if (!zm831_ai->output_buffer)
    //     {
    //     LIBMAIX_INFO_PRINTF("no memory!!!\n");
    //     return -1;
    //     }

    //     zm831_ai->quantize_buffer = (uint8_t *)malloc(zm831_ai->input.w * zm831_ai->input.h * zm831_ai->input.c);
    //     if (!zm831_ai->quantize_buffer)
    //     {
    //     LIBMAIX_INFO_PRINTF("no memory!!!\n");
    //     return -1;
    //     }

    //     zm831_ai->out_fmap.data = zm831_ai->output_buffer;
    //     zm831_ai->input.buff_quantization = zm831_ai->quantize_buffer;

    //     LIBMAIX_INFO_PRINTF("-- nn create\n");
    //     zm831_ai->nn = libmaix_nn_create();
    //     if (!zm831_ai->nn)
    //     {
    //     LIBMAIX_INFO_PRINTF("libmaix_nn object create fail\n");
    //     return -1;
    //     }
    //     LIBMAIX_INFO_PRINTF("-- nn object init\n");
    //     err = zm831_ai->nn->init(zm831_ai->nn);
    //     if (err != LIBMAIX_ERR_NONE)
    //     {
    //     LIBMAIX_INFO_PRINTF("libmaix_nn init fail: %s\n", libmaix_get_err_msg(err));
    //     return -1;
    //     }
    //     LIBMAIX_INFO_PRINTF("-- nn object load model\n");
    //     err = zm831_ai->nn->load(zm831_ai->nn, &zm831_ai->model_path, &zm831_ai->opt_param);
    //     if (err != LIBMAIX_ERR_NONE)
    //     {
    //     LIBMAIX_INFO_PRINTF("libmaix_nn load fail: %s\n", libmaix_get_err_msg(err));
    //     return -1;
    //     }

    //     LIBMAIX_INFO_PRINTF("-- yolo2 decoder create\n");
    //     zm831_ai->yolo2_decoder = libmaix_nn_decoder_yolo2_create();
    //     if (!zm831_ai->yolo2_decoder)
    //     {
    //     LIBMAIX_INFO_PRINTF("no mem\n");
    //     return -1;
    //     }
    //     LIBMAIX_INFO_PRINTF("-- yolo2 decoder init\n");
    //     err = zm831_ai->yolo2_decoder->init(zm831_ai->yolo2_decoder, (void *)&zm831_ai->yolo2_config);
    //     if (err != LIBMAIX_ERR_NONE)
    //     {
    //     LIBMAIX_INFO_PRINTF("decoder init error:%d\n", err);
    //     return -1;
    //     }

    //     LIBMAIX_INFO_PRINTF("nn_gestures_app_load");
    // }

    // int zm831_ai_exit()
    // {
    //     if(zm831_ai->yolo2_decoder)
    //     {
    //         zm831_ai->yolo2_decoder->deinit(zm831_ai->yolo2_decoder);
    //         libmaix_nn_decoder_yolo2_destroy(&zm831_ai->yolo2_decoder);
    //         zm831_ai->yolo2_decoder = NULL;
    //     }
    //     if(zm831_ai->output_buffer)
    //     {
    //         free(zm831_ai->output_buffer);
    //         zm831_ai->output_buffer = NULL;
    //     }
    //     if(zm831_ai->nn)
    //     {
    //         libmaix_nn_destroy(&zm831_ai->nn);
    //     }
    // }

    // int zm831_ai_loop()
    // {
    //     libmaix_err_t err = LIBMAIX_ERR_NONE;
    //     libmaix_image_t *ai_rgb = NULL;
    //     if (LIBMAIX_ERR_NONE == zm831->ai->capture_image(zm831->ai, &ai_rgb))
    //     {
    //         zm831_ai->input.data = ai_rgb->data;
    //         err = zm831_ai->nn->forward(zm831_ai->nn, &zm831_ai->input, &zm831_ai->out_fmap);
    //         if(err != LIBMAIX_ERR_NONE)
    //         {
    //             printf("libmaix_nn forward fail: %s\n", libmaix_get_err_msg(err));\
    //         }

    //         err = zm831_ai->yolo2_decoder->decode(zm831_ai->yolo2_decoder, &zm831_ai->out_fmap, (void*)&zm831_ai->yolo2_result);
    //         if(err != LIBMAIX_ERR_NONE)
    //         {
    //             printf("yolo2 decode fail: %s\n", libmaix_get_err_msg(err));
    //         }

    //         if(zm831_ai->yolo2_result.boxes_num > 0)
    //         {
    //             // libmaix_nn_decoder_yolo2_draw(zm831_ai, zm831_ai->yolo2_decoder, &zm831_ai->yolo2_result);
    //             LIBMAIX_INFO_PRINTF("yolo2_result.boxes_num %d", zm831_ai->yolo2_result.boxes_num);
    //         }
    //     }
    // }

    // // =========================================================================================

    void zm831_vi_load()
    {
        LIBMAIX_DEBUG_PRINTF("zm831_vi_load");
        libmaix_camera_module_init();
        libmaix_image_module_init();
        libmaix_nn_module_init();

        zm831->vi_w = zm831_vi_w, zm831->vi_h = zm831_vi_h;
        zm831->ai_w = zm831_ai_w, zm831->ai_h = zm831_ai_h;
        zm831->ui_w = zm831_ui_w, zm831->ui_h = zm831_ui_h;

        zm831->vi = libmaix_cam_create(0, zm831->vi_w, zm831->vi_h, 1, 0);
        if (NULL == zm831->vi)
            return;
        zm831->vi->start_capture(zm831->vi);

        // zm831->vi_yuv = (uint8_t *)g2d_allocMem(zm831->vi_w * zm831->vi_h * 3 / 2);
        // if (NULL == zm831->vi_yuv)
        //     return;

        zm831->ai = libmaix_cam_create(1, zm831->ai_w, zm831->ai_h, 0, 0);
        if (NULL == zm831->ai)
            return;
        zm831->ai->start_capture(zm831->ai);

        // zm831->ai_rgb = (uint8_t *)malloc(zm831->ai_w * zm831->ai_h * 3);
        // if (NULL == zm831->ai_rgb)
        //     return;

        zm831->ui = libmaix_vo_create(zm831->ui_w, zm831->ui_h, 0, 0, zm831->ui_w, zm831->ui_h);
        if (NULL == zm831->ui)
            return;

        // zm831->ui_rgba = libmaix_image_create(zm831->ui_w, zm831->ui_h, LIBMAIX_IMAGE_MODE_RGBA8888, LIBMAIX_IMAGE_LAYOUT_HWC, NULL, false);
        // if (NULL == zm831->ui_rgba)
        //     return;

        zm831->vi_th_usec = 30 * 1000; // 30ms 33fps for vi & hw
    }

    void zm831_vi_exit()
    {
        if (NULL != zm831->vi)
            libmaix_cam_destroy(&zm831->vi);

        // if (NULL != zm831->vi_yuv)
        //     g2d_freeMem(zm831->vi_yuv), zm831->vi_yuv = NULL;

        if (NULL != zm831->ai)
            libmaix_cam_destroy(&zm831->ai);

        // if (NULL != zm831->ai_rgb)
        //     free(zm831->ai_rgb), zm831->ai_rgb = NULL;

        if (NULL != zm831->ui)
            libmaix_vo_destroy(&zm831->ui), zm831->ui = NULL;

        // if (zm831->ui_rgba)
        //     libmaix_image_destroy(&zm831->ui_rgba);

        libmaix_nn_module_deinit();
        libmaix_image_module_deinit();
        libmaix_camera_module_deinit();
        LIBMAIX_DEBUG_PRINTF("zm831_vi_exit");

    }

    void zm831_vi_loop()
    {
        // CALC_FPS("zm831_vi_loop");
        // LIBMAIX_INFO_PRINTF("zm831_vi_loop");

        cap_set();
        void *frame = zm831->ui->get_frame(zm831->ui, 0);
        if (frame != NULL)
        {
            uint32_t *phy = NULL, *vir = NULL;
            zm831->ui->frame_addr(zm831->ui, frame, &vir, &phy);
            if (LIBMAIX_ERR_NONE == zm831->vi->capture(zm831->vi, (unsigned char *)vir[0]))
            {
                zm831->ui->set_frame(zm831->ui, frame, 0);
            }
        }
        cap_get("zm831->vi");

        // cap_set();
        // pthread_mutex_lock(&zm831->vi_mutex);
        // if (LIBMAIX_ERR_NONE == zm831->ai->capture_image(zm831->ai, &zm831->ai_rgb))
        // {
        //     // cv::Mat cv_src(zm831->ai_rgb->height, zm831->ai_rgb->width, CV_8UC3, zm831->ai_rgb->data);
        //     // cv::rectangle(cv_src, cv::Point(24, 24), cv::Point(200, 200), cv::Scalar(255, 0, 0), 5);
        //     // void *tmp = zm831->ui->get_frame(zm831->ui, 9);
        //     // if (tmp != NULL)
        //     // {
        //     //     uint32_t *phy = NULL, *vir = NULL;
        //     //     zm831->ui->frame_addr(zm831->ui, tmp, &vir, &phy);
        //     //     cv::Mat bgra(zm831->ui_h, zm831->ui_w, CV_8UC4, (unsigned char *)vir[0]);
        //     //     cv::rectangle(bgra, cv::Point(20, 20), cv::Point(220, 220), cv::Scalar(0, 0, 255, 128), 20);
        //     //     // cv::Mat cv_dst;
        //     //     // cv::resize(cv_src, cv_dst, cv::Size(zm831->ui_w, zm831->ui_h));
        //     //     // cv::cvtColor(cv_dst, bgra, cv::COLOR_RGB2BGRA);
        //     //     zm831->ui->set_frame(zm831->ui, tmp, 9);
        //     // }
        // }
        // pthread_mutex_unlock(&zm831->vi_mutex);
        // cap_get("zm831->ai");
    }

    void maix_zm831_main(int argc, char *argv[])
    {
        void zm831_ctrl_load();
        void zm831_home_load();
        void zm831_ctrl_loop();
        void zm831_home_loop();
        void zm831_ctrl_exit();
        void zm831_home_exit();

        pthread_mutex_init(&zm831->vi_mutex, NULL);
        pthread_mutex_init(&zm831->ai_mutex, NULL);
        pthread_mutex_init(&zm831->ui_mutex, NULL);

        zm831->exit = 0;
        signal(SIGINT, zm831_signal);
        signal(SIGABRT, zm831_signal);
        signal(SIGSEGV, zm831_signal);
        zm831_vi_load();
        zm831_ui_load();
        // zm831_ai_load();
        zm831_ctrl_load();
        zm831_home_load();

        while (zm831->exit == 0)
        {
            usleep(zm831->vi_th_usec); // 30ms 33fps for vi & hw
            zm831_vi_loop();
            zm831_ctrl_loop();
            zm831_home_loop();
            // zm831_ui_loop();
            // zm831_ai_loop();
        }

        // extern int imlib_find_blobs_app_load(zm831_home_app *app);
        // extern int imlib_find_blobs_app_loop(zm831_home_app *app);
        // extern int imlib_find_blobs_app_exit(zm831_home_app *app);
        // extern zm831_home_app get_imlib_find_blobs_app();
        // zm831_home_app tmp = get_imlib_find_blobs_app();
        // imlib_find_blobs_app_load(&tmp);
        // while (zm831->exit == 0)
        // {
        //     usleep(zm831->vi_th_usec);
        //     zm831_vi_loop();
        //     zm831_ctrl_loop();
        //     // zm831_home_loop();
        //     imlib_find_blobs_app_loop(&tmp);
        // }

        // imlib_find_blobs_app_exit(&tmp);

        zm831_home_exit();
        zm831_ctrl_exit();
        // zm831_ai_exit();
        zm831_ui_exit();
        zm831_vi_exit();
        zm831->exit = 1;
    }
}
