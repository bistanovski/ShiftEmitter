#include "FakeCompassReading.hpp"

#include <QTimer>
#include <QRandomGenerator>

FakeCompassReading::FakeCompassReading(QObject *parent) : QObject(parent)
{
    m_timer.reset(new QTimer(this));
    m_timer->setInterval(1000);
    m_randomGenerator.reset(new QRandomGenerator());
}

FakeCompassReading::~FakeCompassReading()
{

}

void FakeCompassReading::startGeneratingData()
{
    connect(m_timer.data(), &QTimer::timeout, this, &FakeCompassReading::generateReadingsData);
    m_timer->start();
}

void FakeCompassReading::stopGeneratingData()
{
    m_timer->stop();
    disconnect(m_timer.data(), &QTimer::timeout, this, &FakeCompassReading::generateReadingsData);
}

void FakeCompassReading::generateReadingsData()
{
    const auto azimuth = m_randomGenerator->generateDouble();
    const auto callibration = m_randomGenerator->bounded(1.0);
    emit readingChanged(azimuth, callibration);
}
