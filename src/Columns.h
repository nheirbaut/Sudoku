#ifndef COLUMNS_H
#define COLUMNS_H

#include "ColumnIterators.h"

namespace Sudoku {

class Columns
{
public:

    explicit Columns(Cell* firstCellInFirstColumn, std::size_t size);

    ColumnIterator begin();
    ColumnIterator end();
    ConstColumnIterator begin() const;
    ConstColumnIterator end() const;
    ConstColumnIterator cbegin() const;
    ConstColumnIterator cend() const;

private:

    Cell* m_firstCellInFirstColumn;
    const std::size_t m_size;

}; // class Columns

} // namespace Sudoku

#endif // COLUMNS_H
