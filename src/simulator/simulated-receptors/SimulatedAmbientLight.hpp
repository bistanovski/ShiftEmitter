#ifndef SIMULATEDAMBIENTLIGHT_HPP
#define SIMULATEDAMBIENTLIGHT_HPP

#include "receptors/AmbientLightReceptor.hpp"

class SimulatedAmbientLight : public AmbientLightReceptor
{
public:
    explicit SimulatedAmbientLight(QObject *parent = nullptr);
    virtual ~SimulatedAmbientLight();

    virtual void connectReceptor() override;
    virtual void startListening() override;

private slots:
    virtual void onReadingChanged() override;
};

#endif // SIMULATEDAMBIENTLIGHT_HPP
