#ifndef SHIFTSETTINGS_HPP
#define SHIFTSETTINGS_HPP

#include <QObject>
class QQmlContext;

class ShiftSettings : public QObject
{
    Q_OBJECT

    Q_PROPERTY(bool usingSimulator READ isSimulatorUsed WRITE setIsUsedSimulator NOTIFY usingSimulatorChanged)
    Q_PROPERTY(QString deviceUUID READ getDeviceUUID NOTIFY deviceUUIDChanged)
    Q_PROPERTY(QString deviceName READ getDeviceName WRITE setDeviceName NOTIFY deviceNameChanged)
    Q_PROPERTY(QString deviceType READ getDeviceType WRITE setDeviceType NOTIFY deviceTypeChanged)

    Q_PROPERTY(QString restApiHost READ getRestApiHost WRITE setRestApiHost NOTIFY restApiHostChanged)
    Q_PROPERTY(int restApiPort READ getRestApiPort WRITE setRestApiPort NOTIFY restApiPortChanged)

    Q_PROPERTY(QString telemetryHost READ getTelemetryHost WRITE setTelemetryHost NOTIFY telemetryHostChanged)
    Q_PROPERTY(int telemetryPort READ getTelemetryPort WRITE setTelemetryPort NOTIFY telemetryPortChanged)

    Q_PROPERTY(QString osName READ getOSName NOTIFY osNameChanged)
    Q_PROPERTY(QString osVersion READ getOSVersion NOTIFY osVersionChanged)

    Q_PROPERTY(bool isUserRegistered READ getIsUserRegistered WRITE setIsUserRegistered NOTIFY userIsRegisteredChanged)
    Q_PROPERTY(QString userName READ getUserName WRITE setUserName NOTIFY userNameChanged)
    Q_PROPERTY(QString userEmail READ getUserEmail WRITE setUserEmail NOTIFY userEmailChanged)
    Q_PROPERTY(QString userFirstName READ getUserFirstName WRITE setUserFirstName NOTIFY userFirstNameChanged)
    Q_PROPERTY(QString userLastName READ getUserLastName WRITE setUserLastName NOTIFY userLastNameChanged)
    Q_PROPERTY(QString userPassword READ getUserPassword WRITE setUserPassword NOTIFY userPasswordChanged)

public:
    explicit ShiftSettings(QObject *parent = nullptr);
    virtual ~ShiftSettings();

    void registerQmlSettings(QQmlContext *ctxt);

    bool isSimulatorUsed() const;
    void setIsUsedSimulator(const bool &isUsed);

    QString getRestApiHost() const;
    void setRestApiHost(const QString &host);

    int getRestApiPort() const;
    void setRestApiPort(const int &port);

    QString getTelemetryHost() const;
    void setTelemetryHost(const QString &host);

    int getTelemetryPort() const;
    void setTelemetryPort(const int &port);

    QString getDeviceUUID() const;
    void setDeviceUUID(const QString &deviceUUID);

    QString getDeviceName() const;
    void setDeviceName(const QString &deviceName);

    QString getDeviceType() const;
    void setDeviceType(const QString &deviceType);

    QString getOSName() const;
    void setOSName(const QString &osName);

    QString getOSVersion() const;
    void setOSVersion(const QString &osVersion);

    bool getIsUserRegistered() const;
    void setIsUserRegistered(bool isRegistered);

    QString getUserName() const;
    void setUserName(const QString &userName);

    QString getUserEmail() const;
    void setUserEmail(const QString &email);

    QString getUserFirstName() const;
    void setUserFirstName(const QString &firstName);

    QString getUserLastName() const;
    void setUserLastName(const QString &lastName);

    QString getUserPassword() const;
    void setUserPassword(const QString &userPassword);

signals:
    void usingSimulatorChanged();
    void restApiHostChanged();
    void restApiPortChanged();
    void telemetryHostChanged();
    void telemetryPortChanged();

    void deviceUUIDChanged();
    void deviceNameChanged();
    void deviceTypeChanged();
    void osNameChanged();
    void osVersionChanged();

    void userIsRegisteredChanged();
    void userNameChanged();
    void userEmailChanged();
    void userFirstNameChanged();
    void userLastNameChanged();
    void userPasswordChanged();
};

#endif // SHIFTSETTINGS_HPP
