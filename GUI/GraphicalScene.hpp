#pragma once

#include "GUI.hpp"
#include "Scene.hpp"

template <typename T = PRECISION>
class TGraphicalScene : public TScene<T>, private GUI
{
public:
  TGraphicalScene()
  {
    start();
  }

  void render()
  {
    for (std::shared_ptr<TObject<T>> o : TScene<T>::getObjects())
      addPoint(o->getPosition()._x, o->getPosition()._y, 0);
    update();
  }

  bool alive() const
  {
    return GUI::alive();
  }
};

using GraphicalScene = TGraphicalScene<>;
