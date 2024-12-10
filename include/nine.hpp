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

    using disk_map_t = vector<char>;
    disk_map_t diskMap{};

    void parse (const disk_map_t &dm, string *src);
    void sortMap (const string &str);
    int getChecksum (const string &sorted);

  private:
};
} // aoc
