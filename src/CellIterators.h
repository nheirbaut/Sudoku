#ifndef CELLITERATORTEMPLATE
#define CELLITERATORTEMPLATE

#include <Cell.h>

#include <iterator>
#include <type_traits>

namespace Sudoku {

template<typename ValueType>
class CellIteratorTemplate : public std::iterator<
                                std::forward_iterator_tag,
                                std::remove_cv_t<ValueType>,
                                std::ptrdiff_t,
                                ValueType*,
                                ValueType&>
{
public:

    explicit CellIteratorTemplate(ValueType* firstElementPointer)
        : m_currentCellInGridPointer(firstElementPointer)
    {}

    CellIteratorTemplate& operator++()
    {
        ++m_currentCellInGridPointer;
        return *this;
    }

    CellIteratorTemplate operator++(int)
    {
        CellIteratorTemplate tmp(*this);
        ++(*this);
        return tmp;
    }

    bool operator==(const CellIteratorTemplate& rhs)
    {
        return m_currentCellInGridPointer == rhs.m_currentCellInGridPointer;
    }

    bool operator!=(const CellIteratorTemplate& rhs)
    {
        return m_currentCellInGridPointer != rhs.m_currentCellInGridPointer;
    }

    ValueType& operator*() const
    {
        return *m_currentCellInGridPointer;
    }

    ValueType& operator->() const
    {
        return *m_currentCellInGridPointer;
    }

private:

    ValueType* m_currentCellInGridPointer;

}; // class CellIteratorTemplate

using CellIterator = CellIteratorTemplate<Cell>;
using ConstCellIterator = CellIteratorTemplate<const Cell>;

} // namespace Sudoku

#endif // CELLITERATORTEMPLATE

