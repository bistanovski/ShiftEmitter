#ifndef LIGHTRECEPTOR_HPP
#define LIGHTRECEPTOR_HPP

#include <QLightSensor>
#include "Receptor.hpp"

class LightReceptor : public Receptor
{
    Q_OBJECT

public:
    explicit LightReceptor(QObject *parent = nullptr);
    virtual ~LightReceptor();

    void connectReceptor() override;
    void startListening() override;

    QSensorReading *reading() const override;

    qreal fieldOfView() const;
    void setFieldOfView(qreal fieldOfView);

private slots:
    void onReadingChanged();

private:
    QLightSensor m_lightSensor;
};

#endif // LIGHTRECEPTOR_HPP
