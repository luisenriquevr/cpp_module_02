/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvarela <lvarela@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 15:28:51 by lvarela           #+#    #+#             */
/*   Updated: 2023/04/06 16:06:33 by lvarela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

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
};

std::ostream &operator<<(std::ostream &COUT, const Fixed &fixed);

#endif
