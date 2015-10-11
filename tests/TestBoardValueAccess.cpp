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

TEST_CASE("Cannot set fields outside row range", "[Board Access]")
{
    const Sudoku::Board::FieldType blockSize {4};
    auto board = Sudoku::Board {blockSize};

    REQUIRE_THROWS_AS(board.setValueForField(blockSize, 0, Sudoku::Board::UNSET_FIELD_VALUE), std::out_of_range);
}

TEST_CASE("Cannot set fields outside column range", "[Board Access]")
{
    const Sudoku::Board::FieldType blockSize {4};
    auto board = Sudoku::Board {blockSize};

    REQUIRE_THROWS_AS(board.setValueForField(0, blockSize, Sudoku::Board::UNSET_FIELD_VALUE), std::out_of_range);
}

TEST_CASE("Can set a valid value on the board", "[Board Access]")
{
    const Sudoku::Board::FieldType blockSize {4};
    const Sudoku::Board::FieldType validValue {1};
    auto board = Sudoku::Board {blockSize};

    board.setValueForField(0, 0, validValue);

    REQUIRE(board.getValueForField(0, 0) == validValue);
}
