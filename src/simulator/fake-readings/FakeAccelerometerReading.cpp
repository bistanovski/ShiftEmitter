#include "FakeAccelerometerReading.hpp"

#include <QTimer>
#include <QRandomGenerator>

FakeAccelerometerReading::FakeAccelerometerReading(QObject *parent) : QObject(parent)
{
    m_timer.reset(new QTimer(this));
    m_timer->setInterval(100);
    m_randomGenerator.reset(new QRandomGenerator());
}

FakeAccelerometerReading::~FakeAccelerometerReading()
{

}

void FakeAccelerometerReading::startGeneratingData()
{
    connect(m_timer.data(), &QTimer::timeout, this, &FakeAccelerometerReading::generateReadingsData);
    m_timer->start();
}

void FakeAccelerometerReading::stopGeneratingData()
{
    m_timer->stop();
    disconnect(m_timer.data(), &QTimer::timeout, this, &FakeAccelerometerReading::generateReadingsData);
}

void FakeAccelerometerReading::generateReadingsData()
{
    const auto x = m_randomGenerator->generateDouble();
    const auto y = m_randomGenerator->generateDouble();
    const auto z = m_randomGenerator->generateDouble();
    emit readingChanged(x, y, z);
}
