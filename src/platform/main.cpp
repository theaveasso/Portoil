#include <cstdlib>

#include <raylib.h>
#include <vector>

#include "app.h"
#include "command.h"
#include "entity.h"
#include "input.h"
#include "loop.h"
#include "pt_math.h"
#include "world.h"

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

static Camera2D ArenaCamera()
{
  Camera2D Result = {};
  Result.zoom = Min(static_cast<float>(GetScreenWidth()) / ARENA_WIDTH, static_cast<float>(GetScreenHeight()) / ARENA_HEIGHT);
  Result.offset = {
    .x = (static_cast<float>(GetScreenWidth()) - (ARENA_WIDTH * Result.zoom)) / 2,
    .y = (static_cast<float>(GetScreenHeight()) - (ARENA_HEIGHT * Result.zoom)) / 2,
  };
  return Result;
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
  entity &Player = State.World.Entities[State.World.PlayerIndex];
  vec2 Position = Vec2Lerp(Player.Transform.PrevPosition, Player.Transform.CurrPosition, LoopAlpha(State.LoopState));

  BeginMode2D(ArenaCamera());
  DrawRectangleLines(0, 0, ARENA_WIDTH, ARENA_HEIGHT, GRAY);
  DrawCircleV(Vector2{ .x = Position.X, .y = Position.Y }, Player.Transform.Radius, BLUE);
  EndMode2D();
  EndDrawing();
}

int main()
{
  const app_def AppDef = { .TargetFPS = 60 };
  InitApp(&AppDef);

  frame_state State;
  world_def WorldDef = { .Width = ARENA_WIDTH, .Height = ARENA_HEIGHT };
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
