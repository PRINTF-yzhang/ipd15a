#include "member_functions.hxx"
#include <cmath>
# define M_PI           3.14159265358979323846  /* pi */


const Posn Posn::the_origin{0, 0};

double
Posn::distance_to(Posn other) const
{
    double dx = x - other.x;
    double dy = y - other.y;
    return std::sqrt(dx * dx + dy * dy);
}

std::ostream&
operator<<(std::ostream& out, Posn p)
{
    out << "(" << p.x << ", " << p.y << ")";
    return out;
}

double
Circle::area() const
{
    return radius * radius * M_PI;
}

bool
Circle::overlaps(Circle other) const
{
    return radius + other.radius > center.distance_to(other.center);
}

Circle
Circle::at_origin(double radius)
{
    return Circle{radius, Posn::the_origin};
}

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


