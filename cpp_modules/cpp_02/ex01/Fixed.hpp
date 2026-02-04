#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath> 

class Fixed {
private:
    int _raw;
    static const int _fracBits = 8;

public:
    Fixed();                       
    Fixed(const int n);            
    Fixed(const float f);          
    Fixed(const Fixed &other);     
    Fixed &operator=(const Fixed &other); 
    ~Fixed();                     

    int getRawBits() const;
    void setRawBits(int const raw);

    float toFloat() const;
    int toInt() const;
};

std::ostream& operator<<(std::ostream& out, const Fixed& fixed);

#endif
