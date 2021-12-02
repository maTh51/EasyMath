#include <gtest/gtest.h>
#include "Circle.hpp"

TEST(CircleTest, CircleNonNegativeRadius) {
    EXPECT_THROW({
        try {
            Circle<double> circle = Circle<double>(-1);
        }
        catch(const std::invalid_argument& e) {
            EXPECT_STREQ("cannot crate a circle with a non-positive radius", e.what());
            throw;
        }
    }, std::invalid_argument);
}

TEST(CircleTest, CircleArea) {
    Circle<double> circle = Circle<double>(3);
    ASSERT_EQ(M_PI*3*3, circle.area());
}

TEST(CircleTest, CirclePerimeter) {
    Circle<double> circle = Circle<double>(3);
    ASSERT_EQ(M_PI*2*3, circle.perimeter());
}

TEST(CircleTest, CircleDiameter) {
    Circle<double> circle = Circle<double>(3);
    ASSERT_EQ(6, circle.diameter());
}