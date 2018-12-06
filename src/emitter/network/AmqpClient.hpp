#ifndef AMQPCLIENT_HPP
#define AMQPCLIENT_HPP

#include <QThread>
#include <QObject>
#include <qamqpqueue.h>
#include <qamqpclient.h>
#include <qamqpexchange.h>

class QQmlContext;

class AmqpWorker : public QObject
{
    Q_OBJECT

public:
    explicit AmqpWorker(QString deviceUUID, QObject *parent = nullptr);
    virtual ~AmqpWorker();

public slots:
    void initializeConnection(const QString hostname, const QString virtualHost, const int port, const QString username, const QString password);
    void onPublishNewMessage(const QString topicName, const QByteArray message);

private:
    void initializeQueues();

signals:
    void connectionStatusChanged(const bool connected);

private:
    QString m_deviceUUID;
    QScopedPointer<QAmqpClient> m_amqpClient;
    QScopedPointer<QAmqpExchange> m_amqpExchange;
    QScopedPointer<QMap<QString, QAmqpQueue *>> m_queuesMap;
};



class AmqpClient : public QObject
{
    Q_OBJECT

public:
    explicit AmqpClient(QString deviceUUID, QObject *parent = nullptr);
    virtual ~AmqpClient();

    void registerQmlClient(QQmlContext* ctxt);

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

#endif // AMQPCLIENT_HPP
