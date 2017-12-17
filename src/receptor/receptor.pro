include($$PRI_PATH/platform.pri)
include($$PRI_PATH/shared-library.pri)

DESTDIR  = $${ROOT_BUILD}/libs

HEADERS += \
    Receptor.hpp

SOURCES += \
    Receptor.cpp


DEFINES += SHOW_STATUS
include($$PRI_PATH/status.pri)
