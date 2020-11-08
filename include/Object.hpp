#ifndef OBJECT_HPP
#define OBJECT_HPP

#include "Vec.hpp"
#include "precision.hpp"

template <typename T = PRECISION>
class Object
{
public:
  Object(Vec2<T> const &position = Vec2<T>(), Vec2<T> const &velocity = Vec2<T>())
    : _position(position)
    , _velocity(velocity)
  {
  }

private:
  Vec2<T> _position;
  Vec2<T> _velocity;
};

#endif /* OBJECT_HPP */
