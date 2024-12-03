#include "two.hpp"

namespace aoc
{

Two::Two () : Day<size_t> (2) {}

Two::~Two () = default;

size_t
Two::one ()
{
    size_t answer = 0;
    while (this->filestream)
        {
            string line{};
            getline (this->filestream, line);
            if (line.empty ())
                {
                    break;
                }
            vector<int> nums{};
            string substr{};
            size_t idx = 0;
            for (const auto &ch : line)
                {
                    idx++;
                    if (isdigit (ch))
                        {
                            substr.push_back (ch);
                            if (idx == line.size ())
                                {
                                    auto num = static_cast<int> (std::stoi (substr));
                                    nums.emplace_back (num);
                                    substr.clear ();
                                }
                        }
                    else
                        {
                            auto num = static_cast<int> (std::stoi (substr));
                            nums.emplace_back (num);
                            substr.clear ();
                        }
                }

            if (isSafe (nums))
                {
                    answer++;
                }
        }

    return answer;
}

size_t
Two::two ()
{
    size_t answer = 0;
    while (this->filestream)
        {
            string line{};
            getline (this->filestream, line);
            if (line.empty ())
                {
                    break;
                }
            vector<int> nums{};
            string substr{};
            size_t idx = 0;
            for (const auto &ch : line)
                {

                    idx++;
                    if (isdigit (ch))
                        {
                            substr.push_back (ch);
                            if (idx == line.size ())
                                {
                                    auto num = static_cast<int> (std::stoi (substr));
                                    nums.emplace_back (num);
                                    substr.clear ();
                                }
                        }
                    else
                        {
                            auto num = static_cast<int> (std::stoi (substr));
                            nums.emplace_back (num);
                            substr.clear ();
                        }
                }

            if (isSafe2 (nums))
                {
                    answer++;
                }
        }

    return answer;
}

bool
Two::isSafe (const vector<int> &vec)
{
    size_t idx = 0;
    int prev = -1;
    bool positive = true;

    for (const auto &num : vec)
        {
            if (idx == 0)
                {
                    idx++;
                    prev = num;
                    continue;
                }
            auto diff = num - prev;
            auto absDiff = std::abs (diff);
            auto direction = diff > 0;
            if (absDiff < 1 || absDiff > 3)
                {
                    return false;
                }
            if (idx == 1)
                {
                    positive = direction;
                }
            else
                {
                    if (direction != positive)
                        {
                            return false;
                        }
                }
            prev = num;
            idx++;
        }

    return true;
}

bool
Two::isSafe2 (const vector<int> &vec)
{
    int idx = 0;
    int prev = -1;
    bool positive = true;

    for (const auto &num : vec)
        {
            if (idx == 0)
                {
                    idx++;
                    prev = num;
                    continue;
                }
            auto diff = num - prev;
            auto absDiff = std::abs (diff);
            auto direction = diff > 0;
            if (absDiff < 1 || absDiff > 3)
                {
                    return secondTry (vec);
                }
            if (idx == 1)
                {
                    positive = direction;
                }
            else
                {
                    if (direction != positive)
                        {
                            return secondTry (vec);
                        }
                }
            prev = num;
            idx++;
        }

    return true;
}
bool
Two::secondTry (const vector<int> &vec)
{
    for (auto i = 0; i < vec.size (); i++)
        {
            vector<int> newVec{};
            newVec.assign (vec.begin (), vec.end ());
            newVec.erase (newVec.begin () + i);
            if (isSafe (newVec))
                {
                    return true;
                }
        }
    return false;
}

size_t
Two::answerOne ()
{
    return 510;
}

size_t
Two::answerTwo ()
{
    return 553;
}

} // aoc