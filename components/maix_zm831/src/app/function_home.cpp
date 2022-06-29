
#include "zm831_uvai.hpp"

extern "C"
{
  extern zm831_uv *zm831;

  // ==============================================================================================
  /*
    主界面，切功能，

  */
  static struct _function_home_
  {

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

  int function_home_app_load(zm831_home_app *app)
  {
    auto self = (_function_home_ *)app->userdata;

    if (!self->init)
    {


      self->init = true;
    }
    LIBMAIX_INFO_PRINTF("function_home_app_load");
    return 0;
  }

  int function_home_app_loop(zm831_home_app *app)
  {
    auto self = (_function_home_ *)app->userdata;
    libmaix_err_t err = LIBMAIX_ERR_NONE;
    libmaix_image_t *ai_rgb = NULL;
    if (zm831->ai && LIBMAIX_ERR_NONE == zm831->ai->capture_image(zm831->ai, &ai_rgb))
    {

    }
    return 0;
  }

  int function_home_app_exit(zm831_home_app *app)
  {
    auto self = (_function_home_ *)app->userdata;
    if (self->init)
    {
      self->init = false;
    }
    LIBMAIX_INFO_PRINTF("function_home_app_exit");
    return 0;
  }
}
