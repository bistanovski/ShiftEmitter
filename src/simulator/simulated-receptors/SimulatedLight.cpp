#include "SimulatedLight.hpp"

#include "fake-readings/FakeLightReading.hpp"

SimulatedLight::SimulatedLight(QObject *parent) : LightReceptor(parent)
{
    setConnectedToBackend(true);
    setIsListening(true);
}

SimulatedLight::~SimulatedLight()
{
    m_workerThread.exit();
    m_workerThread.wait(1000);
}

void SimulatedLight::connectReceptor()
{
    setConnectedToBackend(true);
    FakeLightReading *fakeReading = new FakeLightReading();
    connect(fakeReading, &FakeLightReading::readingChanged, this, &SimulatedLight::lightReadingChanged);
    connect(&m_workerThread, &QThread::started, fakeReading, &FakeLightReading::startGeneratingData);
    connect(&m_workerThread, &QThread::finished, fakeReading, &FakeLightReading::stopGeneratingData);
    fakeReading->moveToThread(&m_workerThread);
}

void SimulatedLight::startListening()
{
    setIsListening(true);
    m_workerThread.start();
}

void SimulatedLight::stopListening()
{
    m_workerThread.exit();
    m_workerThread.wait(1000);
}
