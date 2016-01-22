#ifndef ROW_H
#define ROW_H

#include "Cell.h"

namespace Sudoku {

template<typename Type>
class Row
{
public:

    Row(Type* firstElementInRow, Cell::ValueType rowSize)
        : m_currentElementInRow(firstElementInRow),
          m_rowSize(rowSize)
    {}

private:

    Type* m_currentElementInRow;
    const Cell::ValueType m_rowSize;
};

} // namespace Sudoku

#endif // ROW_H
