#include "AccelerometerReceptor.hpp"

#include <QDebug>

AccelerometerReceptor::AccelerometerReceptor(const QByteArray &identifier, QObject *parent) : Receptor(parent)
{
    qDebug() << "AccelerometerReceptor";
    m_accelerometer.setIdentifier(identifier);
    emit identifierChanged();
}

AccelerometerReceptor::~AccelerometerReceptor()
{
    qDebug() << "~AccelerometerReceptor";
}

QByteArray AccelerometerReceptor::getType() const
{
    return m_accelerometer.type;
}

QByteArray AccelerometerReceptor::getIdentifier() const
{
    return m_accelerometer.identifier();
}

QSensorReading *AccelerometerReceptor::reading() const
{
    return m_accelerometer.reading();
}
