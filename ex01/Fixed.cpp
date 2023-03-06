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

Fixed::Fixed() : _value(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value) : _value(value << _bits) {
    std::cout << "Int constructor called" << std::endl;
}

// Para convertir de float a fixed point:
// - Calculamos el factor de escala multiplicando 1 por 2^_bits (es decir,
//   desplaza 1 _bits bits a la izquierda -> 1 << bits). (1 << 8 = 256 -> 00000001.00000000).
// - Multiplicamos el valor por el factor de escala. (Ej: valor = 2,5; 2,5 es 10,1 en binario;
//   10,1 * 00000001.00000000 = 00000010.10000000; guardamos 000001010000000 en el int
//	 sabiendo que la coma está a 8 bits)
Fixed::Fixed(const float value) : _value(value * roundf(1 << _bits)) {
    std::cout << "Float constructor called" << std::endl;
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

/* Conversion functions */

// Para convertir de fixed point a float:
// - Dividimos el input entre 2^_bits (es decir, dividimos el valor
//   entre el factor de escala -> 1 << bits)
float Fixed::toFloat() const {
    return ((float)this->_value / (float)(1 << this->_bits));
}

int Fixed::toInt() const {
    return (this->_value << this->_bits);
}

std::ostream &operator<<(std::ostream &COUT, const Fixed &fixed) {
    COUT << fixed.toFloat();
    return COUT;
}
