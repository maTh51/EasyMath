#ifndef RECTANGULAR_PARALLELIPIPED
#define RECTANGULAR_PARALLELIPIPED

#include <cmath>
#include <stdexcept>

template<typename T = double>

class RectangularParallelipiped {
private:
    T _length, _width, _height;

public:
    RectangularParallelipiped(T length, T width, T height) {
        if(length <= 0 || width <= 0 || height <= 0) {
            throw std::invalid_argument("cannot create a rectangular parallelepiped with non-positive length, width, or height");
        }

        this->_length = length;
        this->_width = width;
        this->_height = height;
    }

    T perimeter() {
        return 4*(this->_length+this->_width+this->_height);
    }
    
    T baseArea() {
        return this->_length*this->_width;
    }

    T lateralArea() {
        return this->_width*this->_height;
    }
    
    T volume() {
        return this->_length*this->_width*this->_height;
    }
};

#endif