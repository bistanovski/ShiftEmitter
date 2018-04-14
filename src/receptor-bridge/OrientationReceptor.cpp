#include "OrientationReceptor.hpp"

#include <QDebug>

OrientationReceptor::OrientationReceptor(QObject *parent) : Receptor(parent)
{
    qDebug() << "OrientationReceptor";
}

OrientationReceptor::~OrientationReceptor()
{
    qDebug() << "~OrientationReceptor";
}

QByteArray OrientationReceptor::getType() const
{
    return m_orientationSensor.type;
}

QByteArray OrientationReceptor::getIdeintifier() const
{
    return m_orientationSensor.identifier();
}

QSensorReading *OrientationReceptor::reading() const
{
    return m_orientationSensor.reading();
}
