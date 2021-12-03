#ifndef HEXAGON_H
#define HEXAGON_H

#include <cmath>
#include <stdexcept>

template<typename T = double>
class Hexagon {
    T S;

    public:
    Hexagon(T S) 
    {
        if(S < 0) {
            throw std::invalid_argument( "cannot crate a hexagon with a negative side" );
        }

        this->S = S;
    }
    
    inline T area() 
    {
        return (3*sqrt(3)*S*S)/2;
    }
    
    inline T perimeter() 
    { 
        return 6*S;
    };

    inline T diagonal() 
    { 
        return 2*S;
    };
};

#endif