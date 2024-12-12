#pragma once

#include "day.hpp"

namespace aoc
{

using eleven_t = size_t;

class Eleven final : public Day<eleven_t>
{
  public:
    Eleven ();

    ~Eleven () final;

    eleven_t one () final;

    eleven_t two () final;

    eleven_t answerOne () final;

    eleven_t answerTwo () final;

    int countStones (const string &input, size_t blinks);

  private:
    void parse (const string &input);
    using stones_t = vector<eleven_t>;
    using stone_changes_t = vector<unique_ptr<stones_t>>;
    stone_changes_t changes{};

    void print (const stones_t &stones);
};
} // aoc
