#include "Fixed.hpp"
#include "Point.hpp"

int main(void) {
    Point const a(2, 2);
    Point const b(7, 2);
    Point const c(4, 5);
    Point const point(4.0, 4.9);         // is inside
    Point const point2(6.1111, 4.2341);  // is outside
    Point const point3(4, 3);            // is inside

    bool result = bsp(a, b, c, point);
    std::cout << "The point point " << (result == true ? "is inside" : "is outside") << " the triangle" << std::endl;

    result = bsp(a, b, c, point2);
    std::cout << "The point point2 " << (result == true ? "is inside" : "is outside") << " the triangle" << std::endl;

    result = bsp(a, b, c, point3);
    std::cout << "The point point3 " << (result == true ? "is inside" : "is outside") << " the triangle" << std::endl;

    result = bsp(Point(0, 0), Point(10, 30), Point(20, 0), Point(0, 2));  // is outside
    std::cout << "The point (0, 2) " << (result == true ? "is inside" : "is outside") << " the triangle" << std::endl;

    return 0;
}
