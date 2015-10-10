#define CATCH_CONFIG_MAIN

#include <catch.hpp>

#include "Board.h"

TEST_CASE("Cannot create a board with no fields", "[board creation]")
{
    REQUIRE_THROWS_AS(Sudoku::Board(0), std::invalid_argument);
}
