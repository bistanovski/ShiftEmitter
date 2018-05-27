#ifndef ACCELEROMETERRECEPTOR_HPP
#define ACCELEROMETERRECEPTOR_HPP

#include <QAccelerometer>
#include "Receptor.hpp"

class AccelerometerReceptor : public Receptor
{
    Q_OBJECT

public:
    explicit AccelerometerReceptor(QObject *parent = nullptr);
    virtual ~AccelerometerReceptor();

    virtual void connectReceptor() override;
    virtual void startListening() override;
    virtual void stopListening() override;

private slots:
    virtual void onReadingChanged() override;

signals:
    void accelerationChanged(const qreal xValue, const qreal yValue, const qreal zValue);

private:
    QAccelerometer m_accelerometer;
};

#endif // ACCELEROMETERRECEPTOR_HPP
