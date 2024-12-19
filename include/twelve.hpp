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
    using region_t = int;
    struct Plant
    {
        int row;
        int col;
        char type;
        bool visited = false;
        region_t region = -1;
        bool internal = true;

        Plant *up = nullptr;
        Plant *down = nullptr;
        Plant *left = nullptr;
        Plant *right = nullptr;
    };

    int regionCounter = 0;
    using mapRow_t = vector<shared_ptr<Plant>>;
    vector<mapRow_t> map{};
    vector<Plant *> regionStarts{};

    void findRegion (Plant *plant);
    bool isInternal (Plant *plant);

    [[maybe_unused]] void printMap ();
    [[maybe_unused]] void printAllRegions ();
};
} // aoc
