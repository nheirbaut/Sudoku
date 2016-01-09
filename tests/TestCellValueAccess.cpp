#include <catch.hpp>

#include "Cell.h"

TEST_CASE("Cannot set a cell value larger than the set maximum", "[Cell Access]")
{
    const Sudoku::Cell::ValueType maximumCellValue {1};
    Sudoku::Cell cell {maximumCellValue};

    REQUIRE_THROWS_AS(cell = maximumCellValue + 1, std::out_of_range);
}
