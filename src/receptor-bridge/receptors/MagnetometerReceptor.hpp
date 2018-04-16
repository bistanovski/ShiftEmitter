#ifndef MAGNETOMETERRECEPTOR_HPP
#define MAGNETOMETERRECEPTOR_HPP

#include <QMagnetometer>
#include "Receptor.hpp"

class MagnetometerReceptor : public Receptor
{
    Q_OBJECT

public:
    MagnetometerReceptor() {}
    explicit MagnetometerReceptor(const QByteArray &identifier, QObject *parent = nullptr);
    virtual ~MagnetometerReceptor();

    QByteArray getType() const override;
    QByteArray getIdentifier() const override;

    QSensorReading *reading() const override;

private:
    QMagnetometer m_magnetoMeter;
};

#endif // MAGNETOMETERRECEPTOR_HPP
