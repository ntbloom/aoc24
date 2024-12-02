#ifndef AOC23_ONE_HPP
#define AOC23_ONE_HPP

#include "day.hpp"

#include <vector>
#include <unordered_map>

namespace aoc {
    class One final : public Day<size_t> {
    public:
        One();

        ~One() final;

        size_t one() final;

        size_t two() final;

    private:
        std::vector<size_t> left, right;

        std::unordered_map<size_t, size_t> occurrences;
    };
} // aoc

#endif // AOC23_ONE_HPP
