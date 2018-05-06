#ifndef SHIFTSETTINGS_HPP
#define SHIFTSETTINGS_HPP

#include <QObject>
class QQmlContext;

class ShiftSettings : public QObject
{
    Q_OBJECT

    Q_PROPERTY(bool usingSimulator READ isSimulatorUsed WRITE setIsUsedSimulator NOTIFY usingSimulatorChanged)
    Q_PROPERTY(QByteArray deviceUUID READ getDeviceUUID NOTIFY deviceUUIDChanged)

public:
    explicit ShiftSettings(QObject *parent = nullptr);
    virtual ~ShiftSettings();

    void registerQmlSettings(QQmlContext *ctxt);

    bool isSimulatorUsed() const;
    void setIsUsedSimulator(const bool &isUsed);

    QByteArray getDeviceUUID() const;
    void setDeviceUUID(const QByteArray &deviceUUID);

signals:
    void usingSimulatorChanged();
    void deviceUUIDChanged();

};

#endif // SHIFTSETTINGS_HPP
