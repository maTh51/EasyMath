#include <gtest/gtest.h>
#include "Sphere.hpp"

TEST(SphereTest, SphereNonNegativeRadius) {
    EXPECT_THROW({
        try {
            Sphere<double> s = Sphere<double>(0);
        }
        catch(const std::invalid_argument& e) {
            EXPECT_STREQ("cannot crate a sphere with a non-positive radius", e.what());
            throw;
        }
    }, std::invalid_argument);
}

TEST(SphereTest, SphereArea) {
    Sphere<double> s = Sphere<double>(5);
    ASSERT_NEAR(314.1592, s.area(), 0.001);
}

TEST(SphereTest, SphereVolume) {
    Sphere<double> s = Sphere<double>(5);
    ASSERT_NEAR(523.598, s.volume(), 0.001);
}

TEST(SphereTest, SphereDiameter) {
    Sphere<double> s = Sphere<double>(5);
    ASSERT_EQ(10, s.diameter());
}