#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed{

    private:
        int _value;
        static const int _fractionalBits = 8;
    public:
        Fixed();
        Fixed(const int integer);
        Fixed(const float floating);
        Fixed(const Fixed& other);
        Fixed& operator=(const Fixed& other);
        ~Fixed();
        int getRawBits(void) const;
        void setRawBits(int const raw);
        float toFloat(void) const;
        int toInt(void) const;
        // set operators ::
        bool operator>(const Fixed& other);
        bool operator<(const Fixed& other);
        bool operator>=(const Fixed& other);
        bool operator<=(const Fixed& other);
        bool operator==(const Fixed& other);
        bool operator!=(const Fixed& other);
        Fixed operator++(int);
        Fixed operator++();
        Fixed operator--(int);
        Fixed operator--();
        Fixed operator*(const Fixed& other)const;
        Fixed operator+(const Fixed& other)const;
        Fixed operator-(const Fixed& other)const;
        Fixed operator/(const Fixed& other)const;

        static const Fixed&    max(const Fixed& a, const Fixed& b);
        static  Fixed&    max(Fixed& a, Fixed& b);
        static const Fixed&    min(const Fixed& a, const Fixed& b);
        static  Fixed&    min(Fixed& a, Fixed& b);

};

std::ostream& operator<<(std::ostream& os, const Fixed& other);

#endif