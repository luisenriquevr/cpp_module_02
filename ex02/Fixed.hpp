/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvarela <lvarela@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 15:28:51 by lvarela           #+#    #+#             */
/*   Updated: 2023/02/27 19:33:27 by lvarela          ###   ########.fr       */
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
		Fixed(const Fixed &toCopy);
		Fixed &					operator=(const Fixed &toCopy);
		~Fixed();

		void					setRawBits(int const raw);
		int						getRawBits(void) const;
		float					toFloat(void) const;
		int						toInt(void) const;

		bool					operator>(const Fixed &toCompare) const;
		bool					operator<(const Fixed &toCompare) const;
		bool					operator>=(const Fixed &toCompare) const;
		bool					operator<=(const Fixed &toCompare) const;
		bool					operator==(const Fixed &toCompare) const;
		bool					operator!=(const Fixed &toCompare) const;

		Fixed &					operator+(const Fixed &toOperate);
		Fixed &					operator-(const Fixed &toOperate);
		Fixed &					operator*(const Fixed &toOperate);
		Fixed &					operator/(const Fixed &toOperate);

		Fixed &					operator++(void);
		Fixed &					operator--(void);
		Fixed &					operator++(int);
		Fixed &					operator--(int);

		static const Fixed & 	min(const Fixed &, const Fixed &);
		static const Fixed &	max(const Fixed &, const Fixed &);
		static Fixed &			min(Fixed &, Fixed &);
		static Fixed &			max(Fixed &, Fixed &);
};

std::ostream & operator<<(std::ostream &COUT, const Fixed &fixed);

#endif
