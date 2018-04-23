#ifndef SIMULATEDMAGNETOMETER_HPP
#define SIMULATEDMAGNETOMETER_HPP

#include "receptors/MagnetometerReceptor.hpp"

class SimulatedMagnetometer : public MagnetometerReceptor
{
public:
    explicit SimulatedMagnetometer(QObject *parent = nullptr);
    virtual ~SimulatedMagnetometer();

    virtual void connectReceptor() override;
    virtual void startListening() override;

private slots:
    virtual void onReadingChanged() override;
};

#endif // SIMULATEDMAGNETOMETER_HPP
