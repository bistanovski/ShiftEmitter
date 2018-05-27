include($$PRI_PATH/defines.pri)
include($$PRI_PATH/platform.pri)
include($$PRI_PATH/shared-library.pri)

QT += sensors

contains(DEFINES, SHIFT_ANDROID) {
    ## When Android build is needed, 'quick' must be provided
    ## So the qmlRegisterType<>() method is accessible
    QT += quick
}

DESTDIR  = $${ROOT_BUILD}/libs

include($$PWD/bridge-sources.pri)

DEFINES += SHOW_STATUS
include($$PRI_PATH/status.pri)
