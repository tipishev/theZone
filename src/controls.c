#include "controls.h"

// VIBE PATTERNS vibe-pause-vibe-...
static const uint32_t const FOOTSTEPS[] = {50, 100, 50, 100, 50 };
static const uint32_t const DAMAGE[] = {200};

static void vibe(const uint32_t const *pattern) {
     VibePattern pat = {
       .durations = pattern,
         /*.num_segments = ARRAY_LENGTH(pattern),*/  // TODO determine pattern length
         .num_segments = 5,
         };
         vibes_enqueue_custom_pattern(pat);
}


static void increment_click_handler(ClickRecognizerRef recognizer, void *context) {
}

static void decrement_click_handler(ClickRecognizerRef recognizer, void *context) {
}

static void run_click_handler(ClickRecognizerRef recognizer, void *context) {
    vibe(FOOTSTEPS);
}

static void click_config_provider(void *context) {
  window_single_repeating_click_subscribe(BUTTON_ID_UP, REPEAT_INTERVAL_MS, increment_click_handler);
  window_single_repeating_click_subscribe(BUTTON_ID_DOWN, REPEAT_INTERVAL_MS, decrement_click_handler);
  window_single_repeating_click_subscribe(BUTTON_ID_SELECT, REPEAT_INTERVAL_MS, run_click_handler);
}
