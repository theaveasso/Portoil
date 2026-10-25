#pragma once

template<typename T> T Clamp(T Value, T Min, T Max)
{
  T Result = Value;
  if (Result < Min) { Result = Min; }
  if (Result > Max) { Result = Max; }
  return Result;
}
