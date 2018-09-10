#include "RestClient.hpp"
#include "requests/RegisterUserRequest.hpp"
#include "requests/RegisterDeviceRequest.hpp"

#include <QQmlContext>

RestClient::RestClient(QObject *parent) : QObject(parent)
{

}

RestClient::~RestClient()
{

}

void RestClient::registerQmlRestClient(QQmlContext *ctxt)
{
    ctxt->setContextProperty("RestClient", this);
}

void RestClient::registerUser(QByteArray requestContent)
{
    auto *registerUserRequest = new RegisterUserRequest(m_networkManager, this);
    registerUserRequest->hookSignals(this);
    registerUserRequest->postRegisterUser(requestContent);
}

void RestClient::registerDevice(QByteArray requestContent)
{
    auto *registerDeviceRequest = new RegisterDeviceRequest(m_networkManager, this);
    registerDeviceRequest->hookSignals(this);
    registerDeviceRequest->postRegisterDevice(requestContent);
}

void RestClient::onRegisterUserResponse(bool succeed)
{
    auto *registerUserRequest = qobject_cast<RegisterUserRequest *>(QObject::sender());
    if(nullptr != registerUserRequest)
    {
        emit registerUserResponse(succeed, registerUserRequest->readReplyData());
        registerUserRequest->deleteLater();
    }
}

void RestClient::onRegisterDeviceResponse(bool succeed)
{
    auto *registerDeviceRequest = qobject_cast<RegisterDeviceRequest *>(QObject::sender());
    if(nullptr != registerDeviceRequest)
    {
        emit registerDeviceResponse(succeed, registerDeviceRequest->readReplyData());
        registerDeviceRequest->deleteLater();
    }
}
