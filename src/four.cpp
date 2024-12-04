#include "four.hpp"

namespace aoc
{

Four::Four () : Day<size_t> (4)
{
    size_t row = 0;
    while (this->filestream)
        {
            string line{};
            getline (this->filestream, line);
            if (line.empty ())
                {
                    break;
                }
            size_t col = 0;
            for (const auto &ch : line)
                {
                    this->wordSearch[row][col++] = ch;
                }
            assert (col == 140);
            row++;
        }
    assert (row == 140);
}

Four::~Four () = default;

size_t
Four::one ()
{
    size_t answer = 0;
    for (size_t row = 0; row < 140; row++)
        {
            for (size_t col = 0; col < 140; col++)
                {
                    if (wordSearch[row][col] == 'X')
                        {
                            answer += checkNorth (row, col);
                            answer += checkSouth (row, col);
                            answer += checkEast (row, col);
                            answer += checkWest (row, col);
                            answer += checkNortheast (row, col);
                            answer += checkNorthwest (row, col);
                            answer += checkSoutheast (row, col);
                            answer += checkSouthwest (row, col);
                        }
                }
        }
    return answer;
}

size_t
Four::two ()
{
    size_t answer = 0;

    for (size_t row = 0; row < 140; row++)
        {
            for (size_t col = 0; col < 140; col++)
                {
                    if (wordSearch[row][col] == 'A')
                        {
                            answer += checkXmas (row, col);
                        }
                }
        }
    return answer;
}

size_t
Four::checkNorth (size_t row, size_t col)
{
    if (row < northLimit)
        {
            return 0;
        }

    string word ("X");
    word += wordSearch[row - 1][col];
    word += wordSearch[row - 2][col];
    word += wordSearch[row - 3][col];
    if (word == targetWord)
        {
            return 1;
        }
    return 0;
}

size_t
Four::checkSouth (size_t row, size_t col)
{
    if (row > southLimit)
        {
            return 0;
        }
    string word ("X");
    word += wordSearch[row + 1][col];
    word += wordSearch[row + 2][col];
    word += wordSearch[row + 3][col];
    if (word == targetWord)
        {
            return 1;
        }
    return 0;
}

size_t
Four::checkEast (size_t row, size_t col)
{
    if (col > eastLimit)
        {
            return 0;
        }
    string word ("X");
    word += wordSearch[row][col + 1];
    word += wordSearch[row][col + 2];
    word += wordSearch[row][col + 3];
    if (word == targetWord)
        {
            return 1;
        }
    return 0;
}

size_t
Four::checkWest (size_t row, size_t col)
{
    if (col < westLimit)
        {
            return 0;
        }
    string word ("X");
    word += wordSearch[row][col - 1];
    word += wordSearch[row][col - 2];
    word += wordSearch[row][col - 3];
    if (word == targetWord)
        {
            return 1;
        }
    return 0;
}

size_t
Four::checkNorthwest (size_t row, size_t col)
{
    if (row < northLimit || col < westLimit)
        {
            return 0;
        }
    string word ("X");
    word += wordSearch[row - 1][col - 1];
    word += wordSearch[row - 2][col - 2];
    word += wordSearch[row - 3][col - 3];
    if (word == targetWord)
        {
            return 1;
        }
    return 0;
}
size_t
Four::checkNortheast (size_t row, size_t col)
{
    if (row < northLimit || col > eastLimit)
        {
            return 0;
        }
    string word ("X");
    word += wordSearch[row - 1][col + 1];
    word += wordSearch[row - 2][col + 2];
    word += wordSearch[row - 3][col + 3];
    if (word == targetWord)
        {
            return 1;
        }
    return 0;
}
size_t
Four::checkSoutheast (size_t row, size_t col)
{
    if (row > southLimit || col > eastLimit)
        {
            return 0;
        }
    string word ("X");
    word += wordSearch[row + 1][col + 1];
    word += wordSearch[row + 2][col + 2];
    word += wordSearch[row + 3][col + 3];
    if (word == targetWord)
        {
            return 1;
        }
    return 0;
}
size_t
Four::checkSouthwest (size_t row, size_t col)
{
    if (row > southLimit || col < westLimit)
        {
            return 0;
        }
    string word ("X");
    word += wordSearch[row + 1][col - 1];
    word += wordSearch[row + 2][col - 2];
    word += wordSearch[row + 3][col - 3];
    if (word == targetWord)
        {
            return 1;
        }
    return 0;
}

size_t
Four::checkXmas (size_t row, size_t col)
{
    if (row < XnorthLimit || row > XsouthLimit || col < XwestLimit || col > XeastLimit)
        {
            return 0;
        }
    // clang-format off

    // M.S
    // .A.
    // M.S
    if (
           wordSearch[row-1][col-1] == 'M'
        && wordSearch[row-1][col+1] == 'S'
        && wordSearch[row+1][col-1] == 'M'
        && wordSearch[row+1][col+1] == 'S'
        ) {
            return 1;
        }

    // M.M
    // .A.
    // S.S
    if (
           wordSearch[row-1][col-1] == 'M'
        && wordSearch[row-1][col+1] == 'M'
        && wordSearch[row+1][col-1] == 'S'
        && wordSearch[row+1][col+1] == 'S'
        ) {
        return 1;
        }

    // S.S
    // .A.
    // M.M
    if (
           wordSearch[row-1][col-1] == 'S'
        && wordSearch[row-1][col+1] == 'S'
        && wordSearch[row+1][col-1] == 'M'
        && wordSearch[row+1][col+1] == 'M'
        ) {
        return 1;
        }

    // S.M
    // .A.
    // S.M
    if (
           wordSearch[row-1][col-1] == 'S'
        && wordSearch[row-1][col+1] == 'M'
        && wordSearch[row+1][col-1] == 'S'
        && wordSearch[row+1][col+1] == 'M'
        ) {
        return 1;
    }

    // clang-format on
    return 0;
}

size_t
Four::answerOne ()
{
    return 2549;
}

size_t
Four::answerTwo ()
{
    return 2003;
}

} // aoc