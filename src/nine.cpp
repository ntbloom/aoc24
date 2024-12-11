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

    sort ();

    int answer = getChecksum ();
    cout << format ("answer={}", answer) << endl;
    assert (answer != 1065085117);
    assert (answer != 800232992);
    assert (answer != 2102453279);
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
    this->lineSize = input.size ();
    int idx = 0;
    bool even;
    for (auto i = 0; i < input.size (); i++)
        {
            auto ch = input.at (i);
            auto num = static_cast<int> (ch - 48);
            string asStr{};
            asStr += (ch);
            if (asStr != format ("{}", num))
                {
                    throw std::runtime_error ("misread");
                }

            even = i % 2 == 0;
            if (num == 0)
                {
                    assert (!even);
                }
            for (auto j = 0; j < num; j++)
                {
                    if (even)
                        {
                            this->diskMap.emplace_back (make_shared<Block> (idx, false));
                        }
                    else
                        {
                            this->diskMap.emplace_back (make_shared<Block> (0, true));
                        }
                }

            if (even)
                {
                    idx++;
                }
        }
}

void
Nine::sort ()
{
    size_t start = 0;
    size_t end = this->diskMap.size () - 1;
    while (this->diskMap.at (end)->empty)
        {
            end--;
        }
    Block *front, *back;
    while (start < end)
        {
            front = this->diskMap.at (start++).get ();
            if (front->empty)
                {
                    back = this->diskMap.at (end--).get ();
                    assert (!back->empty);
                    assert (back->fileId != 0);
                    front->fileId = back->fileId;
                    front->empty = false;
                    back->fileId = 0;
                    back->empty = true;
                    while (this->diskMap.at (end)->empty)
                        {
                            end--;
                        }
                    if (lineSize < 100)
                        {
                            printLine ();
                        }
                }
        }
    bool allNumbers = true;
    for (auto &block : this->diskMap)
        {
            if (block->empty)
                {
                    allNumbers = false;
                }
            if (!allNumbers)
                {
                    if (block->fileId != 0)
                        {
                            throw std::runtime_error ("mis-sorted");
                        }
                }
        }
}

int
Nine::getChecksum ()
{
    int total = 0;
    int idx = 0;
    for (const auto &bl : this->diskMap)
        {
            auto num = bl->fileId * idx++;
            total += num;
        }
    cout << format ("answer={}", total) << endl;
    return total;
}

[[maybe_unused]] void
Nine::printLine ()
{
    for (const auto &block : this->diskMap)
        {
            if (block->empty)
                {
                    cout << "." << " ";
                }
            else
                {
                    cout << block->fileId << " ";
                }
        }
    cout << endl;
}
}
// aoc