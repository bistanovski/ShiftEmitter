#ifndef SIMULATEDORIENTATION_H
#define SIMULATEDORIENTATION_H

#include <QThread>
#include "receptors/OrientationReceptor.hpp"

class SimulatedOrientation : public OrientationReceptor
{
public:
    explicit SimulatedOrientation(QObject *parent = nullptr);
    virtual ~SimulatedOrientation();

    virtual void connectReceptor() override;
    virtual void startListening() override;

private:
    QThread m_workerThread;
};

#endif // SIMULATEDORIENTATION_H
