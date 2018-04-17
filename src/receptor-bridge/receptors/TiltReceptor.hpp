#ifndef TILTRECEPTOR_HPP
#define TILTRECEPTOR_HPP

#include <QTiltSensor>
#include "Receptor.hpp"

class TiltReceptor : public Receptor
{
    Q_OBJECT

public:
    explicit TiltReceptor(QObject *parent = nullptr);
    virtual ~TiltReceptor();

    void connectReceptor() override;
    void startListening() override;

    QSensorReading *reading() const override;

private slots:
    void onReadingChanged();

private:
    QTiltSensor m_tiltSensor;
};

#endif // TILTRECEPTOR_HPP
