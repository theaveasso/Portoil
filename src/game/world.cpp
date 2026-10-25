#include "world.h"
#include "command.h"
#include "loop.h"
#include "pt_math.h"

void InitWorld(const world_def *Def, world &World)
{
  World.Arena = rect{ .X = 0, .Y = 0, .Width = static_cast<float>(Def->Width), .Height = static_cast<float>(Def->Height) };
  World.PlayerCurrPosition = vec2{ .X = World.Arena.Width / 2, .Y = World.Arena.Height / 2 };
  World.PlayerPrevPosition = World.PlayerCurrPosition;
}

void TickWorld(world &World, std::span<const command> Commands)
{
  World.MoveIntent = {};
  for (const command &Command : Commands) { ApplyCommand(World, Command); }
  World.PlayerPrevPosition = World.PlayerCurrPosition;

  vec2 Direction = Vec2Length(World.MoveIntent) > 1 ? Vec2Normalize(World.MoveIntent) : World.MoveIntent;
  World.PlayerCurrPosition = Vec2Add(World.PlayerCurrPosition, Vec2Mul(Direction, PLAYER_SPEED * FIXED_TIMESTEP));
  World.PlayerCurrPosition.X = Clamp(World.PlayerCurrPosition.X, PLAYER_RADIUS, World.Arena.Width - PLAYER_RADIUS);
  World.PlayerCurrPosition.Y = Clamp(World.PlayerCurrPosition.Y, PLAYER_RADIUS, World.Arena.Height - PLAYER_RADIUS);
  ++World.Tick;
}

void ApplyCommand(world &World, const command &Command)
{
  switch (Command.Type) {
  case command_type::MOVE:
    World.MoveIntent = Command.Direction;
    break;
  default:
    break;
  }
}
