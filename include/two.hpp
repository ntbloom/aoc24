#pragma once

#include "day.hpp"

namespace aoc
{
class Two final : public Day<size_t>
{
  public:
    Two ();

    ~Two () final;

    static bool isSafe (const vector<int> &vec);

    static bool isSafe2 (const vector<int> &vec);

    static bool secondTry (const vector<int> &vec);

    size_t one () final;

    size_t two () final;

    size_t answerOne () final;

    size_t answerTwo () final;
};
} // aoc
