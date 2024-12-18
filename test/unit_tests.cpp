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
#include "eleven.hpp"
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

TEST (NineTest, FullPathway)
{
    string input ("2333133121414131402");
    auto nine = make_shared<Nine> ();
    nine->parse (input);
    nine->sort ();
    ASSERT_EQ (nine->getChecksum (), 1928);
}

TEST (NineTest, SampleWithTwoDigitIndex)
{
    string input ("233313312141413140259022");
    auto nine = make_shared<Nine> ();
    nine->parse (input);
    nine->sort ();
    nine->getChecksum ();
}

class TestEleven : public testing::TestWithParam<std::pair<int, int>>
{
  protected:
    unique_ptr<Eleven> eleven = make_unique<Eleven> ();
    int blinks = GetParam ().first;
    int expected = GetParam ().second;
};

TEST_P (TestEleven, Blinks)
{
    string input ("125 17");
    ASSERT_EQ (eleven->countStones (input, blinks), expected);
}
TEST_P (TestEleven, Part1)
{
    auto expected = eleven->answerOne ();
    auto actual = eleven->countStones (25);
    ASSERT_EQ (actual, expected);
}

INSTANTIATE_TEST_SUITE_P (TestElevenWithParam, TestEleven,
                          testing::Values (std::pair<int, int> (6, 22),
                                           std::pair<int, int> (25, 55312)));