#include "MagnetometerReceptor.hpp"

#include <QDebug>

MagnetometerReceptor::MagnetometerReceptor(QObject *parent) : Receptor(parent)
{
    qDebug() << "MagnetometerReceptor";
}

MagnetometerReceptor::~MagnetometerReceptor()
{
    qDebug() << "~MagnetometerReceptor";
}

void MagnetometerReceptor::connectReceptor()
{
    QObject::connect(&m_magnetoMeter, SIGNAL(readingChanged()), this, SLOT(onReadingChanged()));
    setConnectedToBackend(m_magnetoMeter.connectToBackend());
    qDebug() << "Connected to Backend:" << (isConnectedToBackend() ? "true" : "false");
}

void MagnetometerReceptor::startListening()
{
    setIsListening(m_magnetoMeter.start());
    qDebug() << "Magnetometer Listening:" << (isListening() ? "true" : "false");
}

void MagnetometerReceptor::stopListening()
{
    m_magnetoMeter.stop();
    setIsListening(false);
}

void MagnetometerReceptor::onReadingChanged()
{
    qDebug() << "Reading Changed";
    const auto magnetoReading = m_magnetoMeter.reading();
    emit magneticFluxChanged(magnetoReading->x(), magnetoReading->y(), magnetoReading->z(), magnetoReading->calibrationLevel());
}
