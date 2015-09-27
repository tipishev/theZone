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

Player player;

int zombies_count = 7; // FIXME remove when you've had enough fun with it

void load_world() {
  // TODO read *a* world aka level from raw resources
}

void init_player() {
  player.health = 10;
  player.position.x = 4;
  player.position.y = 14;
  player.direction = N;
}

void deinit_player() {
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

GPoint get_player_position() {
  return player.position;
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
    world[player.position.y][player.position.x] = '.';
    player.position = new_position;
    world[player.position.y][player.position.x] = '@';
  }

  static char s_buffer[32];
  snprintf(s_buffer, sizeof(s_buffer),
           "@(%d, %d) #: %d dir: %d",
           player.position.x, player.position.y,
           zombies_count,
           player.direction
  );

  set_status_text(s_buffer);
}
