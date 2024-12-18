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
    struct Plant
    {
        int row;
        int col;
        char type;
    };

    struct Region
    {
    };

    using mapRow_t = vector<shared_ptr<Plant>>;
    vector<mapRow_t> map;

    void printMap ();
};
} // aoc
