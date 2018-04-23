#ifndef SIMULATEDTILT_HPP
#define SIMULATEDTILT_HPP

#include "receptors/TiltReceptor.hpp"

class SimulatedTilt : public TiltReceptor
{
public:
    explicit SimulatedTilt(QObject *parent = nullptr);
    virtual ~SimulatedTilt();

    virtual void connectReceptor() override;
    virtual void startListening() override;

private slots:
    virtual void onReadingChanged() override;
};

#endif // SIMULATEDTILT_HPP
