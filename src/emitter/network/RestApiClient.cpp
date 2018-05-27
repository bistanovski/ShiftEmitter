#include "RestApiClient.hpp"

#include <QDebug>
#include "ShiftSettings.hpp"

RestApiClient::RestApiClient(QObject *parent) : QObject(parent)
{

}

RestApiClient::~RestApiClient()
{

}

void RestApiClient::registerDevice(const QString deviceName)
{
    ShiftSettings settings;
    qDebug() << "DN:" << deviceName
             << "UUID:" << settings.getDeviceUUID()
             << "OSN:" << settings.getOSName()
             << "OSV:" << settings.getOSVersion();
}
