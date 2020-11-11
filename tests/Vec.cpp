#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "Vec.hpp"

TEMPLATE_TEST_CASE("Vec constructor", "Vec", float, double)
{
  // Default contructor
  TVec2<TestType> a;
  REQUIRE(a._x == TestType(0));
  REQUIRE(a._y == TestType(0));

  // Positive Values
  TVec2<TestType> b(1, 2);
  REQUIRE(b._x == TestType(1));
  REQUIRE(b._y == TestType(2));

  // Negative Values
  TVec2<TestType> c(-1, 2);
  REQUIRE(c._x == TestType(-1));
  REQUIRE(c._y == TestType(2));

  // Decimal Values & large values
  TVec2<TestType> d(3.1415, 200000);
  REQUIRE(d._x == Approx(TestType(3.1415)));
  REQUIRE(d._y == TestType(200000));

  // Zero
  TVec2<TestType> e(0, -0);
  REQUIRE(e._x == TestType(0));
  REQUIRE(e._y == TestType(0));
}

TEMPLATE_TEST_CASE("Vec addition", "Vec", float, double)
{
  TVec2<TestType> a(1, 2);
  TVec2<TestType> b(3, 4);

  a += b;
  REQUIRE(a._x == TestType(4));
  REQUIRE(a._y == TestType(6));
  REQUIRE(b._x == TestType(3));
  REQUIRE(b._y == TestType(4));

  b += a;
  REQUIRE(a._x == TestType(4));
  REQUIRE(a._y == TestType(6));
  REQUIRE(b._x == TestType(7));
  REQUIRE(b._y == TestType(10));
}

TEMPLATE_TEST_CASE("Vec multiplication", "Vec", float, double)
{
  // Positive Values
  TVec2<TestType> b(1, 2);
  b *= 10;
  REQUIRE(b._x == TestType(10));
  REQUIRE(b._y == TestType(20));

  // Negative Values
  TVec2<TestType> c(-1, 2);
  c *= 10;
  REQUIRE(c._x == TestType(-10));
  REQUIRE(c._y == TestType(20));
  c *= -2;
  REQUIRE(c._x == TestType(20));
  REQUIRE(c._y == TestType(-40));

  // Decimal Values & large values
  TVec2<TestType> d(3.1415, 200000);
  d *= 10;
  REQUIRE(d._x == Approx(TestType(31.415)));
  REQUIRE(d._y == TestType(2000000));

  // Zero vector
  TVec2<TestType> e(0, -0);
  e *= 10;
  REQUIRE(e._x == TestType(0));
  REQUIRE(e._y == TestType(0));

  // Zero scalar
  TVec2<TestType> f(1.234, -2);
  f *= 0;
  REQUIRE(f._x == TestType(0));
  REQUIRE(f._y == TestType(0));
}
