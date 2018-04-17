include($$PRI_PATH/defines.pri)
include($$PRI_PATH/platform.pri)
include($$PRI_PATH/shared-library.pri)

QT += sensors

contains(DEFINES, ANDROID) {
    ## When Android build is needed, 'quick' must be provided
    ## So the qmlRegisterType<>() method is accessible
    QT += quick
}

DESTDIR  = $${ROOT_BUILD}/libs
RECEPTORS_SRC_DIR = $${PWD}/receptors

HEADERS += \
    $${RECEPTORS_SRC_DIR}/Receptor.hpp \
    $${RECEPTORS_SRC_DIR}/LightReceptor.hpp \
    $${RECEPTORS_SRC_DIR}/CompassReceptor.hpp \
    $${RECEPTORS_SRC_DIR}/AmbientLightReceptor.hpp \
    $${RECEPTORS_SRC_DIR}/OrientationReceptor.hpp \
    $${RECEPTORS_SRC_DIR}/ProximityReceptor.hpp \
    $${RECEPTORS_SRC_DIR}/TiltReceptor.hpp \
    $${RECEPTORS_SRC_DIR}/AccelerometerReceptor.hpp \
    $${RECEPTORS_SRC_DIR}/MagnetometerReceptor.hpp \
    $${RECEPTORS_SRC_DIR}/DummyReceptor.hpp \
    ReceptorInfo.hpp \
    ReceptorBridge.hpp \
    ReceptorFactory.hpp \
    ReceptorUtils.hpp

SOURCES += \
    $${RECEPTORS_SRC_DIR}/LightReceptor.cpp \
    $${RECEPTORS_SRC_DIR}/CompassReceptor.cpp \
    $${RECEPTORS_SRC_DIR}/AmbientLightReceptor.cpp \
    $${RECEPTORS_SRC_DIR}/OrientationReceptor.cpp \
    $${RECEPTORS_SRC_DIR}/ProximityReceptor.cpp \
    $${RECEPTORS_SRC_DIR}/TiltReceptor.cpp \
    $${RECEPTORS_SRC_DIR}/AccelerometerReceptor.cpp \
    $${RECEPTORS_SRC_DIR}/MagnetometerReceptor.cpp \
    $${RECEPTORS_SRC_DIR}/DummyReceptor.cpp \
    ReceptorInfo.cpp \
    ReceptorBridge.cpp \
    ReceptorFactory.cpp

INCLUDEPATH += $${RECEPTORS_SRC_DIR}

DEFINES += SHOW_STATUS
include($$PRI_PATH/status.pri)
