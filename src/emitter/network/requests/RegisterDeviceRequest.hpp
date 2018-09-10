#ifndef REGISTERDEVICEREQUEST_HPP
#define REGISTERDEVICEREQUEST_HPP

#include "AbstractWebRequest.hpp"

class RegisterDeviceRequest : public AbstractWebRequest
{
    Q_OBJECT

public:
    explicit RegisterDeviceRequest(QNetworkAccessManager &networkManager, QObject *parent = nullptr);
    virtual ~RegisterDeviceRequest();

    void postRegisterDevice(const QByteArray &requestContent);
    void hookSignals(const QObject *targetObject) const;

protected:
    virtual void networkResponse(const QNetworkReply::NetworkError & status, const int httpCode) override;

signals:
    void registerDeviceResponse(bool succeed);
};

#endif // REGISTERDEVICEREQUEST_HPP
