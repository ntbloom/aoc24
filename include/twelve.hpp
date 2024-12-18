#pragma once

#include "day.hpp"

namespace aoc
{
class Twelve final : public Day<int>
{
  public:
    Twelve ();

    ~Twelve () final;

    int one () final;

    int two () final;

    int answerOne () final;

    int answerTwo () final;

  private:
};
} // aoc
