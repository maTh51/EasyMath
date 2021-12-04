#ifndef CUBE_H
#define CUBE_H

#include <cmath>
#include <stdexcept>

template<typename T = double>

class Cube {
private:
    T _edge;

public:
    Cube(T edge) {
        if(edge <= 0) {
            throw std::invalid_argument("cannot create a cube with non-positive edges");
        }

        this->_edge = edge;
    }

    T perimeter() {
        return 12*this->_edge;
    }

    T area() {
        return this->_edge * this->_edge;
    }

    T volume() {
        return this->_edge * this->_edge * this->_edge;
    }

};

#endif