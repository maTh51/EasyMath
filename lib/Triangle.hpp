#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <cmath>
#include <stdexcept>

template<typename T = double>

class Triangle {
private:
    T S1, S2, S3;

public:
    Triangle(T s1, T s2, T s3) {
        if(s1 <= 0 || s2 <= 0 || s3 <= 0) {
            throw std::invalid_argument("cannot create a triangle with one or more non-positive side");
        }

        this->S1 = s1;
        this->S2 = s2;
        this->S3 = s3;
    }

    T perimeter() {
        return this->S1 + this->S2 + this->S3;
    }

    T heightRelativeToSide(T side) {
        if(side > 3 || side < 1)
            throw std::invalid_argument("cannot calculate relative are with invalide side. Only accept 1, 2 or 3");
        else {
            T area = this->area();
            if(side == 1)
                return area/(this->S1/2);
            else if(side == 2)
                return area/(this->S2/2);
            else if(side == 3)
                return area/(this->S3/2);
            else
                throw std::invalid_argument("cannot calculate relative are with invalide side. Only accept 1, 2 or 3");
        } 
    }

    T area() {
        double s = (this->S1 + this->S2 + this->S3)/2;
        return sqrt(s*(s-this->S1)*(s-this->S2)*(s-this->S3));
    }

};

#endif