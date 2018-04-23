#ifndef SIMULATEDLIGHT_HPP
#define SIMULATEDLIGHT_HPP

#include "receptors/LightReceptor.hpp"

class SimulatedLight : public LightReceptor
{
public:
    explicit SimulatedLight(QObject *parent = nullptr);
    virtual ~SimulatedLight();

    virtual void connectReceptor() override;
    virtual void startListening() override;

private slots:
    virtual void onReadingChanged() override;
};

#endif // SIMULATEDLIGHT_HPP
