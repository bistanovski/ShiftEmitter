#include "ReceptorInfo.hpp"

#include <QDebug>

ReceptorInfo::ReceptorInfo(const QByteArray &type, const QByteArray &identifier, QObject *parent) : QObject(parent),
    m_type(type),
    m_identifier(identifier),
    m_friendlyName(receptorTypeToFriendlyName(m_type))
{
    emit typeChanged();
    emit identifierChanged();
    qDebug() << "ReceptorInfo:" << m_friendlyName;
}

ReceptorInfo::~ReceptorInfo()
{
    qDebug() << "~ReceptorInfo:" << m_friendlyName;
}

QString ReceptorInfo::getFriendlyName() const
{
    return m_friendlyName;
}

QByteArray ReceptorInfo::getType() const
{
    return m_type;
}

QByteArray ReceptorInfo::getIdentifier() const
{
    return m_identifier;
}

QString receptorTypeToFriendlyName(const QByteArray &type)
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
    else if(QLatin1String("QCompass") == type)
    {
        return QLatin1String("Compass");
    }
    else if(QLatin1String("QAccelerometer") == type)
    {
        return QLatin1String("Accelerometer");
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
