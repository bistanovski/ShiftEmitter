#ifndef RECEPTOR_HPP
#define RECEPTOR_HPP

#include <QObject>

class QSensorReading;

class Receptor : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QByteArray receptorType READ getType WRITE setType NOTIFY typeChanged)
    Q_PROPERTY(QByteArray receptorIdentifier READ getIdentifier WRITE setIdentifier NOTIFY identifierChanged)
    Q_PROPERTY(QString friendlyName READ getFriendlyName WRITE setFriendlyName NOTIFY friendlyNameChanged)

public:
    explicit Receptor(QObject *parent = nullptr) : QObject(parent) {}
    virtual ~Receptor() {}

    inline QByteArray getType() const { return m_type; }
    inline void setType(const QByteArray &type) { m_type = type; emit typeChanged(); }

    inline QByteArray getIdentifier() const { return m_identifier; }
    inline void setIdentifier(const QByteArray &identifier) { m_identifier = identifier; emit identifierChanged(); }

    inline QString getFriendlyName() const { return m_friendlyName; }
    inline void setFriendlyName(const QString &name) { m_friendlyName = name; emit friendlyNameChanged(); }

    Q_INVOKABLE virtual void connectReceptor() = 0;
    Q_INVOKABLE virtual void startListening() = 0;

    virtual QSensorReading *reading() const = 0;

signals:
    void typeChanged();
    void identifierChanged();
    void friendlyNameChanged();
    void readingChanged();

protected:
    QByteArray m_type;
    QByteArray m_identifier;
    QString m_friendlyName;
};

#endif // RECEPTOR_HPP
