#pragma once

#include "entity.h"

entity CreatePlayer(vec2 Position);
void UpdatePlayer(world &World, entity &Player, float Deltatime);
