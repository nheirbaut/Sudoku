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
    for (auto gridIterator = grid.ConstCellBegin(); gridIterator != grid.ConstCellEnd(); ++gridIterator)
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

    for (auto gridIterator = grid.CellBegin(); gridIterator != grid.CellEnd(); ++gridIterator)
    {
        *gridIterator = testValue;
    }

    std::size_t numberOfCorrectlySetTestValues {0};
    for (auto gridIterator = grid.ConstCellBegin(); gridIterator != grid.ConstCellEnd(); ++gridIterator)
    {
        if (*gridIterator == testValue)
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

    for (auto rowIterator = grid.RowBegin(); rowIterator != grid.RowEnd(); ++rowIterator)
    {
        ++numberOfRows;
    }

    REQUIRE(numberOfRows == blockSize);
}

TEST_CASE("Can const iterate over all columns", "[Grid Access]")
{
    const Sudoku::Cell::ValueType blockSize {9};
    Sudoku::Grid grid {blockSize};

    Sudoku::Cell::ValueType numberOfColumns {0};

    for (auto columnIterator = grid.ConstColumnBegin(); columnIterator != grid.ConstColumnEnd(); ++columnIterator)
    {
        ++numberOfColumns;
    }

    REQUIRE(numberOfColumns == blockSize);
}

TEST_CASE("Can iterate over all columns", "[Grid Access]")
{
    const Sudoku::Cell::ValueType blockSize {9};
    Sudoku::Grid grid {blockSize};

    Sudoku::Cell::ValueType numberOfColumns {0};

    for (auto columnIterator = grid.ColumnBegin(); columnIterator != grid.ColumnEnd(); ++columnIterator)
    {
        ++numberOfColumns;
    }

    REQUIRE(numberOfColumns == blockSize);
}

TEST_CASE("Can const iterate over all rows", "[Grid Access]")
{
    const Sudoku::Cell::ValueType blockSize {9};
    Sudoku::Grid grid {blockSize};

    Sudoku::Cell::ValueType numberOfRows {0};

    for (auto rowIterator = grid.ConstRowBegin(); rowIterator != grid.ConstRowEnd(); ++rowIterator)
    {
        ++numberOfRows;
    }

    REQUIRE(numberOfRows == blockSize);
}

TEST_CASE("Cannot set a cell to an invalid value using an iterator", "[Grid Access]")
{
    const Sudoku::Cell::ValueType blockSize {1};
    Sudoku::Grid grid {blockSize};

    REQUIRE_THROWS_AS(*grid.CellBegin() = Sudoku::Grid::MAX_BLOCKSIZE + 1, std::out_of_range);
}
