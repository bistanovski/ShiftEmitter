#include "SimulatedAmbientLight.hpp"

#include <QDebug>
#include "fake-readings/FakeAmbientLightReading.hpp"

SimulatedAmbientLight::SimulatedAmbientLight(QObject *parent) : AmbientLightReceptor(parent)
{
    setConnectedToBackend(true);
    setIsListening(true);
}

SimulatedAmbientLight::~SimulatedAmbientLight()
{
    m_workerThread.exit();
    m_workerThread.wait(1000);
}

void SimulatedAmbientLight::connectReceptor()
{
    setConnectedToBackend(true);
    FakeAmbientLightReading *fakeReading = new FakeAmbientLightReading();
    connect(fakeReading, &FakeAmbientLightReading::readingChanged, this, &SimulatedAmbientLight::lightLevelChanged);
    connect(&m_workerThread, &QThread::started, fakeReading, &FakeAmbientLightReading::startGeneratingData);
    connect(&m_workerThread, &QThread::finished, fakeReading, &FakeAmbientLightReading::stopGeneratingData);
    fakeReading->moveToThread(&m_workerThread);
}

void SimulatedAmbientLight::startListening()
{
    setIsListening(true);
    m_workerThread.start();
}
