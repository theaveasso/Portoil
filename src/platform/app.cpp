#include "app.h"

#include <cassert>
#include <raylib.h>

struct app
{ bool IsInitialized = false; };

static app &GetApp()
{
  static app App;
  return App;
}

void InitApp(const app_def *Def)
{
  assert(!GetApp().IsInitialized);
  SetConfigFlags(FLAG_WINDOW_RESIZABLE);
  InitWindow(Def->Width, Def->Height, Def->Title);

#if not defined(PT_PLATFORM_WEB)
  SetTargetFPS(Def->TargetFPS);
#endif
  GetApp().IsInitialized = true;
}

void ShutdownApp()
{
  if (!GetApp().IsInitialized) { return; }
  CloseWindow();
  GetApp() = {};
}

bool AppShouldClose() { return GetApp().IsInitialized && WindowShouldClose(); }
