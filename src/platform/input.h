#pragma once

#include "game/command.h"
#include "pt_math.h"
#include <vector>

struct input_frame
{
  vec2 Move;
  vec2 Aim;
  bool Fire = false;
  bool DashPressed = false;
  bool HurtPressed = false;
};

void GatherInput(input_frame &Input);
void TakeTickCommands(input_frame &Input, std::vector<command> &Out);
