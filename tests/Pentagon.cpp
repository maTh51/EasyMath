#include <gtest/gtest.h>
#include "Pentagon.hpp"

TEST(PentagonTest, PentagonNonNegativeSide) {
    EXPECT_THROW({
        try {
            Pentagon<double> pentagon = Pentagon<double>(0);
        }
        catch(const std::invalid_argument& e) {
            EXPECT_STREQ("cannot crate a pentagon with a non-positive side", e.what());
            throw;
        }
    }, std::invalid_argument);
}

TEST(PentagonTest, PentagonArea) {
    Pentagon<double> pentagon = Pentagon<double>(5);
    ASSERT_NEAR(43.011935, pentagon.area(), 0.00001);
}

TEST(PentagonTest, PentagonPerimeter) {
    Pentagon<double> pentagon = Pentagon<double>(5);
    ASSERT_EQ(25, pentagon.perimeter());
}