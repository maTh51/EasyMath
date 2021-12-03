#include <gtest/gtest.h>
#include "EasyMath.hpp"

#include "Circle.cpp"
#include "Trapeze.cpp"
#include "Pentagon.cpp"
#include "PentagonalPrism.cpp"
#include "Cylinder.cpp"
#include "Sphere.cpp"
#include "Square.cpp"
#include "Hexagon.cpp"
#include "HexagonalPrism.cpp"
#include "Pyramid.cpp"
#include "Rectangle.cpp"

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}