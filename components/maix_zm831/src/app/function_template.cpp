
#include "zm831_uvai.hpp"

extern "C"
{
  extern zm831_uv *zm831;

  // ==============================================================================================

  static struct _function_template_
  {
    lv_draw_label_dsc_t label_dsc_zh, label_dsc_en;
    lv_draw_rect_dsc_t rect_dsc;

    bool init = false;

  } function_template_app;

  int function_template_app_load(zm831_home_app *app);
  int function_template_app_loop(zm831_home_app *app);
  int function_template_app_exit(zm831_home_app *app);

  zm831_home_app get_function_template_app()
  {
    return {function_template_app_load, function_template_app_loop, function_template_app_exit, &function_template_app};
  }

  // ==============================================================================================

  int function_template_app_load(zm831_home_app *app)
  {
    auto self = (_function_template_ *)app->userdata;

    lv_draw_label_dsc_init(&self->label_dsc_zh);
    self->label_dsc_zh.color = LV_COLOR_GREEN;
    self->label_dsc_zh.font = zm831->ft_font.font;

    lv_draw_label_dsc_init(&self->label_dsc_en);
    self->label_dsc_en.color = LV_COLOR_WHITE;

    lv_draw_rect_dsc_init(&self->rect_dsc);
    self->rect_dsc.radius = 5;
    self->rect_dsc.bg_color = {0x00, 0x00, 0x00, 0xDF};;
    self->rect_dsc.bg_opa = LV_OPA_80;
    self->rect_dsc.border_width = 5;
    self->rect_dsc.border_opa = LV_OPA_80;
    self->rect_dsc.border_color = {0x00, 0x00, 0x00, 0x7f};

    if (!self->init)
    {
      self->init = true;
    }
    LIBMAIX_INFO_PRINTF("function_template_app_load");
    return 0;
  }

  int function_template_app_loop(zm831_home_app *app)
  {
    auto self = (_function_template_ *)app->userdata;
    libmaix_err_t err = LIBMAIX_ERR_NONE;
    libmaix_image_t *ai_rgb = NULL;
    if (zm831->ai && LIBMAIX_ERR_NONE == zm831->ai->capture_image(zm831->ai, &ai_rgb))
    {
      CALC_FPS("function_template_app_loop");
    }
    return 0;
  }

  int function_template_app_exit(zm831_home_app *app)
  {
    auto self = (_function_template_ *)app->userdata;
    if (self->init)
    {
      self->init = false;
    }
    LIBMAIX_INFO_PRINTF("function_template_app_exit");
    return 0;
  }
}
