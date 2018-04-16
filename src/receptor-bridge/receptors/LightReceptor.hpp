#ifndef LIGHTRECEPTOR_HPP
#define LIGHTRECEPTOR_HPP

#include <QLightSensor>
#include "Receptor.hpp"

class LightReceptor : public Receptor
{
    Q_OBJECT

public:
    LightReceptor() {}
    explicit LightReceptor(const QByteArray &identifier, QObject *parent = nullptr);
    virtual ~LightReceptor();

    QByteArray getType() const override;
    QByteArray getIdentifier() const override;

    QSensorReading *reading() const override;

    qreal fieldOfView() const;
    void setFieldOfView(qreal fieldOfView);

private:
    QLightSensor m_lightSensor;
};

#endif // LIGHTRECEPTOR_HPP
