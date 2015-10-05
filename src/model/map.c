#include "map.h"

char world[WORLD_WIDTH][WORLD_HEIGHT] = {
//  0   1   2   3   4   5   6   7   8   9   A   B   C   D   E   F
  {'.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','Z'}, // 0
  {'.','Z','#','#','#','#','#','#','#','.','.','.','.','#','#','#'}, // 1
  {'.','.','#','.','#','Z','.','.','#','.','.','.','.','#','.','#'}, // 2
  {'.','.','#','.','#','.','#','.','#','.','.','.','.','#','.','#'}, // 3
  {'.','.','#','.','.','.','#','.','#','.','.','.','.','#','.','#'}, // 4
  {'.','.','#','.','#','.','#','.','.','.','.','.','.','#','.','#'}, // 5
  {'.','.','#','Z','#','.','.','.','#','.','.','.','.','.','.','.'}, // 6
  {'.','.','#','#','#','#','#','#','#','.','#','#','.','.','.','.'}, // 7
  {'.','.','.','#','.','.','.','.','.','.','.','#','#','.','.','.'}, // 8
  {'.','.','.','.','.','.','.','.','.','.','.','#','.','.','.','.'}, // 9
  {'.','.','.','#','.','.','.','.','.','.','.','#','.','.','.','.'}, // A
  {'.','.','.','#','#','#','#','.','.','#','.','.','.','.','.','.'}, // B
  {'.','.','.','#','.','.','#','.','.','#','.','.','#','Z','.','.'}, // C
  {'.','.','.','#','.','.','#','#','.','#','.','.','#','.','.','.'}, // D
  {'.','.','.','#','.','.','.','.','.','#','.','.','#','.','Z','.'}, // E
  {'Z','.','.','#','#','#','#','#','#','#','.','.','#','.','.','.'}  // F
};


void load_world() {
  // TODO read *a* world aka level from raw resources
}

void give_world_piece(GPoint position, char destination[VIEWPORT_HEIGHT][VIEWPORT_WIDTH]) {
  GPoint upper_left;
  upper_left.x = min(max(position.x, 0), WORLD_WIDTH - VIEWPORT_WIDTH);
  upper_left.y = min(max(position.y, 0), WORLD_HEIGHT - VIEWPORT_HEIGHT);
  for (int i=0; i<VIEWPORT_HEIGHT; ++i) {
    for (int j=0; j<VIEWPORT_WIDTH; ++j) {
      destination[i][j] = world[upper_left.y + i][upper_left.x + j];
    }
  }
}

char get_world_at(GPoint position) {
    return world[position.y][position.x];
}

void set_world_at(GPoint position, char tile) {
    world[position.y][position.x] = tile;
}

/*void get_neighbors(GPoint tile, char destination[8]) {*/
/*  [>destination[E] = (tile.x < WORLD_EAST_EDGE) ? world[tile.y][tile.x + 1] : '~'; <]*/
/*  [>destination[N] = (tile.y > WORLD_NORTH_EDGE) ? world[tile.y - 1][tile.x] : '~'; <]*/
/*  [>destination[W] = (tile.x > WORLD_WEST_EDGE) ? world[tile.y][tile.x - 1] : '~'; <]*/
/*  [>destination[S] = (tile.y < WORLD_SOUTH_EDGE) ? world[tile.y + 1][tile.x] : '~'; <]*/

/*  [>destination[NE] = ((tile.x < WORLD_EAST_EDGE) && (tile.y < WORLD_NORTH_EDGE)) ? world[tile.y-1][tile.x + 1] : '~'; <]*/
/*  [>destination[NW] = ((tile.x > WORLD_WEST_EDGE) && (tile.y < WORLD_NORTH_EDGE)) ? world[tile.y-1][tile.x - 1] : '~'; <]*/
/*  [>destination[SW] = ((tile.x > WORLD_WEST_EDGE) && (tile.y < WORLD_NORTH_EDGE)) ? world[tile.y-1][tile.x - 1] : '~'; <]*/
/*  [>destination[NE] = ((tile.x < WORLD_EAST_EDGE) && (tile.y < WORLD_NORTH_EDGE)) ? world[tile.y-1][tile.x + 1] : '~'; <]*/
/*}*/

/*char get_available_directions() {*/
/*  return '0';*/
/*}*/

