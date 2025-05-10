cmake_minimum_required(VERSION 3.31)
project(sudoku)

set(CMAKE_CXX_STANDARD 14)

include_directories(src)

add_executable(sudoku
        src/Cell.cpp
        src/Cell.h
        src/CellIterators.h
        src/Cells.cpp
        src/Cells.h
        src/Column.h
        src/ColumnIterators.h
        src/Columns.cpp
        src/Columns.h
        src/Grid.cpp
        src/Grid.h
        src/Row.h
        src/RowIterators.h
        src/Rows.cpp
        src/Rows.h
        tests/TestCellValueAccess.cpp
        tests/TestGridCreation.cpp
        tests/TestGridValueAccess.cpp
        tests/TestMain.cpp)
