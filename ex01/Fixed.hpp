/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvarela <lvarela@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 15:28:51 by lvarela           #+#    #+#             */
/*   Updated: 2022/06/27 21:41:20 by lvarela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <math.h>

class	Fixed {
	private:
		int					_value;
		static const int	_fractionalBits = 8;
	public:
		Fixed( void );
		Fixed( const int );
		Fixed( const float );
		Fixed( const Fixed & );
		Fixed & operator=( const Fixed & );
		~Fixed();
		void				setRawBits( int const );
		int					getRawBits( void ) const;
		float				toFloat( void ) const;
		int					toInt( void ) const;
};

std::ostream & operator<<( std::ostream &, const Fixed & );

#endif