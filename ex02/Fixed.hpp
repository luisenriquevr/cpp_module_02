/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvarela <lvarela@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 15:28:51 by lvarela           #+#    #+#             */
/*   Updated: 2023/03/06 21:04:34 by lvarela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <math.h>

#include <iostream>

class Fixed {
   private:
    int _value;
    static const int _bits = 8;

   public:
    Fixed();
    Fixed(const int);
    Fixed(const float);
    Fixed(const Fixed &toCopy);
    Fixed &operator=(const Fixed &toCopy);
    ~Fixed();

    void setRawBits(int const raw);
    int getRawBits() const;
    float toFloat() const;
    int toInt() const;

    bool operator>(const Fixed &toCompare) const;
    bool operator<(const Fixed &toCompare) const;
    bool operator>=(const Fixed &toCompare) const;
    bool operator<=(const Fixed &toCompare) const;
    bool operator==(const Fixed &toCompare) const;
    bool operator!=(const Fixed &toCompare) const;

    Fixed operator+(const Fixed &toOperate);
    Fixed operator-(const Fixed &toOperate);
    Fixed operator*(const Fixed &toOperate);
    Fixed operator/(const Fixed &toOperate);

    Fixed &operator++();
    Fixed operator++(int);
    Fixed &operator--();
    Fixed operator--(int);

    static const Fixed min(const Fixed &a, const Fixed &b);
    static const Fixed max(const Fixed &a, const Fixed &b);
    static Fixed min(Fixed &a, Fixed &b);
    static Fixed max(Fixed &a, Fixed &b);
};

std::ostream &operator<<(std::ostream &COUT, const Fixed &fixed);

#endif
