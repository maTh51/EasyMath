#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <cmath>
#include <stdexcept>

template<typename T = double>
class Rectangle {
    T S0;
    T S1;

    public:
    Rectangle(T A, T B) 
    {
        if(A < 0) {
            throw std::invalid_argument( "cannot crate a rectangle with a negative side" );
        }
        if(B < 0) {
            throw std::invalid_argument( "cannot crate a rectangle with a negative heigth" );
        }
        
        S0 = A;
        S1 = B;
    }

    inline T area() 
    { 
        return S0*S1; 
    }
    
    inline T perimeter() 
    { 
        return 2*S0+2*S1;
    }
    
    inline T diagonal() 
    { 
        return sqrt(S0*S0 + S1*S1); 
    }
};

#endif