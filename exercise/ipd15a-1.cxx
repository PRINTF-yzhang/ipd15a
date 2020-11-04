#include "ipd15a-1.hxx"

std::ostream&
operator<<(std::ostream& out, Posn p)
{
    return out << "(" << p.x << ", " << p.y << ")";
}

std::ostream&
operator<<(std::ostream& out, Circle my_circle)
{
    return out << "my_circle is "<< "Circle {radius: "<< my_circle.radius << ", center: " << my_circle.center << "}";
}
