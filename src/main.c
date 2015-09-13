#include "pebble.h"

#include "controls.h"
#include "graphics.h"

static Window *s_main_window;

static void main_window_load(Window *window) {
  init_graphics(window);
  action_bar_layer_set_click_config_provider(get_action_bar(), click_config_provider);
}

static void main_window_unload(Window *window) {
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
}

static void deinit(void) {
  window_destroy(s_main_window);
}

int main(void) {
  init();
  app_event_loop();
  deinit();
}
