#include "controls.h"
#include "vibe.h"
#include "graphics.h" // leaky abstraction for demo purposes x 2

static void increment_click_handler(ClickRecognizerRef recognizer, void *context) {
  static char world_piece[VIEWPORT_HEIGHT][VIEWPORT_WIDTH] = {
    {'#','#','#','.','.'},
    {'#','.','#','.','.'},
    {'.','@','#','#','Z'},
    {'.','.','Z','#','.'},
    {'.','Z','.','.','.'},
    {'.','.','.','.','.'}
  };
  fill_viewport(world_piece);
}

static void decrement_click_handler(ClickRecognizerRef recognizer, void *context) {
  static char world_piece[VIEWPORT_HEIGHT][VIEWPORT_WIDTH] = {
    {'#','#','#','.','.'},
    {'#','@','#','.','Z'},
    {'.','.','#','#','.'},
    {'.','.','.','#','.'},
    {'.','.','.','Z','.'},
    {'Z','.','.','.','.'}
  };
  fill_viewport(world_piece);
}

static void run_click_handler(ClickRecognizerRef recognizer, void *context) {
    vibe_footsteps();
}

static void switch_mode_click_handler(ClickRecognizerRef recognizer, void *context) {
    switch_action_bar();
}

void click_config_provider(void *context) {
  window_single_repeating_click_subscribe(BUTTON_ID_UP, REPEAT_INTERVAL_MS, increment_click_handler);
  window_single_repeating_click_subscribe(BUTTON_ID_DOWN, REPEAT_INTERVAL_MS, decrement_click_handler);
  window_single_repeating_click_subscribe(BUTTON_ID_SELECT, REPEAT_INTERVAL_MS, run_click_handler);

  window_single_click_subscribe(BUTTON_ID_BACK, switch_mode_click_handler);
}
