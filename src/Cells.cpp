#include "Cells.h"

using namespace Sudoku;

Cells::Cells(Cell *startingCell, std::size_t size)
    : m_startingCell(startingCell),
      m_collectionSize(size)
{
}

CellIterator Cells::begin()
{
    return CellIterator(m_startingCell);
}

CellIterator Cells::end()
{
    return CellIterator(m_startingCell + m_collectionSize);
}

ConstCellIterator Cells::begin() const
{
    return ConstCellIterator(m_startingCell);
}

ConstCellIterator Cells::end() const
{
    return ConstCellIterator(m_startingCell + m_collectionSize);
}

ConstCellIterator Cells::cbegin() const
{
    return ConstCellIterator(m_startingCell);
}

ConstCellIterator Cells::cend() const
{
    return ConstCellIterator(m_startingCell + m_collectionSize);
}
