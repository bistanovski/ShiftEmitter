#ifndef TILTRECEPTOR_HPP
#define TILTRECEPTOR_HPP

#include <QTiltSensor>
#include "Receptor.hpp"

class TiltReceptor : public Receptor
{
public:
    TiltReceptor(const QByteArray &identifier, QObject *parent = nullptr);
    virtual ~TiltReceptor();

    QByteArray getType() const override;
    QByteArray getIdeintifier() const override;

    QSensorReading *reading() const override;

private:
    QTiltSensor m_tiltSensor;
};

#endif // TILTRECEPTOR_HPP
