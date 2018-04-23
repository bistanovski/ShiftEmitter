#ifndef SIMULATEDORIENTATION_H
#define SIMULATEDORIENTATION_H

#include "receptors/OrientationReceptor.hpp"

class SimulatedOrientation : public OrientationReceptor
{
public:
    explicit SimulatedOrientation(QObject *parent = nullptr);
    virtual ~SimulatedOrientation();

    virtual void connectReceptor() override;
    virtual void startListening() override;

private slots:
    virtual void onReadingChanged() override;
};

#endif // SIMULATEDORIENTATION_H
