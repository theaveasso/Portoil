#include "checksum.h"
#include <bit>

static constexpr uint64_t FNV_OFFSET = 14695981039346656037ULL;
static constexpr uint64_t FNV_PRIME = 1099511628211ULL;

static void Mix(uint64_t &Hash, uint32_t Value)
{
  for (int Byte = 0; Byte < 4; ++Byte) {
    Hash ^= (Value >> (Byte * 8)) & 0xFFU;
    Hash *= FNV_PRIME;
  }
}
static void Mix(uint64_t &Hash, int Value) { Mix(Hash, static_cast<uint32_t>(Value)); }
static void Mix(uint64_t &Hash, float Value) { Mix(Hash, std::bit_cast<uint32_t>(Value)); }
static void Mix(uint64_t &Hash, const vec2 &Value)
{
  Mix(Hash, Value.X);
  Mix(Hash, Value.Y);
}

uint64_t GetWorldChecksum(const world &World)
{
  uint64_t Hash = FNV_OFFSET;
  Mix(Hash, static_cast<uint32_t>(World.Tick));
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

  int ProjIndex = -1;
  for (const projectile &Item : World.Projectiles.Items) {
    ++ProjIndex;
    if (!Item.Active) { continue; }
    Mix(Hash, ProjIndex);
    Mix(Hash, Item.CurrPosition);
  }
  return Hash;
}
