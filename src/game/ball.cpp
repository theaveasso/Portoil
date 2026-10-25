#include "ball.h"
#include "pt_math.h"
#include <cmath>

void TickBall(ball &Ball, const bounds &Bounds, float DeltaTime)
{
  Ball.PrevPosition = Ball.CurrPosition;
  Ball.CurrPosition = Vec2Add(Ball.CurrPosition, Vec2Mul(Ball.Velocity, DeltaTime));
  if (Ball.CurrPosition.X - Ball.Radius < Bounds.Left) {
    Ball.CurrPosition.X = Bounds.Left + Ball.Radius;
    Ball.Velocity.X = +std::fabs(Ball.Velocity.X);
  }
  if (Ball.CurrPosition.X + Ball.Radius > Bounds.Right) {
    Ball.CurrPosition.X = Bounds.Right - Ball.Radius;
    Ball.Velocity.X = -std::fabs(Ball.Velocity.X);
  }
  if (Ball.CurrPosition.Y - Ball.Radius < Bounds.Top) {
    Ball.CurrPosition.Y = Bounds.Top + Ball.Radius;
    Ball.Velocity.Y = +std::fabs(Ball.Velocity.Y);
  }
  if (Ball.CurrPosition.Y + Ball.Radius > Bounds.Bottom) {
    Ball.CurrPosition.Y = Bounds.Bottom - Ball.Radius;
    Ball.Velocity.Y = -std::abs(Ball.Velocity.Y);
  }
}

vec2 GetBallRenderPos(const ball &Ball, float Alpha) { return Vec2Lerp(Ball.PrevPosition, Ball.CurrPosition, Alpha); }
