#pragma once

#include "player.h"

#define MAP_EAST_EDGE map_WIDTH - 1
#define MAP_NORTH_EDGE 0
#define MAP_WEST_EDGE 0
#define MAP_SOUTH_EDGE map_HEIGHT - 1


void load_map();

/* Copy a piece of the global map to the `destination`.
 * Tile at `position` is used as the upper-left corner
 * of the piece if it is far enough from the edges;
 * otherwise the piece is within the global map as close
 * as possible to the `position` and even containing that
 * tile if it is witnin the map boundaries.
 * */
void give_map_piece(GPoint position, char destination[VIEWPORT_HEIGHT][VIEWPORT_WIDTH]);

char get_map_at(GPoint position); // TODO generalize with `give_map_piece`
void set_map_at(GPoint position, char tile);
