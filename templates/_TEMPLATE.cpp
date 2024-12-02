#include "template.hpp"

namespace aoc
{

Template::Template () : Day<TYPE> (X) {}

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

Template::~Template () = default;

} // aoc