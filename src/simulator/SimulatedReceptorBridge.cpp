#include "SimulatedReceptorBridge.hpp"

#include <QDebug>
#include <QtQml/qqml.h>

#include "ReceptorInfo.hpp"
#include "ReceptorFactory.hpp"
#include "simulated-receptors/SimulatedTilt.hpp"
#include "simulated-receptors/SimulatedLight.hpp"
#include "simulated-receptors/SimulatedCompass.hpp"
#include "simulated-receptors/SimulatedRotation.hpp"
#include "simulated-receptors/SimulatedGyroscope.hpp"
#include "simulated-receptors/SimulatedProximity.hpp"
#include "simulated-receptors/SimulatedOrientation.hpp"
#include "simulated-receptors/SimulatedAmbientLight.hpp"
#include "simulated-receptors/SimulatedMagnetometer.hpp"
#include "simulated-receptors/SimulatedAccelerometer.hpp"

namespace SimulatedReceptorBridge
{

    QObjectList fetchReceptorInfos(QObject *targetParent)
    {
        QObjectList result;
        QVector<QPair<QByteArray, QByteArray>> sensors;
        insertPairOfByteArraysInVector(sensors, "QTiltSensor", "simulated_tilt");
        insertPairOfByteArraysInVector(sensors, "QLightSensor", "simulated_light");
        insertPairOfByteArraysInVector(sensors, "QCompass", "simulated_compass");
        insertPairOfByteArraysInVector(sensors, "QProximitySensor", "simulated_proximity");
        insertPairOfByteArraysInVector(sensors, "QOrientationSensor", "simulated_orientation");
        insertPairOfByteArraysInVector(sensors, "QRotationSensor", "simulated_rotation");
        insertPairOfByteArraysInVector(sensors, "QAmbientLightSensor", "simulated_ambient_light");
        insertPairOfByteArraysInVector(sensors, "QMagnetometer", "simulated_magnetometer");
        insertPairOfByteArraysInVector(sensors, "QAccelerometer", "simulated_accelerometer");
        insertPairOfByteArraysInVector(sensors, "QGyroscope", "simulated_gyroscope");

        for(const auto &simulatedSensor : qAsConst(sensors)) {
            const auto simulatedType = simulatedSensor.first;
            const auto simulatedIdentifier = simulatedSensor.second;
            qDebug() << "Found simulated type: " << simulatedType;
            qDebug() << "Found simulated identifier: " << simulatedIdentifier;
            result.push_back(ReceptorFactory::createReceptorInfo(simulatedType, simulatedIdentifier, targetParent));
        }

        return result;
    }

    void registerQuickComponents()
    {
        qmlRegisterType<SimulatedTilt>("ShiftRayReceptor", 1, 0, "TiltReceptor");
        qmlRegisterType<SimulatedLight>("ShiftRayReceptor", 1, 0, "LightReceptor");
        qmlRegisterType<SimulatedCompass>("ShiftRayReceptor", 1, 0, "CompassReceptor");
        qmlRegisterType<SimulatedRotation>("ShiftRayReceptor", 1, 0, "RotationReceptor");
        qmlRegisterType<SimulatedGyroscope>("ShiftRayReceptor", 1, 0, "GyroscopeReceptor");
        qmlRegisterType<SimulatedProximity>("ShiftRayReceptor", 1, 0, "ProximityReceptor");
        qmlRegisterType<SimulatedOrientation>("ShiftRayReceptor", 1, 0, "OrientationReceptor");
        qmlRegisterType<SimulatedAmbientLight>("ShiftRayReceptor", 1, 0, "AmbientLightReceptor");
        qmlRegisterType<SimulatedMagnetometer>("ShiftRayReceptor", 1, 0, "MagnetometerReceptor");
        qmlRegisterType<SimulatedAccelerometer>("ShiftRayReceptor", 1, 0, "AccelerometerReceptor");
    }

    void insertPairOfByteArraysInVector(QVector<QPair<QByteArray, QByteArray>> &targetVector, const QByteArray &first, const QByteArray &second)
    {
        targetVector.push_back(QPair<QByteArray, QByteArray>(first, second));
    }

    // This method simplifies registering, but QtCreator is not aware of the registered types
    // Disabled for now

    //#include <QMetaObject>
    //template<class T> int qmlRegisterReceptor()
    //{
    //    return qmlRegisterType<T>("ShiftRayReceptor", 1, 0, T::staticMetaObject.className());
    //}

}
