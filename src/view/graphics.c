#include "graphics.h"

static BitmapLayer *s_board_layer;

static BitmapLayer *viewport[VIEWPORT_WIDTH][VIEWPORT_HEIGHT];

static ActionBarLayer *s_action_bar;
enum  action_bar_mode {MOVE, ATTACK};  // FIXME
enum action_bar_mode mode = ATTACK;  // FIXME

static TextLayer *s_status_text_layer;

// helpers
static GRect get_frame(GPoint tile){
    GRect frame;
    frame.origin.x = tile.x * TILE_SIZE;
    frame.origin.y = tile.y * TILE_SIZE;
    frame.size.w = frame.size.h = TILE_SIZE;
    return frame;
}


static void create_viewport(Window *window){
  Layer* window_layer = window_get_root_layer(window);
  for (int i=0; i<VIEWPORT_WIDTH; ++i) {
    for (int j=0; j<VIEWPORT_HEIGHT; ++j) {
      GPoint tile = GPoint(i, j);
      viewport[i][j] = bitmap_layer_create(get_frame(tile));
      layer_add_child(window_layer, bitmap_layer_get_layer(viewport[i][j]));
    }
  }
}

void fill_viewport(char map_piece[VIEWPORT_HEIGHT][VIEWPORT_WIDTH]) {
  static GBitmap *cursor;
  for (int i=0; i<VIEWPORT_HEIGHT; ++i) {
    for (int j=0; j<VIEWPORT_WIDTH; ++j) {
      char tile_char = map_piece[i][j];
      switch (tile_char) {
        case '.':
          cursor = s_tile_blank;
          break;
        case '@':
          cursor = s_tile_character;
          break;
        case 'Z':
          cursor = s_tile_zombie;
          break;
        case '#':
          cursor = s_tile_wall;
          break;
      }
          bitmap_layer_set_bitmap(viewport[j][i], cursor);
    }
  }
}

static void destroy_viewport(){
  for (int i=0; i<VIEWPORT_WIDTH; ++i) {
    for (int j=0; j<VIEWPORT_HEIGHT; ++j) {
      bitmap_layer_destroy(viewport[i][j]);
    }
  }
}

static void create_backdrop(Window *window){
  Layer* window_layer = window_get_root_layer(window);
  GRect frame = layer_get_frame(window_layer);

  s_board_layer = bitmap_layer_create(frame);
  bitmap_layer_set_bitmap(s_board_layer, s_background_board);
  layer_add_child(window_layer, bitmap_layer_get_layer(s_board_layer));
}

static void destroy_backdrop(){
  bitmap_layer_destroy(s_board_layer);
}

static void create_action_bar(Window *window) {
  s_action_bar = action_bar_layer_create();
  action_bar_layer_add_to_window(s_action_bar, window);
}

void switch_action_bar() {
  if (mode == MOVE) {
  mode = ATTACK;
  action_bar_layer_set_icon(s_action_bar, BUTTON_ID_UP, s_icon_previous_target);
  action_bar_layer_set_icon(s_action_bar, BUTTON_ID_DOWN, s_icon_next_target);
  action_bar_layer_set_icon(s_action_bar, BUTTON_ID_SELECT, s_icon_crosshair);
  }
  else {
  mode = MOVE;
  action_bar_layer_set_icon(s_action_bar, BUTTON_ID_UP, s_icon_counterclockwise);
  action_bar_layer_set_icon(s_action_bar, BUTTON_ID_DOWN, s_icon_clockwise);
  action_bar_layer_set_icon(s_action_bar, BUTTON_ID_SELECT, s_icon_runner);
  }
}

ActionBarLayer* get_action_bar() {
    return s_action_bar;
}

static void destroy_action_bar() {
  action_bar_layer_destroy(s_action_bar);
}

static void create_status_text(Window *window) {
  s_status_text_layer = text_layer_create(STATUS_TEXT_POSITION);
  text_layer_set_background_color(s_status_text_layer, GColorClear);
  text_layer_set_text_color(s_status_text_layer, GColorBlack);
  text_layer_set_font(s_status_text_layer, fonts_get_system_font(FONT_KEY_GOTHIC_14_BOLD));
  layer_add_child(window_get_root_layer(window), text_layer_get_layer(s_status_text_layer));
}

void set_status_text(char *text) {
  text_layer_set_text(s_status_text_layer, text);
}

static void destroy_status_text() {
  text_layer_destroy(s_status_text_layer);
}

void init_graphics(Window* window){
    create_bitmaps();
    create_backdrop(window);
    create_viewport(window);
    create_action_bar(window);
    create_status_text(window);
    set_status_text("abcdefghijklmnopq");
    switch_action_bar();
}

void deinit_graphics(){
    destroy_bitmaps();
    destroy_backdrop();
    destroy_viewport();
    destroy_action_bar();
    destroy_status_text();
}
