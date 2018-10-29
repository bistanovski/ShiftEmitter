#include "SimulatedGyroscope.hpp"

#include <QDebug>
#include "fake-readings/FakeGyroscopeReading.hpp"

SimulatedGyroscope::SimulatedGyroscope(QObject *parent) : GyroscopeReceptor(parent)
{
    setConnectedToBackend(true);
    setIsListening(true);
}

SimulatedGyroscope::~SimulatedGyroscope()
{
    m_workerThread.exit();
    m_workerThread.wait(1000);
}

void SimulatedGyroscope::connectReceptor()
{
    setConnectedToBackend(true);
    FakeGyroscopeReading *fakeReading = new FakeGyroscopeReading();
    connect(fakeReading, &FakeGyroscopeReading::readingChanged, this, &SimulatedGyroscope::gyroscopeChanged);
    connect(&m_workerThread, &QThread::started, fakeReading, &FakeGyroscopeReading::startGeneratingData);
    connect(&m_workerThread, &QThread::finished, fakeReading, &FakeGyroscopeReading::stopGeneratingData);
    fakeReading->moveToThread(&m_workerThread);
}

void SimulatedGyroscope::startListening()
{
    setIsListening(true);
    m_workerThread.start();
}

void SimulatedGyroscope::stopListening()
{
    m_workerThread.exit();
    m_workerThread.wait(1000);
}
