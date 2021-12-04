#include <gtest/gtest.h>
#include "RectangularParallelipiped.hpp"

TEST(RectangularParallelipipedTest, RectangularParallelipipedNonNegativeDimensions) {
    EXPECT_THROW({
        try {
            RectangularParallelipiped<double> rectangularParallelipiped = RectangularParallelipiped<double>(15,-5.2,6);
        }
        catch(const std::invalid_argument& e) {
            EXPECT_STREQ("cannot create a rectangular parallelepiped with non-positive length, width, or height", e.what());
            throw;
        }
    }, std::invalid_argument);
}

TEST(RectangularParallelipipedTest, RectangularParallelipipedPerimeter) {
    RectangularParallelipiped<double> rectangularParallelipiped = RectangularParallelipiped<double>(12.0,4.0,7.0);
    ASSERT_EQ(92.0, rectangularParallelipiped.perimeter());
}

TEST(RectangularParallelipipedTest, RectangularParallelipipedBaseArea) {
    RectangularParallelipiped<double> rectangularParallelipiped = RectangularParallelipiped<double>(8,5,4);
    ASSERT_EQ(40.0, rectangularParallelipiped.baseArea());
}

TEST(RectangularParallelipipedTest, RectangularParallelipipedLateralArea) {
    RectangularParallelipiped<double> rectangularParallelipiped = RectangularParallelipiped<double>(8,5,4);
    ASSERT_EQ(20.0, rectangularParallelipiped.lateralArea());
}

TEST(RectangularParallelipipedTest, RectangularParallelipipedVolume) {
    RectangularParallelipiped<double> rectangularParallelipiped = RectangularParallelipiped<double>(10,4,6.0);
    ASSERT_EQ(240.0, rectangularParallelipiped.volume());
} 