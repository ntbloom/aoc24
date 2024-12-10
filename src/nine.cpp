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
            this->diskMap.emplace_back (static_cast<int> (ch - 48));
        }
}

Nine::~Nine () = default;

int
Nine::one ()
{
    string parsed{};
    parse (this->diskMap, &parsed);
    sortMap (parsed);
    return getChecksum (parsed);
}

int
Nine::two ()
{
    return -2;
}
void
Nine::parse (const Nine::disk_map_t &dm, string *src)
{
    assert (src->empty ());
    int idx = 0;
    for (auto i = 0; i < dm.size (); i++)
        {
            auto num = dm.at (i);
            bool even = i == 0 || (i % 2 == 0);
            for (auto j = 0; j < num; j++)
                {
                    if (even)
                        {
                            src->append (format ("{}", idx));
                        }
                    else
                        {
                            src->append (".");
                        }
                }
            if (even)
                {
                    idx++;
                }
        }
    return;
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