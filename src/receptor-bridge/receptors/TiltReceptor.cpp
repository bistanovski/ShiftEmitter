#include "TiltReceptor.hpp"

#include <QDebug>

TiltReceptor::TiltReceptor(const QByteArray &identifier, QObject *parent) : Receptor(parent)
{
    qDebug() << "TiltReceptor";
    m_tiltSensor.setIdentifier(identifier);
    emit identifierChanged();
}

TiltReceptor::~TiltReceptor()
{
    qDebug() << "~TiltReceptor";
}

QByteArray TiltReceptor::getType() const
{
    return m_tiltSensor.type;
}

QByteArray TiltReceptor::getIdentifier() const
{
    return m_tiltSensor.identifier();
}

QSensorReading *TiltReceptor::reading() const
{
    return m_tiltSensor.reading();
}
