#include "SimulatedAmbientLight.hpp"

SimulatedAmbientLight::SimulatedAmbientLight(QObject *parent) : AmbientLightReceptor(parent)
{

}

SimulatedAmbientLight::~SimulatedAmbientLight()
{

}

void SimulatedAmbientLight::connectReceptor()
{
    setConnectedToBackend(true);
}

void SimulatedAmbientLight::startListening()
{
    setIsListening(true);
}

void SimulatedAmbientLight::onReadingChanged()
{

}
