#ifndef BOARD_H
#define BOARD_H

namespace Sudoku {

class Board
{
public:

    /**
     * Creates a new Sudoku board.
     * @param size The initial size.
     * @throws std::invalid_argument if an invalid argument is given.
     */
    Board(unsigned int size);

}; // class Board

} // namespace Sudoku

#endif // BOARD_H
