#include "member_functions.hxx"

#include <catch.hxx>
#define _USE_MATH_DEFINES
#include <cmath>
#include <math.h>
# define M_PI           3.14159265358979323846  /* pi */
#include <sstream>

TEST_CASE("Posn::the_origin is the origin")
{
    CHECK(Posn::the_origin.x == 0);
    CHECK(Posn::the_origin.y == 0);
}

TEST_CASE("Posn stream insertion works")
{
    std::ostringstream oss;
    Posn p{3, 4};

    oss << p;

    CHECK(oss.str() == "(3, 4)");
}

TEST_CASE("Area of circle works")
{
    const Circle unit_circle{1, {5, 100}};
    const Circle other_circle{3, {5, 100}};

    CHECK(unit_circle.area() == Catch::Approx(M_PI));
    CHECK(other_circle.area() == Catch::Approx(9 * M_PI));
}

TEST_CASE("Circle::overlapped(Circle)")
{
    const Circle
            c1{5, {0, 0}},
            c2{5, {1, 2}},
            c3{5, {100, 100}};

    CHECK(c1.overlaps(c2));
    CHECK(c2.overlaps(c1));
    CHECK_FALSE(c1.overlaps(c3));
    CHECK_FALSE(c3.overlaps(c1));
    CHECK_FALSE(c2.overlaps(c3));
    CHECK_FALSE(c3.overlaps(c2));
}

TEST_CASE("Circle::at_origin(double)")
{
    Circle c = Circle::at_origin(8);
    CHECK( c.center.x == 0 );
    CHECK( c.center.y == 0 );
    CHECK( c.radius == 8 );
}
