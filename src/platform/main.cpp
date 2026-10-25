#include <cstdlib>
#include <iostream>

#include <raylib.h>

#include "app.h"

int main()
{
  std::cout << "PORTOIL!" << "\n";
  const app_def AppDef = {};
  InitApp(&AppDef);

  while (!AppShouldClose()) {
    BeginDrawing();
    ClearBackground(BLACK);
    EndDrawing();
  }

  ShutdownApp();
  return EXIT_SUCCESS;
}
