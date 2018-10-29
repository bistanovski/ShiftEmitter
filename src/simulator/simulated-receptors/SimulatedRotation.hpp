#ifndef SIMULATEDROTATION_HPP
#define SIMULATEDROTATION_HPP

#include <QThread>
#include "receptors/RotationReceptor.hpp"

class SimulatedRotation : public RotationReceptor
{
    Q_OBJECT

public:
    explicit SimulatedRotation(QObject *parent = nullptr);
    virtual ~SimulatedRotation();

    virtual void connectReceptor() override;
    virtual void startListening() override;
    virtual void stopListening() override;

private:
    QThread m_workerThread;
};

#endif // SIMULATEDROTATION_HPP
