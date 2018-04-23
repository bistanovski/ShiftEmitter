#include "SimulatedAccelerometer.hpp"

SimulatedAccelerometer::SimulatedAccelerometer(QObject *parent) : AccelerometerReceptor(parent)
{

}

SimulatedAccelerometer::~SimulatedAccelerometer()
{

}

void SimulatedAccelerometer::connectReceptor()
{
    setConnectedToBackend(true);
}

void SimulatedAccelerometer::startListening()
{
    setIsListening(true);
}

void SimulatedAccelerometer::onReadingChanged()
{

}
