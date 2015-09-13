#include "graphics.h"

static GBitmap *s_background_board;
static BitmapLayer *s_board_layer;

static GBitmap *s_tile_character, *s_tile_zombie, *s_tile_wall;
static BitmapLayer *s_character_layer, *s_zombie_layer, *s_wall_layer;

static ActionBarLayer *s_action_bar;
static GBitmap *s_icon_counterclockwise, *s_icon_clockwise, *s_icon_runner;


// helpers
static GRect tile_to_global(const int tile_x, const int tile_y){  // TODO better name
    GRect cursor;
    cursor.origin.x = tile_x * TILE_SIZE;
    cursor.origin.y = tile_y * TILE_SIZE;
    cursor.size.w = cursor.size.h = TILE_SIZE;
    return cursor;
}


// TODO this should go to controls
#define REPEAT_INTERVAL_MS 50


// VIBE PATTERNS vibe-pause-vibe-...
static const uint32_t const FOOTSTEPS[] = {50, 100, 50, 100, 50 };
static const uint32_t const DAMAGE[] = {200};

static void vibe(const uint32_t const *pattern) {
     VibePattern pat = {
       .durations = pattern,
         /*.num_segments = ARRAY_LENGTH(pattern),*/  // TODO determine pattern length
         .num_segments = 5,
         };
         vibes_enqueue_custom_pattern(pat);
}
static void increment_click_handler(ClickRecognizerRef recognizer, void *context) {
}

static void decrement_click_handler(ClickRecognizerRef recognizer, void *context) {
}

static void run_click_handler(ClickRecognizerRef recognizer, void *context) {
    vibe(FOOTSTEPS);
}

static void click_config_provider(void *context) {
  window_single_repeating_click_subscribe(BUTTON_ID_UP, REPEAT_INTERVAL_MS, increment_click_handler);
  window_single_repeating_click_subscribe(BUTTON_ID_DOWN, REPEAT_INTERVAL_MS, decrement_click_handler);
  window_single_repeating_click_subscribe(BUTTON_ID_SELECT, REPEAT_INTERVAL_MS, run_click_handler);
}


void create_bitmaps() {
  s_background_board = gbitmap_create_with_resource(RESOURCE_ID_IMAGE_BACKGROUND_BOARD);

  s_tile_wall = gbitmap_create_with_resource(RESOURCE_ID_IMAGE_TILE_WALL);
  s_tile_character = gbitmap_create_with_resource(RESOURCE_ID_IMAGE_TILE_CHARACTER);
  s_tile_zombie = gbitmap_create_with_resource(RESOURCE_ID_IMAGE_TILE_ZOMBIE);

  s_icon_counterclockwise = gbitmap_create_with_resource(RESOURCE_ID_IMAGE_ACTION_ICON_COUNTERCLOCKWISE);
  s_icon_clockwise = gbitmap_create_with_resource(RESOURCE_ID_IMAGE_ACTION_ICON_CLOCKWISE);
  s_icon_runner = gbitmap_create_with_resource(RESOURCE_ID_IMAGE_ACTION_ICON_RUNNER);
}

void destroy_bitmaps() {
  gbitmap_destroy(s_background_board);

  gbitmap_destroy(s_tile_wall);
  gbitmap_destroy(s_tile_character);
  gbitmap_destroy(s_tile_zombie);

  gbitmap_destroy(s_icon_counterclockwise);
  gbitmap_destroy(s_icon_clockwise);
  gbitmap_destroy(s_icon_runner);
}

void create_layers(Window *window){
  Layer* window_layer = window_get_root_layer(window);
  GRect cursor = layer_get_frame(window_layer);

  s_board_layer = bitmap_layer_create(cursor);
  bitmap_layer_set_bitmap(s_board_layer, s_background_board);
  layer_add_child(window_layer, bitmap_layer_get_layer(s_board_layer));


  s_character_layer = bitmap_layer_create(tile_to_global(1,3));
  layer_add_child(window_layer, bitmap_layer_get_layer(s_character_layer));
  bitmap_layer_set_bitmap(s_character_layer, s_tile_character);

  s_zombie_layer = bitmap_layer_create(tile_to_global(2,2));
  bitmap_layer_set_bitmap(s_zombie_layer, s_tile_zombie);
  layer_add_child(window_layer, bitmap_layer_get_layer(s_zombie_layer));

  s_zombie_layer = bitmap_layer_create(tile_to_global(2,4));  // leak
  bitmap_layer_set_bitmap(s_zombie_layer, s_tile_zombie);
  layer_add_child(window_layer, bitmap_layer_get_layer(s_zombie_layer));

  s_zombie_layer = bitmap_layer_create(tile_to_global(3,4));  // leak
  bitmap_layer_set_bitmap(s_zombie_layer, s_tile_zombie);
  layer_add_child(window_layer, bitmap_layer_get_layer(s_zombie_layer));

  s_wall_layer = bitmap_layer_create(tile_to_global(1,4));  // leak
  bitmap_layer_set_bitmap(s_wall_layer, s_tile_wall);
  layer_add_child(window_layer, bitmap_layer_get_layer(s_wall_layer));

  s_wall_layer = bitmap_layer_create(tile_to_global(0,4));  // leak
  bitmap_layer_set_bitmap(s_wall_layer, s_tile_wall);
  layer_add_child(window_layer, bitmap_layer_get_layer(s_wall_layer));

  s_wall_layer = bitmap_layer_create(tile_to_global(1,5));  // leak
  bitmap_layer_set_bitmap(s_wall_layer, s_tile_wall);
  layer_add_child(window_layer, bitmap_layer_get_layer(s_wall_layer));


}

void destroy_layers(){ // TODO better name
  bitmap_layer_destroy(s_character_layer);
  bitmap_layer_destroy(s_zombie_layer);
  bitmap_layer_destroy(s_wall_layer);
}


void create_action_bar(Window *window) {
  s_action_bar = action_bar_layer_create();
  action_bar_layer_add_to_window(s_action_bar, window);
  action_bar_layer_set_click_config_provider(s_action_bar, click_config_provider);
  action_bar_layer_set_icon(s_action_bar, BUTTON_ID_UP, s_icon_counterclockwise);
  action_bar_layer_set_icon(s_action_bar, BUTTON_ID_DOWN, s_icon_clockwise);
  action_bar_layer_set_icon(s_action_bar, BUTTON_ID_SELECT, s_icon_runner);
}

void destroy_action_bar() {
  action_bar_layer_destroy(s_action_bar);
}
