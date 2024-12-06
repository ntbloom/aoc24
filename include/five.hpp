#pragma once

#include "day.hpp"

namespace aoc
{
class Five final : public Day<int>
{
  public:
    Five ();

    ~Five () final;

    int one () final;

    int two () final;

    int answerOne () final;

    int answerTwo () final;

  private:
    using order = std::pair<int, int>;
    vector<order> orders;

    using update = vector<int>;
    vector<update> updates;

    using updateMap = unordered_map<int, unordered_set<int>>;
    shared_ptr<updateMap> befores = make_shared<updateMap> ();

    bool isValid (const update &update);
    int fix (update &update);
};
} // aoc
