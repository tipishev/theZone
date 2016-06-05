#include "pebble.h"
#include "pge/pge.h"

#include "control/controls.h"
#include "view/graphics.h"
#include "model/player.h"

static Window *s_main_window;

void backlight_toggle(AccelAxisType _axis, int32_t _direction) {
  static bool _backlight = false;
  _backlight = !_backlight;
  light_enable(_backlight);
  vibes_long_pulse();
}


static void main_window_load(Window *window) {
  load_map();
  init_player();
  init_graphics(window);
  action_bar_layer_set_click_config_provider(get_action_bar(), click_config_provider);
}

static void main_window_unload(Window *window) {
  deinit_player();
  deinit_graphics();
}

static void init(void) {
  s_main_window = window_create();
  window_set_fullscreen(s_main_window, true);

  window_set_window_handlers(s_main_window, (WindowHandlers) {
    .load = main_window_load,
    .unload = main_window_unload
  });
  window_stack_push(s_main_window, true);
  accel_tap_service_subscribe(backlight_toggle);
}

static void deinit(void) {
  window_destroy(s_main_window);
  accel_tap_service_unsubscribe();
}

int main(void) {
  init();
  app_event_loop();
  deinit();
}
