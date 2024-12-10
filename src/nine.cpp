#include "nine.hpp"

namespace aoc
{

int
Nine::answerOne ()
{
    return -1;
}

int
Nine::answerTwo ()
{
    return -2;
}

Nine::Nine () : Day<int> (9)
{
    string line;
    getline (this->filestream, line);
    assert (!line.empty ());
    for (auto ch : line)
        {
            this->diskMap.emplace_back (ch);
        }
}

Nine::~Nine () = default;

int
Nine::one ()
{
    string parsed{};
    this->parse (this->diskMap, &parsed);
    this->sortMap (parsed);
    return this->getChecksum (parsed);
}

int
Nine::two ()
{
    return -2;
}
void
Nine::parse (const Nine::disk_map_t &dm, string *src)
{
    (void)dm;
    (void)src;
}

void
Nine::sortMap (const string &str)
{
    (void)str;
}

int
Nine::getChecksum (const string &sorted)
{
    (void)sorted;
    return 0;
}

} // aoc