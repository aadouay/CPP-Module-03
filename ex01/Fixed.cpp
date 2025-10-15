#include "Fixed.hpp"

Fixed::Fixed(): _value(0){
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int integer){
    std::cout << "Int constructor called" << std::endl;
    _value = integer * (1 << _fractionalBits);
}

Fixed::Fixed(const float floating){
    std::cout << "Float constructor called" << std::endl;
    _value = roundf((floating * (1 << _fractionalBits)));
}

Fixed::Fixed(const Fixed& other){
    std::cout << "Copy constructor called" << std::endl;
    _value = other._value;
}

Fixed& Fixed::operator=(const Fixed& other) {
    std::cout << "Copy assignment operator called" << std::endl;
    _value = other._value;
    return *this;
}

int Fixed::getRawBits(void) const {
    std::cout << "getRawBits member function called" << std::endl;
    return _value;
}

void Fixed::setRawBits(int const raw) {
    _value = raw;
}
float Fixed::toFloat(void) const{
    return (float)_value / (1 << _fractionalBits);
}
int Fixed::toInt(void) const{
    return (_value / (1 << _fractionalBits));
}

std::ostream& operator<<(std::ostream& os, const Fixed& other){
    os << other.toFloat();
    return os;
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}