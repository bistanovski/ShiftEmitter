#ifndef TELEMETRYTRANSPORTER_HPP
#define TELEMETRYTRANSPORTER_HPP

#include <QThread>
#include <QObject>
#include <QMqttClient>
#include <QMqttTopicName>

class Receptor;
class QQmlContext;

class TransportWorker : public QObject
{
    Q_OBJECT

public:
    static QString PROXIMITY;
    static QString TILT;
    static QString AMBIENT_LIGHT;
    static QString LIGHT;
    static QString COMPASS;
    static QString ACCELEROMETER;
    static QString MAGNETOMETER;
    static QString ORIENTATION;

    explicit TransportWorker(QObject *parent = nullptr);
    virtual ~TransportWorker();

signals:
    void connectionStatusChanged(const bool connected);

public slots:
    void initializeConnection(const QString brokerHost, const int brokerPort);
    void onPublishNewMessage(const QString topicName, const QByteArray message);

private:
    QScopedPointer<QMqttClient> m_mqttCLient;
    QMap<QString, QMqttTopicName> m_topicsMap;
};



class TelemetryTransporter : public QObject
{
    Q_OBJECT
public:
    explicit TelemetryTransporter(QObject *parent = nullptr);
    virtual ~TelemetryTransporter();

    void registerQmlTransporter(QQmlContext* ctxt);

    Q_PROPERTY(bool isConnected READ connectedToServer WRITE setConnectedToServer NOTIFY connectedToServerChanged)

    Q_INVOKABLE void sendAccelerometerTelemetry(const qreal xValue, const qreal yValue, const qreal zValue);
    Q_INVOKABLE void sendAmbientLightTelemetry(const int lightLevel);
    Q_INVOKABLE void sendCompassTelemetry(const qreal azimuth, const qreal calibrationLevel);
    Q_INVOKABLE void sendLightTelemetry(const qreal luxValue);
    Q_INVOKABLE void sendMagnetometerTelemetry(const qreal xFlux, const qreal yFlux, const qreal zFlux, const qreal calibrationLevel);
    Q_INVOKABLE void sendOrientationTelemetry(const int orientation);
    Q_INVOKABLE void sendProximityTelemetry(const bool close);
    Q_INVOKABLE void sendTiltTelemetry(const qreal xRotation, const qreal yRotation);

    bool connectedToServer() const;
    void setConnectedToServer(const bool connected);

signals:
    void connectedToServerChanged();
    void publishNewMessage(const QString topicName, const QByteArray message);

private:
    bool m_connectedToServer{false};
    QThread m_workerThread;
};

#endif // TELEMETRYTRANSPORTER_HPP
