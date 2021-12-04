#ifndef PARALLELOGRAM_H
#define PARALLELOGRAM_H

#include <cmath>
#include <stdexcept>

template<typename T = double>

class Parallelogram {
private:
    T _base, _lateral, _height;

public:
    Parallelogram(T base, T lateral, T height) {
        if(base <= 0 || lateral <= 0 || height <= 0) {
            throw std::invalid_argument("cannot create a parallelogram with non-positive dimensions");
        }

        this->_base = base;
        this->_lateral = lateral;
        this->_height = height;
    }

    T perimeter() {
        return 2*(this->_base + this->_lateral);
    }

    T area() {
        return this->_base*this->_height;
    }
    
    T otherHeight() {
        T area = this->area();
        return area/this->_lateral; 
    }


};

#endif