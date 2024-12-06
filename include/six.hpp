#pragma once

#include "day.hpp"

namespace aoc
{

enum class Direction : uint8_t
{
    DIRECTION_UNSET,
    UP,
    DOWN,
    LEFT,
    RIGHT,
};

struct Node
{
    Node (int x, int y, char value);

    int x;
    int y;
    Node *prev;
    char value;
    bool visited = false;
    Direction direction;
};

class Six final : public Day<int>
{
  public:
    Six ();

    ~Six () final;

    int one () final;

    int two () final;

    int answerOne () final;

    int answerTwo () final;

  private:
    static constexpr int mapsize = 132;

    static constexpr char startTile = '^';
    static constexpr char goalTile = '+';
    static constexpr char obstructionTile = '#';
    static constexpr char ordinaryTile = '.';

    using mapLine = array<Node *, mapsize>;
    array<mapLine, mapsize> map{};
    Node *start = nullptr;

    int search (Node *node, Direction direction, int count);
    int findLoop (Node *node, Direction direction);
    void printMap ();
    void clearMap ();
};

} // aoc
