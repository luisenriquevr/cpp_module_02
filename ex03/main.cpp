#include "Fixed.hpp"
#include "Point.hpp"

int main( void ) {

    Point const a(1, 1);
    Point const b(6, 1);
    Point const c(3, 4);
    Point const point(3.25, 2.8764);    //inside
    Point const point2(7.0005, 2.8764); //outside
    Point const point3(3, 4);           //outside

    bool result = bsp(a, b, c, point);
    std::cout << "The point is in the triangle: " << result << std::endl;
    result = bsp(a, b, c, point2);
    std::cout << "The point is in the triangle: " << result << std::endl;
    result = bsp(a, b, c, point3);
    std::cout << "The point is in the triangle: " << result << std::endl;

    result = bsp( Point(0, 0), Point(10, 30), Point(20, 0), Point(10, 10) ); //inside
    std::cout << "The point is in the triangle: " << result << std::endl;
    
    return 0;
    
}