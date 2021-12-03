#ifndef TRIANGULAR_PRISM_H
#define TRIANGULAR_PRISM_H

#include <cmath>
#include <stdexcept>

template<typename T = double>

class TriangularPrism {
private:
    T L, W, H;

public:
    TriangularPrism(T l, T w, T h) {
        if(l <= 0 || w <= 0 || h <= 0) {
            throw std::invalid_argument("cannot create a Triangular Prism a non-positive lenght, width or height");
        }

        this->L = l;
        this->W = w;
        this->H = h;
    }

    T rectangularBaseArea() {
        return this->W*this->L;
    }

    T triangularBaseArea() {
        return (this->W*this->H)/2;
    }
    
    T volume() {
        return (this->L*this->W*this->H)/2;
    }
};

#endif