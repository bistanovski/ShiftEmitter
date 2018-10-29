#include "TelemetryTransporter.hpp"

#include <QString>
#include <QQmlContext>
#include "ShiftSettings.hpp"
#include "receptor-bridge/receptors/Receptor.hpp"

QString TransportWorker::PROXIMITY = QStringLiteral("Proximity");
QString TransportWorker::TILT = QStringLiteral("Tilt");
QString TransportWorker::AMBIENT_LIGHT = QStringLiteral("AmbientLight");
QString TransportWorker::LIGHT = QStringLiteral("Light");
QString TransportWorker::COMPASS = QStringLiteral("Compass");
QString TransportWorker::ACCELEROMETER = QStringLiteral("Accelerometer");
QString TransportWorker::MAGNETOMETER = QStringLiteral("Magnetometer");
QString TransportWorker::ORIENTATION = QStringLiteral("Orientation");
QString TransportWorker::ROTATION = QStringLiteral("Rotation");
QString TransportWorker::GYROSCOPE = QStringLiteral("Gyroscope");

TransportWorker::TransportWorker(QObject *parent) : QObject(parent)
{
    m_topicsMap.insert(PROXIMITY, QMqttTopicName(PROXIMITY));
    m_topicsMap.insert(TILT, QMqttTopicName(TILT));
    m_topicsMap.insert(AMBIENT_LIGHT, QMqttTopicName(AMBIENT_LIGHT));
    m_topicsMap.insert(LIGHT, QMqttTopicName(LIGHT));
    m_topicsMap.insert(COMPASS, QMqttTopicName(COMPASS));
    m_topicsMap.insert(ACCELEROMETER, QMqttTopicName(ACCELEROMETER));
    m_topicsMap.insert(MAGNETOMETER, QMqttTopicName(MAGNETOMETER));
    m_topicsMap.insert(ORIENTATION, QMqttTopicName(ORIENTATION));
    m_topicsMap.insert(ROTATION, QMqttTopicName(ROTATION));
    m_topicsMap.insert(GYROSCOPE, QMqttTopicName(GYROSCOPE));
}

TransportWorker::~TransportWorker()
{

}

void TransportWorker::initializeConnection(const QString brokerHost, const int brokerPort)
{
    m_mqttCLient.reset(new QMqttClient());
    m_mqttCLient->setHostname(brokerHost);
    m_mqttCLient->setPort(static_cast<quint16>(brokerPort));
    m_mqttCLient->setUsername("test");
    m_mqttCLient->setPassword("test");

    QObject::connect(m_mqttCLient.data(), &QMqttClient::stateChanged, [](QMqttClient::ClientState state){
        qDebug() << "State Changed: " << state;
    });
    QObject::connect(m_mqttCLient.data(), &QMqttClient::disconnected, [this](){
        qDebug() << "CLIENT DISCONNECTED";
        emit connectionStatusChanged(false);
    });
    QObject::connect(m_mqttCLient.data(), &QMqttClient::connected, [this](){
        qDebug() << "CLIENT CONNECTED!!!!";
        emit connectionStatusChanged(true);
    });

    m_mqttCLient->connectToHost();
}

void TransportWorker::onPublishNewMessage(const QString topicName, const QByteArray message)
{
    QMqttTopicName topic = m_topicsMap.value(topicName);
    m_mqttCLient->publish(m_topicsMap.value(topicName), message);
}


TelemetryTransporter::TelemetryTransporter(QObject *parent) : QObject(parent)
{
    ShiftSettings settings;
    TransportWorker *worker = new TransportWorker();
    connect(worker, &TransportWorker::connectionStatusChanged, this, &TelemetryTransporter::setConnectedToServer);
    connect(this, &TelemetryTransporter::publishNewMessage, worker, &TransportWorker::onPublishNewMessage);
    connect(&m_workerThread, &QThread::started, [&settings, worker](){
        worker->initializeConnection(settings.getTelemetryHost(), settings.getTelemetryPort());
    });
    worker->moveToThread(&m_workerThread);
    m_workerThread.start();
}

