#include "SimulatedAccelerometer.hpp"

#include <QDebug>
#include "fake-readings/FakeAccelerometerReading.hpp"

SimulatedAccelerometer::SimulatedAccelerometer(QObject *parent) : AccelerometerReceptor(parent)
{
    setConnectedToBackend(true);
    setIsListening(true);
}

SimulatedAccelerometer::~SimulatedAccelerometer()
{
    m_workerThread.exit();
    m_workerThread.wait(1000);
}

void SimulatedAccelerometer::connectReceptor()
{
    setConnectedToBackend(true);
    FakeAccelerometerReading *fakeReading = new FakeAccelerometerReading();
    connect(fakeReading, &FakeAccelerometerReading::readingChanged, this, &SimulatedAccelerometer::accelerationChanged);
    connect(&m_workerThread, &QThread::started, fakeReading, &FakeAccelerometerReading::startGeneratingData);
    connect(&m_workerThread, &QThread::finished, fakeReading, &FakeAccelerometerReading::stopGeneratingData);
    fakeReading->moveToThread(&m_workerThread);
}

void SimulatedAccelerometer::startListening()
{
    setIsListening(true);
    m_workerThread.start();
}
