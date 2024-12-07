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

    assert (count > 654933917946);
    assert (count < 175653415269101);
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
    string operations{};
    for (auto i = 0; i < numbers.size () - 1; i++)
        {
            operations += 'm';
        }
    assert (operations.size () == numbers.size () - 1);
    if (calculate (numbers, operations, total) != 0)
        {
            cout << "all mult works";
            return total;
        }
    for (auto i = 0; i < numbers.size () - 1; i++)
        {
            operations.at (i) = 'a';
            while (std::next_permutation (operations.begin (), operations.end ()))
                {
                    if (calculate (numbers, operations, total) != 0)
                        {
                            cout << "all add works" << endl;
                            return total;
                        }
                }
        }

    return 0;
}

long
Seven::calculate (const Seven::remaining_t &nums, Seven::operators_t &operators, long target)
{
    cout << operators << endl;
    assert (nums.size () - 1 == operators.size ());

    long answer = nums.at (0);
    for (size_t i = 1, opIdx = 0; i < nums.size (); i++, opIdx++)
        {
            if (answer > target)
                {
                    return 0;
                }
            char op = operators.at (opIdx);
            switch (op)
                {
                case 'm':
                    answer *= nums.at (opIdx);
                    break;
                case 'a':
                    answer += nums.at (opIdx);
                    break;
                default:
                    throw std::runtime_error ("Illegal operator");
                }
        }
    return answer == target ? answer : 0;
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