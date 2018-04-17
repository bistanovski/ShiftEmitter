#ifndef MAGNETOMETERRECEPTOR_HPP
#define MAGNETOMETERRECEPTOR_HPP

#include <QMagnetometer>
#include "Receptor.hpp"

class MagnetometerReceptor : public Receptor
{
    Q_OBJECT

public:
    explicit MagnetometerReceptor(QObject *parent = nullptr);
    virtual ~MagnetometerReceptor();

    void connectReceptor() override;
    void startListening() override;

    QSensorReading *reading() const override;

private slots:
    void onReadingChanged();

private:
    QMagnetometer m_magnetoMeter;
};

#endif // MAGNETOMETERRECEPTOR_HPP
