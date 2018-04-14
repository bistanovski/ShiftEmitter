#include "TiltReceptor.hpp"

TiltReceptor::TiltReceptor(const QByteArray &identifier, QObject *parent) : Receptor(parent)
{
    m_tiltSensor.setIdentifier(identifier);
}

TiltReceptor::~TiltReceptor()
{

}

QByteArray TiltReceptor::getType() const
{
    return m_tiltSensor.type;
}

QByteArray TiltReceptor::getIdeintifier() const
{
    return m_tiltSensor.identifier();
}

QSensorReading *TiltReceptor::reading() const
{
    return m_tiltSensor.reading();
}
