#include "six.hpp"

namespace aoc
{

Node::Node (int x, int y, char value)
    : x (x), y (y), value (value), prev (nullptr), visited (false),
      direction (Direction::DIRECTION_UNSET)
{
}

Six::Six () : Day<int> (6)
{
    for (const auto row : { 0, mapsize - 1 })
        {
            for (auto col = 0; col < this->mapsize; col++)
                {
                    this->map.at (row).at (col) = new Node (row, col, goalTile);
                }
        }
    auto row = 1;
    while (this->filestream)
        {
            string line;
            getline (this->filestream, line);
            if (line.empty ())
                {
                    break;
                }
            auto col = 1;
            for (const auto &ch : line)
                {
                    auto *node = new Node (row, col, ch);
                    this->map.at (row).at (col++) = node;
                    if (ch == startTile)
                        {
                            this->start = node;
                        }
                }
            this->map.at (row).at (0) = new Node (row, 0, goalTile);
            this->map.at (row).at (mapsize - 1) = new Node (row, mapsize - 1, goalTile);
            row++;
        }
}

Six::~Six ()
{
    for (auto row : this->map)
        {
            for (auto node : row)
                {
                    delete node;
                }
        }
}

int
Six::one ()
{
    auto answer = search (this->start, Direction::UP, 0);
    return answer;
}

int
Six::two ()
{
    int answer = 0;
    for (auto &row : this->map)
        {
            for (auto node : row)
                {
                    if (node->value == ordinaryTile)
                        {
                            node->value = obstructionTile;
                            answer += findLoop (this->start, Direction::UP);
                            node->value = ordinaryTile;
                            clearMap ();
                        }
                }
        }
    return answer;
}

[[maybe_unused]] void
Six::printMap ()
{
    cout << "\033c\n";

    for (const auto &row : this->map)
        {
            for (const auto &node : row)
                {
                    if (node->visited)
                        {
                            cout << format ("{}{}{}", termcolor::RED, node->value,
                                            termcolor::RESET);
                        }
                    else
                        {
                            cout << node->value;
                        }
                }
            cout << "\n";
        }
    cout << "\n";
}

int
Six::search (Node *node, Direction direction, int answer)
{
    if (node->value == goalTile)
        {
            node->visited = true;
            return answer;
        }

    Direction turn;
    Node *next;
    switch (direction)
        {
        case Direction::UP:
            next = this->map.at (node->x - 1).at (node->y);
            turn = Direction::RIGHT;
            break;
        case Direction::RIGHT:
            next = this->map.at (node->x).at (node->y + 1);
            turn = Direction::DOWN;
            break;
        case Direction::DOWN:
            next = this->map.at (node->x + 1).at (node->y);
            turn = Direction::LEFT;
            break;
        case Direction::LEFT:
            next = this->map.at (node->x).at (node->y - 1);
            turn = Direction::UP;
            break;
        default:
            throw std::runtime_error ("Illegal direction");
        }

    if (node->value == obstructionTile)
        {
            return search (node->prev, turn, answer);
        }
    if (!node->visited)
        {
            node->visited = true;
            answer++;
        }
    next->prev = node;
    return search (next, direction, answer);
}

int
Six::findLoop (Node *node, Direction direction)
{
    if (node->value == goalTile)
        {
            return 0;
        }
    if (node->visited && direction == node->direction)
        {
            return 1;
        }

    node->visited = true;
    node->direction = direction;

    Direction turn;
    Node *next;
    switch (direction)
        {
        case Direction::UP:
            next = this->map.at (node->x - 1).at (node->y);
            turn = Direction::RIGHT;
            break;
        case Direction::RIGHT:
            next = this->map.at (node->x).at (node->y + 1);
            turn = Direction::DOWN;
            break;
        case Direction::DOWN:
            next = this->map.at (node->x + 1).at (node->y);
            turn = Direction::LEFT;
            break;
        case Direction::LEFT:
            next = this->map.at (node->x).at (node->y - 1);
            turn = Direction::UP;
            break;
        default:
            throw std::runtime_error ("Illegal direction");
        }

    if (node->value == obstructionTile)
        {
            return findLoop (node->prev, turn);
        }
    next->prev = node;
    return findLoop (next, direction);
}

void
Six::clearMap ()
{
    for (auto row : this->map)
        {
            for (auto node : row)
                {
                    node->visited = false;
                    node->direction = Direction::DIRECTION_UNSET;
                }
        }
}
int
Six::answerOne ()
{
    return 5444;
}

int
Six::answerTwo ()
{
    return 1946;
}

} // aoc