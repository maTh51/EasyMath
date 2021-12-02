#ifndef PENTAGON_H
#define PENTAGON_H

#include <cmath>
#include <stdexcept>

template<typename T = double>

class Pentagon {
private:
    T side;

public:
    Pentagon(T side) {
        if(side <= 0) {
            throw std::invalid_argument("cannot crate a pentagon with a non-positive side");
        }
        this->side = side;
    }

    T area() {
        return (5*(this->side*this->side)) / (4*tan(36*M_PI/180));
    }

    T perimeter() {
        return 5*this->side;
    }

};

#endif