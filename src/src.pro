include(../defaults.pri)

CONFIG   += console
CONFIG   -= app_bundle
CONFIG   -= qt

TEMPLATE = lib

TARGET = SudokuSolver

SOURCES += \
    Board.cpp \
    Cell.cpp

HEADERS += \
    Board.h \
    Cell.h
