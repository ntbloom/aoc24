#include "twelve.hpp"

namespace aoc
{

int
Twelve::answerOne ()
{
    return -1;
}

int
Twelve::answerTwo ()
{
    return -2;
}

Twelve::Twelve () : Day<int> (12)
{
    string line;
    int row = 0;
    for (auto i = 0; i < 140; i++)
        {
            map.emplace_back (vector<shared_ptr<Plant>> ());
            for (auto j = 0; j < 140; j++)
                {
                    map.at (i).emplace_back (make_shared<Plant> ());
                }
        }
    while (this->filestream)
        {
            getline (this->filestream, line);
            if (line.empty ())
                {
                    break;
                }

            int col = 0;
            for (const auto &ch : line)
                {
                    auto ref = map.at (row).at (col);
                    ref->row = row;
                    ref->col = col;
                    ref->type = ch;
                    if (row != 0)
                        {
                            ref->up = map.at (row - 1).at (col).get ();
                        }
                    if (row != 139)
                        {
                            ref->down = map.at (row + 1).at (col).get ();
                        }
                    if (col != 0)
                        {
                            ref->left = map.at (row).at (col - 1).get ();
                        }
                    if (col != 139)
                        {
                            ref->right = map.at (row).at (col + 1).get ();
                        }
                    col++;
                }
            row++;
        }
    for (auto &gardenRow : map)
        {
            for (auto &plant : gardenRow)
                {
                    if (plant->region == -1)
                        {
                            plant->region = ++regionCounter;
                            regionStarts.emplace_back (plant.get ());
                            findRegion (plant.get ());
                        }
                }
        }
    //    printAllRegions ();
    printMap ();
}

Twelve::~Twelve () = default;

int
Twelve::one ()
{
    return -1;
}

int
Twelve::two ()
{
    return -2;
}

void
Twelve::findRegion (aoc::Twelve::Plant *plant)
{
    plant->visited = true;
    vector<Plant *> neighbors{};
    if (plant->row != 0)
        {
            neighbors.emplace_back (plant->up);
        }
    if (plant->row != 139)
        {
            neighbors.emplace_back (plant->down);
        }
    if (plant->col != 0)
        {
            neighbors.emplace_back (plant->left);
        }
    if (plant->col != 139)
        {
            neighbors.emplace_back (plant->right);
        }
    for (const auto &neighbor : neighbors)
        {
            if (!neighbor->visited && neighbor->type == plant->type)
                {
                    neighbor->internal == isInternal (plant);
                    neighbor->region = plant->region;
                    findRegion (neighbor);
                }
        }
}

bool
Twelve::isInternal (Twelve::Plant *plant)
{
    auto type = plant->type;
    if (plant->up == nullptr || plant->up->type != type || plant->left == nullptr
        || plant->left->type != type || plant->right == nullptr || plant->right->type != type
        || plant->down == nullptr || plant->down->type != type)
        {
            return false;
        }
    return true;
}

void
Twelve::printMap ()
{
    termcolor::clear ();
    for (const auto &line : map)
        {
            for (const auto &plant : line)
                {
                    auto ch = plant->type;
                    if (!plant->internal)
                        {
                            cout << termcolor::RED << plant->type << termcolor::RESET;
                        }
                    else
                        {
                            cout << plant->type;
                        }
                }
            cout << "\n";
        }
}

void
Twelve::printAllRegions ()
{
    termcolor::clear ();
    for (auto i = 1; i < regionCounter; i++)
        {
            for (const auto &line : map)
                {
                    for (const auto &plant : line)
                        {
                            auto ch = plant->type;
                            if (plant->internal)
                                {
                                    cout << termcolor::RED << plant->type << termcolor::RESET;
                                }
                            else
                                {
                                    cout << plant->type;
                                }
                        }
                    cout << "\n";
                }
            SLEEP (200);
            termcolor::clear ();
        }
}

} // aoc