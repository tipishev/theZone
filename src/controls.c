#include "controls.h"
#include "vibe.h"
#include "graphics.h" // leaky abstraction for demo purposes x 2
#include "model.h" // leaky abstraction for demo purposes x 2

static  GPoint position;
char world_piece[VIEWPORT_HEIGHT][VIEWPORT_WIDTH] = { // FIXME declare as static?
    {'.', '.', '.', '.', '.'},
    {'.', '.', '.', '.', '.'},
    {'.', '.', '.', '.', '.'},
    {'.', '.', '.', '.', '.'},
    {'.', '.', '.', '.', '.'},
    {'.', '.', '.', '.', '.'}
  };

static void increment_click_handler(ClickRecognizerRef recognizer, void *context) {
  if (position.y > 0) {
    --position.y;
    give_world_piece(position, world_piece);
    fill_viewport(world_piece);
  }
}

static void decrement_click_handler(ClickRecognizerRef recognizer, void *context) {
  if (position.y < WORLD_HEIGHT - 1) {
    ++position.y;
    give_world_piece(position, world_piece);
    fill_viewport(world_piece);
  }
}

static void run_click_handler(ClickRecognizerRef recognizer, void *context) {
  if (position.x < WORLD_WIDTH - 1) {
    ++position.x;
    give_world_piece(position, world_piece);
    fill_viewport(world_piece);
  }
  else position.x = 0;
}

static void switch_mode_click_handler(ClickRecognizerRef recognizer, void *context) {
    /*vibe_explosion();*/
    switch_action_bar();
}

void click_config_provider(void *context) {
  window_single_repeating_click_subscribe(BUTTON_ID_UP, REPEAT_INTERVAL_MS, increment_click_handler);
  window_single_repeating_click_subscribe(BUTTON_ID_DOWN, REPEAT_INTERVAL_MS, decrement_click_handler);
  window_single_repeating_click_subscribe(BUTTON_ID_SELECT, REPEAT_INTERVAL_MS, run_click_handler);

  window_single_click_subscribe(BUTTON_ID_BACK, switch_mode_click_handler);
}
