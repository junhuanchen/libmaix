
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

    uint32_t zm831_get_ms()
    {
        static struct timespec tmp;
        clock_gettime(CLOCK_MONOTONIC, &tmp);
        return (tmp.tv_sec * 1000) + (uint32_t)tmp.tv_nsec / 1000000;
    }

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
        if (zm831->vo)
        {
            void *tmp = zm831->vo->get_frame(zm831->vo, 9);
            if (tmp != NULL)
            {
                uint32_t *phy = NULL, *vir = NULL;
                zm831->vo->frame_addr(zm831->vo, tmp, &vir, &phy);
                cv::Mat ui_bgra(zm831->ui_h, zm831->ui_w, CV_8UC4, (unsigned char *)color_p);
                // cv::flip(ui_bgra, ui_bgra, -1);
                cv::Mat vo_bgra(zm831->ui_h, zm831->ui_w, CV_8UC4, (unsigned char *)vir[0]);
                ui_bgra.copyTo(vo_bgra);
                // pthread_mutex_lock(&zm831->ai_mutex);
                // zm831->ui_bgra = cv::Mat(zm831->ui_h, zm831->ui_w, CV_8UC4, (unsigned char *)color_p);
                // cv::rectangle(ui_bgra, cv::Point(20, 20), cv::Point(220, 220), cv::Scalar(255, 0, 0, 128), 20);
                // zm831->ui_bgra.copyTo(vo_bgra);
                // pthread_mutex_unlock(&zm831->ai_mutex);
                // cv::cvtColor(rgba, bgra, cv::COLOR_BGRA2RGBA);
                zm831->vo->set_frame(zm831->vo, tmp, 9);
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
        while (zm831->ui_th_ms)
        {
            zm831_ui_loop();
            msleep(zm831->ui_th_ms);
            // CALC_FPS("ui");
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

        // zm831->canvas = lv_canvas_create(lv_scr_act(), NULL);
        // lv_canvas_set_buffer(zm831->canvas, zm831->canvas_buffer, zm831->ui_w, zm831->ui_h, LV_IMG_CF_TRUE_COLOR_ALPHA);
        // lv_obj_align(zm831->canvas, NULL, LV_ALIGN_CENTER, 0, 0);

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

        /*Init freetype library
        /* init freetype library */
        lv_freetype_init(64, 1, 0);

        /*Create a font*/
        zm831->ft_font.name = "/home/res/sans.ttf";
        zm831->ft_font.weight = 20;
        zm831->ft_font.style = FT_FONT_STYLE_NORMAL;
        lv_ft_font_init(&zm831->ft_font);

        // lv_style_set_text_font(&zm831->screen_style, LV_STATE_DEFAULT, zm831->ft_font.font);
        // lv_obj_add_style(zm831->canvas, LV_LABEL_PART_MAIN, &zm831->screen_style);

        // /*Create style with the new font*/
        // static lv_style_t style;
        // lv_style_init(&style);
        // lv_style_set_text_font(&style, LV_STATE_DEFAULT, sans_ft.font);

        // /*Create a label with the new style*/
        // lv_obj_t * label = lv_label_create(lv_scr_act(), NULL);
        // lv_obj_add_style(label, LV_LABEL_PART_MAIN, &style);
        // lv_label_set_text(label, "你好 Hi 今天");

        signal(SIGALRM, zm831_signal);
        ualarm(0, 10000); // 10ms

        zm831->ui_th_ms = 20; // 20ms > 5ms
        int ret = pthread_create(&zm831->ui_thread, NULL, zm831_ui_thread, NULL);
        // (ret != 0) ? -1 : 0;

        LIBMAIX_DEBUG_PRINTF("zm831_ui_init");
    }

    void zm831_ui_exit()
    {
        int *thread_ret = NULL;
        if (zm831->ui_th_ms)
        {
            zm831->ui_th_ms = 0;
            pthread_join(zm831->ui_thread, (void **)&thread_ret);
        }

        ualarm(0, 0);

        if (zm831->ui_buf1)
            free(zm831->ui_buf1), zm831->ui_buf1 = NULL;
        if (zm831->ui_buf1)
            free(zm831->ui_buf2), zm831->ui_buf2 = NULL;

        LIBMAIX_DEBUG_PRINTF("zm831_ui_exit");
    }

    lv_obj_t *zm831_ui_get_canvas()
    {
        if (!lv_debug_check_obj_valid(zm831->canvas))
        {
            zm831->canvas = lv_canvas_create(lv_scr_act(), NULL);
            if (zm831->canvas == NULL)
            {
                LIBMAIX_INFO_PRINTF("zm831->canvas == NULL !!!");
                return NULL;
            }
            lv_canvas_set_buffer(zm831->canvas, zm831->canvas_buffer, zm831->ui_w, zm831->ui_h, LV_IMG_CF_TRUE_COLOR_ALPHA);
        }
        return zm831->canvas;
    }

    void zm831_ui_show_clear()
    {
        pthread_mutex_lock(&zm831->ui_mutex);
        lv_canvas_fill_bg(zm831_ui_get_canvas(), LV_COLOR_BLACK, LV_OPA_TRANSP);
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
        img_bgra.data = (uint8_t *)bgra.data;
        img_bgra.data_size = bgra.cols * bgra.rows * LV_IMG_PX_SIZE_ALPHA_BYTE;

        lv_draw_img_dsc_t img_dsc;
        lv_draw_img_dsc_init(&img_dsc);
        img_dsc.opa = opa;

        lv_canvas_draw_img(zm831_ui_get_canvas(), x, y, &img_bgra, &img_dsc);

        pthread_mutex_unlock(&zm831->ui_mutex);
    }

    // =========================================================================================
    /*
    static struct _zm831_ai_
    {
        const char *model_path_param = "/home/res/yolo2_face_int8.param";
        const char *model_path_bin = "/home/res/yolo2_face_int8.bin";
        const char *inputs_names[1] = {"input0"};
        const char *outputs_names[1] = {"output0"};
        const float opt_param_mean = 127.5;
        const float opt_param_norm = 0.0078125;
        libmaix_nn_layer_t input = {
            .w = 224,
            .h = 224,
            .c = 3,
            .dtype = LIBMAIX_NN_DTYPE_UINT8,
        };
        libmaix_nn_layer_t out_fmap = {
            .w = 7,
            .h = 7,
            .c = 30,
            .dtype = LIBMAIX_NN_DTYPE_FLOAT,
        };
        libmaix_nn_t *nn;
        libmaix_nn_model_path_t model_path;
        libmaix_nn_opt_param_t opt_param;
        // -------------- yolo2 decode -----------------------
        const char *labels[1] = {"face"};
        const float anchors[10] = {1.19, 1.98, 2.79, 4.59, 4.53, 8.92, 8.06, 5.29, 10.32, 10.65};
        libmaix_nn_decoder_t *yolo2_decoder;
        libmaix_nn_decoder_yolo2_result_t yolo2_result;
        libmaix_nn_decoder_yolo2_config_t yolo2_config = {
            .classes_num = sizeof(labels) / sizeof(anchors[0]),
            .threshold = 0.5,
            .nms_value = 0.3,
            .anchors_num = (sizeof(anchors) / sizeof(anchors[0])) / 2,
            .anchors = (float *)anchors,
            .net_in_width = 224,
            .net_in_height = 224,
            .net_out_width = 7,
            .net_out_height = 7,
            .input_width = 224,
            .input_height = 224};
    } _zm831_ai, *zm831_ai = &_zm831_ai;

    static int max_index(float *a, int n)
    {
        int i, max_i = 0;
        float max = a[0];

        for (i = 1; i < n; ++i)
        {
            if (a[i] > max)
            {
                max = a[i];
                max_i = i;
            }
        }
        return max_i;
    }

    static void libmaix_nn_decoder_yolo2_draw(_zm831_ai_ *self, struct libmaix_nn_decoder *obj, libmaix_nn_decoder_yolo2_result_t *result)
    {
        region_layer_t *rl = (region_layer_t *)obj->data;
        char *label = NULL;
        uint32_t image_width = rl->config->input_width;
        uint32_t image_height = rl->config->input_height;
        float threshold = rl->config->threshold;
        libmaix_nn_decoder_yolo2_box_t *boxes = result->boxes;

        for (int i = 0; i < result->boxes_num; ++i)
        {
            int class_id = max_index(rl->probs[i], rl->config->classes_num);
            float prob = result->probs[i][class_id];
            if (prob > threshold)
            {
                libmaix_nn_decoder_yolo2_box_t *b = boxes + i;
                uint32_t x = b->x * image_width - (b->w * image_width / 2);
                uint32_t y = b->y * image_height - (b->h * image_height / 2);
                uint32_t w = b->w * image_width;
                uint32_t h = b->h * image_height;
                printf("%d %d %d %d %d %f %s\n", x, y, w, h, prob, self->labels[class_id]);
            }
        }
    }

    int zm831_ai_load(_zm831_ai_ *self)
    {
        libmaix_err_t err = LIBMAIX_ERR_NONE;

        self->opt_param.awnn.input_names = (char **)self->inputs_names;
        self->opt_param.awnn.output_names = (char **)self->outputs_names;
        self->opt_param.awnn.input_num = sizeof(self->inputs_names) / sizeof(self->inputs_names[0]);
        self->opt_param.awnn.output_num = sizeof(self->outputs_names) / sizeof(self->outputs_names[0]);

        self->opt_param.awnn.mean[0] = self->opt_param_mean;
        self->opt_param.awnn.mean[1] = self->opt_param.awnn.mean[0];
        self->opt_param.awnn.mean[2] = self->opt_param.awnn.mean[0];

        self->opt_param.awnn.norm[0] = self->opt_param_norm;
        self->opt_param.awnn.norm[1] = self->opt_param.awnn.norm[0];
        self->opt_param.awnn.norm[2] = self->opt_param.awnn.norm[0];

        self->model_path.awnn.param_path = (char *)self->model_path_param;
        self->model_path.awnn.bin_path = (char *)self->model_path_bin;

        self->input.need_quantization = true;

        self->out_fmap.data = (float *)malloc(self->out_fmap.w * self->out_fmap.h * self->out_fmap.c * sizeof(float));
        if (!self->out_fmap.data)
        {
            LIBMAIX_INFO_PRINTF("no memory!!!\n");
            return -1;
        }

        self->input.buff_quantization = (uint8_t *)malloc(self->input.w * self->input.h * self->input.c);
        if (!self->input.buff_quantization)
        {
            LIBMAIX_INFO_PRINTF("no memory!!!\n");
            return -1;
        }

        LIBMAIX_INFO_PRINTF("-- nn create\n");
        self->nn = libmaix_nn_create();
        if (!self->nn)
        {
            LIBMAIX_INFO_PRINTF("libmaix_nn object create fail\n");
            return -1;
        }
        LIBMAIX_INFO_PRINTF("-- nn object init\n");
        err = self->nn->init(self->nn);
        if (err != LIBMAIX_ERR_NONE)
        {
            LIBMAIX_INFO_PRINTF("libmaix_nn init fail: %s\n", libmaix_get_err_msg(err));
            return -1;
        }
        LIBMAIX_INFO_PRINTF("-- nn object load model\n");
        err = self->nn->load(self->nn, &self->model_path, &self->opt_param);
        if (err != LIBMAIX_ERR_NONE)
        {
            LIBMAIX_INFO_PRINTF("libmaix_nn load fail: %s\n", libmaix_get_err_msg(err));
            return -1;
        }

        LIBMAIX_INFO_PRINTF("-- yolo2 decoder create\n");
        self->yolo2_decoder = libmaix_nn_decoder_yolo2_create(libmaix_nn_decoder_yolo2_init,
                                                              libmaix_nn_decoder_yolo2_deinit,
                                                              libmaix_nn_decoder_yolo2_decode);
        if (!self->yolo2_decoder)
        {
            LIBMAIX_INFO_PRINTF("no mem\n");
            return -1;
        }
        LIBMAIX_INFO_PRINTF("-- yolo2 decoder init\n");
        err = self->yolo2_decoder->init(self->yolo2_decoder, (void *)&self->yolo2_config);
        if (err != LIBMAIX_ERR_NONE)
        {
            LIBMAIX_INFO_PRINTF("decoder init error:%d\n", err);
            return -1;
        }

        LIBMAIX_INFO_PRINTF("nn_gestures_app_load");
    }

    int zm831_ai_exit(_zm831_ai_ *self)
    {
        if (self->yolo2_decoder)
        {
            self->yolo2_decoder->deinit(self->yolo2_decoder);
            libmaix_nn_decoder_yolo2_destroy(&self->yolo2_decoder);
            self->yolo2_decoder = NULL;
        }
        if (self->input.buff_quantization)
        {
            free(self->input.buff_quantization);
            self->input.buff_quantization = NULL;
        }
        if (self->out_fmap.data)
        {
            free(self->out_fmap.data);
            self->out_fmap.data = NULL;
        }
        if (self->nn)
        {
            libmaix_nn_destroy(&self->nn);
        }
    }

    int zm831_ai_loop(_zm831_ai_ *self)
    {
        libmaix_err_t err = LIBMAIX_ERR_NONE;
        libmaix_image_t *ai_rgb = NULL;
        if (zm831->ai && LIBMAIX_ERR_NONE == zm831->ai->capture_image(zm831->ai, &ai_rgb))
        {
            // LIBMAIX_INFO_PRINTF("ai_rgb: %p, %d, %d\r\n", ai_rgb, ai_rgb->width, ai_rgb->height);
            // cv::Mat rgb(ai_rgb->height, ai_rgb->width, CV_8UC3, ai_rgb->data);

            self->input.data = ai_rgb->data;
            err = self->nn->forward(self->nn, &self->input, &self->out_fmap);
            if (err != LIBMAIX_ERR_NONE)
            {
                printf("libmaix_nn forward fail: %s\n", libmaix_get_err_msg(err));
            }

            err = self->yolo2_decoder->decode(self->yolo2_decoder, &self->out_fmap, (void *)&self->yolo2_result);
            if (err != LIBMAIX_ERR_NONE)
            {
                printf("yolo2 decode fail: %s\n", libmaix_get_err_msg(err));
            }

            if (self->yolo2_result.boxes_num > 0)
            {
                // libmaix_nn_decoder_yolo2_draw(self, self->yolo2_decoder, &self->yolo2_result);
                LIBMAIX_INFO_PRINTF("yolo2_result.boxes_num %d", self->yolo2_result.boxes_num);
            }
        }
        CALC_FPS("ai");
        return 0;
    }
    */
    // =========================================================================================

    void zm831_vi_open()
    {
        zm831->vi = libmaix_cam_create(0, zm831->vi_w, zm831->vi_h, 0, 0);
        if (NULL == zm831->vi)
            return;
        zm831->vi->start_capture(zm831->vi);

        zm831->ai = libmaix_cam_create(1, zm831->ai_w, zm831->ai_h, 0, 0);
        if (NULL == zm831->ai)
            return;
        zm831->ai->start_capture(zm831->ai);
    }

    void zm831_vi_stop()
    {
        if (NULL != zm831->vi)
            libmaix_cam_destroy(&zm831->vi);

        if (NULL != zm831->ai)
            libmaix_cam_destroy(&zm831->ai);
    }

    void zm831_vi_load()
    {
        LIBMAIX_DEBUG_PRINTF("zm831_vi_load");
        libmaix_camera_module_init();
        libmaix_image_module_init();
        libmaix_nn_module_init();

        zm831->vi_w = zm831_vi_w, zm831->vi_h = zm831_vi_h;
        zm831->ai_w = zm831_ai_w, zm831->ai_h = zm831_ai_h;
        zm831->ui_w = zm831_ui_w, zm831->ui_h = zm831_ui_h;

        zm831_vi_open();

        // zm831->vi_yuv = (uint8_t *)g2d_allocMem(zm831->vi_w * zm831->vi_h * 3 / 2);
        // if (NULL == zm831->vi_yuv)
        //     return;

        // zm831->ai_rgb = (uint8_t *)malloc(zm831->ai_w * zm831->ai_h * 3);
        // if (NULL == zm831->ai_rgb)
        //     return;

        zm831->vo = libmaix_vo_create(zm831->ui_w, zm831->ui_h, 0, 0, zm831->ui_w, zm831->ui_h);
        if (NULL == zm831->vo)
            return;

        // zm831->ui_rgba = libmaix_image_create(zm831->ui_w, zm831->ui_h, LIBMAIX_IMAGE_MODE_RGBA8888, LIBMAIX_IMAGE_LAYOUT_HWC, NULL, false);
        // if (NULL == zm831->ui_rgba)
        //     return;

        zm831->vi_th_ms = 30; // 30ms 33fps for vi & hw
    }

    void zm831_vi_exit()
    {
        zm831_vi_stop();

        // if (NULL != zm831->vi_yuv)
        //     g2d_freeMem(zm831->vi_yuv), zm831->vi_yuv = NULL;

        // if (NULL != zm831->ai_rgb)
        //     free(zm831->ai_rgb), zm831->ai_rgb = NULL;

        if (NULL != zm831->vo)
            libmaix_vo_destroy(&zm831->vo), zm831->vo = NULL;

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
        void *frame = zm831->vo->get_frame(zm831->vo, 0);
        if (frame != NULL)
        {
            uint32_t *phy = NULL, *vir = NULL;
            zm831->vo->frame_addr(zm831->vo, frame, &vir, &phy);
            if (zm831->vi && LIBMAIX_ERR_NONE == zm831->vi->capture(zm831->vi, (unsigned char *)vir[0]))
            {
                zm831->vo->set_frame(zm831->vo, frame, 0);
            }
        }
        cap_get("zm831->vi");

        // cap_set();
        // pthread_mutex_lock(&zm831->vi_mutex);
        // libmaix_image_t *ai_rgb = NULL;
        // if (LIBMAIX_ERR_NONE == zm831->ai->capture_image(zm831->ai, &ai_rgb))
        // {
        //     cv::Mat cv_src(ai_rgb->height, ai_rgb->width, CV_8UC3, ai_rgb->data);
        //     cv::rectangle(cv_src, cv::Point(24, 24), cv::Point(200, 200), cv::Scalar(255, 0, 0), 5);
        //     void *tmp = zm831->vo->get_frame(zm831->vo, 9);
        //     if (tmp != NULL)
        //     {
        //         uint32_t *phy = NULL, *vir = NULL;
        //         zm831->vo->frame_addr(zm831->vo, tmp, &vir, &phy);
        //         cv::Mat bgra(zm831->ui_h, zm831->ui_w, CV_8UC4, (unsigned char *)vir[0]);
        //         cv::rectangle(bgra, cv::Point(20, 20), cv::Point(220, 220), cv::Scalar(0, 0, 255, 128), 20);
        //         // cv::Mat cv_dst;
        //         // cv::resize(cv_src, cv_dst, cv::Size(zm831->ui_w, zm831->ui_h));
        //         // cv::cvtColor(cv_dst, bgra, cv::COLOR_RGB2BGRA);
        //         zm831->vo->set_frame(zm831->vo, tmp, 9);
        //     }
        // }
        // pthread_mutex_unlock(&zm831->vi_mutex);
        // cap_get("zm831->ai");
    }

    void zm831_write_string_to_file(std::string path, std::string txt)
    {
        // FILE *fp = NULL;
        // fp = fopen(path.c_str(), "w+");
        // if (fp) {
        //     fprintf(fp, "%s", txt.c_str());
        //     fclose(fp);
        // }
        // printf("fp %p\r\n", fp);
        std::ofstream outfile(path);
        outfile << txt;
        outfile.flush();
        outfile.close();
    }

    std::string zm831_read_file_to_string(const std::string &path)
    {
        std::ifstream file(path);
        if (!file.is_open())
        {
            return "";
        }
        std::stringstream ss;
        ss << file.rdbuf();
        return ss.str();
    }

    void zm831_save_json_conf(const std::string &path, json5pp::value &cfg)
    {
        auto tmp = cfg.stringify();
        LIBMAIX_INFO_PRINTF("save_json_conf %s\n", tmp.c_str());
        zm831_write_string_to_file(path, tmp);
        system("sync");
    }

    void zm831_load_json_conf(const std::string &path, json5pp::value &cfg, json5pp::value old)
    {
        std::string conf = zm831_read_file_to_string(path);
        try
        {
            cfg = json5pp::parse(conf);
            // {
            //     cfg["last_select"] = cfg["last_select"] + 1;
            //     cfg["language"] = "zh-kz";
            //     std::cout << cfg["last_select"] << std::endl;
            //     std::cout << cfg["language"] << std::endl;
            // }
        }
        catch (json5pp::syntax_error e)
        {
            LIBMAIX_INFO_PRINTF("load_json_conf %s : %s", conf.c_str(), e.what());
            system(string_format("rm -rf %s && sync", path.c_str()).c_str());
            cfg = old;
            zm831_save_json_conf(path, cfg);
        }
        LIBMAIX_INFO_PRINTF("load_json_conf %s\n", conf.c_str());
    }

    #include <linux/input.h>
    #include "linux/watchdog.h"

    /**
     * @brief 看门狗初始化
     * @details
     * 目前看门狗超时时间只能设置为1、2、3、4、5、6、8、10、12、14、16秒
     * @param [in] feed_time          喂狗时间，单位s
     * @retval
    */
    static void _watchdog_init(int feed_time)
    {
        int res;
        int fd = -1;

        fd = open("/dev/watchdog", O_RDWR);
        if (fd < 0)
        {
            fprintf(stderr, "open %s error:%s\n", "/dev/watchdog", strerror(errno));
            return;
        }

        res = ioctl(fd, WDIOC_SETTIMEOUT, &feed_time);
        if (res < 0)
        {
            fprintf(stderr, "watchdog set timeout error\n");
            close(fd);
            return;
        }

        res = ioctl(fd, WDIOC_SETOPTIONS, WDIOS_ENABLECARD);
        if (res < 0)
        {
            fprintf(stderr, "watchdog enable error\n");
            close(fd);
            return;
        }

        res = close(fd);
        if (res < 0)
        {
            fprintf(stderr, "close %s error:%s\n", "/dev/watchdog", strerror(errno));
            return;
        }
    }

    static void _watchdog_feed(void)
    {
        int res;
        int fd = -1;

        fd = open("/dev/watchdog", O_RDWR);
        if (fd < 0)
        {
            fprintf(stderr, "open %s error:%s\n", "/dev/watchdog", strerror(errno));
            return;
        }

        res = ioctl(fd, WDIOC_KEEPALIVE, 0);
        if (res < 0)
        {
            fprintf(stderr, "watchdog feed error\n");
            close(fd);
            return;
        }

        res = close(fd);
        if (res < 0)
        {
            fprintf(stderr, "close %s error:%s\n", "/dev/watchdog", strerror(errno));
            return;
        }
    }

    void maix_zm831_main(int argc, char *argv[])
    {
        zm831_load_json_conf(zm831->config_file, zm831->config_json, json5pp::object({
                                                                         {"last_select", 0},
                                                                         {"language", "zh-cn"},
                                                                     }));

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
        // zm831_ai_load(zm831_ai);
        zm831_ctrl_load();
        zm831_home_load();

        while (zm831->exit == 0)
        {
            // CALC_FPS("vi");
            msleep(zm831->vi_th_ms); // 30ms 33fps for vi & hw
            zm831_vi_loop();
            zm831_ctrl_loop();
            zm831_home_loop();
            // zm831_ui_loop();
            // zm831_ai_loop(zm831_ai);
        }

        // extern int imlib_find_blobs_app_load(zm831_home_app *app);
        // extern int imlib_find_blobs_app_loop(zm831_home_app *app);
        // extern int imlib_find_blobs_app_exit(zm831_home_app *app);
        // extern zm831_home_app get_imlib_find_blobs_app();
        // zm831_home_app tmp = get_imlib_find_blobs_app();
        // imlib_find_blobs_app_load(&tmp);
        // while (zm831->exit == 0)
        // {
        //     msleep(zm831->vi_th_ms);
        //     zm831_vi_loop();
        //     zm831_ctrl_loop();
        //     // zm831_home_loop();
        //     imlib_find_blobs_app_loop(&tmp);
        // }
        // imlib_find_blobs_app_exit(&tmp);

        zm831_home_exit();
        zm831_ctrl_exit();
        // zm831_ai_exit(zm831_ai);
        zm831_ui_exit();
        zm831_vi_exit();
        zm831->exit = 1;
        zm831_save_json_conf(zm831->config_file, zm831->config_json);
    }
}
