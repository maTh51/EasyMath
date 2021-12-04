#include <gtest/gtest.h>
#include "Parallelogram.hpp"

TEST(ParallelogramTest, ParallelogramNonNegativeDimensions) {
    EXPECT_THROW({
        try {
            Parallelogram<double> parallelogram = Parallelogram<double>(-1,8,9);
        }
        catch(const std::invalid_argument& e) {
            EXPECT_STREQ("cannot create a parallelogram with non-positive dimensions", e.what());
            throw;
        }
    }, std::invalid_argument);
}

TEST(ParallelogramTest, ParallelogramPerimeter) {
    Parallelogram<double> parallelogram = Parallelogram<double>(10.0,9.0,8.0);
    ASSERT_EQ(38.0, parallelogram.perimeter());
}

TEST(ParallelogramTest, ParallelogramArea) {
    Parallelogram<double> parallelogram = Parallelogram<double>(8.0,5.0,4.0);
    ASSERT_EQ(32.0, parallelogram.area());
}

TEST(ParallelogramTest, ParallelogramOtherHeight) {
    Parallelogram<double> parallelogram = Parallelogram<double>(5,6,3);
    ASSERT_NEAR(2.5, parallelogram.otherHeight(), 0.0000001);
} 