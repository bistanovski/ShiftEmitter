MODELS_SOURCES_DIR = $$PWD/models
NETWORK_SOURCES_DIR = $$PWD/network
REQUESTS_SOURCES_DIR = $${NETWORK_SOURCES_DIR}/requests

HEADERS += \
    $$PWD/Utility.hpp \
    $$PWD/ShiftSettings.hpp \
    $${MODELS_SOURCES_DIR}/ReceptorsModel.hpp \
    $${NETWORK_SOURCES_DIR}/TelemetryTransporter.hpp \
    $${NETWORK_SOURCES_DIR}/RestClient.hpp \
    $${NETWORK_SOURCES_DIR}/AmqpClient.hpp \
    $${REQUESTS_SOURCES_DIR}/AbstractWebRequest.hpp \
    $${REQUESTS_SOURCES_DIR}/RegisterDeviceRequest.hpp \
    $${REQUESTS_SOURCES_DIR}/RegisterUserRequest.hpp

SOURCES += main.cpp \
    $$PWD/Utility.cpp \
    $$PWD/ShiftSettings.cpp \
    $${MODELS_SOURCES_DIR}/ReceptorsModel.cpp \
    $${NETWORK_SOURCES_DIR}/TelemetryTransporter.cpp \
    $${NETWORK_SOURCES_DIR}/RestClient.cpp \
    $${NETWORK_SOURCES_DIR}/AmqpClient.cpp \
    $${REQUESTS_SOURCES_DIR}/AbstractWebRequest.cpp \
    $${REQUESTS_SOURCES_DIR}/RegisterDeviceRequest.cpp \
    $${REQUESTS_SOURCES_DIR}/RegisterUserRequest.cpp
