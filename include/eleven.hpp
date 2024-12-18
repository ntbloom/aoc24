#pragma once

#include "day.hpp"

namespace aoc
{

class Eleven final : public Day<uint64_t>
{
  public:
    Eleven ();

    ~Eleven () final;

    uint64_t one () final;

    uint64_t two () final;

    uint64_t answerOne () final;

    uint64_t answerTwo () final;

    uint64_t countStones (const string &input, size_t blinks);

    uint64_t countStones (size_t blinks);

  private:
    using memo_t = unordered_map<string, uint64_t>;
    unique_ptr<memo_t> memo = make_unique<memo_t> ();

    void parse (const string &input, vector<uint64_t> &numbers);
    uint64_t getCount (uint64_t stone, size_t round, size_t blinks) const;
};
} // aoc
