#include "Grid.h"

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

const Cell::ValueType Grid::MAX_BLOCKSIZE = maxValueOfCellType();

struct Grid::Implementation
{
    explicit Implementation(Cell::ValueType blockSize);

    Cell::ValueType getCellIndex(RowIndexType row, ColumnIndexType column) const;
    void validateRowAndColumnIndex(RowIndexType row, ColumnIndexType column) const;

    const Cell::ValueType m_blockSize;
    std::vector<Cell> m_cells;

}; // struct Grid::Implementation

Grid::Grid(Cell::ValueType blockSize)
    : m_implementation(std::make_unique<Implementation>(blockSize))
{
    static_assert(std::is_integral<Cell::ValueType>::value, "You cannot use a non-integral type as CellType");
    static_assert(std::is_unsigned<Cell::ValueType>::value, "You cannot use a signed type as CellType");

    if (blockSize > Grid::MAX_BLOCKSIZE)
    {
        throw std::out_of_range("The block size is too large");
    }

    if (! isPerfectSquare(blockSize))
    {
        throw std::invalid_argument("The given block size does not represent a perfect square value.");
    }
}

Cells Grid::cells()
{
    return Cells(&m_implementation->m_cells[0], m_implementation->m_cells.size());
}

Rows Grid::rows()
{
    return Rows(&m_implementation->m_cells[0], m_implementation->m_blockSize);
}

Columns Grid::columns()
{
    return Columns(&m_implementation->m_cells[0], m_implementation->m_blockSize);
}

Grid::~Grid() = default;

Cell::ValueType Grid::getValueForCellAt(Grid::RowIndexType row, Grid::ColumnIndexType column) const
{
    m_implementation->validateRowAndColumnIndex(row, column);
    return m_implementation->m_cells[m_implementation->getCellIndex(row, column)];
}

void Grid::setValueForCell(Grid::RowIndexType row, Grid::ColumnIndexType column, Cell::ValueType value)
{
    m_implementation->validateRowAndColumnIndex(row, column);
    m_implementation->m_cells[m_implementation->getCellIndex(row, column)] = value;
}

Grid::Implementation::Implementation(Cell::ValueType blockSize)
    : m_blockSize(blockSize),
      m_cells(blockSize * blockSize, Cell(blockSize))
{
}

Cell::ValueType Grid::Implementation::getCellIndex(Grid::RowIndexType row, Grid::ColumnIndexType column) const
{
    return row * m_blockSize + column;
}

void Grid::Implementation::validateRowAndColumnIndex(Grid::RowIndexType row, Grid::ColumnIndexType column) const
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
