#include <gtest/gtest.h>
#include "RectangularPrallelipiped.hpp"

TEST(RectangularPrallelipipedTest, RectangularPrallelipipedNonNegativeRadius) {
    EXPECT_THROW({
        try {
            RectangularPrallelipiped<double> rectangularPrallelipiped = RectangularPrallelipiped<double>(15,-5.2,6);
        }
        catch(const std::invalid_argument& e) {
            EXPECT_STREQ("cannot create a Rectangular Prallelipiped with a non-positive lenght, width or height", e.what());
            throw;
        }
    }, std::invalid_argument);
}

TEST(RectangularPrallelipipedTest, RectangularPrallelipipedPerimeter) {
    RectangularPrallelipiped<double> rectangularPrallelipiped = RectangularPrallelipiped<double>(12.0,4.0,7.0);
    ASSERT_EQ(92.0, rectangularPrallelipiped.perimeter());
}

TEST(RectangularPrallelipipedTest, RectangularPrallelipipedBaseArea) {
    RectangularPrallelipiped<double> rectangularPrallelipiped = RectangularPrallelipiped<double>(8,5,4);
    ASSERT_EQ(40.0, rectangularPrallelipiped.baseArea());
}

TEST(RectangularPrallelipipedTest, RectangularPrallelipipedLateralArea) {
    RectangularPrallelipiped<double> rectangularPrallelipiped = RectangularPrallelipiped<double>(8,5,4);
    ASSERT_EQ(20.0, rectangularPrallelipiped.lateralArea());
}

TEST(RectangularPrallelipipedTest, RectangularPrallelipipedVolume) {
    RectangularPrallelipiped<double> rectangularPrallelipiped = RectangularPrallelipiped<double>(10,4,6.0);
    ASSERT_EQ(240.0, rectangularPrallelipiped.volume());
} 