#include "projectile.h"

#include "pt_geometry.h"
#include <cassert>

void InitProjectilePool(projectile_pool &Pool)
{
  int Index = 0;
  for (projectile &Item : Pool.Items) {
    Item.NextFree = Index + 1;
    Item.Active = false;
    ++Index;
  }
  Pool.Items.back().NextFree = -1;
  Pool.FirstFree = 0;
  Pool.ActiveCount = 0;
}

int SpawnProjectile(projectile_pool &Pool, const vec2 &Position, const vec2 &Velocity)
{
  const int Result = Pool.FirstFree;
  if (Result == -1) { return -1; }

  projectile &Item = Pool.Items[Result];
  Pool.FirstFree = Item.NextFree;
  Item = {
    .PrevPosition = Position,
    .CurrPosition = Position,
    .Velocity = Velocity,
    .Lifespan = PROJECTILE_LIFESPAN,
    .Active = true,
  };
  Pool.ActiveCount++;
  return Result;
}

void FreeProjectile(projectile_pool &Pool, int Index)
{
  assert(Index >= 0 && Index < MAX_PROJECTILES);
  projectile &Item = Pool.Items[Index];
  if (!Item.Active) { return; }

  Item.Active = false;
  Item.NextFree = Pool.FirstFree;
  Pool.FirstFree = Index;
  --Pool.ActiveCount;
}

void UpdateProjectiles(projectile_pool &Pool, const rect &Arena, float Deltatime)
{
  int Index = -1;
  for (projectile &Item : Pool.Items) {
    ++Index;
    if (!Item.Active) { continue; }
    Item.PrevPosition = Item.CurrPosition;
    Item.CurrPosition = Vec2Add(Item.CurrPosition, Vec2Mul(Item.Velocity, Deltatime));
    Item.Lifespan -= Deltatime;
    if (Item.Lifespan <= 0 || !RectContainsPoint(Arena, Item.CurrPosition)) { FreeProjectile(Pool, Index); }
  }
}
