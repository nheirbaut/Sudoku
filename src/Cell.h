#ifndef CELL_H
#define CELL_H

#include <cstdint>

namespace Sudoku {

/**
 * @brief The Cell class
 */
class Cell
{
public:

    using ValueType = std::uint8_t;
    static const ValueType UNSET_CELL_VALUE;

public:

    Cell(ValueType maxValue);

    Cell& operator=(ValueType value);

    operator ValueType() const;

private:

    ValueType m_value;
    const ValueType m_maxValue;

}; // class Cell

} // namespace Sudoku

#endif // CELL_H
