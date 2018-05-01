#include "LightReceptor.hpp"

#include <QDebug>

LightReceptor::LightReceptor(QObject *parent) : Receptor(parent)
{
    qDebug() << "LightReceptor";
}

LightReceptor::~LightReceptor()
{
    qDebug() << "~LightReceptor";
}

void LightReceptor::connectReceptor()
{
    QObject::connect(&m_lightSensor, SIGNAL(readingChanged()), this, SLOT(onReadingChanged()));
    setConnectedToBackend(m_lightSensor.connectToBackend());
    qDebug() << "Connected to Backend:" << (isConnectedToBackend() ? "true" : "false");
}

void LightReceptor::startListening()
{
    setIsListening(m_lightSensor.start());
    qDebug() << "LightSensor Listening:" << (isListening() ? "true" : "false");
}

qreal LightReceptor::fieldOfView() const
{
    return m_lightSensor.fieldOfView();
}

void LightReceptor::setFieldOfView(qreal fieldOfView)
{
    m_lightSensor.setFieldOfView(fieldOfView);
}

void LightReceptor::onReadingChanged()
{
    qDebug() << "Reading Changed";
    const auto lightReading = m_lightSensor.reading();
    emit lightReadingChanged(lightReading->lux());
}
