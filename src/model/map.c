#include "map.h"

char map[MAP_WIDTH][MAP_HEIGHT] = {
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


void load_map() {
  // TODO read *a* map aka level from raw resources
}

void give_map_piece(GPoint position, char destination[VIEWPORT_HEIGHT][VIEWPORT_WIDTH]) {
  GPoint upper_left;
  upper_left.x = min(max(position.x, 0), MAP_WIDTH - VIEWPORT_WIDTH);
  upper_left.y = min(max(position.y, 0), MAP_HEIGHT - VIEWPORT_HEIGHT);
  for (int i=0; i<VIEWPORT_HEIGHT; ++i) {
    for (int j=0; j<VIEWPORT_WIDTH; ++j) {
      destination[i][j] = map[upper_left.y + i][upper_left.x + j];
    }
  }
}

char get_map_at(GPoint position) {
    return map[position.y][position.x];
}

void set_map_at(GPoint position, char tile) {
    map[position.y][position.x] = tile;
}

/*void get_neighbors(GPoint tile, char destination[8]) {*/
/*  [>destination[E] = (tile.x < MAP_EAST_EDGE) ? map[tile.y][tile.x + 1] : '~'; <]*/
/*  [>destination[N] = (tile.y > MAP_NORTH_EDGE) ? map[tile.y - 1][tile.x] : '~'; <]*/
/*  [>destination[W] = (tile.x > MAP_WEST_EDGE) ? map[tile.y][tile.x - 1] : '~'; <]*/
/*  [>destination[S] = (tile.y < MAP_SOUTH_EDGE) ? map[tile.y + 1][tile.x] : '~'; <]*/

/*  [>destination[NE] = ((tile.x < MAP_EAST_EDGE) && (tile.y < map_NORTH_EDGE)) ? map[tile.y-1][tile.x + 1] : '~'; <]*/
/*  [>destination[NW] = ((tile.x > MAP_WEST_EDGE) && (tile.y < map_NORTH_EDGE)) ? map[tile.y-1][tile.x - 1] : '~'; <]*/
/*  [>destination[SW] = ((tile.x > MAP_WEST_EDGE) && (tile.y < map_NORTH_EDGE)) ? map[tile.y-1][tile.x - 1] : '~'; <]*/
/*  [>destination[NE] = ((tile.x < MAP_EAST_EDGE) && (tile.y < map_NORTH_EDGE)) ? map[tile.y-1][tile.x + 1] : '~'; <]*/
/*}*/

/*char get_available_directions() {*/
/*  return '0';*/
/*}*/

