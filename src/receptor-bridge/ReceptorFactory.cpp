#include "ReceptorFactory.hpp"

#include "Receptor.hpp"
#include "LightReceptor.hpp"
#include "CompassReceptor.hpp"
#include "OrientationReceptor.hpp"
#include "AmbientLightReceptor.hpp"
#include "DummyReceptor.hpp"

std::unique_ptr<Receptor> ReceptorFactory::createReceptor(const QByteArray &type)
{
    switch (sensorTypeToReceptorType(type)) {
    case ReceptorType::LIGHT_RECEPTOR:
        return std::move(std::make_unique<LightReceptor>(nullptr));
        break;
    case ReceptorType::COMPASS_RECEPTOR:
        return std::move(std::make_unique<CompassReceptor>(nullptr));
        break;
    case ReceptorType::ORIENTATION_RECEPTOR:
        return std::move(std::make_unique<OrientationReceptor>(nullptr));
        break;
    case ReceptorType::AMBIENT_LIGHT_RECEPTOR:
        return std::move(std::make_unique<AmbientLightReceptor>(nullptr));
        break;
    case ReceptorType::UNKNOWN_RECEPTOR:
        return std::move(std::make_unique<DummyReceptor>(nullptr));
        break;
    default:
        return std::move(std::make_unique<DummyReceptor>(nullptr));
    }
}

ReceptorType sensorTypeToReceptorType(const QByteArray &type)
{
    if(QLightSensor::type == type)
    {
        return ReceptorType::LIGHT_RECEPTOR;
    }
    else if(QCompass::type == type)
    {
        return ReceptorType::COMPASS_RECEPTOR;
    }
    else if(QOrientationSensor::type == type)
    {
        return ReceptorType::ORIENTATION_RECEPTOR;
    }
    else if(QAmbientLightSensor::type == type)
    {
        return ReceptorType::AMBIENT_LIGHT_RECEPTOR;
    }
    else
    {
        return ReceptorType::UNKNOWN_RECEPTOR;
    }
}
