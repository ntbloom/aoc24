#include "eleven.hpp"

namespace aoc
{

uint64_t
Eleven::answerOne ()
{
    return 188902;
}

uint64_t
Eleven::answerTwo ()
{
    return 223894720281135;
}

Eleven::Eleven () : Day<uint64_t> (11) {}

Eleven::~Eleven () = default;

uint64_t
Eleven::one ()
{
    return countStones (25);
}

uint64_t
Eleven::two ()
{
    return countStones (75);
}

void
Eleven::parse (const string &input, vector<uint64_t> &numbers)
{
    std::smatch match;
    regex pattern ("(\\d+)");
    string::const_iterator iter (input.cbegin ());
    char *end;
    while (std::regex_search (iter, input.end (), match, pattern))
        {
            long num = strtol (match[0].str ().c_str (), &end, 10);
            numbers.emplace_back (num);
            iter = match.suffix ().first;
        }
}

uint64_t
Eleven::countStones (size_t blinks)
{
    string line;
    getline (this->filestream, line);

    return countStones (line, blinks);
}

uint64_t
Eleven::countStones (const string &input, size_t blinks)
{
    vector<uint64_t> stones{};
    parse (input, stones);
    uint64_t total = 0;
    for (const auto &stone : stones)
        {
            total += getCount (stone, 0, blinks);
        }
    return total;
}

uint64_t
Eleven::getCount (uint64_t stone, size_t round, size_t blinks) const
{
    uint64_t stones = 0;
    if (round == blinks)
        {
            return 1;
        }
    auto combined = format ("{},{}", stone, round);
    if (memo->contains (combined))
        {
            return memo->at (combined);
        }

    if (stone == 0)
        {
            stones = getCount (1, round + 1, blinks);
            memo->insert (std::pair{ combined, stones });
            return stones;
        }
    else
        {
            auto asStr = format ("{}", stone);
            auto even = format ("{}", stone).size () % 2 == 0;
            if (even)
                {
                    auto left = asStr.substr (0, asStr.size () / 2);
                    auto right = asStr.substr (asStr.size () / 2, asStr.size () - 1);
                    char *end;
                    for (auto &str : { left, right })
                        {
                            auto newVal = static_cast<uint64_t> (strtol (str.c_str (), &end, 10));
                            stones += getCount (newVal, round + 1, blinks);
                        }
                    memo->insert (std::pair{ combined, stones });
                    return stones;
                }
        }
    {
        auto newVal = stone * 2024;
        stones = getCount (newVal, round + 1, blinks);
        memo->insert (std::pair{ combined, stones });
        return stones;
    }
}

} // aoc