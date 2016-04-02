#pragma once

#include <pebble.h>
#include "game.h"
#include "sprite.h"

void init_graphics(Window* window);
void deinit_graphics();

ActionBarLayer* get_action_bar();  // TODO const?
void switch_action_bar();  // TODO make it smarter

void fill_viewport(char map_piece[VIEWPORT_HEIGHT][VIEWPORT_WIDTH]);

void set_status_text(char *text);
