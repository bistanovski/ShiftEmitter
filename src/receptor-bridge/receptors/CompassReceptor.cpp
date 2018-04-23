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
    const auto status = m_compass.connectToBackend();
    qDebug() << "Connected to Backend:" << (status ? "true" : "false");
}

void CompassReceptor::startListening()
{
    const auto status = m_compass.start();
    qDebug() << "Accelerometer Listening:" << (status ? "true" : "false");
}

void CompassReceptor::onReadingChanged()
{
    qDebug() << "Reading Changed";
    const auto compassReading = m_compass.reading();
    emit readingChanged();
}
