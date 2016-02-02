#ifndef CELLCOLLECTION_H
#define CELLCOLLECTION_H

#include "CellIterators.h"

namespace Sudoku {

/**
 * @brief The CellCollection class
 * It provides a view on the data of the Sudoku grid as individual cells.
 */
class CellCollection
{
public:

    explicit CellCollection(Cell* startingCell, std::size_t size);

    CellIterator begin();// { return CellIterator(nullptr); }
    CellIterator end();// { return CellIterator(nullptr); }
    ConstCellIterator begin() const;// { return ConstCellIterator(nullptr); }
    ConstCellIterator end() const;// { return ConstCellIterator(nullptr); }
    ConstCellIterator cbegin() const;// { return ConstCellIterator(nullptr); }
    ConstCellIterator cend() const;// { return ConstCellIterator(nullptr); }

private:

    Cell* m_startingCell;
    const std::size_t m_collectionSize;

}; // class CellCollection

} // namespace Sudoku

#endif // CELLCOLLECTION_H
