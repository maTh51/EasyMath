#include <gtest/gtest.h>

#include "Triangle.cpp"
#include "Cube.cpp"
#include "TriangularPrism.cpp"
#include "Parallelogram.cpp"
#include "RectangularParallelipiped.cpp"
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

#include "Integration.cpp"

int main(int argc, char **argv) {

    testing::InitGoogleTest(&argc, argv);
    
    return RUN_ALL_TESTS();
}