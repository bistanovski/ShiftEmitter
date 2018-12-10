#ifndef MQTTCLIENT_HPP
#define MQTTCLIENT_HPP

#include <QThread>
#include <QObject>
#include <QMqttClient>
#include <QMqttTopicName>

class QQmlContext;

class MqttWorker : public QObject
{
    Q_OBJECT

public:
    explicit MqttWorker(QString deviceUUID, QObject *parent = nullptr);
    virtual ~MqttWorker();

signals:
    void connectionStatusChanged(const bool connected);

public slots:
    void initializeConnection(const QString brokerHost, const int brokerPort, const QString username, const QString password);
    void onPublishNewMessage(const QString topicName, const QByteArray message);

private:
    QScopedPointer<QMqttClient> m_mqttCLient;
    QMap<QString, QMqttTopicName> m_topicsMap;
};



class MqttClient : public QObject
{
    Q_OBJECT

public:
    explicit MqttClient(QString deviceUUID, QObject *parent = nullptr);
    virtual ~MqttClient();

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
    Q_INVOKABLE void sendRotationTelemetry(const qreal xValue, const qreal yValue, const qreal zValue);
    Q_INVOKABLE void sendGyroscopeTelemetry(const qreal xValue, const qreal yValue, const qreal zValue);

    bool connectedToServer() const;
    void setConnectedToServer(const bool connected);

signals:
    void connectedToServerChanged();
    void publishNewMessage(const QString topicName, const QByteArray message);

private:
    bool m_connectedToServer{false};
    QThread m_workerThread;
};

#endif // MQTTCLIENT_HPP
