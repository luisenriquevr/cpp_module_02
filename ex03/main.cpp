#include "Fixed.hpp"
#include "Point.hpp"

bool bsp(const Point A, const Point B, const Point C, const Point P);

int main() {

    Point A(float(5), float(3));
    Point B(float(9), float(2));
    Point C(float(2), float(-3));
    Point P(float(8), float(1));

    std::cout << bsp(A, B, C, P) << std::endl;

    return 0;
}