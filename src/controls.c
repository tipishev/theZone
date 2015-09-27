#include "controls.h"
#include "vibe.h"
#include "graphics.h" // leaky abstraction for demo purposes x 2
#include "model.h" // leaky abstraction for demo purposes x 2

static GPoint position;
static char world_piece[VIEWPORT_HEIGHT][VIEWPORT_WIDTH];

static void up_click_handler(ClickRecognizerRef recognizer, void *context) {
  if (position.y > 0) {
    --position.y;
    give_world_piece(position, world_piece);
    fill_viewport(world_piece);
  }
}

static void down_click_handler(ClickRecognizerRef recognizer, void *context) {
  if (position.y < WORLD_HEIGHT - VIEWPORT_HEIGHT) {
    ++position.y;
    give_world_piece(position, world_piece);
    fill_viewport(world_piece);
  }
}

static void right_click_handler(ClickRecognizerRef recognizer, void *context) {
  if (position.x < WORLD_WIDTH - VIEWPORT_WIDTH) {
    ++position.x;
    give_world_piece(position, world_piece);
    fill_viewport(world_piece);
  }
}

static void left_click_handler(ClickRecognizerRef recognizer, void *context) {
  if (position.x > 0) {
    --position.x;
    give_world_piece(position, world_piece);
    fill_viewport(world_piece);
  }
}

void click_config_provider(void *context) {
  window_single_repeating_click_subscribe(BUTTON_ID_UP, REPEAT_INTERVAL_MS, up_click_handler);
  window_single_repeating_click_subscribe(BUTTON_ID_DOWN, REPEAT_INTERVAL_MS, down_click_handler);
  window_single_repeating_click_subscribe(BUTTON_ID_SELECT, REPEAT_INTERVAL_MS, right_click_handler);
  window_single_click_subscribe(BUTTON_ID_BACK, left_click_handler);
}
