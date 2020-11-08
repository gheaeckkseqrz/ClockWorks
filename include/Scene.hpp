#ifndef SCENE_HPP
#define SCENE_HPP

#include <memory>
#include <vector>

#include "Object.hpp"
#include "precision.hpp"

template <typename T = PRECISION>
class Scene
{
public:
  Scene() = default;

  void addObject(std::shared_ptr<Object<>> o)
  {
    _objects.push_back(o);
  }

private:
  std::vector<std::shared_ptr<Object<T>>> _objects;
};

#endif /* SCENE_HPP */
