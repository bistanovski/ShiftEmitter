#include "SimulatedTilt.hpp"

SimulatedTilt::SimulatedTilt(QObject *parent) : TiltReceptor(parent)
{

}

SimulatedTilt::~SimulatedTilt()
{

}

void SimulatedTilt::connectReceptor()
{
    setConnectedToBackend(true);
}

void SimulatedTilt::startListening()
{
    setIsListening(true);
}

void SimulatedTilt::onReadingChanged()
{

}
