include(../defaults.pri)

CONFIG   += console
CONFIG   -= app_bundle
CONFIG   -= qt

TEMPLATE = lib

TARGET = SudokuSolver

SOURCES += \
    Grid.cpp \
    Cell.cpp \
    CellCollection.cpp

HEADERS += \
    Grid.h \
    Cell.h \
    CellIterators.h \
    RowIterators.h \
    Row.h \
    ColumnIterators.h \
    Column.h \
    CellCollection.h
