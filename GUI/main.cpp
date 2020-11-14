#include <iostream>

#include "GraphicalScene.hpp"

int main(int ac, char **av)
{
  GraphicalScene scene;

  std::shared_ptr<Object> a = std::make_shared<Object>(Vec2(100.0f, 0.0f), Vec2(.1, 0));
  std::shared_ptr<Object> b = std::make_shared<Object>(Vec2(-100.0f, 0.0f));
  scene.addObject(a);
  scene.addObject(b);

  while (scene.alive())
  {
    scene.step(0.01);
    scene.render();
    std::cout << a->getPosition()._x << std::endl;
  }

  return 0;
}
