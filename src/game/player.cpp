#include "player.h"
#include "components.h"
#include "config.h"
#include "entity.h"
#include "pt_math.h"
#include "world.h"

entity CreatePlayer(vec2 Position)
{
  entity Result = {};
  Result.Mask = COMP_MOVER | COMP_DASHER | COMP_HEALTH | COMP_SHOOTER;
  Result.Transform = { .PrevPosition = Position, .CurrPosition = Position, .Radius = PLAYER_RADIUS };
  Result.Mover = { .Speed = PLAYER_SPEED };
  Result.Health = { .Hp = PLAYER_MAX_HEALTH, .MaxHp = PLAYER_MAX_HEALTH, .InvulnTimer = PLAYER_INVULN_WINDOW };
  Result.Shooter = { .AimDir = { .X = 1 }, .FireCooldown = FIRE_COOLDOWN, .BulletSpeed = PROJECTILE_SPEED };
  Result.Update = UpdatePlayer;
  return Result;
}

void UpdatePlayer(world &World, entity &Player, float Deltatime)
{
  vec2 Direction = Vec2Length(Player.Mover.Intent) > 1 ? Vec2Normalize(Player.Mover.Intent) : Player.Mover.Intent;
  Player.Transform.CurrPosition = Vec2Add(Player.Transform.CurrPosition, Vec2Mul(Direction, Player.Mover.Speed * Deltatime));
  Player.Transform.CurrPosition.X = Clamp(Player.Transform.CurrPosition.X, Player.Transform.Radius, World.Arena.Width - Player.Transform.Radius);
  Player.Transform.CurrPosition.Y = Clamp(Player.Transform.CurrPosition.Y, Player.Transform.Radius, World.Arena.Height - Player.Transform.Radius);

  if (Player.Shooter.CooldownTimer > 0) { Player.Shooter.CooldownTimer -= Deltatime; }
  if (Player.Shooter.Firing && Player.Shooter.CooldownTimer <= 0) {
    vec2 SpawnPosition = Vec2Add(Player.Transform.CurrPosition, Vec2Mul(Player.Shooter.AimDir, Player.Transform.Radius));
    vec2 SpawnVelocity = Vec2Mul(Player.Shooter.AimDir, Player.Shooter.BulletSpeed);
    SpawnProjectile(World.Projectiles, SpawnPosition, SpawnVelocity);
    Player.Shooter.CooldownTimer = Player.Shooter.FireCooldown;
  }
}
