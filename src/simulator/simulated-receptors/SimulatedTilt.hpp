#ifndef SIMULATEDTILT_HPP
#define SIMULATEDTILT_HPP

#include <QThread>
#include "receptors/TiltReceptor.hpp"

class SimulatedTilt : public TiltReceptor
{
public:
    explicit SimulatedTilt(QObject *parent = nullptr);
    virtual ~SimulatedTilt();

    virtual void connectReceptor() override;
    virtual void startListening() override;
    virtual void stopListening() override;

private:
    QThread m_workerThread;
};

#endif // SIMULATEDTILT_HPP
