#pragma once

#include "command.h"
#include "pt_math.h"
#include <cstdint>
#include <span>

constexpr float PLAYER_SPEED = 300;
constexpr float PLAYER_RADIUS = 14;

struct world
{
  vec2 PlayerPrevPosition;
  vec2 PlayerCurrPosition;
  vec2 MoveIntent;
  rect Arena;
  uint64_t Tick = 0;
};

struct world_def
{
  int Width = 0;
  int Height = 0;
};

void InitWorld(const world_def *Def, world &World);
void TickWorld(world &World, std::span<const command> Commands);
void ApplyCommand(world &World, const command &Command);
