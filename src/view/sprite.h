#pragma once
#include <pebble.h>

extern GBitmap *s_background_board;
extern GBitmap *s_tile_blank, *s_tile_character, *s_tile_zombie, *s_tile_wall;
extern GBitmap *s_icon_counterclockwise, *s_icon_clockwise, *s_icon_runner;
extern GBitmap *s_icon_previous_target, *s_icon_next_target, *s_icon_crosshair;

extern void create_bitmaps();
extern void destroy_bitmaps();
