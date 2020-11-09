#include <iostream>

#include "Scene.hpp"

int main(int /* ac */, char ** /* av */)
{
  std::cout << "ClockWorks Engine" << std::endl;

  Scene s;

  // Add object at position (0, 0) with no initial velocity (1, 0)
  std::shared_ptr<Object> o = std::make_shared<Object>(Vec2(0.0f, 0.0f), Vec2(1.0f, 0.0f));
  s.addObject(o);
  std::cout << "Object Position " << o->getPosition()._x << " / " << o->getPosition()._y << std::endl;
  s.step(0.1);
  std::cout << "Object Position " << o->getPosition()._x << " / " << o->getPosition()._y << std::endl;

  return 0;
}
