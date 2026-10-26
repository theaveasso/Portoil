#pragma once

#include "pt_math.h"

inline bool RectContainsPoint(const rect &Rect, const vec2 &Point)
{ return ((Point.X >= Rect.X) && (Point.X <= Rect.X + Rect.Width)) && ((Point.Y >= Rect.Y) && (Point.Y <= Rect.Y + Rect.Height)); }
