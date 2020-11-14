#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <cmath>
#include <iostream>
#include <mutex>
#include <thread>

struct Item
{
  float x;
  float y;
  unsigned int label;
};

class GUI
{
public:
  GUI()
  {
    _colors.push_back({0, 0, 255});
    _colors.push_back({0, 255, 0});
    _colors.push_back({0, 255, 255});
    _colors.push_back({255, 0, 0});
    _colors.push_back({255, 0, 255});
    _colors.push_back({255, 255, 0});
    _colors.push_back({255, 255, 255});
    _colors.push_back({127, 127, 127});
  }

  virtual ~GUI()
  {
    _thread.join();
  }

  void start()
  {
    _thread = std::thread(&GUI::_start, this);
  }

  void addPoint(double x, double y, unsigned int label)
  {
    Item i;
    i.x = x;
    i.y = y;
    i.label = label;
    _pointsNext.push_back(i);
    while (label >= _colors.size())
      _colors.push_back(sf::Color(rand() % 255, rand() % 255, rand() % 255));
  }

  void update()
  {
    std::scoped_lock lock(_pointActiveM);
    _pointsActive.swap(_pointsNext);
    _pointsNext.clear();
  }

  bool alive() const
  {
    return _alive;
  }

private:
  void _start()
  {
    _window.create(sf::VideoMode(2000, 2000), "My window");
    _alive = true;
    while (_alive)
    {
      sf::Event event;
      while (_window.pollEvent(event))
      {
        // "close requested" event: we close the window
        if (event.type == sf::Event::Closed)
        {
          _alive = false;
          break;
        }
        if (event.type == sf::Event::KeyReleased)
        {
          switch (event.key.code)
          {
          case sf::Keyboard::Q:
            _alive = false;
            break;
          default:
            break;
          }
        }
      }
      _window.clear(sf::Color(10, 10, 10));
      {
        std::scoped_lock lock(_pointActiveM);
        unsigned int x(0);
        for (Item item : _pointsActive)
        {
          item.x += 1000;
          item.y += 1000;
          sf::CircleShape shape(5.f);
          shape.setFillColor(_colors[item.label]);
          shape.setPosition(item.x - 5, item.y - 5);
          _window.draw(shape);
        }
      }
      _window.display();
    }
    std::cout << "Quitting" << std::endl;
  }

private:
  std::vector<Item> _pointsNext;
  std::vector<Item> _pointsActive;
  std::mutex _pointActiveM;
  sf::RenderWindow _window;
  std::thread _thread;
  std::vector<sf::Color> _colors;
  volatile bool _alive;
};
