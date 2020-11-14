#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "Scene.hpp"

TEMPLATE_TEST_CASE("Vec constructor", "Scene", float, double)
{
  // Default contructor
  TScene<TestType> s;
}

TEST_CASE("Object Management", "Scene")
{
  Scene s;
  REQUIRE(s.getObjects().size() == 0);
  std::shared_ptr<Object> a = std::make_shared<Object>(Vec2(0.0f, 0.0f), Vec2(1.0f, 0.0f));
  s.addObject(a);
  REQUIRE(s.getObjects().size() == 1);
  std::shared_ptr<Object> b = std::make_shared<Object>(Vec2(0.0f, 0.0f), Vec2(1.0f, 0.0f));
  s.addObject(b);
  REQUIRE(s.getObjects().size() == 2);
  std::shared_ptr<Object> c = std::make_shared<Object>(Vec2(0.0f, 0.0f), Vec2(1.0f, 0.0f));
  s.addObject(c);
  REQUIRE(s.getObjects().size() == 3);
}

TEST_CASE("Basic Stepping", "Scene")
{
  Scene s;
  std::shared_ptr<Object> o = std::make_shared<Object>(Vec2(0.0f, 0.0f), Vec2(1.0f, 0.0f));
  s.addObject(o);
  REQUIRE(o->getPosition()._x == 0.0f);
  REQUIRE(o->getPosition()._y == 0.0f);
  s.step(0.1);
  REQUIRE(o->getPosition()._x == 0.1f);
  REQUIRE(o->getPosition()._y == 0.0f);
}
