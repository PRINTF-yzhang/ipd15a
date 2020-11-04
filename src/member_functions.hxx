#pragma once

#include <iostream>

// Represents a point on the 2-D Euclidean plane.
struct Posn
{
    using coordinate_type = double;

    coordinate_type x, y;

    // The origin
    static const Posn the_origin;

    // Computes the distance between two `Posn`s
    double distance_to(Posn other) const;
};

// Represents a circle on the 2-D Euclidean plane.
struct Circle
{
    double radius;
    Posn center;

    // Computes the area of this circle.
    double area() const;

    // Determines whether two circles overlap.
    bool overlaps(Circle other) const;

    // Returns a circle centered at the origin with the given radius.
    static Circle at_origin(double radius);

    void scale_by(double factor);

    bool operator==(Circle other) const;
};

// Stream insertion for `Posn`.
std::ostream&
operator<<(std::ostream& out, Posn p);
