#ifndef SIMULATEDPROXIMITY_HPP
#define SIMULATEDPROXIMITY_HPP

#include "receptors/ProximityReceptor.hpp"

class SimulatedProximity : public ProximityReceptor
{
public:
    explicit SimulatedProximity(QObject *parent = nullptr);
    virtual ~SimulatedProximity();

    virtual void connectReceptor() override;
    virtual void startListening() override;

private slots:
    virtual void onReadingChanged() override;
};

#endif // SIMULATEDPROXIMITY_HPP
