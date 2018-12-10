#include "MqttClient.hpp"

#include <QDebug>
#include <QString>
#include <QQmlContext>
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
    const auto pubMessage = QString("xVal:" + QString::number(xValue) + ";yVal:" + QString::number(yValue) +";zVal:" + QString::number(zValue));
    emit publishNewMessage(ACCELEROMETER, pubMessage.toUtf8());
}

void MqttClient::sendAmbientLightTelemetry(const int lightLevel)
{
    const auto pubMessage = QString("lightLevel:" + QString::number(lightLevel));
    emit publishNewMessage(AMBIENT_LIGHT, pubMessage.toUtf8());
}

void MqttClient::sendCompassTelemetry(const qreal azimuth, const qreal calibrationLevel)
{
    const auto pubMessage = QString("azimuth:" + QString::number(azimuth) + ";calibrationLevel:" + QString::number(calibrationLevel));
    emit publishNewMessage(COMPASS, pubMessage.toUtf8());
}

void MqttClient::sendLightTelemetry(const qreal luxValue)
{
    const auto pubMessage = QString("luxValue:" + QString::number(luxValue));
    emit publishNewMessage(LIGHT, pubMessage.toUtf8());
}

void MqttClient::sendMagnetometerTelemetry(const qreal xFlux, const qreal yFlux, const qreal zFlux, const qreal calibrationLevel)
{
    const auto pubMessage = QString("xFlux:" + QString::number(xFlux) + ";yFlux:" + QString::number(yFlux) + ";zFlux:" + QString::number(zFlux) + ";calibrationLevel:" + QString::number(calibrationLevel));
    emit publishNewMessage(MAGNETOMETER, pubMessage.toUtf8());
}

void MqttClient::sendOrientationTelemetry(const int orientation)
{
    const auto pubMessage = QString("orientation:" + QString::number(orientation));
    emit publishNewMessage(ORIENTATION, pubMessage.toUtf8());
}

void MqttClient::sendProximityTelemetry(const bool close)
{
    const auto pubMessage = QString("close:" + QString(close ? "true" : "false"));
    emit publishNewMessage(PROXIMITY, pubMessage.toUtf8());
}

void MqttClient::sendTiltTelemetry(const qreal xRotation, const qreal yRotation)
{
    const auto pubMessage = QString("xRotation:" + QString::number(xRotation) + ";yRotation:" + QString::number(yRotation));
    emit publishNewMessage(TILT, pubMessage.toUtf8());
}

void MqttClient::sendRotationTelemetry(const qreal xValue, const qreal yValue, const qreal zValue)
{
    const auto pubMessage = QString("xVal:" + QString::number(xValue) + ";yVal:" + QString::number(yValue) +";zVal:" + QString::number(zValue));
    emit publishNewMessage(ROTATION, pubMessage.toUtf8());
}

void MqttClient::sendGyroscopeTelemetry(const qreal xValue, const qreal yValue, const qreal zValue)
{
    const auto pubMessage = QString("xVal:" + QString::number(xValue) + ";yVal:" + QString::number(yValue) +";zVal:" + QString::number(zValue));
    emit publishNewMessage(GYROSCOPE, pubMessage.toUtf8());
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
