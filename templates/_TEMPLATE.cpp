#include "template.hpp"

namespace aoc
{

Template::Template () : Day<TYPE> (X) {}
Template::~Template () = default;

TYPE
Template::one ()
{
    return -1;
}

TYPE
Template::two ()
{
    return -2;
}

TYPE
Template::answerOne ()
{
    return -1;
}

TYPE
Template::answerTwo ()
{
    return -2;
}

} // aoc