#ifndef RESTAPICLIENT_HPP
#define RESTAPICLIENT_HPP

#include <QObject>

class RestApiClient : public QObject
{
    Q_OBJECT
public:
    explicit RestApiClient(QObject *parent = nullptr);
    virtual ~RestApiClient();

    Q_INVOKABLE void registerDevice(const QString deviceName);
};

#endif // RESTAPICLIENT_HPP
