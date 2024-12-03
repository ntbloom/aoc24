#pragma once

#include "day.hpp"

namespace aoc
{
class Template final : public Day<TYPE>
{
  public:
    Template ();

    ~Template () final;

    TYPE one () final;

    TYPE two () final;

    TYPE answerOne () final;

    TYPE answerTwo () final;
};
} // aoc
