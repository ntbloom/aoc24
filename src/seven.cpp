#include "seven.hpp"

namespace aoc
{

Seven::Seven () : Day<long> (7), equations (new vector<equation *> ())
{
    regex pattern ("(\\d+)");
    while (this->filestream)
        {
            string line{};
            getline (this->filestream, line);
            if (line.empty ())
                {
                    break;
                }
            auto numbers = make_shared<vector<long>> ();
            char *end;
            long first = strtol (line.substr (0, line.find (':')).c_str (), &end, 10);
            auto eq = make_shared<equation> (first, numbers.get ());
            equations->emplace_back (eq.get ());
        }
}

Seven::~Seven () = default;

long
Seven::one ()
{
    return -1;
}

long
Seven::two ()
{
    return -2;
}

long
Seven::answerOne ()
{
    return -1;
}

long
Seven::answerTwo ()
{
    return -2;
}

} // aoc