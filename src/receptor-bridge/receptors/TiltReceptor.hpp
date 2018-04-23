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

    virtual void connectReceptor() override;
    virtual void startListening() override;

private slots:
    virtual void onReadingChanged() override;

private:
    QTiltSensor m_tiltSensor;
};

#endif // TILTRECEPTOR_HPP
