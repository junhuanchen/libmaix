
#include "zm831_uvai.hpp"

extern "C"
{
  extern zm831_uv *zm831;

  // ==============================================================================================

  static struct _function_template_
  {
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
      zm831->sensor_time = zm831_get_ms();
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
