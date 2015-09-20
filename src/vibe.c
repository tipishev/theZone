#include "vibe.h"

static void vibe(const uint32_t const *durations, const short num_segents) {
  VibePattern pattern = {
    .durations = durations, // {vibe_duration, pause_duration, ...}
    .num_segments = num_segents,
  };
  vibes_enqueue_custom_pattern(pattern);
}

void vibe_footsteps() {
  static const uint32_t const FOOTSTEPS[] = {50, 100, 50, 100, 50 };
  vibe(FOOTSTEPS, 5);
}

void vibe_damage() {
  static const uint32_t const DAMAGE[] = {200};
  vibe(DAMAGE, 1);
}
