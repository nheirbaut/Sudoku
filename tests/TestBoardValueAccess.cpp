#include <catch.hpp>

#include "Board.h"

TEST_CASE("Cannot access cells outside row range", "[Board Access]")
{
    const Sudoku::Board::CellType blockSize {4};
    auto board = Sudoku::Board {blockSize};

    REQUIRE_THROWS_AS(board.getValueForCell(blockSize, 0), std::out_of_range);
}

TEST_CASE("Cannot access cells outside column range", "[Board Access]")
{
    const Sudoku::Board::CellType blockSize {4};
    auto board = Sudoku::Board {blockSize};

    REQUIRE_THROWS_AS(board.getValueForCell(0, blockSize), std::out_of_range);
}

TEST_CASE("Cannot set cells outside row range", "[Board Access]")
{
    const Sudoku::Board::CellType blockSize {4};
    auto board = Sudoku::Board {blockSize};

    REQUIRE_THROWS_AS(board.setValueForCell(blockSize, 0, Sudoku::Board::UNSET_CELL_VALUE), std::out_of_range);
}

TEST_CASE("Cannot set cells outside column range", "[Board Access]")
{
    const Sudoku::Board::CellType blockSize {4};
    auto board = Sudoku::Board {blockSize};

    REQUIRE_THROWS_AS(board.setValueForCell(0, blockSize, Sudoku::Board::UNSET_CELL_VALUE), std::out_of_range);
}

TEST_CASE("Cannot set an invalid value using a valid location", "[Board Access]")
{
    const Sudoku::Board::CellType blockSize {4};
    auto board = Sudoku::Board {blockSize};

    REQUIRE_THROWS_AS(board.setValueForCell(0, 0, Sudoku::Board::MAX_BLOCKSIZE + 1), std::out_of_range);
}

TEST_CASE("Can set a valid value on the board", "[Board Access]")
{
    const Sudoku::Board::CellType blockSize {4};
    const Sudoku::Board::CellType validValue {1};
    auto board = Sudoku::Board {blockSize};

    board.setValueForCell(0, 0, validValue);

    REQUIRE(board.getValueForCell(0, 0) == validValue);
}

TEST_CASE("Can iterate over all board cells", "[Board Access]")
{
    const Sudoku::Board::CellType blockSize {4};
    auto board = Sudoku::Board {blockSize};

    std::size_t numberOfCellsOnBoard {0};
    for (auto boardIterator = board.cbegin(); boardIterator != board.cend(); ++boardIterator)
    {
        ++numberOfCellsOnBoard;
    }

    REQUIRE(numberOfCellsOnBoard == blockSize * blockSize);
}

TEST_CASE("Can change board values using iterators", "[Board Access]")
{
    const Sudoku::Board::CellType testValue {1};
    const Sudoku::Board::CellType blockSize {4};
    auto board = Sudoku::Board {blockSize};

    for (auto boardIterator = board.begin(); boardIterator != board.end(); ++boardIterator)
    {
        *boardIterator = testValue;
    }

    std::size_t numberOfCorrectlySetTestValues {0};
    for (auto boardIterator = board.cbegin(); boardIterator != board.cend(); ++boardIterator)
    {
        if (*boardIterator == testValue)
        {
            ++numberOfCorrectlySetTestValues;
        }
    }

    REQUIRE(numberOfCorrectlySetTestValues == blockSize * blockSize);
}

TEST_CASE("Cannot set a cell to an invalid value using an iterator", "[Board Access]")
{
    const Sudoku::Board::CellType blockSize {1};
    auto board = Sudoku::Board {blockSize};

    REQUIRE_THROWS_AS(*board.begin() = Sudoku::Board::MAX_BLOCKSIZE + 1, std::out_of_range);
}
