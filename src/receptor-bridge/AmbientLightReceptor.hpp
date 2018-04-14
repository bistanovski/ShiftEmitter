#ifndef AMBIENTLIGHTRECEPTOR_HPP
#define AMBIENTLIGHTRECEPTOR_HPP

#include <QAmbientLightSensor>
#include "Receptor.hpp"

class AmbientLightReceptor : public Receptor
{
public:
    AmbientLightReceptor(QObject *parent = nullptr);
    virtual ~AmbientLightReceptor();

    QByteArray getType() const override;
    QByteArray getIdeintifier() const override;

    QSensorReading *reading() const override;

private:
    QAmbientLightSensor m_ambientLightSensor;
};

#endif // AMBIENTLIGHTRECEPTOR_HPP
