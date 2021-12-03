#include <gtest/gtest.h>
#include "Triangle.cpp"
#include "Cube.cpp"

int main(int argc, char **argv) {
    Cube<double> cube = Cube<double>(5);
    std::cout << cube.volume() << std::endl;

    testing::InitGoogleTest(&argc, argv);
    
    return RUN_ALL_TESTS();
}