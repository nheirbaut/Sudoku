#include <catch.hpp>

#include "Grid.h"

TEST_CASE("Cannot access cells outside row range", "[Grid Access]")
{
    const Sudoku::Cell::ValueType blockSize {4};
    Sudoku::Grid grid {blockSize};

    REQUIRE_THROWS_AS(grid.getValueForCellAt(blockSize, 0), std::out_of_range);
}

TEST_CASE("Cannot access cells outside column range", "[Grid Access]")
{
    const Sudoku::Cell::ValueType blockSize {4};
    Sudoku::Grid grid {blockSize};

    REQUIRE_THROWS_AS(grid.getValueForCellAt(0, blockSize), std::out_of_range);
}

TEST_CASE("Cannot set cells outside row range", "[Grid Access]")
{
    const Sudoku::Cell::ValueType blockSize {4};
    Sudoku::Grid grid {blockSize};

    REQUIRE_THROWS_AS(grid.setValueForCell(blockSize, 0, Sudoku::Cell::UNSET_CELL_VALUE), std::out_of_range);
}

TEST_CASE("Cannot set cells outside column range", "[Grid Access]")
{
    const Sudoku::Cell::ValueType blockSize {4};
    Sudoku::Grid grid {blockSize};

    REQUIRE_THROWS_AS(grid.setValueForCell(0, blockSize, Sudoku::Cell::UNSET_CELL_VALUE), std::out_of_range);
}

TEST_CASE("Cannot set an invalid value using a valid location", "[Grid Access]")
{
    const Sudoku::Cell::ValueType blockSize {4};
    Sudoku::Grid grid {blockSize};

    REQUIRE_THROWS_AS(grid.setValueForCell(0, 0, Sudoku::Grid::MAX_BLOCKSIZE + 1), std::out_of_range);
}

TEST_CASE("Can set a valid value on the grid", "[Grid Access]")
{
    const Sudoku::Cell::ValueType blockSize {4};
    const Sudoku::Cell::ValueType validValue {1};
    Sudoku::Grid grid {blockSize};

    grid.setValueForCell(0, 0, validValue);

    REQUIRE(grid.getValueForCellAt(0, 0) == validValue);
}

TEST_CASE("Can iterate over all grid cells", "[Grid Access]")
{
    const Sudoku::Cell::ValueType blockSize {4};
    Sudoku::Grid grid {blockSize};

    std::size_t numberOfCellsOnGrid {0};
    for (auto& cell : grid.cells())
    {
        ++numberOfCellsOnGrid;
    }

    REQUIRE(numberOfCellsOnGrid == blockSize * blockSize);
}

TEST_CASE("Can change grid values using iterators", "[Grid Access]")
{
    const Sudoku::Cell::ValueType testValue {1};
    const Sudoku::Cell::ValueType blockSize {4};
    Sudoku::Grid grid {blockSize};

    for (auto& cell : grid.cells())
    {
        cell = testValue;
    }

    std::size_t numberOfCorrectlySetTestValues {0};
    for (const auto& cell : grid.cells())
    {
        if (cell == testValue)
        {
            ++numberOfCorrectlySetTestValues;
        }
    }

    REQUIRE(numberOfCorrectlySetTestValues == blockSize * blockSize);
}

TEST_CASE("Can iterate over all rows", "[Grid Access]")
{
    const Sudoku::Cell::ValueType blockSize {9};
    Sudoku::Grid grid {blockSize};

    Sudoku::Cell::ValueType numberOfRows {0};

    for (auto rowIterator = grid.rows().begin(); rowIterator != grid.rows().end(); ++rowIterator)
    {
        ++numberOfRows;
    }

    REQUIRE(numberOfRows == blockSize);
}

TEST_CASE("Can const iterate over all rows", "[Grid Access]")
{
    const Sudoku::Cell::ValueType blockSize {9};
    Sudoku::Grid grid {blockSize};

    Sudoku::Cell::ValueType numberOfRows {0};

    for (auto rowIterator = grid.rows().cbegin(); rowIterator != grid.rows().cend(); ++rowIterator)
    {
        ++numberOfRows;
    }

    REQUIRE(numberOfRows == blockSize);
}

TEST_CASE("Can iterate over all columns", "[Grid Access]")
{
    const Sudoku::Cell::ValueType blockSize {9};
    Sudoku::Grid grid {blockSize};

    Sudoku::Cell::ValueType numberOfColumns {0};

    for (auto columnIterator = grid.columns().begin(); columnIterator != grid.columns().end(); ++columnIterator)
    {
        ++numberOfColumns;
    }

    REQUIRE(numberOfColumns == blockSize);
}

TEST_CASE("Can const iterate over all columns", "[Grid Access]")
{
    const Sudoku::Cell::ValueType blockSize {9};
    Sudoku::Grid grid {blockSize};

    Sudoku::Cell::ValueType numberOfColumns {0};

    for (auto columnIterator = grid.columns().cbegin(); columnIterator != grid.columns().cend(); ++columnIterator)
    {
        ++numberOfColumns;
    }

    REQUIRE(numberOfColumns == blockSize);
}

TEST_CASE("Cannot set a cell to an invalid value using an iterator", "[Grid Access]")
{
    const Sudoku::Cell::ValueType blockSize {1};
    Sudoku::Grid grid {blockSize};

    REQUIRE_THROWS_AS(*grid.cells().begin() = Sudoku::Grid::MAX_BLOCKSIZE + 1, std::out_of_range);
}
