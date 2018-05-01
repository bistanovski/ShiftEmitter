#include "CompassReceptor.hpp"

#include <QDebug>

CompassReceptor::CompassReceptor(QObject *parent) : Receptor(parent)
{
    qDebug() << "CompassReceptor";
}

CompassReceptor::~CompassReceptor()
{
    qDebug() << "~CompassReceptor";
}

void CompassReceptor::connectReceptor()
{
    QObject::connect(&m_compass, SIGNAL(readingChanged()), this, SLOT(onReadingChanged()));
    setConnectedToBackend(m_compass.connectToBackend());
    qDebug() << "Connected to Backend:" << (isConnectedToBackend() ? "true" : "false");
}

void CompassReceptor::startListening()
{
    setIsListening(m_compass.start());
    qDebug() << "Accelerometer Listening:" << (isListening() ? "true" : "false");
}

void CompassReceptor::onReadingChanged()
{
    qDebug() << "Reading Changed";
    const auto compassReading = m_compass.reading();
    emit compassReadingChanged(compassReading->azimuth(), compassReading->calibrationLevel());
}
