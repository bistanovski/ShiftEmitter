#ifndef RECEPTOR_HPP
#define RECEPTOR_HPP

#include <QObject>

class QSensorReading;

class ContextData : public QObject
{
    Q_OBJECT
public:
    ContextData(QObject *parent = nullptr) : QObject(parent) {}
    virtual ~ContextData() {}

    Q_PROPERTY(int foundSensors READ getFoundSensors NOTIFY foundSensorsChanged)
    Q_PROPERTY(QStringList foundTypes READ getFoundTypes NOTIFY foundTypesChanged)
    Q_PROPERTY(QStringList foundIdentifiers READ getFoundIdentifiers NOTIFY foundIndetifiersChanged)

    auto getFoundSensors() const {return foundSensors;}
    auto getFoundTypes() const {return foundTypes;}
    auto getFoundIdentifiers() const {return foundIdentifiers;}

    void setFoundSensors(const int numOfSensors) {foundSensors = numOfSensors; emit foundSensorsChanged();}
    void appendFoundType(const QString &type) {foundTypes.push_back(type); emit foundTypesChanged();}
    void appendFoundIdentifier(const QString &identifier) {foundIdentifiers.push_back(identifier); emit foundIndetifiersChanged();}

    int foundSensors = 0;
    QStringList foundTypes;
    QStringList foundIdentifiers;

signals:
    void foundSensorsChanged();
    void foundTypesChanged();
    void foundIndetifiersChanged();
};

class Receptor : public QObject
{
    Q_OBJECT

public:
    explicit Receptor(QObject *parent = nullptr);
    virtual ~Receptor();

    virtual QByteArray getType() const = 0;
    virtual QByteArray getIdeintifier() const = 0;

    virtual QSensorReading *reading() const = 0;
};

#endif // RECEPTOR_HPP
