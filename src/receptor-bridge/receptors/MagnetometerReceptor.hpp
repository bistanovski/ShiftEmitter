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

private slots:
    virtual void onReadingChanged() override;

private:
    QMagnetometer m_magnetoMeter;
};

#endif // MAGNETOMETERRECEPTOR_HPP
