#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "Scene.hpp"

TEMPLATE_TEST_CASE("Vec constructor", "Scene", float, double)
{
  // Default contructor
  TScene<TestType> s;
}

TEST_CASE("Vec constructor", "Basic stepping")
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
