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

    qreal fieldOfView() const;
    void setFieldOfView(qreal fieldOfView);

private slots:
    virtual void onReadingChanged() override;

private:
    QLightSensor m_lightSensor;
};

#endif // LIGHTRECEPTOR_HPP
