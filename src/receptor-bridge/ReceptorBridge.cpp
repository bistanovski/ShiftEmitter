#include "ReceptorBridge.hpp"

#include <QDebug>
#include <QSensor>

#include "ReceptorInfo.hpp"
#include "ReceptorFactory.hpp"

ReceptorBridge::ReceptorBridge(QObject *parent) : QObject(parent)
{

}

ReceptorBridge::~ReceptorBridge()
{

}

QObjectList ReceptorBridge::fetchReceptorInfos(QObject *targetParent)
{
    QObjectList result;
    auto sensorTypes = QSensor::sensorTypes();

    qDebug() << "Found N Receptors (ReceptorNetwork): " << sensorTypes.length();
    for (const auto &type : qAsConst(sensorTypes)) {
        qDebug() << "Found type" << type;
        for (const auto &identifier : QSensor::sensorsForType(type)) {
            qDebug() << "Found identifier" << identifier;
            result.push_back(ReceptorFactory::createReceptorInfo(type, identifier, targetParent));
        }
    }

    return result;
}
