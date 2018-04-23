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

    virtual void connectReceptor() override;
    virtual void startListening() override;

private slots:
    virtual void onReadingChanged() override;

private:
    QProximitySensor m_proximitySensor;
};

#endif // PROXIMITYRECEPTOR_HPP
