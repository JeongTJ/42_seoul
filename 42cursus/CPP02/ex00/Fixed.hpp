#pragma once
#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed {
	public:
		Fixed( void );
		~Fixed( void );
		Fixed( const Fixed &fixed );
		Fixed &operator=( const Fixed &fixed );
		int getRawBits( void ) const;
		void setRawBits( int const rawBits );
	private:
		int rawBits;
		short fractionalBits;

};

#endif
