#include "pebble.h"

#define REPEAT_INTERVAL_MS 50
#define NUM_DRINKS_PKEY 1 //special key for saving
#define NUM_DRINKS_DEFAULT 0

#define TILE_SIZE 24

void window_set_fullscreen(Window * window, bool enabled);

static Window *s_main_window;

static GBitmap *s_background_board;
static BitmapLayer *s_board_layer;

static ActionBarLayer *s_action_bar;
static GBitmap *s_icon_plus, *s_icon_minus, *s_icon_runner;

static GBitmap *s_tile_character, *s_tile_zombie, *s_tile_wall;
static BitmapLayer *s_character_layer, *s_zombie_layer;

static int s_num_drinks = NUM_DRINKS_DEFAULT;

static void increment_click_handler(ClickRecognizerRef recognizer, void *context) {
  s_num_drinks++;
}

static void decrement_click_handler(ClickRecognizerRef recognizer, void *context) {
  if (s_num_drinks <= 0) {return;}
  s_num_drinks--;
}

static void shoot_click_handler(ClickRecognizerRef recognizer, void *context) {
}

static void click_config_provider(void *context) {
  window_single_repeating_click_subscribe(BUTTON_ID_UP, REPEAT_INTERVAL_MS, increment_click_handler);
  window_single_repeating_click_subscribe(BUTTON_ID_DOWN, REPEAT_INTERVAL_MS, decrement_click_handler);
  window_single_repeating_click_subscribe(BUTTON_ID_SELECT, REPEAT_INTERVAL_MS, shoot_click_handler);
}


static void create_bitmaps() {
  s_background_board = gbitmap_create_with_resource(RESOURCE_ID_IMAGE_BACKGROUND_BOARD);
  /*s_background_board = gbitmap_create_with_resource(RESOURCE_ID_IMAGE_TILE_WALL);*/
  s_tile_wall = gbitmap_create_with_resource(RESOURCE_ID_IMAGE_TILE_WALL);
  s_tile_character = gbitmap_create_with_resource(RESOURCE_ID_IMAGE_TILE_CHARACTER);
  s_tile_zombie = gbitmap_create_with_resource(RESOURCE_ID_IMAGE_TILE_ZOMBIE);

  s_icon_plus = gbitmap_create_with_resource(RESOURCE_ID_IMAGE_ACTION_ICON_PLUS);
  s_icon_minus = gbitmap_create_with_resource(RESOURCE_ID_IMAGE_ACTION_ICON_MINUS);
  s_icon_runner = gbitmap_create_with_resource(RESOURCE_ID_IMAGE_ACTION_ICON_RUNNER);
}

static void destroy_bitmaps() {
  gbitmap_destroy(s_background_board);
  gbitmap_destroy(s_tile_wall);
  gbitmap_destroy(s_tile_character);
  gbitmap_destroy(s_tile_zombie);

  gbitmap_destroy(s_icon_plus);
  gbitmap_destroy(s_icon_minus);
  gbitmap_destroy(s_icon_runner);
}

static void create_action_bar(Window *window) {
  s_action_bar = action_bar_layer_create();
  action_bar_layer_add_to_window(s_action_bar, window);
  action_bar_layer_set_click_config_provider(s_action_bar, click_config_provider);
  action_bar_layer_set_icon(s_action_bar, BUTTON_ID_UP, s_icon_plus);
  action_bar_layer_set_icon(s_action_bar, BUTTON_ID_DOWN, s_icon_minus);
  action_bar_layer_set_icon(s_action_bar, BUTTON_ID_SELECT, s_icon_runner);
}


static void main_window_load(Window *window) {
  create_bitmaps();
  create_action_bar(window);

  Layer *window_layer = window_get_root_layer(window);

  GRect layer_frame_description = layer_get_frame(window_layer);
  layer_frame_description.origin.x = -10; // to account for action bar

  s_board_layer = bitmap_layer_create(layer_frame_description);
  bitmap_layer_set_bitmap(s_board_layer, s_background_board);
  layer_add_child(window_layer, bitmap_layer_get_layer(s_board_layer));


  layer_frame_description.origin.x -= 2*TILE_SIZE;
  layer_frame_description.origin.y -= 2*TILE_SIZE;
  s_character_layer = bitmap_layer_create(layer_frame_description);
  bitmap_layer_set_bitmap(s_character_layer, s_tile_character);
  layer_add_child(window_layer, bitmap_layer_get_layer(s_character_layer));


  layer_frame_description.origin.x += 2*TILE_SIZE;
  layer_frame_description.origin.y += 1*TILE_SIZE;
  s_zombie_layer = bitmap_layer_create(layer_frame_description);
  bitmap_layer_set_bitmap(s_zombie_layer, s_tile_zombie);
  layer_add_child(window_layer, bitmap_layer_get_layer(s_zombie_layer));

  layer_frame_description.origin.x += TILE_SIZE;
  layer_frame_description.origin.y += 2*TILE_SIZE;
  s_zombie_layer = bitmap_layer_create(layer_frame_description);
  bitmap_layer_set_bitmap(s_zombie_layer, s_tile_zombie);
  layer_add_child(window_layer, bitmap_layer_get_layer(s_zombie_layer));

}

static void main_window_unload(Window *window) {
  bitmap_layer_destroy(s_character_layer);
  bitmap_layer_destroy(s_zombie_layer);
  action_bar_layer_destroy(s_action_bar);
  destroy_bitmaps();
}

static void init(void) {
  s_num_drinks = persist_exists(NUM_DRINKS_PKEY) ? persist_read_int(NUM_DRINKS_PKEY) : NUM_DRINKS_DEFAULT;

  s_main_window = window_create();
  window_set_fullscreen(s_main_window, true);


  window_set_window_handlers(s_main_window, (WindowHandlers) {
    .load = main_window_load,
    .unload = main_window_unload
  });
  window_stack_push(s_main_window, true);
}

static void deinit(void) {
  persist_write_int(NUM_DRINKS_PKEY, s_num_drinks);
  window_destroy(s_main_window);
}

int main(void) {
  init();
  app_event_loop();
  deinit();
}
