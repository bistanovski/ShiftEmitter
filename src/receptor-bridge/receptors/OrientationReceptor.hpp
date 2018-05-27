#ifndef ORIENTATIONRECEPTOR_HPP
#define ORIENTATIONRECEPTOR_HPP

#include <QOrientationSensor>
#include "Receptor.hpp"

class OrientationReceptor : public Receptor
{
    Q_OBJECT

public:
    explicit OrientationReceptor(QObject *parent = nullptr);
    virtual ~OrientationReceptor();

    virtual void connectReceptor() override;
    virtual void startListening() override;
    virtual void stopListening() override;

private slots:
    virtual void onReadingChanged() override;

signals:
    void orientationChanged(const int orientation);

private:
    QOrientationSensor m_orientationSensor;
};

#endif // ORIENTATIONRECEPTOR_HPP
