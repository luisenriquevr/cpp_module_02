#include "Fixed.hpp"
#include "Point.hpp"

int main() {
	Point a;
	std::cout << a.getFixedX() << std::endl;
	std::cout << a.getFixedY() << std::endl;
	Point b(a);
	std::cout << b.getFixedX() << std::endl;
	std::cout << b.getFixedY() << std::endl;
	Point c = b;
	std::cout << c.getFixedX() << std::endl;
	std::cout << c.getFixedY() << std::endl;

	return 0;
}