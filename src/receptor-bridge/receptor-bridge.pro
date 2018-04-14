include($$PRI_PATH/defines.pri)
include($$PRI_PATH/platform.pri)
include($$PRI_PATH/shared-library.pri)

QT += sensors

DESTDIR  = $${ROOT_BUILD}/libs

HEADERS += \
    Receptor.hpp \
    ReceptorBridge.hpp \
    ReceptorFactory.hpp \
    LightReceptor.hpp \
    CompassReceptor.hpp \
    AmbientLightReceptor.hpp \
    OrientationReceptor.hpp \
    ProximityReceptor.hpp \
    TiltReceptor.hpp \
    AccelerometerReceptor.hpp \
    MagnetometerReceptor.hpp \
    DummyReceptor.hpp

SOURCES += \
    Receptor.cpp \
    ReceptorBridge.cpp \
    ReceptorFactory.cpp \
    LightReceptor.cpp \
    CompassReceptor.cpp \
    AmbientLightReceptor.cpp \
    OrientationReceptor.cpp \
    ProximityReceptor.cpp \
    TiltReceptor.cpp \
    AccelerometerReceptor.cpp \
    MagnetometerReceptor.cpp \
    DummyReceptor.cpp


DEFINES += SHOW_STATUS

include($$PRI_PATH/status.pri)
