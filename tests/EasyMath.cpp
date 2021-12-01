#include <gtest/gtest.h>
#include "EasyMath.hpp"

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

TEST(EasyMathSquareTest, Area) {
    square<double> a = square<double>(36);
    ASSERT_EQ(1296, a.area());
}
 

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}