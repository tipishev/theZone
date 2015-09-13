#pragma once

#include "pebble.h"

// TODO move to global config
#define TILE_SIZE 24

static GRect tile_to_global(const int tile_x, const int tile_y);

void create_bitmaps();
void destroy_bitmaps();

void create_layers(Window *window);
void destroy_layers();

void create_action_bar(Window *window);
void destroy_action_bar();
