#include "SimulatedProximity.hpp"

#include "fake-readings/FakeProximityReading.hpp"

SimulatedProximity::SimulatedProximity(QObject *parent) : ProximityReceptor(parent)
{
    setConnectedToBackend(true);
    setIsListening(true);
}

SimulatedProximity::~SimulatedProximity()
{
    m_workerThread.exit();
    m_workerThread.wait(1000);
}

void SimulatedProximity::connectReceptor()
{
    setConnectedToBackend(true);
    FakeProximityReading *fakeReading = new FakeProximityReading;
    connect(fakeReading, &FakeProximityReading::readingChanged, this, &SimulatedProximity::somethingIsCloseChanged);
    connect(&m_workerThread, &QThread::started, fakeReading, &FakeProximityReading::startGeneratingData);
    connect(&m_workerThread, &QThread::finished, fakeReading, &FakeProximityReading::stopGeneratingData);
    fakeReading->moveToThread(&m_workerThread);
}

void SimulatedProximity::startListening()
{
    setIsListening(true);
    m_workerThread.start();
}
