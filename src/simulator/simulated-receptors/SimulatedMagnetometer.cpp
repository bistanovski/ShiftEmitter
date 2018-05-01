#include "SimulatedMagnetometer.hpp"

#include "fake-readings/FakeMagnetometerReading.hpp"

SimulatedMagnetometer::SimulatedMagnetometer(QObject *parent) : MagnetometerReceptor(parent)
{
    setConnectedToBackend(true);
    setIsListening(true);
}

SimulatedMagnetometer::~SimulatedMagnetometer()
{
    m_workerThread.exit();
    m_workerThread.wait(1000);
}

void SimulatedMagnetometer::connectReceptor()
{
    setConnectedToBackend(true);
    FakeMagnetometerReading *fakeReading = new FakeMagnetometerReading();
    connect(fakeReading, &FakeMagnetometerReading::readingChanged, this, &SimulatedMagnetometer::magneticFluxChanged);
    connect(&m_workerThread, &QThread::started, fakeReading, &FakeMagnetometerReading::startGeneratingData);
    connect(&m_workerThread, &QThread::finished, fakeReading, &FakeMagnetometerReading::stopGeneratingData);
    fakeReading->moveToThread(&m_workerThread);
}

void SimulatedMagnetometer::startListening()
{
    setIsListening(true);
    m_workerThread.start();
}
