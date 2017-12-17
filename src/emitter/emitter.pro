include($$PRI_PATH/platform.pri)

QT += quick

TEMPLATE = app
TARGET   = ShiftEmitter
DESTDIR  = $${ROOT_BUILD}

SOURCES += main.cpp

#Simulator
INCLUDEPATH += $$SRC_PATH/simulator
LIBS += -L$${ROOT_BUILD}/libs -lsimulator

#Receptor
INCLUDEPATH += $$SRC_PATH/receptor
LIBS += -L$${ROOT_BUILD}/libs -lreceptor

RESOURCES += \
    resources/res.qrc


DEFINES += SHOW_STATUS
include($$PRI_PATH/status.pri)
