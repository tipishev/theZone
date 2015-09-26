#pragma once

// needs to be defined even with pebble.h included
void window_set_fullscreen(Window * window, bool enabled);

// Model stuff
#define WORLD_WIDTH 16
#define WORLD_HEIGHT 16

// View stuff
#define TILE_SIZE 24
#define VIEWPORT_WIDTH 5
#define VIEWPORT_HEIGHT 6

// Control stuff
#define REPEAT_INTERVAL_MS 50


// some silly macros TODO move to a separated header file
#define max(a, b) \
({ __typeof__ (a) _a = (a); \
__typeof__ (b) _b = (b); \
_a > _b ? _a : _b; })

#define min(a, b) \
({ __typeof__ (a) _a = (a); \
__typeof__ (b) _b = (b); \
_a < _b ? _a : _b; })
