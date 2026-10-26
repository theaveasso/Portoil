#pragma once

#include "components.h"
#include "config.h"
#include "pt_math.h"
#include "rng.h"
#include <array>

struct world;

enum enemy_kind : int { ENEMY_KIND_CRAWLER, ENEMY_KIND_SKITTER, ENEMY_KIND_COUNT };

struct enemy_type
{
  float Speed = 0;
  int MaxHp = 0;
  float Radius = 0;
  float SpawnWeight = 0;
};

struct enemy
{
  int Kind = 0;
  transform Transform;
  health Health;
  float FrozenTimer = 0;
  int NextFree = -1;
  bool Active = false;
};

struct enemy_pool
{
  std::array<enemy, MAX_ENEMIES> Items;
  int FirstFree = 0;
  int ActiveCount = 0;
};

void InitEnemyPool(enemy_pool &Pool);
int SpawnEnemy(enemy_pool &Pool, int Kind, const vec2 &Position);
void FreeEnemy(enemy_pool &Pool, int Index);
void UpdateEnemies(world &World, float Deltatime);

int PickEnemyKind(rng &Rng);
