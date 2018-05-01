#include "AccelerometerReceptor.hpp"

#include <QDebug>

AccelerometerReceptor::AccelerometerReceptor(QObject *parent) : Receptor(parent)
{
    qDebug() << "AccelerometerReceptor";
}

AccelerometerReceptor::~AccelerometerReceptor()
{
    qDebug() << "~AccelerometerReceptor";
}

void AccelerometerReceptor::connectReceptor()
{
    QObject::connect(&m_accelerometer, SIGNAL(readingChanged()), this, SLOT(onReadingChanged()));
    setConnectedToBackend(m_accelerometer.connectToBackend());
    qDebug() << "Connected to Backend:" << (isConnectedToBackend() ? "true" : "false");
}

void AccelerometerReceptor::startListening()
{
    setIsListening(m_accelerometer.start());
    qDebug() << "Accelerometer Listening:" << (isListening() ? "true" : "false");
}

void AccelerometerReceptor::onReadingChanged()
{
    qDebug() << "Reading Changed";
    const auto accelerometerReading = m_accelerometer.reading();
    emit accelerationChanged(accelerometerReading->x(), accelerometerReading->y(), accelerometerReading->z());
}
