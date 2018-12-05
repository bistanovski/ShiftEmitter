#include "AbstractWebRequest.hpp"

const QString APPLICATION_DATA_JSON = QLatin1String("application/json");

AbstractWebRequest::AbstractWebRequest(QNetworkAccessManager &manager, const QString &urlApiPath, const QString &signature, QObject *parent) : QObject(parent),
    m_networkManager(manager),
    m_urlPath(urlApiPath),
    m_signature(QLatin1String("AWR ") + signature)
{
    m_hostUrl.setScheme(QLatin1String("http"));
    m_hostUrl.setHost(QLatin1String("localhost"));
    m_hostUrl.setPort(8000);

    if(m_urlPath.isEmpty())
    {
        qWarning() << "AWR: ERROR: urlPath is empty";
    }

    m_hostUrl.setPath(m_urlPath);
    m_request.setUrl(m_hostUrl);
    qDebug() << "AWR: Final URL PATH: " << m_hostUrl;
}

AbstractWebRequest::~AbstractWebRequest()
{

}

QString AbstractWebRequest::getErrString() const
{
    return m_errorString;
}

QUrl AbstractWebRequest::getURL() const
{
    return m_hostUrl;
}

int AbstractWebRequest::getHTTPCode() const
{
    return m_httpErrorCode;
}

QString AbstractWebRequest::signature() const
{
    return m_signature;
}

QByteArray AbstractWebRequest::readReplyData()
{
    if(!m_reply.isNull())
    {
        return m_reply->readAll();
    }
    return QByteArray();
}

void AbstractWebRequest::get()
{
    if(Method::UNSET_METHOD != m_method)
    {
        qWarning()<< "ERROR: WebRequest is not mutable. Aborting second call to sendRequest";
        return;
    }
    m_method = Method::GET;
    sendRequest();
}

#include <QJsonDocument>

void AbstractWebRequest::post(const QByteArray &out)
{
    if(Method::UNSET_METHOD != m_method)
    {
        qWarning() << "AWR: ERROR: WebRequest is not mutable. Aborting second call to sendRequest";
        return;
    }
    qDebug().noquote() << "DATA:" << QJsonDocument::fromJson(out).toJson(QJsonDocument::Indented);
    this->m_outData = out;
    m_method = Method::POST;
    sendRequest();
}

void AbstractWebRequest::sendRequest()
{
    m_completed = false;
    m_request.setHeader(QNetworkRequest::KnownHeaders::UserAgentHeader, QVariant("ShiftEmitter"));

    switch(m_method)
    {
        case(Method::HEAD):
        {
            m_reply.reset(m_networkManager.head(m_request));
        }break;
        case(Method::GET):
        {
            m_reply.reset(m_networkManager.get(m_request));
        }break;
        case(Method::POST):
        {
            m_request.setHeader(QNetworkRequest::KnownHeaders::ContentTypeHeader, APPLICATION_DATA_JSON);
            m_reply.reset(m_networkManager.post(m_request, m_outData));
        }break;

        case(Method::UNSET_METHOD):
        {
            qWarning() << signature() << "AWR: ERROR: method UNSET";
            m_reply.reset();
        }return;
    }

    if(!m_reply.isNull())
    {
        hookReplySignals();
    }
    else
    {
        qWarning() << signature() << "AWR: ERROR: no reply object";
    }
}

void AbstractWebRequest::hookReplySignals() const
{
    if(!connect(m_reply.data(), SIGNAL(finished()), this, SLOT(onReplyFinished())))
    {
        qWarning() << signature() <<"AWR: ERROR: Could not connect reply finished";
    }
    if(!connect(m_reply.data(), SIGNAL(error(QNetworkReply::NetworkError)),this, SLOT(onReplyError(QNetworkReply::NetworkError))))
    {
        qWarning() << signature() <<"AWR: ERROR: Could not connect reply error";
    }
}

void AbstractWebRequest::processResponse()
{
    if(m_wasProcessed)
    {
        return;
    }
    else
    {
        m_wasProcessed = true;
    }

    if(m_completed)
    {
        qWarning() << signature() << "ERROR: Double complete detected";
    }
    else
    {
        m_completed = true;
        if(!m_reply.isNull())
        {
            const auto statusCode = m_reply->attribute(QNetworkRequest::HttpStatusCodeAttribute );
            m_httpErrorCode = statusCode.isValid() ? statusCode.toInt() : 0;
            m_errorString = m_reply->errorString();

            //Propagate response to children
            networkResponse(m_reply->error(), m_httpErrorCode);

            if (QNetworkReply::NoError != m_reply->error())
            {
                qWarning()<< signature() << "AWR: ERROR: " << m_errorString << " HTTP Code:" << m_httpErrorCode;
            }
            else
            {
                qDebug()<< signature() << "AWR: ENDED WITH NO ERROR" << "HTTP:" << m_httpErrorCode;
            }
            m_reply.reset();
        }
        else
        {
            qWarning()<< signature()<<"AWR: ERROR: nullptr == reply";
        }
    }
}

void AbstractWebRequest::onReplyFinished()
{
    processResponse();
}

void AbstractWebRequest::onReplyError(QNetworkReply::NetworkError)
{
    processResponse();
}
