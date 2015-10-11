#include <catch.hpp>

#include "Board.h"

TEST_CASE("Cannot access fields outside row range", "[Board Access]")
{
    const Sudoku::Board::FieldType blockSize {4};
    auto board = Sudoku::Board {blockSize};

    REQUIRE_THROWS_AS(board.getValueForField(blockSize, 0), std::out_of_range);
}

TEST_CASE("Cannot access fields outside column range", "[Board Access]")
{
    const Sudoku::Board::FieldType blockSize {4};
    auto board = Sudoku::Board {blockSize};

    REQUIRE_THROWS_AS(board.getValueForField(0, blockSize), std::out_of_range);
}
