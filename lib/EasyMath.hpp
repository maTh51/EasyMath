#ifndef EASY_MATH_H
#define EASY_MATH_H

#include <cmath>
#include <stdexcept>

template<typename T = double>
class square {
    T S;

    public:
    square(T S)
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

template<typename T = double>
class hexagon {
    T S;

    public:
    hexagon(T S) 
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

template<typename T = double>
class hexagonal_prism {
    T S;
    T H;

    public:
    hexagonal_prism(T S, T H) 
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

template<typename T = double>
class pyramid {
    T S;
    T H;

    public:
    pyramid(T S, T H)
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

template<typename T = double>
class rectangle {
    T S0;
    T S1;

    public:
    rectangle(T A, T B) 
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