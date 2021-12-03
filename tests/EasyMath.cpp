#include <gtest/gtest.h>
#include "EasyMath.hpp"

#include "Circle.cpp"
#include "Trapeze.cpp"
#include "Pentagon.cpp"
#include "PentagonalPrism.cpp"
#include "Cylinder.cpp"
#include "Sphere.cpp"

TEST(EasyMathSquareTest, SquareNoNegativeSide) {
    EXPECT_THROW({
        try
        {
            square<double> s = square<double>(-1);
        }
        catch(const std::invalid_argument& e )
        {
            EXPECT_STREQ( "cannot crate a square with a negative side", e.what() );
            throw;
        }
    }, std::invalid_argument);
}

TEST(EasyMathSquareTest, SquareArea) {
    square<double> a = square<double>(36);
    ASSERT_EQ(1296, a.area());
}
 
TEST(EasyMathSquareTest, SquarePerimeter) {
    square<double> a = square<double>(36);
    ASSERT_EQ(144, a.perimeter());
}

TEST(EasyMathSquareTest, SquareDiagonal) {
    square<double> a = square<double>(1);
    ASSERT_FLOAT_EQ(1.414214, a.diagonal());
}

TEST(EasyMathHexagonTest, HexagonNoNegativeSide) {
    EXPECT_THROW({
        try
        {
            hexagon<double> s = hexagon<double>(-1);
        }
        catch(const std::invalid_argument& e )
        {
            EXPECT_STREQ( "cannot crate a hexagon with a negative side", e.what() );
            throw;
        }
    }, std::invalid_argument);
}

TEST(EasyMathHexagonTest, HexagonArea) {
    hexagon<double> a = hexagon<double>(3);
    ASSERT_FLOAT_EQ(23.38269, a.area());
}
 
TEST(EasyMathHexagonTest, HexagonPerimeter) {
    hexagon<double> a = hexagon<double>(3);
    ASSERT_FLOAT_EQ(18, a.perimeter());
}

TEST(EasyMathHexagonTest, HexagonDiagonal) {
    hexagon<double> a = hexagon<double>(1);
    ASSERT_FLOAT_EQ(2, a.diagonal());
}


TEST(EasyMathHexagonalPrismsTest, HexagonalPrismsNoNegativeSide) {
    EXPECT_THROW({
        try
        {
            hexagonal_prism<double> s = hexagonal_prism<double>(-1, 1);
        }
        catch(const std::invalid_argument& e )
        {
            EXPECT_STREQ( "cannot crate a hexagonal prism with a negative side", e.what() );
            throw;
        }
    }, std::invalid_argument);

    EXPECT_THROW({
        try
        {
            hexagonal_prism<double> s = hexagonal_prism<double>(1, -1);
        }
        catch(const std::invalid_argument& e )
        {
            EXPECT_STREQ( "cannot crate a hexagonal prism with a negative heigth", e.what() );
            throw;
        }
    }, std::invalid_argument);
}

TEST(EasyMathHexagonalPrismsTest, HexagonalPrismsArea) {
    hexagonal_prism<double> a = hexagonal_prism<double>(3, 3);
    ASSERT_FLOAT_EQ(70.14806, a.volume());
}
 
TEST(EasyMathHexagonalPrismsTest, HexagonalPrismsPerimeter) {
    hexagonal_prism<double> a = hexagonal_prism<double>(3, 1);
    ASSERT_FLOAT_EQ(64.76537, a.area());
}


TEST(EasyMathPyramidTest, PyramidNoNegativeSide) {
    EXPECT_THROW({
        try
        {
            pyramid<double> s = pyramid<double>(-1, 1);
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
            pyramid<double> s = pyramid<double>(1, -1);
        }
        catch(const std::invalid_argument& e )
        {
            EXPECT_STREQ( "cannot crate a pyramid with a negative heigth", e.what() );
            throw;
        }
    }, std::invalid_argument);
}

TEST(EasyMathPyramidTest, PyramidVolume) {
    pyramid<double> a = pyramid<double>(3, 3);
    ASSERT_FLOAT_EQ(9, a.volume());
}
 
TEST(EasyMathPyramidTest, PyramidArea) {
    pyramid<double> a = pyramid<double>(4, 10);
    ASSERT_FLOAT_EQ(97.58431, a.area());
}



TEST(EasyMathRectangleTest, RectangleNoNegativeSide) {
    EXPECT_THROW({
        try
        {
            rectangle<double> s = rectangle<double>(-1, 1);
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
            rectangle<double> s = rectangle<double>(1, -1);
        }
        catch(const std::invalid_argument& e )
        {
            EXPECT_STREQ( "cannot crate a rectangle with a negative heigth", e.what() );
            throw;
        }
    }, std::invalid_argument);
}

TEST(EasyMathRectangleTest, RectanglePerimeter) {
    rectangle<double> a = rectangle<double>(3, 3);
    ASSERT_FLOAT_EQ(12, a.perimeter());
}
 
TEST(EasyMathRectangleTest, RectangleArea) {
    rectangle<double> a = rectangle<double>(4, 10);
    ASSERT_FLOAT_EQ(40, a.area());
}

TEST(EasyMathRectangleTest, RectangleDiagonal) {
    rectangle<double> a = rectangle<double>(6, 6);
    ASSERT_FLOAT_EQ(8.48528137424, a.diagonal());
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}