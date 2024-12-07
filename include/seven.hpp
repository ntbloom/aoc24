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

    enum class Operation
    {
        OPERATION_UNSET,
        MULT,
        ADD,
        CAT,
    };

    struct Node
    {
        long rawNumber;
        Operation op;
        long result;
        int level;
        Node *parent;
    };

    bool findCalibration (Node *node, const remaining_t &numbers, const long goal,
                          bool withCat = false);
    long cat (long first, long second);
};
} // aoc
