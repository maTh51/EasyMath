#ifndef CIRCLE_H
#define CIRCLE_H

#include <cmath>
#include <stdexcept>

template<typename T = double>

class Circle {
private:
    T radius;

public:
    Circle(T radius) {
        if(radius <= 0) {
            throw std::invalid_argument("cannot crate a circle with a non-positive radius");
        }
        this->radius = radius;
    }

    T area() {
        return M_PI * (this->radius * this->radius);
    }

    T perimeter() {
        return 2 * M_PI * this->radius;
    }

    T diameter() {
        return 2 * this->radius;
    }

};

#endif