#pragma once

#include "pebble.h"
#include "config.h"

void init_graphics(Window* window);
void deinit_graphics();

ActionBarLayer* get_action_bar();  // TODO const?
void switch_action_bar();  // TODO make it smarter

