#ifndef PENTAGONAL_PRISM_H
#define PENTAGONAL_PRISM_H

#include <cmath>
#include <stdexcept>

#include "Pentagon.hpp"

template<typename T = double>

class PentagonalPrism {
private:
    T side;
    T high;
    Pentagon<T> *base;

public:
    PentagonalPrism(T side, T high) {
        if(side <= 0 || high <= 0) {
            throw std::invalid_argument("cannot crate a pentagonal prism with a non-positive side or high");
        }
        this->side = side;
        this->high = high;
        this->base = new Pentagon<T>(side);
    }

    T area() {
        double bases = 2 * this->base->area();
        double sides = 5 * this->side * this->high;
        return bases + sides;
    }

    T volume() {
        return this->base->area() * this->high;
    }
};

#endif