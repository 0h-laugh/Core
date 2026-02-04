#include "Fixed.hpp"

Fixed::Fixed() : _raw(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int n) {
    std::cout << "Int constructor called" << std::endl;
    _raw = n << _fracBits;  
}

Fixed::Fixed(const float f) {
    std::cout << "Float constructor called" << std::endl;
    _raw = roundf(f * (1 << _fracBits));
}

Fixed::Fixed(const Fixed &other) {
    std::cout << "Copy constructor called" << std::endl;
    _raw = other._raw;
}

Fixed &Fixed::operator=(const Fixed &other) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other) {
        _raw = other._raw;
    }
    return *this;
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits() const {
    std::cout << "getRawBits member function called" << std::endl;
    return _raw;
}

void Fixed::setRawBits(int const raw) {
    _raw = raw;
}

float Fixed::toFloat() const {
    return (float)_raw / (1 << _fracBits);
}

int Fixed::toInt() const {
    return _raw >> _fracBits;
}

std::ostream& operator<<(std::ostream& out, const Fixed& fixed) {
    out << fixed.toFloat();
    return out;
}
