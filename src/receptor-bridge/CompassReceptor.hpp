#ifndef COMPASSRECEPTOR_H
#define COMPASSRECEPTOR_H

#include <QCompass>
#include "Receptor.hpp"

class CompassReceptor : public Receptor
{
    Q_OBJECT

public:
    CompassReceptor(QObject *parent = nullptr);
    virtual ~CompassReceptor();

    QByteArray getType() const override;
    QByteArray getIdeintifier() const override;

    QSensorReading *reading() const override;

private:
    QCompass m_compass;
};

#endif // COMPASSRECEPTOR_H
