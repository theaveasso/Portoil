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
  int PlayerCount = 0;
  uint64_t Tick = 0;
};

struct world_def
{
  int Width = 0;
  int Height = 0;
  int PlayerCount = 1;
};

void InitWorld(const world_def *Def, world &World);
void TickWorld(world &World, std::span<const command> Commands);
void ApplyCommand(world &World, const command &Command);
