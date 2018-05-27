#include "SimulatedOrientation.hpp"

#include "fake-readings/FakeOrientationReading.hpp"

SimulatedOrientation::SimulatedOrientation(QObject *parent) : OrientationReceptor(parent)
{
    setConnectedToBackend(true);
    setIsListening(true);
}

SimulatedOrientation::~SimulatedOrientation()
{
    m_workerThread.exit();
    m_workerThread.wait(1000);
}

void SimulatedOrientation::connectReceptor()
{
    setConnectedToBackend(true);
    FakeOrientationReading *fakeReading = new FakeOrientationReading();
    connect(fakeReading, &FakeOrientationReading::readingChanged, this, &SimulatedOrientation::orientationChanged);
    connect(&m_workerThread, &QThread::started, fakeReading, &FakeOrientationReading::startGeneratingData);
    connect(&m_workerThread, &QThread::finished, fakeReading, &FakeOrientationReading::stopGeneratingData);
    fakeReading->moveToThread(&m_workerThread);
}

void SimulatedOrientation::startListening()
{
    setIsListening(true);
    m_workerThread.start();
}

void SimulatedOrientation::stopListening()
{
    m_workerThread.exit();
    m_workerThread.wait(1000);
}
