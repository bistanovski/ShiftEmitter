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

    virtual void connectReceptor() override;
    virtual void startListening() override;
    virtual void stopListening() override;

private slots:
    virtual void onReadingChanged() override;

signals:
    void magneticFluxChanged(const qreal xFlux, const qreal yFlux, const qreal zFlux, const qreal calibrationLevel);

private:
    QMagnetometer m_magnetoMeter;
};

#endif // MAGNETOMETERRECEPTOR_HPP
