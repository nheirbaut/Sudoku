#include "Cell.h"

namespace Sudoku {

const Cell::ValueType Cell::UNSET_CELL_VALUE = 0;

Cell::Cell()
    : m_value(UNSET_CELL_VALUE)
{
}

Cell& Cell::operator=(Cell::ValueType value)
{
    m_value = value;
    return *this;
}

Cell::operator Cell::ValueType() const
{
    return m_value;
}

} // namespace Sudoku
