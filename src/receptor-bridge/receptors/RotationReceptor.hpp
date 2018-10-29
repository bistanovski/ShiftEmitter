#ifndef ROTATIONRECEPTOR_HPP
#define ROTATIONRECEPTOR_HPP

#include <QRotationSensor>
#include "Receptor.hpp"

class RotationReceptor : public Receptor
{
    Q_OBJECT

public:
    explicit RotationReceptor(QObject *parent = nullptr);
    virtual ~RotationReceptor();

    virtual void connectReceptor() override;
    virtual void startListening() override;
    virtual void stopListening() override;

private slots:
    virtual void onReadingChanged() override;

signals:
    void rotationChanged(const qreal xValue, const qreal yValue, const qreal zValue);

private:
    QRotationSensor m_rotationSensor;
};

#endif // ROTATIONRECEPTOR_HPP
