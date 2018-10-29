#include "RotationReceptor.hpp"

#include <QDebug>

RotationReceptor::RotationReceptor(QObject *parent) : Receptor(parent)
{
    qDebug() << "RotationReceptor";
}

RotationReceptor::~RotationReceptor()
{
    qDebug() << "~RotationReceptor";
}

void RotationReceptor::connectReceptor()
{
    QObject::connect(&m_rotationSensor, SIGNAL(readingChanged()), this, SLOT(onReadingChanged()));
    setConnectedToBackend(m_rotationSensor.connectToBackend());
    qDebug() << "Connected to Backend:" << (isConnectedToBackend() ? "true" : "false");
}

void RotationReceptor::startListening()
{
    setIsListening(m_rotationSensor.start());
    qDebug() << "RotationReceptor Listening:" << (isListening() ? "true" : "false");
}

void RotationReceptor::stopListening()
{
    m_rotationSensor.stop();
    setIsListening(false);
}

void RotationReceptor::onReadingChanged()
{
    qDebug() << "Reading Changed";
    const auto rotationReading = m_rotationSensor.reading();
    emit rotationChanged(rotationReading->x(), rotationReading->y(), rotationReading->z());
}
