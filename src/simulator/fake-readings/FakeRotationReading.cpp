#include "FakeRotationReading.hpp"

#include <QTimer>
#include <QRandomGenerator>

FakeRotationReading::FakeRotationReading(QObject *parent) : QObject(parent)
{
    m_timer.reset(new QTimer(this));
    m_timer->setInterval(1000);
    m_randomGenerator.reset(new QRandomGenerator());
}

FakeRotationReading::~FakeRotationReading()
{

}

void FakeRotationReading::startGeneratingData()
{
    connect(m_timer.data(), &QTimer::timeout, this, &FakeRotationReading::generateReadingsData);
    m_timer->start();
}

void FakeRotationReading::stopGeneratingData()
{
    m_timer->stop();
    disconnect(m_timer.data(), &QTimer::timeout, this, &FakeRotationReading::generateReadingsData);
}

void FakeRotationReading::generateReadingsData()
{
    const auto x = m_randomGenerator->generateDouble();
    const auto y = m_randomGenerator->generateDouble();
    const auto z = m_randomGenerator->generateDouble();
    emit readingChanged(x, y, z);
}
