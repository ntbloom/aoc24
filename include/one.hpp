#ifndef AOC23_ONE_HPP
#define AOC23_ONE_HPP

#include "day.hpp"

namespace aoc {
    class One final : public Day<size_t> {
    public:
        One();

        ~One() final;

        size_t one() final;

        size_t two() final;

    private:
        std::vector<size_t> left, right;
    };
} // aoc

#endif // AOC23_ONE_HPP
