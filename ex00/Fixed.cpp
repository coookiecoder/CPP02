#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed() {
	std::cout << "Default constructor called" << std::endl;
	this->FixedPointValue = 0;
}

Fixed::Fixed(Fixed &copy) {
	std::cout << "Copy constructor called" << std::endl;
	this->FixedPointValue = copy.getRawBits();
}

Fixed &Fixed::operator=(const Fixed &copy) {
	std::cout << "Copy assignment operator called" << std::endl;
	this->FixedPointValue = copy.getRawBits();
	return *this;
}

Fixed::~Fixed() {
	std::cout << "Deconstructor called" << std::endl;
}

int Fixed::getRawBits() const {
	std::cout << "getRawBits member function called" << std::endl;
	return this->FixedPointValue;
}

void Fixed::setRawBits(const int raw) {
	this->FixedPointValue = raw;
}