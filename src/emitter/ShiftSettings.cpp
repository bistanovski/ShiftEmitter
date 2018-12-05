#include "ShiftSettings.hpp"

#include <QSettings>
#include <QQmlContext>

Q_GLOBAL_STATIC_WITH_ARGS(QSettings, globalSettings, ("ShiftRay", "ShiftEmitter"))

const QLatin1String SIMULATOR_KEY("usedSimulator");
const QLatin1String REST_API_HOST_KEY("restApiHost");
const QLatin1String REST_API_PORT_KEY("restApiPort");

const QLatin1String TELEMETRY_HOST_KEY("telemetryHost");
const QLatin1String TELEMETRY_VIRTUAL_HOST_KEY("telemetryVirtualHost");
const QLatin1String TELEMETRY_PORT_KEY("telemetryPort");
const QLatin1String TELEMETRY_USERNAME_KEY("telemetryUsername");
const QLatin1String TELEMETRY_PASSWORD_KEY("telemetryPassword");

const QLatin1String DEVICE_UUID_KEY("deviceUUID");
const QLatin1String DEVICE_NAME_KEY("deviceName");
const QLatin1String DEVICE_TYPE_KEY("deviceType");
const QLatin1String OS_NAME_KEY("osName");
const QLatin1String OS_VERSION_KEY("osVersion");

const QLatin1String USER_REGISTERED_KEY("isUserRegistered");
const QLatin1String USER_NAME_KEY("userName");
const QLatin1String USER_EMAIL_KEY("userEmail");
const QLatin1String USER_FIRST_NAME_KEY("userFirstName");
const QLatin1String USER_LAST_NAME_KEY("userLastName");
const QLatin1String USER_PASSWORD_KEY("userPassword");

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

QString ShiftSettings::getTelemetryVirtualHost() const
{
    return globalSettings->value(TELEMETRY_VIRTUAL_HOST_KEY, QString("/")).toString();
}

void ShiftSettings::setTelemetryVirtualHost(const QString &host)
{
    globalSettings->setValue(TELEMETRY_VIRTUAL_HOST_KEY, host);
    emit telemetryVirtualHostChanged();
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

QString ShiftSettings::getTelemetryUsername() const
{
    return globalSettings->value(TELEMETRY_USERNAME_KEY, QString("")).toString();
}

void ShiftSettings::setTelemetryUsername(const QString &userName)
{
    globalSettings->setValue(TELEMETRY_USERNAME_KEY, userName);
    emit telemetryUsernameChanged();
}

QString ShiftSettings::getTelemetryPassword() const
{
    return globalSettings->value(TELEMETRY_PASSWORD_KEY, QString("")).toString();
}

void ShiftSettings::setTelemetryPassword(const QString &password)
{
    globalSettings->setValue(TELEMETRY_PASSWORD_KEY, password);
    emit telemetryPasswordChanged();
}

QString ShiftSettings::getDeviceUUID() const
{
    return globalSettings->value(DEVICE_UUID_KEY, QString()).toString();
}

void ShiftSettings::setDeviceUUID(const QString &deviceUUID)
{
    globalSettings->setValue(DEVICE_UUID_KEY, deviceUUID);
    emit deviceUUIDChanged();
}

QString ShiftSettings::getDeviceName() const
{
    return globalSettings->value(DEVICE_NAME_KEY, QString()).toString();
}

void ShiftSettings::setDeviceName(const QString &deviceName)
{
    globalSettings->setValue(DEVICE_NAME_KEY, deviceName);
    emit deviceNameChanged();
}

QString ShiftSettings::getDeviceType() const
{
    return globalSettings->value(DEVICE_TYPE_KEY, QString()).toString();
}

void ShiftSettings::setDeviceType(const QString &deviceType)
{
    globalSettings->setValue(DEVICE_TYPE_KEY, deviceType);
    emit deviceTypeChanged();
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

bool ShiftSettings::getIsUserRegistered() const
{
    return globalSettings->value(USER_REGISTERED_KEY, false).toBool();
}

void ShiftSettings::setIsUserRegistered(bool isRegistered)
{
    globalSettings->setValue(USER_REGISTERED_KEY, isRegistered);
    emit userIsRegisteredChanged();
}

QString ShiftSettings::getUserName() const
{
    return globalSettings->value(USER_NAME_KEY, QString()).toString();
}

void ShiftSettings::setUserName(const QString &userName)
{
    globalSettings->setValue(USER_NAME_KEY, userName);
    emit userNameChanged();
}

QString ShiftSettings::getUserEmail() const
{
    return globalSettings->value(USER_EMAIL_KEY, QString()).toString();
}

void ShiftSettings::setUserEmail(const QString &email)
{
    globalSettings->setValue(USER_EMAIL_KEY, email);
    emit userEmailChanged();
}

QString ShiftSettings::getUserFirstName() const
{
    return globalSettings->value(USER_FIRST_NAME_KEY, QString()).toString();
}

void ShiftSettings::setUserFirstName(const QString &firstName)
{
    globalSettings->setValue(USER_FIRST_NAME_KEY, firstName);
    emit userFirstNameChanged();
}

QString ShiftSettings::getUserLastName() const
{
    return globalSettings->value(USER_LAST_NAME_KEY, QString()).toString();
}

void ShiftSettings::setUserLastName(const QString &lastName)
{
    globalSettings->setValue(USER_LAST_NAME_KEY, lastName);
    emit userLastNameChanged();
}

QString ShiftSettings::getUserPassword() const
{
    return globalSettings->value(USER_PASSWORD_KEY, QString()).toString();
}

void ShiftSettings::setUserPassword(const QString &userPassword)
{
    globalSettings->setValue(USER_PASSWORD_KEY, userPassword);
    emit userPasswordChanged();
}
