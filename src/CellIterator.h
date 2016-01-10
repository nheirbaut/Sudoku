#ifndef CELLITERATOR_H
#define CELLITERATOR_H

#include "Cell.h"

#include <iterator>

namespace Sudoku {

class CellIterator : public std::iterator<std::forward_iterator_tag, Cell>
{
public:

    explicit CellIterator(pointer firstElementPointer);

    reference operator*();
    reference operator->();
    CellIterator& operator++();
    CellIterator operator++(int);
    bool operator==(const CellIterator& rhs) const;
    bool operator!=(const CellIterator& rhs) const;

private:

    pointer m_currentCellInGridPointer;

}; // class CellIterator

} // namespace Sudoku

#endif // CELLITERATOR_H
