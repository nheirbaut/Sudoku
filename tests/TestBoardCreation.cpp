#define CATCH_CONFIG_MAIN

#include <catch.hpp>

#include "Board.h"
#include "Cell.h"

TEST_CASE("Cannot create a board that is not square", "[Board Creation]")
{
    REQUIRE_THROWS_AS(Sudoku::Board(2), std::invalid_argument);
}

TEST_CASE("Cannot create a board that exceeds the maximum size for the given type", "[Board Creation]")
{
    REQUIRE_THROWS_AS(Sudoku::Board(Sudoku::Board::MAX_BLOCKSIZE + 1), std::out_of_range);
}

TEST_CASE("Can create a board that is a perfect square", "[Board Creation]")
{
    REQUIRE_NOTHROW(Sudoku::Board(9));
}

TEST_CASE("A newly created board has all cells properly initialised", "[Board Creation]")
{
    const Sudoku::Cell::ValueType blockSize {9};
    auto board = Sudoku::Board {blockSize};
    unsigned int numberOfCellsWithNoValueSet {0};

    for (Sudoku::Board::RowIndexType row {0}; row < blockSize; ++row)
    {
        for (Sudoku::Board::ColumnIndexType column {0}; column < blockSize; ++column)
        {
            if (board.getValueForCellAt(row, column) == Sudoku::Cell::UNSET_CELL_VALUE)
            {
                ++numberOfCellsWithNoValueSet;
            }
        }
    }

    REQUIRE(numberOfCellsWithNoValueSet == blockSize * blockSize);
}
