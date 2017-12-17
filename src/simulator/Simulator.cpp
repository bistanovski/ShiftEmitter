#include "Simulator.hpp"
#include <QDebug>

Simulator::Simulator(QObject *parent) : QObject(parent)
{

    qDebug() << "SIMULATOR HAS BEEN CREATED :)";
}
