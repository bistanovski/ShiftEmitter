#ifndef SIMULATEDACCELEROMETER_HPP
#define SIMULATEDACCELEROMETER_HPP

#include "receptors/AccelerometerReceptor.hpp"

class SimulatedAccelerometer : public AccelerometerReceptor
{
public:
    explicit SimulatedAccelerometer(QObject *parent = nullptr);
    virtual ~SimulatedAccelerometer();

    virtual void connectReceptor() override;
    virtual void startListening() override;

private slots:
    virtual void onReadingChanged() override;
};

#endif // SIMULATEDACCELEROMETER_HPP
