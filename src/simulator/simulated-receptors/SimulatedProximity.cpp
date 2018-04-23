#include "SimulatedProximity.hpp"

SimulatedProximity::SimulatedProximity(QObject *parent) : ProximityReceptor(parent)
{

}

SimulatedProximity::~SimulatedProximity()
{

}

void SimulatedProximity::connectReceptor()
{
    setConnectedToBackend(true);
}

void SimulatedProximity::startListening()
{
    setIsListening(true);
}

void SimulatedProximity::onReadingChanged()
{

}
