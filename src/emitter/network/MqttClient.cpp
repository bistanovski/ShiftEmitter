#include "MqttClient.hpp"

#include <QDebug>
#include <QString>
#include <QQmlContext>
#include <QJsonDocument>
#include "ShiftSettings.hpp"
#include "receptor-bridge/receptors/Receptor.hpp"

const auto PROXIMITY = QStringLiteral("Proximity");
const auto TILT = QStringLiteral("Tilt");
const auto AMBIENT_LIGHT = QStringLiteral("AmbientLight");
const auto LIGHT = QStringLiteral("Light");
const auto COMPASS = QStringLiteral("Compass");
const auto ACCELEROMETER = QStringLiteral("Accelerometer");
const auto MAGNETOMETER = QStringLiteral("Magnetometer");
const auto ORIENTATION = QStringLiteral("Orientation");
const auto ROTATION = QStringLiteral("Rotation");
const auto GYROSCOPE = QStringLiteral("Gyroscope");

MqttWorker::MqttWorker(QString deviceUUID, QObject *parent) : QObject(parent)
{
    m_topicsMap.insert(PROXIMITY, QMqttTopicName(deviceUUID + "_" + PROXIMITY));
    m_topicsMap.insert(TILT, QMqttTopicName(deviceUUID + "_" + TILT));
    m_topicsMap.insert(AMBIENT_LIGHT, QMqttTopicName(deviceUUID + "_" + AMBIENT_LIGHT));
    m_topicsMap.insert(LIGHT, QMqttTopicName(deviceUUID + "_" + LIGHT));
    m_topicsMap.insert(COMPASS, QMqttTopicName(deviceUUID + "_" + COMPASS));
    m_topicsMap.insert(ACCELEROMETER, QMqttTopicName(deviceUUID + "_" + ACCELEROMETER));
    m_topicsMap.insert(MAGNETOMETER, QMqttTopicName(deviceUUID + "_" + MAGNETOMETER));
    m_topicsMap.insert(ORIENTATION, QMqttTopicName(deviceUUID + "_" + ORIENTATION));
    m_topicsMap.insert(ROTATION, QMqttTopicName(deviceUUID + "_" + ROTATION));
    m_topicsMap.insert(GYROSCOPE, QMqttTopicName(deviceUUID + "_" + GYROSCOPE));
}

MqttWorker::~MqttWorker()
{
    qDebug() << "~MqttWorker";
}

void MqttWorker::initializeConnection(const QString brokerHost, const int brokerPort, const QString username, const QString password)
{
    m_mqttCLient.reset(new QMqttClient());
    m_mqttCLient->setHostname(brokerHost);
    m_mqttCLient->setPort(static_cast<quint16>(brokerPort));
    m_mqttCLient->setUsername(username);
    m_mqttCLient->setPassword(password);

    QObject::connect(m_mqttCLient.data(), &QMqttClient::stateChanged, [](QMqttClient::ClientState state){
        qDebug() << "Telemetry state changed: " << state;
    });
    QObject::connect(m_mqttCLient.data(), &QMqttClient::disconnected, [this](){
        qDebug() << "Telemetry client disconnected!";
        emit connectionStatusChanged(false);
    });
    QObject::connect(m_mqttCLient.data(), &QMqttClient::connected, [this](){
        qDebug() << "Telemetry client connected!";
        emit connectionStatusChanged(true);
    });

    m_mqttCLient->connectToHost();
}

void MqttWorker::onPublishNewMessage(const QString topicName, const QByteArray message)
{
    m_mqttCLient->publish(m_topicsMap[topicName], message);
}


MqttClient::MqttClient(QString deviceUUID, QObject *parent) : QObject(parent)
{
    ShiftSettings settings;
    MqttWorker *worker = new MqttWorker(deviceUUID);
    connect(worker, &MqttWorker::connectionStatusChanged, this, &MqttClient::setConnectedToServer);
    connect(this, &MqttClient::publishNewMessage, worker, &MqttWorker::onPublishNewMessage);
    connect(&m_workerThread, &QThread::started, [&settings, worker](){
        worker->initializeConnection(settings.getTelemetryHost(),
                                     settings.getTelemetryPort(),
                                     settings.getTelemetryUsername(),
                                     settings.getTelemetryPassword()
                                     );
    });
    connect(&m_workerThread, &QThread::finished, worker, &MqttClient::deleteLater);
    worker->moveToThread(&m_workerThread);
    m_workerThread.setObjectName("MqttWorker");
    m_workerThread.start();
}