TelemetryTransporter::~TelemetryTransporter()
{
    m_workerThread.exit();
    m_workerThread.wait(1000);
}

void TelemetryTransporter::registerQmlTransporter(QQmlContext *ctxt)
{
    ctxt->setContextProperty("TelemetryTransporter", this);
}

void TelemetryTransporter::sendAccelerometerTelemetry(const qreal xValue, const qreal yValue, const qreal zValue)
{
    const auto pubMessage = QString("xVal:" + QString::number(xValue) + ";yVal:" + QString::number(yValue) +";zVal:" + QString::number(zValue));
    emit publishNewMessage(TransportWorker::ACCELEROMETER, pubMessage.toUtf8());
}

void TelemetryTransporter::sendAmbientLightTelemetry(const int lightLevel)
{
    const auto pubMessage = QString("lightLevel:" + QString::number(lightLevel));
    emit publishNewMessage(TransportWorker::AMBIENT_LIGHT, pubMessage.toUtf8());
}

void TelemetryTransporter::sendCompassTelemetry(const qreal azimuth, const qreal calibrationLevel)
{
    const auto pubMessage = QString("azimuth:" + QString::number(azimuth) + ";calibrationLevel:" + QString::number(calibrationLevel));
    emit publishNewMessage(TransportWorker::COMPASS, pubMessage.toUtf8());
}

void TelemetryTransporter::sendLightTelemetry(const qreal luxValue)
{
    const auto pubMessage = QString("luxValue:" + QString::number(luxValue));
    emit publishNewMessage(TransportWorker::LIGHT, pubMessage.toUtf8());
}

void TelemetryTransporter::sendMagnetometerTelemetry(const qreal xFlux, const qreal yFlux, const qreal zFlux, const qreal calibrationLevel)
{
    const auto pubMessage = QString("xFlux:" + QString::number(xFlux) + ";yFlux:" + QString::number(yFlux) + ";zFlux:" + QString::number(zFlux) + ";calibrationLevel:" + QString::number(calibrationLevel));
    emit publishNewMessage(TransportWorker::MAGNETOMETER, pubMessage.toUtf8());
}

void TelemetryTransporter::sendOrientationTelemetry(const int orientation)
{
    const auto pubMessage = QString("orientation:" + QString::number(orientation));
    emit publishNewMessage(TransportWorker::ORIENTATION, pubMessage.toUtf8());
}

void TelemetryTransporter::sendProximityTelemetry(const bool close)
{
    const auto pubMessage = QString("close:" + QString(close ? "true" : "false"));
    emit publishNewMessage(TransportWorker::PROXIMITY, pubMessage.toUtf8());
}

void TelemetryTransporter::sendTiltTelemetry(const qreal xRotation, const qreal yRotation)
{
    const auto pubMessage = QString("xRotation:" + QString::number(xRotation) + ";yRotation:" + QString::number(yRotation));
    emit publishNewMessage(TransportWorker::TILT, pubMessage.toUtf8());
}

void TelemetryTransporter::sendRotationTelemetry(const qreal xValue, const qreal yValue, const qreal zValue)
{
    const auto pubMessage = QString("xVal:" + QString::number(xValue) + ";yVal:" + QString::number(yValue) +";zVal:" + QString::number(zValue));
    emit publishNewMessage(TransportWorker::ROTATION, pubMessage.toUtf8());
}

void TelemetryTransporter::sendGyroscopeTelemetry(const qreal xValue, const qreal yValue, const qreal zValue)
{
    const auto pubMessage = QString("xVal:" + QString::number(xValue) + ";yVal:" + QString::number(yValue) +";zVal:" + QString::number(zValue));
    emit publishNewMessage(TransportWorker::GYROSCOPE, pubMessage.toUtf8());
}

bool TelemetryTransporter::connectedToServer() const
{
    return m_connectedToServer;
}

void TelemetryTransporter::setConnectedToServer(const bool connected)
{
    m_connectedToServer = connected;
    emit connectedToServerChanged();
}
