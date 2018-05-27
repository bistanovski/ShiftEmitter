#include "OrientationReceptor.hpp"

#include <QDebug>

OrientationReceptor::OrientationReceptor(QObject *parent) : Receptor(parent)
{
    qDebug() << "OrientationReceptor";
}

OrientationReceptor::~OrientationReceptor()
{
    qDebug() << "~OrientationReceptor";
}

void OrientationReceptor::connectReceptor()
{
    QObject::connect(&m_orientationSensor, SIGNAL(readingChanged()), this, SLOT(onReadingChanged()));
    setConnectedToBackend(m_orientationSensor.connectToBackend());
    qDebug() << "Connected to Backend:" << (isConnectedToBackend() ? "true" : "false");
}

void OrientationReceptor::startListening()
{
    setIsListening(m_orientationSensor.start());
    qDebug() << "Orientation Listening:" << (isListening() ? "true" : "false");
}

void OrientationReceptor::stopListening()
{
    m_orientationSensor.stop();
    setIsListening(false);
}

void OrientationReceptor::onReadingChanged()
{
    qDebug() << "Reading Changed";
    const auto orientationReading = m_orientationSensor.reading();
    emit orientationChanged(static_cast<int>(orientationReading->orientation()));
}
