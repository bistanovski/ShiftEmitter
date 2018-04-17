#ifndef DUMMYRECEPTOR_HPP
#define DUMMYRECEPTOR_HPP

#include <QSensor>
#include "Receptor.hpp"

class DummyReceptor : public Receptor
{
    Q_OBJECT

public:
    explicit DummyReceptor(QObject *parent = nullptr);
    virtual ~DummyReceptor();

    void connectReceptor() override;
    void startListening() override;

    QSensorReading *reading() const override;

private slots:
    void onReadingChanged();

private:
    QSensor m_dummySensor;
    const QByteArray m_dummyType = "DUMMY";
};

#endif // DUMMYRECEPTOR_HPP
