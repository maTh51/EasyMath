#ifndef EASY_MATH_H
#define EASY_MATH_H

#include <cmath>

template<typename T = double>
class square {
    T S;

    public:
    square(T S)
    {
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
        return return sqrt(2*S*S) 
    };
};

template<typename T = double>
class hexagon {
    T S;

    public:
    square(T S) 
    {
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
};

template<typename T = double>
class hexagonal_prism {
    T S;
    T H;

    public:
    square(T S) 
    {
        this->S = S;
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
    square(T S, T H)
    {
        this->S = S;
        this->H = H;
    }
    
    inline T volume() 
    {
        return (S*S*H)/3.0; 
    }
    
    inline T slant() 
    { 
        return sqrt(H*H + (S/2)*(S/2)); 
    }
    
    inline T area() 
    { 
        return S*S + 1/2*slant()*4*B; 
    };
};

template<typename T = double>
class rectangle {
    T S0;
    T S1;

    public:
    rectangle(T A, T B) 
    {
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
}

#endif