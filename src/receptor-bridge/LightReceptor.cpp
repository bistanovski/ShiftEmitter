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

QByteArray LightReceptor::getType() const
{
    return m_lightSensor.type;
}

QByteArray LightReceptor::getIdeintifier() const
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
