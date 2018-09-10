#include "RegisterUserRequest.hpp"

RegisterUserRequest::RegisterUserRequest(QNetworkAccessManager &networkManager, QObject *parent) :
    AbstractWebRequest(networkManager, QLatin1String("/api/v1/user/register"), QLatin1String("RegisterUserRequest"), parent)
{

}

RegisterUserRequest::~RegisterUserRequest()
{

}

void RegisterUserRequest::postRegisterUser(const QByteArray &requestContent)
{
    post(requestContent);
}

void RegisterUserRequest::hookSignals(const QObject *targetObject) const
{
    if(nullptr == targetObject)
    {
        qWarning()<<"ERROR: targetObject == nullptr";
    }
    else
    {
        if(!connect(this, SIGNAL(registerUserResponse(bool)), targetObject, SLOT(onRegisterUserResponse(bool))))
        {
            qWarning()<<"ERROR: Could not connect registerUserResponse";
        }
    }
}

void RegisterUserRequest::networkResponse(const QNetworkReply::NetworkError &status, const int httpCode)
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
    emit registerUserResponse(succeed);
}
