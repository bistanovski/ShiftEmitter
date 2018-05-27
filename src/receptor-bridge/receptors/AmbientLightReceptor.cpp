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
    setConnectedToBackend(m_ambientLightSensor.connectToBackend());
    qDebug() << "Connected to Backend:" << (isConnectedToBackend() ? "true" : "false");
}

void AmbientLightReceptor::startListening()
{
    setIsListening(m_ambientLightSensor.start());
    qDebug() << "AmbientLight Listening:" << (isListening() ? "true" : "false");
}

void AmbientLightReceptor::stopListening()
{
    m_ambientLightSensor.stop();
    setIsListening(false);
}

void AmbientLightReceptor::onReadingChanged()
{
    qDebug() << "Reading Changed";
    const auto ambientLightReading = m_ambientLightSensor.reading();
    emit lightLevelChanged(static_cast<int>(ambientLightReading->lightLevel()));
}
