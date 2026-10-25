#include <cstdlib>
#include <iostream>

#include <raylib.h>
#include <string>

#include "app.h"
#include "core/loop.h"
#include "game/ball.h"

struct frame_state
{
  loop_state LoopState = {};
  ball Ball = {};
  int TickCounted = 0;
  int TickPerSecond = 0;
  float SecondTimer = 0;
};

int main()
{
  std::cout << "PORTOIL!" << "\n";
  const app_def AppDef = { .TargetFPS = 60 };
  InitApp(&AppDef);

  frame_state State;
  State.Ball.CurrPosition = { .X = static_cast<float>(GetScreenWidth()) / 2, .Y = static_cast<float>(GetScreenHeight()) / 2 };
  while (!AppShouldClose()) {
    BeginDrawing();
    ClearBackground(BLACK);

    int Tick = LoopAdvance(State.LoopState, GetFrameTime());
    State.TickCounted += Tick;
    State.SecondTimer = GetFrameTime();
    if (State.SecondTimer > 1) {
      State.TickPerSecond = State.TickCounted;
      State.TickCounted = 0;
      State.SecondTimer -= 1;
    }

    const bounds Bounds = { .Left = 0, .Right = static_cast<float>(GetScreenWidth()), .Top = 0, .Bottom = static_cast<float>(GetScreenHeight()) };
    for (int Index = 0; Index < Tick; ++Index) { TickBall(State.Ball, Bounds, FIXED_TIMESTEP); }
    vec2 BallPosition = GetBallRenderPos(State.Ball, LoopAlpha(State.LoopState));
    DrawCircleV(Vector2{ .x = BallPosition.X, .y = BallPosition.Y }, State.Ball.Radius, BLUE);
    DrawText(std::to_string(State.TickPerSecond).c_str(), 10, 10, 50, WHITE);
    EndDrawing();
  }

  ShutdownApp();
  return EXIT_SUCCESS;
}
