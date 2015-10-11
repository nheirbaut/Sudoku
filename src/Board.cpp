#include "Board.h"

#include <cmath>
#include <limits>
#include <stdexcept>
#include <vector>

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

struct Board::Implementation
{
    explicit Implementation(FieldType blockSize);

    FieldType getValueIndex(RowIndexType row, ColumnIndexType column) const;
    void validateRowAndColumnIndex(RowIndexType row, ColumnIndexType column) const;

    const FieldType m_blockSize;
    std::vector<FieldType> m_values;

}; // struct Board::Implementation

Board::Board(FieldType blockSize)
    : m_implementation(std::make_unique<Implementation>(blockSize))
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

Board::~Board() = default;
Board::Board(Board &&) = default;
Board& Board::operator=(Board&&) = default;

Board::FieldType Board::getValueForField(Board::RowIndexType row, Board::ColumnIndexType column) const
{
    m_implementation->validateRowAndColumnIndex(row, column);
    return m_implementation->m_values[m_implementation->getValueIndex(row, column)];
}

Board::Implementation::Implementation(FieldType blockSize)
    : m_blockSize(blockSize),
      m_values(blockSize * blockSize, UNSET_FIELD_VALUE)
{
}

Board::FieldType
Board::Implementation::getValueIndex(Board::RowIndexType row, Board::ColumnIndexType column) const
{
    return m_values[row * m_blockSize + column];
}

void Board::Implementation::validateRowAndColumnIndex(Board::RowIndexType row, Board::ColumnIndexType column) const
{
    if (row >= m_blockSize)
    {
        throw std::out_of_range("Row index value is out of range");
    }

    if (column >= m_blockSize)
    {
        throw std::out_of_range("Column index value is out of range");
    }
}
