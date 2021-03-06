#pragma once

#include <pebble.h>
#include "game.h"
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

void init_player();
GPoint get_player_position();
void set_player_position(GPoint new_position);
void deinit_player();
