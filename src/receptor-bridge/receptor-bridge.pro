include($$PRI_PATH/defines.pri)
include($$PRI_PATH/platform.pri)
include($$PRI_PATH/shared-library.pri)

QT += sensors

DESTDIR  = $${ROOT_BUILD}/libs

HEADERS += \
    Receptor.hpp \
    ReceptorNetwork.hpp \
    ReceptorFactory.hpp \
    LightReceptor.hpp \
    CompassReceptor.hpp \
    AmbientLightReceptor.hpp \
    OrientationReceptor.hpp \
    DummyReceptor.hpp

SOURCES += \
    Receptor.cpp \
    ReceptorNetwork.cpp \
    ReceptorFactory.cpp \
    LightReceptor.cpp \
    CompassReceptor.cpp \
    AmbientLightReceptor.cpp \
    OrientationReceptor.cpp \
    DummyReceptor.cpp


DEFINES += SHOW_STATUS
include($$PRI_PATH/status.pri)
