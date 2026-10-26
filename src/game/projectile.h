#pragma once

#include "config.h"
#include "pt_math.h"
#include <array>

struct projectile
{
  vec2 PrevPosition;
  vec2 CurrPosition;
  vec2 Velocity;
  float Lifespan = 0;
  int NextFree = -1;
  bool Active = false;
};

struct projectile_pool
{
  std::array<projectile, MAX_PROJECTILES> Items;
  int FirstFree = 0;
  int ActiveCount = 0;
};

void InitProjectilePool(projectile_pool &Pool);
int SpawnProjectile(projectile_pool &Pool, const vec2 &Position, const vec2 &Velocity);
void FreeProjectile(projectile_pool &Pool, int Index);
void UpdateProjectiles(projectile_pool &Pool, const rect &Arena, float Deltatime);
