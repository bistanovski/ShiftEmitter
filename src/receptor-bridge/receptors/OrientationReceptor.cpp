#include "OrientationReceptor.hpp"

#include <QDebug>

OrientationReceptor::OrientationReceptor(const QByteArray &identifier, QObject *parent) : Receptor(parent)
{
    qDebug() << "OrientationReceptor";
    m_orientationSensor.setIdentifier(identifier);
    emit identifierChanged();
}

OrientationReceptor::~OrientationReceptor()
{
    qDebug() << "~OrientationReceptor";
}

QByteArray OrientationReceptor::getType() const
{
    return m_orientationSensor.type;
}

QByteArray OrientationReceptor::getIdentifier() const
{
    return m_orientationSensor.identifier();
}

QSensorReading *OrientationReceptor::reading() const
{
    return m_orientationSensor.reading();
}
