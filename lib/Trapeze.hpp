#ifndef TRAPEZE_H
#define TRAPEZE_H

#include <cmath>
#include <stdexcept>

template<typename T = double>

class Trapeze {
private:
    T leftSide;
    T rightSide;
    T smallerBase;
    T largerBase;
    T high;

public:
    Trapeze(T leftSide, T rightSide, T smallerBase, T largerBase, T high) {
        if(leftSide <= 0 || rightSide <= 0 || smallerBase <= 0 || largerBase <= 0 || high <= 0) {
            throw std::invalid_argument("cannot crate a trapeze with non-positive dimensions");
        }

        this->leftSide = leftSide;
        this->rightSide = rightSide;
        this->smallerBase = smallerBase;
        this->largerBase = largerBase;
        this->high = high;
    }

    T area() {
        return ((this->smallerBase + this->largerBase)*this->high)/2;
    }

    T perimeter() {
        return this->leftSide + this->rightSide + this->smallerBase + this->largerBase;
    }
};

#endif