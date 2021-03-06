#ifndef GRID_H
#define GRID_H

#include "Cells.h"
#include "Columns.h"
#include "Rows.h"

#include <memory>

namespace Sudoku {

/**
 * @brief The Grid class
 */
class Grid
{
public:

    using RowIndexType = Cell::ValueType;
    using ColumnIndexType = Cell::ValueType;

    static const Cell::ValueType MAX_BLOCKSIZE;

public:

    /**
     * Creates a new Sudoku grid.
     * A Sudoku grid must always be a square composed of other squares that
     * have exactly as many elements as the rib of the entire Sudoku grid.
     * @param blockSize The block size for the grid. On a standard Sudoku grid
     *                  this value will be 9.
     * @throw std::invalid_argument if @p blockSize does not lead to a square
     *                              Sudoku grid.
     * @throw std::out_of_range if @p blockSize exceeds Grid::MAX_CELL_VALUE.
     */
    explicit Grid(Cell::ValueType blockSize);

    /**
     * Destructor
     */
    ~Grid();

    Cells cells();
    Rows rows();
    Columns columns();

    /**
     * Get the value at the given location on the grid. The top-left location
     * is coordinate (0,0);
     * @param row The row index of the value on the grid
     * @param column The column index of the value on the grid
     * @return The set value at the given row and column on the grid.
     * @throw std::out_of_range if the values for @p row or @p column are
     *                          off the defined grid.
     */
    Cell::ValueType getValueForCellAt(RowIndexType row, ColumnIndexType column) const;

    /**
     * Set the given value at the given location on the grid. The top-left
     * location is coordinate (0,0).
     * @param row The row index of the value on the grid
     * @param column The column index of the value on the grid
     * @param value The value to set on the grid.
     * @throw std::out_of_range if the values for @p row or @p column are
     *                          off the defined grid or if the value of
     *                          @p value is too large.
     */
    void setValueForCell(RowIndexType row, ColumnIndexType column, Cell::ValueType value);

private:

    struct Implementation;
    std::unique_ptr<Implementation> m_implementation;

}; // class Grid

} // namespace Sudoku

#endif // GRID_H
