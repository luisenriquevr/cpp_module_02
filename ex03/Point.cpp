#include "Point.hpp"

Point::Point(void) : x(0), y(0) {
	std::cout << "Constructor called" << std::endl;
}

Point::~Point(void) {
	std::cout << "Destructor called" << std::endl;
}

Point::Point(const Point &toCopy) : x(toCopy.x), y(toCopy.y) {
	std::cout << "Copy constructor called" << std::endl;
}

Point &	Point::operator=(const Point &toCopy) {
	std::cout << "Assignation operator called" << std::endl;
	return *toCopy;
}

Fixed	Point::getFixedX(void) const {
	std::cout << "getFixedX called" << std::endl;
	return x;
}

Fixed	Point::getFixedY(void) const {
	std::cout << "getFixedY called" << std::endl;
	return y;
}