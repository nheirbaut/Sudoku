include(../defaults.pri)

CONFIG   += console
CONFIG   -= app_bundle
CONFIG   -= qt

TEMPLATE = lib

TARGET = SudokuSolver

SOURCES += \
    Grid.cpp \
    Cell.cpp \
    CellIterator.cpp

HEADERS += \
    Grid.h \
    Cell.h \
    CellIterator.h
