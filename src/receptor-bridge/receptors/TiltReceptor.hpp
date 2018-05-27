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
    virtual void stopListening() override;

private slots:
    virtual void onReadingChanged() override;

signals:
    void tiltDetected(const qreal xRotation, const qreal yRotation);

private:
    QTiltSensor m_tiltSensor;
};

#endif // TILTRECEPTOR_HPP
