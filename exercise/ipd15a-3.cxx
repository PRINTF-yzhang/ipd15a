#include <member_functions.hxx>

#include <catch.hxx>

void
Circle::scale_by(double factor)
{
    radius = radius *factor;
}

bool
Circle::operator==(Circle other) const
{
    return (radius == other.radius) &&(center.x == other.center.x) &&(center.y == other.center.y);
}



TEST_CASE("scale circle by 4")
{
    Posn   center{100, -6};
    Circle actual{5, center},
           expected{20, center};

     CHECK_FALSE(actual == expected);

     actual.scale_by(4.0);

     CHECK(actual == expected);
}

TEST_CASE("scale circle by 0.5")
{
    Posn   center{-100, -6.2};
    Circle actual{8, center},
           expected{4, center};

     CHECK_FALSE(actual == expected);

     actual.scale_by(0.5);

     CHECK(actual == expected);
}

TEST_CASE("Circle::operator==(Circle) const works")
{
    Posn p1{2, 3}, p2{9, 4};
    double r1{10}, r2{50};

     SECTION("equal circles") {
         CHECK(Circle{r1, p1} == Circle{r1, p1});
         CHECK(Circle{r2, p1} == Circle{r2, p1});
         CHECK(Circle{r1, p2} == Circle{r1, p2});
         CHECK(Circle{r2, p2} == Circle{r2, p2});
     }

     SECTION("unequal circles") {
         CHECK_FALSE(Circle{r1, p1} == Circle{r1, p2});
         CHECK_FALSE(Circle{r1, p1} == Circle{r2, p1});
         CHECK_FALSE(Circle{r1, p1} == Circle{r2, p2});
         CHECK_FALSE(Circle{r1, p2} == Circle{r1, p1});
         CHECK_FALSE(Circle{r1, p2} == Circle{r2, p1});
         CHECK_FALSE(Circle{r1, p2} == Circle{r2, p2});
         CHECK_FALSE(Circle{r2, p1} == Circle{r1, p1});
         CHECK_FALSE(Circle{r2, p1} == Circle{r1, p2});
         CHECK_FALSE(Circle{r2, p1} == Circle{r2, p2});
         CHECK_FALSE(Circle{r2, p2} == Circle{r1, p1});
         CHECK_FALSE(Circle{r2, p2} == Circle{r1, p2});
         CHECK_FALSE(Circle{r2, p2} == Circle{r2, p1});
     }
}

/*
 * 15.a.4
 * Static member
 *
 * a variable that's just once for all
 *
 * Static member function: A static member function can be called even if no objects of the class
 * exist and the static functions are accessed using only the class name and the scope resolution
 * operator ::
 *
 * Static member type
 * Static member variable(data)
 *
 * use the struct:: to refer to static things
 */
