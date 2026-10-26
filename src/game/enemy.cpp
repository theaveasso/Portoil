#include "enemy.h"
#include "player.h"
#include "rng.h"
#include "world.h"
#include <cassert>

static constexpr std::array<enemy_type, enemy_kind::ENEMY_KIND_COUNT> ENEMY_TYPES = { {
  { .Speed = 40, .MaxHp = 4, .Radius = 12, .SpawnWeight = 0.5F },
  { .Speed = 110, .MaxHp = 2, .Radius = 8, .SpawnWeight = 0.5F },
} };


int PickEnemyKind(rng &Rng)
{
  float Total = 0;
  for (const enemy_type &Type : ENEMY_TYPES) { Total += Type.SpawnWeight; }
  float Roll = RngFloat(Rng) * Total;
  for (int Kind = 0; Kind < ENEMY_KIND_COUNT; ++Kind) {
    Roll -= ENEMY_TYPES[Kind].SpawnWeight;
    if (Roll < 0) { return Kind; }
  }
  return ENEMY_KIND_COUNT - 1;
}

enemy_type GetEnemyType(int Index)
{
  assert(Index >= 0 && Index < enemy_kind::ENEMY_KIND_COUNT);
  return ENEMY_TYPES[Index];
}


void InitEnemyPool(enemy_pool &Pool)
{
  int Index = 0;
  for (enemy &Item : Pool.Items) {
    Item.NextFree = Index + 1;
    Item.Active = false;
    ++Index;
  }
  Pool.Items.back().NextFree = -1;
  Pool.FirstFree = 0;
  Pool.ActiveCount = 0;
}

int SpawnEnemy(enemy_pool &Pool, int Kind, const vec2 &Position)
{
  const int Result = Pool.FirstFree;
  if (Result == -1) { return -1; }

  enemy &Item = Pool.Items[Result];
  Pool.FirstFree = Item.NextFree;
  enemy_type Type = GetEnemyType(Kind);
  Item = {
    .Kind = Kind,
    .Transform = { .PrevPosition = Position, .CurrPosition = Position, .Radius = Type.Radius },
    .Health = { .Hp = Type.MaxHp, .MaxHp = Type.MaxHp },
    .Active = true,
  };
  Pool.ActiveCount++;
  return Result;
}

static vec2 FindNearestTarget(const world &World, const vec2 &From)
{
  vec2 Best = World.Hearth.Position;
  float BestSquare = Vec2LengthSq(Vec2Sub(Best, From));
  for (int Index = 0; Index < World.PlayerCount; ++Index) {
    const entity &Keeper = World.Entities[Index];
    if (Keeper.State == PLAYER_STATE_DOWNED) { continue; }
    const float LengthSquare = Vec2LengthSq(Vec2Sub(Keeper.Transform.CurrPosition, From));
    if (LengthSquare < BestSquare) {
      BestSquare = LengthSquare;
      Best = Keeper.Transform.CurrPosition;
    }
  }
  return Best;
}

void FreeEnemy(enemy_pool &Pool, int Index)
{
  assert(Index >= 0 && Index < MAX_ENEMIES);
  enemy &Item = Pool.Items[Index];
  if (!Item.Active) { return; }

  Item.Active = false;
  Item.NextFree = Pool.FirstFree;
  Pool.FirstFree = Index;
  --Pool.ActiveCount;
}

void UpdateEnemies(world &World, float Deltatime)
{
  for (enemy &Item : World.Enemies.Items) {
    if (!Item.Active) { continue; }
    Item.Transform.PrevPosition = Item.Transform.CurrPosition;
    if (Item.FrozenTimer > 0) {
      Item.FrozenTimer -= Deltatime;
      continue;
    }
    const vec2 Target = FindNearestTarget(World, Item.Transform.CurrPosition);
    const vec2 Direction = Vec2Normalize(Vec2Sub(Target, Item.Transform.CurrPosition));
    const float Speed = GetEnemyType(Item.Kind).Speed;
    Item.Transform.CurrPosition = Vec2Add(Item.Transform.CurrPosition, Vec2Mul(Direction, Speed * Deltatime));
  }
}
