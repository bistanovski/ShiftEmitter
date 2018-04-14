#include "DummyReceptor.hpp"

#include <QDebug>

DummyReceptor::DummyReceptor(const QByteArray &identifier, QObject *parent) : Receptor(parent),
    m_dummySensor(m_dummyType)
{
    qDebug() << "DummyReceptor";
    m_dummySensor.setIdentifier(identifier);
}

DummyReceptor::~DummyReceptor()
{
    qDebug() << "~DummyReceptor";
}

QByteArray DummyReceptor::getType() const
{
    return m_dummySensor.type();
}

QByteArray DummyReceptor::getIdeintifier() const
{
    return m_dummySensor.identifier();
}

QSensorReading *DummyReceptor::reading() const
{
    return m_dummySensor.reading();
}
