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

const Board::FieldType Board::MAX_BLOCKSIZE = maxValueOfFieldType();
const Board::FieldType Board::UNSET_FIELD_VALUE = 0;

Board::Board(FieldType blockSize)
    : m_blockSize(blockSize),
      m_values(blockSize * blockSize, UNSET_FIELD_VALUE)
{
    static_assert(std::is_integral<FieldType>::value, "You cannot use a non-integral type as FieldType");
    static_assert(std::is_unsigned<FieldType>::value, "You cannot use a signed type as FieldType");

    if (blockSize > Board::MAX_BLOCKSIZE)
    {
        throw std::out_of_range("The block size is too large");
    }

    if (! isPerfectSquare(blockSize))
    {
        throw std::invalid_argument("The given block size does not represent a perfect square value.");
    }
}

Board::FieldType Board::getValueForField(Board::RowIndexType row, Board::ColumnIndexType column) const
{
    return m_values[getValueIndex(row, column)];
}

Board::FieldType
Board::getValueIndex(Board::RowIndexType row, Board::ColumnIndexType column) const
{
    return m_values[row * m_blockSize + column];
}
