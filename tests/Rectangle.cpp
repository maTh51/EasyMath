#include <gtest/gtest.h>
#include "Rectangle.hpp"

TEST(EasyMathRectangleTest, RectangleNoNegativeSide) {
    EXPECT_THROW({
        try
        {
            Rectangle<double> s = Rectangle<double>(-1, 1);
        }
        catch(const std::invalid_argument& e )
        {
            EXPECT_STREQ( "cannot crate a rectangle with a negative side", e.what() );
            throw;
        }
    }, std::invalid_argument);

    EXPECT_THROW({
        try
        {
            Rectangle<double> s = Rectangle<double>(1, -1);
        }
        catch(const std::invalid_argument& e )
        {
            EXPECT_STREQ( "cannot crate a rectangle with a negative heigth", e.what() );
            throw;
        }
    }, std::invalid_argument);
}

TEST(EasyMathRectangleTest, RectanglePerimeter) {
    Rectangle<double> a = Rectangle<double>(3, 3);
    ASSERT_FLOAT_EQ(12, a.perimeter());
}
 
TEST(EasyMathRectangleTest, RectangleArea) {
    Rectangle<double> a = Rectangle<double>(4, 10);
    ASSERT_FLOAT_EQ(40, a.area());
}

TEST(EasyMathRectangleTest, RectangleDiagonal) {
    Rectangle<double> a = Rectangle<double>(6, 6);
    ASSERT_FLOAT_EQ(8.48528137424, a.diagonal());
}