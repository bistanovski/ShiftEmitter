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
    const auto status = m_magnetoMeter.connectToBackend();
    qDebug() << "Connected to Backend:" << (status ? "true" : "false");
}

void MagnetometerReceptor::startListening()
{
    const auto status = m_magnetoMeter.start();
    qDebug() << "Magnetometer Listening:" << (status ? "true" : "false");
}

QSensorReading *MagnetometerReceptor::reading() const
{
    return m_magnetoMeter.reading();
}

void MagnetometerReceptor::onReadingChanged()
{
    qDebug() << "Reading Changed";
    const auto magnetometerReading = m_magnetoMeter.reading();
    emit readingChanged();
}
