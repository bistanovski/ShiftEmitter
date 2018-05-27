#ifndef LIGHTRECEPTOR_HPP
#define LIGHTRECEPTOR_HPP

#include <QLightSensor>
#include "Receptor.hpp"

class LightReceptor : public Receptor
{
    Q_OBJECT

public:
    explicit LightReceptor(QObject *parent = nullptr);
    virtual ~LightReceptor();

    virtual void connectReceptor() override;
    virtual void startListening() override;
    virtual void stopListening() override;

    qreal fieldOfView() const;
    void setFieldOfView(qreal fieldOfView);

private slots:
    virtual void onReadingChanged() override;

signals:
    void lightReadingChanged(const qreal luxValue);

private:
    QLightSensor m_lightSensor;
};

#endif // LIGHTRECEPTOR_HPP
