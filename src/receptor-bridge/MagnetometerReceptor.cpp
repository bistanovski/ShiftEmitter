#include "MagnetometerReceptor.hpp"

MagnetometerReceptor::MagnetometerReceptor(const QByteArray &identifier, QObject *parent) : Receptor(parent)
{
    m_magnetoMeter.setIdentifier(identifier);
}

MagnetometerReceptor::~MagnetometerReceptor()
{

}

QByteArray MagnetometerReceptor::getType() const
{
    return m_magnetoMeter.type;
}

QByteArray MagnetometerReceptor::getIdeintifier() const
{
    return m_magnetoMeter.identifier();
}

QSensorReading *MagnetometerReceptor::reading() const
{
    return m_magnetoMeter.reading();
}
