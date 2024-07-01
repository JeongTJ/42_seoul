#pragma once
#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed {
	public:
		Fixed( void );
		Fixed( int const num );
		Fixed( float const num );
		~Fixed( void );
		Fixed( const Fixed &fixed );

		Fixed &operator=( const Fixed &fixed );

		int getRawBits( void ) const;
		void setRawBits( int const rawBits );
		float toFloat( void ) const;
		int toInt( void ) const;
	private:
		int rawBits;
		short fractionalBits;

};

std::ostream &operator<<( std::ostream &ostrm, const Fixed &fixed );

#endif
