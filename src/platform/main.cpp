#include <cstdlib>

#include <raylib.h>
#include <string>
#include <vector>

#include "app.h"
#include "core/loop.h"
#include "game/command.h"
#include "game/world.h"
#include "platform/input.h"
#include "pt_math.h"

#if defined(PT_PLATFORM_WEB)
#include <emscripten/emscripten.h>
#endif

constexpr int MAX_COMMANDS = 8;

struct frame_state
{
  loop_state LoopState = {};
  world World = {};
  input_frame Input = {};
  std::vector<command> Commands;
  int TickCounted = 0;
  int TickPerSecond = 0;
  float SecondTimer = 0;
};

static void UpdateDrawFrame(void *Args)
{
  frame_state &State = *static_cast<frame_state *>(Args);
  BeginDrawing();
  ClearBackground(BLACK);

  int Tick = LoopAdvance(State.LoopState, GetFrameTime());
  State.TickCounted += Tick;
  State.SecondTimer += GetFrameTime();
  if (State.SecondTimer > 1) {
    State.TickPerSecond = State.TickCounted;
    State.TickCounted = 0;
    State.SecondTimer -= 1;
  }
  GatherInput(State.Input);
  for (int Index = 0; Index < Tick; ++Index) {
    TakeTickCommands(State.Input, State.Commands);
    TickWorld(State.World, State.Commands);
  }
  vec2 Position = Vec2Lerp(State.World.PlayerPrevPosition, State.World.PlayerCurrPosition, LoopAlpha(State.LoopState));
  DrawCircleV(Vector2{ .x = Position.X, .y = Position.Y }, PLAYER_RADIUS, BLUE);
  DrawText(std::to_string(State.TickPerSecond).c_str(), 10, 10, 50, WHITE);
  EndDrawing();
}

int main()
{
  const app_def AppDef = { .TargetFPS = 60 };
  InitApp(&AppDef);

  frame_state State;
  world_def WorldDef = { .Width = GetScreenWidth(), .Height = GetScreenHeight() };
  InitWorld(&WorldDef, State.World);
  State.Commands.reserve(MAX_COMMANDS);
#if defined(PT_PLATFORM_WEB)
  emscripten_set_main_loop_arg(UpdateDrawFrame, &State, 0, true);
#else
  while (!AppShouldClose()) { UpdateDrawFrame(&State); }
#endif

  ShutdownApp();
  return EXIT_SUCCESS;
}
