include($$PRI_PATH/defines.pri)
include($$PRI_PATH/platform.pri)
include($$PRI_PATH/shared-library.pri)

RECEPTORS_SRC_DIR = $$SRC_PATH/receptor-bridge
INCLUDEPATH += $${RECEPTORS_SRC_DIR}

QT += sensors

contains(DEFINES, SHIFT_ANDROID) {
    ## When Android build is needed, 'quick' must be provided
    ## So the qmlRegisterType<>() method is accessible
    QT += quick
}

DESTDIR  = $${ROOT_BUILD}/libs

include(fake-readings.pri)
include(simulator-sources.pri)

#Receptor
LIBS += -L$${ROOT_BUILD}/libs -lreceptor-bridge

DEFINES += SHOW_STATUS
include($$PRI_PATH/status.pri)
