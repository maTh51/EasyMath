#include <gtest/gtest.h>
#include "Pyramid.hpp"

TEST(EasyMathPyramidTest, PyramidNoNegativeSide) {
    EXPECT_THROW({
        try
        {
            Pyramid<double> s = Pyramid<double>(-1, 1);
        }
        catch(const std::invalid_argument& e )
        {
            EXPECT_STREQ( "cannot crate a pyramid with a negative side", e.what() );
            throw;
        }
    }, std::invalid_argument);

    EXPECT_THROW({
        try
        {
            Pyramid<double> s = Pyramid<double>(1, -1);
        }
        catch(const std::invalid_argument& e )
        {
            EXPECT_STREQ( "cannot crate a pyramid with a negative heigth", e.what() );
            throw;
        }
    }, std::invalid_argument);
}

TEST(EasyMathPyramidTest, PyramidVolume) {
    Pyramid<double> a = Pyramid<double>(3, 3);
    ASSERT_FLOAT_EQ(9, a.volume());
}
 
TEST(EasyMathPyramidTest, PyramidArea) {
    Pyramid<double> a = Pyramid<double>(4, 10);
    ASSERT_FLOAT_EQ(97.58431, a.area());
}