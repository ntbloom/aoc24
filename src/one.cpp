#include "one.hpp"
#include <cmath>

aoc::One::One() : Day<size_t>(1) {}

size_t
aoc::One::one() {
    size_t answer = 0;
    assert (this->filestream);
    while (this->filestream) {
        std::string line;
        std::getline(this->filestream, line);
        if (line.compare("") == 0) {
            break;
        }

        static constexpr auto beginOne = 0;
        static constexpr auto beginTwo = 8;
        static constexpr auto size = 5;
        auto first = static_cast<size_t>(std::stoi(line.substr(beginOne, size)));
        auto second = static_cast<size_t>(std::stoi(line.substr(beginTwo, size)));
        this->left.emplace_back(first);
        this->right.emplace_back(second);
    }
    std::sort(this->left.begin(), this->left.end());
    std::sort(this->right.begin(), this->right.end());
    assert(left.size() == right.size());

    for (size_t i = 0; i < left.size(); i++) {
        answer += std::abs(static_cast<long>((left.at(i) - right.at(i))));
    }
    return answer;
}

size_t
aoc::One::two() {
    return -2;
}

aoc::One::~One() = default;
