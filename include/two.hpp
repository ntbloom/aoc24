#pragma once

#include "day.hpp"

namespace aoc
{
class Two final : public Day<size_t>
{
  public:
    Two();

    ~Two() final;

    size_t one () final;

    size_t two () final;
};
} // aoc
