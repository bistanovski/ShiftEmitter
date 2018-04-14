#include "AccelerometerReceptor.hpp"

AccelerometerReceptor::AccelerometerReceptor(const QByteArray &identifier, QObject *parent) : Receptor(parent)
{
    m_accelerometer.setIdentifier(identifier);
}

AccelerometerReceptor::~AccelerometerReceptor()
{

}

QByteArray AccelerometerReceptor::getType() const
{
    return m_accelerometer.type;
}

QByteArray AccelerometerReceptor::getIdeintifier() const
{
    return m_accelerometer.identifier();
}

QSensorReading *AccelerometerReceptor::reading() const
{
    return m_accelerometer.reading();
}
