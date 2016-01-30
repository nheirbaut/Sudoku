#include <catch.hpp>

#include "Grid.h"

TEST_CASE("Cannot access cells outside row range", "[Grid Access]")
{
    const Sudoku::Cell::ValueType blockSize {4};
    Sudoku::Grid board {blockSize};

    REQUIRE_THROWS_AS(board.getValueForCellAt(blockSize, 0), std::out_of_range);
}

TEST_CASE("Cannot access cells outside column range", "[Grid Access]")
{
    const Sudoku::Cell::ValueType blockSize {4};
    Sudoku::Grid board {blockSize};

    REQUIRE_THROWS_AS(board.getValueForCellAt(0, blockSize), std::out_of_range);
}

TEST_CASE("Cannot set cells outside row range", "[Grid Access]")
{
    const Sudoku::Cell::ValueType blockSize {4};
    Sudoku::Grid board {blockSize};

    REQUIRE_THROWS_AS(board.setValueForCell(blockSize, 0, Sudoku::Cell::UNSET_CELL_VALUE), std::out_of_range);
}

TEST_CASE("Cannot set cells outside column range", "[Grid Access]")
{
    const Sudoku::Cell::ValueType blockSize {4};
    Sudoku::Grid board {blockSize};

    REQUIRE_THROWS_AS(board.setValueForCell(0, blockSize, Sudoku::Cell::UNSET_CELL_VALUE), std::out_of_range);
}

TEST_CASE("Cannot set an invalid value using a valid location", "[Grid Access]")
{
    const Sudoku::Cell::ValueType blockSize {4};
    Sudoku::Grid board {blockSize};

    REQUIRE_THROWS_AS(board.setValueForCell(0, 0, Sudoku::Grid::MAX_BLOCKSIZE + 1), std::out_of_range);
}

TEST_CASE("Can set a valid value on the board", "[Grid Access]")
{
    const Sudoku::Cell::ValueType blockSize {4};
    const Sudoku::Cell::ValueType validValue {1};
    Sudoku::Grid board {blockSize};

    board.setValueForCell(0, 0, validValue);

    REQUIRE(board.getValueForCellAt(0, 0) == validValue);
}

TEST_CASE("Can iterate over all board cells", "[Grid Access]")
{
    const Sudoku::Cell::ValueType blockSize {4};
    Sudoku::Grid board {blockSize};

    std::size_t numberOfCellsOnGrid {0};
    for (auto boardIterator = board.ConstCellBegin(); boardIterator != board.ConstCellEnd(); ++boardIterator)
    {
        ++numberOfCellsOnGrid;
    }

    REQUIRE(numberOfCellsOnGrid == blockSize * blockSize);
}

TEST_CASE("Can change board values using iterators", "[Grid Access]")
{
    const Sudoku::Cell::ValueType testValue {1};
    const Sudoku::Cell::ValueType blockSize {4};
    Sudoku::Grid board {blockSize};

    for (auto boardIterator = board.CellBegin(); boardIterator != board.CellEnd(); ++boardIterator)
    {
        *boardIterator = testValue;
    }

    std::size_t numberOfCorrectlySetTestValues {0};
    for (auto boardIterator = board.ConstCellBegin(); boardIterator != board.ConstCellEnd(); ++boardIterator)
    {
        if (*boardIterator == testValue)
        {
            ++numberOfCorrectlySetTestValues;
        }
    }

    REQUIRE(numberOfCorrectlySetTestValues == blockSize * blockSize);
}

TEST_CASE("Can iterate over all rows", "[Grid Access]")
{
    const Sudoku::Cell::ValueType blockSize {9};
    Sudoku::Grid board {blockSize};

    Sudoku::Cell::ValueType numberOfRows {0};

    for (auto rowIterator = board.RowBegin(); rowIterator != board.RowEnd(); ++rowIterator)
    {
        ++numberOfRows;
    }

    REQUIRE(numberOfRows == blockSize);
}

TEST_CASE("Can const iterate over all columns", "[Grid Access]")
{
    const Sudoku::Cell::ValueType blockSize {9};
    Sudoku::Grid board {blockSize};

    Sudoku::Cell::ValueType numberOfColumns {0};

    for (auto columnIterator = board.ConstColumnBegin(); columnIterator != board.ConstColumnEnd(); ++columnIterator)
    {
        ++numberOfColumns;
    }

    REQUIRE(numberOfColumns == blockSize);
}

TEST_CASE("Can iterate over all columns", "[Grid Access]")
{
    const Sudoku::Cell::ValueType blockSize {9};
    Sudoku::Grid board {blockSize};

    Sudoku::Cell::ValueType numberOfColumns {0};

    for (auto columnIterator = board.ColumnBegin(); columnIterator != board.ColumnEnd(); ++columnIterator)
    {
        ++numberOfColumns;
    }

    REQUIRE(numberOfColumns == blockSize);
}

TEST_CASE("Can const iterate over all rows", "[Grid Access]")
{
    const Sudoku::Cell::ValueType blockSize {9};
    Sudoku::Grid board {blockSize};

    Sudoku::Cell::ValueType numberOfRows {0};

    for (auto rowIterator = board.ConstRowBegin(); rowIterator != board.ConstRowEnd(); ++rowIterator)
    {
        ++numberOfRows;
    }

    REQUIRE(numberOfRows == blockSize);
}

TEST_CASE("Cannot set a cell to an invalid value using an iterator", "[Grid Access]")
{
    const Sudoku::Cell::ValueType blockSize {1};
    Sudoku::Grid board {blockSize};

    REQUIRE_THROWS_AS(*board.CellBegin() = Sudoku::Grid::MAX_BLOCKSIZE + 1, std::out_of_range);
}
