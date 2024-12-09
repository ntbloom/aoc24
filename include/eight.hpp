#pragma once

#include "day.hpp"

namespace aoc
{
class Eight final : public Day<int>
{
  public:
    Eight ();

    ~Eight () final;

    int one () final;

    int two () final;

    int answerOne () final;

    int answerTwo () final;

  private:
    struct Node
    {
        int row;
        int col;
        char frequency;
        bool hasAntinode = false;
        bool markedbylowercaseb = false;
    };
    using row_t = array<Node *, 50>;
    using map_t = array<row_t *, 50>;
    using nodeset_t = vector<Node *>;
    using pairings_t = unordered_map<char, shared_ptr<nodeset_t>>;

    shared_ptr<map_t> map = make_shared<map_t> ();
    shared_ptr<pairings_t> pairings = make_shared<pairings_t> ();

    void printMap ();
    void findAntinode (const Node *one, const Node *two);
    void findAllAntinodes (const Node *one, const Node *two);
    void findPairs (const nodeset_t *nodeset, bool all);
};
} // aoc
