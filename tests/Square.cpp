#include <gtest/gtest.h>
#include "Square.hpp"

TEST(EasyMathSquareTest, SquareNoNegativeSide) {
    EXPECT_THROW({
        try
        {
            Square<double> s = Square<double>(-1);
        }
        catch(const std::invalid_argument& e )
        {
            EXPECT_STREQ( "cannot crate a square with a negative side", e.what() );
            throw;
        }
    }, std::invalid_argument);
}

TEST(EasyMathSquareTest, SquareArea) {
    Square<double> a = Square<double>(36);
    ASSERT_EQ(1296, a.area());
}
 
TEST(EasyMathSquareTest, SquarePerimeter) {
    Square<double> a = Square<double>(36);
    ASSERT_EQ(144, a.perimeter());
}

TEST(EasyMathSquareTest, SquareDiagonal) {
    Square<double> a = Square<double>(1);
    ASSERT_FLOAT_EQ(1.414214, a.diagonal());
}