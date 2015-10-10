include(../defaults.pri)

CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

TEMPLATE = app

SOURCES += \
    TestBoardCreation.cpp

LIBS += -L../src -lSudokuSolver
