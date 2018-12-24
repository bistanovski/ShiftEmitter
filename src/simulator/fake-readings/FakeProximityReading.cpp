#include "FakeProximityReading.hpp"

#include <QTimer>
#include <QRandomGenerator>

FakeProximityReading::FakeProximityReading(QObject *parent) : QObject(parent)
{
    m_timer.reset(new QTimer(this));
    m_timer->setInterval(1000);
    m_randomGenerator.reset(new QRandomGenerator());
}

FakeProximityReading::~FakeProximityReading()
{

}

void FakeProximityReading::startGeneratingData()
{
    connect(m_timer.data(), &QTimer::timeout, this, &FakeProximityReading::generateReadingsData);
    m_timer->start();
}

void FakeProximityReading::stopGeneratingData()
{
    m_timer->stop();
    disconnect(m_timer.data(), &QTimer::timeout, this, &FakeProximityReading::generateReadingsData);
}

void FakeProximityReading::generateReadingsData()
{
    const auto somethingClose = static_cast<int>(m_randomGenerator->bounded(0,2)) == 1 ? true : false;
    emit readingChanged(somethingClose);
}
