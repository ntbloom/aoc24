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
                    map.at (row).emplace_back (make_shared<Plant> (row, col++, ch));
                }
            row++;
        }
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
Twelve::printMap ()
{
    for (const auto &line : map)
        {
            for (const auto &plant : line)
                {
                    auto ch = plant->type;
                    //                    if (ch == 'C')
                    //                        {
                    //                            cout << termcolor::RED << plant->type <<
                    //                            termcolor::RESET;
                    //                        }
                    //                    else
                    //                        {
                    cout << plant->type;
                    //                        }
                }
            cout << "\n";
        }
    cout << std::flush;
}

} // aoc