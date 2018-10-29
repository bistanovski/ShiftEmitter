#ifndef SIMULATEDGYROSCOPE_HPP
#define SIMULATEDGYROSCOPE_HPP

#include <QThread>
#include "receptors/GyroscopeReceptor.hpp"

class SimulatedGyroscope : public GyroscopeReceptor
{
    Q_OBJECT

public:
    explicit SimulatedGyroscope(QObject *parent = nullptr);
    virtual ~SimulatedGyroscope();

    virtual void connectReceptor() override;
    virtual void startListening() override;
    virtual void stopListening() override;

private:
    QThread m_workerThread;
};

#endif // SIMULATEDGYROSCOPE_HPP
