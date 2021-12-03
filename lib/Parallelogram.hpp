#ifndef PARALLELOGRAM_H
#define PARALLELOGRAM_H

#include <cmath>
#include <stdexcept>

template<typename T = double>

class Parallelogram {
private:
    T SB, SO, H;

public:
    Parallelogram(T sb, T so, T h) {
        if(sb <= 0 || so <= 0 || h <= 0) {
            throw std::invalid_argument("cannot create a Parallelogram with one or more non-positive sides or height");
        }

        this->SB = sb;
        this->SO = so;
        this->H = h;
    }

    T perimeter() {
        return 2*(this->SB + this->SO);
    }

    T area() {
        return this->SB*this->H;
    }
    
    T otherHeight() {
        T area = this->area();
        return area/this->SO; 
    }


};

#endif