#include <gtest/gtest.h>
#include "PentagonalPrism.hpp"

TEST(PentagonalPrismTest, PentagonalPrismNonNegativeSide) {
    EXPECT_THROW({
        try {
            PentagonalPrism<double> prism = PentagonalPrism<double>(0, 3);
        }
        catch(const std::invalid_argument& e) {
            EXPECT_STREQ("cannot crate a pentagonal prism with a non-positive side or high", e.what());
            throw;
        }
    }, std::invalid_argument);
}

TEST(PentagonalPrismTest, PentagonalPrismArea) {
    PentagonalPrism<double> p = PentagonalPrism<double>(5,8);
    ASSERT_NEAR(286.023, p.area(), 0.001);
}

TEST(PentagonalPrismTest, PentagonalPrismVolume) {
    PentagonalPrism<double> p = PentagonalPrism<double>(5,8);
    ASSERT_NEAR(344.095, p.volume(), 0.001);
}