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

TEMPLATE_TEST_CASE("Vec substraction", "Vec", float, double)
{
  TVec2<TestType> a(1, 2);
  TVec2<TestType> b(3, 4);

  TVec2<TestType> c = a - b;
  REQUIRE(c._x == TestType(-2));
  REQUIRE(c._y == TestType(-2));
  REQUIRE(a._x == TestType(1));
  REQUIRE(a._y == TestType(2));
  REQUIRE(b._x == TestType(3));
  REQUIRE(b._y == TestType(4));

  TVec2<TestType> d = b - a;
  REQUIRE(d._x == TestType(2));
  REQUIRE(d._y == TestType(2));
  REQUIRE(a._x == TestType(1));
  REQUIRE(a._y == TestType(2));
  REQUIRE(b._x == TestType(3));
  REQUIRE(b._y == TestType(4));

  TVec2<TestType> e = a - c;
  REQUIRE(e._x == TestType(3));
  REQUIRE(e._y == TestType(4));
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

TEMPLATE_TEST_CASE("Norm", "Vec", float, double)
{
  TVec2<TestType> a(0, 2);
  REQUIRE(a.normSquared() == 4);
  REQUIRE(a.norm() == 2);

  TVec2<TestType> b(3, 0);
  REQUIRE(b.normSquared() == 9);
  REQUIRE(b.norm() == 3);

  TVec2<TestType> c(-3, 0);
  REQUIRE(c.normSquared() == 9);
  REQUIRE(c.norm() == 3);

  TVec2<TestType> d(1, 1);
  REQUIRE(d.normSquared() == 2);
  REQUIRE(d.norm() == Approx(1.41421356237));

  TVec2<TestType> e;
  REQUIRE(e.normSquared() == 0);
  REQUIRE(e.norm() == 0);
}

TEMPLATE_TEST_CASE("Normalise", "Vec", float, double)
{
  TVec2<TestType> a(0, 2);
  a.normalise();
  REQUIRE(a._x == 0);
  REQUIRE(a._y == 1);

  TVec2<TestType> b(3, 0);
  b.normalise();
  REQUIRE(b._x == 1);
  REQUIRE(b._y == 0);

  TVec2<TestType> c(-3, 0);
  c.normalise();
  REQUIRE(c._x == -1);
  REQUIRE(c._y == 0);

  TVec2<TestType> d(1, 1);
  d.normalise();
  REQUIRE(d._x == Approx(0.70710678118));
  REQUIRE(d._y == Approx(0.70710678118));

  TVec2<TestType> e;
  e.normalise();
  REQUIRE(e._x == 0);
  REQUIRE(e._y == 0);
}
