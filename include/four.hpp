#pragma once

#include "day.hpp"

namespace aoc
{
class Four final : public Day<size_t>
{
  public:
    Four ();

    ~Four () final;

    size_t one () final;

    size_t two () final;

    size_t answerOne () final;

    size_t answerTwo () final;

  private:
    static constexpr size_t northLimit = 3;
    static constexpr size_t southLimit = 136;
    static constexpr size_t eastLimit = 136;
    static constexpr size_t westLimit = 3;

    static constexpr size_t XnorthLimit = 1;
    static constexpr size_t XsouthLimit = 138;
    static constexpr size_t XeastLimit = 138;
    static constexpr size_t XwestLimit = 1;

    static constexpr const string targetWord{ "XMAS" };

    char wordSearch[140][140];

    size_t checkNorth (size_t row, size_t col);
    size_t checkSouth (size_t row, size_t col);
    size_t checkEast (size_t row, size_t col);
    size_t checkWest (size_t row, size_t col);
    size_t checkNorthwest (size_t row, size_t col);
    size_t checkNortheast (size_t row, size_t col);
    size_t checkSoutheast (size_t row, size_t col);
    size_t checkSouthwest (size_t row, size_t col);
    size_t checkXmas (size_t row, size_t col);
};
} // aoc
