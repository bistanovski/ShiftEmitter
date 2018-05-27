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
    setConnectedToBackend(m_proximitySensor.connectToBackend());
    qDebug() << "Connected to Backend:" << (isConnectedToBackend() ? "true" : "false");
}

void ProximityReceptor::startListening()
{
    setIsListening(m_proximitySensor.start());
    qDebug() << "Proximity Listening:" << (isListening() ? "true" : "false");
}

void ProximityReceptor::stopListening()
{
    m_proximitySensor.stop();
    setIsListening(false);
}

void ProximityReceptor::onReadingChanged()
{
    qDebug() << "Reading Changed";
    const auto proximityReading = m_proximitySensor.reading();
    emit somethingIsCloseChanged(proximityReading->close());
}
