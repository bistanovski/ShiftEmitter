#ifndef ACCELEROMETERRECEPTOR_HPP
#define ACCELEROMETERRECEPTOR_HPP

#include <QAccelerometer>
#include "Receptor.hpp"

class AccelerometerReceptor : public Receptor
{
    Q_OBJECT

public:
    explicit AccelerometerReceptor(const QByteArray &identifier, QObject *parent = nullptr);
    virtual ~AccelerometerReceptor();

    QByteArray getType() const override;
    QByteArray getIdentifier() const override;

    QSensorReading *reading() const override;

private:
    QAccelerometer m_accelerometer;
};

#endif // ACCELEROMETERRECEPTOR_HPP
