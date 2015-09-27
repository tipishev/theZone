#pragma once

#include "pebble.h"
#include "config.h"
#include "math.h"

void load_world();

/* Copy a piece of the global map to the `destination`.
 * Tile at `position` is used as the upper-left corner
 * of the piece if it is far enough from the edges;
 * otherwise the piece is within the global map as close
 * as possible to the `position` and even containing that
 * tile if it is witnin the world boundaries.
 * */
void give_world_piece(GPoint position, char destination[VIEWPORT_HEIGHT][VIEWPORT_WIDTH]);
