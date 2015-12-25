#include "Board.h"

#include <cmath>
#include <limits>
#include <stdexcept>
#include <vector>

using namespace Sudoku;

namespace
{
bool
isPerfectSquare(Cell::ValueType blockSize)
{
    auto root = static_cast<Cell::ValueType>(std::round(std::sqrt(blockSize)));
    return root * root == blockSize;
}

Cell::ValueType
maxValueOfCellType()
{
    auto maxSystemValueOfCellType = std::numeric_limits<Cell::ValueType>::max();
    return static_cast<Cell::ValueType>(std::round(std::sqrt(maxSystemValueOfCellType)));
}
} // anonymous namespace

const Cell::ValueType Board::MAX_BLOCKSIZE = maxValueOfCellType();

struct Board::Implementation
{
    explicit Implementation(Cell::ValueType blockSize);

    Cell::ValueType getCellIndex(RowIndexType row, ColumnIndexType column) const;
    void validateRowAndColumnIndex(RowIndexType row, ColumnIndexType column) const;

    const Cell::ValueType m_blockSize;
    std::vector<Cell> m_cells;

}; // struct Board::Implementation

Board::Board(Cell::ValueType blockSize)
    : m_implementation(std::make_unique<Implementation>(blockSize))
{
    static_assert(std::is_integral<Cell::ValueType>::value, "You cannot use a non-integral type as CellType");
    static_assert(std::is_unsigned<Cell::ValueType>::value, "You cannot use a signed type as CellType");

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

Cell::ValueType Board::getValueForCellAt(Board::RowIndexType row, Board::ColumnIndexType column) const
{
    m_implementation->validateRowAndColumnIndex(row, column);
    return m_implementation->m_cells[m_implementation->getCellIndex(row, column)];
}

void Board::setValueForCell(Board::RowIndexType row, Board::ColumnIndexType column, Cell::ValueType value)
{
    m_implementation->validateRowAndColumnIndex(row, column);

    if (value > m_implementation->m_blockSize)
    {
        throw std::out_of_range("The value is too large");
    }

    m_implementation->m_cells[m_implementation->getCellIndex(row, column)] = value;
}

Board::iterator Board::begin()
{
    return iterator(m_implementation->m_cells.begin());
}

Board::iterator Board::end()
{
    return iterator(m_implementation->m_cells.end());
}

Board::const_iterator Board::begin() const
{
    return const_iterator(m_implementation->m_cells.begin());
}

Board::const_iterator Board::end() const
{
    return const_iterator(m_implementation->m_cells.end());
}

Board::const_iterator Board::cbegin() const
{
    return const_iterator(m_implementation->m_cells.cbegin());
}

Board::const_iterator Board::cend() const
{
    return const_iterator(m_implementation->m_cells.cend());
}

Board::Implementation::Implementation(Cell::ValueType blockSize)
    : m_blockSize(blockSize),
      m_cells(blockSize * blockSize)
{
}

Cell::ValueType Board::Implementation::getCellIndex(Board::RowIndexType row, Board::ColumnIndexType column) const
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
