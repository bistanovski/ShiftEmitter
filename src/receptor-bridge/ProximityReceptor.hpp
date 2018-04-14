#ifndef PROXIMITYRECEPTOR_HPP
#define PROXIMITYRECEPTOR_HPP

#include <QProximitySensor>
#include "Receptor.hpp"

class ProximityReceptor : public Receptor
{
    Q_OBJECT

public:
    ProximityReceptor(const QByteArray &identifier, QObject *parent = nullptr);
    virtual ~ProximityReceptor();

    QByteArray getType() const override;
    QByteArray getIdeintifier() const override;

    QSensorReading *reading() const override;

private:
    QProximitySensor m_proximitySensor;
};

#endif // PROXIMITYRECEPTOR_HPP
