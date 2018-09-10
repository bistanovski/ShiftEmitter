#include "RegisterDeviceRequest.hpp"

RegisterDeviceRequest::RegisterDeviceRequest(QNetworkAccessManager &networkManager, QObject *parent) :
    AbstractWebRequest(networkManager, QLatin1String("/api/v1/device/register"), QLatin1String("RegisterDeviceRequest"), parent)
{

}

RegisterDeviceRequest::~RegisterDeviceRequest()
{

}

void RegisterDeviceRequest::postRegisterDevice(const QByteArray &requestContent)
{
    post(requestContent);
}

void RegisterDeviceRequest::hookSignals(const QObject *targetObject) const
{
    if(nullptr == targetObject)
    {
        qWarning()<<"ERROR: targetObject == nullptr";
    }
    else
    {
        if(!connect(this, SIGNAL(registerDeviceResponse(bool)), targetObject, SLOT(onRegisterDeviceResponse(bool))))
        {
            qWarning()<<"ERROR: Could not connect registerDeviceResponse";
        }
    }
}

void RegisterDeviceRequest::networkResponse(const QNetworkReply::NetworkError &status, const int httpCode)
{
    auto succeed = false;
    if(QNetworkReply::NoError == status)
    {
        succeed = true;
    }
    else
    {
        qWarning() << "RDR: WARNING:" << status << "=" << getErrString() << "HTTP Code:" << httpCode;
        succeed = false;
    }
    emit registerDeviceResponse(succeed);
}
