#include "FakeGyroscopeReading.hpp"

#include <QTimer>
#include <QRandomGenerator>

FakeGyroscopeReading::FakeGyroscopeReading(QObject *parent) : QObject(parent)
{
    m_timer.reset(new QTimer(this));
    m_timer->setInterval(100);
    m_randomGenerator.reset(new QRandomGenerator());
}

FakeGyroscopeReading::~FakeGyroscopeReading()
{

}

void FakeGyroscopeReading::startGeneratingData()
{
    connect(m_timer.data(), &QTimer::timeout, this, &FakeGyroscopeReading::generateReadingsData);
    m_timer->start();
}

void FakeGyroscopeReading::stopGeneratingData()
{
    m_timer->stop();
    disconnect(m_timer.data(), &QTimer::timeout, this, &FakeGyroscopeReading::generateReadingsData);
}

void FakeGyroscopeReading::generateReadingsData()
{
    const auto x = m_randomGenerator->generateDouble();
    const auto y = m_randomGenerator->generateDouble();
    const auto z = m_randomGenerator->generateDouble();
    emit readingChanged(x, y, z);
}
