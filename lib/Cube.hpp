#ifndef CUBE_H
#define CUBE_H

#include <cmath>
#include <stdexcept>

template<typename T = double>

class Cube {
private:
    T S;

public:
    Cube(T s) {
        if(s <= 0) {
            throw std::invalid_argument("cannot create a cube with a non-positive side");
        }

        this->S = s;
    }

    T perimeter() {
        return 12*this->S;
    }

    T area() {
        return this->S * this->S;
    }

    T volume() {
        return this->S * this->S * this->S;
    }

};

#endif