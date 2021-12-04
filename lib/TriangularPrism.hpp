#ifndef TRIANGULAR_PRISM_H
#define TRIANGULAR_PRISM_H

#include <cmath>
#include <stdexcept>

template<typename T = double>

class TriangularPrism {
private:
    T _length, _width, _height;

public:
    TriangularPrism(T length, T width, T height) {
        if(length <= 0 || width <= 0 || height <= 0) {
            throw std::invalid_argument("cannot create a Triangular Prism a non-positive length, width or height");
        }

        this->_length = length;
        this->_width = width;
        this->_height = height;
    }

    T rectangularBaseArea() {
        return this->_width*this->_length;
    }

    T triangularBaseArea() {
        return (this->_width*this->_height)/2;
    }
    
    T volume() {
        return (this->_length*this->_width*this->_height)/2;
    }
};

#endif