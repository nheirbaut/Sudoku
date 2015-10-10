#define CATCH_CONFIG_MAIN

#include <catch.hpp>

#include "Board.h"

TEST_CASE("Cannot create a board that is not square", "[Board Creation]")
{
    REQUIRE_THROWS_AS(Sudoku::Board(2), std::invalid_argument);
}

TEST_CASE("Cannot create a board that exceeds the maximum size for the given type", "[Board Creation]")
{
    REQUIRE_THROWS_AS(Sudoku::Board(Sudoku::Board::MAX_FIELD_VALUE + 1), std::out_of_range);
}

TEST_CASE("Can create a board that is a perfect square", "[Board Creation]")
{
    REQUIRE_NOTHROW(Sudoku::Board(9));
}

