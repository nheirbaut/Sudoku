#ifndef BOARD_H
#define BOARD_H

#include <cstdint>

namespace Sudoku {

/**
 * @brief The Board class
 */
class Board
{
public:

    using FieldType = std::uint8_t;

    static const FieldType MAX_FIELD_VALUE;

public:

    /**
     * Creates a new Sudoku board.
     * A Sudoku board must always be a square composed of other squares that
     * have exactly as many elements as the rib of the Sudoku board.
     * @param blockSize The block size for the board. On a standard Sudoku board
     *                  this value will be 9.
     * @throws std::invalid_argument if @p blockSize does not lead to a square
     *                               Sudoku board.
     * @throws std::out_of_range if @p blockSize exceeds Board::MAX_FIELD_VALUE.
     */
    explicit Board(FieldType blockSize);

}; // class Board

} // namespace Sudoku

#endif // BOARD_H
