#ifndef SIMULATEDCOMPASS_HPP
#define SIMULATEDCOMPASS_HPP

#include <QThread>
#include "receptors/CompassReceptor.hpp"

class SimulatedCompass : public CompassReceptor
{
public:
    explicit SimulatedCompass(QObject *parent = nullptr);
    virtual ~SimulatedCompass();

    virtual void connectReceptor() override;
    virtual void startListening() override;

private:
    QThread m_workerThread;
};

#endif // SIMULATEDCOMPASS_HPP
