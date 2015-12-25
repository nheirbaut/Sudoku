include(../defaults.pri)

CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

TEMPLATE = app

SOURCES += \
    TestBoardCreation.cpp \
    TestBoardValueAccess.cpp \
    TestCellCreation.cpp \
    TestCellValueAccess.cpp

LIBS += -L../src -lSudokuSolver

HEADERS +=
