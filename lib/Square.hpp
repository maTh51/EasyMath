#ifndef SQUARE_H
#define SQUARE_H

#include <cmath>
#include <stdexcept>

template<typename T = double>
class Square {
    T S;

    public:
    Square(T S)
    {
        if(S < 0) {
            throw std::invalid_argument( "cannot crate a square with a negative side" );
        }

        this->S = S;
    }

    inline T area() 
    { 
        return S * S;
    }

    inline T perimeter()
    { 
        return 4*S;
    }

    inline T diagonal()
    {
        return sqrt(2*S*S);
    };
};

#endif