#ifndef SHIFTSETTINGS_HPP
#define SHIFTSETTINGS_HPP

#include <QObject>
class QQmlContext;

class ShiftSettings : public QObject
{
    Q_OBJECT

    Q_PROPERTY(bool usingSimulator READ isSimulatorUsed WRITE setIsUsedSimulator NOTIFY usingSimulatorChanged)
    Q_PROPERTY(QByteArray deviceUUID READ getDeviceUUID NOTIFY deviceUUIDChanged)

    Q_PROPERTY(QString restApiHost READ getRestApiHost WRITE setRestApiHost NOTIFY restApiHostChanged)
    Q_PROPERTY(int restApiPort READ getRestApiPort WRITE setRestApiPort NOTIFY restApiPortChanged)

    Q_PROPERTY(QString telemetryHost READ getTelemetryHost WRITE setTelemetryHost NOTIFY telemetryHostChanged)
    Q_PROPERTY(int telemetryPort READ getTelemetryPort WRITE setTelemetryPort NOTIFY telemetryPortChanged)

    Q_PROPERTY(QString osName READ getOSName NOTIFY osNameChanged)
    Q_PROPERTY(QString osVersion READ getOSVersion NOTIFY osVersionChanged)

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

    QByteArray getDeviceUUID() const;
    void setDeviceUUID(const QByteArray &deviceUUID);

    QString getOSName() const;
    void setOSName(const QString &osName);

    QString getOSVersion() const;
    void setOSVersion(const QString &osVersion);

signals:
    void usingSimulatorChanged();
    void restApiHostChanged();
    void restApiPortChanged();
    void telemetryHostChanged();
    void telemetryPortChanged();
    void deviceUUIDChanged();
    void osNameChanged();
    void osVersionChanged();

};

#endif // SHIFTSETTINGS_HPP
