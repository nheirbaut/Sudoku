#include "Board.h"

#include <stdexcept>

using namespace Sudoku;

Board::Board(unsigned int size)
{
    if (size == 0)
    {
        throw std::invalid_argument("Cannot create a Soduku board without fields. Use a value > 0.");
    }
}
