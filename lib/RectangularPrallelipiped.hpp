#ifndef RECTANGULAR_PRALLELIPIPED
#define RECTANGULAR_PRALLELIPIPED

#include <cmath>
#include <stdexcept>

template<typename T = double>

class RectangularPrallelipiped {
private:
    T L, W, H;

public:
    RectangularPrallelipiped(T l, T w, T h) {
        if(l <= 0 || w <= 0 || h <= 0) {
            throw std::invalid_argument("cannot create a Rectangular Prallelipiped with a non-positive lenght, width or height");
        }

        this->L = l;
        this->W = w;
        this->H = h;
    }

    T perimeter() {
        return 4*(this->L+this->W+this->H);
    }
    
    T baseArea() {
        return this->L*this->W;
    }

    T lateralArea() {
        return this->W*this->H;
    }
    
    T volume() {
        return this->L*this->W*this->H;
    }
};

#endif