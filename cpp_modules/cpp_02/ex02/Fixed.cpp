#include "Fixed.hpp"

Fixed::Fixed() : _fpValue(0) {
    
}

Fixed::Fixed(const int i) {
    
    _fpValue = i << _bits;
}

Fixed::Fixed(const float f) {
    
    _fpValue = roundf(f * (1 << _bits));
}

Fixed::Fixed(const Fixed& other) {
    
    *this = other;
}

Fixed& Fixed::operator=(const Fixed& other) {
    
    if (this != &other)
        _fpValue = other.getRawBits();
    return *this;
}

Fixed::~Fixed() {
    
}

int Fixed::getRawBits() const {
    return _fpValue;
}

void Fixed::setRawBits(int const raw) {
    
    _fpValue = raw;
}

float Fixed::toFloat() const {
    return static_cast<float>(_fpValue) / (1 << _bits);
}

int Fixed::toInt() const {
    return _fpValue >> _bits;
}

bool Fixed::operator>(const Fixed& other) const { return _fpValue > other._fpValue; }
bool Fixed::operator<(const Fixed& other) const { return _fpValue < other._fpValue; }
bool Fixed::operator>=(const Fixed& other) const { return _fpValue >= other._fpValue; }
bool Fixed::operator<=(const Fixed& other) const { return _fpValue <= other._fpValue; }
bool Fixed::operator==(const Fixed& other) const { return _fpValue == other._fpValue; }
bool Fixed::operator!=(const Fixed& other) const { return _fpValue != other._fpValue; }

Fixed Fixed::operator+(const Fixed& other) const {
    Fixed result;
    result._fpValue = _fpValue + other._fpValue;
    return result;
}

Fixed Fixed::operator-(const Fixed& other) const {
    Fixed result;
    result._fpValue = _fpValue - other._fpValue;
    return result;
}

Fixed Fixed::operator*(const Fixed& other) const {
    Fixed result;
    result._fpValue = (_fpValue * other._fpValue) >> _bits;
    return result;
}

Fixed Fixed::operator/(const Fixed& other) const {
    Fixed result;
    result._fpValue = (_fpValue << _bits) / other._fpValue;
    return result;
}

Fixed& Fixed::operator++() {
    _fpValue++;
    return *this;
}

Fixed Fixed::operator++(int) {
    Fixed temp = *this;
    _fpValue++;
    return temp;
}

Fixed& Fixed::operator--() {
    _fpValue--;
    return *this;
}

Fixed Fixed::operator--(int) {
    Fixed temp = *this;
    _fpValue--;
    return temp;
}

Fixed& Fixed::min(Fixed& a, Fixed& b) {
    if (a < b)
        return a;
    return b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
    if (a < b)
        return a;
    return b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b) {
    if (a > b)
        return a;
    return b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
    if (a > b)
        return a;
    return b;
}

std::ostream& operator<<(std::ostream& out, const Fixed& fixed) {
    out << fixed.toFloat();
    return out;
}
