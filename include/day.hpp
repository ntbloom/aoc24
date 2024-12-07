#pragma once

#include <algorithm>
#include <array>
#include <cassert>
#include <chrono>
#include <filesystem>
#include <format>
#include <fstream>
#include <iostream>
#include <numeric>
#include <queue>
#include <regex>
#include <sstream>
#include <string>
#include <thread>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using steadyTimer_t = std::chrono::steady_clock;
using nanosecDuration_t = std::chrono::duration<long, std::ratio<1, 1000000000>>;
using timestamp_t = std::chrono::time_point<steadyTimer_t, nanosecDuration_t>;

using std::accumulate;
using std::array;
using std::cout;
using std::endl;
using std::format;
using std::getline;
using std::make_shared;
using std::make_unique;
using std::pair;
using std::queue;
using std::regex;
using std::regex_search;
using std::shared_ptr;
using std::smatch;
using std::string;
using std::stringstream;
using std::unique_ptr;
using std::unordered_map;
using std::unordered_set;
using std::vector;
using std::chrono::milliseconds;
using std::this_thread::sleep_for;

namespace termcolor
{
static constexpr const char *RED = "\033[0;31m";
static constexpr const char *RESET = "\033[0m";
};

namespace aoc
{
template <typename T> class Day
{
  public:
    explicit Day (int num)
    {
        this->num = num;
        stringstream filename;
        filename << num << ".txt";
        this->inputFile = std::filesystem::current_path () / std::filesystem::path{ "inputs" }
                          / std::filesystem::path{ filename.str () };
        if (!exists (this->inputFile))
            {
                stringstream err;
                err << absolute (this->inputFile) << " doesn't exist";
                throw std::runtime_error (err.str ());
            }
        this->filestream.open (this->inputFile);
        if (!this->filestream.is_open ())
            {
                throw std::runtime_error ("unable to open file");
            }
        assert (this->filestream);
    }

    virtual ~Day () { this->filestream.close (); };

    T
    solve (int puzzle)
    {
        timestamp_t start, stop;
        start = steadyTimer_t::now ();
        auto answer = puzzle == 1 ? this->one () : this->two ();
        stop = steadyTimer_t::now ();
        auto duration = stop - start;

        string border{ "**************************************" };
        cout << format ("{}\n            Day {}/Puzzle {}\nAnswer= = {}\nDuration (μs) = {}\n{}\n",
                        border, this->num, puzzle, answer, duration.count () / 1000, border);
        return answer;
    }

    virtual T answerOne () = 0;

    virtual T answerTwo () = 0;

  protected:
    virtual T
    one ()
    {
        return 0;
    };

    virtual T
    two ()
    {
        return 0;
    };

    int num;
    std::filesystem::path inputFile;
    std::ifstream filestream;
};

} // aoc
