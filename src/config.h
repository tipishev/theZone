#pragma once

// needs to be defined even with pebble.h included
void window_set_fullscreen(Window * window, bool enabled);

// Model stuff
#define MAP_WIDTH 16
#define MAP_HEIGHT 16

// View stuff
#define TILE_SIZE 24
#define VIEWPORT_WIDTH 5
#define VIEWPORT_HEIGHT 6
#define STATUS_TEXT_POSITION GRect(1, 153, 118, 166)

// Control stuff
#define REPEAT_INTERVAL_MS 50
