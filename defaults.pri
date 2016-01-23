INCLUDEPATH += $$PWD/src
SRC_DIR = $$PWD

# Global compile flag defaults
QMAKE_CXXFLAGS += \
    -O3 \
    -Wall \
    -Wcast-align \
    -Wcast-qual \
    -Wdisabled-optimization \
    -Weffc++ \
    -Werror \
    -Wextra \
    -Wfloat-equal \
    -Wformat-nonliteral \
    -Wformat-security  \
    -Wformat-y2k \
    -Wformat=2 \
    -Wimport \
    -Winit-self \
    -Winline \
    -Winvalid-pch \
    -Wlong-long \
    -Wmissing-field-initializers \
    -Wmissing-format-attribute \
    -Wmissing-include-dirs \
    -Wmissing-noreturn \
    -Wpacked \
    -Wpointer-arith \
    -Wredundant-decls \
    -Wshadow \
    -Wstack-protector \
    -Wstrict-aliasing=2 \
    -Wswitch-default \
    -Wswitch-enum \
    -Wunreachable-code \
    -Wunused \
    -Wunused-parameter \
    -Wvariadic-macros \
    -Wwrite-strings \
    -Wzero-as-null-pointer-constant \
    -pedantic \
    -pedantic-errors \
    -std=c++14
