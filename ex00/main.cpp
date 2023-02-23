/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvarela <lvarela@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 16:06:38 by lvarela           #+#    #+#             */
/*   Updated: 2023/02/23 20:27:55 by lvarela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int	main( void ) {
	Fixed a;
	Fixed b(a);
	Fixed c;
	
	c = b;
	std::cout << a.getFixedPointNumber() << std::endl;
	std::cout << b.getFixedPointNumber() << std::endl;
	std::cout << c.getFixedPointNumber() << std::endl;
	return 0;
}
