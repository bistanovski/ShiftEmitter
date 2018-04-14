#ifndef ORIENTATIONRECEPTOR_HPP
#define ORIENTATIONRECEPTOR_HPP

#include <QOrientationSensor>
#include "Receptor.hpp"

class OrientationReceptor : public Receptor
{
public:
    OrientationReceptor(QObject *parent = nullptr);
    virtual ~OrientationReceptor();

    QByteArray getType() const override;
    QByteArray getIdeintifier() const override;

    QSensorReading *reading() const override;

private:
    QOrientationSensor m_orientationSensor;
};

#endif // ORIENTATIONRECEPTOR_HPP
