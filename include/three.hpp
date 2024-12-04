#pragma once

#include "day.hpp"

namespace aoc
{
class Three final : public Day<size_t>
{
  public:
    Three ();

    ~Three () final;

    size_t one () final;

    size_t two () final;

    size_t answerOne () final;

    size_t answerTwo () final;

  private:
    string complete;

    static size_t process (const string &line);
};
} // aoc
