#include "ReceptorFactory.hpp"

#include <memory>

#include <QDebug>
#include <QScopedPointer>

//#include "Receptor.hpp"
#include "ReceptorInfo.hpp"
//#include "ReceptorUtils.hpp"
//#include "TiltReceptor.hpp"
//#include "LightReceptor.hpp"
//#include "CompassReceptor.hpp"
//#include "ProximityReceptor.hpp"
//#include "OrientationReceptor.hpp"
//#include "AmbientLightReceptor.hpp"
//#include "MagnetometerReceptor.hpp"
//#include "AccelerometerReceptor.hpp"
//#include "DummyReceptor.hpp"

//Receptor *ReceptorFactory::createReceptor(const QByteArray &type, const QByteArray &identifier, QObject *targetParent)
//{
//    switch (sensorTypeToReceptorType(type)) {
//    case ReceptorType::TILT_RECEPTOR:
//        return std::move(new TiltReceptor(identifier, targetParent));
//        break;
//    case ReceptorType::LIGHT_RECEPTOR:
//        return std::move(new LightReceptor(identifier, targetParent));
//        break;
//    case ReceptorType::COMPASS_RECEPTOR:
//        return std::move(new CompassReceptor(identifier, targetParent));
//        break;
//    case ReceptorType::PROXIMITY_RECEPTOR:
//        return std::move(new ProximityReceptor(identifier, targetParent));
//        break;
//    case ReceptorType::ORIENTATION_RECEPTOR:
//        return std::move(new OrientationReceptor(identifier, targetParent));
//        break;
//    case ReceptorType::ACCELEROMETER_RECEPTOR:
//        return std::move(new AccelerometerReceptor(identifier, targetParent));
//        break;
//    case ReceptorType::AMBIENT_LIGHT_RECEPTOR:
//        return std::move(new AmbientLightReceptor(identifier, targetParent));
//        break;
//    case ReceptorType::MAGNETOMETER_RECEPTOR:
//        return std::move(new MagnetometerReceptor(identifier, targetParent));
//        break;
//    case ReceptorType::UNKNOWN_RECEPTOR:
//        return std::move(new DummyReceptor(identifier, targetParent));
//        break;
//    default:
//        return std::move(new DummyReceptor(identifier, targetParent));
//    }
//}

ReceptorInfo *ReceptorFactory::createReceptorInfo(const QByteArray &type, const QByteArray &identifier, QObject *targetParent)
{
    return std::move(new ReceptorInfo(type, identifier, targetParent));
}

//ReceptorType sensorTypeToReceptorType(const QByteArray &type)
//{
//    if(QTiltSensor::type == type)
//    {
//        return ReceptorType::TILT_RECEPTOR;
//    }
//    else if(QLightSensor::type == type)
//    {
//        return ReceptorType::LIGHT_RECEPTOR;
//    }
//    else if(QCompass::type == type)
//    {
//        return ReceptorType::COMPASS_RECEPTOR;
//    }
//    else if(QProximitySensor::type == type)
//    {
//        return ReceptorType::PROXIMITY_RECEPTOR;
//    }
//    else if(QOrientationSensor::type == type)
//    {
//        return ReceptorType::ORIENTATION_RECEPTOR;
//    }
//    else if(QAccelerometer::type == type)
//    {
//        return ReceptorType::ACCELEROMETER_RECEPTOR;
//    }
//    else if(QAmbientLightSensor::type == type)
//    {
//        return ReceptorType::AMBIENT_LIGHT_RECEPTOR;
//    }
//    else if(QMagnetometer::type == type)
//    {
//        return ReceptorType::MAGNETOMETER_RECEPTOR;
//    }
//    else
//    {
//        qDebug() << "ReceptorType: " << type << " is not implemented!!!";
//        return ReceptorType::UNKNOWN_RECEPTOR;
//    }
//}
