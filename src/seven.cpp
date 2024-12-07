#include "seven.hpp"

namespace aoc
{

Seven::Seven () : Day<long> (7)
{
    regex pattern ("(\\d+)");
    size_t idx = 0;
    while (this->filestream)
        {
            string line{};
            getline (this->filestream, line);
            if (line.empty ())
                {
                    break;
                }
            char *end;
            long first = strtol (line.substr (0, line.find (':')).c_str (), &end, 10);
            equations.emplace_back (make_shared<equation_t> (first, remaining_t{}));

            std::smatch match;
            const auto leftovers = line.substr (line.find (':') + 1, line.size () - 1);
            string::const_iterator iter (leftovers.cbegin ());
            while (std::regex_search (iter, leftovers.end (), match, pattern))
                {
                    auto size = match.size ();
                    long num = strtol (match[0].str ().c_str (), &end, 10);
                    equations.at (idx)->second.emplace_back (num);
                    iter = match.suffix ().first;
                }
            idx++;
        }
}

Seven::~Seven () = default;

long
Seven::one ()
{
    long count = 0;
    for (const auto &eq : this->equations)
        {
            count += getCalibration (*eq);
        }

    return count;
}

long
Seven::two ()
{
    return -2;
}

long
Seven::getCalibration (const Seven::equation_t &eq)
{
    auto total = eq.first;
    auto numbers = eq.second;
    operators_t allAddition{}, allMultiplication{};
    for (auto i = 0; i < numbers.size () - 1; i++)
        {
            allAddition.push (operation::ADD);
            allMultiplication.push (operation::MULT);
        }
    if ((calculate (numbers, allAddition, total) != 0)
        || (calculate (numbers, allMultiplication, total) != 0))
        {
            return total;
        }

    return 0;
}

long
Seven::calculate (const Seven::remaining_t &nums, Seven::operators_t &operators, long target)
{
    assert (nums.size () == operators.size () + 1);
    long answer = nums.at (0);
    for (size_t i = 1; i < nums.size (); i++)
        {
            if (answer > target)
                {
                    return 0;
                }
            auto current = operators.front ();
            operators.pop ();

            switch (current)
                {
                case operation::MULT:
                    answer *= nums.at (i);
                    break;
                case operation::ADD:
                    answer += nums.at (i);
                    break;
                default:
                    throw std::runtime_error ("Illegal operator");
                }
        }
    assert (operators.empty ());
    return answer;
}

long
Seven::answerOne ()
{
    return -1;
}

long
Seven::answerTwo ()
{
    return -2;
}
} // aoc