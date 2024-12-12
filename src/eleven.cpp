#include "eleven.hpp"

namespace aoc
{

eleven_t
Eleven::answerOne ()
{
    return -1;
}

eleven_t
Eleven::answerTwo ()
{
    return -2;
}

Eleven::Eleven () : Day<eleven_t> (11) {}

Eleven::~Eleven () = default;

eleven_t
Eleven::one ()
{
    string line;
    getline (this->filestream, line);
    return countStones (line, 25);
}

eleven_t
Eleven::two ()
{
    return -2;
}

void
Eleven::parse (const string &input)
{
    std::smatch match;
    regex pattern ("(\\d+)");
    string::const_iterator iter (input.cbegin ());
    char *end;
    changes.emplace_back (make_unique<stones_t> ());
    auto numbers = changes.at (0).get ();
    while (std::regex_search (iter, input.end (), match, pattern))
        {
            long num = strtol (match[0].str ().c_str (), &end, 10);
            numbers->emplace_back (num);
            iter = match.suffix ().first;
        }
    //    print (*changes.at (0));
}

int
Eleven::countStones (const string &input, size_t blinks)
{
    parse (input);
    for (size_t i = 1; i < blinks + 1; i++)
        {
            changes.emplace_back (make_unique<stones_t> ());
            auto prev = changes.at (i - 1).get ();
            auto next = changes.at (i).get ();
            for (const auto &stone : *prev)
                {
                    if (stone == 0)
                        {
                            next->emplace_back (1);
                        }
                    else
                        {
                            auto asStr = format ("{}", stone);
                            auto even = format ("{}", stone).size () % 2 == 0;
                            if (even)
                                {
                                    auto left = asStr.substr (0, asStr.size () / 2);
                                    auto right
                                        = asStr.substr (asStr.size () / 2, asStr.size () - 1);
                                    char *end;
                                    for (auto &str : { left, right })
                                        {
                                            auto stoneValue = static_cast<uint64_t> (
                                                strtol (str.c_str (), &end, 10));
                                            next->emplace_back (stoneValue);
                                        }
                                }
                            else
                                {
                                    next->emplace_back (stone * 2024);
                                }
                        }
                }
            //            print (*next);
            //            cout << "";
        }
    auto size = changes.back ()->size ();
    changes.clear ();
    return size;
}
void
Eleven::print (const Eleven::stones_t &stones)
{
    for (const auto &stone : stones)
        {
            cout << stone << " ";
        }
    cout << "\n";
}
} // aoc