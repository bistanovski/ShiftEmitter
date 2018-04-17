#include "DummyReceptor.hpp"

#include <QDebug>

DummyReceptor::DummyReceptor(QObject *parent) : Receptor(parent),
    m_dummySensor(m_dummyType)
{
    qDebug() << "DummyReceptor";
}

DummyReceptor::~DummyReceptor()
{
    qDebug() << "~DummyReceptor";
}

void DummyReceptor::connectReceptor()
{
    QObject::connect(&m_dummySensor, SIGNAL(readingChanged()), this, SLOT(onReadingChanged()));
    const auto status = m_dummySensor.connectToBackend();
    qDebug() << "Connected to Backend:" << (status ? "true" : "false");
}

void DummyReceptor::startListening()
{
    const auto status = m_dummySensor.start();
    qDebug() << "Accelerometer Listening:" << (status ? "true" : "false");
}

QSensorReading *DummyReceptor::reading() const
{
    return m_dummySensor.reading();
}

void DummyReceptor::onReadingChanged()
{
    qDebug() << "Reading Changed";
    const auto accelerometerReading = m_dummySensor.reading();
    emit readingChanged();
}
