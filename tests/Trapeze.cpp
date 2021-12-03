#include <gtest/gtest.h>
#include "Trapeze.hpp"

TEST(TrapezeTest, TrapezeNonNegativeDimensions) {
    EXPECT_THROW({
        try {
            Trapeze<double> trapeze = Trapeze<double>(-2,2,2,2,2);
        }
        catch(const std::invalid_argument& e) {
            EXPECT_STREQ("cannot crate a trapeze with non-positive dimensions", e.what());
            throw;
        }
    }, std::invalid_argument);
}

TEST(TrapezeTest, TrapezeArea) {
    Trapeze<double> trapeze = Trapeze<double>(3,4,5,3,2);
    ASSERT_EQ(8, trapeze.area());
}

TEST(TrapezeTest, TrapezePerimeter) {
    Trapeze<double> trapeze = Trapeze<double>(3,2,2,2,2);
    ASSERT_EQ(9, trapeze.perimeter());
}
