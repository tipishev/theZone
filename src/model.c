#include "model.h"

static char world[WORLD_WIDTH][WORLD_HEIGHT] = {
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

GPoint player_position;
int zombies_count = 7;

void load_world() {
  // TODO read *a* world aka level from raw resources
  player_position.x = 0;
  player_position.y = 0;
}

void give_world_piece(GPoint position, char destination[VIEWPORT_HEIGHT][VIEWPORT_WIDTH]){
  GPoint upper_left;
  upper_left.x = min(max(position.x, 0), WORLD_WIDTH - VIEWPORT_WIDTH);
  upper_left.y = min(max(position.y, 0), WORLD_HEIGHT - VIEWPORT_HEIGHT);
  for (int i=0; i<VIEWPORT_HEIGHT; ++i) {
    for (int j=0; j<VIEWPORT_WIDTH; ++j) {
      destination[i][j] = world[upper_left.y + i][upper_left.x + j];
    }
  }
}

GPoint get_player_position() {
  return player_position;
}

void set_player_position(GPoint new_position) {
  char to_crush = world[new_position.y][new_position.x];
  if (to_crush != '#') {
    new_position.x = min(max(new_position.x, 0), WORLD_WIDTH - 1);
    new_position.y = min(max(new_position.y, 0), WORLD_HEIGHT - 1);
    if (to_crush == 'Z') {
      --zombies_count;
      vibe_explosion();
    }
    world[player_position.y][player_position.x] = '.';
    player_position = new_position;
    world[player_position.y][player_position.x] = '@';
  }

  static char s_buffer[32];
  snprintf(s_buffer, sizeof(s_buffer), "(%d, %d) %d", player_position.x, player_position.y, zombies_count);
  set_status_text(s_buffer);
}
