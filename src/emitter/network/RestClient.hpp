#ifndef RESTCLIENT_HPP
#define RESTCLIENT_HPP

#include <QObject>
#include <QNetworkAccessManager>

class QQmlContext;

class RestClient : public QObject
{
    Q_OBJECT
public:
    explicit RestClient(QObject *parent = nullptr);
    virtual ~RestClient();

    void registerQmlRestClient(QQmlContext *ctxt);

    Q_INVOKABLE void registerUser(QByteArray requestContent);
    Q_INVOKABLE void registerDevice(QByteArray requestContent);

private slots:
    void onRegisterUserResponse(bool succeed);
    void onRegisterDeviceResponse(bool succeed);

signals:
    void registerUserResponse(bool succeed, QByteArray data);
    void registerDeviceResponse(bool succeed, QByteArray data);

private:
    QNetworkAccessManager m_networkManager;
};

#endif // RESTCLIENT_HPP
