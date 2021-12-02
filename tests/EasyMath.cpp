#include <gtest/gtest.h>

#include "Circle.cpp"
#include "Trapeze.cpp"
#include "Pentagon.cpp"
#include "PentagonalPrism.cpp"
#include "Cylinder.cpp"
#include "Sphere.cpp"

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}