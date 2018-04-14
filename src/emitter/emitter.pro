include($$PRI_PATH/defines.pri)
include($$PRI_PATH/platform.pri)

QT += quick

TEMPLATE = app
TARGET   = ShiftEmitter
DESTDIR  = $${ROOT_BUILD}

SOURCES += main.cpp
INCLUDEPATH += $$SRC_PATH

#Simulator
LIBS += -L$${ROOT_BUILD}/libs -lsimulator

#Receptor
LIBS += -L$${ROOT_BUILD}/libs -lreceptor-bridge

RESOURCES += \
    resources/res.qrc


DEFINES += SHOW_STATUS
include($$PRI_PATH/status.pri)
