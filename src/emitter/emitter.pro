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

contains(DEFINES, ANDROID) {

    ## The library libQt5Sensors.so have to be linked against the executable
    ## and not against receptor-bridge, since the bridge is built as library
    ## Linking against receptor-bridge does not bundle Qt5Sensors into final APK, and causes crash

    ## NOTE: ANDROID_EXTRA_LIBS variable puts the library under 'bundled_libs' property in libs.xml file, and not
    ## under 'qt_libs', and code from Qt5Sensors is never executed. Use LIBS instead

    LIBS += $$[QT_INSTALL_LIBS]/libQt5Sensors.so
}


DEFINES += SHOW_STATUS
include($$PRI_PATH/status.pri)
