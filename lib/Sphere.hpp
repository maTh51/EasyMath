#ifndef SPHERE_H
#define SPHERE_H

#include <cmath>
#include <stdexcept>

template<typename T = double>

class Sphere {
private:
    T radius;

public:
    Sphere(T radius) {
        if(radius <= 0) {
            throw std::invalid_argument("cannot crate a sphere with a non-positive radius");
        }
        this->radius = radius;
    }

    T area() {
        return 4 * M_PI * (this->radius * this->radius);
    }

    T volume() {
        return (4 * M_PI * (this->radius * this->radius * this->radius)) / 3;
    }

    T diameter() {
        return 2 * this->radius;
    }
};

#endif