#ifndef COMPASSRECEPTOR_H
#define COMPASSRECEPTOR_H

#include <QCompass>
#include "Receptor.hpp"

class CompassReceptor : public Receptor
{
    Q_OBJECT

public:
    CompassReceptor() {}
    explicit CompassReceptor(const QByteArray &identifier, QObject *parent = nullptr);
    virtual ~CompassReceptor();

    QByteArray getType() const override;
    QByteArray getIdentifier() const override;

    QSensorReading *reading() const override;

private:
    QCompass m_compass;
};

#endif // COMPASSRECEPTOR_H
