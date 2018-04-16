#ifndef TILTRECEPTOR_HPP
#define TILTRECEPTOR_HPP

#include <QTiltSensor>
#include "Receptor.hpp"

class TiltReceptor : public Receptor
{
    Q_OBJECT

public:
    TiltReceptor() {}
    explicit TiltReceptor(const QByteArray &identifier, QObject *parent = nullptr);
    virtual ~TiltReceptor();

    QByteArray getType() const override;
    QByteArray getIdentifier() const override;

    QSensorReading *reading() const override;

private:
    QTiltSensor m_tiltSensor;
};

#endif // TILTRECEPTOR_HPP
