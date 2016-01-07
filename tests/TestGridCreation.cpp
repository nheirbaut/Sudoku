#include <catch.hpp>

#include "Grid.h"
#include "Cell.h"

TEST_CASE("Cannot create a grid that is not square", "[Grid Creation]")
{
    REQUIRE_THROWS_AS(Sudoku::Grid(2), std::invalid_argument);
}

TEST_CASE("Cannot create a grid that exceeds the maximum size for the given type", "[Grid Creation]")
{
    REQUIRE_THROWS_AS(Sudoku::Grid(Sudoku::Grid::MAX_BLOCKSIZE + 1), std::out_of_range);
}

TEST_CASE("Can create a grid that is a perfect square", "[Grid Creation]")
{
    REQUIRE_NOTHROW(Sudoku::Grid(9));
}

TEST_CASE("A newly created grid has all cells properly initialised", "[Grid Creation]")
{
    const Sudoku::Cell::ValueType blockSize {9};
    Sudoku::Grid grid {blockSize};
    unsigned int numberOfCellsWithNoValueSet {0};

    for (Sudoku::Grid::RowIndexType row {0}; row < blockSize; ++row)
    {
        for (Sudoku::Grid::ColumnIndexType column {0}; column < blockSize; ++column)
        {
            if (grid.getValueForCellAt(row, column) == Sudoku::Cell::UNSET_CELL_VALUE)
            {
                ++numberOfCellsWithNoValueSet;
            }
        }
    }

    REQUIRE(numberOfCellsWithNoValueSet == blockSize * blockSize);
}
