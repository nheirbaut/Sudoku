#include "Cell.h"

#include <stdexcept>

using namespace Sudoku;

const Cell::ValueType Cell::UNSET_CELL_VALUE = 0;

Cell::Cell(ValueType maxValue)
    : m_value(UNSET_CELL_VALUE),
      m_maxValue(maxValue)
{
}

Cell& Cell::operator=(Cell::ValueType value)
{
    if (value > m_maxValue)
    {
        throw std::out_of_range("The value is too large");
    }

    m_value = value;
    return *this;
}

Cell::operator Cell::ValueType() const
{
    return m_value;
}
