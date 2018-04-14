#include "ProximityReceptor.hpp"

ProximityReceptor::ProximityReceptor(const QByteArray &identifier, QObject *parent) : Receptor(parent)
{
    m_proximitySensor.setIdentifier(identifier);
}

ProximityReceptor::~ProximityReceptor()
{

}

QByteArray ProximityReceptor::getType() const
{
    return m_proximitySensor.type;
}

QByteArray ProximityReceptor::getIdeintifier() const
{
    return m_proximitySensor.identifier();
}

QSensorReading *ProximityReceptor::reading() const
{
    return m_proximitySensor.reading();
}
