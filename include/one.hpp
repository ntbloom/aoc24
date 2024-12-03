#pragma once

#include "day.hpp"

#include <unordered_map>
#include <vector>

namespace aoc
{
class One final : public Day<size_t>
{
  public:
    One ();

    ~One () final;

    size_t one () final;

    size_t two () final;

    size_t answerOne () final;

    size_t answerTwo () final;

  private:
    vector<size_t> left, right;

    unordered_map<size_t, size_t> occurrences;
};
} // aoc
