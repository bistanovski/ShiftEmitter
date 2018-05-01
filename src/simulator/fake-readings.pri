FAKE_READINGS_SRC_DIR = $${PWD}/fake-readings

HEADERS += \
    $${FAKE_READINGS_SRC_DIR}/FakeAccelerometerReading.hpp \
    $${FAKE_READINGS_SRC_DIR}/FakeAmbientLightReading.hpp \
    $$PWD/fake-readings/FakeCompassReading.hpp \
    $$PWD/fake-readings/FakeLightReading.hpp \
    $$PWD/fake-readings/FakeMagnetometerReading.hpp \
    $$PWD/fake-readings/FakeOrientationReading.hpp \
    $$PWD/fake-readings/FakeProximityReading.hpp \
    $$PWD/fake-readings/FakeTiltReading.hpp

SOURCES += \
    $${FAKE_READINGS_SRC_DIR}/FakeAccelerometerReading.cpp \
    $${FAKE_READINGS_SRC_DIR}/FakeAmbientLightReading.cpp \
    $$PWD/fake-readings/FakeCompassReading.cpp \
    $$PWD/fake-readings/FakeLightReading.cpp \
    $$PWD/fake-readings/FakeMagnetometerReading.cpp \
    $$PWD/fake-readings/FakeOrientationReading.cpp \
    $$PWD/fake-readings/FakeProximityReading.cpp \
    $$PWD/fake-readings/FakeTiltReading.cpp
