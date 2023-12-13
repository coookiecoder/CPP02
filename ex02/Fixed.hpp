#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
	private:
		int	FixedPointValue;
		static const int FractionalBits = 8;
	public:
		Fixed(const int value);
		Fixed(const float value);
		Fixed(void);
		~Fixed(void);
		Fixed(const Fixed &copy);
		Fixed &operator=(const Fixed &copy);
		int	getRawBits(void) const;
		void setRawBits(int const raw);
		float toFloat(void) const;
		int toInt(void) const;
		bool operator>(Fixed const &b) const ;
		bool operator<(Fixed const &b) const ;
		bool operator>=(Fixed const &b) const ;
		bool operator<=(Fixed const &b) const ;
		bool operator==(Fixed const &b) const ;
		bool operator!=(Fixed const &b) const ;
		Fixed operator+(Fixed const &b) const ;
		Fixed operator-(Fixed const &b) const ;
		Fixed operator*(Fixed const &b) const ;
		Fixed operator/(Fixed const &b) const ;
		Fixed &operator++(void);
		Fixed operator++(int);
		Fixed &operator--(void);
		Fixed operator--(int);
		static Fixed &max(Fixed &a, Fixed &b);
		static const Fixed &max(const Fixed &a, const Fixed &b);
		static Fixed &min(Fixed &a, Fixed &b);
		static const Fixed &min(const Fixed &a, const Fixed &b);
};

std::ostream &operator<<(std::ostream &output, Fixed const &input);

#endif