#include "player.h"
#include "map.h"

Player player;

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
  // model stuff
  GPoint old_position;
  old_position = player.position;

  // graphics stuff
  char to_crush = get_map_at(new_position);
  if (to_crush != '#') {
    new_position.x = min(max(new_position.x, 0), MAP_WIDTH - 1);
    new_position.y = min(max(new_position.y, 0), MAP_HEIGHT - 1);
    if (to_crush == 'Z') {
      vibe_explosion();
    }
    set_map_at(old_position, '.');
    player.position = new_position;
    set_map_at(player.position, '@');
  }

  static char s_buffer[32];
  snprintf(s_buffer, sizeof(s_buffer),
           "@(%d, %d) dir:%d",
           player.position.x, player.position.y,
           player.direction
  );
  set_status_text(s_buffer);
}
