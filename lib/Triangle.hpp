#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <cmath>
#include <stdexcept>

template<typename T = double>

class Triangle {
private:
    T _side1, _side2, _side3;

public:
    Triangle(T side1, T side2, T side3) {
        if(side1 <= 0 || side2 <= 0 || side3 <= 0) {
            throw std::invalid_argument("cannot create a triangle with non-positive dimensions");
        }

        this->_side1 = side1;
        this->_side2 = side2;
        this->_side3 = side3;
    }

    T perimeter() {
        return this->_side1 + this->_side2 + this->_side3;
    }

    T heightRelativeToSide(T side) {
        T area = this->area();
        if(side == 1)
            return area/(this->_side1/2);
        else if(side == 2)
            return area/(this->_side2/2);
        else if(side == 3)
            return area/(this->_side3/2);
        else
            throw std::invalid_argument("cannot calculate the relative height of an invalid side. Input only 1, 2 or 3");
    }

    T area() {
        double s = (this->_side1 + this->_side2 + this->_side3)/2;
        return sqrt(s*(s-this->_side1)*(s-this->_side2)*(s-this->_side3));
    }

};

#endif