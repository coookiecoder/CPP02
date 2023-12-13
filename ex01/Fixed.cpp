#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed(const int value) {
	std::cout << "Int constructor called" << std::endl;
	this->FixedPointValue = value << this->FractionalBits;
}

Fixed::Fixed(const float value) {
	std::cout << "Float constructor called" << std::endl;
	this->FixedPointValue = roundf(value * (1 << this->FractionalBits));
}

Fixed::Fixed() {
	std::cout << "Default constructor called" << std::endl;
	this->FixedPointValue = 0;
}

Fixed::Fixed(const Fixed &copy) {
	std::cout << "Copy constructor called" << std::endl;
	this->FixedPointValue = copy.getRawBits();
}

Fixed &Fixed::operator=(const Fixed &copy) {
	std::cout << "Copy assignment operator called" << std::endl;
	this->FixedPointValue = copy.getRawBits();
	return *this;
}

std::ostream & operator<<(std::ostream &output, Fixed const &number) {
    output << number.toFloat();
    return output;
}

Fixed::~Fixed() {
	std::cout << "Deconstructor called" << std::endl;
}

int Fixed::getRawBits() const {
	std::cout << "getRawBits member function called" << std::endl;
	return this->FixedPointValue;
}

int Fixed::toInt() const {
	return this->FixedPointValue >> this->FractionalBits;
}

float Fixed::toFloat() const {
	return (float)this->FixedPointValue / (float)(1 << this->FractionalBits);
}