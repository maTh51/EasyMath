#include <gtest/gtest.h>
#include "TriangularPrism.hpp"

TEST(TriangularPrismTest, TriangularPrismNonNegativeRadius) {
    EXPECT_THROW({
        try {
            TriangularPrism<double> triangularPrism = TriangularPrism<double>(15,-5,6);
        }
        catch(const std::invalid_argument& e) {
            EXPECT_STREQ("cannot create a Triangular Prism a non-positive lenght, width or height", e.what());
            throw;
        }
    }, std::invalid_argument);
}

TEST(TriangularPrismTest, TriangularPrismRectangularBaseArea) {
    TriangularPrism<double> triangularPrism = TriangularPrism<double>(18.0,12.0,9.0);
    ASSERT_EQ(216.0, triangularPrism.rectangularBaseArea());
}

TEST(TriangularPrismTest, TriangularPrismTriangularBaseArea) {
    TriangularPrism<double> triangularPrism = TriangularPrism<double>(10.0,8,3);
    ASSERT_EQ(12.0, triangularPrism.triangularBaseArea());
}

TEST(TriangularPrismTest, TriangularPrismVolume) {
    TriangularPrism<double> triangularPrism = TriangularPrism<double>(8.0,6,5.0);
    ASSERT_EQ(120.0, triangularPrism.volume());
} 