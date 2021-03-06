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
    virtual void stopListening() override;

private slots:
    virtual void onReadingChanged() override;

signals:
    void somethingIsCloseChanged(const bool close);

private:
    QProximitySensor m_proximitySensor;
};

#endif // PROXIMITYRECEPTOR_HPP
