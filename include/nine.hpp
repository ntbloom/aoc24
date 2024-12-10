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

    struct Block
    {
        string ch;
        int fileId;
    };

    using disk_map_t = vector<shared_ptr<Block>>;
    disk_map_t diskMap{};

    void parse (const string &input);
    void sort ();
    int getChecksum ();
    void printLine ();
};
} // aoc
