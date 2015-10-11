include(../defaults.pri)

CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

TEMPLATE = app

SOURCES += \
    TestBoardCreation.cpp \
    TestBoardValueAccess.cpp

LIBS += -L../src -lSudokuSolver
