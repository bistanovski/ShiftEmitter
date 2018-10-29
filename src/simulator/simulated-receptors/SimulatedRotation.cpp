#include "SimulatedRotation.hpp"

#include <QDebug>
#include "fake-readings/FakeRotationReading.hpp"

SimulatedRotation::SimulatedRotation(QObject *parent) : RotationReceptor(parent)
{
    setConnectedToBackend(true);
    setIsListening(true);
}

SimulatedRotation::~SimulatedRotation()
{
    m_workerThread.exit();
    m_workerThread.wait(1000);
}

void SimulatedRotation::connectReceptor()
{
    setConnectedToBackend(true);
    FakeRotationReading *fakeReading = new FakeRotationReading();
    connect(fakeReading, &FakeRotationReading::readingChanged, this, &SimulatedRotation::rotationChanged);
    connect(&m_workerThread, &QThread::started, fakeReading, &FakeRotationReading::startGeneratingData);
    connect(&m_workerThread, &QThread::finished, fakeReading, &FakeRotationReading::stopGeneratingData);
    fakeReading->moveToThread(&m_workerThread);
}

void SimulatedRotation::startListening()
{
    setIsListening(true);
    m_workerThread.start();
}

void SimulatedRotation::stopListening()
{
    m_workerThread.exit();
    m_workerThread.wait(1000);
}
