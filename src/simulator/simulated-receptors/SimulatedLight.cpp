#include "SimulatedLight.hpp"

SimulatedLight::SimulatedLight(QObject *parent) : LightReceptor(parent)
{

}

SimulatedLight::~SimulatedLight()
{

}

void SimulatedLight::connectReceptor()
{
    setConnectedToBackend(true);
}

void SimulatedLight::startListening()
{
    setIsListening(true);
}

void SimulatedLight::onReadingChanged()
{

}
