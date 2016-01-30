#ifndef COLUMNITERATORS_H
#define COLUMNITERATORS_H

#include "Cell.h"
#include "Column.h"

#include <iterator>
#include <type_traits>

// Code created with the help of Stack Exhange question
// https://codereview.stackexchange.com/questions/74609/custom-iterator-for-a-linked-list-class
// Question by PRP:
// https://codereview.stackexchange.com/users/61711/prp
// Answer by glampert:
// https://codereview.stackexchange.com/users/39810/glampert


namespace Sudoku {

template
<
    typename Type,
    typename UnqualifiedType = std::remove_cv_t<Type>
>
class ColumnIteratorTemplate
    : public std::iterator<std::forward_iterator_tag,
                           UnqualifiedType,
                           std::ptrdiff_t,
                           Type*,
                           Type&>
{
private:

    using ColumnType = typename std::conditional
                             <
                                 std::is_const<Type>::value,
                                 const Column<Type>,
                                 Column<Type>
                             >::type;

public:

    explicit ColumnIteratorTemplate(Type* firstColumnPointer, Cell::ValueType rowSize)
        : m_currentColumnInGridPointer(firstColumnPointer),
          m_rowSize(rowSize)
    {}

    ColumnIteratorTemplate()
        : m_currentColumnInGridPointer(nullptr),
          m_rowSize(0)
    {}

    void swap(ColumnIteratorTemplate& other) noexcept
    {
        std::swap(m_currentColumnInGridPointer, other.m_currentColumnInGridPointer);
        std::swap(m_rowSize, other.m_rowSize);
    }

    ColumnIteratorTemplate& operator++()
    {
        ++m_currentColumnInGridPointer;
        return *this;
    }

    ColumnIteratorTemplate operator++(int)
    {
        ColumnIteratorTemplate tmp(*this);
        ++m_currentColumnInGridPointer;
        return tmp;
    }

    // two-way comparison: v.begin() == v.cbegin() and vice versa
    template<typename OtherType>
    bool operator==(const ColumnIteratorTemplate<OtherType>& rhs) const
    {
        return m_currentColumnInGridPointer == rhs.m_currentColumnInGridPointer;
    }

    template<typename OtherType>
    bool operator!=(const ColumnIteratorTemplate<OtherType>& rhs) const
    {
        return m_currentColumnInGridPointer != rhs.m_currentColumnInGridPointer;
    }

    ColumnType operator*() const
    {
        return Column<Type>(m_currentColumnInGridPointer, m_rowSize);
    }

    ColumnType operator->() const
    {
        return Column<Type>(m_currentColumnInGridPointer, m_rowSize);
    }

    // One way conversion: iterator -> const_iterator
    operator ColumnIteratorTemplate<const Type>() const
    {
        return ColumnIteratorTemplate<const Type>(m_currentColumnInGridPointer);
    }

private:

    Type* m_currentColumnInGridPointer;
    const Cell::ValueType m_rowSize;

}; // class ColumnIteratorTemplate

using ColumnIterator = ColumnIteratorTemplate<Cell>;
using ConstColumnIterator = ColumnIteratorTemplate<const Cell>;

} // namespace Sudoku

#endif // COLUMNITERATORS_H

