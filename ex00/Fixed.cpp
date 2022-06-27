/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvarela <lvarela@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 16:08:33 by lvarela           #+#    #+#             */
/*   Updated: 2022/06/27 16:34:24 by lvarela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/* Constructor, copy constructor, assignation operator overload and destructor */

Fixed::Fixed( void ) : _value(0) {
	std::cout << "Default constructor called" << std::endl;
}

// Copy constructor
Fixed::Fixed( Fixed const &copy) {
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

// Assignation operator overload
Fixed & Fixed::operator=( Fixed const & copy ) {
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