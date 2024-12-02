#include <cassert>
#include <getopt.h>
#include <iostream>
#include <memory>

// clang-format off
#include "day.hpp"
#include "one.hpp"
//#include "two.hpp"
//#include "three.hpp"
//#include "four.hpp"
//#include "five.hpp"
//#include "six.hpp"
//#include "seven.hpp"
//#include "eight.hpp"
//#include "nine.hpp"
//#include "ten.hpp"
//#include "eleven.hpp"
//#include "twelve.hpp"
//#include "thirteen.hpp"
//#include "fourteen.hpp"
//#include "fifteen.hpp"
//#include "sixteen.hpp"
//#include "seventeen.hpp"
//#include "eighteen.hpp"
//#include "nineteen.hpp"
//#include "twenty.hpp"
//#include "twentyone.hpp"
//#include "twentytwo.hpp"
//#include "twentythree.hpp"
//#include "twentyfour.hpp"
//#include "twentyfive.hpp"
// clang-format on

using std::make_unique;

int
help (int rc)
{
    std::cout << "Usage:" << std::endl;
    std::cout << "\t[--help/-h]\tShow options" << std::endl;
    std::cout << "\t[--day/-d]\tPick a day" << std::endl;
    std::cout << "\t[--puzzle/-p]\tPick a puzzle" << std::endl;
    return rc;
}

template <typename T>
int
getSolution (int puzzle)
{
    auto solution = make_unique<T> ();
    solution->solve (puzzle);

    return 0;
}

int
main (int argc, char **argv)
{
    int option, day = 0, puzzle = 0;

    struct option longOptions[] = { { "help", 0, nullptr, 'h' },
                                    { "day", 0, nullptr, 'd' },
                                    { "puzzle", 0, nullptr, 'p' },
                                    { nullptr, 0, nullptr, 0 } };

    if (argc == 1)
        {
            return help (-1);
        }

    char *input;
    char *end;
    while ((option = getopt_long (argc, argv, "hd:p:", longOptions, nullptr)) != -1)
        {
            switch (option)
                {
                case 'h':
                    return help (0);
                case 'd':
                    input = optarg;
                    day = (int)strtol (input, &end, 10);
                    break;
                case 'p':
                    input = optarg;
                    puzzle = (int)strtol (input, &end, 10);
                    break;
                default:
                    return help (EINVAL);
                }
        }

    assert (day > 0 && day <= 25);
    assert (puzzle == 1 || puzzle == 2);

    switch (day)
        {
        case 1:
            return getSolution<aoc::One> (puzzle);
            //        case 2:
            //            return getSolution<aoc::Two> (puzzle);
            //        case 3:
            //            return getSolution<aoc::Three> (puzzle);
            //        case 4:
            //            return getSolution<aoc::Four> (puzzle);
            //        case 5:
            //            return getSolution<aoc::Five> (puzzle);
            //        case 6:
            //            return getSolution<aoc::Six> (puzzle);
            //        case 7:
            //            return getSolution<aoc::Seven> (puzzle);
            //        case 8:
            //            return getSolution<aoc::Eight> (puzzle);
            //        case 9:
            //            return getSolution<aoc::Nine> (puzzle);
            //        case 10:
            //            return getSolution<aoc::Ten> (puzzle);
            //        case 11:
            //            return getSolution<aoc::Eleven> (puzzle);
            //        case 12:
            //            return getSolution<aoc::Twelve> (puzzle);
            //        case 13:
            //            return getSolution<aoc::Thirteen> (puzzle);
            //        case 14:
            //            return getSolution<aoc::Fourteen> (puzzle);
            //        case 15:
            //            return getSolution<aoc::Fifteen> (puzzle);
            //        case 16:
            //            return getSolution<aoc::Sixteen> (puzzle);
            //        case 17:
            //            return getSolution<aoc::Seventeen> (puzzle);
            //        case 18:
            //            return getSolution<aoc::Eighteen> (puzzle);
            //        case 19:
            //            return getSolution<aoc::Nineteen> (puzzle);
            //        case 20:
            //            return getSolution<aoc::Twenty> (puzzle);
            //        case 21:
            //            return getSolution<aoc::TwentyOne> (puzzle);
            //        case 22:
            //            return getSolution<aoc::TwentyTwo> (puzzle);
            //        case 23:
            //            return getSolution<aoc::TwentyThree> (puzzle);
            //        case 24:
            //            return getSolution<aoc::TwentyFour> (puzzle);
            //        case 25:
            //            return getSolution<aoc::TwentyFive> (puzzle);

        default:
            throw std::runtime_error ("Illegal day!");
        }

    return 0;
}
