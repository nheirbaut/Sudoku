#ifndef GRID_H
#define GRID_H

#include "Cell.h"

#include <boost/range/concepts.hpp>
#include <boost/range/detail/any_iterator.hpp>

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

    using iterator = boost::range_detail::any_iterator<
                        Cell,
                        boost::forward_traversal_tag,
                        Cell&,
                        std::ptrdiff_t
                     >;

    using const_iterator = boost::range_detail::any_iterator<
                            const Cell,
                            boost::forward_traversal_tag,
                            const Cell&,
                            std::ptrdiff_t
                           >;

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

    /**
     * @return Return an iterator pointing to the start position of the cells.
     */
    iterator begin();

    /**
     * @return Return an iterator pointing to the end position of the cells.
     */
    iterator end();

    /**
     * @return Return an iterator pointing to the start position of the cells.
     */
    const_iterator begin() const;

    /**
     * @return Return an iterator pointing to the end position of the cells.
     */
    const_iterator end() const;

    /**
     * @return Return an iterator pointing to the start position of the cells.
     */
    const_iterator cbegin() const;

    /**
     * @return Return an iterator pointing to the end position of the cells.
     */
    const_iterator cend() const;

private:

    struct Implementation;
    std::unique_ptr<Implementation> m_implementation;

}; // class Grid

} // namespace Sudoku

#endif // GRID_H
