#pragma once

#include "player.h"

#define WORLD_EAST_EDGE WORLD_WIDTH - 1
#define WORLD_NORTH_EDGE 0
#define WORLD_WEST_EDGE 0
#define WORLD_SOUTH_EDGE WORLD_HEIGHT - 1


void load_world();

/* Copy a piece of the global map to the `destination`.
 * Tile at `position` is used as the upper-left corner
 * of the piece if it is far enough from the edges;
 * otherwise the piece is within the global map as close
 * as possible to the `position` and even containing that
 * tile if it is witnin the world boundaries.
 * */
void give_world_piece(GPoint position, char destination[VIEWPORT_HEIGHT][VIEWPORT_WIDTH]);

char get_world_at(GPoint position); // TODO generalize with `give_world_piece`
void set_world_at(GPoint position, char tile);
