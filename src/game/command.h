#pragma once

#include "pt_math.h"
#include <cstdint>

enum class command_type : uint8_t {
  NONE,
  MOVE,
  AIM,
  FIRE,
  DASH,
  DEBUG_HURT,
};

struct command
{
  uint8_t PlayerIndex = 0;
  command_type Type = command_type::NONE;
  vec2 Direction = {};
};
