#ifndef SIMULATEDLIGHT_HPP
#define SIMULATEDLIGHT_HPP

#include <QThread>
#include "receptors/LightReceptor.hpp"

class SimulatedLight : public LightReceptor
{
public:
    explicit SimulatedLight(QObject *parent = nullptr);
    virtual ~SimulatedLight();

    virtual void connectReceptor() override;
    virtual void startListening() override;
    virtual void stopListening() override;

private:
    QThread m_workerThread;
};

#endif // SIMULATEDLIGHT_HPP
