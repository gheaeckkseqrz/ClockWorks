#ifndef SCENE_HPP
#define SCENE_HPP

#include <memory>
#include <vector>

#include "Object.hpp"
#include "precision.hpp"

template <typename T = PRECISION>
class TScene
{
public:
  TScene() = default;

  void addObject(std::shared_ptr<TObject<>> o)
  {
    _objects.push_back(o);
  }

  void step(float dt)
  {
    for (std::shared_ptr<TObject<T>> const &o : _objects)
    {
      o->move(o->getVelocity() * dt);
    }
  }

private:
  std::vector<std::shared_ptr<TObject<T>>> _objects;
};

using Scene = TScene<>;

#endif /* SCENE_HPP */
