include(../defaults.pri)

CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

TEMPLATE = app

SOURCES += \
    TestGridCreation.cpp \
    TestGridValueAccess.cpp \
    TestCellCreation.cpp \
    TestCellValueAccess.cpp

LIBS += -L../src -lSudokuSolver

HEADERS +=
