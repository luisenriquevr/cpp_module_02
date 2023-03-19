
#ifndef POINT_HPP
#define POINT_HPP

#include <math.h>

#include <iostream>

#include "Fixed.hpp"

class Point {
   private:
    const Fixed _x;
    const Fixed _y;

   public:
    Point();
    ~Point();
    Point(const Point &toCopy);
    Point(const float x, const float y);
    Point &operator=(const Point &toCopy);
    Fixed getFixedX() const;
    Fixed getFixedY() const;
};

std::ostream &operator<<(std::ostream &COUT, const Point &point);

bool bsp(const Point A, const Point B, const Point C, const Point P);

#endif
