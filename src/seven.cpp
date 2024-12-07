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

            std::smatch match;
            const auto remainder = line.substr (line.find (':') + 1, line.size () - 1);
            string::const_iterator iter (remainder.cbegin ());
            while (std::regex_search (iter, remainder.end (), match, pattern))
                {
                    auto size = match.size ();
                    long num = strtol (match[0].str ().c_str (), &end, 10);
                    numbers->emplace_back (num);
                    iter = match.suffix ().first;
                }

            auto eq = make_shared<equation> (first, numbers.get ());
            equations->emplace_back (eq.get ());
        }
    cout << "";
}

Seven::~Seven () = default;

long
Seven::one ()
{
    for (auto line : *equations)
        {
            cout << line->first << "\n";
            //            for (auto num : *line->second)
            //                {
            //                    cout << num << " ";
            //                }
            //            cout << "\n";
        }
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