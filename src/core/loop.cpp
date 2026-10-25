#include "loop.h"
#include "pt_math.h"

constexpr double MAX_FRAME_SECONDS = 0.25;
constexpr double FIXED_TIMESTEP = 1. / 60.;

int LoopAdvance(loop_state &State, double FrameSeconds)
{
  FrameSeconds = Clamp(FrameSeconds, 0., MAX_FRAME_SECONDS);
  State.Accumlator += FrameSeconds;
  int Tick = 0;
  while (State.Accumlator >= FIXED_TIMESTEP) {
    State.Accumlator -= FIXED_TIMESTEP;
    Tick++;
  }
  return Tick;
}

float LoopAlpha(const loop_state &State) { return static_cast<float>(State.Accumlator / FIXED_TIMESTEP); }
