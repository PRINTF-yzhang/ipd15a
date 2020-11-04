#include "ipd15a-1.hxx"

#include <catch.hxx>

#include <sstream>

TEST_CASE("operator<<(std::ostream&, Circle) works")
{
    std::ostringstream oss;
    Circle my_circle{10, {3, 4}};
    oss << my_circle;
    CHECK(oss.str() == "my_circle is Circle {radius: 10, center: (3, 4)}");
}
