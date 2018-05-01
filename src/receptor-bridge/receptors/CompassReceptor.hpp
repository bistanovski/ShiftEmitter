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

    virtual void connectReceptor() override;
    virtual void startListening() override;

private slots:
    virtual void onReadingChanged() override;

signals:
    void compassReadingChanged(const qreal azimuth, const qreal calibrationLevel);

private:
    QCompass m_compass;
};

#endif // COMPASSRECEPTOR_H
