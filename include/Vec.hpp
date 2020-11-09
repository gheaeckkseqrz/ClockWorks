#ifndef VEC_HPP
#define VEC_HPP

#include "precision.hpp"

template <typename T = PRECISION>
struct TVec2
{
  TVec2(T x = 0, T y = 0)
    : _x(x)
    , _y(y)
  {
  }

  TVec2 &operator+=(TVec2 const &o)
  {
    _x += o._x;
    _y += o._y;
    return *this;
  }

  TVec2 &operator*=(T s)
  {
    _x *= s;
    _y *= s;
    return *this;
  }

public:
  T _x = 0;
  T _y = 0;
};

template <typename T = PRECISION>
inline TVec2<T> operator*(TVec2<T> const &a, T s)
{
  return TVec2<T>(a._x * s, a._y * s);
}

using Vec2 = TVec2<>;

#endif /* VEC_HPP */
