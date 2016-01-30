#ifndef COLUMN_H
#define COLUMN_H

#include "Cell.h"

namespace Sudoku {

template<typename Type>
class Column
{
public:

    Column(Type* firstElementInColumn, Cell::ValueType columnSize)
        : m_currentElementInColumn(firstElementInColumn),
          m_columnSize(columnSize)
    {}

private:

    Type* m_currentElementInColumn;
    const Cell::ValueType m_columnSize;
};

} // namespace Sudoku

#endif // COLUMN_H
