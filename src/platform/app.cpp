#include "app.h"

#include <cassert>
#include <raylib.h>

constexpr int FPS = 60;

struct app
{
  bool IsInitialized = false;
};

static app &GetApp()
{
  static app App;
  return App;
}

void InitApp(const app_def *Def)
{
  assert(!GetApp().IsInitialized);
  InitWindow(Def->Width, Def->Height, Def->Title);
  SetTargetFPS(FPS);
  GetApp().IsInitialized = true;
}

void ShutdownApp()
{
  if (!GetApp().IsInitialized) { return; }
  CloseWindow();
  GetApp() = {};
}

bool AppShouldClose() { return GetApp().IsInitialized && WindowShouldClose(); }
