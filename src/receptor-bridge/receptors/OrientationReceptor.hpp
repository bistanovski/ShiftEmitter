#ifndef ORIENTATIONRECEPTOR_HPP
#define ORIENTATIONRECEPTOR_HPP

#include <QOrientationSensor>
#include "Receptor.hpp"

class OrientationReceptor : public Receptor
{
    Q_OBJECT

public:
    explicit OrientationReceptor(const QByteArray &identifier, QObject *parent = nullptr);
    virtual ~OrientationReceptor();

    QByteArray getType() const override;
    QByteArray getIdentifier() const override;

    QSensorReading *reading() const override;

private:
    QOrientationSensor m_orientationSensor;
};

#endif // ORIENTATIONRECEPTOR_HPP
