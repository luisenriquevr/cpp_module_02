/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvarela <lvarela@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 16:08:33 by lvarela           #+#    #+#             */
/*   Updated: 2022/06/27 22:13:18 by lvarela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/* Constructor, copy constructor, assignation operator overload and destructor */

Fixed::Fixed( void ) : _value(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( const int value ) {
	std::cout << "Int constructor called" <<  std::endl;
	this->_value = value << this->_fractionalBits;
}

Fixed::Fixed( const float value ) {
	std::cout << "Float constructor called" << std::endl;
	this->_value = value * roundf(1 << this->_fractionalBits);
}

// Copy constructor
Fixed::Fixed( const Fixed &copy) {
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

// Assignation operator overload
Fixed & Fixed::operator=( const Fixed & copy ) {
	std::cout << "Assignation operator called" << std::endl;
	this->_value = copy.getRawBits();
	return *this;
}

Fixed::~Fixed( void ) {
	std::cout << "Destructor called" << std::endl;
}

/* Setter function */

void	Fixed::setRawBits( const int raw ) {
	this->_value = raw;
}

/* Getter function */

int		Fixed::getRawBits( void ) const {
	std::cout << "getRawBits called" << std::endl;
	return this->_value;
}

/* Conversion functions */

// Converting from fixed-point to floating-point is
// straightforward. We take the input value and divide it by 
// (2^fractional_bits), putting the result into a double

// pow(2, this->_frac) == 1 << this->_frac
float	Fixed::toFloat( void ) const {
	return ((double)this->_value / (double)(1 << this->_fractionalBits));
}

int		Fixed::toInt( void ) const {
	return (this->_value << this->_fractionalBits);
}

std::ostream & operator<<( std::ostream & out, const Fixed & value ) {
	out << value.toFloat();
	return out;
}
