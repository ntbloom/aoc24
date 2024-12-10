#pragma once

#include "day.hpp"

namespace aoc
{
class Nine final : public Day<int>
{
  public:
    Nine ();

    ~Nine () final;

    int one () final;

    int two () final;

    int answerOne () final;

    int answerTwo () final;

  private:
};
} // aoc
