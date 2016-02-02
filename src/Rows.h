#ifndef ROWS_H
#define ROWS_H

#include "RowIterators.h"

namespace Sudoku {

class Rows
{
public:

    explicit Rows(Cell* firstCellInFirstRow, std::size_t size);

    RowIterator begin();
    RowIterator end();
    ConstRowIterator begin() const;
    ConstRowIterator end() const;
    ConstRowIterator cbegin() const;
    ConstRowIterator cend() const;

private:

    Cell* m_firstCellInFirstRow;
    const std::size_t m_size;

}; // class Rows

} // namespace Sudoku

#endif // ROWS_H
