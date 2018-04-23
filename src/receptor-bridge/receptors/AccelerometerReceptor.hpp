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

    virtual void connectReceptor() override;
    virtual void startListening() override;

private slots:
    virtual void onReadingChanged() override;

private:
    QAccelerometer m_accelerometer;
};

#endif // ACCELEROMETERRECEPTOR_HPP
