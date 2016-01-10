#include "CellIterator.h"

using namespace Sudoku;

CellIterator::CellIterator(CellIterator::pointer firstElementPointer)
    : m_currentCellInGridPointer(firstElementPointer)
{
}

CellIterator::reference CellIterator::operator*()
{
    return *m_currentCellInGridPointer;
}

CellIterator::reference CellIterator::operator->()
{
    return *m_currentCellInGridPointer;
}

CellIterator& CellIterator::operator++()
{
    ++m_currentCellInGridPointer;
    return *this;
}

CellIterator CellIterator::operator++(int)
{
    auto tmp = *this;
    ++m_currentCellInGridPointer;
    return tmp;
}

bool CellIterator::operator==(const CellIterator &rhs) const
{
    return m_currentCellInGridPointer == rhs.m_currentCellInGridPointer;
}

bool CellIterator::operator!=(const CellIterator &rhs) const
{
    return m_currentCellInGridPointer != rhs.m_currentCellInGridPointer;
}
