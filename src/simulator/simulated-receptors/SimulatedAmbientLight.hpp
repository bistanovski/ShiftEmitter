#ifndef SIMULATEDAMBIENTLIGHT_HPP
#define SIMULATEDAMBIENTLIGHT_HPP

#include <QThread>
#include "receptors/AmbientLightReceptor.hpp"

class SimulatedAmbientLight : public AmbientLightReceptor
{
public:
    explicit SimulatedAmbientLight(QObject *parent = nullptr);
    virtual ~SimulatedAmbientLight();

    virtual void connectReceptor() override;
    virtual void startListening() override;

private:
    QThread m_workerThread;
};

#endif // SIMULATEDAMBIENTLIGHT_HPP
