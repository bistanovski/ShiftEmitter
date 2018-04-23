#include "SimulatedOrientation.hpp"

SimulatedOrientation::SimulatedOrientation(QObject *parent) : OrientationReceptor(parent)
{

}

SimulatedOrientation::~SimulatedOrientation()
{

}

void SimulatedOrientation::connectReceptor()
{
    setConnectedToBackend(true);
}

void SimulatedOrientation::startListening()
{
    setIsListening(true);
}

void SimulatedOrientation::onReadingChanged()
{

}
