#include "eight.hpp"

namespace aoc
{

int
Eight::answerOne ()
{
    return 396;
}

int
Eight::answerTwo ()
{
    return 1200;
}

Eight::Eight () : Day<int> (8)
{
    for (auto i = 0; i < 50; i++)
        {
            this->map->at (i) = new row_t ();
        }
    size_t rowCount = 0;
    while (this->filestream)
        {
            string line;
            getline (this->filestream, line);
            if (line.empty ())
                {
                    break;
                }
            size_t column = 0;
            for (const auto ch : line)
                {
                    this->map->at (rowCount)->at (column) = new Node (rowCount, column, ch);

                    column++;
                }
            rowCount++;
        }

    for (const auto &row : *this->map)
        {
            for (const auto &node : *row)
                {
                    auto freq = node->frequency;
                    if (freq != '.')
                        {
                            if (!pairings->contains (freq))
                                {
                                    pairings->insert (std::pair<char, shared_ptr<nodeset_t>> (
                                        freq, new nodeset_t ()));
                                }
                            pairings->at (freq)->emplace_back (node);
                        }
                }
        }
}

Eight::~Eight () = default;

int
Eight::one ()
{
    for (const auto &pairs : *this->pairings)
        {
            auto nodeset = pairs.second;
            findPairs (nodeset.get (), false);
        }
    int count = 0;
    for (const auto &line : *this->map)
        {
            for (const auto *node : *line)
                {
                    if (node->hasAntinode)
                        {
                            count++;
                        }
                }
        }
    return count;
}

int
Eight::two ()

{
    for (const auto &pairs : *this->pairings)
        {
            auto nodeset = pairs.second;
            findPairs (nodeset.get (), true);
        }
    int count = 0;
    for (const auto &line : *this->map)
        {
            for (const auto *node : *line)
                {
                    if (node->hasAntinode)
                        {
                            count++;
                        }
                }
        }
    return count;
}

void
Eight::printMap ()
{
    for (const auto &line : *this->map)
        {
            for (const auto node : *line)
                {
                    if (node->markedbylowercaseb)
                        {
                            cout << termcolor::RED << node->frequency << termcolor::RESET;
                        }
                    else
                        {
                            cout << node->frequency;
                        }
                }
            cout << "\n";
        }
}

void
Eight::findPairs (const Eight::nodeset_t *nodeset, bool all)
{
    auto size = nodeset->size ();
    if (nodeset->size () == 2)
        {
            if (all)
                {
                    findAllAntinodes (nodeset->at (0), nodeset->at (1));
                }
            else
                {

                    findAntinode (nodeset->at (0), nodeset->at (1));
                }
            return;
        }
    for (auto i = 0; i < nodeset->size (); i++)
        {
            auto newNodeset = make_shared<nodeset_t> (*nodeset);
            newNodeset->erase (newNodeset->begin () + i);
            findPairs (newNodeset.get (), all);
        }
}

void
Eight::findAntinode (const Eight::Node *one, const Eight::Node *two)
{
    auto upper = one->row < two->row ? one : two;
    auto lower = one == upper ? two : one;

    auto rise = lower->row - upper->row;
    auto run = upper->col - lower->col;

    auto upperRow = upper->row - rise;
    auto upperCol = upper->col + run;
    if (upperRow >= 0 && upperCol >= 0 && upperCol <= 49)
        {
            this->map->at (upperRow)->at (upperCol)->hasAntinode = true;
        }

    auto lowerRow = lower->row + rise;
    auto lowerCol = lower->col - run;
    if (lowerRow <= 49 && lowerCol >= 0 && lowerCol <= 49)
        {
            this->map->at (lowerRow)->at (lowerCol)->hasAntinode = true;
        }
}

void
Eight::findAllAntinodes (const Eight::Node *one, const Eight::Node *two)
{
    auto upper = one->row < two->row ? one : two;
    auto lower = one == upper ? two : one;
    for (const auto &node : { upper, lower })

        {

            this->map->at (node->row)->at (node->col)->hasAntinode = true;
        }

    auto rise = lower->row - upper->row;
    auto run = upper->col - lower->col;

    auto upperRow = upper->row - rise;
    auto upperCol = upper->col + run;
    while (upperRow >= 0 && upperCol >= 0 && upperCol <= 49)
        {
            this->map->at (upperRow)->at (upperCol)->hasAntinode = true;
            upperRow -= rise;
            upperCol += run;
        }

    auto lowerRow = lower->row + rise;
    auto lowerCol = lower->col - run;
    while (lowerRow <= 49 && lowerCol >= 0 && lowerCol <= 49)
        {
            this->map->at (lowerRow)->at (lowerCol)->hasAntinode = true;
            lowerRow += rise;
            lowerCol -= run;
        }
}

} // aoc