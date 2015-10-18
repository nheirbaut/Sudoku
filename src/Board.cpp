#include "Board.h"

#include <cmath>
#include <limits>
#include <stdexcept>
#include <vector>

using namespace Sudoku;

namespace
{
bool
isPerfectSquare(Board::CellType blockSize)
{
    auto root = static_cast<Board::CellType>(std::round(std::sqrt(blockSize)));
    return root * root == blockSize;
}

Board::CellType
maxValueOfCellType()
{
    auto maxSystemValueOfCellType = std::numeric_limits<Board::CellType>::max();
    return static_cast<Board::CellType>(std::round(std::sqrt(maxSystemValueOfCellType)));
}
} // anonymous namespace

const Board::CellType Board::MAX_BLOCKSIZE = maxValueOfCellType();
const Board::CellType Board::UNSET_CELL_VALUE = 0;

struct Board::Implementation
{
    explicit Implementation(CellType blockSize);

    CellType getValueIndex(RowIndexType row, ColumnIndexType column) const;
    void validateRowAndColumnIndex(RowIndexType row, ColumnIndexType column) const;

    const CellType m_blockSize;
    std::vector<CellType> m_values;

}; // struct Board::Implementation

Board::Board(CellType blockSize)
    : m_implementation(std::make_unique<Implementation>(blockSize))
{
    static_assert(std::is_integral<CellType>::value, "You cannot use a non-integral type as CellType");
    static_assert(std::is_unsigned<CellType>::value, "You cannot use a signed type as CellType");

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

Board::CellType Board::getValueForCell(Board::RowIndexType row, Board::ColumnIndexType column) const
{
    m_implementation->validateRowAndColumnIndex(row, column);
    return m_implementation->m_values[m_implementation->getValueIndex(row, column)];
}

void Board::setValueForCell(Board::RowIndexType row, Board::ColumnIndexType column, Board::CellType value)
{
    m_implementation->validateRowAndColumnIndex(row, column);

    if (value > m_implementation->m_blockSize)
    {
        throw std::out_of_range("The value is too large");
    }

    m_implementation->m_values[m_implementation->getValueIndex(row, column)] = value;
}

Board::iterator Board::begin()
{
    return iterator(m_implementation->m_values.begin());
}

Board::iterator Board::end()
{
    return iterator(m_implementation->m_values.end());
}

Board::const_iterator Board::begin() const
{
    return const_iterator(m_implementation->m_values.begin());
}

Board::const_iterator Board::end() const
{
    return const_iterator(m_implementation->m_values.end());
}

Board::const_iterator Board::cbegin() const
{
    return const_iterator(m_implementation->m_values.cbegin());
}

Board::const_iterator Board::cend() const
{
    return const_iterator(m_implementation->m_values.cend());
}

Board::Implementation::Implementation(CellType blockSize)
    : m_blockSize(blockSize),
      m_values(blockSize * blockSize, UNSET_CELL_VALUE)
{
}

Board::CellType Board::Implementation::getValueIndex(Board::RowIndexType row, Board::ColumnIndexType column) const
{
    return row * m_blockSize + column;
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
