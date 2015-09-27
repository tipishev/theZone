#pragma once

#include <pebble.h>
#include "config.h"
#include "view/graphics.h"
#include "view/vibe.h"
#include "utils/math.h"

typedef enum { E = 0, NE = 1, N = 2, NW = 3,
               W = 4, SW = 5, S = 6, SE = 7
} Direction;

typedef struct {
  int health;
  int ammo;
  GPoint position;
  Direction direction;
} Player;

/* map */
void load_world();

/* Copy a piece of the global map to the `destination`.
 * Tile at `position` is used as the upper-left corner
 * of the piece if it is far enough from the edges;
 * otherwise the piece is within the global map as close
 * as possible to the `position` and even containing that
 * tile if it is witnin the world boundaries.
 * */
void give_world_piece(GPoint position, char destination[VIEWPORT_HEIGHT][VIEWPORT_WIDTH]);

/* player */
void init_player();
GPoint get_player_position();
void set_player_position(GPoint new_position);
void deinit_player();
