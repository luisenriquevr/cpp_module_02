/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvarela <lvarela@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 15:28:51 by lvarela           #+#    #+#             */
/*   Updated: 2023/02/23 20:53:37 by lvarela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <math.h>

class	Fixed {
	private:
		int						_value;
		static const int		_bits = 8;
	public:
		Fixed(void);
		Fixed(const int);
		Fixed(const float);
		Fixed(const Fixed &);
		Fixed &					operator=(const Fixed &);
		~Fixed();
		void					setFixedPointNumber(int const);
		int						getFixedPointNumber(void) const;
		float					toFloat(void) const;
		int						toInt(void) const;
		bool					operator>(const Fixed &) const;
		bool					operator<(const Fixed &) const;
		bool					operator>=(const Fixed &) const;
		bool					operator==(const Fixed &) const;
		bool					operator!=(const Fixed &) const;
		Fixed &					operator+(const Fixed &);
		Fixed &					operator-(const Fixed &);
		Fixed &					operator*(const Fixed &);
		Fixed &					operator/(const Fixed &);
		Fixed &					operator++(void);
		Fixed &					operator--(void);
		Fixed &					operator++(int);
		Fixed &					operator--(int);
		static const Fixed & 	min(const Fixed &, const Fixed &);
		static const Fixed &	max(const Fixed &, const Fixed &);
		static Fixed &			min(Fixed &, Fixed &);
		static Fixed &			max(Fixed &, Fixed &);
};

std::ostream & operator<<(std::ostream &, const Fixed &);

#endif
