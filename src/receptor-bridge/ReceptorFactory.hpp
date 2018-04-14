#ifndef RECEPTORFACTORY_HPP
#define RECEPTORFACTORY_HPP

#include <memory>

class Receptor;
class QByteArray;

enum class ReceptorType : int {
    UNKNOWN_RECEPTOR = 0,
    LIGHT_RECEPTOR,
    COMPASS_RECEPTOR,
    ORIENTATION_RECEPTOR,
    AMBIENT_LIGHT_RECEPTOR
};

namespace ReceptorFactory {
    std::unique_ptr<Receptor> createReceptor(const QByteArray &type);
}

ReceptorType sensorTypeToReceptorType(const QByteArray &type);

#endif // RECEPTORFACTORY_HPP
