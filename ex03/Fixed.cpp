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

// oveloded operators
bool Fixed::operator>(const Fixed& other){
    return (this->_value > other._value);
}

bool Fixed::operator<(const Fixed& other){
    return (this->_value < other._value);
}

bool Fixed::operator>=(const Fixed& other){
    return (this->_value >= other._value);
}

bool Fixed::operator<=(const Fixed& other){
    return (this->_value <= other._value);
}

bool Fixed::operator==(const Fixed& other){
    return (this->_value == other._value);
}

bool Fixed::operator!=(const Fixed& other){
    return (this->_value != other._value);
}

// add same operators 
Fixed   Fixed::operator++(int){
    Fixed temp = *this;
    _value++;
    return temp;
}

Fixed   Fixed::operator++(){
    _value++;
    return *this;
}
Fixed   Fixed::operator--(int){
    Fixed temp = *this;
    _value--;
    return temp;
}

Fixed   Fixed::operator--(){
    _value--;
    return *this;
}

Fixed Fixed::operator*(const Fixed& other)const{

    return Fixed(this->toFloat() * other.toFloat());
}

Fixed Fixed::operator+(const Fixed& other)const{

    return Fixed(this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed& other)const{
    return Fixed(this->toFloat() - other.toFloat());
}

Fixed Fixed::operator/(const Fixed& other)const{

    return Fixed(this->toFloat() / other.toFloat());
}


const Fixed&    Fixed::max(const Fixed& a, const Fixed& b){
    if(a._value > b._value)
        return (a);
    else
        return (b);
}

Fixed&    Fixed::max(Fixed& a, Fixed& b){
    if(a._value > b._value)
        return (a);
    else
        return (b);
}

const Fixed&    Fixed::min(const Fixed& a, const Fixed& b){
    if(a._value < b._value)
        return (a);
    else
        return (b);
}

Fixed&    Fixed::min(Fixed& a, Fixed& b){
    if(a._value < b._value)
        return (a);
    else
        return (b);
}


Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}
