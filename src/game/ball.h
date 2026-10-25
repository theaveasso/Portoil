#pragma once

#include "pt_math.h"

constexpr float DEFAULT_BALL_RADIUS = 20;

struct bounds
{
  float Left = 0, Right = 0;
  float Top = 0, Bottom = 0;
};

struct ball
{
  vec2 PrevPosition;
  vec2 CurrPosition;
  vec2 Velocity = vec2{ .X = 100, .Y = 100 };
  float Radius = DEFAULT_BALL_RADIUS;
};

void TickBall(ball &Ball, const bounds &Bounds, float DeltaTime);
vec2 GetBallRenderPos(const ball &Ball, float Alpha);
