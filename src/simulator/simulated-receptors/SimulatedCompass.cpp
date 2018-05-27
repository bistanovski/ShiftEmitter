#include "SimulatedCompass.hpp"

#include "fake-readings/FakeCompassReading.hpp"

SimulatedCompass::SimulatedCompass(QObject *parent) : CompassReceptor(parent)
{
    setConnectedToBackend(true);
    setIsListening(true);
}

SimulatedCompass::~SimulatedCompass()
{
    m_workerThread.exit();
    m_workerThread.wait(1000);
}

void SimulatedCompass::connectReceptor()
{
    setConnectedToBackend(true);
    FakeCompassReading *fakeReading = new FakeCompassReading();
    connect(fakeReading, &FakeCompassReading::readingChanged, this, &SimulatedCompass::compassReadingChanged);
    connect(&m_workerThread, &QThread::started, fakeReading, &FakeCompassReading::startGeneratingData);
    connect(&m_workerThread, &QThread::finished, fakeReading, &FakeCompassReading::stopGeneratingData);
    fakeReading->moveToThread(&m_workerThread);
}

void SimulatedCompass::startListening()
{
    setIsListening(true);
    m_workerThread.start();
}

void SimulatedCompass::stopListening()
{
    m_workerThread.exit();
    m_workerThread.wait(1000);
}
