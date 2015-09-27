#pragma once

#include <pebble.h>
#include "config.h"

void init_graphics(Window* window);
void deinit_graphics();

ActionBarLayer* get_action_bar();  // TODO const?
void switch_action_bar();  // TODO make it smarter

void fill_viewport(char world_piece[VIEWPORT_HEIGHT][VIEWPORT_WIDTH]);

void set_status_text(char *text);
