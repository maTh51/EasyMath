#include <gtest/gtest.h>
#include "Triangle.cpp"
#include "Cube.cpp"
#include "TriangularPrism.cpp"
#include "Parallelogram.cpp"
#include "RectangularPrallelipiped.cpp"

int main(int argc, char **argv) {

    testing::InitGoogleTest(&argc, argv);
    
    return RUN_ALL_TESTS();
}