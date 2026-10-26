#include "world.h"
#include "command.h"
#include "config.h"
#include "enemy.h"
#include "entity.h"
#include "loop.h"
#include "player.h"
#include "pt_math.h"
#include <cassert>
#include <numbers>

static constexpr float SPAWN_RADIUS = 110.F;

static constexpr float ENEMY_SPAWN_INTERVAL = 3.F;
static constexpr int ENEMY_SPAWN_CAP = 8;
static constexpr float ENEMY_SPAWN_MARGIN = 40.F;

void InitWorld(const world_def *Def, world &World)
{
  assert(Def->PlayerCount >= 1 && Def->PlayerCount <= MAX_PLAYERS);
  const vec2 Center = { .X = static_cast<float>(Def->Width) / 2.F, .Y = static_cast<float>(Def->Height) / 2.F };
  World.Arena = rect{ .X = 0, .Y = 0, .Width = static_cast<float>(Def->Width), .Height = static_cast<float>(Def->Height) };
  World.Entities.reserve(MAX_ENTITIES);
  World.PlayerCount = Def->PlayerCount;
  World.Hearth = { .Hp = HEARTH_MAX_HP, .MaxHp = HEARTH_MAX_HP, .Position = Center };
  World.Rng = { .State = Def->Seed };
  for (int Index = 0; Index < Def->PlayerCount; ++Index) {
    const float Angle = static_cast<float>(Index) / static_cast<float>(Def->PlayerCount) * 2.F * static_cast<float>(std::numbers::pi);
    const vec2 Offset = Vec2Mul({ .X = std::cos(Angle), .Y = std::sin(Angle) }, SPAWN_RADIUS);
    World.Entities.push_back(CreatePlayer(Vec2Add(Center, Offset)));
  }
  InitProjectilePool(World.Projectiles);
  InitEnemyPool(World.Enemies);
}

static vec2 RandomEdgePoint(rng &Rng, const rect &Arena, float Margin)
{
  const uint32_t Edge = RngNext(Rng) % 4;
  const float Amount = RngFloat(Rng);
  switch (Edge) {
  case 0:
    return { .X = Arena.X + (Amount * Arena.Width), .Y = Arena.Y - Margin };
  case 1:
    return { .X = Arena.X + Arena.Width + Margin, .Y = Arena.Y + (Amount * Arena.Height) };
  case 2:
    return { .X = Arena.X + (Amount * Arena.Width), .Y = Arena.Y + Arena.Height + Margin };
  default:
    return { .X = Arena.X - Margin, .Y = Arena.Y + (Amount * Arena.Height) };
  }
}

static void SpawnEnemies(world &World)
{
  World.EnemySpawnTimer -= FIXED_TIMESTEP;
  if (World.EnemySpawnTimer > 0) { return; }
  World.EnemySpawnTimer = ENEMY_SPAWN_INTERVAL;
  if (World.Enemies.ActiveCount >= ENEMY_SPAWN_CAP) { return; }

  const int Kind = PickEnemyKind(World.Rng);
  const vec2 Position = RandomEdgePoint(World.Rng, World.Arena, ENEMY_SPAWN_MARGIN);
  SpawnEnemy(World.Enemies, Kind, Position);
}

void TickWorld(world &World, std::span<const command> Commands)
{
  for (int Index = 0; Index < World.PlayerCount; ++Index) {
    World.Entities[Index].Mover.Intent = {};
    World.Entities[Index].Shooter.Firing = false;
    World.Entities[Index].Dasher.Requested = false;
  }

  for (const command &Command : Commands) { ApplyCommand(World, Command); }
  for (entity &Entity : World.Entities) {
    Entity.Transform.PrevPosition = Entity.Transform.CurrPosition;
    if (Entity.Update != nullptr) { Entity.Update(World, Entity, FIXED_TIMESTEP); }
  }
  SpawnEnemies(World);
  UpdateProjectiles(World.Projectiles, World.Arena, FIXED_TIMESTEP);
  UpdateEnemies(World, FIXED_TIMESTEP);
  ++World.Tick;
}

void ApplyCommand(world &World, const command &Command)
{
  if (Command.PlayerIndex >= World.PlayerCount) { return; }
  entity &Player = World.Entities[Command.PlayerIndex];

  switch (Command.Type) {
  case command_type::MOVE:
    Player.Mover.Intent = Command.Direction;
    break;
  case command_type::AIM:
    if (Vec2Length(Command.Direction) == 0) { break; }
    Player.Shooter.AimDir = Vec2Normalize(Command.Direction);
    break;
  case command_type::FIRE:
    Player.Shooter.Firing = true;
    break;
  case command_type::DASH:
    Player.Dasher.Requested = true;
    break;
  case command_type::DEBUG_HURT:
    DamagePlayer(Player, 1);
    break;
  default:
    break;
  }
}
