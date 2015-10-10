#include "Board.h"

#include <cmath>
#include <limits>
#include <stdexcept>

using namespace Sudoku;

namespace
{
bool
isPerfectSquare(Board::FieldType blockSize)
{
    auto root = static_cast<Board::FieldType>(std::round(std::sqrt(blockSize)));
    return root * root == blockSize;
}

Board::FieldType
maxValueOfFieldType()
{
    auto maxSystemValueOfFieldType = std::numeric_limits<Board::FieldType>::max();
    return static_cast<Board::FieldType>(std::round(std::sqrt(maxSystemValueOfFieldType)));
}
} // anonymous namespace

const Board::FieldType Board::MAX_FIELD_VALUE = maxValueOfFieldType();

Board::Board(FieldType blockSize)
{
    static_assert(std::is_integral<FieldType>::value, "You cannot use a non-integral type as FieldType");
    static_assert(std::is_unsigned<FieldType>::value, "You cannot use a signed type as FieldType");

    if (blockSize > Board::MAX_FIELD_VALUE)
    {
        throw std::out_of_range("The block size is too large");
    }

    if (! isPerfectSquare(blockSize))
    {
        throw std::invalid_argument("The given block size does not represent a perfect square value.");
    }
}
