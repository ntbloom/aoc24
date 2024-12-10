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

    using disk_map_t = vector<int>;
    disk_map_t diskMap{};

    static void parse (const disk_map_t &dm, string *src);
    static void sortMap (const string &str);
    static int getChecksum (const string &sorted);

  private:
};
} // aoc
