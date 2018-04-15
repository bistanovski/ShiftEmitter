#include "LightReceptor.hpp"

#include <QDebug>

LightReceptor::LightReceptor(const QByteArray &identifier, QObject *parent) : Receptor(parent)
{
    qDebug() << "LightReceptor";
    m_lightSensor.setIdentifier(identifier);
    emit identifierChanged();
}

LightReceptor::~LightReceptor()
{
    qDebug() << "~LightReceptor";
}

QByteArray LightReceptor::getType() const
{
    return m_lightSensor.type;
}

QByteArray LightReceptor::getIdentifier() const
{
    return m_lightSensor.identifier();
}

QSensorReading *LightReceptor::reading() const
{
    return m_lightSensor.reading();
}

qreal LightReceptor::fieldOfView() const
{
    return m_lightSensor.fieldOfView();
}

void LightReceptor::setFieldOfView(qreal fieldOfView)
{
    m_lightSensor.setFieldOfView(fieldOfView);
}
