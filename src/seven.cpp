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
    long count = 0;
    for (const auto &eq : this->equations)
        {
            count += getCalibrationWithCat (*eq);
        }
    assert (count > 770405823023);
    return count;
}

long
Seven::getCalibration (const Seven::equation_t &eq)
{
    auto total = eq.first;
    auto numbers = eq.second;
    string allAdd{};
    string allMult{};
    for (auto i = 0; i < numbers.size () - 1; i++)
        {
            allMult += 'm';
            allAdd += 'a';
        }
    unordered_set<string> possibles{};
    possibles.insert (allAdd);
    possibles.insert (allMult);
    auto operations = allMult;
    for (auto i = 0; i < numbers.size () - 1; i++)
        {
            operations.at (i) = 'a';
            possibles.insert (operations);
            while (std::next_permutation (operations.begin (), operations.end ()))
                {
                    possibles.insert (operations);
                }
        }
    for (auto line : possibles)
        {
            if (calculate (numbers, line, total) == total)
                {
                    return total;
                }
        }
    return 0;
}

long
Seven::getCalibrationWithCat (const Seven::equation_t &eq)
{
    auto total = eq.first;
    auto numbers = eq.second;
    auto *possibles = new unordered_set<string> ();
    makeStrings (numbers.size () - 1, possibles);
    if (numbers.size () == 3)
        {
            cout << "";
        }
    for (auto line : *possibles)
        {
            if (calculateWithCat (numbers, line, total) == total)
                {
                    delete possibles;
                    return total;
                }
        }
    delete possibles;
    return 0;
}

long
Seven::calculate (const Seven::remaining_t &nums, Seven::operators_t &operators, long target)
{
    long answer = nums.at (0);
    for (size_t i = 1, opIdx = 0; i < nums.size (); i++, opIdx++)
        {
            if (answer > target)
                {
                    return answer;
                }
            char op = operators.at (opIdx);
            auto number = nums.at (i);
            switch (op)
                {
                case 'm':
                    answer *= number;
                    break;
                case 'a':
                    answer += number;
                    break;
                default:
                    throw std::runtime_error ("Illegal operator");
                }
        }
    return answer;
}

long
Seven::calculateWithCat (const Seven::remaining_t &nums, Seven::operators_t &operators, long target)
{
    long answer = nums.at (0);
    for (size_t i = 1, opIdx = 0; i < nums.size (); i++, opIdx++)
        {
            if (answer > target)
                {
                    return answer;
                }
            char op = operators.at (opIdx);
            auto number = nums.at (i);
            switch (op)
                {
                case 'm':
                    answer *= number;
                    break;
                case 'a':
                    answer += number;
                    break;
                case 'c':
                    char *end;
                    answer = strtol (format ("{}{}", answer, number).c_str (), &end, 10);
                    break;
                default:
                    throw std::runtime_error ("Illegal operator");
                }
        }
    return answer;
}

void
Seven::makeStrings (size_t len, unordered_set<string> *options)
{
    string str{};
    if (len == 2)
        {
            cout << "";
        }
    for (size_t m = 0; m < len + 1; m++)
        {
            for (size_t a = 0; a < len - m + 1; a++)
                {
                    auto c = len - m - a;
                    assert (m + a + c == len);
                    for (size_t i = 0; i < m; i++)
                        {
                            str += 'm';
                        }
                    for (size_t i = 0; i < a; i++)
                        {
                            str += 'a';
                        }
                    for (size_t i = 0; i < c; i++)
                        {
                            str += 'c';
                        }

                    assert (str.size () == len);
                    cout << str << "\n";
                    options->insert (str);
                    while (std::next_permutation (str.begin (), str.end ()))
                        {
                            options->insert (str);
                        }
                    str.clear ();
                }
        }
}

long
Seven::answerOne ()
{
    return 850435817339;
}

long
Seven::answerTwo ()
{
    return -2;
}
} // aoc