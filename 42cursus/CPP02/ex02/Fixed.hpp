#pragma once
#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>
# include <iomanip>

class Fixed {
	public:
		Fixed(void );
		Fixed(int const num);
		Fixed(float const num);
		~Fixed(void);
		Fixed(const Fixed &other);

		Fixed &operator=(const Fixed &other);

		bool operator>(const Fixed &other) const;
		bool operator>=(const Fixed &other) const;
		bool operator<(const Fixed &other) const;
		bool operator<=(const Fixed &other) const;
		bool operator==(const Fixed &other) const;
		bool operator!=(const Fixed &other) const;

		Fixed operator+(const Fixed &other) const;
		Fixed operator-(const Fixed &other) const;
		Fixed operator*(const Fixed &other) const;
		Fixed operator/(const Fixed &other) const;

		Fixed &operator++(void);
		Fixed &operator--(void);
		Fixed operator++(int);
		Fixed operator--(int);

		int getRawBits(void) const;
		void setRawBits(int const rawBits);
		float toFloat(void) const;
		int toInt(void) const;

		static Fixed &max(Fixed &a, Fixed &b);
		static const Fixed &max(const Fixed &a, const Fixed &b);
		static Fixed &min(Fixed &a, Fixed &b);
		static const Fixed &min(const Fixed &a, const Fixed &b);
	private:
		short fractionalBits;
		int rawBits;
};

std::ostream &operator<<(std::ostream &ostrm, const Fixed &fixed);

#endif
