#include "Point.hpp"

Point::Point() : _x(0), _y(0) {
    //std::cout << "Constructor called" << std::endl;
}

Point::~Point() {
    //std::cout << "Destructor called" << std::endl;
}

Point::Point(const Point &toCopy) : _x(toCopy.getFixedX()), _y(toCopy.getFixedY()) {
    //std::cout << "Copy constructor called" << std::endl;
}

Point::Point(const float x, const float y) : _x(x), _y(y) {
    //std::cout << "Float constructor called" << std::endl;
}

Point &Point::operator=(const Point &toCopy) {
    //std::cout << "Assignation operator called" << std::endl;
    if (this != &toCopy) {
        (Fixed) this->_x = (Fixed)toCopy._x;
        (Fixed) this->_y = (Fixed)toCopy._y;
    }
    return *this;
}

Fixed Point::getFixedX() const {
    //std::cout << "getFixedX called" << std::endl;
    return this->_x;
}

Fixed Point::getFixedY() const {
    //std::cout << "getFixedY called" << std::endl;
    return this->_y;
}

std::ostream    &operator<<(std::ostream &COUT, const Point &point) {
    COUT << "(" << point.getFixedX().toFloat() << ", " << point.getFixedY().toFloat() << ")";
    return COUT;
}