#pragma once

#include "components.h"
#include <cstdint>
struct world;
struct entity;

using pfn_update = void (*)(world &World, entity &Object, float Deltatime);

struct entity
{
  uint32_t Mask = 0;
  transform Transform = {};
  mover Mover = {};
  dasher Dasher = {};
  health Health = {};
  shooter Shooter = {};
  int State = 0;
  int NextState = 0;
  float StateTimer = 0;

  pfn_update Update = nullptr;
};
