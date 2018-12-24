#include "FakeLightReading.hpp"

#include <QTimer>
#include <QRandomGenerator>

FakeLightReading::FakeLightReading(QObject *parent) : QObject(parent)
{
    m_timer.reset(new QTimer(this));
    m_timer->setInterval(1000);
    m_randomGenerator.reset(new QRandomGenerator());
}

FakeLightReading::~FakeLightReading()
{

}

void FakeLightReading::startGeneratingData()
{
    connect(m_timer.data(), &QTimer::timeout, this, &FakeLightReading::generateReadingsData);
    m_timer->start();
}

void FakeLightReading::stopGeneratingData()
{
    m_timer->stop();
    disconnect(m_timer.data(), &QTimer::timeout, this, &FakeLightReading::generateReadingsData);
}

void FakeLightReading::generateReadingsData()
{
    const auto lux = m_randomGenerator->generateDouble();
    emit readingChanged(lux);
}
