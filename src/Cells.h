#ifndef CELLS_H
#define CELLS_H

#include "CellIterators.h"

namespace Sudoku {

/**
 * @brief The Cells class
 * It provides a view on the data of the Sudoku grid as individual cells.
 */
class Cells
{
public:

    explicit Cells(Cell* startingCell, std::size_t size);

    CellIterator begin();
    CellIterator end();
    ConstCellIterator begin() const;
    ConstCellIterator end() const;
    ConstCellIterator cbegin() const;
    ConstCellIterator cend() const;

private:

    Cell* m_startingCell;
    const std::size_t m_collectionSize;

}; // class Cells

} // namespace Sudoku

#endif // CELLS_H
