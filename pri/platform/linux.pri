DEFINES += SHIFT_LINUX

QMAKE_CXXFLAGS += -pedantic -Wall -Wextra
QMAKE_CXXFLAGS += -Wredundant-decls
#QMAKE_CXXFLAGS += -Wsign-promo
QMAKE_CXXFLAGS += -Wmissing-include-dirs   -Woverloaded-virtual
QMAKE_CXXFLAGS += -Wformat=2 -Winit-self
QMAKE_CXXFLAGS += -Wdisabled-optimization
QMAKE_CXXFLAGS += -Wstrict-overflow=5
QMAKE_CXXFLAGS += -Wundef # Warn about referenced but undefined preprocessor defines
QMAKE_CXXFLAGS += -Wno-unused-parameter -Wno-format-contains-nul  -Wno-format-security -Wno-vla

QMAKE_CXXFLAGS += -fstack-protector-all -fstrict-overflow -fstack-usage
