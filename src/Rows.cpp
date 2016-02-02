#include "Rows.h"

using namespace Sudoku;

Rows::Rows(Cell* firstCellInFirstRow, std::size_t size)
    : m_firstCellInFirstRow(firstCellInFirstRow),
      m_size(size)
{ }

RowIterator Rows::begin()
{
    return RowIterator(m_firstCellInFirstRow, m_size);
}

RowIterator Rows::end()
{
    return RowIterator(m_firstCellInFirstRow + m_size * m_size, 0);
}

ConstRowIterator Rows::begin() const
{
    return ConstRowIterator(m_firstCellInFirstRow, m_size);
}

ConstRowIterator Rows::end() const
{
    return ConstRowIterator(m_firstCellInFirstRow + m_size * m_size, 0);
}

ConstRowIterator Rows::cbegin() const
{
    return ConstRowIterator(m_firstCellInFirstRow, m_size);
}

ConstRowIterator Rows::cend() const
{
    return ConstRowIterator(m_firstCellInFirstRow + m_size * m_size, 0);
}
