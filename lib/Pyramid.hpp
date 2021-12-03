#ifndef PYRAMID_H
#define PYRAMID_H

#include <cmath>
#include <stdexcept>

template<typename T = double>
class Pyramid {
    T S;
    T H;

    public:
    Pyramid(T S, T H)
    {
        if(S < 0) {
            throw std::invalid_argument( "cannot crate a pyramid with a negative side" );
        }
        if(H < 0) {
            throw std::invalid_argument( "cannot crate a pyramid with a negative heigth" );
        }
        this->S = S;
        this->H = H;
    }
    
    inline T volume() 
    {
        return (S*S*H)/3.0; 
    }
    
    inline T area() 
    { 
        return S*S + 2*S*sqrt((S/2)*(S/2) + H*H); 
    };
};

#endif