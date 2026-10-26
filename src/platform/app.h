#pragma once

struct app_def
{
  int Width = 0;
  int Height = 0;
  const char *Title = nullptr;

  int TargetFPS = 0;
};

void InitApp(const app_def *Def);
void ShutdownApp();
bool AppShouldClose();
