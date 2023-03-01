
#ifndef POINT_HPP
# define POINT_HPP

# include <iostream>
# include <math.h>
# include "Fixed.hpp"

class	Point {
	private:
		Fixed const x;
		Fixed const y;

	public:
		Point(void);
		~Point(void);
		Point(const Point &toCopy);
		Point &operator=(const Point &toCopy);
		Fixed	getFixedX(void) const;
		Fixed	getFixedY(void) const;
};


#endif
