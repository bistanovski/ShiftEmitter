#include "SimulatedCompass.hpp"

SimulatedCompass::SimulatedCompass(QObject *parent) : CompassReceptor(parent)
{

}

SimulatedCompass::~SimulatedCompass()
{

}

void SimulatedCompass::connectReceptor()
{
    setConnectedToBackend(true);
}

void SimulatedCompass::startListening()
{
    setIsListening(true);
}

void SimulatedCompass::onReadingChanged()
{

}
