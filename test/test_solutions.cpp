#include <gtest/gtest.h>

// clang-format off
#include "one.hpp"
#include "two.hpp"
#include "three.hpp"
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
using std::make_unique;

template <typename T> class TestDay : public testing::Test
{
  public:
    void
    testOne ()
    {
        auto day = make_unique<T> ();
        ASSERT_EQ (day->solve (1), day->answerOne ());
    }

    void
    testTwo ()
    {
        auto day = make_unique<T> ();
        ASSERT_EQ (day->solve (2), day->answerTwo ());
    }
};
TYPED_TEST_SUITE_P (TestDay);

TYPED_TEST_P (TestDay, PartOne) { this->testOne (); }
TYPED_TEST_P (TestDay, PartTwo) { this->testTwo (); }

REGISTER_TYPED_TEST_SUITE_P (TestDay, PartOne, PartTwo);

using dayTypes = ::testing::Types<One, Two, Three
                                  //    ,Four
                                  //    ,Five
                                  //    ,Six
                                  //    ,Seven
                                  //    ,Eight
                                  //    ,Nine
                                  //    ,Ten
                                  //    ,Eleven
                                  //    ,Twelve
                                  //    ,Thirteen
                                  //    ,Fourteen
                                  //    ,Fifteen
                                  //    ,Sixteen
                                  //    ,Seventeen
                                  //    ,Eighteen
                                  //    ,Nineteen
                                  //    ,Twenty
                                  //    ,TwentyOne
                                  //    ,TwentyTwo
                                  //    ,TwentyThree
                                  //    ,TwentyFour
                                  //    ,TwentyFive
                                  >;
INSTANTIATE_TYPED_TEST_SUITE_P (ParametrizedDayTests, TestDay, dayTypes);
