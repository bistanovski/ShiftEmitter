#ifndef RECEPTORINFO_HPP
#define RECEPTORINFO_HPP

#include <QMap>
#include <QObject>
#include <QJsonObject>

auto receptorTypeToFriendlyName(const QByteArray &type);
auto readingsPerReceptor(const QByteArray &type);

typedef QMap<QString, QPair<QString, QString>> ReadingsMap;

class ReceptorInfo : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QByteArray receptorType READ getType NOTIFY typeChanged)
    Q_PROPERTY(QByteArray receptorIdentifier READ getIdentifier NOTIFY identifierChanged)
    Q_PROPERTY(QString friendlyName READ getFriendlyName NOTIFY friendlyNameChanged)

public:
    explicit ReceptorInfo(const QByteArray &type, const QByteArray &identifier, QObject *parent = nullptr);
    virtual ~ReceptorInfo();

    QByteArray getType() const;
    QByteArray getIdentifier() const;
    QString getFriendlyName() const;
    const ReadingsMap &getReadings() const;

    Q_INVOKABLE QJsonObject toJson() const;

signals:
    void typeChanged();
    void identifierChanged();
    void friendlyNameChanged();

private:
    QByteArray m_type;
    QByteArray m_identifier;
    QString m_friendlyName;
    ReadingsMap m_receptorReadings;
};

#endif // RECEPTORINFO_HPP
