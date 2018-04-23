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

    virtual void connectReceptor() override;
    virtual void startListening() override;

private slots:
    virtual void onReadingChanged() override;

private:
    QAmbientLightSensor m_ambientLightSensor;
};

#endif // AMBIENTLIGHTRECEPTOR_HPP
