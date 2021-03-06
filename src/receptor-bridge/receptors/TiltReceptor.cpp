#include "TiltReceptor.hpp"

#include <QDebug>

TiltReceptor::TiltReceptor(QObject *parent) : Receptor(parent)
{
    qDebug() << "TiltReceptor";
}

TiltReceptor::~TiltReceptor()
{
    qDebug() << "~TiltReceptor";
}

void TiltReceptor::connectReceptor()
{
    QObject::connect(&m_tiltSensor, SIGNAL(readingChanged()), this, SLOT(onReadingChanged()));
    setConnectedToBackend(m_tiltSensor.connectToBackend());
    qDebug() << "Connected to Backend:" << (isConnectedToBackend() ? "true" : "false");
}

void TiltReceptor::startListening()
{
    setIsListening(m_tiltSensor.start());
    qDebug() << "Tilt Listening:" << (isListening() ? "true" : "false");
}

void TiltReceptor::stopListening()
{
    m_tiltSensor.stop();
    setIsListening(false);
}

void TiltReceptor::onReadingChanged()
{
    qDebug() << "Reading Changed";
    const auto tiltReading = m_tiltSensor.reading();
    emit tiltDetected(tiltReading->xRotation(), tiltReading->yRotation());
}
