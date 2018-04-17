#include "ProximityReceptor.hpp"

#include <QDebug>

ProximityReceptor::ProximityReceptor(QObject *parent) : Receptor(parent)
{
    qDebug() << "ProximityReceptor";
}

ProximityReceptor::~ProximityReceptor()
{
    qDebug() << "~ProximityReceptor";
}

void ProximityReceptor::connectReceptor()
{
    QObject::connect(&m_proximitySensor, SIGNAL(readingChanged()), this, SLOT(onReadingChanged()));
    const auto status = m_proximitySensor.connectToBackend();
    qDebug() << "Connected to Backend:" << (status ? "true" : "false");
}

void ProximityReceptor::startListening()
{
    const auto status = m_proximitySensor.start();
    qDebug() << "Proximity Listening:" << (status ? "true" : "false");
}

QSensorReading *ProximityReceptor::reading() const
{
    return m_proximitySensor.reading();
}

void ProximityReceptor::onReadingChanged()
{
    qDebug() << "Reading Changed";
    const auto proximityReading = m_proximitySensor.reading();
    emit readingChanged();
}
