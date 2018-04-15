#include "ProximityReceptor.hpp"

#include <QDebug>

ProximityReceptor::ProximityReceptor(const QByteArray &identifier, QObject *parent) : Receptor(parent)
{
    qDebug() << "ProximityReceptor";
    m_proximitySensor.setIdentifier(identifier);
    emit identifierChanged();
}

ProximityReceptor::~ProximityReceptor()
{
    qDebug() << "~ProximityReceptor";
}

QByteArray ProximityReceptor::getType() const
{
    return m_proximitySensor.type;
}

QByteArray ProximityReceptor::getIdentifier() const
{
    return m_proximitySensor.identifier();
}

QSensorReading *ProximityReceptor::reading() const
{
    return m_proximitySensor.reading();
}
