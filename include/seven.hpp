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

    using operators_t = string;

    static long getCalibration (const Seven::equation_t &eq);
    static long getCalibrationWithCat (const Seven::equation_t &eq);
    static long calculate (const remaining_t &nums, operators_t &operators, long target);
    static long calculateWithCat (const remaining_t &nums, operators_t &operators, long target);

    static void makeStrings (size_t len, unordered_set<string> *options);
    static void appendString (string &str, char ch, size_t len, unordered_set<string> *options);
};
} // aoc
