#include "FakeOrientationReading.hpp"

#include <QTimer>
#include <QRandomGenerator>

FakeOrientationReading::FakeOrientationReading(QObject *parent) : QObject(parent)
{
    m_timer.reset(new QTimer(this));
    m_timer->setInterval(1000);
    m_randomGenerator.reset(new QRandomGenerator());
}

FakeOrientationReading::~FakeOrientationReading()
{

}

void FakeOrientationReading::startGeneratingData()
{
    connect(m_timer.data(), &QTimer::timeout, this, &FakeOrientationReading::generateReadingsData);
    m_timer->start();
}

void FakeOrientationReading::stopGeneratingData()
{
    m_timer->stop();
    disconnect(m_timer.data(), &QTimer::timeout, this, &FakeOrientationReading::generateReadingsData);
}

void FakeOrientationReading::generateReadingsData()
{
    const auto orientation = static_cast<int>(m_randomGenerator->bounded(1, 6));
    emit readingChanged(orientation);
}
