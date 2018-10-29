#ifndef RECEPTOR_HPP
#define RECEPTOR_HPP

#include <QObject>

class Receptor : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QByteArray receptorType READ getType WRITE setType NOTIFY typeChanged)
    Q_PROPERTY(QByteArray receptorIdentifier READ getIdentifier WRITE setIdentifier NOTIFY identifierChanged)
    Q_PROPERTY(QString friendlyName READ getFriendlyName WRITE setFriendlyName NOTIFY friendlyNameChanged)
    Q_PROPERTY(bool connectedToBackend READ isConnectedToBackend WRITE setConnectedToBackend NOTIFY connectedToBackendChanged)
    Q_PROPERTY(bool listening READ isListening WRITE setIsListening NOTIFY listeningChanged)

public:
    explicit Receptor(QObject *parent = nullptr) : QObject(parent) {}
    virtual ~Receptor() {}

    inline QByteArray getType() const { return m_type; }
    inline void setType(const QByteArray &type) { m_type = type; emit typeChanged(); }

    inline QByteArray getIdentifier() const { return m_identifier; }
    inline void setIdentifier(const QByteArray &identifier) { m_identifier = identifier; emit identifierChanged(); }

    inline QString getFriendlyName() const { return m_friendlyName; }
    inline void setFriendlyName(const QString &name) { m_friendlyName = name; emit friendlyNameChanged(); }

    inline bool isConnectedToBackend() const { return m_isConnectedToBackend; }
    inline void setConnectedToBackend(const bool &connected) { m_isConnectedToBackend = connected; emit connectedToBackendChanged(); }

    inline bool isListening() const { return m_isListening; }
    inline void setIsListening(const bool &listening) { m_isListening = listening; emit listeningChanged(); }

    Q_INVOKABLE virtual void connectReceptor() = 0;
    Q_INVOKABLE virtual void startListening() = 0;
    Q_INVOKABLE virtual void stopListening() = 0;

private slots:
    virtual void onReadingChanged() = 0;

signals:
    void typeChanged();
    void identifierChanged();
    void friendlyNameChanged();
    void connectedToBackendChanged();
    void listeningChanged();

protected:
    QByteArray m_type;
    QByteArray m_identifier;
    QString m_friendlyName;
    bool m_isConnectedToBackend = false;
    bool m_isListening = false;
};

#endif // RECEPTOR_HPP
