#ifndef REGISTERUSERREQUEST_HPP
#define REGISTERUSERREQUEST_HPP

#include "AbstractWebRequest.hpp"

class RegisterUserRequest : public AbstractWebRequest
{
    Q_OBJECT

public:
    explicit RegisterUserRequest(QNetworkAccessManager &networkManager, QObject *parent = nullptr);
    virtual ~RegisterUserRequest();

    void postRegisterUser(const QByteArray &requestContent);
    void hookSignals(const QObject *targetObject) const;

protected:
    virtual void networkResponse(const QNetworkReply::NetworkError & status, const int httpCode) override;

signals:
    void registerUserResponse(bool succeed);
};

#endif // REGISTERUSERREQUEST_HPP
