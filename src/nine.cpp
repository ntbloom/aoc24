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
    unordered_set<char> letters{};
    string line;
    getline (this->filestream, line);
    assert (!line.empty ());
    for (auto ch : line)
        {
            letters.insert (ch);
            this->diskMap.emplace_back (static_cast<int> (ch - 48));
        }
    for (auto ch : letters)
        {
            cout << ch << "\n";
        }
}

Nine::~Nine () = default;

int
Nine::one ()
{
    auto parsed = make_shared<string> ();
    parse (this->diskMap, parsed.get ());
    sortMap (parsed.get ());
    return getChecksum (*parsed);
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
Nine::sortMap (string *str)
{
    swapChars (str, 0, str->size () - 1);
}

int
Nine::getChecksum (const string &sorted)
{
    int total = 0;
    int idx = 0;
    for (auto ch : sorted)
        {
            if (ch != '.')
                {
                    auto num = static_cast<int> (ch - 48);
                    total += num * idx++;
                }
        }
    return total;
}

void
Nine::swapChars (string *str, size_t start, size_t end)
{
    if (start >= end)
        {
            return;
        }
    if (str->at (start) == '.')
        {
            str->at (start) = str->at (end);
            str->at (end--) = '.';
            while (str->at (end) == '.')
                {
                    end--;
                }
        }
    return swapChars (str, ++start, end);
}

} // aoc