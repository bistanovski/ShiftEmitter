SIMULATOR_SRC_DIR = $${PWD}/simulated-receptors

HEADERS += \
    $${SIMULATOR_SRC_DIR}/SimulatedAccelerometer.hpp \
    $${SIMULATOR_SRC_DIR}/SimulatedAmbientLight.hpp \
    $${SIMULATOR_SRC_DIR}/SimulatedCompass.hpp \
    $${SIMULATOR_SRC_DIR}/SimulatedLight.hpp \
    $${SIMULATOR_SRC_DIR}/SimulatedMagnetometer.hpp \
    $${SIMULATOR_SRC_DIR}/SimulatedOrientation.hpp \
    $${SIMULATOR_SRC_DIR}/SimulatedProximity.hpp \
    $${SIMULATOR_SRC_DIR}/SimulatedTilt.hpp \
    SimulatedReceptorBridge.hpp

SOURCES += \
    $${SIMULATOR_SRC_DIR}/SimulatedAccelerometer.cpp \
    $${SIMULATOR_SRC_DIR}/SimulatedAmbientLight.cpp \
    $${SIMULATOR_SRC_DIR}/SimulatedCompass.cpp \
    $${SIMULATOR_SRC_DIR}/SimulatedLight.cpp \
    $${SIMULATOR_SRC_DIR}/SimulatedMagnetometer.cpp \
    $${SIMULATOR_SRC_DIR}/SimulatedOrientation.cpp \
    $${SIMULATOR_SRC_DIR}/SimulatedProximity.cpp \
    $${SIMULATOR_SRC_DIR}/SimulatedTilt.cpp \
    SimulatedReceptorBridge.cpp
