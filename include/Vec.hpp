#ifndef VEC_HPP
#define VEC_HPP

#include "precision.hpp"

template <typename T = PRECISION>
struct Vec2
{
  Vec2(T x = 0, T y = 0)
    : _x(x)
    , _y(y)
  {
  }

public:
  T _x = 0;
  T _y = 0;
};

#endif /* VEC_HPP */
