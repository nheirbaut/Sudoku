include(../defaults.pri)

CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

TEMPLATE = app

SOURCES += \
    TestGridCreation.cpp \
    TestGridValueAccess.cpp \
    TestCellValueAccess.cpp \
    TestMain.cpp

LIBS += -L../src -lSudokuSolver

HEADERS +=
