#include "Columns.h"

using namespace Sudoku;

Columns::Columns(Cell *firstCellInFirstColumn, std::size_t size)
    : m_firstCellInFirstColumn(firstCellInFirstColumn),
      m_size(size)
{ }

ColumnIterator Columns::begin()
{
    return ColumnIterator(m_firstCellInFirstColumn, m_size);
}

ColumnIterator Columns::end()
{
    return ColumnIterator(m_firstCellInFirstColumn + m_size, 0);
}

ConstColumnIterator Columns::begin() const
{
    return ConstColumnIterator(m_firstCellInFirstColumn, m_size);
}

ConstColumnIterator Columns::end() const
{
    return ConstColumnIterator(m_firstCellInFirstColumn + m_size, 0);
}

ConstColumnIterator Columns::cbegin() const
{
    return ConstColumnIterator(m_firstCellInFirstColumn, m_size);
}

ConstColumnIterator Columns::cend() const
{
    return ConstColumnIterator(m_firstCellInFirstColumn + m_size, 0);
}
