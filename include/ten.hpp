#pragma once

#include "day.hpp"

namespace aoc
{
class Ten final : public Day<int>
{
  public:
    Ten ();

    ~Ten () final;

    int one () final;

    int two () final;

    int answerOne () final;

    int answerTwo () final;

  private:
    struct Step
    {
        Step *left;
        Step *right;
        Step *up;
        Step *down;

        int height;
        bool visited;

        explicit Step (int height);
    };

    void printMap ();
    using mapline_t = vector<shared_ptr<Step>>;
    using map_t = vector<mapline_t>;
    void populateNeighbors ();

    unordered_set<Step *> trailheads{};
    map_t map{};

    using dfsStack = stack<Step *>;
    using dfsVisits = unordered_set<Step *>;
    int dfs (Step *root);
    void findNeighbors (Step *step, dfsStack &stk, dfsVisits &visits);

    int dfsNoMarking (Step *root);
    void findNeighborsNoMarking (Step *step, dfsStack &stk, dfsVisits &visits);
};
} // aoc
