#include "seven.hpp"

namespace aoc
{

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
    for (auto line : this->equations)
        {
            auto goal = line->first;
            auto numbers = line->second;
            auto first = numbers.at (0);
            auto size = numbers.size ();

            auto addNode
                = make_shared<Node> (first, Operation::OPERATION_UNSET, first, size, nullptr);
            if (findCalibration (addNode.get (), numbers, goal, false))
                {
                    count += goal;
                    continue;
                }
        }

    assert (count == 850435817339);
    return count;
}

long
Seven::two ()
{
    long count = 0;
    for (auto line : this->equations)
        {
            auto goal = line->first;
            auto numbers = line->second;
            auto first = numbers[0];
            auto size = numbers.size () - 1;

            auto addNode
                = make_shared<Node> (first, Operation::OPERATION_UNSET, first, size, nullptr);
            if (findCalibration (addNode.get (), numbers, goal, true))
                {
                    count += goal;
                    continue;
                }
        }
    assert (count > 850435817339);
    assert (count != 1299759418016);
    assert (count != 1299662764120);
    return count;
}

bool
Seven::findCalibration (Seven::Node *node, const Seven::remaining_t &numbers, const long goal,
                        bool withCat)
{
    if (node->level == 1)
        {
            return node->result == goal;
        }
    if (node->result > goal)
        {
            return false;
        }
    auto level = node->level - 1;
    auto first = node->result;
    auto second = numbers.at (numbers.size () - level);
    auto addNode = make_shared<Node> (second, Operation::ADD, second + first, level, node);
    if (findCalibration (addNode.get (), numbers, goal, withCat))
        {
            return true;
        }
    auto multNode = make_shared<Node> (second, Operation::MULT, second * first, level, node);
    if (findCalibration (multNode.get (), numbers, goal, withCat))
        {
            return true;
        }
    if (withCat)
        {
            auto catNode
                = make_shared<Node> (second, Operation::CAT, cat (first, second), level, node);
            if (findCalibration (catNode.get (), numbers, goal, withCat))
                {
                    return true;
                }
        }
    return false;
}

long
Seven::cat (long first, long second)
{
    char *end;
    auto res = strtol (format ("{}{}", first, second).c_str (), &end, 10);
    return res;
}

} // aoc