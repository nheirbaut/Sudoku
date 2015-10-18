#ifndef BOARD_H
#define BOARD_H

#include <boost/range/concepts.hpp>
#include <boost/range/detail/any_iterator.hpp>

#include <cstdint>
#include <memory>

namespace Sudoku {

/**
 * @brief The Board class
 */
class Board
{
public:

    using FieldType = std::uint8_t;
    using RowIndexType = FieldType;
    using ColumnIndexType = FieldType;

    using iterator = boost::range_detail::any_iterator<
                        FieldType,
                        boost::forward_traversal_tag,
                        FieldType&,
                        std::ptrdiff_t
                     >;

    using const_iterator = boost::range_detail::any_iterator<
                            const FieldType,
                            boost::forward_traversal_tag,
                            const FieldType&,
                            std::ptrdiff_t
                           >;

    static const FieldType UNSET_FIELD_VALUE;
    static const FieldType MAX_BLOCKSIZE;

public:

    /**
     * Creates a new Sudoku board.
     * A Sudoku board must always be a square composed of other squares that
     * have exactly as many elements as the rib of the entire Sudoku board.
     * @param blockSize The block size for the board. On a standard Sudoku board
     *                  this value will be 9.
     * @throw std::invalid_argument if @p blockSize does not lead to a square
     *                              Sudoku board.
     * @throw std::out_of_range if @p blockSize exceeds Board::MAX_FIELD_VALUE.
     */
    explicit Board(FieldType blockSize);

    ~Board();
    Board(Board&&);
    Board& operator=(Board&&);

    /**
     * Get the value at the given location on the board. The top-left location
     * is coordinate (0,0);
     * @param row The row index of the value on the board
     * @param column The column index of the value on the board
     * @return The set value at the given row and column on the board.
     * @throw std::out_of_range if the values for @p row or @p column are
     *                          off the defined board.
     */
    FieldType getValueForField(RowIndexType row, ColumnIndexType column) const;

    /**
     * Set the given value at the given location on the board. The top-left
     * location is coordinate (0,0).
     * @param row The row index of the value on the board
     * @param column The column index of the value on the board
     * @param value The value to set on the board.
     * @throw std::out_of_range if the values for @p row or @p column are
     *                          off the defined board or if the value of
     *                          @p value is too large.
     */
    void setValueForField(RowIndexType row, ColumnIndexType column, FieldType value);

    iterator begin();
    iterator end();

    const_iterator begin() const;
    const_iterator end() const;

    const_iterator cbegin() const;
    const_iterator cend() const;

private:

    struct Implementation;
    std::unique_ptr<Implementation> m_implementation;

}; // class Board

} // namespace Sudoku

#endif // BOARD_H
