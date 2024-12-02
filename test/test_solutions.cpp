#include <gtest/gtest.h>

// clang-format off
#include "one.hpp"
// clang-format on

using namespace aoc;

TEST (Test_Solutions, One_ONE)
{
    One one{};
    EXPECT_EQ (one.solve (1), 1651298);
}

TEST (Test_Solutions, One_TWO)
{
    One one{};
    EXPECT_EQ (one.solve (2), 21306195);
}
