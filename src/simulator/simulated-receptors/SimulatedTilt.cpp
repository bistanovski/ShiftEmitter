#include "SimulatedTilt.hpp"

#include "fake-readings/FakeTiltReading.hpp"

SimulatedTilt::SimulatedTilt(QObject *parent) : TiltReceptor(parent)
{
    setConnectedToBackend(true);
    setIsListening(true);
}

SimulatedTilt::~SimulatedTilt()
{

}

void SimulatedTilt::connectReceptor()
{
    setConnectedToBackend(true);
    FakeTiltReading *fakeReading = new FakeTiltReading();
    connect(fakeReading, &FakeTiltReading::readingChanged, this, &SimulatedTilt::tiltDetected);
    connect(&m_workerThread, &QThread::started, fakeReading, &FakeTiltReading::startGeneratingData);
    connect(&m_workerThread, &QThread::finished, fakeReading, &FakeTiltReading::stopGeneratingData);
    fakeReading->moveToThread(&m_workerThread);
}

void SimulatedTilt::startListening()
{
    setIsListening(true);
    m_workerThread.start();
}
