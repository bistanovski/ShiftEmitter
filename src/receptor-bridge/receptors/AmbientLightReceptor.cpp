#include "AmbientLightReceptor.hpp"

#include <QDebug>

AmbientLightReceptor::AmbientLightReceptor(const QByteArray &identifier, QObject *parent) : Receptor(parent)
{
    qDebug() << "AmbientLightReceptor";
    emit identifierChanged();
    m_ambientLightSensor.setIdentifier(identifier);
}

AmbientLightReceptor::~AmbientLightReceptor()
{
    qDebug() << "~AmbientLightReceptor" ;
}

QByteArray AmbientLightReceptor::getType() const
{
    return m_ambientLightSensor.type;
}

QByteArray AmbientLightReceptor::getIdentifier() const
{
    return m_ambientLightSensor.identifier();
}

QSensorReading *AmbientLightReceptor::reading() const
{
    return m_ambientLightSensor.reading();
}
