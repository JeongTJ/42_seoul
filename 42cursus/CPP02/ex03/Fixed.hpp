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

		bool operator>( const Fixed &fixed ) const;
		bool operator>=( const Fixed &fixed ) const;
		bool operator<( const Fixed &fixed ) const;
		bool operator<=( const Fixed &fixed ) const;
		bool operator==( const Fixed &fixed ) const;
		bool operator!=( const Fixed &fixed ) const;

		Fixed operator+( const Fixed &fixed ) const;
		Fixed operator-( const Fixed &fixed ) const;
		Fixed operator*( const Fixed &fixed ) const;
		Fixed operator/( const Fixed &fixed ) const;

		Fixed &operator++( void );
		Fixed &operator--( void );
		Fixed operator++( int );
		Fixed operator--( int );

		Fixed operator-( void );

		int getRawBits( void ) const;
		void setRawBits( int const rawBits );
		float toFloat( void ) const;
		int toInt( void ) const;

		static Fixed &max( Fixed &a, Fixed &b );
		static const Fixed &max( const Fixed &a, const Fixed &b );
		static Fixed &min( Fixed &a, Fixed &b );
		static const Fixed &min( const Fixed &a, const Fixed &b );
		static const Fixed absF( const Fixed &a );
	private:
		int rawBits;
		short fractionalBits;
};

std::ostream &operator<<( std::ostream &ostrm, const Fixed &fixed );

#endif
