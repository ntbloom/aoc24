#include <gtest/gtest.h>

// clang-format off
#include "one.hpp"
#include "two.hpp"
//#include "three.hpp"
//#include "four.hpp"
//#include "five.hpp"
//#include "six.hpp"
//#include "seven.hpp"
//#include "eight.hpp"
//#include "nine.hpp"
//#include "ten.hpp"
//#include "eleven.hpp"
//#include "twelve.hpp"
//#include "thirteen.hpp"
//#include "fourteen.hpp"
//#include "fifteen.hpp"
//#include "sixteen.hpp"
//#include "seventeen.hpp"
//#include "eighteen.hpp"
//#include "nineteen.hpp"
//#include "twenty.hpp"
//#include "twentyone.hpp"
//#include "twentytwo.hpp"
//#include "twentythree.hpp"
//#include "twentyfour.hpp"
//#include "twentyfive.hpp"
// clang-format on

using namespace aoc;

TEST (One, One)
{
    One one{};
    EXPECT_EQ (one.solve (1), 1651298);
}
TEST (One, Two)
{
    One one{};
    EXPECT_EQ (one.solve (2), 21306195);
}

TEST (Two, One)
{
    Two two{};
    EXPECT_EQ (two.solve (1), 510);
}
TEST (Two, Two)
{
    Two two{};
    EXPECT_EQ (two.solve (2), 553);
}