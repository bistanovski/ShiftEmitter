#include "GyroscopeReceptor.hpp"

#include <QDebug>

GyroscopeReceptor::GyroscopeReceptor(QObject *parent) : Receptor(parent)
{
    qDebug() << "GyroscopeReceptor";
}

GyroscopeReceptor::~GyroscopeReceptor()
{
    qDebug() << "~GyroscopeReceptor";
}

void GyroscopeReceptor::connectReceptor()
{
    QObject::connect(&m_gyroscope, SIGNAL(readingChanged()), this, SLOT(onReadingChanged()));
    setConnectedToBackend(m_gyroscope.connectToBackend());
    qDebug() << "Connected to Backend:" << (isConnectedToBackend() ? "true" : "false");
}

void GyroscopeReceptor::startListening()
{
    setIsListening(m_gyroscope.start());
    qDebug() << "GyroscopeReceptor Listening:" << (isListening() ? "true" : "false");
}

void GyroscopeReceptor::stopListening()
{
    m_gyroscope.stop();
    setIsListening(false);
}

void GyroscopeReceptor::onReadingChanged()
{
    qDebug() << "Reading Changed";
    const auto gyroscopeReading = m_gyroscope.reading();
    emit gyroscopeChanged(gyroscopeReading->x(), gyroscopeReading->y(), gyroscopeReading->z());
}
