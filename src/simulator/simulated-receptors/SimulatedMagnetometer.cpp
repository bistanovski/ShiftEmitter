#include "SimulatedMagnetometer.hpp"

SimulatedMagnetometer::SimulatedMagnetometer(QObject *parent) : MagnetometerReceptor(parent)
{

}

SimulatedMagnetometer::~SimulatedMagnetometer()
{

}

void SimulatedMagnetometer::connectReceptor()
{
    setConnectedToBackend(true);
}

void SimulatedMagnetometer::startListening()
{
    setIsListening(true);
}

void SimulatedMagnetometer::onReadingChanged()
{

}
