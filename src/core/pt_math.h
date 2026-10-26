#pragma once

#include <cmath>

template<typename T> T Min(T Value1, T Value2) { return Value1 < Value2 ? Value1 : Value2; }

template<typename T> T Max(T Value1, T Value2) { return Value1 > Value2 ? Value1 : Value2; }

template<typename T> T Clamp(T Value, T Min, T Max)
{
  T Result = Value;
  if (Result < Min) { Result = Min; }
  if (Result > Max) { Result = Max; }
  return Result;
}

struct vec2
{
  float X = 0;
  float Y = 0;
};

inline float Lerp(float Value1, float Value2, float Amount) { return Value1 + (Amount * (Value2 - Value1)); }

inline vec2 Vec2Add(const vec2 &Lhs, const vec2 &Rhs) { return vec2{ .X = Lhs.X + Rhs.X, .Y = Lhs.Y + Rhs.Y }; }

inline vec2 Vec2Sub(const vec2 &Lhs, const vec2 &Rhs) { return vec2{ .X = Lhs.X - Rhs.X, .Y = Lhs.Y - Rhs.Y }; }

inline vec2 Vec2Mul(const vec2 &Vec, float Scalar) { return vec2{ .X = Vec.X * Scalar, .Y = Vec.Y * Scalar }; }

inline vec2 Vec2Div(const vec2 &Vec, float Scalar) { return vec2{ .X = Vec.X / Scalar, .Y = Vec.Y / Scalar }; }

inline vec2 Vec2Lerp(const vec2 &Vec1, const vec2 &Vec2, float Amount) { return vec2{ .X = Lerp(Vec1.X, Vec2.X, Amount), .Y = Lerp(Vec1.Y, Vec2.Y, Amount) }; }

inline float Vec2Length(const vec2 &Vec) { return std::sqrt((Vec.X * Vec.X) + (Vec.Y * Vec.Y)); }

inline vec2 Vec2Normalize(const vec2 &Vec)
{
  float Length = Vec2Length(Vec);
  if (Length <= 0) { return vec2{}; }
  return Vec2Div(Vec, Length);
}

struct rect
{
  float X = 0;
  float Y = 0;
  float Width = 0;
  float Height = 0;
};
