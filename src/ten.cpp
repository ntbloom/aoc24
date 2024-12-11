#include "ten.hpp"

namespace aoc
{

int
Ten::answerOne ()
{
    return 607;
}

int
Ten::answerTwo ()
{
    return 1384;
}

Ten::Ten () : Day<int> (10)
{
    size_t row = 0;
    while (this->filestream)
        {
            string line;
            getline (this->filestream, line);
            if (line.empty ())
                {
                    break;
                }
            mapline_t mapline{};
            map.emplace_back (mapline);
            for (auto i = 0; i < line.size (); i++)
                {
                    int num = line.at (i) - 48;
                    auto step = make_shared<Step> (num);

                    map.at (row).emplace_back (step);
                    if (num == 0)
                        {
                            trailheads.insert (step.get ());
                        }
                }
            row++;
        }
    populateNeighbors ();
    printMap ();
}

Ten::~Ten () = default;

int
Ten::one ()
{
    int total = 0;
    for (auto possible : trailheads)
        {
            total += dfs (possible);
        }
    return total;
}

int
Ten::two ()
{
    int total = 0;
    for (auto possible : trailheads)
        {
            total += dfsNoMarking (possible);
        }
    return total;
}

[[maybe_unused]] void
Ten::printMap ()
{
    for (const auto &line : this->map)
        {
            for (const auto &step : line)
                {
                    if (step->height == 0)
                        {
                            cout << termcolor::GREEN << step->height << termcolor::RESET << " ";
                        }
                    else if (step->visited)
                        {
                            cout << termcolor::RED << step->height << termcolor::RESET << " ";
                        }
                    else
                        {
                            cout << step->height << " ";
                        }
                }
            cout << "\n";
        }
    cout << endl;
}

Ten::Step::Step (int height) : height (height), visited (false)
{
    if (height > 9 || height < 0)
        {
            throw;
        }
}

int
Ten::dfs (Step *root)
{
    int goal = 0;

    dfsStack stk{};
    stk.emplace (root);
    Step *step{};
    dfsVisits visits{};
    while (!stk.empty ())
        {
            step = stk.top ();
            stk.pop ();
            step->visited = true;
            if (step->height == 9)
                {
                    goal += 1;
                }
            findNeighbors (step, stk, visits);
        }
    for (auto &visit : visits)
        {
            visit->visited = false;
        }
    return goal;
}

void
Ten::findNeighbors (Ten::Step *step, dfsStack &stk, dfsVisits &visits)
{
    for (const auto &node : { step->up, step->down, step->left, step->right })
        {
            if (node != nullptr && node->height == step->height + 1 && !node->visited)
                {
                    visits.insert (node);
                    stk.emplace (node);
                }
        }
}

int
Ten::dfsNoMarking (Step *root)
{
    int goal = 0;

    dfsStack stk{};
    stk.emplace (root);
    Step *step{};
    dfsVisits visits{};
    while (!stk.empty ())
        {
            step = stk.top ();
            stk.pop ();
            if (step->height == 9)
                {
                    goal += 1;
                }
            findNeighbors (step, stk, visits);
        }
    for (auto &visit : visits)
        {
            visit->visited = false;
        }
    return goal;
}

void
Ten::findNeighborsNoMarking (Ten::Step *step, dfsStack &stk, dfsVisits &visits)
{
    for (const auto &node : { step->up, step->down, step->left, step->right })
        {
            if (node != nullptr && node->height == step->height + 1)
                {
                    visits.insert (node);
                    stk.emplace (node);
                }
        }
}

void
Ten::populateNeighbors ()
{
    auto width = map.at (0).size ();
    auto length = map.size ();
    for (auto row = 0; row < map.size (); row++)
        {
            for (auto col = 0; col < width; col++)
                {
                    auto step = map.at (row).at (col);
                    step->up = row == 0 ? nullptr : map.at (row - 1).at (col).get ();
                    step->down
                        = row == map.size () - 1 ? nullptr : map.at (row + 1).at (col).get ();
                    step->left = col == 0 ? nullptr : map.at (row).at (col - 1).get ();
                    step->right = col == length - 1 ? nullptr : map.at (row).at (col + 1).get ();
                }
        }
}
} // aoc