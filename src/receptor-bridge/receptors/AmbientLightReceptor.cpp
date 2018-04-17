#include "AmbientLightReceptor.hpp"

#include <QDebug>

AmbientLightReceptor::AmbientLightReceptor(QObject *parent) : Receptor(parent)
{
    qDebug() << "AmbientLightReceptor";
}

AmbientLightReceptor::~AmbientLightReceptor()
{
    qDebug() << "~AmbientLightReceptor" ;
}

void AmbientLightReceptor::connectReceptor()
{
    QObject::connect(&m_ambientLightSensor, SIGNAL(readingChanged()), this, SLOT(onReadingChanged()));
    const auto status = m_ambientLightSensor.connectToBackend();
    qDebug() << "Connected to Backend:" << (status ? "true" : "false");
}

void AmbientLightReceptor::startListening()
{
    const auto status = m_ambientLightSensor.start();
    qDebug() << "AmbientLight Listening:" << (status ? "true" : "false");
}

QSensorReading *AmbientLightReceptor::reading() const
{
    return m_ambientLightSensor.reading();
}

void AmbientLightReceptor::onReadingChanged()
{
    qDebug() << "Reading Changed";
    const auto ambientLightReading = m_ambientLightSensor.reading();
    emit readingChanged();
}
