#ifndef SIMULATEDACCELEROMETER_HPP
#define SIMULATEDACCELEROMETER_HPP

#include <QThread>
#include "receptors/AccelerometerReceptor.hpp"

class SimulatedAccelerometer : public AccelerometerReceptor
{
    Q_OBJECT

public:
    explicit SimulatedAccelerometer(QObject *parent = nullptr);
    virtual ~SimulatedAccelerometer();

    virtual void connectReceptor() override;
    virtual void startListening() override;
    virtual void stopListening() override;

private:
    QThread m_workerThread;
};

#endif // SIMULATEDACCELEROMETER_HPP
