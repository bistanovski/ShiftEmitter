#include "AmqpClient.hpp"

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

AmqpWorker::AmqpWorker(QObject *parent) : QObject(parent)
{

}

AmqpWorker::~AmqpWorker()
{
    qDebug() << "~AmqpWorker";
}

void AmqpWorker::initializeConnection(const QString hostname, const QString virtualHost, const int port, const QString username, const QString password)
{
    m_amqpClient.reset(new QAmqpClient());
    m_amqpClient->setHost(hostname);
    m_amqpClient->setVirtualHost(virtualHost);
    m_amqpClient->setPort(static_cast<quint16>(port));
    m_amqpClient->setUsername(username);
    m_amqpClient->setPassword(password);

    QObject::connect(m_amqpClient.data(), &QAmqpClient::connected, [this](){
        qDebug() << "AmqpClient connected!";
        emit connectionStatusChanged(true);

        m_amqpExchange.reset(m_amqpClient.data()->createExchange("SampleExchange"));
        QObject::connect(m_amqpExchange.data(), &QAmqpExchange::declared, [](){
            qDebug() << "Exchange declared!";
        });
        m_amqpExchange->declare(QAmqpExchange::ExchangeType::Topic, QAmqpExchange::ExchangeOption::Durable);

    });
    QObject::connect(m_amqpClient.data(), &QAmqpClient::disconnected, [this](){
        qDebug() << "AmqpClient disconnected!";
        emit connectionStatusChanged(false);
    });
    QObject::connect(m_amqpClient.data(), &QAmqpClient::heartbeat, [](){
        qDebug() << "AmqpClient hearbeat!";
    });

    QObject::connect(m_amqpClient.data(), QOverload<QAMQP::Error>::of(&QAmqpClient::error), [this](QAMQP::Error error){
        qDebug() << "AmqpClient error:" << error << " errorString:" << m_amqpClient.data()->errorString();
    });

    QObject::connect(m_amqpClient.data(), QOverload<QAbstractSocket::SocketError>::of(&QAmqpClient::socketError), [this](QAbstractSocket::SocketError error){
        qDebug() << "AmqpClient socket error:" << error << " errorString:" << m_amqpClient.data()->errorString();
    });

    m_amqpClient->connectToHost();
}

void AmqpWorker::onPublishNewMessage(const QString topicName, const QByteArray message)
{
    m_amqpExchange->publish(message, topicName);
}



AmqpClient::AmqpClient(QObject *parent) : QObject(parent)
{
    ShiftSettings settings;
    AmqpWorker *worker = new AmqpWorker();

    QObject::connect(worker, &AmqpWorker::connectionStatusChanged, this, &AmqpClient::setConnectedToServer);
    QObject::connect(this, &AmqpClient::publishNewMessage, worker, &AmqpWorker::onPublishNewMessage);
    QObject::connect(&m_workerThread, &QThread::finished, worker, &AmqpWorker::deleteLater);
    QObject::connect(&m_workerThread, &QThread::started, [&settings, worker](){
        worker->initializeConnection(settings.getTelemetryHost(),
                                     settings.getTelemetryVirtualHost(),
                                     settings.getTelemetryPort(),
                                     settings.getTelemetryUsername(),
                                     settings.getTelemetryPassword()
                                     );
    });

    worker->moveToThread(&m_workerThread);
    m_workerThread.setObjectName("AmqpWorker");
    m_workerThread.start();
}

AmqpClient::~AmqpClient()
{
    m_workerThread.exit();
    m_workerThread.wait(1000);
}

void AmqpClient::registerQmlClient(QQmlContext *ctxt)
{
    ctxt->setContextProperty("AmqpClient", this);
}

void AmqpClient::sendAccelerometerTelemetry(const qreal xValue, const qreal yValue, const qreal zValue)
{
    const auto pubMessage = QString("xVal:" + QString::number(xValue) + ";yVal:" + QString::number(yValue) +";zVal:" + QString::number(zValue));
    emit publishNewMessage(ACCELEROMETER, pubMessage.toUtf8());
}

void AmqpClient::sendAmbientLightTelemetry(const int lightLevel)
{
    const auto pubMessage = QString("lightLevel:" + QString::number(lightLevel));
    emit publishNewMessage(AMBIENT_LIGHT, pubMessage.toUtf8());
}

void AmqpClient::sendCompassTelemetry(const qreal azimuth, const qreal calibrationLevel)
{
    const auto pubMessage = QString("azimuth:" + QString::number(azimuth) + ";calibrationLevel:" + QString::number(calibrationLevel));
    emit publishNewMessage(COMPASS, pubMessage.toUtf8());
}

void AmqpClient::sendLightTelemetry(const qreal luxValue)
{
    const auto pubMessage = QString("luxValue:" + QString::number(luxValue));
    emit publishNewMessage(LIGHT, pubMessage.toUtf8());
}

void AmqpClient::sendMagnetometerTelemetry(const qreal xFlux, const qreal yFlux, const qreal zFlux, const qreal calibrationLevel)
{
    const auto pubMessage = QString("xFlux:" + QString::number(xFlux) + ";yFlux:" + QString::number(yFlux) + ";zFlux:" + QString::number(zFlux) + ";calibrationLevel:" + QString::number(calibrationLevel));
    emit publishNewMessage(MAGNETOMETER, pubMessage.toUtf8());
}

void AmqpClient::sendOrientationTelemetry(const int orientation)
{
    const auto pubMessage = QString("orientation:" + QString::number(orientation));
    emit publishNewMessage(ORIENTATION, pubMessage.toUtf8());
}

void AmqpClient::sendProximityTelemetry(const bool close)
{
    const auto pubMessage = QString("close:" + QString(close ? "true" : "false"));
    emit publishNewMessage(PROXIMITY, pubMessage.toUtf8());
}

void AmqpClient::sendTiltTelemetry(const qreal xRotation, const qreal yRotation)
{
    const auto pubMessage = QString("xRotation:" + QString::number(xRotation) + ";yRotation:" + QString::number(yRotation));
    emit publishNewMessage(TILT, pubMessage.toUtf8());
}

void AmqpClient::sendRotationTelemetry(const qreal xValue, const qreal yValue, const qreal zValue)
{
    const auto pubMessage = QString("xVal:" + QString::number(xValue) + ";yVal:" + QString::number(yValue) +";zVal:" + QString::number(zValue));
    emit publishNewMessage(ROTATION, pubMessage.toUtf8());
}

void AmqpClient::sendGyroscopeTelemetry(const qreal xValue, const qreal yValue, const qreal zValue)
{
    const auto pubMessage = QString("xVal:" + QString::number(xValue) + ";yVal:" + QString::number(yValue) +";zVal:" + QString::number(zValue));
    emit publishNewMessage(GYROSCOPE, pubMessage.toUtf8());
}

bool AmqpClient::connectedToServer() const
{
    return m_connectedToServer;
}

void AmqpClient::setConnectedToServer(const bool connected)
{
    m_connectedToServer = connected;
    emit connectedToServerChanged();
}
