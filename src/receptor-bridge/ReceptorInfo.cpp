#include "ReceptorInfo.hpp"

#include <QDebug>
#include <QJsonArray>

auto receptorTypeToFriendlyName(const QByteArray &type)
{
    if(QLatin1String("QProximitySensor") == type)
    {
        return QLatin1String("Proximity");
    }
    else if(QLatin1String("QTiltSensor") == type)
    {
        return QLatin1String("Tilt");
    }
    else if(QLatin1String("QAmbientLightSensor") == type)
    {
        return QLatin1String("AmbientLight");
    }
    else if(QLatin1String("QLightSensor") == type)
    {
        return QLatin1String("Light");
    }
    else if(QLatin1String("QRotationSensor") == type)
    {
        return QLatin1String("Rotation");
    }
    else if(QLatin1String("QCompass") == type)
    {
        return QLatin1String("Compass");
    }
    else if(QLatin1String("QAccelerometer") == type)
    {
        return QLatin1String("Accelerometer");
    }
    else if(QLatin1String("QGyroscope") == type)
    {
        return QLatin1String("Gyroscope");
    }
    else if(QLatin1String("QMagnetometer") == type)
    {
        return QLatin1String("Magnetometer");
    }
    else if(QLatin1String("QOrientationSensor") == type)
    {
        return QLatin1String("Orientation");
    }
    else
    {
        return QLatin1String("Unknown");
    }
}

auto readingsPerReceptor(const QByteArray &type)
{
    QMap<QString, QPair<QString, QString>> result;

    const auto createReadingPair = [](const QString &readingType, const QString &renderingType){
        return QPair<QString,QString>(readingType, renderingType);
    };

    if(QLatin1String("QProximitySensor") == type)
    {
        result.insert(QLatin1String("close"), createReadingPair("bool", "chart"));
    }
    else if(QLatin1String("QTiltSensor") == type)
    {
        const auto doubleReading = createReadingPair("double", "chart");
        result.insert(QLatin1String("xRotation"), doubleReading);
        result.insert(QLatin1String("yRotation"), doubleReading);
    }
    else if(QLatin1String("QAmbientLightSensor") == type)
    {
        result.insert(QLatin1String("lightLevel"), createReadingPair("int", "chart"));
    }
    else if(QLatin1String("QLightSensor") == type)
    {
        const auto doubleReading = createReadingPair("double", "chart");
        result.insert(QLatin1String("lux"), doubleReading);
    }
    else if(QLatin1String("QRotationSensor") == type)
    {
        const auto doubleReading = QPair<QString,QString>(QLatin1String("double"), QLatin1String("chart"));
        result.insert(QLatin1String("x"), doubleReading);
        result.insert(QLatin1String("y"), doubleReading);
        result.insert(QLatin1String("z"), doubleReading);
    }
    else if(QLatin1String("QCompass") == type)
    {
        const auto doubleReading = createReadingPair("double", "chart");
        result.insert(QLatin1String("azimuth"), doubleReading);
        result.insert(QLatin1String("calibrationLevel"), doubleReading);
    }
    else if(QLatin1String("QAccelerometer") == type)
    {
        const auto doubleReading = createReadingPair("double", "chart");
        result.insert(QLatin1String("x"), doubleReading);
        result.insert(QLatin1String("y"), doubleReading);
        result.insert(QLatin1String("z"), doubleReading);
    }
    else if(QLatin1String("QGyroscope") == type)
    {
        const auto doubleReading = createReadingPair("double", "chart");
        result.insert(QLatin1String("x"), doubleReading);
        result.insert(QLatin1String("y"), doubleReading);
        result.insert(QLatin1String("z"), doubleReading);
    }
    else if(QLatin1String("QMagnetometer") == type)
    {
        const auto doubleReading = createReadingPair("double", "chart");
        result.insert(QLatin1String("x"), doubleReading);
        result.insert(QLatin1String("y"), doubleReading);
        result.insert(QLatin1String("z"), doubleReading);
        result.insert(QLatin1String("calibrationLevel"), doubleReading);
    }
    else if(QLatin1String("QOrientationSensor") == type)
    {
        result.insert(QLatin1String("orientation"), createReadingPair("int", "chart"));
    }

    return result;
}

ReceptorInfo::ReceptorInfo(const QByteArray &type, const QByteArray &identifier, QObject *parent) : QObject(parent),
    m_type(type),
    m_identifier(identifier),
    m_friendlyName(receptorTypeToFriendlyName(m_type)),
    m_receptorReadings(readingsPerReceptor(m_type))
{
    emit typeChanged();
    emit identifierChanged();
}

ReceptorInfo::~ReceptorInfo()
{
    qDebug() << "~ReceptorInfo:" << m_friendlyName;
}

QString ReceptorInfo::getFriendlyName() const
{
    return m_friendlyName;
}

const ReadingsMap &ReceptorInfo::getReadings() const
{
    return m_receptorReadings;
}

QJsonObject ReceptorInfo::toJson() const
{
    QJsonObject receptorObject
    {
//        {"identifier", QString(m_identifier)},
        {"type", QString(m_type)},
        {"sensor_name", m_friendlyName},
        {"number_of_readings", m_receptorReadings.count()}
    };

    QJsonArray readingsArray;
    for(auto kIt = m_receptorReadings.keyBegin(); kIt != m_receptorReadings.keyEnd(); ++kIt)
    {
        readingsArray.push_back(std::move(
                                    QJsonObject
                                    {
                                        {"reading_name", *kIt},
                                        {"reading_type", m_receptorReadings.value(*kIt).first},
                                        {"rendering_type", m_receptorReadings.value(*kIt).second},
                                    }
                                    ));
    }

    receptorObject.insert("sensor_readings", readingsArray);
    return receptorObject;
}

QByteArray ReceptorInfo::getType() const
{
    return m_type;
}

QByteArray ReceptorInfo::getIdentifier() const
{
    return m_identifier;
}
