#ifndef PROXIMITYRECEPTOR_HPP
#define PROXIMITYRECEPTOR_HPP

#include <QProximitySensor>
#include "Receptor.hpp"

class ProximityReceptor : public Receptor
{
    Q_OBJECT

public:
    explicit ProximityReceptor(QObject *parent = nullptr);
    virtual ~ProximityReceptor();

    void connectReceptor() override;
    void startListening() override;

    QSensorReading *reading() const override;

private slots:
    void onReadingChanged();

private:
    QProximitySensor m_proximitySensor;
};

#endif // PROXIMITYRECEPTOR_HPP
