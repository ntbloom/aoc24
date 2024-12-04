#include "three.hpp"

namespace aoc
{

Three::Three () : Day<size_t> (3)
{
    while (this->filestream)
        {
            string line;
            getline (this->filestream, line);
            if (line.empty ())
                {
                    break;
                }
            this->complete += line;
        }
}

Three::~Three () = default;

size_t
Three::one ()
{
    return process (complete);
}

size_t
Three::two ()
{
    size_t answer = 0;
    bool enable = true;
    size_t idx = 0;
    for (size_t i = 0; i < this->complete.size (); i++)
        {
            if (this->complete.substr (i, 5) == "don't")
                {
                    if (enable)
                        {
                            answer += process (this->complete.substr (idx, i - idx));
                            enable = false;
                        }
                }
            else if (this->complete.substr (i, 2) == "do")
                {
                    if (!enable)
                        {
                            idx = i;
                            enable = true;
                        }
                }
        }
    if (enable)
        {
            answer += process (this->complete.substr (idx, this->complete.size () - idx));
        }

    return answer;
}

size_t
Three::process (const string &line)
{
    size_t answer = 0;
    regex digitPattern (R"(mul\((\d+),(\d+)\))");

    std::smatch match;
    string::const_iterator iter (line.cbegin ());
    while (std::regex_search (iter, line.end (), match, digitPattern))
        {
            assert (match.size () == 3);
            answer += stoi (match[1]) * stoi (match[2]);
            iter = match.suffix ().first;
        }
    return answer;
}

size_t
Three::answerOne ()
{
    return 188192787;
}

size_t
Three::answerTwo ()
{
    return 113965544;
}

} // aoc