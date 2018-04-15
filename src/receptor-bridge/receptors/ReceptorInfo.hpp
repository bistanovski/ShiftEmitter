#ifndef RECEPTORINFO_HPP
#define RECEPTORINFO_HPP

#include <QObject>

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

signals:
    void typeChanged();
    void identifierChanged();
    void friendlyNameChanged();

private:
    QByteArray m_type;
    QByteArray m_identifier;
    QString m_friendlyName;
};

QString receptorTypeToFriendlyName(const QByteArray &type);

#endif // RECEPTORINFO_HPP
