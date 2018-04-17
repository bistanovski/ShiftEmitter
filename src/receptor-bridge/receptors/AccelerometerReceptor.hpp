#ifndef ACCELEROMETERRECEPTOR_HPP
#define ACCELEROMETERRECEPTOR_HPP

#include <QAccelerometer>
#include "Receptor.hpp"

class AccelerometerReceptor : public Receptor
{
    Q_OBJECT

public:
    explicit AccelerometerReceptor(QObject *parent = nullptr);
    virtual ~AccelerometerReceptor();

    void connectReceptor() override;
    void startListening() override;

    QSensorReading *reading() const override;

private slots:
    void onReadingChanged();

private:
    QAccelerometer m_accelerometer;
};

#endif // ACCELEROMETERRECEPTOR_HPP
