#ifndef OBJECT_HPP
#define OBJECT_HPP

#include "Vec.hpp"
#include "precision.hpp"

template <typename T = PRECISION>
class Object
{
public:
  Object() = default;

private:
  Vec2<T> _position;
  Vec2<T> _velocity;
};

#endif /* OBJECT_HPP */
