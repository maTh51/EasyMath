#include <gtest/gtest.h>
#include "Triangle.hpp"

TEST(TriangleTest, TriangleNonNegativeRadius) {
    EXPECT_THROW({
        try {
            Triangle<double> triangle = Triangle<double>(-1,8,9);
        }
        catch(const std::invalid_argument& e) {
            EXPECT_STREQ("cannot create a triangle with one or more non-positive side", e.what());
            throw;
        }
    }, std::invalid_argument);
}

TEST(TriangleTest, TrianglePerimeter) {
    Triangle<double> triangle = Triangle<double>(7.0,8.0,9.0);
    ASSERT_EQ(24.0, triangle.perimeter());
}

TEST(TriangleTest, TriangleArea) {
    Triangle<double> triangle = Triangle<double>(3.0,4.0,5.0);
    ASSERT_EQ(6.0, triangle.area());
}

TEST(TriangleTest, TriangleHeightRelativeToSide) {
    Triangle<double> triangle = Triangle<double>(6,8,10);
    ASSERT_EQ(8.0, triangle.heightRelativeToSide(1));
    ASSERT_EQ(6.0, triangle.heightRelativeToSide(2));
    ASSERT_EQ(4.8, triangle.heightRelativeToSide(3));
} 

TEST(TriangleTest, TriangleHeightRelativeToSideExceptions) {
    Triangle<double> triangle = Triangle<double>(6,8,10);
    EXPECT_THROW({
        try {
            triangle.heightRelativeToSide(0.5);
        }
        catch(const std::invalid_argument& e) {
            EXPECT_STREQ("cannot calculate relative are with invalide side. Only accept 1, 2 or 3", e.what());
            throw;
        }
    }, std::invalid_argument);
    EXPECT_THROW({
        try {
            triangle.heightRelativeToSide(4);
        }
        catch(const std::invalid_argument& e) {
            EXPECT_STREQ("cannot calculate relative are with invalide side. Only accept 1, 2 or 3", e.what());
            throw;
        }
    }, std::invalid_argument);
    EXPECT_THROW({
        try {
            triangle.heightRelativeToSide(2.5);
        }
        catch(const std::invalid_argument& e) {
            EXPECT_STREQ("cannot calculate relative are with invalide side. Only accept 1, 2 or 3", e.what());
            throw;
        }
    }, std::invalid_argument);
} 