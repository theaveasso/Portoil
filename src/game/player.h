#pragma once

#include "entity.h"

enum player_state : int {
  PLAYER_STATE_ALIVE,
  PLAYER_STATE_DASHING,
  PLAYER_STATE_DOWNED,
  PLAYER_STATE_COUNT,
};

entity CreatePlayer(vec2 Position);
void UpdatePlayer(world &World, entity &Player, float Deltatime);
bool DamagePlayer(entity &Player, int Amount);
