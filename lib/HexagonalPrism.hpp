#ifndef HEXAGONAL_PRISM_H
#define HEXAGONAL_PRISM_H

#include <cmath>
#include <stdexcept>

template<typename T = double>
class HexagonalPrism {
    T S;
    T H;

    public:
    HexagonalPrism(T S, T H) 
    {
        if(S < 0) {
            throw std::invalid_argument( "cannot crate a hexagonal prism with a negative side" );
        }
    
        if(H < 0) {
            throw std::invalid_argument( "cannot crate a hexagonal prism with a negative heigth" );
        }
        this->S = S;
        this->H = H;
    }

    inline T volume() 
    { 
        return H*(3*sqrt(3)*S*S)/2;
    }
    
    inline T area() 
    { 
        return S*H*6 + (3*sqrt(3)*S*S);
    };
};

#endif