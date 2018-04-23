#ifndef SIMULATEDCOMPASS_HPP
#define SIMULATEDCOMPASS_HPP

#include "receptors/CompassReceptor.hpp"

class SimulatedCompass : public CompassReceptor
{
public:
    explicit SimulatedCompass(QObject *parent = nullptr);
    virtual ~SimulatedCompass();

    virtual void connectReceptor() override;
    virtual void startListening() override;

private slots:
    virtual void onReadingChanged() override;
};

#endif // SIMULATEDCOMPASS_HPP
