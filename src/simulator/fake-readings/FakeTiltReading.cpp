#include "FakeTiltReading.hpp"

#include <QTimer>
#include <QRandomGenerator>

FakeTiltReading::FakeTiltReading(QObject *parent) : QObject(parent)
{
    m_timer.reset(new QTimer(this));
    m_timer->setInterval(1000);
    m_randomGenerator.reset(new QRandomGenerator());
}

FakeTiltReading::~FakeTiltReading()
{

}

void FakeTiltReading::startGeneratingData()
{
    connect(m_timer.data(), &QTimer::timeout, this, &FakeTiltReading::generateReadingsData);
    m_timer->start();
}

void FakeTiltReading::stopGeneratingData()
{
    m_timer->stop();
    disconnect(m_timer.data(), &QTimer::timeout, this, &FakeTiltReading::generateReadingsData);
}

void FakeTiltReading::generateReadingsData()
{
    const auto xRotation = m_randomGenerator->generateDouble();
    const auto yRotation = m_randomGenerator->generateDouble();
    emit readingChanged(xRotation, yRotation);
}
