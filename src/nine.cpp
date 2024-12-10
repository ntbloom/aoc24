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

Nine::Nine () : Day<int> (9) {}

Nine::~Nine () = default;

int
Nine::one ()
{
    string line;
    getline (this->filestream, line);
    parse (line);
    printLine ();

    sort ();

    int answer = getChecksum ();
    assert (answer > 800232992);
    return answer;
}

int
Nine::two ()
{
    return -2;
}

void
Nine::parse (const string &input)
{
    int idx = 0;
    int i = 0;
    for (auto ch : input)
        {
            auto num = static_cast<int> (ch - 48);
            auto even = i % 2 == 0;
            for (auto j = 0; j < num; j++)
                {
                    if (even)
                        {
                            this->diskMap.emplace_back (
                                make_shared<Block> (format ("{}", idx), idx));
                        }
                    else
                        {
                            this->diskMap.emplace_back (make_shared<Block> (".", 0));
                        }
                }
            if (even && num != 0)
                {
                    idx++;
                }
            i++;
        }
}

void
Nine::sort ()
{
    size_t start = 0;
    size_t end = this->diskMap.size () - 1;

    while (start <= end)
        {
            if (this->diskMap.at (start)->ch == ".")
                {
                    this->diskMap.at (start)->ch = this->diskMap.at (end)->ch;
                    this->diskMap.at (start)->fileId = this->diskMap.at (end)->fileId;
                    this->diskMap.at (end)->ch = '.';
                    this->diskMap.at (end)->fileId = 0;
                    end--;
                    while (this->diskMap.at (end)->ch == ".")
                        {
                            end--;
                        }
                }
            start++;
        }
    bool allNumbers = true;
    for (auto &block : this->diskMap)
        {
            if (block->ch == ".")
                {
                    allNumbers = false;
                }
            if (!allNumbers)
                {
                    if (block->ch != ".")
                        {
                            throw std::runtime_error ("shouldn't have any dots left");
                        }
                }
        }
}

int
Nine::getChecksum ()
{
    int total = 0;
    int prevTotal = 0;
    int idx = 0;
    for (const auto &block : this->diskMap)
        {
            if (prevTotal > total)
                {
                    throw std::runtime_error ("Overflow");
                }
            total += idx++ * block->fileId;
            prevTotal = total;
        }
    return total;
}

[[maybe_unused]] void
Nine::printLine ()
{
    for (const auto &block : this->diskMap)
        {
            cout << block->fileId << " ";
        }
    cout << "\n";
}
}
// aoc