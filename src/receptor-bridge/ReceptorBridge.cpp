#include "ReceptorBridge.hpp"

#include <QDebug>
#include <QSensor>
#include <QtQml/qqml.h>

#include "ReceptorInfo.hpp"
#include "ReceptorFactory.hpp"
#include "receptors/TiltReceptor.hpp"
#include "receptors/LightReceptor.hpp"
#include "receptors/CompassReceptor.hpp"
#include "receptors/RotationReceptor.hpp"
#include "receptors/GyroscopeReceptor.hpp"
#include "receptors/ProximityReceptor.hpp"
#include "receptors/OrientationReceptor.hpp"
#include "receptors/AmbientLightReceptor.hpp"
#include "receptors/MagnetometerReceptor.hpp"
#include "receptors/AccelerometerReceptor.hpp"

namespace ReceptorBridge
{

    QObjectList fetchReceptorInfos(QObject *targetParent)
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

    void registerQuickComponents()
    {
        qmlRegisterType<TiltReceptor>("ShiftRayReceptor", 1, 0, "TiltReceptor");
        qmlRegisterType<LightReceptor>("ShiftRayReceptor", 1, 0, "LightReceptor");
        qmlRegisterType<CompassReceptor>("ShiftRayReceptor", 1, 0, "CompassReceptor");
        qmlRegisterType<RotationReceptor>("ShiftRayReceptor", 1, 0, "RotationReceptor");
        qmlRegisterType<GyroscopeReceptor>("ShiftRayReceptor", 1, 0, "GyroscopeReceptor");
        qmlRegisterType<ProximityReceptor>("ShiftRayReceptor", 1, 0, "ProximityReceptor");
        qmlRegisterType<OrientationReceptor>("ShiftRayReceptor", 1, 0, "OrientationReceptor");
        qmlRegisterType<AmbientLightReceptor>("ShiftRayReceptor", 1, 0, "AmbientLightReceptor");
        qmlRegisterType<MagnetometerReceptor>("ShiftRayReceptor", 1, 0, "MagnetometerReceptor");
        qmlRegisterType<AccelerometerReceptor>("ShiftRayReceptor", 1, 0, "AccelerometerReceptor");
    }

    // This method simplifies registering, but QtCreator is not aware of the registered types
    // Disabled for now

    //#include <QMetaObject>
    //template<class T> int qmlRegisterReceptor()
    //{
    //    return qmlRegisterType<T>("ShiftRayReceptor", 1, 0, T::staticMetaObject.className());
    //}

}
