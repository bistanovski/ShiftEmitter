#ifndef ORIENTATIONRECEPTOR_HPP
#define ORIENTATIONRECEPTOR_HPP

#include <QOrientationSensor>
#include "Receptor.hpp"

class OrientationReceptor : public Receptor
{
    Q_OBJECT

public:
    explicit OrientationReceptor(QObject *parent = nullptr);
    virtual ~OrientationReceptor();

    void connectReceptor() override;
    void startListening() override;

    QSensorReading *reading() const override;

private slots:
    void onReadingChanged();

private:
    QOrientationSensor m_orientationSensor;
};

#endif // ORIENTATIONRECEPTOR_HPP