MqttClient::~MqttClient()
{
    m_workerThread.exit();
    m_workerThread.wait(1000);
}

void MqttClient::registerQmlTransporter(QQmlContext *ctxt)
{
    ctxt->setContextProperty("MqttClient", this);
}

void MqttClient::sendAccelerometerTelemetry(const qreal xValue, const qreal yValue, const qreal zValue)
{
    QVariantMap map;
    map["xVal"] = xValue;
    map["yVal"] = yValue;
    map["zVal"] = zValue;
    emit publishNewMessage(ACCELEROMETER, QJsonDocument::fromVariant(map).toJson());
}

void MqttClient::sendAmbientLightTelemetry(const int lightLevel)
{
    QVariantMap map;
    map["lightLevel"] = lightLevel;
    emit publishNewMessage(AMBIENT_LIGHT, QJsonDocument::fromVariant(map).toJson());
}

void MqttClient::sendCompassTelemetry(const qreal azimuth, const qreal calibrationLevel)
{
    QVariantMap map;
    map["azimuth"] = azimuth;
    map["calibrationLevel"] = calibrationLevel;
    emit publishNewMessage(COMPASS, QJsonDocument::fromVariant(map).toJson());
}

void MqttClient::sendLightTelemetry(const qreal luxValue)
{
    QVariantMap map;
    map["luxValue"] = luxValue;
    emit publishNewMessage(LIGHT, QJsonDocument::fromVariant(map).toJson());
}

void MqttClient::sendMagnetometerTelemetry(const qreal xFlux, const qreal yFlux, const qreal zFlux, const qreal calibrationLevel)
{
    QVariantMap map;
    map["xFlux"] = xFlux;
    map["yFlux"] = yFlux;
    map["zFlux"] = zFlux;
    map["calibrationLevel"] = QString::number(calibrationLevel);
    emit publishNewMessage(MAGNETOMETER, QJsonDocument::fromVariant(map).toJson());
}

void MqttClient::sendOrientationTelemetry(const int orientation)
{
    QVariantMap map;
    map["orientation"] = orientation;
    emit publishNewMessage(ORIENTATION, QJsonDocument::fromVariant(map).toJson());
}

void MqttClient::sendProximityTelemetry(const bool close)
{
    QVariantMap map;
    map["close"] = close;
    emit publishNewMessage(PROXIMITY, QJsonDocument::fromVariant(map).toJson());
}

void MqttClient::sendTiltTelemetry(const qreal xRotation, const qreal yRotation)
{
    QVariantMap map;
    map["xRotation"] = xRotation;
    map["yRotation"] = yRotation;
    emit publishNewMessage(TILT, QJsonDocument::fromVariant(map).toJson());
}

void MqttClient::sendRotationTelemetry(const qreal xValue, const qreal yValue, const qreal zValue)
{
    QVariantMap map;
    map["xVal"] = xValue;
    map["yVal"] = yValue;
    map["zVal"] = zValue;
    emit publishNewMessage(ROTATION, QJsonDocument::fromVariant(map).toJson());
}

void MqttClient::sendGyroscopeTelemetry(const qreal xValue, const qreal yValue, const qreal zValue)
{
    QVariantMap map;
    map["xVal"] = xValue;
    map["yVal"] = yValue;
    map["zVal"] = zValue;
    emit publishNewMessage(GYROSCOPE, QJsonDocument::fromVariant(map).toJson());
}

bool MqttClient::connectedToServer() const
{
    return m_connectedToServer;
}

void MqttClient::setConnectedToServer(const bool connected)
{
    m_connectedToServer = connected;
    emit connectedToServerChanged();
}
