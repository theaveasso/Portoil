#pragma once

#include "pt_math.h"
#include <cstdint>

#include "config.h"

enum component_bit : uint32_t {
  COMP_MOVER = 1U << 0U,
  COMP_DASHER = 1U << 1U,
  COMP_HEALTH = 1U << 2U,
  COMP_SHOOTER = 1U << 3U,
};

struct transform
{
  vec2 PrevPosition;
  vec2 CurrPosition;
  float Radius = PLAYER_RADIUS;
};

struct mover
{
  vec2 Intent;
  float Speed = PLAYER_SPEED;
};

struct dasher
{
  vec2 Direction;
  float Speed = PLAYER_SPEED;
  float Cooldown = PLAYER_SKILL_COOLDOWN;
  float Timer = 0;
  float CooldownTimer = 0;
};

struct health
{
  int Hp = 0;
  int MaxHp = 0;
  float InvulnTimer = 0;
};

struct shooter
{
  vec2 AimDir;
  bool Firing = false;
  float FireRate = 0;
  float CooldownTimer = 0;
  float BulletSpeed = 0;
};
