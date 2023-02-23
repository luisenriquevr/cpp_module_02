/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvarela <lvarela@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 16:08:33 by lvarela           #+#    #+#             */
/*   Updated: 2023/02/23 20:56:58 by lvarela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/* Constructor, copy constructor, assignation operator overload and destructor */

Fixed::Fixed(void) : _value(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value) {
	std::cout << "Int constructor called" <<  std::endl;
	this->_value = value << this->_bits;
}

// En la siguiente función realizamos los siguientes cálculos:
// - Calculamos el factor de escala multiplicando 1 por 2^_bits (es decir,
//   desplaza 1 _bits bits a la izquierda -> 1 << bits). (1 << 8 = 256 -> 00000001.00000000).
// - Multiplicamos el valor por el factor de escala. (Ej: valor = 2,5; 2,5 es 10,1 en binario;
//   10,1 * 00000001.00000000 = 00000010.10000000)
Fixed::Fixed(const float value) {
	std::cout << "Float constructor called" << std::endl;
	this->_value = value * roundf(1 << this->_bits);
}

// Copy constructor
Fixed::Fixed(const Fixed &copy) {
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

// Assignation operator overload
Fixed &	Fixed::operator=(const Fixed & copy) {
	std::cout << "Assignation operator called" << std::endl;
	this->_value = copy.getFixedPointNumber();
	return *this;
}

// Destructor
Fixed::~Fixed(void) {
	std::cout << "Destructor called" << std::endl;
}

/* Setter function */

void	Fixed::setFixedPointNumber(const int raw) {
	this->_value = raw;
}

/* Getter function */

int		Fixed::getFixedPointNumber(void) const {
	std::cout << "getFixedPointNumber called" << std::endl;
	return this->_value;
}

/* Conversion functions */

// En la siguiente funciónse realizan los siguientes cálculos:
// - Dividimos el input entre 2^_bits (es decir, dividimos el valor
//   entre el factor de escala -> 1 << bits)
float	Fixed::toFloat(void) const {
	return ((double)this->_value / (double)(1 << this->_bits));
}

int		Fixed::toInt(void) const {
	return (this->_value << this->_bits);
}

std::ostream & operator<<(std::ostream & out, const Fixed & value) {
	out << value.toFloat();
	return out;
}
