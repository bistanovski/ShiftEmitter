#ifndef SIMULATEDMAGNETOMETER_HPP
#define SIMULATEDMAGNETOMETER_HPP

#include <QThread>
#include "receptors/MagnetometerReceptor.hpp"

class SimulatedMagnetometer : public MagnetometerReceptor
{
public:
    explicit SimulatedMagnetometer(QObject *parent = nullptr);
    virtual ~SimulatedMagnetometer();

    virtual void connectReceptor() override;
    virtual void startListening() override;

private:
    QThread m_workerThread;
};

#endif // SIMULATEDMAGNETOMETER_HPP
