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
    using remaining_t = vector<long>;
    using equation_t = pair<long, remaining_t>;
    vector<shared_ptr<equation_t>> equations{};

    long getCalibration (const Seven::equation_t &eq);

    enum class operation : uint8_t
    {
        MULT,
        ADD,
    };
    using operators_t = queue<operation>;
    long calculate (const remaining_t &nums, operators_t &operators, long target);
};
} // aoc
