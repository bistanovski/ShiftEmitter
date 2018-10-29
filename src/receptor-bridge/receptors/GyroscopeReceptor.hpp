#ifndef GYROSCOPERECEPTOR_HPP
#define GYROSCOPERECEPTOR_HPP

#include <QGyroscope>
#include "Receptor.hpp"

class GyroscopeReceptor : public Receptor
{
    Q_OBJECT

public:
    explicit GyroscopeReceptor(QObject *parent = nullptr);
    virtual ~GyroscopeReceptor();

    virtual void connectReceptor() override;
    virtual void startListening() override;
    virtual void stopListening() override;

private slots:
    virtual void onReadingChanged() override;

signals:
    void gyroscopeChanged(const qreal xValue, const qreal yValue, const qreal zValue);

private:
    QGyroscope m_gyroscope;
};

#endif // GYROSCOPERECEPTOR_HPP
