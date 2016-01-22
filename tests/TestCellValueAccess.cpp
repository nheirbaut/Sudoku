#include <catch.hpp>

#include "Cell.h"

TEST_CASE("Cannot set a cell value larger than the set maximum", "[Cell Access]")
{
    const Sudoku::Cell::ValueType maximumCellValue {1};
    Sudoku::Cell cell {maximumCellValue};

    REQUIRE_THROWS_AS(cell = maximumCellValue + 1, std::out_of_range);
}

TEST_CASE("Can convert a cell directly to its value", "[Cell Access]")
{
    const Sudoku::Cell::ValueType maximumCellValue {2};
    const Sudoku::Cell::ValueType cellTestValue {maximumCellValue - 1};
    Sudoku::Cell cell {maximumCellValue};

    cell = cellTestValue;
    const Sudoku::Cell::ValueType convertedCellValue {cell};

    REQUIRE(convertedCellValue == cellTestValue);
}
