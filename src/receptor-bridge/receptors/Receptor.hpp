#ifndef RECEPTOR_HPP
#define RECEPTOR_HPP

#include <QObject>

class QSensorReading;

class Receptor : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QByteArray receptorType READ getType NOTIFY typeChanged)
    Q_PROPERTY(QByteArray receptorIdentifier READ getIdentifier NOTIFY identifierChanged)

public:
    explicit Receptor(QObject *parent = nullptr) : QObject(parent) {}
    virtual ~Receptor() {}

    virtual QByteArray getType() const = 0;
    virtual QByteArray getIdentifier() const = 0;

    virtual QSensorReading *reading() const = 0;

signals:
    void typeChanged();
    void identifierChanged();
};

#endif // RECEPTOR_HPP
