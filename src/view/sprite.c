#include "sprite.h"

GBitmap *s_background_board;
GBitmap *s_tile_blank, *s_tile_character, *s_tile_zombie, *s_tile_wall;
GBitmap *s_icon_counterclockwise, *s_icon_clockwise, *s_icon_runner;
GBitmap *s_icon_previous_target, *s_icon_next_target, *s_icon_crosshair;

void create_bitmaps() {
  s_background_board = gbitmap_create_with_resource(RESOURCE_ID_IMAGE_BACKGROUND_BOARD);

  s_tile_blank = gbitmap_create_with_resource(RESOURCE_ID_IMAGE_TILE_BLANK);
  s_tile_wall = gbitmap_create_with_resource(RESOURCE_ID_IMAGE_TILE_WALL);
  s_tile_character = gbitmap_create_with_resource(RESOURCE_ID_IMAGE_TILE_CHARACTER);
  s_tile_zombie = gbitmap_create_with_resource(RESOURCE_ID_IMAGE_TILE_ZOMBIE);

  s_icon_counterclockwise = gbitmap_create_with_resource(RESOURCE_ID_IMAGE_ACTION_ICON_COUNTERCLOCKWISE);
  s_icon_clockwise = gbitmap_create_with_resource(RESOURCE_ID_IMAGE_ACTION_ICON_CLOCKWISE);
  s_icon_runner = gbitmap_create_with_resource(RESOURCE_ID_IMAGE_ACTION_ICON_RUNNER);

  s_icon_next_target = gbitmap_create_with_resource(RESOURCE_ID_IMAGE_ACTION_ICON_NEXT_TARGET);
  s_icon_previous_target = gbitmap_create_with_resource(RESOURCE_ID_IMAGE_ACTION_ICON_PREVIOUS_TARGET);
  s_icon_crosshair = gbitmap_create_with_resource(RESOURCE_ID_IMAGE_ACTION_ICON_CROSSHAIR);
}

void destroy_bitmaps() {
  gbitmap_destroy(s_background_board);

  gbitmap_destroy(s_tile_blank);
  gbitmap_destroy(s_tile_wall);
  gbitmap_destroy(s_tile_character);
  gbitmap_destroy(s_tile_zombie);

  gbitmap_destroy(s_icon_counterclockwise);
  gbitmap_destroy(s_icon_clockwise);
  gbitmap_destroy(s_icon_runner);

  gbitmap_destroy(s_icon_previous_target);
  gbitmap_destroy(s_icon_next_target);
  gbitmap_destroy(s_icon_crosshair);
}
