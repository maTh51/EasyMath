#include <gtest/gtest.h>
#include "Cylinder.hpp"

TEST(CylinderTest, CylinderNonNegativeRadius) {
    EXPECT_THROW({
        try {
            Cylinder<double> c = Cylinder<double>(0, 3);
        }
        catch(const std::invalid_argument& e) {
            EXPECT_STREQ("cannot crate a cylinder with a non-positive radius or high", e.what());
            throw;
        }
    }, std::invalid_argument);
}

TEST(CylinderTest, CylinderArea) {
    Cylinder<double> c = Cylinder<double>(5, 8);
    ASSERT_NEAR(408.41, c.area(), 0.01);
}

TEST(CylinderTest, CylinderVolume) {
    Cylinder<double> c = Cylinder<double>(5, 8);
    ASSERT_NEAR(628.32, c.volume(), 0.01);
}