#include <fstream>
#include <gtest/gtest.h>

// clang-format off
#include "day.hpp"
//#include "one.hpp"
//#include "two.hpp"
//#include "three.hpp"
//#include "four.hpp"
//#include "five.hpp"
//#include "six.hpp"
//#include "seven.hpp"
//#include "eight.hpp"
#include "nine.hpp"
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

class EightTest : public testing::Test
{
};

TEST_F (EightTest, Parse)
{
    auto testString = make_shared<string> ();
    ASSERT_TRUE (testString->empty ());
    Nine::parse (Nine::disk_map_t{ 1, 2, 3, 4, 5 }, testString.get ());
    ASSERT_FALSE (testString->empty ());
    ASSERT_STREQ (testString->c_str (), "0..111....22222");
}