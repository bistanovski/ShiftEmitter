#include "FakeMagnetometerReading.hpp"

#include <QTimer>
#include <QRandomGenerator>

FakeMagnetometerReading::FakeMagnetometerReading(QObject *parent) : QObject(parent)
{
    m_timer.reset(new QTimer(this));
    m_timer->setInterval(1000);
    m_randomGenerator.reset(new QRandomGenerator());
}

FakeMagnetometerReading::~FakeMagnetometerReading()
{

}

void FakeMagnetometerReading::startGeneratingData()
{
    connect(m_timer.data(), &QTimer::timeout, this, &FakeMagnetometerReading::generateReadingsData);
    m_timer->start();
}

void FakeMagnetometerReading::stopGeneratingData()
{
    m_timer->stop();
    disconnect(m_timer.data(), &QTimer::timeout, this, &FakeMagnetometerReading::generateReadingsData);
}

void FakeMagnetometerReading::generateReadingsData()
{
    const auto xFlux = m_randomGenerator->generateDouble();
    const auto yFlux = m_randomGenerator->generateDouble();
    const auto zFlux = m_randomGenerator->generateDouble();
    const auto callibrationLevel = m_randomGenerator->generateDouble();
    emit readingChanged(xFlux, yFlux, zFlux, callibrationLevel);
}
