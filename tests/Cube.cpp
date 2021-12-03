#include <gtest/gtest.h>
#include "Cube.hpp"

TEST(CubeTest, CubeNonNegativeRadius) {
    EXPECT_THROW({
        try {
            Cube<double> cube = Cube<double>(-1);
        }
        catch(const std::invalid_argument& e) {
            EXPECT_STREQ("cannot create a cube with a non-positive side", e.what());
            throw;
        }
    }, std::invalid_argument);
}

TEST(CubeTest, CubePerimeter) {
    Cube<double> cube = Cube<double>(4.0);
    ASSERT_EQ(48.0, cube.perimeter());
}

TEST(CubeTest, CubeArea) {
    Cube<double> cube = Cube<double>(10);
    ASSERT_EQ(100, cube.area());
}

TEST(CubeTest, CubeVolume) {
    Cube<double> cube = Cube<double>(5.2);
    ASSERT_NEAR(140.608, cube.volume(),0.000001);
}