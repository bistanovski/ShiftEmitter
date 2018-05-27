#include "ShiftSettings.hpp"

#include <QSettings>
#include <QQmlContext>

Q_GLOBAL_STATIC_WITH_ARGS(QSettings, globalSettings, ("ShiftRay", "ShiftEmitter"))

QLatin1String SIMULATOR_KEY("usedSimulator");
QLatin1String REST_API_HOST_KEY("restApiHost");
QLatin1String REST_API_PORT_KEY("restApiPort");
QLatin1String TELEMETRY_HOST_KEY("telemetryHost");
QLatin1String TELEMETRY_PORT_KEY("telemetryPort");
QLatin1String DEVICE_UUID_KEY("deviceUUID");
QLatin1String OS_NAME_KEY("osName");
QLatin1String OS_VERSION_KEY("osVersion");

ShiftSettings::ShiftSettings(QObject *parent) : QObject(parent)
{

}

ShiftSettings::~ShiftSettings()
{

}

void ShiftSettings::registerQmlSettings(QQmlContext *ctxt)
{
    ctxt->setContextProperty("ShiftSettings", this);
}

bool ShiftSettings::isSimulatorUsed() const
{
    return globalSettings->value(SIMULATOR_KEY, false).toBool();
}

void ShiftSettings::setIsUsedSimulator(const bool &isUsed)
{
    globalSettings->setValue(SIMULATOR_KEY, isUsed);
    emit usingSimulatorChanged();
}

QString ShiftSettings::getRestApiHost() const
{
    return globalSettings->value(REST_API_HOST_KEY, QString("127.0.0.1")).toString();
}

void ShiftSettings::setRestApiHost(const QString &host)
{
    globalSettings->setValue(REST_API_HOST_KEY, host);
    emit restApiHostChanged();
}

int ShiftSettings::getRestApiPort() const
{
    return globalSettings->value(REST_API_PORT_KEY, 8000).toInt();
}

void ShiftSettings::setRestApiPort(const int &port)
{
    globalSettings->setValue(REST_API_PORT_KEY, port);
    emit restApiPortChanged();
}

QString ShiftSettings::getTelemetryHost() const
{
    return globalSettings->value(TELEMETRY_HOST_KEY, QString("127.0.0.1")).toString();
}

void ShiftSettings::setTelemetryHost(const QString &host)
{
    globalSettings->setValue(TELEMETRY_HOST_KEY, host);
    emit telemetryHostChanged();
}

int ShiftSettings::getTelemetryPort() const
{
    return globalSettings->value(TELEMETRY_PORT_KEY, 1883).toInt();
}

void ShiftSettings::setTelemetryPort(const int &port)
{
    globalSettings->setValue(TELEMETRY_PORT_KEY, port);
    emit telemetryPortChanged();
}

QByteArray ShiftSettings::getDeviceUUID() const
{
    return globalSettings->value(DEVICE_UUID_KEY, QByteArray()).toByteArray();
}

void ShiftSettings::setDeviceUUID(const QByteArray &deviceUUID)
{
    globalSettings->setValue(DEVICE_UUID_KEY, deviceUUID);
    emit deviceUUIDChanged();
}

QString ShiftSettings::getOSName() const
{
    return globalSettings->value(OS_NAME_KEY, QString()).toString();
}

void ShiftSettings::setOSName(const QString &osName)
{
    globalSettings->setValue(OS_NAME_KEY, osName);
    emit osNameChanged();
}

QString ShiftSettings::getOSVersion() const
{
    return globalSettings->value(OS_VERSION_KEY, QString()).toString();
}

void ShiftSettings::setOSVersion(const QString &osVersion)
{
    globalSettings->setValue(OS_VERSION_KEY, osVersion);
    emit osVersionChanged();
}
