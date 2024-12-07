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
            equations.emplace_back (make_shared<equation> (first, vector<long>{}));

            std::smatch match;
            const auto remaining = line.substr (line.find (':') + 1, line.size () - 1);
            string::const_iterator iter (remaining.cbegin ());
            while (std::regex_search (iter, remaining.end (), match, pattern))
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
Seven::getCalibration (const Seven::equation &eq)
{
    auto total = eq.first;
    auto numbers = eq.second;

    if (accumulate (numbers.begin (), numbers.end (), 0) == total)
        {
            return total;
        }
    const auto product = [] (const vector<long> &_nums) {
        long answer = 0;
        for (size_t i = 1; i < _nums.size (); i++)
            {
                answer += _nums.at (i) * _nums.at (i - 1);
            }
        return answer;
    };
    if (product (numbers) == total)
        {
            return total;
        };

    return 0;
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