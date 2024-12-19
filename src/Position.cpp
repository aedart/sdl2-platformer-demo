#include "Position.h"
#include <iostream>

Position::Position(): Position(0, 0) {}

Position::Position(const int x, const int y) : x(x), y(y) {}

void Position::print() const
{
    std::cout << x << ", " << y << std::endl;
}
