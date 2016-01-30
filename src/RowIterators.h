#ifndef ROWITERATORS_H
#define ROWITERATORS_H

#include "Cell.h"
#include "Row.h"

#include <iterator>
#include <type_traits>

namespace Sudoku {

template
<
    typename Type,
    typename UnqualifiedType = std::remove_cv_t<Type>
>
class RowIteratorTemplate
    : public std::iterator<std::forward_iterator_tag,
                           UnqualifiedType,
                           std::ptrdiff_t,
                           Type*,
                           Type&>
{
private:

    using RowType = typename std::conditional
                             <
                                 std::is_const<Type>::value,
                                 const Row<Type>,
                                 Row<Type>
                             >::type;

public:

    explicit RowIteratorTemplate(Type* firstRowPointer, Cell::ValueType rowSize)
        : m_currentRowInGridPointer(firstRowPointer),
          m_rowSize(rowSize)
    {}

    RowIteratorTemplate()
        : m_currentRowInGridPointer(nullptr),
          m_rowSize(0)
    {}

    void swap(RowIteratorTemplate& other) noexcept
    {
        std::swap(m_currentRowInGridPointer, other.m_currentRowInGridPointer);
        std::swap(m_rowSize, other.m_rowSize);
    }

    RowIteratorTemplate& operator++()
    {
        m_currentRowInGridPointer += m_rowSize;
        return *this;
    }

    RowIteratorTemplate operator++(int)
    {
        RowIteratorTemplate tmp(*this);
        m_currentRowInGridPointer += m_rowSize;
        return tmp;
    }

    // two-way comparison: v.begin() == v.cbegin() and vice versa
    template<typename OtherType>
    bool operator==(const RowIteratorTemplate<OtherType>& rhs) const
    {
        return m_currentRowInGridPointer == rhs.m_currentRowInGridPointer;
    }

    template<typename OtherType>
    bool operator!=(const RowIteratorTemplate<OtherType>& rhs) const
    {
        return m_currentRowInGridPointer != rhs.m_currentRowInGridPointer;
    }

    RowType operator*() const
    {
        return Row<Type>(m_currentRowInGridPointer, m_rowSize);
    }

    RowType operator->() const
    {
        return Row<Type>(m_currentRowInGridPointer, m_rowSize);
    }

    // One way conversion: iterator -> const_iterator
    operator RowIteratorTemplate<const Type>() const
    {
        return RowIteratorTemplate<const Type>(m_currentRowInGridPointer);
    }

private:

    Type* m_currentRowInGridPointer;
    const Cell::ValueType m_rowSize;

}; // class RowIteratorTemplate

using RowIterator = RowIteratorTemplate<Cell>;
using ConstRowIterator = RowIteratorTemplate<const Cell>;

} // namespace Sudoku

#endif // ROWITERATORS_H

