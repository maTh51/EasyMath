#include <gtest/gtest.h>
#include "HexagonalPrism.hpp"

TEST(EasyMathHexagonalPrismsTest, HexagonalPrismsNoNegativeSide) {
    EXPECT_THROW({
        try
        {
            HexagonalPrism<double> s = HexagonalPrism<double>(-1, 1);
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
            HexagonalPrism<double> s = HexagonalPrism<double>(1, -1);
        }
        catch(const std::invalid_argument& e )
        {
            EXPECT_STREQ( "cannot crate a hexagonal prism with a negative heigth", e.what() );
            throw;
        }
    }, std::invalid_argument);
}

TEST(EasyMathHexagonalPrismsTest, HexagonalPrismsArea) {
    HexagonalPrism<double> a = HexagonalPrism<double>(3, 3);
    ASSERT_FLOAT_EQ(70.14806, a.volume());
}
 
TEST(EasyMathHexagonalPrismsTest, HexagonalPrismsPerimeter) {
    HexagonalPrism<double> a = HexagonalPrism<double>(3, 1);
    ASSERT_FLOAT_EQ(64.76537, a.area());
}