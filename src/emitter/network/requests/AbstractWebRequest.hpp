#ifndef ABSTRACTWEBREQUEST_HPP
#define ABSTRACTWEBREQUEST_HPP

#include <QTimer>
#include <QNetworkReply>
#include <QScopedPointer>
#include <QNetworkRequest>
#include <QNetworkAccessManager>

class QObject;
class QNetworkProxy;
class QAuthenticator;

enum class Method:int
{
    UNSET_METHOD,GET,POST,HEAD
};

class AbstractWebRequest : public QObject
{
    Q_OBJECT
public:
    explicit AbstractWebRequest(QNetworkAccessManager &manager, const QString &urlApiPath, const QString &signature, QObject *parent = nullptr);
    virtual ~AbstractWebRequest();

    QString getErrString() const;
    QUrl getURL() const;

    int getHTTPCode() const;
    QString signature() const;

    QByteArray readReplyData();

protected:
    void get();
    void post(const QByteArray &m_outData);

    virtual void networkResponse(const QNetworkReply::NetworkError & status, const int httpCode) = 0;

private:
    void sendRequest();
    void hookReplySignals() const;
    void processResponse();

private slots:
    void onReplyFinished();
    void onReplyError(QNetworkReply::NetworkError);

private:
    QNetworkAccessManager &m_networkManager;
    const QString m_urlPath;
    const QString m_signature;

    Method m_method {Method::UNSET_METHOD};
    QUrl m_hostUrl;
    QByteArray m_outData;
    QNetworkRequest m_request;
    QScopedPointer<QNetworkReply> m_reply;

    bool m_completed {false};
    int m_httpErrorCode {0};
    QString m_errorString;

    bool m_wasProcessed {false};
};

#endif // ABSTRACTWEBREQUEST_HPP
