#include "world.h"
#include "command.h"
#include "config.h"
#include "entity.h"
#include "loop.h"
#include "player.h"
#include "pt_math.h"

void InitWorld(const world_def *Def, world &World)
{
  World.Arena = rect{ .X = 0, .Y = 0, .Width = static_cast<float>(Def->Width), .Height = static_cast<float>(Def->Height) };
  World.Entities.reserve(MAX_ENTITIES);
  World.PlayerIndex = static_cast<int>(World.Entities.size());
  World.Entities.push_back(CreatePlayer(vec2{ .X = static_cast<float>(Def->Width) / 2, .Y = static_cast<float>(Def->Height) / 2 }));
  InitProjectilePool(World.Projectiles);
}

void TickWorld(world &World, std::span<const command> Commands)
{
  World.Entities[World.PlayerIndex].Mover.Intent = {};
  World.Entities[World.PlayerIndex].Shooter.Firing = false;
  World.Entities[World.PlayerIndex].Dasher.Requested = false;

  for (const command &Command : Commands) { ApplyCommand(World, Command); }
  for (entity &Entity : World.Entities) {
    Entity.Transform.PrevPosition = Entity.Transform.CurrPosition;
    if (Entity.Update != nullptr) { Entity.Update(World, Entity, FIXED_TIMESTEP); }
  }
  UpdateProjectiles(World.Projectiles, World.Arena, FIXED_TIMESTEP);
  ++World.Tick;
}

void ApplyCommand(world &World, const command &Command)
{
  switch (Command.Type) {
  case command_type::MOVE:
    World.Entities[World.PlayerIndex].Mover.Intent = Command.Direction;
    break;
  case command_type::AIM:
    if (Vec2Length(Command.Direction) == 0) { break; }
    World.Entities[World.PlayerIndex].Shooter.AimDir = Vec2Normalize(Command.Direction);
    break;
  case command_type::FIRE:
    World.Entities[World.PlayerIndex].Shooter.Firing = true;
    break;
  case command_type::DASH:
    World.Entities[World.PlayerIndex].Dasher.Requested = true;
    break;
  default:
    break;
  }
}
