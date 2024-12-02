#include "one.hpp"
#include <cmath>

namespace aoc
{

One::One () : Day<size_t> (1) {}

size_t
One::one ()
{
    size_t answer = 0;
    assert (this->filestream);
    while (this->filestream)
        {
            string line;
            getline (this->filestream, line);
            if (line.empty ())
                {
                    break;
                }

            static constexpr auto beginOne = 0;
            static constexpr auto beginTwo = 8;
            static constexpr auto size = 5;
            auto first = static_cast<size_t> (std::stoi (line.substr (beginOne, size)));
            auto second = static_cast<size_t> (std::stoi (line.substr (beginTwo, size)));
            this->left.emplace_back (first);
            this->right.emplace_back (second);
        }
    std::sort (this->left.begin (), this->left.end ());
    std::sort (this->right.begin (), this->right.end ());
    assert (left.size () == right.size ());

    for (size_t i = 0; i < left.size (); i++)
        {
            answer += std::abs (static_cast<long> ((left.at (i) - right.at (i))));
        }
    return answer;
}

size_t
One::two ()
{
    size_t answer = 0;
    assert (this->filestream);
    while (this->filestream)
        {
            string line;
            getline (this->filestream, line);
            if (line.empty ())
                {
                    break;
                }

            static constexpr auto beginOne = 0;
            static constexpr auto beginTwo = 8;
            static constexpr auto size = 5;
            auto first = static_cast<size_t> (std::stoi (line.substr (beginOne, size)));
            auto second = static_cast<size_t> (std::stoi (line.substr (beginTwo, size)));
            this->left.emplace_back (first);
            this->right.emplace_back (second);
        }
    assert (this->left.size () == this->right.size ());

    for (auto num : this->right)
        {
            if (this->occurrences.contains (num))
                {
                    auto current = this->occurrences.at (num);
                    current++;
                    this->occurrences.at (num) = current;
                }
            else
                {
                    this->occurrences.emplace (std::pair<size_t, size_t> (num, 1));
                }
        }

    for (auto num : this->left)
        {
            auto multiplier = this->occurrences.contains (num) ? this->occurrences.at (num) : 0;
            answer += num * multiplier;
        }
    return answer;
}

One::~One () = default;

} // aoc