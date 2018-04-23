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
    const auto status = m_accelerometer.connectToBackend();
    qDebug() << "Connected to Backend:" << (status ? "true" : "false");
}

void AccelerometerReceptor::startListening()
{
    const auto status = m_accelerometer.start();
    qDebug() << "Accelerometer Listening:" << (status ? "true" : "false");
}

void AccelerometerReceptor::onReadingChanged()
{
    qDebug() << "Reading Changed";
    const auto accelerometerReading = m_accelerometer.reading();
    emit readingChanged();
}
