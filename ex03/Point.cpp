#include "Point.hpp"

Point::Point() : _x(0), _y(0) {
    std::cout << "Constructor called" << std::endl;
}

Point::~Point() {
    std::cout << "Destructor called" << std::endl;
}

Point::Point(const Point &toCopy) : _x(toCopy._x), _y(toCopy._y) {
    std::cout << "Copy constructor called" << std::endl;
}

Point::Point(const float x, const float y) : _x(x), _y(y) {
}

Point &Point::operator=(const Point &toCopy) {
    std::cout << "Assignation operator called" << std::endl;
    if (this != &toCopy) {
        (Fixed) this->_x = (Fixed)toCopy._x;
        (Fixed) this->_y = (Fixed)toCopy._y;
    }
    return *this;
}

Fixed Point::getFixedX() const {
    std::cout << "getFixedX called" << std::endl;
    return _x;
}

Fixed Point::getFixedY() const {
    std::cout << "getFixedY called" << std::endl;
    return _y;
}