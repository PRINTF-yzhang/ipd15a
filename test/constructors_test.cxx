#include "constructors.hxx"

#include <catch.hxx>
# define M_PI           3.14159265358979323846  /* pi */
#include <cmath>
#include <stdexcept>


TEST_CASE("Default construct a Posn")
{
    Posn origin;
    CHECK( origin.x == 0 );
    CHECK( origin.y == 0 );
}

TEST_CASE("Circle::area() const")
{
    Posn   questionable;
    Circle less_questionable{1, questionable};

    CHECK(less_questionable.area() == M_PI);
}

TEST_CASE("Circle::Circle throws given bad radius")
{
    CHECK_THROWS_AS(Circle(-4, 0, 9), std::invalid_argument);
    CHECK_THROWS_AS(Circle(0, 0, 9), std::invalid_argument);
    CHECK_THROWS_AS(Circle(NAN, {0, 9}), std::invalid_argument);
}

TEST_CASE("Circle::Circle throws given bad posn")
{
    CHECK_THROWS_AS(Circle(4, {0, NAN}), std::invalid_argument);
}
