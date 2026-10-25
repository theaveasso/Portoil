#pragma once

constexpr int WINDOW_WIDTH = 1280;
constexpr int WINDOW_HEIGHT = 720;
constexpr const char *APP_TITLE = "Portoil";
constexpr const int TARGET_FPS = 60;

struct app_def
{
  int Width = WINDOW_WIDTH;
  int Height = WINDOW_HEIGHT;
  const char *Title = APP_TITLE;

  int TargetFPS = TARGET_FPS;
};

void InitApp(const app_def *Def);
void ShutdownApp();
bool AppShouldClose();
