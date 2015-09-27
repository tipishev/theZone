#include "model.h"
#include "map.h"

Player player;

int zombies_count = 7; // FIXME remove when you've had enough fun with it

void init_player() {
  player.health = 10;
  player.position.x = 4;
  player.position.y = 14;
  player.direction = N;
}

void deinit_player() {
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
           "@(%d, %d) Z:%d dir:%d",
           player.position.x, player.position.y,
           zombies_count,
           player.direction
  );
  set_status_text(s_buffer);
}
