#include "ReceptorFactory.hpp"

#include <QDebug>

#include "Receptor.hpp"
#include "TiltReceptor.hpp"
#include "LightReceptor.hpp"
#include "CompassReceptor.hpp"
#include "ProximityReceptor.hpp"
#include "OrientationReceptor.hpp"
#include "AmbientLightReceptor.hpp"
#include "MagnetometerReceptor.hpp"
#include "AccelerometerReceptor.hpp"
#include "DummyReceptor.hpp"

std::unique_ptr<Receptor> ReceptorFactory::createReceptor(const QByteArray &type, const QByteArray &identifier)
{
    switch (sensorTypeToReceptorType(type)) {
    case ReceptorType::TILT_RECEPTOR:
        return std::move(std::make_unique<TiltReceptor>(identifier));
        break;
    case ReceptorType::LIGHT_RECEPTOR:
        return std::move(std::make_unique<LightReceptor>(identifier));
        break;
    case ReceptorType::COMPASS_RECEPTOR:
        return std::move(std::make_unique<CompassReceptor>(identifier));
        break;
    case ReceptorType::PROXIMITY_RECEPTOR:
        return std::move(std::make_unique<ProximityReceptor>(identifier));
        break;
    case ReceptorType::ORIENTATION_RECEPTOR:
        return std::move(std::make_unique<OrientationReceptor>(identifier));
        break;
    case ReceptorType::ACCELEROMETER_RECEPTOR:
        return std::move(std::make_unique<AccelerometerReceptor>(identifier));
        break;
    case ReceptorType::AMBIENT_LIGHT_RECEPTOR:
        return std::move(std::make_unique<AmbientLightReceptor>(identifier));
        break;
    case ReceptorType::MAGNETOMETER_RECEPTOR:
        return std::move(std::make_unique<MagnetometerReceptor>(identifier));
        break;
    case ReceptorType::UNKNOWN_RECEPTOR:
        return std::move(std::make_unique<DummyReceptor>(identifier));
        break;
    default:
        return std::move(std::make_unique<DummyReceptor>(identifier));
    }
}

ReceptorType sensorTypeToReceptorType(const QByteArray &type)
{
    if(QTiltSensor::type == type)
    {
        return ReceptorType::TILT_RECEPTOR;
    }
    else if(QLightSensor::type == type)
    {
        return ReceptorType::LIGHT_RECEPTOR;
    }
    else if(QCompass::type == type)
    {
        return ReceptorType::COMPASS_RECEPTOR;
    }
    else if(QProximitySensor::type == type)
    {
        return ReceptorType::PROXIMITY_RECEPTOR;
    }
    else if(QOrientationSensor::type == type)
    {
        return ReceptorType::ORIENTATION_RECEPTOR;
    }
    else if(QAccelerometer::type == type)
    {
        return ReceptorType::ACCELEROMETER_RECEPTOR;
    }
    else if(QAmbientLightSensor::type == type)
    {
        return ReceptorType::AMBIENT_LIGHT_RECEPTOR;
    }
    else if(QMagnetometer::type == type)
    {
        return ReceptorType::MAGNETOMETER_RECEPTOR;
    }
    else
    {
        qDebug() << "ReceptorType: " << type << " is not implemented!!!";
        return ReceptorType::UNKNOWN_RECEPTOR;
    }
}
