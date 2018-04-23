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
    const auto status = m_tiltSensor.connectToBackend();
    qDebug() << "Connected to Backend:" << (status ? "true" : "false");
}

void TiltReceptor::startListening()
{
    const auto status = m_tiltSensor.start();
    qDebug() << "Tilt Listening:" << (status ? "true" : "false");
}

void TiltReceptor::onReadingChanged()
{
    qDebug() << "Reading Changed";
    const auto tiltReading = m_tiltSensor.reading();
    emit readingChanged();
}
