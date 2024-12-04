#include "one.hpp"
#include <cmath>

namespace aoc
{

One::One () : Day<size_t> (1)
{
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
    assert (left.size () == right.size ());
}

One::~One () = default;

size_t
One::one ()
{
    std::sort (this->left.begin (), this->left.end ());
    std::sort (this->right.begin (), this->right.end ());

    size_t answer = 0;
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
size_t
One::answerOne ()
{
    return 1651298;
}

size_t
One::answerTwo ()
{
    return 21306195;
}

} // aoc