#include <iostream>

#include "Scene.hpp"

int main(int /* ac */, char ** /* av */)
{
  std::cout << "ClockWorks Engine" << std::endl;

  Scene<> s;

  // Add object at position 0, 10 with no initial velocity
  std::shared_ptr<Object<>> o = std::make_shared<Object<>>(Vec2(0.0f, 10.0f));
  s.addObject(o);

  return 0;
}
