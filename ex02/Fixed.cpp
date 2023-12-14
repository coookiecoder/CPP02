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

void Fixed::setRawBits(const int raw) {
	this->FixedPointValue = raw;
}

int Fixed::toInt() const {
	return this->FixedPointValue >> this->FractionalBits;
}

float Fixed::toFloat() const {
	return (float)this->FixedPointValue / (float)(1 << this->FractionalBits);
}

bool Fixed::operator>(const Fixed &b) const {
	return this->FixedPointValue > b.FixedPointValue;
}

bool Fixed::operator<(const Fixed &b) const {
	return this->FixedPointValue < b.FixedPointValue;
}

bool Fixed::operator>=(const Fixed &b) const {
	return this->FixedPointValue >= b.FixedPointValue;
}

bool Fixed::operator<=(const Fixed &b) const {
	return this->FixedPointValue <= b.FixedPointValue;
}

bool Fixed::operator==(const Fixed &b) const {
	return this->FixedPointValue == b.FixedPointValue;
}

bool Fixed::operator!=(const Fixed &b) const {
	return this->FixedPointValue != b.FixedPointValue;
}

Fixed Fixed::operator+(const Fixed &b) const {
	return Fixed(this->toFloat() + b.toFloat());
}

Fixed Fixed::operator-(const Fixed &b) const {
	return Fixed(this->toFloat() - b.toFloat());
}

Fixed Fixed::operator*(const Fixed &b) const {
	return Fixed(this->toFloat() * b.toFloat());
}

Fixed Fixed::operator/(const Fixed &b) const {
	return Fixed(this->toFloat() / b.toFloat());
}

Fixed &Fixed::operator++() {
	FixedPointValue++;
	return *this;
}

Fixed Fixed::operator++(int) {
	Fixed Buffer(this->toFloat());
	FixedPointValue++;
	return Buffer;
}

Fixed &Fixed::operator--() {
	FixedPointValue--;
	return *this;
}

Fixed Fixed::operator--(int) {
	Fixed Buffer(this->toFloat());
	FixedPointValue--;
	return Buffer;
}

Fixed & Fixed::max(Fixed &a, Fixed &b) {
	if (a > b)
		return a;
	return b;
}

const Fixed & Fixed::max(const Fixed &a, const Fixed &b) {
	if (a > b)
		return a;
	return b;
}

Fixed & Fixed::min(Fixed &a, Fixed &b) {
	if (a > b)
		return b;
	return a;
}

const Fixed & Fixed::min(const Fixed &a, const Fixed &b) {
	if (a > b)
		return b;
	return a;
}