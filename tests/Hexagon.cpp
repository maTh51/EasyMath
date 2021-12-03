#include <gtest/gtest.h>
#include "Hexagon.hpp"

TEST(EasyMathHexagonTest, HexagonNoNegativeSide) {
    EXPECT_THROW({
        try
        {
            Hexagon<double> s = Hexagon<double>(-1);
        }
        catch(const std::invalid_argument& e )
        {
            EXPECT_STREQ( "cannot crate a hexagon with a negative side", e.what() );
            throw;
        }
    }, std::invalid_argument);
}

TEST(EasyMathHexagonTest, HexagonArea) {
    Hexagon<double> a = Hexagon<double>(3);
    ASSERT_FLOAT_EQ(23.38269, a.area());
}
 
TEST(EasyMathHexagonTest, HexagonPerimeter) {
    Hexagon<double> a = Hexagon<double>(3);
    ASSERT_FLOAT_EQ(18, a.perimeter());
}

TEST(EasyMathHexagonTest, HexagonDiagonal) {
    Hexagon<double> a = Hexagon<double>(1);
    ASSERT_FLOAT_EQ(2, a.diagonal());
}