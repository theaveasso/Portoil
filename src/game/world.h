#pragma once

#include "command.h"
#include "entity.h"
#include "projectile.h"
#include "pt_math.h"
#include <cstdint>
#include <span>
#include <vector>

struct world
{
  rect Arena;
  std::vector<entity> Entities;
  projectile_pool Projectiles;
  int PlayerIndex = -1;
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
