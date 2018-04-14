#include "CompassReceptor.hpp"

#include <QDebug>

CompassReceptor::CompassReceptor(QObject *parent) : Receptor(parent)
{
    qDebug() << "CompassReceptor";
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
