#include "MagnetometerReceptor.hpp"

#include <QDebug>

MagnetometerReceptor::MagnetometerReceptor(const QByteArray &identifier, QObject *parent) : Receptor(parent)
{
    qDebug() << "MagnetometerReceptor";
    m_magnetoMeter.setIdentifier(identifier);
    emit identifierChanged();
}

MagnetometerReceptor::~MagnetometerReceptor()
{
    qDebug() << "~MagnetometerReceptor";
}

QByteArray MagnetometerReceptor::getType() const
{
    return m_magnetoMeter.type;
}

QByteArray MagnetometerReceptor::getIdentifier() const
{
    return m_magnetoMeter.identifier();
}

QSensorReading *MagnetometerReceptor::reading() const
{
    return m_magnetoMeter.reading();
}
