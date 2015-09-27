#include "controls.h"

static GPoint position;
static char world_piece[VIEWPORT_HEIGHT][VIEWPORT_WIDTH];

static void up_click_handler(ClickRecognizerRef recognizer, void *context) {
  --position.y;
  give_world_piece(position, world_piece);
  fill_viewport(world_piece);
}

static void down_click_handler(ClickRecognizerRef recognizer, void *context) {
  ++position.y;
  give_world_piece(position, world_piece);
  fill_viewport(world_piece);
}

static void right_click_handler(ClickRecognizerRef recognizer, void *context) {
  ++position.x;
  give_world_piece(position, world_piece);
  fill_viewport(world_piece);
}

static void left_click_handler(ClickRecognizerRef recognizer, void *context) {
  --position.x;
  give_world_piece(position, world_piece);
  fill_viewport(world_piece);
}

void click_config_provider(void *context) {
  window_single_repeating_click_subscribe(BUTTON_ID_UP, REPEAT_INTERVAL_MS, up_click_handler);
  window_single_repeating_click_subscribe(BUTTON_ID_DOWN, REPEAT_INTERVAL_MS, down_click_handler);
  window_single_repeating_click_subscribe(BUTTON_ID_SELECT, REPEAT_INTERVAL_MS, right_click_handler);
  window_single_click_subscribe(BUTTON_ID_BACK, left_click_handler);
}
