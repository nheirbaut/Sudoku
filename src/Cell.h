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

    /**
     * Cell constructor.
     * @param maxValue The maximum value the Cell can represent.
     */
    Cell(ValueType maxValue);

    /**
     * Assignment operator to assign a new value to the Cell.
     * @param value The value to set for the Cell.
     * @return The reference to the changed Cell.
     * @thow std::out_of_range If the @p value is larger than the maximum value
     *                         during construction.
     */
    Cell& operator=(ValueType value);

    /**
     * Convert the Cell to its value.
     */
    operator ValueType() const;

private:

    ValueType m_value;
    const ValueType m_maxValue;

}; // class Cell

} // namespace Sudoku

#endif // CELL_H
