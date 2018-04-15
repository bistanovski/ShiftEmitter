#ifndef DUMMYRECEPTOR_HPP
#define DUMMYRECEPTOR_HPP

#include <QSensor>
#include "Receptor.hpp"

class DummyReceptor : public Receptor
{
    Q_OBJECT

public:
    explicit DummyReceptor(const QByteArray &identifier, QObject *parent = nullptr);
    virtual ~DummyReceptor();

    QByteArray getType() const override;
    QByteArray getIdentifier() const override;

    QSensorReading *reading() const override;

private:
    QSensor m_dummySensor;
    const QByteArray m_dummyType = "DUMMY";
};

#endif // DUMMYRECEPTOR_HPP
