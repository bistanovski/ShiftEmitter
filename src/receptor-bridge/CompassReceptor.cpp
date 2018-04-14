#include "CompassReceptor.hpp"

#include <QDebug>

CompassReceptor::CompassReceptor(const QByteArray &identifier, QObject *parent) : Receptor(parent)
{
    qDebug() << "CompassReceptor";
    m_compass.setIdentifier(identifier);
}

CompassReceptor::~CompassReceptor()
{
    qDebug() << "~CompassReceptor";
}

QByteArray CompassReceptor::getType() const
{
    return m_compass.type;
}

QByteArray CompassReceptor::getIdeintifier() const
{
    return m_compass.identifier();
}

QSensorReading *CompassReceptor::reading() const
{
    return m_compass.reading();
}
