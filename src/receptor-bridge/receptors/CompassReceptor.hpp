#ifndef COMPASSRECEPTOR_H
#define COMPASSRECEPTOR_H

#include <QCompass>
#include "Receptor.hpp"

class CompassReceptor : public Receptor
{
    Q_OBJECT

public:
    explicit CompassReceptor(QObject *parent = nullptr);
    virtual ~CompassReceptor();

    void connectReceptor() override;
    void startListening() override;

    QSensorReading *reading() const override;

private slots:
    void onReadingChanged();

private:
    QCompass m_compass;
};

#endif // COMPASSRECEPTOR_H
