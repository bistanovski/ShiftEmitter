#include "FakeAmbientLightReading.hpp"

#include <QTimer>
#include <QRandomGenerator>

FakeAmbientLightReading::FakeAmbientLightReading(QObject *parent) : QObject(parent)
{
    m_timer.reset(new QTimer(this));
    m_timer->setInterval(500);
    m_randomGenerator.reset(new QRandomGenerator());
}

FakeAmbientLightReading::~FakeAmbientLightReading()
{

}

void FakeAmbientLightReading::startGeneratingData()
{
    connect(m_timer.data(), &QTimer::timeout, this, &FakeAmbientLightReading::generateReadingsData);
    m_timer->start();
}

void FakeAmbientLightReading::stopGeneratingData()
{
    m_timer->stop();
    disconnect(m_timer.data(), &QTimer::timeout, this, &FakeAmbientLightReading::generateReadingsData);
}

void FakeAmbientLightReading::generateReadingsData()
{
    const auto lightLevel = static_cast<int>(m_randomGenerator->bounded(1, 6));
    emit readingChanged(lightLevel);
}
