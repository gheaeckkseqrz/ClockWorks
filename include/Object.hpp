#ifndef OBJECT_HPP
#define OBJECT_HPP

#include "Vec.hpp"
#include "precision.hpp"

template <typename T = PRECISION>
class TObject
{
public:
  TObject(TVec2<T> const &position = TVec2<T>(), TVec2<T> const &velocity = TVec2<T>())
    : _position(position)
    , _velocity(velocity)
  {
  }

  void move(TVec2<T> const &d)
  {
    _position += d;
  }

  TVec2<T> const &getPosition() const
  {
    return _position;
  }

  void setPosition(TVec2<T> const &p) const
  {
    _position = p;
  }

  TVec2<T> const &getVelocity() const
  {
    return _velocity;
  }

private:
  TVec2<T> _position;
  TVec2<T> _velocity;
};

using Object = TObject<>;

#endif /* OBJECT_HPP */
