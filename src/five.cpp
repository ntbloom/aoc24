#include <algorithm>

#include "five.hpp"
namespace aoc
{

Five::Five () : Day<int> (5)
{
    bool first = true;
    while (this->filestream)
        {
            string line{};
            getline (this->filestream, line);
            if (first)
                {
                    if (line.empty ())
                        {
                            first = false;
                            continue;
                        }

                    order order{};
                    order.first = stoi (line.substr (0, 2));
                    order.second = stoi (line.substr (3, 2));
                    this->orders.emplace_back (order);
                }
            else
                {
                    if (line.empty ())
                        {
                            break;
                        }
                    update update{};
                    for (auto i = 0; i < line.length (); i++)
                        {
                            auto num = stoi (line.substr (i, 2));
                            update.emplace_back (num);
                            i += 2;
                        }

                    this->updates.emplace_back (update);
                }
        }
    for (size_t i = 0; i < 100; i++)
        {
            this->befores->insert (std::pair<int, unordered_set<int>> (i, unordered_set<int>{}));
        }
    for (const auto &order : this->orders)
        {
            this->befores->at (order.first).insert (order.second);
        }
}

Five::~Five () = default;

int
Five::one ()
{
    int answer = 0;
    for (const auto &update : this->updates)
        {
            if (isValid (update))
                {
                    auto midpoint = update.at (update.size () / 2);
                    answer += midpoint;
                }
        }
    return answer;
}

int
Five::two ()
{
    int answer = 0;
    for (auto &update : this->updates)
        {
            if (!isValid (update))
                {
                    answer += fix (update);
                }
        }
    return answer;
}

int
Five::answerOne ()
{

    return 4662;
}

int
Five::answerTwo ()
{
    return 5900;
}

bool
Five::isValid (const Five::update &update)
{
    for (auto i = 0; i < update.size (); i++)
        {
            auto first = update.at (i);
            for (auto j = i + 1; j < update.size (); j++)
                {
                    auto second = update.at (j);
                    auto invalids = this->befores->at (second);
                    if (invalids.contains (first))
                        {
                            return false;
                        }
                }
        }
    return true;
}

int
Five::fix (Five::update &update)
{
    for (auto i = 0; i < update.size (); i++)
        {
            auto first = update.at (i);
            for (auto j = i + 1; j < update.size (); j++)
                {
                    auto second = update.at (j);
                    auto invalids = this->befores->at (second);
                    if (invalids.contains (first))
                        {
                            auto idx = j;
                            auto dest = i;
                            update.erase (update.begin () + idx);
                            update.insert (update.begin () + dest, second);
                            return fix (update);
                        }
                }
        }
    return update.at (update.size () / 2);
}

} // aoc