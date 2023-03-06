/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvarela <lvarela@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 16:08:33 by lvarela           #+#    #+#             */
/*   Updated: 2023/03/06 21:04:34 by lvarela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/* Constructor, copy constructor, assignation operator overload and destructor */

// Constructor
Fixed::Fixed() : _value(0) {
    std::cout << "Default constructor called" << std::endl;
}

// Copy constructor
Fixed::Fixed(const Fixed &copy) {
    std::cout << "Copy constructor called" << std::endl;
    *this = copy;
}

// Assignation operator overload
Fixed &Fixed::operator=(const Fixed &copy) {
    std::cout << "Assignation operator called" << std::endl;
    this->_value = copy.getRawBits();
    return *this;
}

// Destructor
Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

/* Setter function */

void Fixed::setRawBits(const int raw) {
    this->_value = raw;
}

/* Getter function */

int Fixed::getRawBits() const {
    std::cout << "getRawBits called" << std::endl;
    return this->_value;
}
