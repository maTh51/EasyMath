#ifndef CYLINDER_H
#define CYLINDER_H

#include <cmath>
#include <stdexcept>

#include "Circle.hpp"

template<typename T = double>

class Cylinder {
    private:
        T radius;
        T high;
        Circle<T> *circle;
    
    public:
        Cylinder(T radius, T high) {
            if (radius <= 0 || high <= 0) {
                throw std::invalid_argument("cannot crate a cylinder with a non-positive radius or high");
            }
            this->radius = radius;
            this->high = high;
            this->circle = new Circle<T>(radius);
        }

        T area() {
            T bases = this->circle->area() * 2;
            T side = this->circle->perimeter() * this->high;
            return bases + side;
        }

        T volume() {
            return this->circle->area() * this->high;
        }
};

#endif