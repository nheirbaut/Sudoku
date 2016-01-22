#ifndef CELLITERATORS_H
#define CELLITERATORS_H

#include "Cell.h"

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
class CellIteratorTemplate
    : public std::iterator<std::forward_iterator_tag,
                           UnqualifiedType,
                           std::ptrdiff_t,
                           Type*,
                           Type&>
{
public:

    explicit CellIteratorTemplate(UnqualifiedType* firstElementPointer)
        : m_currentCellInGridPointer(firstElementPointer)
    {}

    CellIteratorTemplate()
        : m_currentCellInGridPointer(nullptr)
    {}

    void swap(CellIteratorTemplate& other) noexcept
    {
        std::swap(m_currentCellInGridPointer, other.m_currentCellInGridPointer);
    }

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

    // two-way comparison: v.begin() == v.cbegin() and vice versa
    template<typename OtherType>
    bool operator==(const CellIteratorTemplate<OtherType>& rhs) const
    {
        return m_currentCellInGridPointer == rhs.m_currentCellInGridPointer;
    }

    template<typename OtherType>
    bool operator!=(const CellIteratorTemplate<OtherType>& rhs) const
    {
        return m_currentCellInGridPointer != rhs.m_currentCellInGridPointer;
    }

    Type& operator*() const
    {
        return *m_currentCellInGridPointer;
    }

    Type& operator->() const
    {
        return *m_currentCellInGridPointer;
    }

    // One way conversion: iterator -> const_iterator
    operator CellIteratorTemplate<const Type>() const
    {
        return CellIteratorTemplate<const Type>(m_currentCellInGridPointer);
    }

private:

    UnqualifiedType* m_currentCellInGridPointer;

}; // class CellIteratorTemplate

using CellIterator = CellIteratorTemplate<Cell>;
using ConstCellIterator = CellIteratorTemplate<const Cell>;

} // namespace Sudoku

#endif // CELLITERATORS_H

