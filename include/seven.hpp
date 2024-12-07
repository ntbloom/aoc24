#pragma once

#include "day.hpp"

namespace aoc
{
class Seven final : public Day<long>
{
  public:
    Seven ();

    ~Seven () final;

    long one () final;

    long two () final;

    long answerOne () final;

    long answerTwo () final;

  private:
    using equation = pair<long, vector<long>>;
    vector<shared_ptr<equation>> equations{};

    long getCalibration (const Seven::equation &eq);
};
} // aoc
