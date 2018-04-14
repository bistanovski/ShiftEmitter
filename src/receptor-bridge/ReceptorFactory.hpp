#ifndef RECEPTORFACTORY_HPP
#define RECEPTORFACTORY_HPP

#include <memory>

class Receptor;
class QByteArray;

enum class ReceptorType : int {
    UNKNOWN_RECEPTOR = 0,
    TILT_RECEPTOR,
    LIGHT_RECEPTOR,
    COMPASS_RECEPTOR,
    PROXIMITY_RECEPTOR,
    ORIENTATION_RECEPTOR,
    ACCELEROMETER_RECEPTOR,
    AMBIENT_LIGHT_RECEPTOR,
    MAGNETOMETER_RECEPTOR,
};

namespace ReceptorFactory {
    std::unique_ptr<Receptor> createReceptor(const QByteArray &type, const QByteArray &identifier);
}

ReceptorType sensorTypeToReceptorType(const QByteArray &type);

#endif // RECEPTORFACTORY_HPP
