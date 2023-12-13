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
};

std::ostream &operator<<(std::ostream &o, Fixed const &i);

#endif