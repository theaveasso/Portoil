#pragma once

#include "command.h"
#include "entity.h"
#include "projectile.h"
#include "pt_math.h"
#include "rng.h"
#include <cstdint>
#include <span>
#include <vector>

struct hearth
{
  int Hp = 0;
  int MaxHp = 0;
  vec2 Position = {};
};

struct world
{
  rect Arena;
  rng Rng;
  hearth Hearth;
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
  uint32_t Seed = 0x9E3779B9U;
};

void InitWorld(const world_def *Def, world &World);
void TickWorld(world &World, std::span<const command> Commands);
void ApplyCommand(world &World, const command &Command);
