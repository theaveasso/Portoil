#include <cstdlib>
#include <iostream>

#include <raylib.h>
#include <string>

#include "app.h"
#include "core/loop.h"

int main()
{
  std::cout << "PORTOIL!" << "\n";
  const app_def AppDef = { .TargetFPS = 60 };
  InitApp(&AppDef);

  loop_state State = {};
  while (!AppShouldClose()) {
    BeginDrawing();
    ClearBackground(BLACK);
    int Tick = LoopAdvance(State, GetFrameTime());
    DrawText(std::to_string(Tick).c_str(), 10, 10, 50, WHITE);
    EndDrawing();
  }

  ShutdownApp();
  return EXIT_SUCCESS;
}
