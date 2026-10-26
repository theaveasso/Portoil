#include "player.h"
#include "components.h"
#include "config.h"
#include "entity.h"
#include "pt_math.h"
#include "world.h"
#include <array>
#include <cassert>

struct player_state_def
{
  void (*Enter)(world &World, entity &Player);
  void (*Update)(world &World, entity &Player, float Deltatime);
  void (*Exit)(world &World, entity &Player);
};

static void UpdateAlive(world &World, entity &Player, float Deltatime);
static void EnterDashing(world &World, entity &Player);
static void UpdateDashing(world &World, entity &Player, float Deltatime);

constexpr std::array<player_state_def, player_state::PLAYER_STATE_COUNT> PLAYER_STATES = { {
  { .Enter = nullptr, .Update = UpdateAlive, .Exit = nullptr },
  { .Enter = EnterDashing, .Update = UpdateDashing, .Exit = nullptr },
  { .Enter = nullptr, .Update = nullptr, .Exit = nullptr },
} };

static player_state_def GetPlayerState(int Index)
{
  assert(Index >= 0 && Index < player_state::PLAYER_STATE_COUNT);
  return PLAYER_STATES[Index];
}

entity CreatePlayer(vec2 Position)
{
  entity Result = {};
  Result.Mask = COMP_MOVER | COMP_DASHER | COMP_HEALTH | COMP_SHOOTER;
  Result.Transform = { .PrevPosition = Position, .CurrPosition = Position, .Radius = PLAYER_RADIUS };
  Result.Mover = { .Speed = PLAYER_SPEED };
  Result.Dasher = { .Speed = DASH_SPEED, .Cooldown = DASH_COOLDOWN };
  Result.Health = { .Hp = PLAYER_MAX_HEALTH, .MaxHp = PLAYER_MAX_HEALTH, .InvulnTimer = PLAYER_INVULN_WINDOW };
  Result.Shooter = { .AimDir = { .X = 1 }, .FireCooldown = FIRE_COOLDOWN, .BulletSpeed = PROJECTILE_SPEED };
  Result.State = PLAYER_STATE_ALIVE;
  Result.NextState = PLAYER_STATE_ALIVE;
  Result.Update = UpdatePlayer;
  return Result;
}

void UpdatePlayer(world &World, entity &Player, float Deltatime)
{
  if (Player.Dasher.CooldownTimer > 0) { Player.Dasher.CooldownTimer -= Deltatime; }
  if (Player.Health.InvulnTimer > 0) { Player.Health.InvulnTimer -= Deltatime; }
  if (Player.Shooter.CooldownTimer > 0) { Player.Shooter.CooldownTimer -= Deltatime; }
  Player.StateTimer += Deltatime;

  const player_state_def &Current = GetPlayerState(Player.State);
  if (Current.Update != nullptr) { Current.Update(World, Player, Deltatime); }

  if (Player.NextState != Player.State) {
    if (Current.Exit != nullptr) { Current.Exit(World, Player); }
    Player.State = Player.NextState;
    Player.StateTimer = 0;
    const player_state_def &Next = GetPlayerState(Player.State);
    if (Next.Enter != nullptr) { Next.Enter(World, Player); }
  }
}

static void MoveClamp(world &World, entity &Entity, const vec2 Velocity, float Deltatime)
{
  transform &Transform = Entity.Transform;
  Transform.CurrPosition = Vec2Add(Transform.CurrPosition, Vec2Mul(Velocity, Deltatime));
  Transform.CurrPosition.X = Clamp(Transform.CurrPosition.X, Transform.Radius, World.Arena.Width - Transform.Radius);
  Transform.CurrPosition.Y = Clamp(Transform.CurrPosition.Y, Transform.Radius, World.Arena.Height - Transform.Radius);
}

static void TryFire(world &World, entity &Entity)
{
  shooter &Shooter = Entity.Shooter;
  if (!Shooter.Firing || Shooter.CooldownTimer > 0) { return; }
  vec2 SpawnPosition = Vec2Add(Entity.Transform.CurrPosition, Vec2Mul(Shooter.AimDir, Entity.Transform.Radius));
  vec2 SpawnVelocity = Vec2Mul(Shooter.AimDir, Shooter.BulletSpeed);
  SpawnProjectile(World.Projectiles, SpawnPosition, SpawnVelocity);
  Shooter.CooldownTimer = Shooter.FireCooldown;
}

bool DamagePlayer(entity &Player, int Amount)
{
  if (Player.State == PLAYER_STATE_DOWNED || Player.State == PLAYER_STATE_DASHING || Player.Health.InvulnTimer > 0) { return false; }
  Player.Health.Hp = Max((Player.Health.Hp - Amount), 0);
  Player.Health.InvulnTimer = PLAYER_INVULN_WINDOW;
  if (Player.Health.Hp <= 0) { Player.NextState = PLAYER_STATE_DOWNED; }

  return true;
}

static void UpdateAlive(world &World, entity &Player, float Deltatime)
{
  if (Player.Health.Hp <= 0) { return; }
  vec2 Direction = Vec2Length(Player.Mover.Intent) > 1 ? Vec2Normalize(Player.Mover.Intent) : Player.Mover.Intent;
  vec2 Velocity = Vec2Mul(Direction, Player.Mover.Speed);
  MoveClamp(World, Player, Velocity, Deltatime);
  TryFire(World, Player);
  if (Player.Dasher.Requested && Player.Dasher.CooldownTimer <= 0) { Player.NextState = PLAYER_STATE_DASHING; }
}

static void EnterDashing(world & /*World*/, entity &Player)
{
  bool Moving = Vec2Length(Player.Mover.Intent) > 0;
  Player.Dasher.Direction = Moving ? Vec2Normalize(Player.Mover.Intent) : Player.Shooter.AimDir;
  Player.Dasher.CooldownTimer = Player.Dasher.Cooldown;
}

static void UpdateDashing(world &World, entity &Player, float Deltatime)
{
  if (Player.Health.Hp <= 0) { return; }
  const float Speed = Player.Dasher.Speed * 2 * (1.0F - Min(Player.StateTimer / DASH_DURATION, 1.0F));
  const vec2 Velocity = Vec2Mul(Player.Dasher.Direction, Speed);
  MoveClamp(World, Player, Velocity, Deltatime);
  if (Player.StateTimer >= DASH_DURATION) { Player.NextState = PLAYER_STATE_ALIVE; }
}
