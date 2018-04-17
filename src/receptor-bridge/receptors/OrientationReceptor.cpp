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
    const auto status = m_orientationSensor.connectToBackend();
    qDebug() << "Connected to Backend:" << (status ? "true" : "false");
}

void OrientationReceptor::startListening()
{
    const auto status = m_orientationSensor.start();
    qDebug() << "Orientation Listening:" << (status ? "true" : "false");
}

QSensorReading *OrientationReceptor::reading() const
{
    return m_orientationSensor.reading();
}

void OrientationReceptor::onReadingChanged()
{
    qDebug() << "Reading Changed";
    const auto orientationReading = m_orientationSensor.reading();
    emit readingChanged();
}
