#include "ReceptorNetwork.hpp"

#include <QDebug>
#include <QSensor>

#include "Receptor.hpp"
#include "ReceptorFactory.hpp"

ReceptorNetwork::ReceptorNetwork(QObject *parent) : QObject(parent)
{

}

ReceptorNetwork::~ReceptorNetwork()
{

}

std::vector<ReceptorPtr> ReceptorNetwork::fetchAllReceptors()
{
    std::vector<ReceptorPtr> result;
    auto sensorTypes = QSensor::sensorTypes();

    qDebug() << "Found N Receptors (ReceptorNetwork): " << sensorTypes.length();
    for (const auto &type : qAsConst(sensorTypes)) {
        qDebug() << "Found type" << type;
        for (const auto &identifier : QSensor::sensorsForType(type)) {
            qDebug() << "Found identifier" << identifier;
            result.push_back(ReceptorFactory::createReceptor(type));
        }
    }

    return result;
}
