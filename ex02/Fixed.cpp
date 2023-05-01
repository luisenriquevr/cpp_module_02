/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvarela <lvarela@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 16:08:33 by lvarela           #+#    #+#             */
/*   Updated: 2023/05/01 15:04:16 by lvarela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _value(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value) : _value(value << _bits) {
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float value) : _value(roundf(value * (1 << _bits))) {
    std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &copy) {
    std::cout << "Copy constructor called" << std::endl;
    *this = copy;
}

Fixed &Fixed::operator=(const Fixed &copy) {
    std::cout << "Assignation operator called" << std::endl;
    this->_value = copy.getRawBits();
    return *this;
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

void Fixed::setRawBits(const int raw) {
    this->_value = raw;
}

int Fixed::getRawBits() const {
    std::cout << "getRawBits called" << std::endl;
    return this->_value;
}

float Fixed::toFloat() const {
    return ((float)(this->_value / (float)(1 << this->_bits)));
}

int Fixed::toInt() const {
    return (this->_value << this->_bits);
}

bool Fixed::operator>(const Fixed &toCompare) const {
    return this->getRawBits() > toCompare.getRawBits();
}

bool Fixed::operator<(const Fixed &toCompare) const {
    return this->getRawBits() < toCompare.getRawBits();
}

bool Fixed::operator>=(const Fixed &toCompare) const {
    return this->getRawBits() >= toCompare.getRawBits();
}

bool Fixed::operator<=(const Fixed &toCompare) const {
    return this->getRawBits() <= toCompare.getRawBits();
}

bool Fixed::operator==(const Fixed &toCompare) const {
    return this->getRawBits() == toCompare.getRawBits();
}

bool Fixed::operator!=(const Fixed &toCompare) const {
    return this->getRawBits() != toCompare.getRawBits();
}

Fixed Fixed::operator+(const Fixed &toOperate) {
    return Fixed(this->toFloat() + toOperate.toFloat());
}

Fixed Fixed::operator-(const Fixed &toOperate) {
    return Fixed(this->toFloat() - toOperate.toFloat());
}

Fixed Fixed::operator*(const Fixed &toOperate) {
    return Fixed(this->toFloat() * toOperate.toFloat());
}

Fixed Fixed::operator/(const Fixed &toOperate) {
    return Fixed(this->toFloat() / toOperate.toFloat());
}

Fixed &Fixed::operator++() {
    ++this->_value;
    return *this;
}

Fixed Fixed::operator++(int) {
    Fixed tmp(*this);
    tmp._value = this->_value++;
    return tmp;
}

Fixed &Fixed::operator--() {
    --this->_value;
    return *this;
}

Fixed Fixed::operator--(int) {
    Fixed tmp(*this);
    tmp._value = this->_value--;
    return tmp;
}

const Fixed Fixed::min(const Fixed &a, const Fixed &b) {
    return a < b ? a : b;
}

const Fixed Fixed::max(const Fixed &a, const Fixed &b) {
    return a > b ? a : b;
}

Fixed Fixed::min(Fixed &a, Fixed &b) {
    return a < b ? a : b;
}

Fixed Fixed::max(Fixed &a, Fixed &b) {
    return a > b ? a : b;
}

std::ostream    &operator<<(std::ostream &COUT, const Fixed &fixed) {
    COUT << fixed.toFloat();
    return COUT;
}
