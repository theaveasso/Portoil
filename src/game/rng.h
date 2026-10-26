#pragma once

#include <cstdint>

struct rng
{ uint32_t State = 1; };

constexpr inline uint32_t RngNext(rng &Rng)
{
  Rng.State ^= Rng.State << 13U;
  Rng.State ^= Rng.State >> 17U;
  Rng.State ^= Rng.State << 5U;
  return Rng.State;
}

constexpr inline float RngFloat(rng &Rng) { return static_cast<float>((RngNext(Rng) >> 8U)) * (1.F / 16777216.F); }
