#ifndef AMBIENTLIGHTRECEPTOR_HPP
#define AMBIENTLIGHTRECEPTOR_HPP

#include <QAmbientLightSensor>
#include "Receptor.hpp"

class AmbientLightReceptor : public Receptor
{
    Q_OBJECT

public:
    explicit AmbientLightReceptor(QObject *parent = nullptr);
    virtual ~AmbientLightReceptor();

    void connectReceptor() override;
    void startListening() override;

    QSensorReading *reading() const override;

private slots:
    void onReadingChanged();

private:
    QAmbientLightSensor m_ambientLightSensor;
};

#endif // AMBIENTLIGHTRECEPTOR_HPP
