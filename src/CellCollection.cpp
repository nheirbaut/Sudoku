#include "CellCollection.h"

using namespace Sudoku;

CellCollection::CellCollection(Cell *startingCell, std::size_t size)
    : m_startingCell(startingCell),
      m_collectionSize(size)
{
}

CellIterator CellCollection::begin()
{
    return CellIterator(m_startingCell);
}

CellIterator CellCollection::end()
{
    return CellIterator(m_startingCell + m_collectionSize);
}

ConstCellIterator CellCollection::begin() const
{
    return ConstCellIterator(m_startingCell);
}

ConstCellIterator CellCollection::end() const
{
    return ConstCellIterator(m_startingCell + m_collectionSize);
}

ConstCellIterator CellCollection::cbegin() const
{
    return ConstCellIterator(m_startingCell);
}

ConstCellIterator CellCollection::cend() const
{
    return ConstCellIterator(m_startingCell + m_collectionSize);
}
