#pragma once

#include <cstdint>

constexpr double FIXED_TIMESTEP = 1. / 60.;

struct loop_state
{
  double Accumlator;
  uint64_t Tick;
};

int LoopAdvance(loop_state &State, double FrameSeconds);
float LoopAlpha(const loop_state &State);
