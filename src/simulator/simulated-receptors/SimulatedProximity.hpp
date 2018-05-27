#ifndef SIMULATEDPROXIMITY_HPP
#define SIMULATEDPROXIMITY_HPP

#include <QThread>
#include "receptors/ProximityReceptor.hpp"

class SimulatedProximity : public ProximityReceptor
{
public:
    explicit SimulatedProximity(QObject *parent = nullptr);
    virtual ~SimulatedProximity();

    virtual void connectReceptor() override;
    virtual void startListening() override;
    virtual void stopListening() override;

private:
    QThread m_workerThread;
};

#endif // SIMULATEDPROXIMITY_HPP
