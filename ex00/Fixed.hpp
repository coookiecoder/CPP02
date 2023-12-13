#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed
{
	private:
		int	FixedPointValue;
		static const int FractionalBits = 8;
	public:
		Fixed(void);
		~Fixed(void);
		Fixed(Fixed &copy);
		Fixed &operator=(const Fixed &copy);
		int	getRawBits(void) const;
		void setRawBits(int const raw);
};

#endif