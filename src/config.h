#pragma once

// needs to be defined even with pebble.h included
void window_set_fullscreen(Window * window, bool enabled);

// Model stuff

// View stuff
#define TILE_SIZE 24
#define VIEWPORT_WIDTH 5
#define VIEWPORT_HEIGHT 6

// Control stuff
#define REPEAT_INTERVAL_MS 50
