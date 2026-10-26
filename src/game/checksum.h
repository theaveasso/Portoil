#pragma once

#include "world.h"
#include <bit>
#include <cstdint>

static constexpr uint64_t FNV_OFFSET = 14695981039346656037ULL;
static constexpr uint64_t FNV_PRIME = 1099511628211ULL;

inline void Mix(uint64_t &Hash, uint32_t Value)
{
  for (int Byte = 0; Byte < 4; ++Byte) {
    Hash ^= (Value >> (Byte * 8)) & 0xFFU;
    Hash *= FNV_PRIME;
  }
}
inline void Mix(uint64_t &Hash, int Value) { Mix(Hash, static_cast<uint32_t>(Value)); }
inline void Mix(uint64_t &Hash, float Value) { Mix(Hash, std::bit_cast<uint32_t>(Value)); }
inline void Mix(uint64_t &Hash, const vec2 &Value)
{
  Mix(Hash, Value.X);
  Mix(Hash, Value.Y);
}

inline uint64_t GetWorldChecksum(const world &World)
{
  uint64_t Hash = FNV_OFFSET;
  Mix(Hash, static_cast<uint32_t>(World.Tick));
  Mix(Hash, static_cast<uint32_t>(World.Hearth.Hp));
  Mix(Hash, World.Hearth.Position);
  Mix(Hash, World.Rng.State);
  Mix(Hash, World.EnemySpawnTimer);

  for (const entity &Entity : World.Entities) {
    Mix(Hash, Entity.Transform.CurrPosition);
    Mix(Hash, Entity.State);
    Mix(Hash, Entity.StateTimer);
    Mix(Hash, Entity.Health.Hp);
    Mix(Hash, Entity.Health.InvulnTimer);
    Mix(Hash, Entity.Dasher.CooldownTimer);
    Mix(Hash, Entity.Shooter.CooldownTimer);
    Mix(Hash, Entity.Shooter.AimDir);
  }

  {
    int ProjIndex = -1;
    for (const projectile &Item : World.Projectiles.Items) {
      ++ProjIndex;
      if (!Item.Active) { continue; }
      Mix(Hash, ProjIndex);
      Mix(Hash, Item.CurrPosition);
    }
  }

  {
    int EnemyIndex = -1;
    for (const enemy &Item : World.Enemies.Items) {
      ++EnemyIndex;
      if (!Item.Active) { continue; }
      Mix(Hash, EnemyIndex);
      Mix(Hash, Item.Transform.CurrPosition);
      Mix(Hash, Item.Kind);
      Mix(Hash, Item.Health.Hp);
    }
  }

  return Hash;
}
