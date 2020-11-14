#include <iostream>

#include "GUI.h"

int main(int ac, char **av)
{
  GUI ui;
  ui.start();

  ui.addPoint(-10, 0, 0);
  ui.addPoint(10, 0, 0);
  ui.update();

  return 0;
}
