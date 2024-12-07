#include <fstream>
#include <gtest/gtest.h>

// clang-format off
//#include "one.hpp"
//#include "two.hpp"
//#include "three.hpp"
//#include "four.hpp"
//#include "five.hpp"
//#include "six.hpp"
#include "seven.hpp"
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

class TestSeven : public testing::Test
{
  protected:
    shared_ptr<Seven> seven = make_shared<Seven> ();
};

TEST_F (TestSeven, Calculate) {}