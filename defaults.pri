INCLUDEPATH += $$PWD/src
SRC_DIR = $$PWD

# Global compile flag defaults
QMAKE_CXXFLAGS += -O2 -std=c++14 -Wall -Weffc++ -pedantic  \
                -pedantic-errors -Wextra -Waggregate-return -Wcast-align \
                -Wcast-qual \
                -Wdisabled-optimization \
                -Werror -Wfloat-equal -Wformat=2 \
                -Wformat-nonliteral -Wformat-security  \
                -Wformat-y2k \
                -Wimport  -Winit-self  -Winline \
                -Winvalid-pch   \
                -Wlong-long \
                -Wmissing-field-initializers -Wmissing-format-attribute   \
                -Wmissing-include-dirs -Wmissing-noreturn \
                -Wpacked -Wpointer-arith \
                -Wredundant-decls \
                -Wshadow -Wstack-protector \
                -Wstrict-aliasing=2 -Wswitch-default \
                -Wswitch-enum \
                -Wunreachable-code -Wunused \
                -Wunused-parameter \
                -Wvariadic-macros \
                -Wwrite-strings
